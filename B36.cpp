#include<iostream>
using namespace std;
struct QLMB{
	int mave;
	string khoihanh;
	string den;;
	float giave;
};
typedef struct QLMB VMB;
void nhap(VMB *A, int n){
	for(int i=0; i<n; i++){
		cout<<"nhap ma ve: ";
		cin>>A[i].mave;
		cout<<"nhap diem khoi hanh: ";
		fflush(stdin);
		getline(cin,A[i].khoihanh);
		cout<<"nhap diem den: ";
		fflush(stdin);
		getline(cin,A[i].den);
		cout<<"nhap gia ve: ";
		cin>>A[i].giave;
	}
}
void xuat(VMB *A, int n){
	for(int i=0; i<n; i++){
		cout<<A[i].mave<<" - "<<A[i].khoihanh<<" - "<<A[i].den<<" - "<<A[i].giave<<endl;
	}
}
void bubblesort(VMB *A, int n){
	for(int i=0; i<n-1; i++)
		for(int j=n-1; j>i; j--)
			if(A[j].giave < A[j-1].giave)
				swap(A[j],A[j-1]);
}
int binarysearch(VMB *A, int n, float x){
	int left = 0, right = n-1, mid;
	do{
		mid = (left + right)/2;
		if(A[mid].giave == x)
		  return mid;
		else if(A[mid].giave <x)
		  left = mid + 1;
		else
		  right = mid - 1;
	}while(left <= right);
	return -1;
}
int main(){
	int n;
	cout<<"nhap so luong ve may bay: ";
	cin>>n;
	VMB *A = new VMB[n];
	nhap(A,n);
	xuat(A,n);
	bubblesort(A,n);
	cout<<"thong tin ve may bay sau khi sap xep: "<<endl;
	xuat(A,n);
	
	int X;
	cout<<"nhap gia ve may bay can tim: ";
	cin>>X;
	int pos = binarysearch(A,n,X);
	if(pos == -1){
		cout<<"khong co ve may bay can tim"<<endl;
	}
	else{
		cout<<"cac ve may bay tim duoc la: "<<endl;
		cout<<A[pos].mave<<" - "<<A[pos].giave<<endl;
		int t = pos - 1;
		while(t >= 0 && A[t].giave == X){
			cout<<A[pos].mave<<" - "<<A[pos].giave<<endl;
			t--;
		}
		int p = pos + 1;
		while(p >= 0 && A[p].giave == X){
			cout<<A[pos].mave<<" - "<<A[pos].giave<<endl;
			p++;
		}
	}
}
