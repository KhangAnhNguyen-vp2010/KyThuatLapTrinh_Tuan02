#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define MAXSIZE 100

void tao_Mang_PhanTu15(int a[], int &n)
{
	printf("Nhap so luong phan tu:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t = rand() % 100;
		if (t >= 15)
		{
			a[i] = t;
		}
		else a[i] = 15;
	}
}

void tao_Mang_PhanTuChan(int a[], int &n)
{
	printf("Nhap so luong phan tu:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t = rand() % 100;
		if (t % 2 == 0)
		{
			a[i] = t;
		}
		else a[i] = t + 1;
	}
}

void xuat_Mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int tim_Kiem_LinearSearch(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (x == a[i])
		{
			return i;
		}
	}
	return -1;
}

void Interchange_Sort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i]>a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

int tim_Kiem_BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (a[middle] == x)
		{
			return middle;
		}
		else if (a[middle]>x)
		{
			right = middle - 1;
		}
		else if (a[middle]<x)
		{
			left = middle + 1;
		}
	}
	return -1;
}

void Selection_Sort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j]<a[min])
			{
				min = j;
			}
		}

		swap(a[i], a[min]);
	}
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void Quick_Sort(int a[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(a, low, high);
		Quick_Sort(a, low, pi - 1);
		Quick_Sort(a, pi + 1, high);
	}
}

int main()
{
	int a[MAXSIZE];
	int n1;
	tao_Mang_PhanTu15(a, n1);
	xuat_Mang(a, n1);
	printf("\n------------------------------------------\n");
	int b[MAXSIZE];
	int n2;
	tao_Mang_PhanTuChan(b, n2);
	xuat_Mang(b, n2);
	printf("\n------------------------------------------\n");
	printf("TIM KIEM LINEAR SEARCH\n");
	int x;
	printf("Nhap x:");
	scanf("%d", &x);
	if (tim_Kiem_LinearSearch(a, n1, x) == -1)
	{
		printf("Khong tim thay!!!");
	}
	else printf("Tim thay!!! X o vi tri a[%d]", tim_Kiem_LinearSearch(a, n1, x));
	printf("\n------------------------------------------\n");
	printf("Sap xep Interchange Sort\n");
	Interchange_Sort(a, n1);
	xuat_Mang(a, n1);
	printf("\n------------------------------------------\n");
	printf("TIM KIEM BINARY SEARCH\n");
	int x1;
	printf("Nhap x:");
	scanf("%d", &x1);
	if (tim_Kiem_BinarySearch(a, n1, x1) == -1)
	{
		printf("Khong tim thay!!!");
	}
	else printf("Tim thay!!! X o vi tri a[%d]", tim_Kiem_BinarySearch(a, n1, x1));
	printf("\n------------------------------------------\n");
		printf("Sap xep Selection Sort\n");
	int d[MAXSIZE] = { 8, 7, 9, 4, 2 };
	printf("Truoc khi sap xep:\n");
	xuat_Mang(d, 5);
	printf("\n");
	printf("Sau khi sap xep:\n");
	Selection_Sort(d, 5);
	xuat_Mang(d, 5);
	printf("\n------------------------------------------\n");
	printf("Sap xep Quick Sort\n");
	int c[MAXSIZE] = { 5, 4, 2, 3, 1 };
	printf("Truoc khi sap xep:\n");
	xuat_Mang(c, 5);
	printf("\n");
	printf("Sau khi sap xep:\n");
	Quick_Sort(c, 0, 4);
	xuat_Mang(c, 5);
	getch();
	return 0;
}