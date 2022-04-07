#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
#define MAX 100
struct graph{
	int n; 
	int A[MAX][MAX];
};
void nhap(graph &G){
	ifstream fi("D:\\Code\\Cau truc du lieu va giai thuat nang cao\\graph_ke3.txt");
	if(fi.is_open()==true){
		fi >> G.n; 
	for(int i=0;i<G.n;i++)
	  for(int j=0;j<G.n;j++)
	    fi >> G.A[i][j];
	fi.close();
	}
    else{
    	cout<<"mo file khong thanh cong"<<endl;
	}
}
void xuat(graph G){
	cout<<"so dinh: "<< G.n <<endl;
	for(int i=0;i<G.n;i++){
	 for(int j=0;j<G.n;j++)
		cout<<G.A[i][j]<<" ";
		cout<<"\n";
	}
}
void Depth_First_Search(graph G, int start, int goal)
{
	stack<int>Open;
	int Close[MAX]={0};
	int Father[MAX];
	int kq = false;
	int u;
	Father[start] = start;
	for (int i=0; i<G.n; i++)
		if (i!=start)
			Father[i] = -1;		
	Open.push(start);
	while(!Open.empty()){
		u = Open.top();
		Open.pop();
		if (u==goal){			
			kq = true;
			break;
		}
		Close[u] = 1; 
		for (int v=0; v<G.n; v++)
			if (G.A[u][v]==1)		
			{
				if (Father[v]==-1 && Close[v]==0){
					Open.push(v);
					Father[v] = u;
				}
			}
	}
	if (kq==true){
		cout << u;
		u = Father[u];
		while (u!=start){
			cout << "<--" << u;
			u = Father[u];
		}
		cout << "<--" << start << endl;
	}
	else{
		cout << "Khong tim duoc duong di!";	
	}
}
int main(){
	graph G;
	int start, goal;
	nhap(G);
	xuat(G);
	cout << "Nhap dinh bat dau: "; 
	cin >> start;
	cout << "Nhap dinh ket thuc: "; 
	cin >> goal;
	Depth_First_Search(G,start, goal);
}

