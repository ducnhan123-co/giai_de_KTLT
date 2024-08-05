#include<iostream>
#include<cmath>
using namespace std;
void nhap_mang(int **&a,int &m,int &n)
{
    a=new int*[m];
    for(int i=0;i<m;i++)
    {
        a[i]=new int[n];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout <<"Nhap a["<<i<<"]["<<j<<"]= ";
            cin>>a[i][j];
        }
    }
    
}
void xuat_mang(int **a,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout <<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int tong_cac_so_le_tren_dong_k(int **a,int m,int n,int dong)
{
    int tong=0;
    for(int j=0;j<n;j++)
    {
        if(a[dong][j]%2!=0)
        {
             tong+=a[dong][j];
        }
       
    }
    return tong;
}


int main()
{
    int **a;
    int m,n;
    cout <<"Nhap dong m :";
    cin>>m;
    cout <<"Nhap cot n : ";
    cin>>n;
    nhap_mang(a,m,n);
    xuat_mang(a,m,n);
    int tongle=tong_cac_so_le_tren_dong_k(a,m,n,1);
    cout <<tongle<<endl;
}