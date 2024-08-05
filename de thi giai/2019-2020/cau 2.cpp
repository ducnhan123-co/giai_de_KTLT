/*Cho một chuỗi s chứa các ký tự chữ cái thường và ký tự khoảng trắng.giả sử đầu chuối và cuối chuối s khôg có khoảng trắc và giữa các từ của chuỗi s chỉ có duy nhất một khoảng trắng .Hãy viết các hàm thực hiện yêu cầu sau:
a. Đếm số lượng ký tự của mỗi từ trong chuỗi s
b. tìm một từ dài nhất chuỗi s
*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
//cau a
void dem_sokytu_moitu_trong_chuoi(const string &s)
{
       vector<int>sokytu(0);
    stringstream ss(s);
    string tu;
    while (ss>>tu)
    {
    	int len=tu.length();
    	sokytu.push_back(len);
	}
	
	for(int i=0;i<sokytu.size();i++)
	{
		cout <<sokytu[i]<<" ";
	}
}

//java was originally developed by james gosling at sun microsystems 
//cau b
void tim_tu_dainhat_trong_chuoi(const string &s)
{
       vector<string>sokytu;
    stringstream ss(s);
    string tu;
    while (ss>>tu)
    {
    	sokytu.push_back(tu);
	}
	 for (int i = 0; i < sokytu.size()-1; i++) {
        for (int j = i + 1; j < sokytu.size(); j++) 
		{
            if (sokytu[i].length() < sokytu[j].length()) {
                swap(sokytu[i], sokytu[j]);
            }
        }
    }
    cout << sokytu[0]<<endl;
}
void tim_tu_dainhat_trong_chuoi2(const string &s) {
    stringstream ss(s);
    string tu;
    string tu_dai_nhat = ""; // Biến để lưu từ dài nhất
    while (ss >> tu) {
        if (tu.length() > tu_dai_nhat.length()) {
            tu_dai_nhat = tu;
        }
    }
    cout << tu_dai_nhat << endl;
}
int main()
{
	string s;
	cout <<"Nhap vao chuoi s : ";
	getline(cin,s);
	 dem_sokytu_moitu_trong_chuoi(s);
	 cout <<endl;
	 tim_tu_dainhat_trong_chuoi(s);
	 cout <<endl;
	 tim_tu_dainhat_trong_chuoi2(s);
	return 0;
	
}