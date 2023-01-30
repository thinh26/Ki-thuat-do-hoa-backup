#include <graphics.h>
#include <stdio.h>
#include <math.h>
#define lamtron(a) ((int)(a+0))
void DDA(int xa, int ya, int xb, int yb, int color)
{
	//Tinh he so goc
	float m;
	m=(float)(yb-ya)/(xb-xa);
	abs()
	printf("Duong thang co he so goc: %.3f\n",m);
	//Toa do diem can xac dinh
	float x; float y;
	//Truong hop 1 (luon co so x va so y)
	// if(m>0 && m<1) //y=f(x)
	// {
	// 	if(xa<xb && ya < yb)
	// 	{
	// 		//x sau = x truoc +1
	// 		x=xa;
	// 		y=ya;
	// 		putpixel(x,y,color);
	// 		for(x=xa;x<xb;x++)
	// 		{
	// 			y=y+m;
	// 			printf("%.0f,%d\n",x,lamtron(y));
	// 			putpixel(x,lamtron(y),color);
	// 		}
	// 	}
	// }
	//Truong hop 2
	if(m>0 && m<1)
	{
	if(xa>xb && ya>yb)
	{
 		//x sau = x truoc -1;
 		x=xa;
 		y=ya;
 		putpixel(x,y,color);
 		for(x=xa;x>=xb;x--)
 		{
 			y=y-m;
 			printf("%.0f,%d\n",x,lamtron(y));
 			putpixel(x,lamtron(y),color);
 		}
 	}
	}
	//Truong hop 3
	// if(m>-1 && m<1)
	// {
	// 	if(xa>xb && ya<yb)
	// 	{
	// 		//x sau = x truoc -1
	// 		x=xa;
	// 		y=ya;
	// 		putpixel(x,y,color);
	// 		for(x=xa;x>=xb;x--)
	// 		{
	// 			y=y-m;
	// 			printf("%.0f,%d\n",x,lamtron(y));
	// 			putpixel(x,lamtron(y),color);
	// 		}
	// 	}
	// }
}
int main()
{
	//khoi tao man hinh do hoa
	initwindow(400,400); //400 chieu cao x 400 chieu rong
	/*DDA(20,30,120,80,4); //Truong hop 1*/
	DDA(120,80,20,30,4); //Truong hop 2
	//DDA(120,30,20,80,4);
	getch();
	//Khi chay se hien cua so Windows BGI
}
