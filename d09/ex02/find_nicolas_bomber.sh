#!/bin/sh

cat $1 | egrep -i '(n|nicolas|Nhicholhas)	bomber|bomber	nicolas|nicolasbomber' | sed -En 's/.*(([0-9]+-)[0-9]{3}-[0-9]{3}-[0-9]{4}).*/\1/p'


