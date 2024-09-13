#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next, *prev;
};

struct ds_Kep {
	Node *head, *tail;
};
//Khoi tao ds
void init_Trieu_36_Bai_1_N2_B3(ds_Kep &k) {
	k.head = NULL;
	k.tail = NULL;
}

//Ham dem ptu
int length_Trieu_36_Bai_1_N2_B3(ds_Kep k) {
	Node*p = k.tail;
	int d = 0;
	while (p != NULL) {
		d++;
		p = p->prev;
	}
	return d;
}

//Tao Node moi
Node* creNode_Trieu_36_Bai_1_N2_B3(int x) {
	Node *p = new Node;
	p->value = x;
	p->next = p->prev = NULL; //Dau cuoi node la NULL
	return p;
}
//Them dau ds
void themDau_Trieu_36_Bai_1_N2_B3(ds_Kep &k, int x) {
	Node *p = creNode_Trieu_36_Bai_1_N2_B3(x); //Tao node tu ham tren
	if (k.head == NULL) {	//Neu ds rong
		k.head = k.tail = p;
	}
	else {	//Neu ds khong rong
		p->next = k.head;
		k.head->prev = p;
		k.head = p;
	}
}

//Them cuoi ds
void themCuoi_Trieu_36_Bai_1_N2_B3(ds_Kep &k, int x) {
	Node *p = creNode_Trieu_36_Bai_1_N2_B3(x); //Tao node tu ham tren
	if (k.head == NULL) { //Neu ds rong
		k.head = k.tail = p;
	}
	else { //Neu ds khong rong
		p->prev = k.tail;
		k.tail->next = p;
		k.tail = p;
	}
}

//Them sau phan tu
void themSauPtu_Trieu_36_Bai_1_N2_B3(ds_Kep &k, int v, int x) {
	Node *p = creNode_Trieu_36_Bai_1_N2_B3(x);
	Node *q = k.head;
	bool check = 0; //Co kiem tra co phan tu do hay khong?
	while (q != NULL) {
		if (q->value == v) {
			p->prev = q;
			p->next = q->next;
			q->next->prev = p;
			q->next = p;
			check = 1;
			break;
		}
		q = q->next;
	}
	if (!check) {	//In thong bao neu khong tim thay
		cout << "Khong tim thay " << v << endl;
	}
}

void xoaDau_Trieu_36_Bai_1_N2_B3(ds_Kep &k) {
	if (k.head == NULL) {	//Kiem tra ds co rong khong
		cout << "Danh sach khong co phan tu nao!" << endl;
	}
	else {	//Neu khong xet tiep
		Node *p = k.head;
		if (p->next == NULL) {	//Neu ds chi co 1 ptu
			k.head = k.tail = NULL;
		}
		else {	//Neu ds co nhieu ptu
			k.head = p->next;
			p->next->prev = NULL;
			p->next = NULL;
		}
		delete p;
	}
}

void xoaCuoi_Trieu_36_Bai_1_N2_B3(ds_Kep &k) {
	if (k.tail == NULL) {	//Kiem tra ds co rong khong
		cout << "Danh sach khong co phan tu nao!" << endl;
	}
	else { //Neu khong xet tiep
		Node *p = k.tail;
		if (p->prev == NULL) {	//Neu ds chi co 1 ptu
			k.tail = k.head = NULL;
		}
		else {	//Neu ds co nhieu ptu
			k.tail = p->prev;
			p->prev->next = NULL;
			p->prev = NULL;
		}
		delete p;
	}
}
//Xoa sau ptu
void xoaSauPtu_Trieu_36_Bai_1_N2_B3(ds_Kep &k, int v) {
	Node *q = k.head;
	bool check = 0; //Co kiem tra co phan tu do hay khong?
	while (q != NULL) {
		if (q->value == v) {
			if (q->next != NULL) {
				Node *p = q->next;
				q->next = p->next;
				p->next->prev = q;
				delete p;
			}
			else {
				cout << "Khong co phan tu sau " << v << endl;
			}
			check = 1;
			break;
		}
		else q = q->next;
	}
	if (!check) {	//In thong bao neu khong tim thay
		cout << "Khong tim thay " << v << endl;
	}
}
//Xoa tai vi tri v
void xoaTaiViTri_Trieu_36_Bai_1_N2_B3(ds_Kep &k, int v) {
	if (v<0 || v >= length_Trieu_36_Bai_1_N2_B3(k)) {	//Kiem tra pham vi co thoa khong?
		cout << "Vi tri " << v << " khong hop le! " << endl;
		return;
	}
	//Kiem tra co phai vi tri dau khong?

	//Chay vong lap den vtri v;
	Node *q = k.head;
	int i = 0;
	while (q != NULL) {
		if (i == v) {
			if (q == k.head) {
				xoaDau_Trieu_36_Bai_1_N2_B3(k);
			}
			else if (q == k.tail) {
				xoaCuoi_Trieu_36_Bai_1_N2_B3(k);
			}
			else {
				//Noi dau cuoi bo giua
				q->prev->next = q->next;
				q->next->prev = q->prev;
				delete q;
			}
			break;
		}
		i++;
		q = q->next;
	}
}

