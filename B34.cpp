#include<iostream>
using namespace std;
struct date{
	int ngay,thang,nam;
};
struct QLNV{
	string manv;
	string tennv;
	date ngaysinh;
	long luong;
};
typedef struct QLNV nv;
void nhap(nv *a,int n){
	for(int i=0;i<n;i++){
		cout<<"\n nhap ma nhan vien: ";
		cin>>a[i].manv;
		cout<<" nhap ten nhan vien: ";
		fflush(stdin);
		getline(cin,a[i].tennv);
		cout<<" nhap ngay sinh: ";
		cin>>a[i].ngaysinh.ngay;
		cout<<" nhap thang sinh: ";
		cin>>a[i].ngaysinh.thang;
		cout<<" nhap nam sinh: ";
		cin>>a[i].ngaysinh.nam;
		cout<<" nhap tien luong: ";
		cin>>a[i].luong;
	}
}
void xuat(nv *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i].manv<<" - "<<a[i].tennv<<" - "<<a[i].ngaysinh.ngay<<"/"<<a[i].ngaysinh.thang<<"/"<<a[i].ngaysinh.nam<<" - "<<a[i].luong<<endl;
	}
}
bubblesort(nv *a, int n){
	int i,j;
	for(i=0;i<n-1;i++)
	  for(j=n-1;j>i;j--)
	    if(a[j].luong < a[j-1].luong){
	    	swap(a[j],a[j-1]);
		}
}
int binarysearch(nv*a, int n,int x){
	int left = 0, right = n-1, mid;
	do{
		mid = (left + right)/2;
		if(a[mid].luong == x)
		  return mid;
		else if(a[mid].luong <x)
		  left = mid + 1;
		else
		  right = mid - 1;
	}while(left <= right);
	return -1;
}
int main(){
	int n;
	cout<<"nhap so luong nhan vien: ";
	cin>>n;
	nv *a = new nv[n];
	nhap(a,n);
	cout<<"thong tin cac nhan vien: "<<endl;
	xuat(a,n);
	bubblesort(a,n);
	cout<<"thong tin cac nhan vien sau khi sap xep: "<<endl;
	xuat(a,n);
	
	int x;
	cout<<"nhap tien luong: ";
	cin>>x;
	int pos = binarysearch(a,x,n);
	if(pos == -1)
	  cout<<"khong co nhan vien can tim";
	else
	{
		cout<<"cac nhan vien tim duoc la: "<<endl;
		cout<<a[pos].tennv<<endl;
		int t = pos -1;
		while (t>= 0 && a[t].luong == x)
		{
			cout<<a[t].tennv<<endl;
			t--;
		}
		int p = pos + 1;
		while (p>= 0 && a[p].luong == x)
		{
			cout<<a[p].tennv<<endl;
			p ++;
		}
	}
}
