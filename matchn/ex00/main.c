

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	match(char *s1, char *s2);

#define TEST_MATCH(S1, S2) printf(#S1 " =~ " #S2 " -> %d\n", match(S1, S2))

int main()
{
	TEST_MATCH("asdf", "asdf");
	TEST_MATCH("a", "asdf");
	TEST_MATCH("asdf", "a");
	TEST_MATCH("aasdf", "asdf");
	TEST_MATCH("asdf", "aasdf");
	TEST_MATCH("asdf", "asde");
	TEST_MATCH("asde", "asdf");

	printf("\n");

	TEST_MATCH("", "");
	TEST_MATCH("asdf", "");
	TEST_MATCH("", "asdf");
	TEST_MATCH("asdff", "asdf");
	TEST_MATCH("qwer", "asdf");

	printf("\n");

	TEST_MATCH("", "*");
	TEST_MATCH("asdf", "*");
	TEST_MATCH("a", "*");
	TEST_MATCH("*", "a");
	TEST_MATCH("", "**");
	TEST_MATCH("a", "**");
	TEST_MATCH("asdf", "**");
	TEST_MATCH("qwerty", "**");
	
	printf("\n");

	TEST_MATCH("asdf", "a*");
	TEST_MATCH("a", "a*");
	TEST_MATCH("aasdf", "a*");
	TEST_MATCH("aaaaaaaaaasdf", "a*");
	TEST_MATCH("aaaaaaaaa", "a*");
	TEST_MATCH("", "a*");
	TEST_MATCH("bete", "a*");
	TEST_MATCH("basdf", "a*");
	TEST_MATCH("*asdf", "a*");

	printf("\n");

	TEST_MATCH("asdf", "*a*");
	TEST_MATCH("aaaaaaasdf", "*a*");
	TEST_MATCH("fdsa", "*a*");
	TEST_MATCH("aaaaaa", "*a*");
	TEST_MATCH("a", "*a*");
	TEST_MATCH("beta", "*a*");
	TEST_MATCH("gams", "*a*");
	TEST_MATCH("ffffff", "*a*");
	TEST_MATCH("", "*a*");
	TEST_MATCH("Asdf", "*a*");

	printf("\n");

	TEST_MATCH("asdf", "a**");
	TEST_MATCH("aaaaaaaaa", "a**");
	TEST_MATCH("a", "a**");
	TEST_MATCH("aaaasdfsdf", "a**");
	TEST_MATCH("aa", "a**");
	TEST_MATCH("aaa", "a**");
	TEST_MATCH("fdsa", "a**");
	TEST_MATCH("rasdf", "a**");
	TEST_MATCH("ra", "a**");
	TEST_MATCH("", "a**");
	TEST_MATCH("r", "a**");
	TEST_MATCH("rr", "a**");
	TEST_MATCH("rrr", "a**");

	printf("\n");

	TEST_MATCH("asdf", "*a**");
	TEST_MATCH("aaaaaaa", "*a**");
	TEST_MATCH("a", "*a**");
	TEST_MATCH("aa", "*a**");
	TEST_MATCH("aaa", "*a**");
	TEST_MATCH("aaaa", "*a**");
	TEST_MATCH("rasdf", "*a**");
	TEST_MATCH("rrrrrrrrrrrrrra", "*a**");
	TEST_MATCH("rrrrrrrrrrrrrraa", "*a**");
	TEST_MATCH("rrrrrrrrrrrrrraaa", "*a**");
	TEST_MATCH("*", "*a**");
	TEST_MATCH("*a", "*a**");
	TEST_MATCH("r", "*a**");
	TEST_MATCH("rr", "*a**");
	TEST_MATCH("rrr", "*a**");
	TEST_MATCH("rrrr", "*a**");
	
	return 0;
}
