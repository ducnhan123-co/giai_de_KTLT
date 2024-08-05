#include<iostream>
#include<fstream>
#include<cmath>
#include<limits.h>
using namespace std;
void doc_file(int *&a,int &n)
{
    ifstream inputfile("input.txt");
    if(!inputfile.is_open())
    {
        cout<<"Khong mo duoc file "<<endl;
        return;
    }
    a=new int[n];
    inputfile>>n;
    for(int i=0;i<n;i++)
    {
        inputfile>>a[i];
    }
    inputfile.close();
}
void tim_gia_tri_lon_nhat_lon_nhi(int *a, int n, ofstream &outputfile) {
    int max1 = INT_MIN, max2 = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2 && a[i] < max1) {
            max2 = a[i];
        }
    }
    
    // Kiểm tra xem có ít nhất hai phần tử khác nhau hay không
    if (max2 == INT_MIN) {
        outputfile << "Khong co gia tri lon nhi" << endl;
    } else {
        outputfile << max1 <<" "<<max2<<endl;
    }
}
bool isPrime(int n)
{
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
bool isPrimePalindrome(int n) {
    if (n <= 2) return false;
    if (!isPrime(n)) return false;

    int truoc = n - 1;
    int sau = n + 1;

    // Tìm số nguyên tố liền trước
    while (truoc > 1 && !isPrime(truoc)) {
        truoc--;
    }

    // Tìm số nguyên tố liền sau
    while (!isPrime(sau)) {
        sau++;
    }

    // Kiểm tra nếu n là trung bình cộng của hai số nguyên tố liền trước và liền sau
    if ((truoc + sau) / 2 == n) {
        return true;
    }

    return false;
}
void dem_so_luong_nguyen_to_doi_xung(int *a,int n,ofstream &outputfile)
{
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if(isPrimePalindrome(a[i]))
        {
            dem++;
           
        }
    }
    outputfile<<dem;
}
void ghi_file(int *&a,int &n)
{
    ofstream outputfile("output.txt");
    if(!outputfile.is_open())
    {
        cout<<"Khong ghi duoc file "<<endl;
        return;
    }
    tim_gia_tri_lon_nhat_lon_nhi(a,n,outputfile);
    
    dem_so_luong_nguyen_to_doi_xung(a,n,outputfile);
    
    outputfile.close();
}
int main()
{
    int *a;
    int n;
    doc_file(a,n);
    ghi_file(a,n);
}