#include<iostream>
using namespace std;

struct sinhVien{
	int masv;
	string name;
	float dtk;
};
typedef struct sinhVien sv;

void nhap(sv *a , int n){
	for(int i = 0 ; i < n ;i++){
		cout << "Nhap ma sinh vien : " ;
		cin >> a[i].masv;
		cout << "Nhap ten : ";
		fflush(stdin);
		getline(cin,a[i].name);
		cout << "Nhap diem tong ket : ";
		cin >> a[i].dtk;
		cout << "\n";
	}
}

void xuat(sv *a , int n){
	for(int i = 0 ; i < n ;i++){
		cout << a[i].masv << " - " << a[i].name << " - " << a[i].dtk << endl;
	}
}

void InterchangeSort(sv *a , int n){
	for(int i = 0 ; i < n - 1 ; i++){
		for(int j = i + 1 ; j < n ; j++){
			if(a[i].masv > a[j].masv){
				sv temp = a[i];
				a[i] = a[j];
				a[j] = temp;
//				swap(a[i],a[j]);
			}
		}
	}
}

void SelectionSort(sv *a , int n){
	for(int i = 0 ; i < n - 1 ; i++){
		int min = i;
		for(int j = i + 1 ; j < n ; j++){
			if(a[j].masv < a[min].masv){
//				sv temp = a[min];
//				a[min] = a[j];
//				a[j] = temp;
				swap(a[min],a[j]);
			}
		}
	}
}

void BubbleSort(sv *a,int n)
{
    for (int i = 0 ; i<n-1 ; i++)
      for (int j =n-1; j >i ; j --)
         if(a[j].masv< a[j-1].masv)
           swap(a[j], a[j-1]);
}

void BubbleSort_2(sv *a,int n)
{
	for (int i=n-1 ; i>0 ; i--)
		for (int j=0; j<i ; j++)
			if(a[j].masv < a[j+1].masv)
				swap(a[j], a[j+1]);
}

void InsertionSort(sv *a, int n ){ 
    int pos, i;
    int x;
    for(i=1 ; i<n ; i++){
       x = a[i].masv; pos = i-1;
       while((pos >= 0)&&(a[pos].masv > x)){
            a[pos+1].masv = a[pos].masv;
            pos--;
       }
       a[pos+1].masv = x;
   }
}
void QuickSort(sv *a,int left, int right){
	int i,j;
	// phan hoach day can sap thanh 3 phan
	int m = (left+right)/2;
	sv x= a[m];
	i = left;j = right;
	while(i <= j){
		while(a[i].masv < x.masv)i++;
		while(a[j].masv > x.masv)j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}
	}
	// de quy QuickSort day ben trai
	if(left<j)
	QuickSort(a,left,j);
	// de quy QuickSort day ben phai
	if(i<right)
	QuickSort(a,i,right);
}
int main(){
	int n ; 
	cout << "Nhap so luong sinh vien : ";
	cin >> n;
	sv *a = new sv[n];
	nhap(a,n);
	cout << "Danh sach sinh vien : " << endl;
	xuat(a,n);
	//InterchangeSort(a,n);
	//SelectionSort(a,n);
	//BubbleSort(a,n);
	//BubbleSort_2(a,n);
	//InsertionSort(a,n);
	QuickSort(a,0,n-1);
	cout << "Danh sach sinh vien sau khi sap xep : " << endl;
	xuat(a,n);
	
}


