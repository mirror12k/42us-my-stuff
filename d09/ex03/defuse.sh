#!/bin/sh

perl -E '
	my $access_time = (stat "bomb.txt")[8] - 1;
	say "$access_time";
	utime $access_time, $access_time, "bomb.txt";
'
