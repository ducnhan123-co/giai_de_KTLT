#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void doc_file(int **&a, int &m, int &n) {
    ifstream inputfile("input.txt");
    if (!inputfile.is_open()) {
        cout << "Khong mo duoc file" << endl;
        return;
    }
    inputfile >> m >> n;

    // Khởi tạo mảng 2 chiều
    a = new int*[m + 1];
    for (int i = 1; i <= m; i++) {
        a[i] = new int[n + 1];
    }

    // Đọc dữ liệu vào mảng
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            inputfile >> a[i][j];
        }
    }

    inputfile.close();
}

bool isSquare(int n) {
    if (n < 0) return false;
    int r = static_cast<int>(sqrt(n));
    return (r * r == n);
}

void so_luong_chinh_phuong_va_vi_tri(int **a, int m, int n, ofstream &outputfile) {
    int dem_cp = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (isSquare(a[i][j])) {
                dem_cp++;
            }
        }
    }
    outputfile << dem_cp << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (isSquare(a[i][j])) {
                outputfile << a[i][j] << " " << i << " " << j << endl;
            }
        }
    }
}

void so_luong_chan_le(int **a, int m, int n, ofstream &outputfile) {
    int dem_le = 0;
    int dem_chan = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] % 2 == 0) {
                dem_chan++;
            } else {
                dem_le++;
            }
        }
    }
    outputfile << dem_le << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] % 2 != 0) {
                outputfile << a[i][j] << " ";
            }
        }
    }
    outputfile << endl;
    outputfile << dem_chan << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] % 2 == 0) {
                outputfile << a[i][j] << " ";
            }
        }
    }
    outputfile << endl;
}

void sap_xep_cot_tang_dan(int **&a, int &m, int &n, ofstream &outputfile) {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m - 1; i++) {
            for (int k = i + 1; k <= m; k++) {
                if (a[i][j] > a[k][j]) {
                    swap(a[i][j], a[k][j]);
                }
            }
        }
    }
    outputfile << m << " " << n << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            outputfile << a[i][j] << " ";
        }
        outputfile << endl;
    }
}

void ghi_file_square_file(int **a, int m, int n) {
    ofstream outputfile("square_file.txt");
    if (!outputfile.is_open()) {
        cout << "Khong ghi duoc file." << endl;
        return;
    }
    so_luong_chinh_phuong_va_vi_tri(a, m, n, outputfile);
    outputfile.close();
}

void ghi_file_oddeven_file(int **a, int m, int n) {
    ofstream outputfile("oddeven_file.txt");
    if (!outputfile.is_open()) {
        cout << "Khong ghi duoc file." << endl;
        return;
    }
    so_luong_chan_le(a, m, n, outputfile);
    outputfile.close();
}

void ghi_file_sort_file(int **a, int m, int n) {
    ofstream outputfile("sort_file.txt");
    if (!outputfile.is_open()) {
        cout << "Khong ghi duoc file." << endl;
        return;
    }
    sap_xep_cot_tang_dan(a, m, n, outputfile);
    outputfile.close();
}

int main() {
    int **a;
    int m, n;
    doc_file(a, m, n);
    ghi_file_square_file(a, m, n);
    ghi_file_oddeven_file(a, m, n);
    ghi_file_sort_file(a, m, n);

    // Giải phóng bộ nhớ
    for (int i = 1; i <= m; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
