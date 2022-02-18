#include <stdio.h>

int main(void)
{
	printf("%u\n", -10);
	printf("%u\n", 0);
	printf("%u\n", 8594967296);
	printf("%u\n", -3295);
	printf("%u\n", -1023);
	printf("%-05d123\n", 123);
	printf("%+05d123\n", 123);
	printf("%-05%123\n");
	printf("%05%123\n");
	printf("%05c0\n", 'a');
	printf("%-5c0\n", 'a');
	printf("%-05c0\n", 'a');
	printf("%5s0\n", "abc");
	printf("%2s0\n", "abc");
	printf("%05s0\n", "abc");
	printf("%02s0\n", "abc");
	printf("%.5s0\n", "abc");
	printf("%5.5s0\n", "abc");
	printf("%5.1s0\n", "abc");
	printf("%2.5s0\n", "abc");
	printf("%2.1s0\n", "abc");
	printf("------------------\n");
	printf("%-5s0\n", "abc");
	printf("%-2s0\n", "abc");
	printf("%-05s0\n", "abc");
	printf("%-02s0\n", "abc");
	printf("%-.5s0\n", "abc");
	printf("%-5.5s0\n", "abc");
	printf("%-5.1s0\n", "abc");
	printf("%-2.5s0\n", "abc");
	printf("%-2.1s0\n", "abc");
	printf("------------------\n");
	printf("%2.0s0\n", "abc");
	printf("%2.-1s0\n", "abc");
	printf("%2.-2s0\n", "abc");
	printf("-------di-------\n");
	printf("%+ d\n", 123);
	printf("% 0d\n", 123);
	printf("% 5d\n", 123);
	printf("%d\n", 2147483648);
}
