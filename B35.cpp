#include<iostream>
using namespace std;
struct QLTL{
	int matl;
	string tentl;
	int namxb;
	float gia;
};
typedef struct QLTL ql;
void nhap(ql *a, int n){
	for(int i=0; i<n; i++){
		cout<<"nhap ma tai lieu: ";
		cin>>a[i].matl;
		cout<<"nhap ten tai lieu: ";
		fflush(stdin);
		getline(cin,a[i].tentl);
		cout<<"nhap nam xuat ban: ";
		cin>>a[i].namxb;
		cout<<"nhap gia ban: ";
		cin>>a[i].gia;
	}
}
void xuat(ql *a, int n){
	for(int i=0; i<n; i++){
		cout<<a[i].matl<<" - "<<a[i].tentl<<" - "<<a[i].namxb<<" - "<<a[i].gia<<endl;
	}
}
void bubblesort(ql *a, int n){
	for(int i=0; i<n-1; i++)
		for(int j=n-1; j>i; j--)
			if(a[j].gia < a[j-1].gia)
				swap(a[j],a[j-1]);
}
int binarysearch(ql *a, int n, float x){
	int left = 0, right = n-1, mid;
	do{
		mid = (left + right)/2;
		if(a[mid].gia == x)
		  return mid;
		else if(a[mid].gia <x)
		  left = mid + 1;
		else
		  right = mid - 1;
	}while(left <= right);
	return -1;
}
int main()
{
	int n;
	cout<<"nhap so tai lieu: ";
	cin>>n;
	ql *a = new ql[n];
	nhap(a,n);
	cout<<"thong tin cac tai lieu: "<<endl;
	xuat(a,n);
	bubblesort(a,n);
	cout<<"thong tin cac tai lieu sau khi sap xep: "<<endl;
	xuat(a,n);
	
	int x;
	cout<<"nhap gia cua tai lieu: ";
	cin>>x;
	int pos = binarysearch(a,n,x);
	if(pos == -1)
	  cout<<"khong co tai lieu can tim";
	else
	{
		cout<<"cac tai lieu tim duoc la: "<<endl;
		cout<<a[pos].tentl<<endl;
		int t = pos -1;
		while (t>= 0 && a[t].gia == x)
		{
			cout<<a[t].tentl<<endl;
			t--;
		}
		int p = pos + 1;
		while (p>= 0 && a[p].gia == x)
		{
			cout<<a[p].tentl<<endl;
			p ++;
		}
	}
}
