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

sub get_given_function_prototype {
	my ($function) = @_;

	my @protos = split /\r?\n/, slurp_file('stupidity.c');
	foreach my $proto (@protos) {
		if ($proto =~ /\A\S+\s+(\w+)\(.*\);\Z/) {
			return $proto if $1 eq $function;
		}
	}
	die "prototype not found for function $function";
}



sub main {
	my ($exercise, $program_name, @required) = @_;

	die "exercise id required" unless defined $exercise;
	die "program name required" unless defined $program_name;

	my @required_prototypes = map get_given_function_prototype($_), @required;


	mkdir $exercise;

	dump_file("$exercise/$program_name.c", `./stdheader.pl $program_name.c` .
( join '', map "$_\n\n", @required_prototypes ) . 
"int		main(int argc, char **argv)
{

	return (0);
}
");

	unless (-e 'build.sh') {
		dump_file('build.sh', "#!/bin/sh\n\n");
		chmod 0755, 'build.sh';
	}

	append_file('build.sh', "
echo building $exercise
gcc -Wall -Wextra -Werror stupidity.c $exercise/$program_name.c -o $exercise/a.out
");
	unless (-e 'verify_normal.sh') {
		dump_file('verify_normal.sh', "#!/bin/sh\n\nnorminette -R CheckForbiddenSourceHeader");
		chmod 0755, 'verify_normal.sh';
	}
	append_file('verify_normal.sh', " $exercise/$program_name.c");

}



caller or main(@ARGV);

