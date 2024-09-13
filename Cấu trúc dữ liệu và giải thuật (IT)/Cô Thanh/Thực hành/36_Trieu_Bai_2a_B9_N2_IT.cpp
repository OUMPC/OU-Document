#include <iostream>
#include <fstream>
#define MAX 20

using namespace std;

int arr[MAX][MAX];
char vertex[MAX];
int n = 0;

struct Node {
	int value;
	Node*link;
};

Node* first[MAX];

void init_36_Trieu_Bai_2a_B9_N2_IT() {
	for (int i = 0; i < n; i++) {
		first[i] = NULL;
	}
}

void insert_first_36_Trieu_Bai_2a_B9_N2_IT(Node*&f, int x) {
	Node *p = new Node;
	p->value = x;
	p->link = f;
	f = p;
}

void input_36_Trieu_Bai_2a_B9_N2_IT()
{
	int d, x, m;
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nnhap dinh thu " << i + 1 << " : ";
		cin >> d;
		if (d == -1) break;
		insert_first_36_Trieu_Bai_2a_B9_N2_IT(first[i], d);
		cout << "nhap vao so dinh ke cua " << d << " : ";
		cin >> m;
		for (int j = 0; j<m; j++)
		{
			cin >> x;
			insert_first_36_Trieu_Bai_2a_B9_N2_IT(first[i], x);
		}
	}
}

void output_list_36_Trieu_Bai_2a_B9_N2_IT(Node *f)
{
	if (f != NULL)
	{
		Node * p = f;
		while (p != NULL)
		{
			cout << p->value << " ";
			p = p->link;
		}
	}}
void output_list_36_Trieu_Bai_2a_B9_N2_IT()
{
	if (n>0)
		for (int i = 0; i<n; i++)
		{
			cout << endl << "Danh sach thu " << i + 1 << ": ";
			output_list_36_Trieu_Bai_2a_B9_N2_IT(first[i]);
		}
	else
		cout << "Rong!";
}



int main() {	

	init_36_Trieu_Bai_2a_B9_N2_IT();
	input_36_Trieu_Bai_2a_B9_N2_IT();
	output_list_36_Trieu_Bai_2a_B9_N2_IT();

	system("pause");
	return 0;
}