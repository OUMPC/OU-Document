#include <iostream>
#include <ctime>
using namespace std;

//Ham hoan vi 2 phan tu
void hoanVi_36_Trieu_N2_IT_B8_Bai_1(int &a, int &b) {
	int delta = a;
	a = b;
	b = delta;
}

//input
void input_36_Trieu_N2_IT_B8_Bai_1(int a[], int &n) {
	cout << "Nhap n:"; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]="; cin >> a[i];
	}
}
//Tao mang random
void random_36_Trieu_N2_IT_B8_Bai_1(int a[], int &n) {
	cout << "Nhap n:"; cin >> n;
	for (int i = 0; i < n; i++) {
		a[i] = (rand() % 31) - 10;
	}
	cout << "Tao thanh cong!" << endl;
}

//Bubble sort
void Bubble_36_Trieu_N2_IT_B8_Bai_1(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[j]<a[j - 1]) {
				hoanVi_36_Trieu_N2_IT_B8_Bai_1(a[j - 1], a[j]);
			}
		}
	}
}

//Insertion sort
void Insertion_36_Trieu_N2_IT_B8_Bai_1(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;	//Lay toa do bat dau lui
		int x = a[i];  //Lay gia tri phan tu chen
		while (j >= 0 && a[j] > x) { //So sanh phan tu chen voi phan tu a[j] 
			a[j + 1] = a[j];	//Neu dung thi doi a[j] len mot phan tu
			j--;
		}
		a[j + 1] = x; //Gan phan tu chen vao vi tri thoa man
	}
	cout << "Sap xep thanh cong!" << endl;

}
//Selection Sort
void Selection_36_Trieu_N2_IT_B8_Bai_1(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		//Di chuyen ranh gioi mang da sap xep va chua sap xep
		int vt = i; //Vi tri phan tu min
		for (int j = i + 1; j < n; j++) { //Tim phan tu min
			if (a[j] < a[vt]) {
				vt = j;
			}
		}
		hoanVi_36_Trieu_N2_IT_B8_Bai_1(a[i], a[vt]); //Hoan vi ptu min cho i ve dau
	}
	cout << "Sap xep thanh cong!" << endl;
}

//Interchage
void Interchange_36_Trieu_N2_IT_B8_Bai_1(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j<n; j++)
			if (a[i]>a[j])
				hoanVi_36_Trieu_N2_IT_B8_Bai_1(a[i], a[j]); //Doi cho a[i] va a[j]
	cout << "Sap xep thanh cong!" << endl;
}

//quick sort
void Quicksort_36_Trieu_N2_IT_B8_Bai_1(int a[], int l, int r) {
	int x = a[(l + r) / 2]; //lay phan tu giua
	int i = l, j = r;
	while (i < j) { //Vong lap doi cho
		while (a[i] < x) i++; //Tim phan tu be hon x
		while (a[j] > x) j--; //Tim phan tu lon hon x
		if (i <= j) { //Neu van con nam 2 ben mid thi hoan vi cho 2 ben
			hoanVi_36_Trieu_N2_IT_B8_Bai_1(a[i], a[j]);
			i++;
			j--;
		}
	}
	//Kiem tra neu mang con con phan tu va de quy Quicksort
	if (l < j) Quicksort_36_Trieu_N2_IT_B8_Bai_1(a, l, j);
	if (r > i) Quicksort_36_Trieu_N2_IT_B8_Bai_1(a, i, r);
}

//Xuat mang
void output_36_Trieu_N2_IT_B8_Bai_1(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}
//Ham shift cua heapsort
void shift_36_Trieu_N2_IT_B8_Bai_1(int a[], int i, int n) {
	int j = 2 * i + 1;
	if (j >= n) // kiem tra vi tri j co ton tai khong
		return;
	if (j + 1 < n) // neu ton tai vi tri j+1 thi khong xet
		if (a[j]<a[j + 1]) j++;// a[j] <a[j+1] thi j = j+1
			
	if (a[i] >= a[j]) {
		return;// Neu a[i] >= a[j] thi shift theo j, khong thi dung
	} else {
		hoanVi_36_Trieu_N2_IT_B8_Bai_1(a[i], a[j]);
		shift_36_Trieu_N2_IT_B8_Bai_1(a, j, n);
	}
}
//HEAPSORT 
void Heapsort_36_Trieu_N2_IT_B8_Bai_1(int a[], int n) {
	int i = n / 2;
	while (i >= 0) { // tao heap dau
		shift_36_Trieu_N2_IT_B8_Bai_1(a, i, n); 
		i--;
	}
	int right = n - 1; // right la vi tri cuoi
	while (right>0) {
		hoanVi_36_Trieu_N2_IT_B8_Bai_1(a[0], a[right]); // hoan vi a[0] va phan tu cuoi mang
		right--; // giam gioi han
		if (right > 0) // Kiem tra mang con 2 ptu tro len
			shift_36_Trieu_N2_IT_B8_Bai_1(a, 0, right+1); // tao lai heap o vi tri 0
	}
	cout << "Sap xep thanh cong!" << endl;
}
//MERGE SORT
void Merge_36_Trieu_N2_IT_B8_Bai_1(int a[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = new int[n1], *R=new int[n2]; // Sao chep tam L[] và R[]
	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	// Merge cac mang tam vao a[l..r]
	int i = 0; 
	int j = 0; 
	int k = l; 

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	//sao cheo phan l[] con lai neu co
	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}
	//sao cheo phan r[] con lai neu co
	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
	delete []L;
	delete []R;
}

