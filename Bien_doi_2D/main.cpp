#include <graphics.h> //line
#include <stdio.h> //printf scanf
#include <math.h>
#define maxdinh 20

int X[maxdinh];	//hoanh do cac dinh
int Y[maxdinh]; //tung do cac dinh
int sodinh;
float sx, sy; //he so s

void nhaptoado(int X[maxdinh], int Y[maxdinh])
{
	printf("So dinh cua da giac: ");
	scanf("%d",&sodinh);
	int i,j;
	for (i=0;i<sodinh;i++)
 	{
 		printf("Toa do x cho canh %d = ",i);
 		scanf("%d",&X[i]);
 		printf("Toa do y cho canh %d = ",i);
 		scanf("%d",&Y[i]);
	}
	printf("Nhap he so sx: ");
	scanf("%f",&sx);
	printf("Nhap he so sy: ");
	scanf("%f",&sy);
}
void vedagiac()
{
 	int i;
 	X[sodinh]=X[0];
 	Y[sodinh]=Y[0];
 	for(i=0;i<sodinh;i++)
 	{
 		setlinestyle(1,0,3);
 		setcolor(WHITE);
 		line(X[i],Y[i],X[i+1],Y[i+1]);	
	}
}
void tinhtien(int X[maxdinh], int Y[maxdinh], int tx, int ty)
{
	int i;
	for(i=0;i<sodinh;i++)
	{
		X[i]+=tx;
		X[i]+=ty;
	}
	vedagiac();
}
void phepquay(int X[maxdinh], int Y[maxdinh], int xr, int yr, int phi)
{
	int i;
	int dx;
	int dy;
	for (i=0;i<sodinh;i++)
	{
		dx = X[i]-xr;
		dy = Y[i]-yr;
		X[i]=xr+float((dx)*cos(phi*3.1416/180))-float((dy)*sin(phi*3.1416/180));
		Y[i]=xr+float((dx)*sin(phi*3.1416/180))+float((dy)*cos(phi*3.1416/180));
	}
	vedagiac();
}
void biendoityle(int X[maxdinh], int Y[maxdinh])
{
	int i;
	for(i=0;i<sodinh;i++)
	{
		X[i]*=sx;
		Y[i]*=sy;
	}
	vedagiac();
}
//bien doi ty le co tam
void tylecotam(int X[maxdinh], int Y[maxdinh], float tx,float ty,float sx, float sy )
	{
		for(int i=0;i<sodinh;i++){
			X[i] = tx + ((X[i]- tx) * sx);
			Y[i] = ty + ((Y[i]- ty) * sy);
		}
		vedagiac(X,Y);
	}
	
//bien dang theo xy
void biendangtheoX(int X[maxdinh], int Y[maxdinh], int shx){
	for(int i = 0;i<sodinh;i++){
		X[i] = X[i]+(shx * Y[i]);
	}
	vedagiac(X,Y);
}

void biendangtheoY(int X[maxdinh], int Y[maxdinh], int shy){
	for(int i = 0;i<sodinh;i++){
		Y[i] = Y[i]+(shy * X[i]);
	}
	vedagiac(X,Y);
}

int main()
{
	nhaptoado(X,Y);
	initwindow(800,800);
	vedagiac();
	//tinhtien(X,Y,100,150);
	/*for(int j=0;j<16;j++)
		phepquay(X,Y,200,150,30);*/
	//biendoityle(X,Y);
	//tyle(X,Y,150,150,1.25,1.5);
	/*biendangtheoX(X,Y,2);
	biendangtheoY(X,Y,2);*/
	tyle(X,Y,0.2,0.2);
	getch();
}
