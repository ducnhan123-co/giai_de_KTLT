/*Câu 1 
Cho dãy An(n là số nguyên dương) được biểu diễn theo công thức sau:
A1=1;
A2=2;
A3=3;
An=24An-1+25An-2+10An-3+2018 mọi n>3
a)Viết hàm tính An bằng cách sử dụng đệ quy
b)Viết hàm tính An bằng cách không sử dụng đệ quy và cũng không dùng mảng
*/
#include<iostream>
#include<math.h>
using namespace std;
//cau a
int tinh_xn_de_quy(int n)
{
	if(n==1) return 1;
	if(n==2) return 2;
	if(n==3) return 3;
	
	return 24*tinh_xn_de_quy(n-1)+25*tinh_xn_de_quy(n-2)+10*tinh_xn_de_quy(n-3)+2018;
}

int tinh_xn_khong_de_quy(int n)
{
		if(n==1) return 1;
	if(n==2) return 2;
	if(n==3) return 3;
	
	int x_n_tru_3=1;
	int x_n_tru_2=2;
	int x_n_tru_1=3;
	int x_n=0;
	for(int i=4;i<=n;i++)
	{
		x_n=24*x_n_tru_1+25*x_n_tru_2+10*x_n_tru_3+2018;
		
		x_n_tru_3=x_n_tru_2;
		x_n_tru_2=x_n_tru_1;
		x_n_tru_1=x_n;
	
	}
	return x_n;
	cout<<caub<<endl;
}










	if(n==1) return 1;