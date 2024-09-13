#include <iostream>
#include <string>

using namespace std;

struct NV {
	NV() {}
	string ma, ten;
	int nam;
	NV(string ma,string ten,int nam)
	{
		this->ma=ma;
		this->ten=ten;
		this->nam=nam;
	};
	
};

struct node {
	NV data;
	node*next;
};

node *head;

void init_Trieu_36_Bai1_N2_B2() {
	head = NULL;
}

node* creNode_Trieu_36_Bai1_N2_B2(NV x) {
	node*p = new node;
	p->data = x;
	p->next = NULL;
	return p;
}


void themCuoi_Trieu_36_Bai1_N2_B2(NV x) {
	node*p = creNode_Trieu_36_Bai1_N2_B2(x);
	if (head == NULL) {
		head = creNode_Trieu_36_Bai1_N2_B2(x);
	}
	else {
		node*i = head;
		while (i != NULL && i->next != NULL) {
			i = i->next;
		}
		i->next = p;
	}
}



void display_Trieu_36_Bai1_N2_B2(node *&head) {
	node*i = head;
	while (i != NULL) {
		cout << "Ma hv: " << i->data.ma << endl;
		cout << "Ten hv: " << i->data.ten << endl;
		cout << "Nam sinh hv: "<< i->data.nam << endl;
		cout << "================================" << endl;
		i = i->next;
	}
	cout << endl;
}


int main() {
	int n, m;
	init_Trieu_36_Bai1_N2_B2();
	// cout << "Nhap so hv: ";
	// cin >> n;
	// for (int i = 0; i < 3; i++) {
	// 	cin >> n;
	// 	NV temp;
	// 	cout << "Nhap ma: " << endl;
	// 	cout << "Nhap ten: " << endl;
	// 	cout << "Nhap nam sinh: " << endl;
	// 	themCuoi_Trieu_36_Bai1_N2_B2(temp);
	// }
	NV temp = NV("22","nguyen thi b",2007);
	themCuoi_Trieu_36_Bai1_N2_B2(temp);
	temp = NV("11","nguyen van a",2005);
	themCuoi_Trieu_36_Bai1_N2_B2(temp);
	display_Trieu_36_Bai1_N2_B2(head);	
	system("pause");
	return 0;
}