#include <iostream>
using namespace std;

// dinh nghia cau truc node
struct Node{
	int data;
	Node *left; // con tro den cay con trai cua nut
	Node *right; // con tro den cay con phai cua nut	
};

typedef Node* Tree; // Tree la ten moi cua kieu Node*

// khoi tao cay rong
void khoitao(Tree &root){
	root = NULL;
}

// tao moi 1 nut
Node* taonut(int x){
	// cap phat
	Node *p = new Node;
	if (p!=NULL){
		p->data = x;
		p->left = p->right = NULL;
	}
	return p;
}

// chen nut voa cay
void chennut(Tree &root, Node *p){
	if(root!=NULL){
		if(root->data==p->data) return; // neu gia tri khoa da co tren cay thi bo qua
		if(root->data>p->data)
		  chennut(root->left, p);
		else
		  chennut(root->right, p);
	}
	else root = p;
}

// tao cay
void taocay(Tree &root){
	int n,x; // so nut can luu
	cout<<"nhap so nut: ";
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"nhap gia tri: ";
		cin>>x;
		Node *p = taonut(x);
		if(p!=NULL)
		  chennut(root, p);
	}
}

void duyettruoc(Tree root){
	if(root!=NULL){
	cout<<root->data<<" ";
	duyettruoc(root->left);
	duyettruoc(root->right);	
	}
}
void duyetgiua(Tree root){
	if(root!=NULL){
	duyetgiua(root->left);
	cout<<root->data<<" ";
	duyetgiua(root->right);	
	}
}
void duyetsau(Tree root){
	if(root!=NULL){
	duyetsau(root->left);
	duyetsau(root->right);
	cout<<root->data<<" ";
    }  
}

int main(){
	Tree root;
	khoitao(root);
	taocay(root);
	cout<<" duyet cay theo thu tu truoc: ";
	duyettruoc(root);
	cout<<"\n duyet cay theo thu tu giua: ";
	duyetgiua(root);
	cout<<"\n duyet cay theo thu tu sau: ";
	duyetsau(root);
}

