
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define getMax(a,b) a>b?a:b

#define f 0
#define t !f

int getmax(int* a, int n)
{
	int max = a[0];
	size_t i = 0;
	for (i = 1; i < n; ++i)
		max = getMax(max, a[i]);
	return max;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

double pow(long long a, int b)
{
	if (!b)return (double)1;
	long long res = a;
	if (b < 0)
	{
		++b;
		while(b)
		{
			res *= a;
			++b;
		}
		return (double)((double)1 / res);
	}else{
		--b;
		while (b)
		{
			res *= a;
			--b;
		}
	}
	return (double)res;
}


void printVector(int *a, int n)
{
	size_t i = 0;
	for (i = 0; i<n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

void bubbleSort(int *a, int n)
{
	short swpd = f;
	size_t i = 0, j = 0;
	for (i = 0; i<n; ++i)
	{
		for (j = 0; j<n - i - 1; ++j)
			if (a[j]>a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				swpd = t;
			}
		if (!swpd)
			break;
	}
	printf("\nBubbleSort: \n");
	printVector(a, n);
}

void naiveSort(int *a, int n)
{
	size_t i = 0, j = 0;
	for (i = 0; i<n; ++i)
		for (j = 0; j<i; ++j)
			if (a[i]<a[j])
				swap(&a[i], &a[j]);
	printf("\nNaiveSort: \n");
	printVector(a, n);
}
void countSort(int *a, int n)//DOES NOT WORK WITH NEGATIVE VALUES
{
	int* out = (int*)malloc(sizeof(int)*n);
	const int SIZE = getmax(a, n)+1;
	int* count = (int*)malloc(sizeof(int)*SIZE);
	size_t i = 0;

	for (i = 0; i < SIZE; ++i)
		count[i] = 0;

	for (i = 0; i < n; ++i)
		count[a[i]]++;

	for (i = 1; i < SIZE; ++i)
		count[i] += count[i - 1];

	for (i = 0; i < n; ++i)
	{
		out[count[a[i]] - 1] = a[i];
		--count[a[i]];
	}

	for (i = 0; i < n; ++i)
		a[i] = out[i];
	free(out);
	free(count);

	printf("\nCountSort:\n");
	printVector(a,n);
}
void countSort(int *a, int n, int e)
{
	int* out =(int*) malloc(sizeof(int)*n);
	int count[10];
	int i;
	for (i = 0; i < 10; ++i)
		count[i] = 0;

	for (i = 0; i < n; i++)
		count[(a[i] / e) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i=n-1;i>=0;--i)
	{
		out[count[(a[i] / e) % 10] - 1] = a[i];
		count[(a[i] / e) % 10] --;
	}

	for (i = 0; i < n; ++i)
		a[i] = out[i];
	free(out);
}

void radixSort(int *a, int n)
{
	int m = getmax(a,n);
	for (int e = 1; m / e > 0; e *= 10)
		countSort(a,n,e);
	printf("\nRadixSort: \n");
	printVector(a, n);
}

void scrambleElements(int *a, int n)
{
	size_t i = 0;
	srand(time(NULL));
	int r = rand() % (int)(n / 2) + 1;
	for (i = 0; i<n / 2; ++i)
		swap(&a[(i + r) % (n / 2)], &a[(i + (int)(n / 2) + r) % n]);
	printf("\nScrambled:\n");
	printVector(a, n);
}




int main()
{
	int a[] = { 170, 45, 75, 90, 802, 24, 2, 66, 500 },
		n = sizeof(a) / sizeof(a[0]);
	printVector(a, n);

	bubbleSort(a, n);
	scrambleElements(a, n);
	naiveSort(a, n);
	scrambleElements(a, n);
	countSort(a, n);
	scrambleElements(a, n);
	radixSort(a, n);

	return 0;
}
