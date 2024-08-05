/*Cau 1
a)Cho mảng một chiều gồm n số nguyên a0,a1,...an-1 viết hàm đệ quy tính tổng các phần tử của mảng
b)Viết hàm đệ quy chuyển đổi một số nguyên dương không âm từ hệ đếm thập phân thành số trong hệ đếm cơ số k với k<=16 trong đó 16 ký số được sử dụng là 0,1,.....9,A,B,C,D,E,F ,ví dụ n=2022 và k bằng 16 thì được kết quả 7E6
*/
#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

// a) Hàm đệ quy tính tổng các phần tử của mảng
int tinh_tong(int a[], int n) {
    if (n == 0) return 0;
    return a[n - 1] + tinh_tong(a, n - 1);
}

// b) Hàm đệ quy chuyển đổi số từ hệ thập phân sang hệ cơ số k
void chuyen10sangk(int n, int k, char KQ[], int &d) {
    if (n == 0) {
        return; // Điều kiện dừng của đệ quy
    }

    int x = n % k; // Lấy phần dư của n khi chia cho k
    n = n / k; // Chia n cho k

    // Gọi đệ quy cho phần nguyên còn lại
    chuyen10sangk(n, k, KQ, d);

    // Lưu phần dư vào mảng KQ
    if (x < 10) {
        KQ[d] = x + '0'; // Chuyển phần dư thành ký tự số
    } else {
        KQ[d] = x - 10 + 'A'; // Chuyển phần dư thành ký tự chữ cái (A-F)
    }
    d++; // Tăng chỉ số d để chuẩn bị lưu ký tự tiếp theo
}

int main() {
    // a) Tính tổng các phần tử của mảng
    int n;
    cout << "Nhap n (so phan tu cua mang): ";
    cin >> n;
    int a[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tong = tinh_tong(a, n);
    cout << "Tong phan tu mang la: " << tong << endl;

    // b) Chuyển đổi số từ hệ thập phân sang hệ cơ số k
    int nb;
    cout << "Nhap so nguyen d: ";
    cin >> nb;
    int k;
    cout << "Nhap co so k (2 <= k <= 16): ";
    cin >> k;

    char KQ[65] = {0}; // Mảng để lưu trữ kết quả (64 bits đủ cho một số lớn)
    int d = 0; // Biến để theo dõi vị trí hiện tại trong mảng KQ

    if (nb == 0) {
        KQ[d++] = '0'; // Nếu nb là 0, đặt KQ là '0'
    } else {
        chuyen10sangk(nb, k, KQ, d); // Gọi hàm đệ quy để chuyển đổi
    }

    KQ[d] = '\0'; // Kết thúc chuỗi KQ bằng ký tự null

    cout << "Ket qua chuyen sang he " << k << ": " << KQ << endl;

    return 0;
}

