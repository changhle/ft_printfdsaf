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
}
