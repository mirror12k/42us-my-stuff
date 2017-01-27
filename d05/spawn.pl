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
		if ($proto =~ /\A\S+\s+\**(\w+)\(.*\);\Z/) {
			return $proto if $1 eq $function;
		}
	}
	die "prototype not found for function $function";
}



sub main {
	my ($exercise, $function, @required) = @_;

	die "exercise id required" unless defined $exercise;
	die "function identifier required" unless defined $function;

	my ($function_name, $function_proto);
	if ($function =~ /\A(\w+)\Z/) {
		$function_name = $1;
		$function_proto = "void	$function_name(void)";
	} elsif ($function =~ /\A(\w+)\((.*)\)\Z/) {
		$function_name = $1;
		$function_proto = "void	$function_name($2)";
	} elsif ($function =~ /\A(.*?) (\**)(\w+)\((.*)\)\Z/) {
		$function_name = $3;
		$function_proto = "$1	$2$function_name($4)";
	} else {
		die "invalid function name: $function";
	}

	my @required_prototypes = map get_given_function_prototype($_), @required;

	#warn "debug: ", join ', ', @required_prototypes;

	#die "debug: $function_name, $function_proto";

	mkdir $exercise;

	dump_file("$exercise/$function_name.c", `./stdheader.pl $function_name.c` .
( join '', map "$_\n\n", @required_prototypes ) . 
"$function_proto
{

}
");

	dump_file("$exercise/main.c", "

#include <stdio.h>

$function_proto;

int main()
{
	$function_name();

	return 0;
}
");
	unless (-e 'build.sh') {
		dump_file('build.sh', "#!/bin/sh\n\n");
		chmod 0755, 'build.sh';
	}

	append_file('build.sh', "
echo building $exercise
gcc -Wall -Wextra -Werror stupidity.c $exercise/*.c -o $exercise/a.out
");
	unless (-e 'verify_normal.sh') {
		dump_file('verify_normal.sh', "#!/bin/sh\n\nnorminette -R CheckForbiddenSourceHeader");
		chmod 0755, 'verify_normal.sh';
	}
	append_file('verify_normal.sh', " $exercise/$function_name.c");

}



caller or main(@ARGV);

