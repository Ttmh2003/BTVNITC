#include<iostream>
using namespace std;

int main()
{
	int n;
	long td; 
	cout<<"- Nhap so KW dien tieu thu n = "; cin>>n;
	if(n>=0 && n<=100)
	{
		td = n*2000;
	}
	else if(n<=200)
	{
		td = n*2500;
	}
	else if(n<=300)
	{
		td = n*3000;
	}
	else 
	{
		td = n*5000;
	}
	cout<<"- Tien dien la: "<<td<<" VND";
  return 0;
}

