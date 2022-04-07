#include <iostream>
using namespace std;
/*
int GT(int n){
	if(n==0)
	  return 1;
	else
	  return n*GT(n-1);
}
int main() 
{
	int n;
	cout<<"nhap n: ";
	cin>>n;
	int kq = GT(n);
	cout<<n<<"! = "<<kq;
}
*/
// vd Fibonaci
int dem=0;
int Fibonaci(int n){
	cout<<++dem<<". Fibonaci("<< n <<")\n";
	if(n<=2)
	  return 1;
	else
	  return Fibonaci(n-1) + Fibonaci(n-2);
}
int main()
{
	int n;
	cout<<"nhap n: ";
	cin>>n;
	int kq = Fibonaci(n);
	cout<<"Fibonaci cua "<<n<<" = "<<kq;
} 
