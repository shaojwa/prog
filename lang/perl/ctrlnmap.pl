#by wangs at 20160304
#!/usr/bin/perl

use strict;
use warnings;

my @arrs=(1, 2, 3, 3, 2, 1);

sub reassign {
    $_[0]= sqrt $_[0];
}
my $x=100;
reassign($x);

print $x;
print "\n";

my $arrsref = \@arrs;
print $arrsref;
print "\n";

sub subroutine {
    print "looks";
}

print subroutine();

package pkwangs;
sub subroutine {
    print "good";
}

print subroutine();
