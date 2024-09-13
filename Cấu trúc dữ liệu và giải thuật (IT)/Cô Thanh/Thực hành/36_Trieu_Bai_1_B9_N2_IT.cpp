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
void init_36_Trieu_Bai_1_B9_N2_IT() {
	root = NULL;
}

//Them vao cay
void them_36_Trieu_Bai_1_B9_N2_IT(Node *&p, int x) {
	if (p == NULL) {	//Neu la node la
		p = new Node;
		p->v = x;
		p->l = NULL;
		p->r = NULL;
	}
	else {
		if (p->v == x) return; //Neu node da co gia tri giong x
		if (p->v > x)	// neu x < node->v thi tim kiem trai va nguoc lai
			return them_36_Trieu_Bai_1_B9_N2_IT(p->l, x);
		else
			return them_36_Trieu_Bai_1_B9_N2_IT(p->r, x);
	}
}

//Tim vao cay
Node *tim_36_Trieu_Bai_1_B9_N2_IT(Node *p, int x) {
	if (p != NULL) {
		if (p->v == x) {//Tim thay gia tri x
			return p;
		}
		else {	//Tiep tuc tim kiem nhi phan
			if (p->v > x)
				return tim_36_Trieu_Bai_1_B9_N2_IT(p->l, x);
			else
				return tim_36_Trieu_Bai_1_B9_N2_IT(p->r, x);
		}
	}
	return NULL; //Neu khong tim thay, tra ve NULL
}

//Tim Node the mang
void timNodeTheMang_36_Trieu_Bai_1_B9_N2_IT(Node *&p, Node *&q) {
	//C1: Tim Node Trai nhat cay con Phai
	if (q->l == NULL) {	//tim thay Node Trai nhat
		p->v = q->v;	//Cap nhat gia tri cua node can xoa la gia tri cua node the mang
		p = q;//Cho node p(Node se bi xoa) tro den node the mang. Ra khoi ham, p se bi xoa
		q = q->r;//Cap nhat lai lien ket cua node cha node the mang voi node con cua node the mang
	}
	else timNodeTheMang_36_Trieu_Bai_1_B9_N2_IT(p, q->l);
	//C2: Tim Node Phai nhat cay con Trai
	/*if (q->r == NULL) {
		p->v = q->v;
		p = q;
		q = q->l;
	}
	else timNodeTheMang_36_Trieu_Bai_1_B9_N2_IT(p, q->r);*/
}

//Xoa cay nhi phan
int xoa_36_Trieu_Bai_1_B9_N2_IT(Node *&root, int x) {
	Node *p = tim_36_Trieu_Bai_1_B9_N2_IT(root,x);	//Tim kiem gia tri x
	if (p == NULL) {	//Neu ham tra ve NULL => Khong tim thay	
		return 0;
	}
	else {
		Node *q = p; //q la node the mang -> se xoa sau
		if (p->l == NULL) {	//Neu p chi co 1 Node con la Right
			p = p->r;	
		}
		else if (p->r == NULL) {//Neu p chi co 1 Node con la Left
			p = p->l;
		} else { //Neu p co 2 con Left, Right
			timNodeTheMang_36_Trieu_Bai_1_B9_N2_IT(q, p->r);
		}
		delete q;
		return 1;
	}
}



//Ham duyet cay nhi phan
void duyetLNR_36_Trieu_Bai_1_B9_N2_IT(Node* root, int space) {
	// Base case
	if (root == NULL)
		return;
	// Increase distance between levels
	space += COUNT;
	// Process right child first
	duyetLNR_36_Trieu_Bai_1_B9_N2_IT(root->r, space);
	// Print current node after space
	// count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->v << "\n";
	// Process left child
	duyetLNR_36_Trieu_Bai_1_B9_N2_IT(root->l, space);
}

int main() {
	int n;
	init_36_Trieu_Bai_1_B9_N2_IT(); //Khoi tao
	them_36_Trieu_Bai_1_B9_N2_IT(root, 20);
	them_36_Trieu_Bai_1_B9_N2_IT(root, 40);
	them_36_Trieu_Bai_1_B9_N2_IT(root, 10);


	cout << "  -------- CHUONG 4: CAY NHI PHAN TIM KIEM --------" << endl << endl;
	cout << "\t\t----- MENU -----" << endl;
	cout << "1. Nhap phan tu cho cay" << endl;
	cout << "2. Duyet cay LNR" << endl;
	cout << "3. Xoa mot Node bat ki" << endl;
	cout << "0. Thoat" << endl;
	cout << "\t\t----- END  -----" << endl;
	do {
		cout << "Nhap lua chon: "; cin >> n;
		switch (n) {
		case 1: {
			int x;
			cout << "Nhap gia tri : "; cin >> x;
			them_36_Trieu_Bai_1_B9_N2_IT(root, x);
			duyetLNR_36_Trieu_Bai_1_B9_N2_IT(root, 0);
			break;
		}
		case 2: {
			cout << "Cay nhi phan: " << endl;
			duyetLNR_36_Trieu_Bai_1_B9_N2_IT(root,0);
			break;
		}
		case 3: {
			int x;
			cout << "Nhap gia tri can xoa : "; cin >> x;
			int kt = xoa_36_Trieu_Bai_1_B9_N2_IT(root, x);
			if (kt == 1) {
				cout << "Xoa thanh cong!" << endl;
			}
			else {
				cout << "Khong tim thay " << x << " can xoa!" << endl;
			}
			duyetLNR_36_Trieu_Bai_1_B9_N2_IT(root, 0);
		}
		default:
			break;
		}
	} while (n != 0);

	system("pause");
	return 0;
}