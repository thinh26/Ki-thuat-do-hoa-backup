#include <graphics.h> //line
#include <stdio.h> //prinf, scanf
#include <stdlib.h> //FILE
#include <math.h>

#define INPUT "chopnhon.inp"
#define MTK "chopnhon.mtk"

#define maxdinh 20

int P[maxdinh][maxdinh]; //Cac dinh cua vat the
int D[maxdinh][maxdinh]; //Ma tran ke
int R[3][maxdinh];
int sodinh,sochieu; // so chieu = 3 (XYZ)
int X[maxdinh];
int Y[maxdinh];
int Z[maxdinh];
float T[3][3]; //Ma tran bien doi
int phi = 30;
float L = 0.5; //L>1 (dai ra), L<1 (nho lai)


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
			for(j=0;j<sodinh;j++)
				fscanf(fp,"%d",&P[i][j]);
		fclose(fp);
	}
	//luu cac dong vao X,Y,Z
	/*for(j=0;j<sodinh;j++)
	{
		X[j]=P[0][j];
		Y[j]=P[1][j];
		Z[j]=P[2][j];
	}*/
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
	fp=fopen(MTK,"r");
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
	printf("Ma tran ke:\n");
	for(i=0;i<sodinh;i++)
	{
		for(j=0;j<sodinh;j++)
			printf("%d ",D[i][j]);
		printf("\n");
	}		
}
void matranbiendoiZ()
{
	int i,j;
	T[0][0]=1;
	T[0][1]=0;
	T[0][2]=(float)L*cos(phi*3.1416/180);
	
	T[1][0]=0;
	T[1][1]=1;
	T[1][2]=(float)L*sin(phi*3.1416/180);
	
	T[2][0]=0;
	T[2][1]=0;
	
	printf("\nMa tran bien doi:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%1.f ",T[i][j]);
	printf("\n");
	}
}

void oblique()
{
	int i,j,k;
	//khoi tao ma tran ket qua
	for(i=0;i<sochieu;i++)
	{
		for(j=0;j<sodinh;j++)
			R[i][j]=0;
	}
	
	//Nhan 2 ma tran
	for(i=0;i<sochieu;i++) //hang P
	{
		for(j=0;j<sodinh;j++) //cot P
			for(k=0;k<3;k++)
				R[i][j]+=T[i][k]*P[k][j];
	}
				
	printf("\nMa tran ket qua:\n");
	for(i=0;i<sochieu;i++)
	{
		for(j=0;j<sodinh;j++)
			printf("%d ",R[i][j]);
		printf("\n");
	}
}
void oxy() //chieu len truc z (z=0)
{
	int i,j;
	//gan X,Y
	for(i=0;i<sodinh;i++)
	{
		X[i]=R[0][i];
		Y[i]=R[1][i];
	}
	
	for(i=0;i<sodinh;i++)
		for(j=i+1;j<sodinh;j++)
		{
			if(D[i][j]==1)
			{
				setcolor(GREEN);
				line(X[i],Y[i],X[j],Y[j]);
			}
		}
}
/*void oxz() //chieu len truc y = chieu bang (y=0)
{
	int i,j;
	//gan X,Z
	for(i=0;i<sodinh;i++)
	{
		X[i]=R[0][i];
		Z[i]=R[1][i];
	}
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
void oyz() //chieu len truc x  = chieu canh (x=0)
{
	int i,j;
	for(i=0;i<sodinh;i++)
		for(j=i+1;j<sodinh;j++)
		{
			if(D[i][j]==1)
			{
				setcolor(GREEN);
				line(Y[i],Z[i],Y[j],Z[j]);
			}
		}
}
*/
int main()
{
	nhaptoado();
	matranke();
	initwindow(800,800);
	/*while(true)
	{
		for(phi=0;phi<360;phi++)
		{
			matranbiendoiZ();
			oblique();
			
			oxy();
			delay(20);
			cleardevice();
		}
	}*/
	
	matranbiendoiZ();
	oblique();
	oxy();
	/*oxy();
	oxz();
	oyz();*/
	getch();
	
	return 0;
}
