#include<iostream>
using namespace std;
struct QLKH{
	int maKK;
	string tenKK;
	string SDT;
	float tienTT;
};
typedef struct QLKH ql;
void nhap(ql *a, int n){
	for(int i=0;i<n;i++){
		cout<<"nhap ma khach hang: ";
		cin>>a[i].maKK;
		cout<<"nhap ten khach hang: ";
		fflush(stdin);
		getline(cin,a[i].tenKK);
		cout<<"nhap so dien thoai: ";
		cin>>a[i].SDT;
		cout<<"nhap tien thanh toan: ";
		cin>>a[i].tienTT;
	}
}
void xuat(ql *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i].maKK<<" - "<<a[i].tenKK<<" - "<<a[i].SDT<<" - "<<a[i].tienTT<<endl;
	}
}
bubblesort(ql *a, int n){
	int i,j;
	for(i=0;i<n-1;i++)
	  for(j=n-1;j>i;j--){
	  	if(a[j].tienTT < a[j-1].tienTT){
	  		swap(a[j],a[j-1]);
		  }
	  }
}
int BinarySearch(ql *a, int n, int x)
{
	int left = 0, right = n - 1, mid;
	do
	{
		mid = (left + right) / 2;
		if (a[mid].tienTT == x)
			return mid;
		else if (a[mid].tienTT < x)
			left = mid + 1;
		else
			right = mid - 1;
	} while (left <= right);
	return -1;
}
int main()
{
	int n;
	cout<<"nhap so luong khach hang: ";
	cin>>n;
	ql *a = new ql[n];
	nhap(a,n);
	cout<<"thong tin cac khach hang: \n"<<endl;
	xuat(a,n);
	bubblesort(a,n);
	cout<<"thong tin cac khach hang sau khi sap xep: \n"<<endl;
	xuat(a,n);
	
	int x;
	cout << "\n nhap tien thanh toan: ";
	cin >> x;
	int pos = BinarySearch(a, n, x);
	if (pos == -1)
		cout << "\n khong tim thay khach hang ";
	else
	{
		cout << "cac khach hang tim duoc la "<<endl;
		cout<<a[pos].maKK<<" - "<<a[pos].tenKK<<" - "<<a[pos].SDT<<" - "<<a[pos].tienTT<<endl;
		int t = pos - 1;
		while (t >= 0 && a[t].tienTT == x)
		{
			cout<<a[t].maKK<<" - "<<a[t].tenKK<<" - "<<a[t].SDT<<" - "<<a[t].tienTT<<endl;
			t--;
		}
		int p = pos + 1;
		while (pos < n && a[p].tienTT == x)
		{
			cout<<a[p].maKK<<" - "<<a[p].tenKK<<" - "<<a[p].SDT<<" - "<<a[p].tienTT<<endl;
		}
	}
}
