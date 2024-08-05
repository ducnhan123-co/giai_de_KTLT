/*Cho dãy số xn được đinh nghĩa như sau :
x1=1;
xn = n + x1 + x2+ x3+....+ xn-1 với mọi số nguyên dương n>1
Hãy viết các hàm thực hiện công việc sau:
a) Tính xn bằng cách sử dụng đệ quy
b) tính xn bằng cách không sử dụng đệ quy
*/

#include<iostream>
#include<cmath>
using namespace std;

int tinh_xn_de_quy(int n)
{
	if(n==1) return 1;
	int tong = 0;
	for(int i=1;i<n;i++)
	{
		tong+=tinh_xn_de_quy(i);
	}
	return n+tong;
}
int tinh_xn_khong_de_quy(int n)
{
	if(n==1) return 1;
	int *xn=new int[n+1];
	xn[1]=1;
	for(int i=2;i<=n;i++)
	{
		int tong=0;
		for(int j=1;j<i;j++)
		{
			tong+=xn[j];
		}
		xn[i]=tong + i;
	}
	int result=xn[n];
	return result;
}
int main()
{
	int n;
	cout<<"Nhap n : ";
	cin>>n;
	
	int caua=tinh_xn_de_quy(n);
	cout<<"Xn de quy = "<< caua<<endl;
	int caub=tinh_xn_khong_de_quy(n);
	cout<<"Xn khong de quy = "<<caub<<endl;
	
}