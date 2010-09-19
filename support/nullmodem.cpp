#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <termios.h>
#include <fcntl.h>

using namespace std;

class Err {
public:
    Err(string msg) {
	cerr << "EXCEPTION: " << msg << endl;
    }
};

class File {
public:
    File(const string path, int fd) {
	_path = path;
	_fd = fd;
    }
public:
    string _path;
    int _fd;
};

vector<File> tty;


int ttyopen(const string &path, int speed = B9600) {
    int fd = open(path.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd < 0) return 0;
    if (fcntl(fd, F_SETFL, 0)) perror("fcntl");

    struct termios termio;
    tcgetattr(fd, &termio);
    cfmakeraw(&termio);
    cfsetispeed(&termio, speed);
    cfsetospeed(&termio, speed);
    termio.c_cflag &= ~CSTOPB;	    // one stop bit
    termio.c_cflag &= ~CRTSCTS;	    // no hardware flow control
    termio.c_cc[VTIME] = 10;
    termio.c_cc[VMIN]  = 0;
    tcsetattr(fd, TCSANOW, &termio);

    if((tcflush(fd, TCIFLUSH) < 0) || (tcsetattr(fd, TCSANOW, &termio) < 0))
    {
      close(fd);
      return 0;
    }

    return fd;
}

int find_device() {
    DIR *dir = opendir("/dev");
    if (!dir) throw Err("bad dir");
    struct dirent *file;
    while (file = readdir(dir)) {
	if (file->d_name[0] == '.') continue;
	if (strncmp("cu.usbserial-", file->d_name, 13)
		&& strncmp("ttyUSB", file->d_name, 6))
	    continue;
	string path("/dev");
	path += "/";
	path += file->d_name;
	bool found = false;
	for (int i=0; i<tty.size(); i++) {
	    if (tty[i]._path == path) found = true;
	}
	if (found) continue;
cerr << "Opening " << path << endl;
	int fd =ttyopen(path);
	if (fd) {
cerr << "\tsuccess.  FD=" << fd << endl;
	    closedir(dir);
	    File f(path, fd);
	    tty.push_back(f);
	    return fd;
	}
    }
    closedir(dir);
    return -1;
}

int main(int argc, char *argv[]) {
    while (1) {
	while (tty.size() < 2) {
	    find_device();
	    sleep(1);
	}
	cerr << "Found both devices.  shuffling data." << endl;
	try {
	    int lastfd = 0;
	    while (tty.size() == 2) {
		struct timeval timeout;
		// listen on both fds
		fd_set readfds;
		FD_ZERO(&readfds);

		int maxfd = 0;
		for (int i=0; i<tty.size(); i++) {
		    FD_SET(tty[i]._fd, &readfds);
		    if (tty[i]._fd > maxfd)
			maxfd = tty[i]._fd;
		}

		timeout.tv_usec = 0;
		timeout.tv_sec = 10;
		select(maxfd+1, &readfds, NULL, NULL, &timeout);
		bool found = false;
		for (int i=0; i<tty.size(); i++) {
		    if (FD_ISSET(tty[i]._fd, &readfds)) {
			char buf[256];
			int bytes = read(tty[i]._fd, buf, sizeof(buf));
			if (bytes <= 0) throw Err("reading error");
			found = true;
			write(tty[1-i]._fd, buf, bytes);
			if (lastfd != tty[i]._fd) {
			    cout << endl << "<fd_" << tty[i]._fd << "> ";
			    lastfd = tty[i]._fd;
			}
			buf[bytes] = '\0';

			// strip out control characters
			for (int j = 0; j < bytes; j++) {
			    if (buf[j] < 28) buf[j] = '_';
			}

			cout << buf << flush;
		    }
		}
		if (!found) {
		    cout << endl << "TIMEOUT" << endl;
		    write(tty[0]._fd, ".", 1);
		}
	    }
	} catch (Err x) {
	    cerr << "lost connection" << endl;
	    for (int i=0; i<tty.size(); i++) {
		close(tty[i]._fd);
	    }
	    tty.clear();
	}
    }
}

