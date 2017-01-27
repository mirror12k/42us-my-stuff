
#include <stdio.h>
#include <stdlib.h>



void rush00(int w, int h)
{
	int x, y;
	for (y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
			if (y == 0 && x == 0)
				putchar('/');
			else if (y == 0 && x == w - 1)
				putchar('\\');
			else if (y == h - 1 && x == 0)
				putchar('\\');
			else if (y == h - 1 && x == w - 1)
				putchar('/');
			else if (y == 0 || y == h - 1)
				putchar('*');
			else if (x == 0 || x == w - 1)
				putchar('*');
			else
				putchar(' ');
		putchar('\n');
	}
}


int main(int argc, char** argv)
{
	int arg_w = atoi(argv[1]);
	int arg_h = atoi(argv[2]);

	rush00(arg_w, arg_h);

	return 0;
}




