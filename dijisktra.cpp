#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
#define VC 100
struct graph{
	int n; 
	int A[MAX][MAX];
};
void nhap(graph &G){
	ifstream fi("D:\\Code\\Cau truc du lieu va giai thuat nang cao\\graph_dijisktra.txt");
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
int TimMin(int d[], int close[], int n){
	int u, Min = 100;
	for (int i=0; i<n; i++)
		if (close[i]==0 && d[i]<Min){
			u = i;
			Min = d[i];
		}
	return u; 
}
void dijisktra(graph G, int start, int goal){
	int d[MAX], truoc[MAX], close[MAX]={0};
	//close[]: mang danh dau, close[u]=1 ->da danh dau, close[u]=0 ->chua danh dau
	//khoi tao
	for (int i=0; i<G.n; i++){
		d[i]=G.A[start][i];
		truoc[i]=start;
	}
	close[start] = 1;
	//lap
	for (int k=1; k<=G.n-2; k++){
		int u = TimMin(d, close, G.n);
		close[u] = 1;
		for (int v=0; v<G.n; v++)
			if (close[v]==0 && d[v]>d[u]+G.A[u][v]){
				d[v] = d[u]+G.A[u][v];
				truoc[v] = u;
			}
	}
	//in duong di
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
	/*
	cout << "\n_______________________\n";
	cout << "Duong di tu dinh " << start << " Den cac dinh con lai:\n";
	
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
	*/
	
	
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
	dijisktra(G,start, goal);
}
