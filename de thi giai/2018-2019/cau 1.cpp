/* Câu 1 2018-2019
Dãy xn được định nghĩa như sau:
x1=1;
xn=n(x1+x2+x3+.....+xn-1) với n>1

a)tính xn đệ quy
b)tính xn không đệ quy
*/
#include<iostream>
#include<math.h>
using namespace std;
//cau a
int tinh_xn_de_quy(int n)
{
	if(n==1) return 1;
	
	return tinh_xn_de_quy(n-1)+n;
}
int cau_a(int n)
{
	return n*tinh_xn_de_quy(n);
}

//cau b
int tinh_xn_khong_de_quy(int n) {
    // Khởi tạo giá trị x_1
    int x_1 = 1;
    // Khởi tạo giá trị tổng
    int tong = 1; // Chú ý: giá trị khởi tạo của tổng phải là 1, không phải là 0
    // Tính tổng từ x_1 đến x_n
    for (int i = 2; i <= n; ++i) { // Chú ý: i chạy từ 2 đến n
        tong += i * x_1;
        x_1 += i;
    }
    // Tính giá trị x_n từ tổng đã tính
    int xn = n * tong;
    return xn;
}



int main()
{
	int n;
	cin>>n;
	int caua=cau_a(n);
	cout <<caua<<endl;
	
	int caub= tinh_xn_khong_de_quy(n);
	cout <<caub<<endl;
	return 0;
}