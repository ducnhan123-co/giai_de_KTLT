/*Cho tập tin mang input.txt chứa các số nguyên mỗi số cách nhau ít nhất một khoảng trắng, Hãy viết chương trình 
đọc các số nguyên trong mảng, sau đó sắp xếp theo thứ tự tăng dần và lưu vạo tập ttin mảng output.txt*/
#include<iostream>
#include<fstream>
#include<cmath>
#define MAX 100
using namespace std;
void doc_file(int *&a,int &n)
{
    ifstream inputfile ("input.txt");
    if(!inputfile.is_open())
    {
        cout<<"Khong mo duoc file ";
        return ;
    }
    a=new int [MAX];
    n=0;
    while (!inputfile.eof() && n<MAX)
    {
        inputfile>>a[n];
        n++;
    }
    inputfile.close();
}
void sap_xep_tang_dan(int *&a,int &n,ofstream &outputfile)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        outputfile<<a[i]<<" ";
    }
}
void ghi_file(int *&a,int &n)
{
    ofstream outputfile("output.txt");
    if(!outputfile.is_open())
    {
        cout<<"Khong mo duoc file ";
        return ;
    }
    sap_xep_tang_dan(a,n,outputfile);
}
int main()
{
    int *a;
    int n;
    doc_file(a,n);
    ghi_file(a,n);
    return 0;
}