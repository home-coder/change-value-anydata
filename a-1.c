#include <stdio.h>

static void change_int(int *a)
{
	*a += 1;
}

static void change_ch(char *c)
{
	*c += '1';
}

int main()
{
//1. int
	{
		int a = 0;
		change_int(&a);
		printf("%d\n", a);
	}
//2. char
	{
		char c = 'a';
		change_ch(&c);
		printf("%c\n", c);
	}

}
