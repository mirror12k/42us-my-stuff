#!/usr/bin/env perl
use strict;
use warnings;

use feature 'say';



sub slurp_file {
	my ($file) = @_;

	die "error opening file $file" unless open my $f, '<', $file;
	local $/;
	my $contents = <$f>;
	$f->close;
	
	return $contents
}

sub dump_file {
	my ($file, $contents) = @_;
	
	say "creating file $file";

	open my $f, '>', $file;
	$f->print($contents);
	$f->close;
}

sub append_file {
	my ($file, $contents) = @_;

	say "appending file $file";

	open my $f, '>>', $file;
	$f->print($contents);
	$f->close;
}



sub main {
	my ($exercise, $function) = @_;
	
	die "exercise id required" unless defined $exercise;
	die "function identifier required" unless defined $function;

	mkdir $exercise;

	dump_file("$exercise/$function.h", "
void	$function(void);
");

	dump_file("$exercise/$function.c", slurp_file('stdheader.h') . "#ifdef STUPIDITY
# include \"../stupidity.h\"
#endif

void	$function(void)
{

}
");

	dump_file("$exercise/main.c", "
#include \"$function.h\"

int main()
{
	$function();

	return 0;
}
");

	dump_file('build.sh', "#!/bin/sh\n\n") unless -e 'build.sh';

	append_file('build.sh', "
echo building $exercise
gcc -DSTUPIDITY -Wall -Wextra -Werror stupidity.c $exercise/*.c -o $exercise/a.out
");

	dump_file('verify_normal.sh', "#!/bin/sh\n\n") unless -e 'verify_normal.sh';
	
	append_file('verify_normal.sh', "
norminette -R CheckForbiddenSourceHeader $exercise/$function.c
");

}



caller or main(@ARGV);

