/*/*Cho chuỗi s gồm các từ,giả sử s không có khoảng trắng ở đầu và cuối ;giữa các từ cũng chỉ có duy nhất một
khoảng trắng;chuỗi gồm các chữ cái,viết thường,không dấu 
Viết các hàm thực hiện công việc sau
a) Đếm xem chuối  s có bao nhiêu ký tự nguyên âm ,bao nhiêu tự phụ âm ? (a i o e u là nguyên âm)
b) đếm xem chuỗi s có bao nhiêu từ
c) sắp xếp các từ chuối s theo chiều tăng dâng
ví dụ s="ky thuat lap trinh" thì kết quả câu a là 4 11 ,kết quả câu b là 4 và kết quả câu c la:"ky lap thuat trinh"
*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
//cau a
void dem_nguyen_am_phu_am(const string &s)
{
	int n=s.length();
	int demnguyenam=0;
	int demphuam=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a' || s[i]=='i' || s[i]=='o' || s[i]=='e' || s[i]=='u' )
		{
			demnguyenam++;
		}
		else if(s[i]>'a' && s[i]<'z')
		{
			demphuam++;
		}
	}
	
	cout <<demnguyenam <<" "<<demphuam<<endl;
	
}
//cau b
void dem_tu_trong_chuoi(const string &s)
{
	stringstream ss(s);
	string tu;
	int dem=0;
	while (ss>>tu)
	{
		dem++;
	}
	cout <<dem<<endl;
}

void sap_xep_tu_tang_dan(const string &s) {
    stringstream ss(s);
    string tu;
    vector<string> tu_loai; // Vector để lưu các từ
    while (ss >> tu) {
        tu_loai.push_back(tu); // Đưa từ vào vector
    }

    // Sắp xếp các từ theo độ dài của chúng bằng sắp xếp nổi bọt
    for (int i = 0; i < tu_loai.size()-1; i++) {
        for (int j = i + 1; j < tu_loai.size(); j++) {
            if (tu_loai[i].length() > tu_loai[j].length()) {
                swap(tu_loai[i], tu_loai[j]);
            }
        }
    }

    for (int i = 0; i < tu_loai.size(); i++) {
        cout << tu_loai[i] << " ";
    }
}



int main()
{
	string s;
	cout <<"Nhap vao chuoi s : ";
	getline(cin,s);
	dem_nguyen_am_phu_am(s);
	dem_tu_trong_chuoi(s);
	
	sap_xep_tu_tang_dan(s);
	return 0;


}