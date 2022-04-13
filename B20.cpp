#include<iostream>
using namespace std;
struct VDV{
	int maVDV;
	string tenVDV;
	int tuoi;
	float luong;
};
void nhap(VDV a[],int n){
	for(int i = 0;i < n;i++){
		cout<<"Nhap ma van dong vien : ";	
		cin>>a[i].maVDV;
		cout<<"Nhap ten van dong vien :";
		fflush(stdin);		
		getline(cin,a[i].tenVDV);
		cout<<"Nhap tuoi van dong vien :";	
		cin>>a[i].tuoi;
		cout<<"Nhap luong van dong vien : ";
		cin>>a[i].luong;
	}
}
void xuatVDV(VDV vdv){
	cout<<"Ma : "<<vdv.maVDV<<endl;
	cout<<"Ten : "<<vdv.tenVDV<<endl;
	cout<<"Tuoi: "<<vdv.tuoi<<endl;
	cout<<"Luong: "<<vdv.luong<<" trieu dong "<<endl;
}
void xuat(VDV a[],int n){
	for(int i = 0;i < n;i++){
		xuatVDV(a[i]);
		cout<<endl;
	}
}
void InserttionSort(VDV a[], int n ){ 
    int pos;
    VDV x;
    for(int i=1 ; i<n ; i++){
       x = a[i]; 
	   pos = i-1;
       while((pos >= 0)&&(a[pos].luong > x.luong)){
            a[pos+1] = a[pos];
            pos--;
       }
       a[pos+1] = x;
   }
}
int search(VDV a[],int n,float x){
	int l,r,m;
	l = 0;
	r=n-1;
	do{
		m = (l+r)/2;
		if(a[m].luong==x){
			return m;
		}
		else if(a[m].luong< x) l = m+1;
		else r = m-1;
	}while(l<=r);
	return -1;
}

int main(){
	VDV a[100];
	int n;
	cout<<"Nhap so luong van dong vien :";
	cin>>n;
	nhap(a,n);
	cout<<"Danh sach :"<<endl;
	xuat(a,n);
	cout<<"\nDanh sach sau khi sap xep :"<<endl;
	InserttionSort(a,n);
	xuat(a,n);
	int x;
	cout<<"Nhap luong cua van dong vien muon tim: ";
	cin>>x;
	int vt = search(a,n,x);
	if(vt != -1){
		cout<<"\nCac van dong vien co luong = "<<x<<" trieu dong la : "<<endl;
		xuatVDV(a[vt]);
		int t = vt -1;
		while(t >= 0 && a[t].luong == x ){
			xuatVDV(a[t]);
			t--;
		}
		int p = vt +1;
		while(p <= n-1 && a[p].luong == x ){
			xuatVDV(a[p]);
			p++;
		}
	}
	else{
		cout<<"\nKhong co van dong vien";
	}
	
	return 0;
}

