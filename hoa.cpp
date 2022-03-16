// Tran Thi Mai Hoa - De 15 - MSV: 21103101529 - lop: 15A2
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
struct ql_diemSV
{
     char msv[20];
	char hoten[30];
	float dtb;
	float drl;
	float dtl;	
};

void tieude();
void clean();
void Menu();
void nhap(ql_diemSV a[], int &n);
void tinh(ql_diemSV a[], int n);
void xuat(ql_diemSV a[], int n);
void sapxep(ql_diemSV a[], int n);
void max_dtl(ql_diemSV a[], int n);
void them(ql_diemSV a[],int &n);
void xoa(ql_diemSV a[], int &n);
void ghitep(ql_diemSV a[], int n);
void doctep(ql_diemSV a[], int n);

int main()
{
	Menu();
	return 0;
}

void tieude()
{
	cout<<left<<setw(20)<<"MA SINH VIEN"
	          <<setw(25)<<"HO TEN"
	          <<setw(20)<<"DIEM TRUNG BINH"
	          <<setw(20)<<"DIEM REN LUYEN"
	          <<setw(20)<<"DIEM TICH LUY"<<endl;
}

// Cau 1
void clean()
{
	system("pause");
	system("cls");
}

void Menu()
{
	ql_diemSV a[100];
	int n,m;
	string s;
	do
	{	
	cout<< "\n\t***********************************************************************************\n";
	cout<< "\n\t**  =================================MENU===================================     **\n";
	cout<< "\n\t**  1. Nhap danh sach so luong sinh vien                                         **\n";
	cout<< "\n\t**  2. Tinh diem tich luy cho sinh vien                                          **\n";
	cout<< "\n\t**  3. In danh sach sinh vien voi day du thong tin duoi dang bang                **\n";
	cout<< "\n\t**  4. Sap xep danh sach sinh vien theo thu tu tang dan cua diem ren luyen       **\n";
	cout<< "\n\t**  5. In thong tin sinh vien co diem tich luy cao nhat                          **\n";
	cout<< "\n\t**  6. Them vao danh sach sinh vien nhap tu ban phim                             **\n";
	cout<< "\n\t**  7. Xoa cac sinh vien co diem trung binh be hon <hs                           **\n";
	cout<< "\n\t**  8. Luu danh sach sinh vien ra tep sv.dat                                     **\n";
	cout<< "\n\t**  9. Doc danh sach sinh vien tu tep sv.dat va ket xuat thong tin len man hinh  **\n";
	cout<< "\n\t**  10. Chuong trinh ket thuc !!                                                 **\n";
	cout<<endl;
	cout<< "  \t***********************************************************************************\n";	
     cout<<"\n\n - Nhap lua chon cua ban : "; cin>>m;
     switch(m)
     {
     	case 1:
    			nhap(a,n);
    			clean();
    			break;
    		case 2:
    			tinh(a,n);
				cout<<"\n - Da tinh diem tich luy !\n" ;
				clean();
				break;
    		case 3:
    			cout<<"\n - Danh sach sinh vien la: \n";
    			xuat(a,n);
    			clean();
    			break;
    		case 4:
    			sapxep(a,n);
    			clean();
    			break;
    		case 5:
    			max_dtl(a,n);
    			clean();
    			break;
    		case 6:
    			them(a,n);
    			clean();
    			break;
    		case 7:
    			xoa(a,n);
    			clean();
    			break;
    		case 8:
    			ghitep(a,n);
    			clean();
    			break;
    		case 9:
    			doctep(a,n);
    			clean();
    			break;
    		default:
				cout<<"\n - Menu khong co muc nay. Vui long nhap lai ! "<<endl;
 	        	clean();
	        	break;
		}
		cout<<" - Ban co muon lua chon tiep khong (YES/NO) : ";
		cin>>s;
		if(s=="NO") 
		{
			cout<<" - Xin chao tam biet !!";
			exit(1);
		}
	}while(s=="YES");
}	

