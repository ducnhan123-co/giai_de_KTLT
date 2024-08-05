/*Cau 4 Hãy viết chương trình hoàn chỉnh sau:
Cho dãy n số nguyên dương a1,a2,.....an 
a)đếm xem dãy a1,a2,...an chứa bao nhiêu số nguyên tố
b)hãy sắp xếp các phần tử của dãy a1,a2,......an theo thứ tự tăng dần
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void doc_file(int *&a, int &n) {
    ifstream inputfile("input.txt");
    if (!inputfile.is_open()) {
        cout << "Khong mo duoc file ";
        return;
    }
    
    inputfile >> n;
    a = new int[n];
    
    for (int i = 0; i < n; i++) {
        inputfile >> a[i];
    }
    
    inputfile.close();
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void dem_so_nguyen_to(int *a, int n, ofstream &outputfile) {
    int dem_nt = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            dem_nt++;
        }
    }
    outputfile << dem_nt << endl;
}

void sap_xep_tang_dan(int *&a, int n, ofstream &outputfile) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        outputfile << a[i] << " ";
    }
    outputfile << endl;
}

void ghi_file(int *a, int n) {
    ofstream outputfile("output.txt");
    if (!outputfile.is_open()) {
        cout << "khong ghi duoc file ";
        return;
    }
    dem_so_nguyen_to(a, n, outputfile);
    sap_xep_tang_dan(a, n, outputfile);
    outputfile.close();
}

int main() {
    int *a = nullptr;
    int n;
    
    doc_file(a, n);
    if (a != nullptr) {
        ghi_file(a, n);
        delete[] a;
    }
    return 0;
}
