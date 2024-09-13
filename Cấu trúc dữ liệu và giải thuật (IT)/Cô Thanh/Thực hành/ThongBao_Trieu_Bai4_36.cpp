#include <iostream>
using namespace std;

        
void ThongBao_Trieu_Bai6_36(int n){
    if (n>0){
        cout <<"Hom nay toi di hoc CTDLGT buoi 2"<<endl;
        ThongBao_Trieu_Bai6_36(n-1);
    }
}
int main() {
    int n;
    cout <<"Nhap n: ";
    cin >> n;
    if (n>0) {
        ThongBao_Trieu_Bai6_36(n);
    }else{
        cout <<"Vui long nhap lai!"<<endl;
    }
	return 0;
}