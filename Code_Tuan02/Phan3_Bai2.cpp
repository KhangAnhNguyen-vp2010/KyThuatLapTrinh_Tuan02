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

void xuat_HonSo(HonSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Hon so thu %d: %d va %d/%d\n", i+1,a[i].phanNguyen, a[i].tuSo, a[i].mauSo);
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

void swap(HonSo &a, HonSo &b)
{
	HonSo temp = a;
	a = b;
	b = temp;
}

int tim_Kiem_LinearSearch(HonSo a[], int n, HonSo x)
{
	for (int i = 0; i < n; i++)
	{
		if (SoSanh_HonSo(x,a[i])==0)
		{
			return i;
		}
	}
	return -1;
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

int tim_Kiem_BinarySearch(HonSo a[], int n, HonSo x)
{
	int left = 0, right = n - 1, middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (SoSanh_HonSo(a[middle],x)==0)
		{
			return middle;
		}
		else if (SoSanh_HonSo(a[middle],x)==1)
		{
			right = middle - 1;
		}
		else if (SoSanh_HonSo(a[middle],x)==-1)
		{
			left = middle + 1;
		}
	}
	return -1;
}

void SapXep(HonSo a[], int n)
{
	int left=0;
	int right=n-1;
	while (left<right)
	{
		while (a[left].phanNguyen%2==0 && left<right)
		{
			left++;
		}

		while (a[right].phanNguyen%2!=0 && left<right)
		{
			right--;
		}

		if (left < right)
		{
			swap(a[left],a[right]);
			left++;
			right--;
		}
	}
}

void xoa_PT(HonSo a[], int &n, int vitri)
{
	for (int i = vitri; i < n; i++)
	{
		a[i]=a[i+1];
	}
	n--;
}

void them_PT(HonSo a[], int &n, HonSo k, int vitri)
{
	for (int i = n; i > vitri; i--)
	{
		a[i]=a[i-1];
	}
	a[vitri]=k;
	n++;
}

struct PhanSo
{
	int tu, mau;
};

void chuyen_HonSo_ThanhPhanSo(HonSo a[], int n, PhanSo c[])
{
	for (int i = 0; i < n; i++)
	{
		c[i].tu=a[i].phanNguyen*a[i].mauSo + a[i].tuSo;
		c[i].mau=a[i].mauSo;
	}
}

void xuat_PhanSo(PhanSo c[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Phan so thu %d: %d/%d\n", i+1, c[i].tu, c[i].mau);
	}
}

float giaTri_HonSo(HonSo a)
{
	return (float)(a.phanNguyen*a.mauSo + a.tuSo)/a.mauSo;
}

float sum_HonSo(HonSo a[], int n)
{
	float tong=0;
	for (int i = 0; i < n; i++)
	{
		tong+=giaTri_HonSo(a[i]);
	}
	return tong;
}

void tim_Max(HonSo a[], int n)
{
	float max=0;
	for (int i = 0; i < n; i++)
	{
		if (giaTri_HonSo(a[i])>=max)
		{
			max=giaTri_HonSo(a[i]);
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (giaTri_HonSo(a[j])==max)
		{
			printf("Phan tu lon nhat la: %d va %d/%d\n", a[j].phanNguyen, a[j].tuSo, a[j].mauSo);
		}
	}
}

void tim_Min(HonSo a[], int n)
{
	float min=giaTri_HonSo(a[0]);
	for (int i = 0; i < n; i++)
	{
		if (giaTri_HonSo(a[i])<=min)
		{
			min=giaTri_HonSo(a[i]);
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (giaTri_HonSo(a[j])==min)
		{
			printf("Phan tu nho nhat la: %d va %d/%d\n", a[j].phanNguyen, a[j].tuSo, a[j].mauSo);
		}
	}
}

void xuatVT_PhanNguyenChan(HonSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].phanNguyen%2==0)
		{
			printf("Vi tri %d\n", i+1);
		}
	}
}

