#include <iostream>
using namespace std;

//Ham hoan vi 2 phan tu
void hoanVi_36_Trieu_N2_IT_Bai1(int &a, int &b) {
	int delta = a;
	a = b;
	b = delta;
}

//input
void input_36_Trieu_N2_IT_Bai1(int a[],int &n) {
	cout << "Nhap n:"; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]="; cin >> a[i];
	}
}

//Bubble sort
void Bubble_36_Trieu_N2_IT_Bai1(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i;j--) {
			if (a[j]<a[j-1]){
				hoanVi_36_Trieu_N2_IT_Bai1(a[j -1], a[j]);
			}
		}
	}
}

//Insertion sort
void Insertion_36_Trieu_N2_IT_Bai1(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;	//Lay toa do bat dau lui
		int x = a[i];  //Lay gia tri phan tu chen
		while (j >= 0 && a[j] > x) { //So sanh phan tu chen voi phan tu a[j] 
			a[j + 1] = a[j];	//Neu dung thi doi a[j] len mot phan tu
			j--;
		}
		a[j+1] = x; //Gan phan tu chen vao vi tri thoa man
	}
}
//Selection Sort
void Selection_36_Trieu_N2_IT_Bai1(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		//Di chuyen ranh gioi mang da sap xep va chua sap xep
		int vt = i; //Vi tri phan tu min
		for (int j = i + 1; j < n; j++) { //Tim phan tu min
			if (a[j] < a[vt]) {
				vt = j;
			}
		}
		hoanVi_36_Trieu_N2_IT_Bai1(a[i], a[vt]); //Hoan vi ptu min cho i ve dau
	}
}

//Interchage
void Interchange_36_Trieu_N2_IT_Bai1(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j<n; j++)
			if (a[i]>a[j])
				hoanVi_36_Trieu_N2_IT_Bai1(a[i], a[j]); //Doi cho a[i] va a[j]
}

//quick sort
void Quicksort_36_Trieu_N2_IT_Bai1(int a[], int l, int r) {
	int x = a[(l + r) / 2]; //lay phan tu giua
	int i = l, j = r;
	while (i < j) { //Vong lap doi cho
		while (a[i] < x) i++; //Tim phan tu be hon x
		while (a[j] > x) j--; //Tim phan tu lon hon x
		if (i <= j) { //Neu van con nam 2 ben mid thi hoan vi cho 2 ben
			hoanVi_36_Trieu_N2_IT_Bai1(a[i], a[j]);
			i++;
			j--;
		}
	}
	//Kiem tra neu mang con con phan tu va de quy Quicksort
	if (l < j) Quicksort_36_Trieu_N2_IT_Bai1(a, l, j); 
	if (r > i) Quicksort_36_Trieu_N2_IT_Bai1(a, i, r);
}

//Xuat mang
void output_36_Trieu_N2_IT_Bai1(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout <<endl;
}

int main() {
	int a[] = { 3,-5,9,0,7,3,20 };
	int n = sizeof(a) / sizeof(a[0]);
	
	cout << "Xep thu tu danh sach bang INSERTION SORT" << endl;
	Insertion_36_Trieu_N2_IT_Bai1(a, n);
	output_36_Trieu_N2_IT_Bai1(a, n);

	cout << "Xep thu tu danh sach bang SELECTION SORT" << endl;
	Selection_36_Trieu_N2_IT_Bai1(a, n);
	output_36_Trieu_N2_IT_Bai1(a, n);

	cout << "Xep thu tu danh sach bang BUBBLE SORT" << endl;
	Bubble_36_Trieu_N2_IT_Bai1(a, n);
	output_36_Trieu_N2_IT_Bai1(a, n);

	cout << "Xep thu tu danh sach bang INTERCHANGE SORT" << endl;
	Bubble_36_Trieu_N2_IT_Bai1(a, n);
	output_36_Trieu_N2_IT_Bai1(a, n);

	cout << "Xep thu tu danh sach bang QUICK SORT" << endl;
	Quicksort_36_Trieu_N2_IT_Bai1(a, 0,n-1);
	output_36_Trieu_N2_IT_Bai1(a, n);
	//=====================
	int b[1000];
	input_36_Trieu_N2_IT_Bai1(b, n);
	cout << "Xep thu tu danh sach bang INSERTION SORT" << endl;
	Insertion_36_Trieu_N2_IT_Bai1(b, n);
	output_36_Trieu_N2_IT_Bai1(b, n);

	cout << "Xep thu tu danh sach bang SELECTION SORT" << endl;
	Selection_36_Trieu_N2_IT_Bai1(b, n);
	output_36_Trieu_N2_IT_Bai1(b, n);

	cout << "Xep thu tu danh sach bang BUBBLE SORT" << endl;
	Bubble_36_Trieu_N2_IT_Bai1(b, n);
	output_36_Trieu_N2_IT_Bai1(b, n);

	cout << "Xep thu tu danh sach bang INTERCHANGE SORT" << endl;
	Bubble_36_Trieu_N2_IT_Bai1(b, n);
	output_36_Trieu_N2_IT_Bai1(b, n);

	cout << "Xep thu tu danh sach bang QUICK SORT" << endl;
	Quicksort_36_Trieu_N2_IT_Bai1(b, 0, n - 1);
	output_36_Trieu_N2_IT_Bai1(b, n);

	system("pause");
	return 0;
}