#include <dirent.h>
#include <string>
#include <iostream>

using namespace std;

class Err {
    public: Err(string msg) {
	cerr << "EXCEPTION: " << msg << endl;
    }
};

int ttyopen(const string &path) {
}

int find_device() {
    DIR *dir = opendir("/dev");
    if (!dir) throw Err("bad dir");
    struct dirent *file;
    while (file = readdir(dir)) {
	if (file->d_name[0] == '.') continue;
	if (strcmp("tty.usbserial-", file->d_name))
	   continue;
	string path("/dev");
	path += "/";
	path += file->d_name;
	// TODO: test open files
	closedir(dir);
	return 1;
    }
    return -1;
}

