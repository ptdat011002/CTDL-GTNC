#include<iostream>
using namespace std;


struct Duan{
	int mada;
	string tenda;
	float tongkinhphi;
};

void nhap(Duan a[],int n){
	for(int i = 0;i < n;i++){
		cout<<"Nhap ma du an : ";	cin>>a[i].mada;
		fflush(stdin);
		cout<<"Nhap ten du an :";		getline(cin,a[i].tenda);
		cout<<"Nhap tong kinh phi :";	cin>>a[i].tongkinhphi;
	}
}
void xuatda(Duan da){
	cout<<"Ma du an: "<<da.mada<<endl;
	cout<<"Ten du an: "<<da.tenda<<endl;
	cout<<"Tong kinh phi: "<<da.tongkinhphi<<" ty dong"<<endl;
}

void xuat(Duan a[],int n){
	for(int i = 0;i < n;i++){
		xuatda(a[i]);
		cout<<endl;
	}
}
void inserttionsort(Duan a[],int n){
	int pos;
	Duan x;
	for(int i = 1 ;i < n;i++){
		pos=i-1;
		x=a[i];
		while(pos>=0 && x.tongkinhphi < a[pos].tongkinhphi){
			a[pos+1]=a[pos];
			pos--;
		}	
		a[pos+1]=x;
	}		
	
}

int search(Duan a[],int n,float x){
	int l,r,m;
	l = 0;
	r=n-1;
	do{
		m = (l+r)/2;
		if(a[m].tongkinhphi==x){
			return m;
		}
		else if(a[m].tongkinhphi < x) l = m+1;
		else r = m-1;
	}while(l<=r);
	return -1;
}

int main(){
	Duan a[100];
	int n;
	cout<<"Nhap so luong du an :";
	cin>>n;
	nhap(a,n);
	cout<<"Danh sach du an :"<<endl;
	xuat(a,n);
	cout<<"\nDanh sach du an sau sap xep :"<<endl;
	inserttionsort(a,n);
	xuat(a,n);
	int x;
	cout<<"Nhap tong kinh phi muon tim: ";
	cin>>x;
	int vt = search(a,n,x);
	if(vt != -1){
		cout<<"\nDanh sach du an co tong kinh phi = "<<x<<" ty dong la : "<<endl;
		xuatda(a[vt]);
		int t = vt -1;
		while(t >= 0 && a[t].tongkinhphi == x ){
			xuatda(a[t]);
			t--;
		}
		int p = vt +1;
		while(p <= n-1 && a[p].tongkinhphi == x ){
			xuatda(a[p]);
			p++;
		}
	}
	else{
		cout<<"\nKhong co du an can tim";
	}
	
	return 0;
}

