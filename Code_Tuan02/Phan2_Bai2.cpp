#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define MAXSIZE 100

struct HonSo
{
	int phanNguyen, tuSo, mauSo;
};

void tao_HonSo(HonSo a[], int &n)
{
	printf("Nhap so luong phan tu:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		a[i].phanNguyen=rand()%10;
		a[i].tuSo=rand()%10;
		int t=rand()%10;
		if (t!=0)
		{
			a[i].mauSo=t;
		}
		else t=1;
	}
}

int SoSanh_HonSo(HonSo a, HonSo b)
{
	if (a.phanNguyen>b.phanNguyen)
	{
		return 1;
	}
	else if (a.phanNguyen<b.phanNguyen)
	{
		return -1;
	}
	else if (a.phanNguyen==b.phanNguyen)
	{
		int tong1 = (float) a.tuSo / a.mauSo;
		int tong2 = (float) b.tuSo / b.mauSo;
		if (tong1>tong2)
		{
			return 1;
		}
		else if (tong1<tong2)
		{
			return -1;
		}
		else return 0;
	}
}

void xuat_HonSo(HonSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Hon so thu %d: %d va %d/%d\n", i+1,a[i].phanNguyen, a[i].tuSo, a[i].mauSo);
	}
}

void chuyen_HonSo_ThanhPhanSo(HonSo a[], int n)
{
	int newTu, newMau;
	for (int i = 0; i < n; i++)
	{
		newTu=a[i].phanNguyen*a[i].mauSo + a[i].tuSo;
		newMau=a[i].mauSo;
		printf("Ket qua cua hon so thu %d :%d/%d\n", i+1, newTu, newMau);
	}
}

void chuyen_PhanSo_ThanhHonSo(int tu, int mau)
{
	int thuong = tu/mau;
	int phandu = tu%mau;
	printf("Ket qua: %d va %d/%d\n", thuong, phandu, mau);
}

void Tinh_HonSo(HonSo a, HonSo b)
{
	float t1 = (float)(a.phanNguyen*a.mauSo + a.tuSo)/a.mauSo;
	float t2 = (float)(b.phanNguyen*b.mauSo + b.tuSo)/b.mauSo;
	float Tong = t1+t2;
	float Hieu = t1-t2;
	float Tich = t1 * t2;
	float Thuong = t1 / t2;
	printf("Tong: %.2f\n", Tong);
	printf("Hieu: %.2f\n", Hieu);
	printf("Tich: %.2f\n", Tich);
	printf("Thuong: %.2f\n", Thuong);
}

void swap(HonSo &a, HonSo &b)
{
	HonSo temp = a;
	a = b;
	b = temp;
}

void Interchange_Sort(HonSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanh_HonSo(a[i],a[j])==1)
			{
				swap(a[i], a[j]);
			}
		}
	}
}

void Selection_Sort(HonSo a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanh_HonSo(a[j],a[min])==-1)
			{
				min = j;
			}
		}

		swap(a[i], a[min]);
	}
}

int partition(HonSo arr[], int low, int high)
{
	HonSo pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (SoSanh_HonSo(arr[j],pivot)==-1)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void Quick_Sort(HonSo a[], int low, int high)
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
	HonSo b[MAXSIZE];
	int n;
	tao_HonSo(b,n);
	xuat_HonSo(b,n);
	printf("\n-------------------------\n");
	HonSo a1=b[0];
	HonSo a2=b[1];
	printf("Ta co 2 hon so:\n");
	printf("Hon so a:%d va %d/%d\n", a1.phanNguyen, a1.tuSo, a1.mauSo);
	printf("Hon so b:%d va %d/%d\n", a2.phanNguyen, a2.tuSo, a2.mauSo);
	printf("Ket qua So Sanh hai hon so a va b\n");
	if (SoSanh_HonSo(a1,a2)==1)
	{
		printf("Phan so a lon hon phan so b\n");
	}
	else if (SoSanh_HonSo(a1,a2)==-1)
	{
		printf("Phan so a nho hon phan so b\n");
	}
	else printf("Phan so a bang phan so b\n");
	printf("\n-------------------------\n");
	printf("CHUYEN DOI HON SO VE PHAN SO\n");
	chuyen_HonSo_ThanhPhanSo(b,n);
	printf("\n-------------------------\n");
	printf("CHUYEN DOI PHAN SO VE HON SO\n");
	printf("Ta co phan so:7/5\n");
	chuyen_PhanSo_ThanhHonSo(7,5);
	printf("\n-------------------------\n");
	printf("\nTong hieu tich thuong 2 hon so\n");
	printf("Ta co 2 hon so:\n");
	printf("Hon so a:%d va %d/%d\n", b[0].phanNguyen, b[0].tuSo, b[0].mauSo);
	printf("Hon so b:%d va %d/%d\n", b[1].phanNguyen, b[1].tuSo, b[1].mauSo);
	printf("Ket qua cua TONG, HIEU, TICH, THUONG hai hon so a va b\n");
	printf("Hon so a:%d va %d/%d\n", b[0].phanNguyen, b[0].tuSo, b[0].mauSo);
	printf("Hon so b:%d va %d/%d\n", b[1].phanNguyen, b[1].tuSo, b[1].mauSo);
	Tinh_HonSo(b[0],b[1]);
	printf("\n-------------------------\n");
	printf("INTERCHANGE SORT\n");
	Interchange_Sort(b,n);
	xuat_HonSo(b,n);
	printf("\n-------------------------\n");
	printf("SELECTION SORT\n");
	Selection_Sort(b,n);
	xuat_HonSo(b,n);
	printf("\n-------------------------\n");
	printf("QUICK SORT\n");
	Quick_Sort(b,0,n-1);
	xuat_HonSo(b,n);
	getch();
	return 0;
}