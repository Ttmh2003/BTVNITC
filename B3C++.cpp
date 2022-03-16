#include<iostream>
using namespace std;

int main()
{
	int n;
	int P=1;
	cout<<"- Nhap so nguyen n = "; cin>>n;
	for(int i=1; i<=n; i++)
	{
	    P=P*2*i;	
	}
	cout<<"- Tich la: "<<P;
	
  return 0;
}

