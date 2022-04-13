#include<iostream>
using namespace std;
struct date{
	int ngay,thang,nam;
};
struct QLHH{
	string maHH;
	string tenHH;
	date ngayxuat;
	float giaxuat;
};
typedef struct QLHH ql;
void nhap(ql *a, int n){
	for(int i=0;i<n;i++){
		cout<<"nhap ma hang hoa: ";
	    cin>>a[i].maHH;
		cout<<"nhap ten hang hoa: ";
		fflush(stdin);
		getline(cin,a[i].tenHH);
		cout<<"nhap ngay xuat: ";
		cin>>a[i].ngayxuat.ngay;
		cout<<"nhap thang xuat: ";
		cin>>a[i].ngayxuat.thang;
		cout<<"nhap nam xuat: ";
		cin>>a[i].ngayxuat.nam;
		cout<<"nhap gia xuat: ";
		cin>>a[i].giaxuat;
	}
}
void xuat(ql *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i].maHH<< " - " <<a[i].tenHH<< " - " <<a[i].ngayxuat.ngay<<"/"<<a[i].ngayxuat.thang<<"/"<<a[i].ngayxuat.nam<< " - " <<a[i].giaxuat<<" trieu dong"<<endl;
	}
}
void bubblesort(ql *a,int n){
	int i,j;
	for(i=0;i<n-1;i++)
	  for(j=n-1;j>i;j--)
	    if(a[j].giaxuat<a[j-1].giaxuat){
	    	swap(a[j],a[j-1]);
		}
}
int BinarySearch(ql *a, int n, int x)
{
	int left = 0, right = n - 1, mid;
	do
	{
		mid = (left + right) / 2;
		if (a[mid].giaxuat == x)
			return mid;
		else if (a[mid].giaxuat < x)
			left = mid + 1;
		else
			right = mid - 1;
	} while (left <= right);
	return -1;
}
int main()
{
	int n;
	cout<<"nhap so luong hang hoa: ";
	cin>>n;
	ql *a = new ql[n];
	nhap(a,n);
	cout<<"thong tin cac hang hoa: \n"<<endl;
	xuat(a,n);
	bubblesort(a,n);
	cout<<"thong tin cac hang hoa sau khi sap xep: \n"<<endl;
	xuat(a,n);
	
	int x;
	cout << "\n nhap gia xuat: ";
	cin >> x;
	int pos = BinarySearch(a, n, x);
	if (pos == -1)
		cout << "\n khong tim thay hang hoa co gia xuat la "<<x<<" trieu dong";
	else
	{
		cout << "cac hang hoa co gia xuat la "<<x<<" trieu dong";
		cout <<"\n"<<a[pos].maHH<< " - " <<a[pos].tenHH<< " - " <<a[pos].ngayxuat.ngay<<"/"<<a[pos].ngayxuat.thang<<"/"<<a[pos].ngayxuat.nam<< " - " <<a[pos].giaxuat<<" trieu dong";
		int t = pos - 1;
		while (t >= 0 && a[t].giaxuat == x)
		{
			cout <<"\n"<<a[t].maHH<< " - " <<a[t].tenHH<< " - " <<a[t].ngayxuat.ngay<<"/"<<a[t].ngayxuat.thang<<"/"<<a[t].ngayxuat.nam<< " - " <<a[t].giaxuat<<" trieu dong";
			t--;
		}
		int p = pos + 1;
		while (pos < n && a[p].giaxuat == x)
		{
			cout <<"\n"<<a[p].maHH<< " - " <<a[p].tenHH<< " - " <<a[p].ngayxuat.ngay<<"/"<<a[p].ngayxuat.thang<<"/"<<a[p].ngayxuat.nam<< " - " <<a[p].giaxuat<<" trieu dong";
			p++;
		}
	}
}
