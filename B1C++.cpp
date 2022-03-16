#include<iostream>
using namespace std;

int main()
{
	int n;
	do
	{
	cout<<"- Nhap vao n = "; cin>>n;
	if(n>0 && n<8)
	{
		if(n==1) cout<<"1: Sunday";
		else if(n==2) cout<<"2: Monday";
		else if(n==3) cout<<"3: Tuesday";
		else if(n==4) cout<<"4: Wednesday";
		else if(n==5) cout<<"5: Tuesday";
		else if(n==6) cout<<"6: Friday";
		else cout<<"7: Saturday";
	}
	else cout<<"- Nhap sai n, moi ban nhap lai!\n";
     }while(n<=0 || n>=8);
  return 0;
}

