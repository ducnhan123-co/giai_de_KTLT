/*Cho chuỗi s gồm các từ,giả sử s không có khoảng trắng ở đầu và cuối ;giữa các từ cũng chỉ có duy nhất một
khoảng trắng;chuỗi gồm các chữ cái,viết thường,không dấu
a) đếm xem chuỗi s có bao nhiêu từ có k ký từ với k là một số nguyên dương
b) đếm số lượng từ có k ký từ trong chuỗi với k=1....7
ví dụ s="truong dai hoc sai gon thanh pho ho chi minh"
thì kết quả là:
a)Câu a. 1 thi du với k=4
b)Cau b 0 1 6 1 1 1 0
*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
//cau a
int dem_chuoi_k_ky_tu(const string &s,int k)
{
	stringstream ss(s);
	string tu;
	int dem=0;
	while (ss>>tu)
	{
		if(tu.length()==k)
		{
			dem++;
		}
	}

return dem;
}
//cau b
void so_luong_tu_co_k_ky_tu(const string &s)
{
    stringstream ss(s);
    string tu;
    vector<int> dem(8, 0); // Tạo một vector có 8 phần tử, mỗi phần tử đại diện cho số lượng từ có từ 0 đến 7 ký tự
    while (ss >> tu)
    {
        int len = tu.length();
        if (len <= 7) // Đảm bảo chỉ đếm số lượng từ có từ 0 đến 7 ký tự
        {
            dem[len]++;
        }
    }
    for (int i = 1; i <= 7; i++) // Bắt đầu từ 1 vì từ có 0 ký tự không có ý nghĩa
    {
        cout << dem[i] << " ";
    }
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
	
	so_luong_tu_co_k_ky_tu(s);
	return 0;
}
