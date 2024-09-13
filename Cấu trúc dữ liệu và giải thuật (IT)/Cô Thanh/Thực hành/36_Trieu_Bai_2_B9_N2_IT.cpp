#include <iostream>
#include <fstream>
#define MAX 20

using namespace std;

int arr[MAX][MAX];
char vertex[MAX];
int n=0;

struct Node {
	int value;
	Node*link;
};

Node* first[MAX];

void init_36_Trieu_Bai_2_B9_N2_IT() {
	for (int i = 0; i < n; i++) {
		first[i] = NULL;
	}
}

void insert_first_Trieu_Bai_2_B9_N2_IT(Node*&f, int x) {
	Node *p = new Node;
	p->value = x;
	p->link = f;
	f = p;
}

void input_Trieu_Bai_2_B9_N2_IT()
{
	int d, x, m;
	cout << "nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << "\nnhap dinh thu " << i + 1 << " : ";
		cin >> d;
		insert_first_Trieu_Bai_2_B9_N2_IT(first[i], d);
		cout << "nhap vao so dinh ke cua " << d << " : ";
		cin >> m;
		for (int j = 0; j<m; j++)
		{
			cin >> x;
			insert_first_Trieu_Bai_2_B9_N2_IT(first[i], x);
		}
	}
}

void output_list_Trieu_Bai_2_B9_N2_IT(Node *f)
{
	if (f != NULL)
	{
		Node * p = f;
		while (p != NULL)
		{
			cout << p->value<< " ";
			p = p->link;
		}
	}}
void output_list_Trieu_Bai_2_B9_N2_IT()
{
	if (n>0)
		for (int i = 0; i<n; i++)
		{
			cout << endl << "Danh sach thu " << i + 1 << ": ";
			output_list_Trieu_Bai_2_B9_N2_IT(first[i]);
		}
	else
		cout << "Rong!";
}

//===============================================================
void initGraph_36_Trieu_Bai_2_B9_N2_IT() {
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

void displayGraph_36_Trieu_Bai_2_B9_N2_IT() {
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

void displayAllList_36_Trieu_Bai_2_B9_N2_IT() {
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << ": ";
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				cout << vertex[j]<<" ";
			}
		}
		cout << endl;
	}
}

void initGraphFile_36_Trieu_Bai_2_B9_N2_IT() {
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

int main() {
	initGraph_36_Trieu_Bai_2_B9_N2_IT();

	//initGraphFile_36_Trieu_Bai_2_B9_N2_IT();
	
	displayGraph_36_Trieu_Bai_2_B9_N2_IT();
	cout << " \n";

	system("pause");
	return 0;
}