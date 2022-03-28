#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct NS
{
	int ngay;
	int thang;
	int nam;
};

class KH
{
	private :
		char ht[30];
		NS ns;
		char cmt[10];
		char k[50];
	public :
		void nhap()
		{
			cout<<"\tNhap ho ten la: ";
			cin.getline(ht, 30);
			cout<<"\tNhap ngay thang nam sinh la: \n";
			cout<<"\t\tNgay: "; cin>>ns.ngay;
			cout<<"\t\tThang: "; cin>>ns.thang;
			cout<<"\t\tNam: "; cin>>ns.nam;
			cin.ignore();
			cout<<"\tNhap chung minh thu la: ";
			cin.getline(cmt, 10);
			cout<<"\tNhap ho khau la: ";
			cin.getline(k, 50);
		}
		void xuat()
		{
			cout<<left<<setw(30)<<ht
						<<setw(2)<<ns.ngay
						<<setw(1)<<"/"
						<<setw(2)<<ns.thang
						<<setw(1)<<"/"
						<<setw(9)<<ns.nam
						<<setw(20)<<cmt
						<<setw(55)<<k<<endl;
		}
		char* TEN()
		{
			return ht;
		}
		int THANG()
		{
			return ns.thang;
		}
		
};

void tieude()
{
	cout<<left<<setw(30)<<"Ho Ten"
				<<setw(15)<<"Ngay Sinh"
				<<setw(20)<<"Chung Minh Thu"
				<<setw(55)<<"Ho Khau"<<endl;
}

int main()
{
	int n;
	KH a[100];
	cout<<"Nhap so khach hang la: ";
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		cout<<"\nNhap thong tin khach hang thu "<<i+1<<" la:\n";
		a[i].nhap();
	}
	for(int i=0; i < n; i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if( strcmp(a[i].TEN(), a[j].TEN() ) > 0 )
			{
				KH tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
	cout<<"Danh sach khach hang theo thu tu tang dan cua ho ten:\n\n";
	tieude();
	for(int i=0;i<n;i++)
	{
		a[i].xuat();
	}
	cout<<"\nDanh sach cac khach hang co sinh nhat thang 12 la:\n\n";
	tieude();
	for(int i=0;i<n;i++)
	{
		if(a[i].THANG() == 12)
		{
			a[i].xuat();
		}
	}
	return 0;
}
