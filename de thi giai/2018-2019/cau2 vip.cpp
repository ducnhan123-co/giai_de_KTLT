/*/*Cho chuỗi s gồm các từ,giả sử s không có khoảng trắng ở đầu và cuối ;giữa các từ cũng chỉ có duy nhất một
khoảng trắng;chuỗi gồm các chữ cái,viết thường,không dấu 
Viết các hàm thực hiện công việc sau
a) Đếm xem chuối  s có bao nhiêu ký tự nguyên âm ,bao nhiêu tự phụ âm ? (a i o e u là nguyên âm)
b) đếm xem chuỗi s có bao nhiêu từ
c) sắp xếp các từ chuối s theo chiều tăng dâng
ví dụ s="ky thuat lap trinh" thì kết quả câu a là 4 11 ,kết quả câu b là 4 và kết quả câu c la:"ky lap thuat trinh"
*/
#include<iostream>
#include<cstring>
using namespace std;
void dem_nguyen_am_phu_am(char *s)
{
	int n=strlen(s);
	int dem_nguyen_am=0;
	int dem_phu_am=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a' || s[i]=='i' || s[i]=='o' || s[i]=='e' || s[i]=='u')
		{
			dem_nguyen_am++;
		}
		else if(s[i]>'a' && s[i]<'z')
		{
			dem_phu_am++;
		}
	}
	cout <<"Chuoi co : "<<dem_nguyen_am <<" nguyen am va "<< dem_phu_am <<" phu am "<<endl;
}
void dem_chuoi_co_bao_nhieu_tu_va_sap_xep_theo_tang_dan(char *s,char **&tu,int &n)
{
	tu=new char *[20];
	for(int i=0;i<20;i++)
	{
		tu[i]=new char[256];
	}
	char delim[]=" ";
	char *temp=new char[strlen(s)+1];
	strcpy(temp,s);
	char *ptr=strtok(temp,delim);
	n=0;
	while(ptr!=NULL)
	{
		strcpy(tu[n],ptr);
		n++;
		ptr=strtok(NULL,delim);
	}
	cout <<n<<endl;
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(strcmp(tu[j-1],tu[j])>0)
			{
				char *temp=tu[j-1];
				tu[j-1]=tu[j];
				tu[j]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout <<tu[i]<<" ";
	}
	cout <<endl;
}

int main()
{
	char *s;
	s=new char[256];
	cout <<"Nhap chuoi s: ";
	cin.getline(s,256);
	dem_nguyen_am_phu_am(s);
	char **tu;
	int n=0;
	dem_chuoi_co_bao_nhieu_tu_va_sap_xep_theo_tang_dan(s,tu,n);
}