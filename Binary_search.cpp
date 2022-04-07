//Viet chuong trinh gom: Hamm nhap d? nhap vao 1 mang, ham xuat de xuat mang ra man hinh
//ham Selection_sort de sap mang theo thu tu tang dan = thuat toan chon
//Ham main(): 
//- Nhap mang, xuat mang
//- sap xep mang, hien thi mang da sap ra man hinh
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

void SelectionSort(int A[], int n){
	int min; //ghi nhan chi so phan tu nho nhat trong day hien hanh
	for (int i=0; i<n-1; i++){
		min = i;
		for (int j=i+1; j<n; j++){
			if (A[j]<A[min])
				min = j;	
		}
		if (min!=i)
			swap(A[i],A[min]);	
	}
}


int BinarySearch(int A[], int n, int x){
	int left=0, right=n-1, mid;
	do{
		
		mid=(left+right)/2;
		if (A[mid]==x)
			return mid;
		else if (A[mid]<x)	
			left = mid + 1; //tim o nua ben phai
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
	SelectionSort(A,n);
	Xuat(A,n);
    /*
	int x;
	cout << "Nhap x: ";
	cin >> x;
	int kq = BinarySearch(A,n,x);
	if (kq==true)
		cout << "Tim thay\n";
	else
		cout << "Khong tim thay";
	*/	
	
	//tim kiem: Nhap vao 1 so nguyen x, tim xem x co trong mang hay khong? in ra vi tri tim dc	
    int x;
	cout<<"\n nhap phan tu can tim: ";
	cin>>x;
	int pos = BinarySearch(A,n,x);
	if(pos == -1)
	  cout<<"\n khong co phan tu nao trong mang";
	else{
		cout<<" vi tri tim duoc la: ";
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





