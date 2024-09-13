#define MAX 100
#include <fstream>
#include <iostream>

using namespace std;

int ARR[100][100];
int n; 

struct Node
{	
	int v;
	Node*p;
};

Node *headS = NULL;
Node *headQ = NULL;

Node *creNode_36_Trieu_BFSDFS_B10_N2_IT(int v) {
	Node *p = new Node;
	p->p = NULL;
	p->v = v;
	return p;
}

void pushStack_36_Trieu_BFSDFS_B10_N2_IT(int v) {
	Node*p = creNode_36_Trieu_BFSDFS_B10_N2_IT(v);
	p->p = headS;
	headS = p;
}

void pushQuece_36_Trieu_BFSDFS_B10_N2_IT(int v) {
	if (headQ == NULL) {
		Node *p = creNode_36_Trieu_BFSDFS_B10_N2_IT(v);
		headQ = p;
	}
	else {
		Node *p = headQ;
		Node*q = creNode_36_Trieu_BFSDFS_B10_N2_IT(v);
		while (p->p != NULL) {
			p = p->p;
		}
		p->p = q;
	}
}

int popStack_36_Trieu_BFSDFS_B10_N2_IT() {
	Node *p = headS;
	if (p == NULL) return -1;
	int v = p->v;
	headS = p->p;
	delete p;
	return v;
}

int popQuece_36_Trieu_BFSDFS_B10_N2_IT() {
	Node *p = headQ;
	if (p == NULL) return -1;
	int v = p->v;
	headQ = p->p;
	delete p;
	return v;
}

void readMatrixFile(){
	fstream f;
	f.open("graph.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < n; j++) {
			f >> ARR[i][j];
		}
	}
	f.close();
}

void display() {
	cout << "   ";
	for (int i = 0; i < n; i++) {
		cout << char(65 + i) << "  ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << char(65 + i) << "  ";
		for (int j = 0; j < n; j++) {
			cout << ARR[i][j]<<"  ";
		}
		cout << endl;
	}
}

bool haveQ(int* arr, int n, int v) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == v) return true;
	}
	Node*p = headQ;
	while (p != NULL) {
		if (p->v == v) return true;
		p = p->p;
	}
	return false;
}

bool haveS(int* arr, int n, int v) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == v) return true;
	}
	Node*p = headS;
	while (p != NULL) {
		if (p->v == v) return true;
		p = p->p;
	}
	return false;
}

void BFS(int k) {
	cout << "BFS: ";
	int *bfs = new int[n];
	int nbfs = 0;
	pushQuece_36_Trieu_BFSDFS_B10_N2_IT(k);
	while (headQ != NULL) {
		int v = popQuece_36_Trieu_BFSDFS_B10_N2_IT();
		bfs[nbfs++] = v;
		cout << char(65 + v)<<"  ";
		for (int i = 0; i < n; i++) {
			if (ARR[v][i] == 1) {
				if (!haveQ(bfs, n, i)) {
					pushQuece_36_Trieu_BFSDFS_B10_N2_IT(i);
				}
			}
		}
	}
	cout << endl;
}

void DFS(int k) {
	cout << "DFS: ";
	int *dfs = new int[n];
	int ndfs = 0;
	pushStack_36_Trieu_BFSDFS_B10_N2_IT(k);
	while (headS != NULL) {
		int v = popStack_36_Trieu_BFSDFS_B10_N2_IT();
		cout << char(65 + v) << "  ";
		dfs[ndfs++] = v;
		for (int i = 0; i < n; i++) {
			if (ARR[v][i] == 1 && !haveS(dfs, n, i)) {
				pushStack_36_Trieu_BFSDFS_B10_N2_IT(v);
				pushStack_36_Trieu_BFSDFS_B10_N2_IT(i);
				dfs[ndfs++] = i;
				break;
			}
		}
	}
	cout << endl;
}

int main() {
	int k;
	readMatrixFile();
	display();
	cout << "\t\tBFS / DFS" << endl;
	cout << "=======================" << endl;
	cout << "Nhap dinh bat dau BFS: "; cin >> k;
	BFS(k);
	cout << "Nhap dinh bat dau DFS:  "; cin >> k;
	//bi bug
	DFS(k);
	system("pause");
	return 0;
}