#include <iostream>
#include <fstream>
#include <list>
using namespace std;
struct edge{
	int u,v;
};
struct graph{
	int n,m;
	list<edge>ds;
};
bool nhap(graph &g){
	ifstream fi("D:\\Code\\Cau truc du lieu va giai thuat nang cao\\dsCanh.txt");
	edge e;
	if(fi.is_open()){
		fi >> g.m;
		for(int i=0;i<g.m;i++){
			fi >> e.u >> e.v;
			g.ds.push_back(e);
		}
		fi.close();
		return true;
	}
	else{
		cout<<"mo file ko thanh cong";
		return false;
	}
}
void xuat(graph &g){
	cout<<"so canh: "<< g.m <<endl;
	for(list<edge>::iterator it = g.ds.begin(); it != g.ds.end(); ++it)
			cout<<" "<<(*it).u<<" "<<(*it).v<<endl;
}
int main(){
	graph g;
	nhap(g);
	xuat(g);
}
