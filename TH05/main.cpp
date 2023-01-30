#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#define INPUT "input.inp"
#define MTK "matranke.mtk"
#define maxdinh 20

int P[maxdinh][maxdinh]; //cac dinh cua vat the
int D[maxdinh][maxdinh]; //ma tran ke

int sochieu, sodinh; //so chieu: 3 (XYZ)
int X[maxdinh];
int Y[maxdinh];
int Z[maxdinh];


int phi = 30;

FILE *fp;

void nhaptoado()
{
	int i,j;
	fp = fopen(INPUT,"r");
	if(fp==NULL)
	{
		printf("File not found !");	
	}
	else
	{
		//doc so chieu
		fscanf(fp,"%d",&sochieu);
		//doc so dinh
		fscanf(fp,"%d",&sodinh);
		//doc toa do cac dinh cua vat the
		for(i=0;i<sochieu;i++)
		{
			for(j=0;j<sodinh;j++)
				fscanf(fp,"%d",&P[i][j]);
		}
		fclose(fp);
	}
	//luu cac dong vao X,Y,Z
	for(j=0;j<sodinh;j++)
	{
		X[j]=P[0][j];
		Y[j]=P[1][j];
		Z[j]=P[2][j];
	}
	//in ra man hinh
	printf("So chieu khong gian = %d",sochieu);
	printf("\nSo dinh cua vat the = %d",sodinh);
	printf("\nToa do cac dinh cua vat the la:\n");
	for(i=0;i<sochieu;i++)
	{
		for(j=0;j<sodinh;j++)
			printf("%d ",P[i][j]);
		printf("\n");
	}
}
void matranke()
{
	int i,j;
	fp = fopen(MTK,"r");
	if(fp==NULL)
		printf("File not found !");
	else
	{
		for(i=0;i<sodinh;i++)
			for(j=0;j<sodinh;j++)
				fscanf(fp,"%d",&D[i][j]);
	}
	fclose(fp);
	//in ra ma tran ke
	printf("\nMa tran ke:\n");
	for(i=0;i<sodinh;i++)
	{
		for(j=0;j<sodinh;j++)
			printf("%d ",D[i][j]);
		printf("\n");
	}
}

void oxz() //chieu len truc y = chieu bang (y=0)
{
	int i,j;
	//gan X,Z
	for(i=0;i<sodinh;i++)
		for(j=i+1;j<sodinh;j++)
		{
			if(D[i][j]==1)
			{
				setcolor(GREEN);
				line(X[i],Z[i],X[j],Z[j]);
			}
		}
}

void phepquay(int X[maxdinh],int Z[maxdinh], int xr, int yr,int phi)
{
	int i;
	int dx;
	int dy;
	for(i=0;i<sodinh;i++)
	{
		dx = X[i] - xr;
		dy = Z[i] - yr;
		X[i]=xr+float((dx)*cos(phi*3.1416/180))-float((dy)*sin(phi*3.1416/180));
		Z[i]=xr+float((dx)*sin(phi*3.1416/180))+float((dy)*cos(phi*3.1416/180));																														
	}
	oxz();
}


int main()
{
	nhaptoado();
	matranke();
	initwindow(800,800);
	oxz();
	getch();
}
