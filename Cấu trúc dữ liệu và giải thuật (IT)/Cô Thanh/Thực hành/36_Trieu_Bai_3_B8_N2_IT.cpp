#include <iostream>
using namespace std;
const int COUNT = 10;

//Khai bao cau truc cay nhi phan
struct Node {
	int v;	//value
	Node *l;//Node left
	Node *r;//Node right
};

Node *root;

//Khoi tao cay nhi phan
void init_36_Trieu_Bai_3_B8_N2_IT() {
	root = NULL;
}

//Them vao cay
void them_36_Trieu_Bai_3_B8_N2_IT(Node *&p, int x) {
	if (p == NULL) {	//Neu la node la
		p = new Node;
		p->v = x;
		p->l = NULL;
		p->r = NULL;
	}
	else {
		if (p->v == x) return; //Neu node da co gia tri giong x
		if (p->v > x)	// neu x < node->v thi tim kiem trai va nguoc lai
			return them_36_Trieu_Bai_3_B8_N2_IT(p->l, x);
		else
			return them_36_Trieu_Bai_3_B8_N2_IT(p->r, x);
	}
}

//Tim vao cay
Node *tim_36_Trieu_Bai_3_B8_N2_IT(Node *p, int x) {
	if (p != NULL) {
		if (p->v == x) {//Tim thay gia tri x
			return p;
		}
		else {	//Tiep tuc tim kiem nhi phan
			if (p->v > x) 
				return tim_36_Trieu_Bai_3_B8_N2_IT(p->l, x);
			else
				return tim_36_Trieu_Bai_3_B8_N2_IT(p->r, x);
		}
	}
	return NULL; //Neu khong tim thay, tra ve NULL
}

//Duyet theo Left-Node-Right
void duyetLNR_36_Trieu_Bai_3_B8_N2_IT(Node *p) {
	if (p != NULL) {
		duyetLNR_36_Trieu_Bai_3_B8_N2_IT(p->l);//Duyet Left
		cout << p->v << "  ";//In ra gia tri node
		duyetLNR_36_Trieu_Bai_3_B8_N2_IT(p->r);//Duyet Right
	}
}

//Duyet theo Node-Left-Right
void duyetNLR_36_Trieu_Bai_3_B8_N2_IT(Node *p) {
	if (p != NULL) {
		cout << p->v << "  ";//In ra gia tri node
		duyetNLR_36_Trieu_Bai_3_B8_N2_IT(p->l);//Duyet Left
		duyetNLR_36_Trieu_Bai_3_B8_N2_IT(p->r);//Duyet Right
	}
}

//Duyet theo Left-Right-Node
void duyetLRN_36_Trieu_Bai_3_B8_N2_IT(Node *p) {
	if (p != NULL) {
		duyetLRN_36_Trieu_Bai_3_B8_N2_IT(p->l);//Duyet Left
		duyetLRN_36_Trieu_Bai_3_B8_N2_IT(p->r);//Duyet Right
		cout << p->v << "  ";//In ra gia tri node
	}
}

//Ham in cay nhi phan
void print2DUtil(Node* root, int space){
	// Base case
	if (root == NULL)
		return;
	// Increase distance between levels
	space += COUNT;
	// Process right child first
	print2DUtil(root->r, space);
	// Print current node after space
	// count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->v << "\n";
	// Process left child
	print2DUtil(root->l, space);
}

int main() {
	int n;
	bool kt = 0;
	
	init_36_Trieu_Bai_3_B8_N2_IT(); //Khoi tao

	them_36_Trieu_Bai_3_B8_N2_IT(root, 12);
	them_36_Trieu_Bai_3_B8_N2_IT(root, 23);
	them_36_Trieu_Bai_3_B8_N2_IT(root, 21);
	them_36_Trieu_Bai_3_B8_N2_IT(root, 11);

	print2DUtil(root, 0);

	cout << "Duyet LNR: \n"; duyetLNR_36_Trieu_Bai_3_B8_N2_IT(root); cout << endl;
	cout << "Duyet NLR: \n"; duyetNLR_36_Trieu_Bai_3_B8_N2_IT(root); cout << endl;
	cout << "Duyet LRN: \n"; duyetLRN_36_Trieu_Bai_3_B8_N2_IT(root); cout << endl;

	int x;
	cout << "Nhap so can tim: "; cin >> x;
	if (tim_36_Trieu_Bai_3_B8_N2_IT(root, x) != NULL) {
		cout << "Tim thay " << x << " trong cay!" << endl;
	}else cout << "Khong tim thay " << x << " trong cay!" << endl;
	system("pause");
	return 0;
}