#include <iostream>
#include <fstream>
#define MAX 20

using namespace std;

int arr[MAX][MAX];
char vertex[MAX];
int n = 0;

struct Node {
	int info;
	Node *link;
};

void initGraph_36_Trieu_Bai_1_B10_N2_IT() {
	cout << "Nhap so luong do thi: ";
	cin >> n;
	cout << "Nhap ten cac dinh do thi theo thu tu: ";
	for (int i = 0; i < n; i++) {
		cin >> vertex[i];
	}
	for (int i = 0; i < n; i++) {
		cout << "Nhap (0/1) cac dinh voi " << vertex[i] << ": ";
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

void displayGraph_36_Trieu_Bai_1_B10_N2_IT() {
	cout << " ";
	for (int i = 0; i < n; i++) {
		cout << " " << vertex[i];
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << " ";
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void displayAllList_36_Trieu_Bai_1_B10_N2_IT() {
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << ": ";
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				cout << vertex[j] << " ";
			}
		}
		cout << endl;
	}
}

void initGraphFile_36_Trieu_Bai_1_B10_N2_IT() {
	fstream f;
	f.open("graph.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> vertex[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> arr[i][j];
		}
	}
	f.close();
}
//BFS
Node*creNode_36_Trieu_Bai_1_B10_N2_IT(int x) {
	Node *p = new Node;
	p->link = NULL;
	p->info = x;
	return p;
}

void pushQ_36_Trieu_Bai_1_B10_N2_IT(Node *&f, int x) {
	if (f == NULL) {
		f = creNode_36_Trieu_Bai_1_B10_N2_IT(x);
	}
	else {
		Node*p = f;
		while (p->link != NULL) p=p->link;
		p->link = creNode_36_Trieu_Bai_1_B10_N2_IT(x);
	}
}

int popQ_36_Trieu_Bai_1_B10_N2_IT(Node *&f) {
	if (f != NULL) {
		int v = f->info;
		Node *p = f;
		f = f->link;
		delete p;
		return v;
	}
	else {
		return -999;
	}
}

int C[100], bfs[100];
int nbfs = 0;

void initC() {
	for (int i = 0; i < n; i++) {
		C[i] = 1;
	}
}

void BFS_36_Trieu_Bai_1_B10_N2_IT(int v,Node*&f) {
	int w, p;
	pushQ_36_Trieu_Bai_1_B10_N2_IT(f, v);
	C[v] = 0;
	while (f != NULL) {
		p=popQ_36_Trieu_Bai_1_B10_N2_IT(f);
		bfs[nbfs++] = p;

		for (w = 0; w < n; w++) {
			if (C[w] && arr[p][w]) {
				pushQ_36_Trieu_Bai_1_B10_N2_IT(f,w);
				C[w] = 0;
			}
		}
	}
	cout << "DUYET BFS: ";
	for (int i = 0; i < p; i++) {
		cout << bfs[i] << " ";
	}
	cout << endl;
}

int main() {
	cout << "----- BAI TAP CHUONG 4, CHUONG 5, DO THI -----" << endl;
	cout << "1. Khoi tao MA TRAN KE rong" << endl;
	cout << "2. Nhap MA TRAN KE tu file text" << endl;
	cout << "3. Nhap MA TRAN KE" << endl;
	cout << "4. Xuat MA TRAN KE" << endl;
	cout << "5. Duyet do thi theo chieu rong BFS - MTK" << endl;
	cout << "6. Duyet do thi theo chieu rong DFS - MTK" << endl;
	cout << "7. Tim dinh co ggia tri x theo BFS" << endl;
	cout << "8. Thoat" << endl;
	int select;
	do {
		cout << ">> Nhap lua chon: "; cin >> select;
		switch (select) {
			case 1: {
				n = 0;
				cout << "Khoi tao rong thanh cong!" << endl << endl;
				break;
			}
			case 2: {
				initGraphFile_36_Trieu_Bai_1_B10_N2_IT();
				cout << "Nhap tu file thanh cong!" << endl << endl;
				break;
			}
			case 3: {
				initGraph_36_Trieu_Bai_1_B10_N2_IT();
				break;
			}
			case 4: {
				displayGraph_36_Trieu_Bai_1_B10_N2_IT();
				break;
			}
			case 5: {
				int v;
				Node *f = NULL;
				cout << "Nhap dinh bat dau: "; cin >> v;
				BFS_36_Trieu_Bai_1_B10_N2_IT(v,f);
				break;
			}
		}
	} while (select != 8);
	system("pause");
	return 0;
}