#include<iostream>
using namespace std;

typedef struct Node{
	int Data;
	Node* Left;
	Node* Right;
};

typedef Node* Tree;
Tree root;

void init(Tree &root){
	root = NULL;
}

Node* taoNut(int x){
	Node *p = new Node;
	if(p != NULL){
		p->Left = NULL;
		p->Right = NULL;
		p->Data = x;
	}
	return (p);	
}

void chenNut(Tree &root, Node *p){
	if(root != NULL){
		if(root->Data < p->Data){
			chenNut(root->Right,p);
		}
		else{
			chenNut(root->Left,p);
		}
	}
	else{
		root = p;
	}
}

void taoCay(Tree &root){
	int x,n;
	cout << "Nhap n : " ;
	cin >> n;
	for(int i = 1; i <= n ; i++)
	{
		cin >> x;
		Node *p = taoNut(x);
		chenNut(root,p);
	}
}

void duyetTruoc(Tree root){
	if(root != NULL){
		cout << root->Data << " " ;
		duyetTruoc(root->Left);
		duyetTruoc(root->Right);
	}
}
void duyetGiua(Tree root){
	if(root != NULL){
		duyetTruoc(root->Left);
		cout << root->Data << " " ;
		duyetTruoc(root->Right);
	}
}
void duyetSau(Tree root){
	if(root != NULL){
		duyetTruoc(root->Left);
		duyetTruoc(root->Right);
		cout << root->Data << " " ;
	}
}

int main(){
	Tree tree;
	init(tree);
	taoCay(tree);
	duyetTruoc(tree);
	cout<<"\n";
	duyetGiua(tree);
	cout<<"\n";
	duyetSau(tree);
}
