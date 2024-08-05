#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int dem_chuoi_k_ky_tu(const string &s,int k)
{
	stringstream ss(s);
	string tu;
	int dem=0;
	while (ss>>tu)
	{
		if(tu.length==4)
		{
			dem++;
		}
	}

return dem;
}

int main()
{
	string s;
	cout <<"Nhap vao chuoi s : ";
	getline(cin,s);
	int k;
	cout <<"Nhap k ky tu can dem trong chuoi s : ";
	cin>>k;
	int dem_k=dem_chuoi_k_ky_tu(s,k);
	cout <<dem_k<<endl;
	return 0;
}