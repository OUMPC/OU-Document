#include <iostream>
#include <ctime>
using namespace std;

void Nhap_Trieu_Bai1_36(int arr[],int &n) {
    //Ham a. Nhap danh sach
    char a;
b1:
    cout <<"   1. Nhap random,"<<endl;
    cout <<"   2. Nhap thu cong.,"<<endl;
    cout <<   "/>";
    cin >> a;
    switch(a){
        case '1':{
            cout <<"Nhap so luong phan tu: ";
            cin >> n;
            for (int i=0;i<n;i++) {
                //10 ->50
                arr[i]=(rand()%41)+10;
                cout <<"Nhap phan tu ["<<i<<"]: "<<arr[i]<<endl;
            }
            cout<<endl;
            break;
        }
        case '2':{
            cout <<"Nhap so luong phan tu: ";
            cin >> n;
            for (int i=0;i<n;i++) {
                //10 ->50
                cout <<"Nhap phan tu ["<<i<<"]: ";
                cin >> arr[i];
            }
            cout<<endl;
            break;
        }
        default:{
            goto b1;
        }
    }
}

void Xuat_Trieu_Bai1_36(int arr[],int n) {
    for (int i=0;i<n;i++) {
        //10 ->50
        cout <<arr[i]<<"\t";
    }
    cout <<endl;
}

void TimPtu_Trieu_Bai1_36(int arr[],int n) {
    int x;
    cout <<"Moi nhap gia tri can tim:";
    cin>>x;
    bool kt=false;
    for (int i=0;i<n;i++) {
        if (arr[i]==x){
            kt=true;
            if (i==0) {
                cout <<"Tim thay x o vi tri dau: "<<i<<endl;
            }else if(i==(n-1)){
                cout <<"Tim thay x o vi tri cuoi: "<<i<<endl;
            }else{
                cout <<"Tim thay x o vi tri: "<<i<<endl;
            }
        }
    }
    if (!kt) cout <<"Khong tim thay gia tri!"<<endl; 
}

void ThemPtu_Trieu_Bai1_36(int arr[],int&n) {
    int vt=0,x=0;
    char a;
    cout <<"Nhap gia tri x can chen: ";cin >> x;
b4:
    cout <<"1. Them o vi tri dau,"<<endl;
    cout <<"2. Them o vi tri cuoi,"<<endl;
    cout <<"3. Them o vi tri thu cong."<<endl;
    cout <<"/>";
    cin >> a;
    switch (a){
        case '1':{
            vt=0;
            break;
        }
        case '2':{
            vt=n;
            break;
        }
        case '3':{
            do {
                cout <<"Moi nhap vi tri (0 -> "<<n<<"): ";
                cin >> vt;
            }while(vt<0 || vt>=n);
            break;
        }
        default:{
            goto b4;
        }
    }
    int temp=arr[vt];
    arr[vt]=x;
    for (int i=vt+1;i<=n;i++) {
        swap(temp,arr[i]);
    }
    n++;
    cout <<"-- Ket qua sau khi chen -- "<<endl;
    Xuat_Trieu_Bai1_36(arr,n);
}

void XoaPtu_Trieu_Bai1_36(int arr[],int&n) {
    int vt=0;
    char a;
b5:
    cout <<"1. Xoa o vi tri dau,"<<endl;
    cout <<"2. Xoa o vi tri cuoi,"<<endl;
    cout <<"3. Xoa o vi tri thu cong."<<endl;
    cout <<"/>";
    cin >> a;
    switch (a){
        case '1':{
            vt=0;
            break;
        }
        case '2':{
            vt=n-1;
            break;
        }
        case '3':{
            do {
                cout <<"Moi nhap vi tri (0 -> "<<n-1<<"): ";
                cin >> vt;
            }while(vt<0 || vt>=n);
            break;
        }
        default:{
            goto b5;
        }
    }
    for (int i=vt;i<=n;i++) {
        swap(arr[i+1],arr[i]);
    }
    arr[n-1]=0;
    n--;
    cout <<"-- Ket qua sau khi xoa -- "<<endl;
    Xuat_Trieu_Bai1_36(arr,n);
}

int main() {
    int n=0;
    int arr[300];
    srand(time(NULL));
    //Nhap danh sach
    cout <<"a. Nhap danh sach:"<<endl;
    Nhap_Trieu_Bai1_36(arr,n);
    //Xuat danh sach
    cout <<"b. Xuat danh sach: ";
    Xuat_Trieu_Bai1_36(arr,n);    
    //Tim 1 phan tu
    cout <<"c. Tim phan tu trong danh sach"<<endl;
    TimPtu_Trieu_Bai1_36(arr,n);
    //Them mot phan tu
    cout <<"d. Them phan tu trong danh sach"<<endl;
    ThemPtu_Trieu_Bai1_36(arr,n);
    //Xoa phan tu
    cout <<"e. Xoa phan tu trong danh sach"<<endl;
    XoaPtu_Trieu_Bai1_36(arr,n);
	return 0;
}