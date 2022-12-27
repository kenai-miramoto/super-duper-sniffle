#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>/*
int fun1(int x, int y);
int fun2(int n, int m);
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("zdgys= %d zxgbs= %d", fun1(a, b), fun2(a, b));
	return 0;
}
int fun1(int x, int y)
{
	int c;
	c = x % y;
	while (c != 0)
	{
		x = y;
		y = c;
		c = x % y;
	}

	return (y);
}
int fun2(int n, int m)
{
	
	int t;
	t = n * m / fun1(n, m);
	return t;
}*/
double fact(int n)
{
	int i;
	double res = 1.0;
	for (i = 1; i <= n; i++)
	{
		res = 1.0*res * i;
	}
	return res;
}
double multe(int n)
{
	int i;
	double res = 1.0;
	for (i = 3; i <= n; i = i + 2)
	{
		res = 1.0*res * i;
	}
	return res;
}
int main()
{
	int i;
	double sum, item, eps;
	eps = 1E-6;
	sum = 1;
	item = 1;
	for (i = 1; item > eps; i++)
	{
		item = fact(i) / multe(2 * i + 1);
		sum += item;
	}
	printf("PL=%0.5lf\n", sum * 2);
	return 0;
}