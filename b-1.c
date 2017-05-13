#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
// 1. 	int
//  		int a = 0;
// 2.	char
//  		char c = 'a';
// 3.	int[]
//  		int a[] = {1, 3, 4, 2};
//
// 4.	char[]
//  		char c[] = {'a', 'c', 'r', 'd'};
// 5.	char *
//  		char *c = "hellownihao";
// 6.   char *[]
//  		char *c[] = {"hello", "nihao", "home-coder", "one_face", NULL};
//		char *value = "own";
// 6-2. 替换数组第2个元素(from 0）里面的第二个字符为'i', home-coder-->hoie-coder
//  		char *c[] = {"hello", "nihao", "home-coder", "one_face", NULL};
// 7.	int[][x]
//  		int a[][3] = {{0, 2, 4}, {3, 4, 5}, {11, 22, 99}, {5, 3, 7}};
// 7-2. int[][x] <===> int(*p)[x]
//  		int a[][3] = {{0, 2, 4}, {3, 4, 5}, {11, 22, 99}, {5, 3, 7}};
// 7-3. 方法一 : int[][x]替换一整行数组inta[2]
//  		int a[][3] = {{0, 2, 4}, {3, 4, 5}, {11, 22, 99}, {5, 3, 7}};
//  		int value[] = {33, 44, 88};
// 7-4. 方法二 : int[][x]替换一整行数组inta[2]， 直接使用一维的一个整形指针，而不是使用二维数组指针.
//			int a[][3] = {{0, 2, 4}, {3, 4, 5}, {55, 66, 77}, {5, 3, 7}};
//			int value[] = {11, 22, 99};

	return 0;
}
