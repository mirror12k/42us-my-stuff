#include <stdio.h>

#include "ft_point.h"
void set_point(t_point *point)
{
	point->x = 15;
	point->y = -25;
}

int main(void)
{
	t_point point;
	set_point(&point);
	printf("%d,%d\n", point.x, point.y);
	return (0);
}
