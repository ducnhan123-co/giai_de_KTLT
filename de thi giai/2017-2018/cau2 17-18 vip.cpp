/*Cau 2 Cho chuỗi s gồm các từ,mỗi từ cách nhau một khoảng trắng(giả sử đầu và cuối 
chuỗi không có khoảng trắng dư thừa).Từ có k kí tự gọi là từ loại k;k có thể là 1,2,3,4,5,6,7
Hãy tìm từ loại xuất hiện nhiều lần nhất,nếu có nhiều hơn 1 kết quả hãy xuất một kết quả đại diện
ví dụ chuỗi s là "thanh pho ho chi minh gia dinh" thì kết quả là từ loại 3
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
void tu_loai_k(char *s,char **&tu,int &n)
{
	tu=new char *[20];
	for(int i=0;i<20;i++)
	{
		tu[i]=new char[256];
	}
	char delim[]=" ";
	char *ptr=strtok(s,delim);
	n=0;
	while (ptr!=NULL)
	{
		strcpy(tu[n],ptr);
		ptr=strtok(NULL,delim);
		n++;
	}
	
	int length_count[8]={0};
	for(int i=0;i<n;i++)
	{
		int len_word=strlen(tu[i]);
		if(len_word >=1 && len_word <=7 )
		{
			length_count[len_word]++;
		}
	}
	int maxtu=0;
	int maxlength=0;
	for(int i=1;i<=7;i++)
	{
		if(length_count[i]>maxtu)
		{
			maxtu=length_count[i];
			maxlength=i;
		}
	}
	cout <<"Tu loai : "<< maxlength <<" xuat hien : "<< maxtu <<" lan ." <<endl;
	
	

	
}

int main()
{
	char *s;
	char **tu;
	s=new char[256];
	cout <<"nhap vao chuoi s : ";
	cin.getline(s,256);
	int n=0;
	tu_loai_k(s,tu,n);
	
	return 0;
}