//In ds theo chieu Trai sang Phai
void output_Trieu_36_Bai_1_N2_B3(ds_Kep k) {
	Node*p = k.head;
	while (p != NULL) {
		cout << p->value << "\t";
		p = p->next;
	}
	cout << endl;
}

//Ham dem ptu chan
int demSoChan_Trieu_36_Bai_1_N2_B3(ds_Kep k) {
	Node*p = k.tail;
	int d = 0;
	while (p != NULL) {
		if (p->value % 2 == 0) d++;
		p = p->prev;
	}
	return d;
}
//Ham tim kiem
Node *timKiem_Trieu_36_Bai_1_N2_B3(ds_Kep k, int v) {
	Node*p = k.head;
	bool check = 0;
	while (p != NULL) {
		if (p->value == v) {
			check = 1;
			cout << "tim thay " << v << " trong danh sach" << endl;
			return p;
			break;
		}
		p = p->next;
	}
	if (!check) {
		cout << " khong tim thay " << v << " trong danh sach" << endl;
	}
	return NULL;
}
//In ds theo chieu Phai sang Trai
void outputRe_Trieu_36_Bai_1_N2_B3(ds_Kep k) {
	Node*p = k.tail;
	while (p != NULL) {
		cout << p->value << "\t";
		p = p->prev;
	}
	cout << endl;
}

int main() {
	ds_Kep k;
	init_Trieu_36_Bai_1_N2_B3(k); //Khoi tao

	int n, x;
	cout << "nhap n:"; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "[" << i << "]: "; cin >> x;
		themCuoi_Trieu_36_Bai_1_N2_B3(k, x);
	}


	output_Trieu_36_Bai_1_N2_B3(k); //In ds tu trai qua phai

									//In thong tin ds gom so ptu dang co va dem so chan
	cout << "danh sach dang co: " << length_Trieu_36_Bai_1_N2_B3(k) << " phan tu" << endl;
	cout << "danh sach cac ptu chan la: " << demSoChan_Trieu_36_Bai_1_N2_B3(k) << " phan tu" << endl;
	//Tim kiem 5 trong ds
	timKiem_Trieu_36_Bai_1_N2_B3(k, 5);
	cout << "xuat danh sach tu phai qua trai" << endl;
	outputRe_Trieu_36_Bai_1_N2_B3(k);

	//Xoa dau xoa cuoi
	cout << "xoa dau\n \n ========== " << endl;
	xoaDau_Trieu_36_Bai_1_N2_B3(k);
	output_Trieu_36_Bai_1_N2_B3(k);

	cout << "xoa cuoi\n \n ========== " << endl;
	xoaCuoi_Trieu_36_Bai_1_N2_B3(k);
	output_Trieu_36_Bai_1_N2_B3(k);



	//Xoa tai vi tri 1
	cout << "xoa ptu tai vi tri 2\n \n ========== " << endl;
	xoaTaiViTri_Trieu_36_Bai_1_N2_B3(k, 2);
	output_Trieu_36_Bai_1_N2_B3(k);

	//In lai thong tin
	cout << "danh sach dang co: " << length_Trieu_36_Bai_1_N2_B3(k) << " phan tu" << endl;
	cout << "danh sach cac ptu chan la: " << demSoChan_Trieu_36_Bai_1_N2_B3(k) << " phan tu" << endl;

	system("pause");
	return 0;
}