#include<cstdio>
#include<iostream>

void seqsearch(int n, const int S[], int x, int& loc)
{
	loc = 0;
	while(loc < n && S[loc] != x)
		loc++;
	if(loc >= n)
		loc = 0;
}

void binsearch(int n, const int S[], int x, int& loc)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	loc = n;

	while(low <= high && loc == n)
	{
		mid = (low + high)/2;
		if(x == S[mid])
			loc = mid;
		else if(x < S[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
}

int fibrec(int n)
{
	if(n <= 1)
		return n;
	else
		return fibrec(n - 1) + fibrec(n - 2);
}

int fibite(int n)
{
	int i;
	int f[n];

	f[0] = 0;
	if(n > 0)
	{
		f[1] = 1;
		for(i = 2; i <= n; i++)
			f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}
void merge(int S[], int low, int mid, int high)
{
    int U[10000];
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (S[i] <= S[j])
            U[k++] = S[i++];
        else
            U[k++] = S[j++];
    }
    while (i <= mid)
        U[k++] = S[i++];
  
    while (j <= high)
        U[k++] = S[j++];
  
	for(int i = 0; i < k; i++)
		S[low + i] = U[i];
}
  
void mergesort(int S[], int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(S, low, m);
        mergesort(S, m + 1, high);
        merge(S, low, m, high);
    }
}

void partition(int S[], int low, int high, int& piv)
{
	int i, j;
	int temp;
	int pivot;
	pivot = S[low];
	j = low;
	for(i = low + 1; i <= high; i++)
		if(S[i] < pivot)
		{
			j++;
			temp = S[i];
			S[i] = S[j];
			S[j] = temp;
		}
	piv = j;
	temp = S[low];
	S[low] = S[piv];
	S[piv] = temp;
}

void quicksort(int S[], int low, int high)
{
	int piv;

	if(high > low)
	{
		partition(S, low, high, piv);
		quicksort(S, low, piv - 1);
		quicksort(S, piv + 1, high);
	}
}

int main(void)
{
	double start, end;
	double result;
	int loc;
	int A1[12000], A2[9000], A3[6000], A4[3000];

	for(int i = 0; i < 12000; i++)
	{
		A1[i] = 12000 - i;
	}
	for(int i = 0; i < 9000; i++)
	{
		A2[i] = 9000 - i;
	}
	for(int i = 0; i < 6000; i++)
	{
		A3[i] = 6000 - i;
	}
	for(int i = 0; i < 3000; i++)
	{
		A4[i] = 3000 - i;
	}
	
	start = clock();
	for(int i = 0; i < 10000; i++)
		seqsearch(3000, A1, 0, loc);
	end = clock();
	result = (end - start) / 10000;
	printf("seq1 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 10000; i++)
		seqsearch(6000, A1, 0, loc);
	end = clock();
	result = (end - start) / 10000;
	printf("seq2 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 10000; i++)
		seqsearch(9000, A1, 0, loc);
	end = clock();
	result = (end - start) / 10000;
	printf("seq3 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 10000; i++)
		seqsearch(12000, A1, 0, loc);
	end = clock();
	result = (end - start) / 10000;
	printf("seq4 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 10000000; i++)
		binsearch(3000, A1, 0, loc);
	end = clock();
	result = (end - start) / 10000000;
	printf("bin1 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 10000000; i++)
		binsearch(6000, A1, 0, loc);
	end = clock();
	result = (end - start) / 10000000;
	printf("bin2 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 10000000; i++)
		binsearch(9000, A1, 0, loc);
	end = clock();
	result = (end - start) / 10000000;
	printf("bin3 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 10000000; i++)
		binsearch(12000, A1, 0, loc);
	end = clock();
	result = (end - start) / 10000000;
	printf("bin4 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 100000; i++)
		fibite(3000);
	end = clock();
	result = (end - start) / 100000;
	printf("fibite1 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 100000; i++)
		fibite(6000);
	end = clock();
	result = (end - start) / 100000;
	printf("fibite2 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 100000; i++)
		fibite(9000);
	end = clock();
	result = (end - start) / 100000;
	printf("fibite3 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 100000; i++)
		fibite(12000);
	end = clock();
	result = (end - start) / 100000;
	printf("fibite4 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 1000000; i++)
		fibrec(10);
	end = clock();
	result = (end - start) / 1000000;
	printf("fibrec1 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 100000; i++)
		fibrec(20);
	end = clock();
	result = (end - start) / 100000;
	printf("fibrec2 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 100; i++)
		fibrec(30);
	end = clock();
	result = (end - start) / 100;
	printf("fibrec3 : %.13lf\n", result);

	start = clock();
	fibrec(40);
	end = clock();
	result = end - start;
	printf("fibrec4 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 10000; i++)
		mergesort(A4, 0, 1000);
	end = clock();
	result = (end - start) / 10000;
	printf("mergesort1 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 1000; i++)
		mergesort(A3, 0, 2000);
	end = clock();
	result = (end - start) / 1000;
	printf("mergesort2 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 1000; i++)
		mergesort(A2, 0, 4000);
	end = clock();
	result = (end - start) / 1000;
	printf("mergesort3 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 100; i++)
		mergesort(A1, 0, 8000);
	end = clock();
	result = (end - start) / 100;
	printf("mergesort4 : %.13lf\n", result);

	for(int i = 0; i < 12000; i++)
	{
		A1[i] = 12000 - i;
	}
	for(int i = 0; i < 9000; i++)
	{
		A2[i] = 9000 - i;
	}
	for(int i = 0; i < 6000; i++)
	{
		A3[i] = 6000 - i;
	}
	for(int i = 0; i < 3000; i++)
	{
		A4[i] = 3000 - i;
	}

	start = clock();
	for(int i = 0; i < 1000; i++)
		quicksort(A4, 0, 1000);
	end = clock();
	result = (end - start) / 1000;
	printf("quicksort1 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 100; i++)
		quicksort(A3, 0, 2000);
	end = clock();
	result = (end - start) / 100;
	printf("quicksort2 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 10; i++)
		quicksort(A2, 0, 4000);
	end = clock();
	result = (end - start) / 10;
	printf("quicksort3 : %.13lf\n", result);

	start = clock();
	for(int i = 0; i < 10; i++)
		quicksort(A1, 0, 8000);
	end = clock();
	result = (end - start) / 10;
	printf("quicksort4 : %.13lf\n", result);

	return 0;
}
