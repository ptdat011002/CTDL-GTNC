#include <iostream>
using namespace std;

void Nhap(int A[], int n){
	for (int i=0; i<n; i++){
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}
}
void Xuat(int A[], int n){
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
}
void InsertionSort(int A[], int n ){ 
    int pos, i;
    int x;
    for(i=1 ; i<n ; i++){
       x = A[i]; pos = i-1;
       while((pos >= 0)&&(A[pos] > x)){
            A[pos+1] = A[pos];
            pos--;
       }
       A[pos+1] = x;
   }
}
void QuickSort(int A[],int left, int right){
	int i,j,x;
	// phan hoach day can sap thanh 3 phan
	int m = (left+right)/2;
	x= A[m];
	i = left;j = right;
	while(i <= j){
		while(A[i]<x)i++;
		while(A[j]>x)j--;
		if(i<=j)
		{
			swap(A[i],A[j]);
			i++;j--;
		}
	}
	// de quy QuickSort day ben trai
	if(left<j)
	QuickSort(A,left,j);
	// de quy QuickSort day ben phai
	if(i<right)
	QuickSort(A,i,right);
}
int BinarySearch(int A[], int n, int x){
	int left=0, right=n-1, mid;
	do{
		
		mid=(left+right)/2;
		if (A[mid]==x)
			return mid;
		else if (A[mid]<x)	
			left = mid + 1; 
		else
			right = mid - 1;
	}while(left<=right);
	return -1;
}
int main(){
	int A[100], n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	Nhap(A,n);
	cout << "\n Mang da nhap: ";
	Xuat(A,n);
	cout << "\n Mang da sap xep: ";
	//InsertionSort(A,n);
	QuickSort(A,0,n-1);
	Xuat(A,n);
	
	int x;
	cout<<"\n nhap phan tu can tim: ";
	cin>>x;
	int pos = BinarySearch(A,n,x);
	if(pos == -1)
	  cout<<"\n khong co phan tu " << x <<" trong mang";
	else{
		cout<<" vi tri phan tu "<< x <<" trong mang: ";
		cout<<pos<< " ";
		int t = pos-1;
		while(t>=0 && A[t]==x){
			cout<<t<<" ";
			t--;
		}
		int p = pos+1;
		while(pos<n && A[p]==x){
			cout<<p<<" ";
			p++;
		}
	}
}
