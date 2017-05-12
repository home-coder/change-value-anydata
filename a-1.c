#include <stdio.h>
#include <stdlib.h>

static void change_int(int *a)
{
	*a += 1;
}

static void change_ch(char *c)
{
	*c += 1;
}

static void change_arri(int *p, int size, int location, int value)
{
	if ((location + 1) > size) {
		perror("location is too large\n");
		exit(-1);
	}
	p[location] = value;
}

static void change_char(char *p, int size, int location, char value)
{
	if (location > size) {
		perror("location is too large\n");
		exit(-1);
	}

	p[location] = value;
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

// 3. int[]
	{
		int a[] = {1, 3, 4, 2};
		int size = sizeof(a)/sizeof(a[0]);
		int *p = a;

		change_arri(p, size, 2, 0);
		//这是一个c程序员常用的遍历方法
		for (; p < &a[size]; p++) {
			printf("%d ", *p);
		}
		printf("\n");
	}

// 4. char[]
	{
		char c[] = {'a', 'c', 'r', 'd'};
		int size = sizeof(c)/sizeof(c[0]);
		char *p = c;

		change_char(p, size, 2, 'm');
		for (; p < &c[size]; p++) {
			printf("%c ", *p);
		}
		printf("\n");
	}
// 5. char *

// 6. char *[]

// 7. int[][x]

	return 0;
}