// Ham Mergesort
void Mergesort_36_Trieu_N2_IT_B8_Bai_1(int a[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2; // Tim mid

		// De quy sap xep mang con ben trai va phai
		Mergesort_36_Trieu_N2_IT_B8_Bai_1(a, l, m);
		Mergesort_36_Trieu_N2_IT_B8_Bai_1(a, m + 1, r);

		// Hop nhap 2 mang con
		Merge_36_Trieu_N2_IT_B8_Bai_1(a, l, m, r);
	}
}
////////////////////////////////////////////////////////////////////////
//Tim kiem tuan tu
int searchSequece_36_Trieu_N2_IT_B8_Bai_1(int a[], int n, int x) {
	int i = 0;
	while (i<n && a[i] != x) {
		i++;
	}
	if (i == n) { //Dat gioi han => khong tim thay
		return -1;
	}
	else {
		return i;//Tim thay
	}
}
//Tim kiem nhi phan
int searchBinary_36_Trieu_N2_IT_B8_Bai_1(int a[], int l, int r, int x) {
	if (r > 0 && l<r) {
		int mid = l + (r - l) / 2; //Lay khoang giua Left va Right
								   //Neu a[mid] tim thay thi tra ve
		if (a[mid] == x) return mid;
		//Neu a[mid] > x thi tiep tuc tim kiem ben trai
		if (a[mid] > x) return searchBinary_36_Trieu_N2_IT_B8_Bai_1(a, l, mid - 1, x);
		//Nguoc lai, a[mid] < x thi tiep tuc tim kiem ben phai
		return searchBinary_36_Trieu_N2_IT_B8_Bai_1(a, mid + 1, r, x);
	}
	return -1; //Neu khong tim thay
}

int main() {
	srand(time(NULL));
	int a[1000];
	int n = 0;
	int key;
	do {
		cout << "------------- CHUONG 3: XEP THU TU VA TIM KIEM -------------" << endl;
		cout << "0. Khoi tao danh sach ngau nhien," << endl;
		cout << "1. Nhap danh sach," << endl;
		cout << "2. Xuat danh sach," << endl;
		cout << "3. Xep thu tu bang Selection Sort," << endl;
		cout << "4. Xep thu tu bang Insertion Sort," << endl;
		cout << "5. Xep thu tu bang Interchange Sort" << endl;
		cout << "6. Xep thu tu bang Bubble Sort" << endl;
		cout << "7. Xep thu tu bang Quick Sort" << endl;
		cout << "8. Xep thu tu bang HEAP SORT" << endl;
		cout << "9. Xep thu tu bang MERGE SORT" << endl;
		cout << "10. Tim kiem phan tu x bang TIM KIEM TUAN TU" << endl;
		cout << "11. Tim kiem phan tu x bang TIM KIEM NHI PHAN" << endl;
		cout << "12. Thoat." << endl;
		cout << ">";
		cin >> key;
		system("cls");
		switch (key) {
		case 0: {
			random_36_Trieu_N2_IT_B8_Bai_1(a, n);
			output_36_Trieu_N2_IT_B8_Bai_1(a, n);
			break;
		}
		case 1: {
			input_36_Trieu_N2_IT_B8_Bai_1(a, n);
			break;
		}
		case 2: {
			output_36_Trieu_N2_IT_B8_Bai_1(a, n);
			break;
		}
		case 3: {
			Selection_36_Trieu_N2_IT_B8_Bai_1(a, n);
			break;
		}
		case 4: {
			Insertion_36_Trieu_N2_IT_B8_Bai_1(a, n);
			break;
		}
		case 5: {
			Interchange_36_Trieu_N2_IT_B8_Bai_1(a, n);
			break;
		}
		case 6: {
			Bubble_36_Trieu_N2_IT_B8_Bai_1(a, n);
			break;
		}
		case 7: {
			Quicksort_36_Trieu_N2_IT_B8_Bai_1(a, 0, n - 1);
			cout << "Sap xep thanh cong!" << endl;
			break;
		}
		case 8: {
			Heapsort_36_Trieu_N2_IT_B8_Bai_1(a, n);
			break;
		}
		case 9: {
			Mergesort_36_Trieu_N2_IT_B8_Bai_1(a, 0, n - 1);
			cout << "Sap xep thanh cong!" << endl;
			break;
		}
		case 10: {
			output_36_Trieu_N2_IT_B8_Bai_1(a, n);
			int x, r;
			cout << "Nhap so can tim: ";
			cin >> x;
			r = searchSequece_36_Trieu_N2_IT_B8_Bai_1(a, n, x);
			if (r<0) {
				cout << "Khong tim thay "<<x << endl;
			}
			else {
				cout << "Tim thay o vi tri " << r << endl;
			}
			break;
		}
		case 11: {
            Selection_36_Trieu_N2_IT_B8_Bai_1(a,n);
			output_36_Trieu_N2_IT_B8_Bai_1(a, n);
			int x, r;
			cout << "Nhap so can tim: ";
			cin >> x;
			r = searchBinary_36_Trieu_N2_IT_B8_Bai_1(a, 0, n - 1, x);
			if (r<0) {
				cout << "Khong tim thay "<<x << endl;
			}
			else {
				cout << "Tim thay o vi tri " << r << endl;
			}
			break;
		}
		case 12: {
			break;
		}
		}
	} while (key != 12);
	system("pause");
	return 0;
}