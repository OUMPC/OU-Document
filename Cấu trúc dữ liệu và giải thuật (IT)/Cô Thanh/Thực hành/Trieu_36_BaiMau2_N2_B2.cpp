#include <iostream>
#include <fstream>

using namespace std;

struct node {
	int value;
	node*next;
};

node *head;

void init_Trieu_36_BaiMau2_N2_B2() {
	head = NULL;
}

node* creNode_Trieu_36_BaiMau2_N2_B2(int x) {
	node*p = new node;
	p->value = x;
	p->next = NULL;
	return p;
}

void themDau_Trieu_36_BaiMau2_N2_B2(int x) {
	node*p = creNode_Trieu_36_BaiMau2_N2_B2(x);
	p->next = head;
	head = p;
}




void themCuoi_Trieu_36_BaiMau2_N2_B2(int x) {
	node*p = creNode_Trieu_36_BaiMau2_N2_B2(x);
	if (head == NULL) {
		head = creNode_Trieu_36_BaiMau2_N2_B2(x);
	}
	else {
		node*i = head;
		while (i != NULL && i->next != NULL) {
			i = i->next;
		}
		i->next = p;
	}
}

void themSau_Trieu_36_BaiMau2_N2_B2(int x, int y) {
	node*p = creNode_Trieu_36_BaiMau2_N2_B2(y);
	node*i = head;
	bool kt = false;
	while (i != NULL) {
		if (i->value == x) {
			p->next = i->next;
			i->next = p;
			kt = true;
			break;
		}
		i = i->next;
	}
	if (kt) {
		cout << "Them "<<y<< " sau ptu "<< x << endl;
	}
	else {
		cout << "Khong tim thay phan tu can chen!" << endl;
	}
}

void display_Trieu_36_BaiMau2_N2_B2() {
	node*i = head;
	while (i != NULL) {
		cout << i->value << "\t";
		i = i->next;
	}
	cout << endl;
}

node* find_Trieu_36_BaiMau2_N2_B2(int x) {
	node*i = head;
	int j = 0;
	bool kt = false;
	while (i != NULL) {
		if (i->value == x) {
			kt = true;
			cout << "Tim thay " << x << " o vi tri thu " << j << endl;
			return i;
			break;
		}
		j++;
		i = i->next;
	}
	if (!kt) {
		cout << "Khong tim thay " << x << " trong ds" << endl;
	}
	return NULL;
}

int main() {
	init_Trieu_36_BaiMau2_N2_B2();

		themDau_Trieu_36_BaiMau2_N2_B2(5);
		themCuoi_Trieu_36_BaiMau2_N2_B2(99);
		themCuoi_Trieu_36_BaiMau2_N2_B2(88);
		themCuoi_Trieu_36_BaiMau2_N2_B2(77);
		themDau_Trieu_36_BaiMau2_N2_B2(10);
		themDau_Trieu_36_BaiMau2_N2_B2(15);
	
	display_Trieu_36_BaiMau2_N2_B2();

	
	themSau_Trieu_36_BaiMau2_N2_B2(99, 77);
	display_Trieu_36_BaiMau2_N2_B2();
	find_Trieu_36_BaiMau2_N2_B2(108);
	system("pause");
	return 0;
}