
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Given an Arithmetic progression (a[x]=a[x-1]+1), and a missing element
in the progression, please find the element that is missing with
an algorithm that has its complexity O(log N)
*/


int findValue(int* a, int l, int r)
{
	if (r >= l)
	{
		int m = l + (r - l) / 2;
		if (a[m - 1] + 2 == a[m])
			return a[m] - 1;
		if (a[m] + 2 == a[m + 1])
			return a[m + 1] - 1;
		if (a[m] == m)
			return findValue(a, m + 1, r);
		return findValue(a, l, m - 1);
	}
	return -1;
}

int main()
{
	int a[] = { 0,1,2,3,4,5,6,7,9,10,11,12,13 };
	int n = sizeof(a) / sizeof(int);
	printf("n=%d\n", n);
	printf("Element that is missing: %d\n", findValue(a, 0, n));




	//bigger vector
	n = 1 << 27 -1;
	int *b = (int*)(malloc(sizeof(int)*(n+1)));
	if (b)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i < 20450)
				b[i] = i;
			else
				b[i] = i + 1;
		}
		printf("n=%d\n", n);
		printf("Element that is missing: %d\n", findValue(b, 0, n));
		free(b);
	}
	return 0;
}