#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct cau_thu
{
    char mct[20];
    string  ten;
    int tuoi, sbt;
    string vt;
};
void tieude();
void nhap(cau_thu a[], int n);
void xuat(cau_thu a[], int n);
void tim(cau_thu a[], int n);
void dem(cau_thu a[], int n);
void kiem(cau_thu a[], int n);
void sap_xep(cau_thu a[], int n);
int main()
{
 int n;
 cau_thu a[50];
 cout<<"Nhap vao so luong cau thu n = "; cin>>n;
 fflush(stdin);
 nhap(a,n);
 xuat(a,n);
 tim(a,n);
 dem(a,n);
 kiem(a,n);
 sap_xep(a,n);
 
  return 0;
}





void tieude()
{
	cout<<left<<setw(15)<<"MA CAU THU"<<setw(20)<<"TEN"<<setw(10)<<"TUOI"<<setw(20)<<"VI TRI CAU THU"<<setw(20)<<"SO BAN THANG"<<endl<<endl;
}


void nhap(cau_thu a[], int n)
{
 for(int i=0; i<n; i++)
 {
  cout<<"Ma cau thu "<<i+1<<" la: "; cin.getline(a[i].mct,15);
  cout<<"Ten cau thu "<<i+1<<" la: ";
  fflush(stdin); getline(cin,a[i].ten);
  cout<<"Tuoi cau thu "<<i+1<<" la: "; cin>>a[i].tuoi;
  fflush(stdin);
  cout<<"Vi tri cau thu "<<i+1<<" la: "; getline(cin,a[i].vt);
  cout<<"So ban thang cua cau thu "<<i+1<<" la: "; cin>>a[i].sbt;
  fflush(stdin);
  cout<<endl;
 }
}
void xuat(cau_thu a[], int n)
{

 cout<<"\nDANH SACH CAC CAU THU DA BONG LA: \n\n";
 tieude();
 for(int i=0; i<n; i++)
 {
 cout<<left<<setw(15)<<a[i].mct<<setw(20)<<a[i].ten<<setw(10)<<a[i].tuoi<<setw(20)<<a[i].vt<<setw(20)<<a[i].sbt<<endl;     
 }
}
void tim(cau_thu a[], int n)
{
 cout<<"\nCAU THU CO TEN VU THANH DAT LA: " <<endl<<endl;
 tieude();
 for(int i=0; i<n; i++)
 {
  if(a[i].ten=="Vu Thanh Dat")
  {
  cout<<left<<setw(15)<<a[i].mct<<setw(20)<<a[i].ten<<setw(10)<<a[i].tuoi<<setw(20)<<a[i].vt<<setw(20)<<a[i].sbt<<endl;      
  }
 }
}
void dem(cau_thu a[], int n)
{
	int dem=0;
 for(int i=0; i<n; i++)
 {
     if(a[i].vt=="Tien ve")
     {
      dem++;
     }
 }
 cout<<"\nCo "<<dem<<" cau thu trong vi tri Tien ve" <<endl;
}
void kiem(cau_thu a[], int n)
{
 int max=a[0].tuoi;
 for(int i=1; i<n; i++)
 {
  if(max < a[i].tuoi)
  {
    max=a[i].tuoi;
      }
 }
 cout<<"\nCAU THU CO SO TUOI LON NHAT TRONG DOI BONG LA: " <<endl<<endl;
 tieude();
 for(int i=0; i<n; i++)
 {
 	if(max==a[i].tuoi)
  cout<<left<<setw(15)<<a[i].mct<<setw(20)<<a[i].ten<<setw(10)<<a[i].tuoi<<setw(20)<<a[i].vt<<setw(20)<<a[i].sbt<<endl;      
 }
}
void sap_xep(cau_thu a[], int n)
{
 for(int i=0; i<n; i++)
 {
  for(int j=i+1; j<n; j++)
  {
   if(a[i].sbt > a[j].sbt)
   {
    cau_thu 	tg = a[j];
    			a[j]=a[i] ;
    			a[i]=tg;
   }
  }
 }
 cout<<"\nSAP XEP CAU THU THEO CHIEU GIAM DAN CUA BAN THANG" <<endl<<endl;
 tieude();
     for(int i=0; i<n; i++)
     {
     cout<<left<<setw(15)<<a[i].mct<<setw(20)<<a[i].ten<<setw(10)<<a[i].tuoi<<setw(20)<<a[i].vt<<setw(20)<<a[i].sbt<<endl;       
 }

}
