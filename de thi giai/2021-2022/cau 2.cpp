/*Cho chuỗi s chứa các ký tự chữ cái (chữ cái viết hoa,viết thường),ký tự khoảng trắng và các ký tự dấu; mỗi từ của chuối s(chỉ) gồm các chữ cái được viết liên tiếp nhau; số lượng ký tự của mỗi từ được gọi là chiều dài của từ đó
Giả thiết rằng:ký tự dấu chỉ đề cập đến các loại dấu sau:dấu phẩy,dấu châm,dấu hỏi,dấu chấm than,dấu hai chấm,dấu chấm phẩy trước các dấu trong chuỗi s không có ký tự khoảng trắng Đầu chuỗi s,cuối chuỗi s không có ký tự khoảng trắng;giữa các từ chuỗi s có đúng 1 ký tự khoảng trắng .
a) đếm xem chuối s có bao nhiêu ký tự khoảng trắng ? đếm xem chuối s có bao nhiêu ký tự đầu theo giả thiết trên
b) đếm số lượng ký tự của mỗi từ trong chuối s
c) tìm một từ dài nhất chuỗi s 
ví dụ chuối s: "conclusion: why are there so many programming languages?"
  kết quả câu a:7 2 
  kết quả câu b: 10 3 3 5 2 4 11 9
  kết quả câu c:programming
  */
  
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

// Đếm số ký tự khoảng trắng và ký tự dấu
void dem_ky_tu_khoang_trang(const string &s) {
    int dem_khoang_trang = 0;
    int dem_dau = 0;
    for (char c : s) {
        if (c == ' ') {
            dem_khoang_trang++;
        } else if (c == ',' || c == '.' || c == '?' || c == '!' || c == ':' || c == ';') {
            dem_dau++;
        }
    }
    cout << dem_khoang_trang << " " << dem_dau << endl;
}

// Đếm số lượng ký tự của mỗi từ trong chuỗi
void dem_so_luong_ky_tu_moi_tu(const string &s) {
    stringstream ss(s);
    string tu;
    while (ss >> tu) {
    	 char last_char = tu.back();
        if (last_char == ',' || last_char == '.' || last_char == '?' || last_char == '!' || last_char == ':' || last_char == ';') {
            tu.pop_back();
        }
        cout << tu.length() << " ";
    }
    cout << endl;
}

// Tìm từ dài nhất trong chuỗi
void tu_dai_nhat(const string &s) {
    stringstream ss(s);
    string tu;
    string tu_dai_nhat;
    int do_dai_max = 0;
    while (ss >> tu) {
        // Kiểm tra ký tự dấu cuối cùng của từ
        char last_char = tu.back();
        if (last_char == ',' || last_char == '.' || last_char == '?' || last_char == '!' || last_char == ':' || last_char == ';') {
            tu.pop_back();
        }
        if (tu.length() > do_dai_max) {
            do_dai_max = tu.length();
            tu_dai_nhat = tu;
        }
    }
    cout << tu_dai_nhat << endl;
}

int main() {
    string s;
    cout << "Nhap vao chuoi s: ";
    getline(cin, s);
    if (s.empty()) {
        cout << "Chuoi nhap vao rong." << endl;
        return 1;
    }
    cout << "Ket qua cau a: ";
    dem_ky_tu_khoang_trang(s);
    cout << "Ket qua cau b: ";
    dem_so_luong_ky_tu_moi_tu(s);
    cout << "Ket qua cau c: ";
    tu_dai_nhat(s);
    return 0;
}