void xuat_ViTri_Max(HonSo a[], int n)
{
	float max=0;
	for (int i = 0; i < n; i++)
	{
		if (giaTri_HonSo(a[i])>=max)
		{
			max=giaTri_HonSo(a[i]);
		}
	}

	for (int j = 0; j < n; j++)
	{
		if (giaTri_HonSo(a[j])==max)
		{
			printf("Vi tri Max: %d\n", j+1);
		}
	}
}

void xuat_ViTri_Min(HonSo a[], int n)
{
	float min=giaTri_HonSo(a[0]);
	for (int i = 0; i < n; i++)
	{
		if (giaTri_HonSo(a[i])<=min)
		{
			min=giaTri_HonSo(a[i]);
		}
	}

	for (int j = 0; j < n; j++)
	{
		if (giaTri_HonSo(a[j])==min)
		{
			printf("Vi tri Max: %d\n", j+1);
		}
	}
}

int main()
{
	HonSo a[MAXSIZE];
	int n;
	tao_HonSo(a,n);
	xuat_HonSo(a,n);
	printf("\n----------------------------------\n");
	printf("Ta co hon so: %d va %d/%d\n", a[1].phanNguyen, a[1].tuSo, a[1].mauSo);
	printf("Tim kiem hon so tren trong mang\n");
	if (tim_Kiem_LinearSearch(a,n,a[1])!=-1)
	{
		printf("=>>Da tim thay!!!");
	}
	else printf("=>>Khong tim thay!!!");
	printf("\n----------------------------------\n");
	printf("PHAN NGUYEN CHAN DAU MANG - PHAN NGUYEN LE CUOI MANG\n");
	SapXep(a,n);
	xuat_HonSo(a,n);
	printf("\n----------------------------------\n");
	printf("Ta co hon so: %d va %d/%d\n", a[3].phanNguyen, a[3].tuSo, a[3].mauSo);
	printf("Tim kiem hon so tren trong mang\n");
	Interchange_Sort(a,n);
	xuat_HonSo(a,n);
	if (tim_Kiem_BinarySearch(a,n,a[3])!=-1)
	{
		printf("=>>Da tim thay!!!");
	}
	else printf("=>>Khong tim thay!!!");
	printf("\n----------------------------------\n");
	printf("\nXOA PHAN TU\n");
	int vitri;
	printf("Nhap vi tri:");
	scanf("%d", &vitri);
	xoa_PT(a,n,vitri-1);
	xuat_HonSo(a,n);
	printf("\n----------------------------------\n");
	printf("\nTHEM PHAN TU\n");
	int vitri2;
	HonSo k;
	printf("Nhap vi tri:");
	scanf("%d", &vitri2);
	printf("Nhap Hon So:\n");
	printf("Nhap phan nguyen:");
	scanf("%d", &k.phanNguyen);
	printf("Nhap phan tu so:");
	scanf("%d", &k.tuSo);
	printf("Nhap phan mau so:");
	scanf("%d", &k.mauSo);
	while (k.mauSo==0)
	{
		printf("Mau so phai > 0, Nhap lai:");
		scanf("%d", &k.mauSo);
	}
	them_PT(a,n,k,vitri2-1);
	xuat_HonSo(a,n);
	printf("\n----------------------------------\n");
	printf("TAO MANG PHAN SO c CHUA PHAN TU HON SO CUA MANG a\n");
	PhanSo c[MAXSIZE];
	chuyen_HonSo_ThanhPhanSo(a,n,c);
	xuat_PhanSo(c,n);
	printf("\n----------------------------------\n");
	printf("Tong cac phan tu cua mang la: %.2f\n", sum_HonSo(a,n));
	printf("\n----------------------------------\n");
	printf("PHAN TU MAX\n");
	tim_Max(a,n);
	printf("PHAN TU MIN\n");
	tim_Min(a,n);
	printf("\n----------------------------------\n");
	printf("Cac vi tri phan tu co phan nguyen chan la:\n");
	xuatVT_PhanNguyenChan(a,n);
	printf("\n----------------------------------\n");
	printf("XUAT VI TRI PHAN TU MAX\n");
	xuat_ViTri_Max(a,n);
	printf("XUAT VI TRI PHAN TU MIN\n");
	xuat_ViTri_Min(a,n);
	getch();
	return 0;
}