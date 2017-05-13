#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static void change_string(char *src, int location, char value, char **dst)
{
	if (src[location] == '\0') {
		perror("location is too large\n");
		exit(-1);
	}

	int size = strlen(src) + 1;// last is '\0';
	*dst = malloc(sizeof(char) * size);
	if (*dst == NULL) {
		perror("malloc memory failed\n");
		exit(-1);
	}

	memset(*dst, 0x0, size);
	memcpy(*dst, src, size);
	(*dst)[location] = value;
}

static void change_arrc(char **p, int location, char *value)
{
	if (p[location] == NULL) {
		perror("malloc memory failed\n");
		exit(-1);
	}
	p[location] = value;
}

static void change_arrii(int *p, int row, int col, int setx, int sety, int value)
{
	if ( (row-1) < setx || (col-1) < sety) {
		perror("out stack\n");
		exit(-1);
	}

	p[setx*col + sety] = value;
}

static void change_arrii2(int (*p)[3], int row, int col, int setx, int sety, int value)
{
	if ( (row-1) < setx || (col-1) < sety) {
		perror("out stack\n");
		exit(-1);
	}

	*(*(p + setx) + sety) = value;
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
	{
		char *c = "hellownihao";
		char *p = c;
		char *q;

		change_string(p, 3, 'c', &q);
		char *mark = q;
		printf("%s \n", mark);
		for (; *q != '\0'; q++) {
			printf("%c", *q);
		}
		printf("\n");
		free(mark);//有可能是因为malloc分配的指针被修改以后，再传给free，导致了munmap错误。你检查一下动态分配的指针有没有中途被修改过
		mark = NULL;
		q = NULL;
	}
// 6. char *[]
	{
		char *c[] = {"hello", "nihao", "home-coder", "one_face", NULL};
		char **p = c;

		change_arrc(p, 2, "own");
		for (; *p != NULL; p++) {
			printf("%s ", *p);
		}
		printf("\n");
	}

// 6-2. 替换数组第2个元素(from 0）里面的第二个字符为'i'
	{
	}

// 7. int[][x]
	{
		int a[][3] = {{0, 2, 4}, {3, 4, 5}, {11, 22, 99}, {5, 3, 7}};
		int *p = a[0];
		int size = sizeof(a)/sizeof(a[0][0]);
		int row = sizeof(a)/sizeof(a[0]);
		int col = 3;
		int i;

		change_arrii(p, row, col, 2, 2, 88);
		for (i = 0; i < size; i++) {
			printf("%d ", *(p + i));
		}
		printf("\n");
	}

// 7-2. int[][x] <===> int(*p)[x]
	{
		int a[][3] = {{0, 2, 4}, {3, 4, 5}, {11, 22, 99}, {5, 3, 7}};
		typedef int (*parri)[3];
		int size = sizeof(a)/sizeof(a[0][0]);
		int row = sizeof(a)/sizeof(a[0]);
		int col = 3;
		int i, j;
		parri p;

		p = a;
		change_arrii2(p, row, col, 2, 2, 88);

		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				printf("%d ", *(*(p + i) + j));
			}
		}
		printf("\n");
	}
// 7-3. int[][x]替换一整行数组inta[2]
	{
		int a[][3] = {{0, 2, 4}, {3, 4, 5}, {11, 22, 99}, {5, 3, 7}};
		int value[] = (33, 44, 88);

		change_arri_row();
	}

	return 0;
}
