#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Sinhvien{
	int masv;
	string tensv, lop, hanhkiem;
	float dtk;
};

struct Node{
	Sinhvien data;
	Node *left;
	Node *right;
}; 

void kt(Node *&root){
	root = NULL;
}

Node *createNode(Sinhvien sv){
	Node *p = new Node;
	p->data = sv;
	p->left = NULL;
	p->right = NULL;
	return p;
}

Node *insertBST(Node *root, Sinhvien sv){
	if (root == NULL){
		return createNode(sv);
	}
	else{
		if (sv.masv < root->data.masv){
			root->left = insertBST(root->left, sv);
		}else if (sv.masv > root->data.masv){
			root->right = insertBST(root->right, sv);
		}
	}
	return root;
}

void LNR(Node *root){
	if (root != NULL){
		LNR(root->left);
		cout << left << setw(20) << root->data.masv << setw(20) << root->data.tensv << setw(20) << root->data.lop << setw(20) << root->data.dtk << setw(20) << root->data.hanhkiem << endl;
		LNR(root->right);
	}
}

void td(){
	cout << left << setw(20) << "Ma sinh vien" << setw(20) << "Ten sinh vien" << setw(20) << "Lop" << setw(20) << "Diem tong ket" << setw(20) << "Hanh kiem" << endl;
	cout << string (100, '-') << endl;
}

Node *search (Node *root, int x){
	if (root == NULL) return NULL;
	if (root->data.masv == x) return root;
	if (x < root->data.masv){
		return search(root->left, x);
	}return search(root->right, x);
}

int main(){
	Node *root;
	kt(root);
	int n;
	do{
		cout << "- Nhap so luong sinh vien: "; cin >> n; cin.ignore(); cout << endl;
	}while (n <= 0);
	
	for(int i = 0; i < n; i++){
		Sinhvien sv;
		cout << "- Nhap thong tin sinh vien thu " << i+1 << ": " << endl;
		cout << "	+ Nhap ma sinh vien: "; cin >> sv.masv;
		cout << "	+ Nhap ten sinh vien: "; getline(cin >> ws, sv.tensv);
		cout << "	+ Nhap lop: "; getline(cin, sv.lop);
		do{
			cout << "	+ Nhap diem tong ket: "; cin >> sv.dtk; cin.ignore();
		}while (sv.dtk <= 0 || sv.dtk > 10.0);
		
		do{
			cout << "	+ Nhap hanh kiem: "; getline(cin, sv.hanhkiem);
		}while(sv.hanhkiem != "tot" && sv.hanhkiem != "kha" && sv.hanhkiem != "trung binh" && sv.hanhkiem != "kem");
		root = insertBST(root, sv);
	}
	
	cout << "\nHien thi thong tin sinh vien vua nhap: " << endl;
	td();
	LNR(root);
	
	int x;
	do{
		cout << "\n- Nhap thong tin ma sinh vien can tim: "; cin >> x; cin.ignore();
	}while (x <= 0);
	
	Node *k = search(root, x);
	if (k != NULL){
		cout << "=> Tim thay sinh vien co ma sinh vien la " << x << ": " << endl;
		td();
		cout << left << setw(20) << k->data.masv << setw(20) << k->data.tensv << setw(20) << k->data.lop << setw(20) << k->data.dtk << setw(20) << k->data.hanhkiem << endl; 
	}else{
		cout << "=> Khong tim thay sinh vien nao co ma sinh vien la " << x << endl;
	}
	
}

