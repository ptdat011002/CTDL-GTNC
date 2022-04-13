#include <iostream>
using namespace std;
struct QLMonHoc
{
	int MaMH;
	string TenMH;
	int TC;
	int SoTiet;
};
typedef struct QLMonHoc ql;
void nhap(ql *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap ma mon hoc: ";
		cin >> a[i].MaMH;
		cout << "nhap ten mon hoc: ";
		fflush(stdin);
		getline(cin, a[i].TenMH);
		cout << "nhap so tin chi: ";
		cin >> a[i].TC;
		cout << "nhap so tiet: ";
		cin >> a[i].SoTiet;
	}
}
void xuat(ql *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i].MaMH << " - " << a[i].TenMH << " - " << a[i].TC << " - " << a[i].SoTiet << endl;
	}
}

void InserttionSort(ql *a, int n ){ 
    int pos;
    ql x;
    for(int i=1 ; i<n ; i++){
       x = a[i]; 
	   pos = i-1;
       while((pos >= 0)&&(a[pos].SoTiet > x.SoTiet)){
            a[pos+1] = a[pos];
            pos--;
       }
       a[pos+1] = x;
   }
}
int BinarySearch(ql *a, int n, int x)
{
	int left = 0, right = n - 1, mid;
	do
	{
		mid = (left + right) / 2;
		if (a[mid].SoTiet == x)
			return mid;
		else if (a[mid].SoTiet < x)
			left = mid + 1;
		else
			right = mid - 1;
	} while (left <= right);
	return -1;
}
int main()
{
	int n;
	cout << "nhap so mon hoc: ";
	cin >> n;
	ql *a = new ql[n];
	nhap(a, n);
	cout << "thong tin cac mon hoc:\n " << endl;
	xuat(a, n);
	InserttionSort(a, n);
	cout << "thong tin cac mon hoc sau khi xap sep:\n " << endl;
	xuat(a, n);

	int x;
	cout << "\n nhap so tiet: ";
	cin >> x;
	int pos = BinarySearch(a, n, x);
	if (pos == -1)
		cout << "\n khong tim thay mon hoc";
	else
	{
		cout << " mon hoc tim duoc la: ";
		cout <<"\n"<<a[pos].MaMH << " - " << a[pos].TenMH << " - " << a[pos].TC << " - " << a[pos].SoTiet;
		int t = pos - 1;
		while (t >= 0 && a[t].SoTiet == x)
		{
			cout <<"\n"<<a[t].MaMH << " - " << a[t].TenMH << " - " << a[t].TC << " - " << a[t].SoTiet;
			t--;
		}
		int p = pos + 1;
		while (pos < n && a[p].SoTiet == x)
		{
			cout <<"\n"<<a[p].MaMH << " - " << a[p].TenMH << " - " << a[p].TC << " - " << a[p].SoTiet;
			p++;
		}
	}
}
