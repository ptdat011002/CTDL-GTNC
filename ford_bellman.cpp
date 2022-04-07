#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100

struct graph{
	int n; 
	int A[MAX][MAX];
};
void nhap(graph &G){
	ifstream fi("D:\\Code\\Cau truc du lieu va giai thuat nang cao\\graph_ford_bellman.txt");
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
		cout<<G.A[i][j]<<"\t";
		cout<<"\n";
	}
}
void ford_bellman(graph G, int start, int goal){
	int d[MAX], truoc[MAX];
	for (int i=0; i<G.n; i++){
		d[i]=G.A[start][i];
		truoc[i]=start;
	}
	d[start] = 0;
	for (int k=1; k<=G.n-2; k++){
		for (int v=0; v<G.n; v++){	   
	        for (int u=0; u<G.n; u++){
			if (d[v]>d[u]+G.A[u][v]){
				d[v] = d[u]+G.A[u][v];
				truoc[v] = u;
			}
		}
	}
}
	/* 
	cout << "\nDuong di tu dinh " << start << " den dinh " << goal << ":\n";
	if (d[goal]!=VC){
		int u = goal;
		cout << u << "<--";
		u = truoc[u];
		while(u!=start){
			cout << u << "<--";
			u = truoc[u];
		}
		cout << start;
	}
	else{
		cout << "Khong co duong di!";
	}
	*/
	cout << "\n_______________________\n";
	cout << "Duong di tu dinh " << start << " den cac dinh con lai:\n";
	
	for (int i=0; i<G.n; i++){
		if (i!=start){
			cout << "\nDuong di tu dinh " << start << " den dinh " << i << ":\n";
			int u = i;
			cout << u << "<--";
			u = truoc[u];
			while(u!=start){
				cout << u << "<--";
				u = truoc[u];
			}
			cout << start;
			cout << "\n";
		}
	}
}
int main(){
	graph G;
	int start, goal;
	nhap(G);
	xuat(G);
	cout << "Nhap dinh bat dau: "; 
	cin >> start;
	ford_bellman(G,start, goal);
}
