#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
struct graph{
	int n;
	int A[MAX];
	int I[MAX];
};
bool nhap(graph &g){
	ifstream fi("D:\\Code\\Cau truc du lieu va giai thuat nang cao\\graph_ke.txt");
	int k,v,d=0;
	if(fi.is_open()){
		fi >> g.n;
		for (int i=0;i<g.n;i++){
			fi >> k;
			g.I[i] = d;
			for(int j=1;j<=k;j++){
				fi >> g.A[d];
				d = d+1;
			}
		}
		g.I[g.n] = d;
		fi.close();
	}
	else{
		cout<<"mo file ko thanh cong";
		return false;
	}
}
void xuat(graph g){
	cout<<"so dinh: "<<g.n<<endl;
	for(int i=0;i<g.n;i++){
		int k = g.I[i+1]-g.I[i];
		cout<<k<<" ";
		for(int j=g.I[i];j<g.I[i+1];j++)
		   cout<<g.A[j]<<" ";
		   cout<<"\n";
	}
}
int main(){
	graph g;
	nhap(g);
	xuat(g);
}
