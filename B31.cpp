#include<iostream>
using namespace std;
struct SV{
	int MSV;
	string TSV;
	string LOP;
	float DTK;
};
typedef struct SV sv;
void nhap(sv *a, int n){
	for(int i=0;i<n;i++){
		cout<<"nhap ma sinh vien: ";
		cin>>a[i].MSV;
		cout<<"nhap ten sinh vien: ";
		fflush(stdin);
		getline(cin,a[i].TSV);
		cout<<"nhap ten lop: ";
		cin>>a[i].LOP;
		cout<<"nhap diem tong ket: ";
		cin>>a[i].DTK;
	}
}
void xuat(sv *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i].MSV<<" - "<<a[i].TSV<<" - "<<a[i].LOP<<" - "<<a[i].DTK<<endl;
	}
}
void bubblesort(sv *a,int n){
	int i,j;
	for(i=0;i<n-1;i++)
	  for(j=n-1;j>i;j--)
	    if(a[j].DTK<a[j-1].DTK){
	    	swap(a[j],a[j-1]);
		}
}
int BinarySearch(sv *a, int n, int x)
{
	int left = 0, right = n - 1, mid;
	do
	{
		mid = (left + right) / 2;
		if (a[mid].DTK == x)
			return mid;
		else if (a[mid].DTK < x)
			left = mid + 1;
		else
			right = mid - 1;
	} while (left <= right);
	return -1;
}
int main(){
	int n;
	cout<<"nhap so luong sinh vien: ";
	cin>>n;
	sv *a=new sv[n];
	nhap(a,n);
	cout<<"thong tin cac sinh vien: \n"<<endl;
	xuat(a,n);
	bubblesort(a,n);
	cout<<"thong tin cac sinh vien sau khi sap xep: \n"<<endl;
	xuat(a,n);
	
	int x;
	cout << "\n nhap diem tong ket: ";
	cin >> x;
	int pos = BinarySearch(a, n, x);
	if (pos == -1)
		cout << "\n khong tim thay sinh vien co diem tong ket la "<< x;
	else
	{
		cout << "cac sinh vien co diem tong ket la "<< x;
		cout <<"\n"<<a[pos].MSV<<" - "<<a[pos].TSV<<" - "<<a[pos].LOP<<" - "<<a[pos].DTK<< " ";
		int t = pos - 1;
		while (t >= 0 && a[t].DTK == x)
		{
			cout <<"\n"<<a[t].MSV<<" - "<<a[t].TSV<<" - "<<a[t].LOP<<" - "<<a[t].DTK << " ";
			t--;
		}
		int p = pos + 1;
		while (pos < n && a[p].DTK == x)
		{
			cout <<"\n"<<a[p].MSV<<" - "<<a[p].TSV<<" - "<<a[p].LOP<<" - "<<a[p].DTK << " ";
			p++;
		}
	}
}
