/*Cau 2 Cho chuỗi s gồm các từ,mỗi từ cách nhau một khoảng trắng(giả sử đầu và cuối 
chuỗi không có khoảng trắng dư thừa).Từ có k kí tự gọi là từ loại k;k có thể là 1,2,3,4,5,6,7
Hãy tìm từ loại xuất hiện nhiều lần nhất,nếu có nhiều hơn 1 kết quả hãy xuất một kết quả đại diện
ví dụ chuỗi s là "thanh pho ho chi minh gia dinh" thì kết quả là từ loại 3
*/
#include<iostream>
#include<string>
#include<sstream>
#include<limits.h>
#include<vector>
using namespace std;

void tu_loai_xuat_hien_nhieu_nhat(const string &s,int k)
{
	stringstream ss(s);
	string tu;
	int dem =0;
    vector<int>dem_tu(k+1,0);
    while (ss>>tu)
    {
    	int len=tu.length();
    	if(len<=k)
    	{
    		dem_tu[len]++;
		}
	}
	int dem_max=0;
	for(int i=0; i<=k;i++)
	{
		if(dem_tu[i]>dem_max)
		{
			dem_max=dem_tu[i];
		}
	}
	
	cout <<dem_max<<endl;



}
int main()
{
	string s;
	cout <<"Nhap vao chuoi s : ";
	getline(cin,s);
	tu_loai_xuat_hien_nhieu_nhat(s,7);
	return 0;
}