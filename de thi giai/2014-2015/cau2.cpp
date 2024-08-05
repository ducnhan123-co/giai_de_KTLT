/*câu 2 Cho một chuỗi s chứa tối đa 256 ký tự gồm chữ cái và khoảng trắng,các từ cách nhau đúng một khoảng
//trắng, đầu và cuối chuỗi s không có khoảng trắng
a) tạo chuỗi con chứa các từ thứ 2,3,4 của chuỗi s;đầu và cuối chuỗi con này không có khoảng trắng
giữa các từ có một khoảng trắng .
b)đảo ngược các từ trong chuối s,trong đó thứ tự các ký tự trong mỗi từ giữ nguyên
*/
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

//cau a
// cau a
void chuoi_con_chua_tu_234(const string &s)
{
    stringstream ss(s);
    string tu;
    int dem = 0;
    while (ss >> tu)
    {
        dem++;
        if (dem >= 2 && dem <= 4)
        {
            cout << tu << " ";
        }
        if (dem == 4) // Kết thúc vòng lặp khi đã tìm được từ thứ 4
        {
            break;
        }
    }
}

// cau b
void dao_nguoc_cac_tu(const string &s)
{
    stringstream ss(s);
    string tu;
    vector<string> cac_tu;
    while (ss >> tu)
    {
        cac_tu.push_back(tu);
    }
    for (int i = cac_tu.size() - 1; i >= 0; i--)
    {
        cout << cac_tu[i] << " ";
    }
}

int main()
{
    string s;
    cout << "Nhap vao chuoi s : ";
    getline(cin, s);
    chuoi_con_chua_tu_234(s);
    cout << endl;
    dao_nguoc_cac_tu(s);
    return 0;
}