// Cau 2
void nhap(ql_diemSV a[], int &n)
{
	cout<<"\n - Nhap so luong sinh vien la: ";
	do
	{
		cin>>n;
		if(n<=0) cout<<"\n - Moi ban nhap lai so sinh vien la: ";
	}
	while(n<=0);
	fflush(stdin);
	for(int i=0; i<n; i++)
	{
		cout<<"\n - Nhap thong tin cua sinh vien thu "<<i+1<<" la: \n";
		cout<<"\t* Ma sinh vien: "; cin.getline(a[i].msv,20);
		cout<<"\t* Ho va ten: "; cin.getline(a[i].hoten,30);
		cout<<"\t* Diem trung binh: "; cin>>a[i].dtb;
		cout<<"\t* Diem ren luyen: "; cin>>a[i].drl;
		fflush(stdin);
	}
}
// Cau 3
void tinh(ql_diemSV a[], int n)
{
	for(int i=0; i<n; i++)
	{
		a[i].dtl = float(a[i].dtb + a[i].drl)/2;
	}
}
// Cau 4
void xuat(ql_diemSV a[], int n)
{
	tieude();
	for(int i=0; i<n; i++)
	{
		cout<<left<<setw(20)<<a[i].msv
		          <<setw(25)<<a[i].hoten
		          <<setw(20)<<a[i].dtb
		          <<setw(20)<<a[i].drl
		          <<setw(20)<<a[i].dtl<<endl;
	}
}
// Cau 5
void sapxep(ql_diemSV a[], int n)
{
	cout<<"\n - Danh sach sinh vien sap xep theo thu tu tang dan cua diem ren luyen la: \n";
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(a[i].drl > a[j].drl)
			{
				ql_diemSV tg = a[i];
				          a[i] = a[j];
				          a[j] = tg;
			}
		}
	}
	xuat(a,n);
}
// Cau 6
void max_dtl(ql_diemSV a[], int n)
{
	float max = a[0].dtl;
	for(int i=0; i<n; i++)
	{
		if(a[i].dtl > max) max=a[i].dtl;
	}
	cout<<"\n - Thong tin sinh vien co diem tich luy cao nhat la:\n";
	tieude();
	for(int i=0; i<n; i++)
	{
		if(max==a[i].dtl)
		{
	     cout<<left<<setw(20)<<a[i].msv
		          <<setw(25)<<a[i].hoten
		          <<setw(20)<<a[i].dtb
		          <<setw(20)<<a[i].drl
		          <<setw(20)<<a[i].dtl<<endl;	
		}
	}
}
// Cau 7
void them(ql_diemSV a[], int &n)
{
	ql_diemSV b;
	int vitri = 0;
	cout<<"\n - Nhap thong tin sinh vien can them la: \n";
	fflush(stdin);
	cout<<"\t* Ma sinh vien: "; cin.getline(b.msv,20);
	cout<<"\t* Ho va ten: "; cin.getline(b.hoten,30);
	cout<<"\t* Diem trung binh: "; cin>>b.dtb;
	cout<<"\t* Diem ren luyen: "; cin>>b.drl;
	b.dtl = float(b.dtb + b.drl)/2;
	for(int i=0; i<n; i++)
	{
		if(a[i].drl<=b.drl) vitri++;
	}
	for(int i=n;i>=vitri;i--)
	{
		a[i]=a[i-1];
	}
	a[vitri]=b;
	n++;
	cout<<"\n - Danh sach sinh vien sau khi them la: \n";
	xuat(a,n);	
}
// Cau 8 
void xoa(ql_diemSV a[], int &n)
{
	float hs;
	cout<<"\n - Nhap so thuc hs tu ban phim : "; cin>>hs;
	for(int i=0; i<n; i++)
	{
		if(a[i].dtb <= hs)
		{
			for(int j=i; j<n-i; j++)
			{
				a[i]=a[j+1];
			}
			n--;
		}
	}
	cout<<"\n - Danh sach sinh vien sau khi xoa la: \n";
	xuat(a,n);
}
// Cau 9
void ghitep(ql_diemSV a[], int n)
{
	fstream x;
	x.open("sv.dat", ios::out );
	if(!x) 
	{
		cout<<" - Tep khong ton tai !!";
		exit(1);
	}
	else
	{
		for(int i=0; i<n; i++)
		{
		   x<<left<<setw(20)<<a[i].msv
		          <<setw(25)<<a[i].hoten
		          <<setw(20)<<a[i].dtb
		          <<setw(20)<<a[i].drl
		          <<setw(20)<<a[i].dtl<<endl;
		}
     }
     x.close();
	cout<<"\n - Da luu danh sach sinh vien ra tep sv.dat ! \n";
}
// Cau 10
void doctep(ql_diemSV a[], int n)
{
	fstream x;
	x.open("sv.dat", ios::in);
	if(!x) 
	{
		cout<<" - Tep khong ton tai !!";
		exit(1);
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			x>>a[i].msv;
			x>>a[i].hoten;
			x>>a[i].dtb;
			x>>a[i].drl;
			x>>a[i].dtl;
		}
		cout<<"\n - Danh sach nhan vien lay tu tep sv.dat la:\n";
	}
	xuat(a,n);
	x.close();
}






