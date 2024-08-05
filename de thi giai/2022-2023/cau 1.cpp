/*Cho dãy số an được định nghĩa như sau:
	a0=1;
	an=1/2 * an-1 với n là số nguyên lớn hơn 0; 
	vài số hạng đầu tiên của dãy an là : 1,1/2,1/4,1/8,1/16,...
a) viết hàm đệ quy tìm số hạng thứ n của dãy số trên
b) viết hàm không đệ quy tìm số hạng thứ n của dãy số trên.
c) viết hàm tính tổng S=1 + 1/2 + 1/4 + 1/8 + 1/16 +...+1/2^n với mọi n>=0.
*/
#include<iostream>
#include<cmath>
using namespace std;

float de_quy(int n)
{
	
    if(n==0) return 1;
    return float(1.0/2)*de_quy(n-1);
}

float khu_de_quy(int n)
{
    float sohang=1;
    for(int i=0;i<n;i++)
    {
        sohang *=1.0/2;
    }
    return sohang;
}

float tong_sn(int n)
{
    if(n==0) return 1.0;
    return float(1.0/pow(2,n))+tong_sn(n-1);
}
int main()
{
    int n;
    cout<<"Nhap n : ";
    cin>>n;
    if(n<0) {
    	cout <<"Gia tri n khong hop le ."<<endl;
	}
	else 
	{
	
    float cau_a=de_quy(n);
    cout <<cau_a<<endl;
    
    float cau_b=khu_de_quy(n);
    cout <<cau_b<<endl;
    
    float cau_c=tong_sn(n);
    cout <<cau_c<<endl;
}
    
    
    return 0;
}
