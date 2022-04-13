#include<iostream>
using namespace std;
struct Date{
	int ngay,thang,nam;
};
struct HangHoa{
	int MaH;
	string TenH;
	float Gia;
	Date NgayXuat;
};
struct Node{
	HangHoa data;
	Node *left;
	Node *right;
};
typedef Node *Tree;
void KhoiTao(Tree &root){
	root=NULL;
}
void Nhap(HangHoa &a){
	cout<<"Nhap ma hang hoa: ";
	cin>>a.MaH;
	cout<<"Nhap ten hang hoa: ";
	fflush(stdin);
	getline(cin, a.TenH);
	cout<<"Nhap ngay xuat: ";
	cin>>a.NgayXuat.ngay;
	cout<<"Nhap thang xuat: ";
	cin>>a.NgayXuat.thang;
	cout<<"Nhap nam xuat: ";
	cin>>a.NgayXuat.nam;
	cout<<"Nhap gia xuat: ";
	cin>>a.Gia;
}
void Xuat(HangHoa a){
	cout<<a.MaH<<"\t"<<a.TenH<<"\t"<<a.NgayXuat.ngay<<"/"<<a.NgayXuat.thang<<"/"<<a.NgayXuat.nam<<"\t"<<a.Gia<<endl;
}
Node *TaoNut(HangHoa a){
	Node *p = new Node;
	if (p!=NULL){
		p->data=a;
		p->left=NULL;
		p->right=NULL;
	}
	return p;
}
void ChenNut(Tree &root, Node *p){
	if (root!=NULL){
		if (root->data.MaH==p->data.MaH)
			return;
		else if (root->data.MaH>p->data.MaH)
			ChenNut(root->left,p);
		else
			ChenNut(root->right,p);
	}
	else root = p;
}
void TaoCay(Tree &root){
	int n;
	HangHoa a;
	cout<<"Nhap so hang hoa: ";
	cin>>n;
	for(int i=1; i<=n; i++){
		cout<<"Nhap thong tin hang hoa thu "<<i<<":\n";
		Nhap(a);
		Node *p = TaoNut(a);
		if(p!=NULL)
			ChenNut(root, p);
	}
}
void DuyetTruoc(Tree root){
	if(root!=NULL){
		Xuat(root->data);
		DuyetTruoc(root->left);
		DuyetTruoc(root->right);
	}
}
void TimKiem(Tree root, int x){
	if (root!=NULL){
		if (root->data.MaH==x){
			cout<<"Thong tin cua hang hoa tim duoc:\n";
			Xuat(root->data);
		}
		else if (root->data.MaH > x)
			TimKiem(root->left, x);
		else 
			TimKiem(root->right, x);
	}
	else{
		cout << "Khong co hang hoa can tim!";
	}
}
int main(){
	Tree root;
	KhoiTao(root);
	TaoCay(root);
	cout << "Thong tin hang hoa:\n";
	DuyetTruoc(root);
	int x;
	cout<<"Nhap ma hang hoa can tim: ";
	cin>>x;
	TimKiem(root,x);
}
