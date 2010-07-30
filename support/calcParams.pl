#!/usr/bin/perl


my $attendees = shift @ARGV;

my ($m, $k) = _calculate_shortest_filter_length( $attendees, 0.1 );
print "Lowest m: $m\n";
print "Best k: $k\n";
exit(0);

# from Bloom::Filter
sub _calculate_shortest_filter_length 
{
        my ( $num_keys, $error_rate ) = @_;
        my $lowest_m;
        my $best_k = 1;

        foreach my $k ( 1..100 ) {
                my $m = (-1 * $k * $num_keys) / 
                        ( log( 1 - ($error_rate ** (1/$k))));

                if ( !defined $lowest_m or ($m < $lowest_m) ) {
                        $lowest_m = $m;
                        $best_k   = $k;
                }
        }
        $lowest_m = int( $lowest_m ) + 1;
        return ( $lowest_m, $best_k );
} 

