#include <graphics.h>
#include <stdio.h>
#include <math.h>
#define maxdinh 10
//Khai bao bien
int sodinh;
int A[maxdinh][2];
float he_so_goc[maxdinh];
int ymin,ymax;
int x_giao_diem[maxdinh];

int min(int a, int b)
{
	return (a<b)? 1:0; //Neu dung tra ve 1, sai tra ve 0
}
int max(int a, int b)
{
	return (a>b)? 1:0; //Neu dung tra ve 1, sai tra ve 0
}
void nhaptoado(int A[maxdinh][2])
{
	printf("Nhap so dinh cua da giac: ");
	scanf("%d",&sodinh);
	int i,j;
	for(i=0;i<sodinh;i++)
	{
		printf("Toa do cac thu %d: \n",i);
		for(j=0;j<2;j++)
		{
			printf("A[%d][%d] = ",i,j);
			scanf("%d",&A[i][j]);
		}
	}
	//gan them mot dinh ket thuc = bat dau
	A[sodinh][0]=A[0][0];
	A[sodinh][1]=A[0][1];
	sodinh++;
	
	printf("Toa do cac dinh cua da giac \n");
	printf("X   Y\n");
	for(i=0;i<sodinh;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	//Tim he so goc
	for(i=0;i<sodinh-1;i++)
	{
		if(A[i][0]==A[i+1][0])
		{
			he_so_goc[i]=99999; // vo cung (+00)
		}
		else
		{
			if(A[i][0]==A[i][1])
			{
				he_so_goc[i]=1;
			}
			else
			{
				he_so_goc[i]=(float)((A[i+1][1]-A[i][1])/(A[i+1][0]-A[i][0]));
			}
		}
	}
	printf("\nHe so goc cua cac canh la: \n");
	for(i=0;i<sodinh-1;i++)
	{
		printf("%.2f\t",he_so_goc[i]);
	}
	//tim y min va y max
	ymin = A[0][1];
	ymax = A[0][1];
	for(i=0;i<sodinh;i++)
	{
		if(min(ymin,A[i][1])==0)
		{
			ymin = A[i][1];	
		}
	}
	for(i=0;i<sodinh;i++)
	{
		if(max(ymax,A[i][1])==0)
		{
			ymax = A[i][1];	
		}
	}
	printf("\n\nymin = %d va ymax = %d\n",ymin,ymax);
}
void scanline(int A[maxdinh][2], int color)
{
	int x,y;
	int dem = 0;
	//xet tung dong quet
	for(y=ymin;y<ymax;y++)
	{
		dem=0;
		// duyet tung canh cua da giac	
		for(int i=0;i<sodinh-1;i++)
		{
			if(y<A[i][1] && y<A[i+1][1] || y>A[i][1] && y>A[i+1][1]) 
				printf("\nVoi y = %d, khong co giao diem",y);
			else 
			{
				// xac dinh hoanh do giao diem
				x=round(A[i][0] + (float)(y - A[i][1]) / he_so_goc[i]);
				x_giao_diem[dem]=x;
				dem++;
				printf("\nVoi y = %d, giao diem [%d] = (%d,%d)",y,i,x,y);
			}
			
			// sap xep lai cac giao diem
			int k;
			int tam;
			for(k=0;k<dem-1;k++)
			{
				if(x_giao_diem[k]>x_giao_diem[k+1])
				{
					tam=x_giao_diem[k];
					x_giao_diem[k]=x_giao_diem[k+1];
					x_giao_diem[k+1]=tam;
				}
			}
			
			// to mau bang cach noi cac duong thang giao diem
			setcolor(color);
			for(k=0;k<dem-1;k=k+2)
			{
				line(x_giao_diem[k],y,x_giao_diem[k+1],y);	
			}
		}
	}	
}
void vedagiac()
{
	int i;
	for(i=0;i<sodinh;i++)
		setlinestyle(1,0,3);
		setcolor(WHITE);
		for(i=0;i<sodinh-1;i++)
		{
			line(A[i][0],A[i][1],A[i+1][0],A[i+1][1]);
		}
}
//Chuong trinh chinh
int main()
{
	nhaptoado(A);
	initwindow(600,600);
	vedagiac();
	scanline(A,4);
	getch();
}
