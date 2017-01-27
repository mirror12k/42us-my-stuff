#!/bin/sh

ifconfig | egrep -o 'inet \d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}' | cut -d ' ' -f 2

