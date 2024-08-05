/*cau 3 vip hon */
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
void dem_ky_tu_moi_tu_va_tu_dai_nhat(char *s,char **&tu,int &n)
{
	tu = new char*[20];
	for(int i=0;i<20;i++)
	{
		tu[i]=new char[256];
	}
	char delim[]=" ";
	char *temp=new char[strlen(s)+1];
	strcpy(temp,s);
	n=0;
	char *ptr=strtok(temp,delim);
	while(ptr!=NULL)
	{
		strcpy(tu[n],ptr);
		ptr=strtok(NULL,delim);
		n++;
	}
	for(int i=0;i<n;i++)
	{
		cout<<strlen(tu[i])<<" ";
	}
	cout<<endl;
	char tu_dai_nhat[100];
	tu_dai_nhat[0]='\0';
	int max_length=0;
	for(int i=0;i<n;i++)
	{
		if(strlen(tu[i])>max_length)
		{
			max_length=strlen(tu[i]);
			strcpy(tu_dai_nhat,tu[i]);
		}
	}
	cout<<tu_dai_nhat<<endl;
}

int main()
{
	char *s;
	char **tu;
	s=new char[256];
	cout<<"nhap vao chuoi s : ";
	cin.getline(s,256);
	int n;
	n=0;
	dem_ky_tu_moi_tu_va_tu_dai_nhat(s,tu,n);
	
	delete []tu;
}