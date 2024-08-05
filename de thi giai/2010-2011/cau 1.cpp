//Câu 1 2010-2011
/* Với mỗi n>=1,dãy số xn được tính như sau:
x1=1,x2=1
xn=xn-1+(n-1)xn-2+2011 với n>=3
a) Viết hàm tính xn bằng phương pháp đệ quy
b) viết hàm tính xn không dùng đệ quy cũng không dùng biết mảng để lưu giá trị tạm
*/
#include<iostream>
#include<math.h>
using namespace std;
//cau a
int tinh_xn_de_quy(int n)
{
	if(n==1) return 1;
	if(n==2) return 1;
	s
	return tinh_xn_de_quy(n-1)+(n-1)*tinh_xn_de_quy(n-2)+2011;
	
}
//cau b
int tinh_xn_khong_de_quy(int n)
{
	if(n==1) return 1;
	if(n==2) return 1;
	int x_n_tru_1=1;
	int x_n_tru_2=1;
	int x_n=0;
	for(int i=3;i<=n;i++)
	{
		x_n=x_n_tru_1+(i-1)*x_n_tru_2 + 2011;
		x_n_tru_2=x_n_tru_1;
		x_n_tru_1=x_n;
		
	}
	
	return x_n;
	
	
	
}

int main()
{
	int n;
	cin>>n;
	
	int caua=tinh_xn_de_quy(n);
	cout<<caua<<endl;
	
	int caub=tinh_xn_khong_de_quy(n);
	cout<<caub<<endl;
}