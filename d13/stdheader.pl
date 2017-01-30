#!/usr/bin/env perl
use strict;
use warnings;


my $filename = shift // die "filename argument required";

my $filename_padded = $filename . ' ' x (50 - length $filename);

my ($second, $minute, $hour, $day, $month, $year) = localtime time;
$year += 1900;
$month++;

my $timestamp = sprintf '%04d/%02d/%02d %02d:%02d:%02d', $year, $month, $day, $hour, $minute, $second;

my $stdheader = "/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   $filename_padded :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k\@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: $timestamp by nmoiseye          #+#    #+#             */
/*   Updated: $timestamp by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

";

print $stdheader;

