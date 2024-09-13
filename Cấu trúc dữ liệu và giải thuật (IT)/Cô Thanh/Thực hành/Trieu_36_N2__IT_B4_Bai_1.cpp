#include <iostream>
using namespace std;

const int MAX=10;
//Khoi tao kieu du lieu stack
struct Stack{
    int top;
    int arr[MAX];
};

//Khoi tao Stack
void init_Trieu_36_N2__IT_B4_Bai_1(Stack& a){
    a.top=-1;
}
//Them phan tu vao Stack
void push_Trieu_36_N2__IT_B4_Bai_1(Stack&a,int v) {
    a.arr[++a.top]=v; //Tang top, dòn thoi gan v vao arr[top] trong Stack
}
//Day phan tu ra khoi Stack
int pop_Trieu_36_N2__IT_B4_Bai_1(Stack&a) {
    int v=a.arr[a.top--]; //Gan a[top] hien tai vao v, dong thoi giam top xuong 1 don vi 
}
//Kiem tra Stack rong
bool isEmpty_Trieu_36_N2__IT_B4_Bai_1(Stack a) {
    return (a.top<0); //Neu top < 0 thi tra ve true, nguoc lai false
}
//Kiem tra Stack day
bool isFull_Trieu_36_N2__IT_B4_Bai_1(Stack a) {
    return (a.top>=MAX-1); //Neu top >= 99 thi tra ve true, nguoc lai false
}
//In cac phan tu trong Stack
bool display_Trieu_36_N2__IT_B4_Bai_1(Stack a) {
    if (isEmpty_Trieu_36_N2__IT_B4_Bai_1(a)) {
        cout <<"Stack rong!"<<endl;
    }else{
        for (int i=0;i<=a.top;i++) {
        cout <<a.arr[i]<<" ";
        }
        cout <<endl;
    }
}
//Ham thuc kien su kien

//Thap phan sang nhi phan
void decToBin_Trieu_36_N2__IT_B4_Bai_1(){
    int n;
            cin >> n;
            Stack b;
            init_Trieu_36_N2__IT_B4_Bai_1(b);
            while (n!=0) {
                push_Trieu_36_N2__IT_B4_Bai_1(b,n%2);
                n=n/2;
            }
            while (!isEmpty_Trieu_36_N2__IT_B4_Bai_1(b)) {
                cout << pop_Trieu_36_N2__IT_B4_Bai_1(b);
            }
            cout <<endl;
}

void app_Trieu_36_N2__IT_B4_Bai_1(char key,Stack&sk,bool &initflag){
    switch (key) {
        case '1':{ //Khoi tao
            initflag=true; //Doi bien co
            init_Trieu_36_N2__IT_B4_Bai_1(sk);
            cout <<"Da khoi tao Stack!"<<endl;
            break;
        }
        case '2':{
            if (!initflag) { //Kiem tra stack da khoi tao chua
                cout <<"Stack chua duoc khoi tao!"<<endl;
                break;
            }
            bool result = isEmpty_Trieu_36_N2__IT_B4_Bai_1(sk);
            if (result) {
                cout<<"Stack dang rong!"<<endl;
            }else{
                cout <<"Stack khong rong!"<<endl;
            }
            break;
        }
        case '3':{
            if (!initflag) { //Kiem tra stack da khoi tao chua
                cout <<"Stack chua duoc khoi tao!"<<endl;
                break;
            }
            bool result = isFull_Trieu_36_N2__IT_B4_Bai_1(sk);
            if (result) {
                cout<<"Stack da day!"<<endl;
            }else{
                cout <<"Stack chua day!"<<endl;
            }
            break;
        }
        case '4':{
            if (!initflag) { //Kiem tra stack da khoi tao chua
                cout <<"Stack chua duoc khoi tao!"<<endl;
                break;
            }
            if (isFull_Trieu_36_N2__IT_B4_Bai_1(sk)) {
                cout <<"Stack day! Khong the them phan tu!"<<endl;
            }else{
                int v;
                cin >> v;
                push_Trieu_36_N2__IT_B4_Bai_1(sk,v);
            }
            display_Trieu_36_N2__IT_B4_Bai_1(sk);
            break;
        }
        case '5':{
            if (!initflag) { //Kiem tra stack da khoi tao chua
                cout <<"Stack chua duoc khoi tao!"<<endl;
                break;
            }
            if (isEmpty_Trieu_36_N2__IT_B4_Bai_1(sk)) {
                cout <<"Stack rong! Khong the xoa phan tu!"<<endl;
            }else{
                cout <<pop_Trieu_36_N2__IT_B4_Bai_1(sk)<<endl;\
                display_Trieu_36_N2__IT_B4_Bai_1(sk);

            }
            
            break;
        }
        case '6':{
            if (!initflag) { //Kiem tra stack da khoi tao chua
                cout <<"Stack chua duoc khoi tao!"<<endl;
                break;
            }
            display_Trieu_36_N2__IT_B4_Bai_1(sk);
            break;
        }
        case '7':{
            decToBin_Trieu_36_N2__IT_B4_Bai_1();
            break;
        }
        case '0':{
            break;
        }
        default:{
            cout <<"Yeu cau khong hop le!"<<endl;
        }
    }
}

int main() {
    char key;
    bool initFlag=0; //Bien kiem tra Stack da khoi tao chua
    Stack sk;
    while (key!='0') {
        cout <<"_____________________________"<<endl;
        cout <<"Stack's menu:"<<endl;
        cout <<"1. Khoi tao stack,"<<endl;
        cout <<"2. Kiem tra Stack rong,"<<endl;
        cout <<"3. Kiem tra Stack day,"<<endl;
        cout <<"4. Them phan tu vao Stack,"<<endl;
        cout <<"5. Xoa phan tu trong Stack,"<<endl;
        cout <<"6. Xuat cac ptu trong Stack ra man hinh."<<endl;
        cout <<"7. Chuyen thap phan sang nhi phan*"<<endl;
        cout <<"0. Thoat chuong trinh."<<endl;
        cout <<">";
        cin >> key; //bat su kien phim bam
        system("cls");
        app_Trieu_36_N2__IT_B4_Bai_1(key,sk,initFlag); //Thuc hien yeu cau        
    }
	return 0;
}