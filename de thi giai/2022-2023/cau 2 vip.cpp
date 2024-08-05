#include<iostream>
#include<cstring>
#include<limits.h>
using namespace std;

void dem_so_luong_ky_tu_moi_tu_va_tim_mot_tu_dai_nhat(char *s, char **&tu, int &n)
{
    tu = new char*[20];
    for(int i = 0; i < 20; i++)
    {
        tu[i] = new char[255];
    }

    char delim[] = " ";
    char *temp = new char[strlen(s) + 1];
    strcpy(temp, s);
    char *ptr = strtok(temp, delim);
    n = 0;
    while(ptr != NULL)
    {
        strcpy(tu[n], ptr);
        ptr = strtok(NULL, delim);
        n++;
    }

    if (n == 0)
    {
        cout << "Khong co tu nao trong chuoi." << endl;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        cout << strlen(tu[i]) << " ";
    }
    cout << endl;

    char longest_word[100]; // Giả sử từ dài nhất có độ dài tối đa là 99 ký tự
    longest_word[0] = '\0'; // Khởi tạo rỗng
    int max_length = 0;
    for(int i = 0; i < n; i++)
    {
        if(strlen(tu[i]) > max_length)
        {
            max_length = strlen(tu[i]);
            strcpy(longest_word, tu[i]);
        }
    }

cout << "Tu dai nhat: " << longest_word << endl;
//    for(int i = 0; i < n; i++)
//    {
//        if(strlen(tu[i]) == max_length)
//        {
//            cout << tu[i] << " ";
//        }
//    }
//    cout << endl;
}

int main()
{
    char *s = new char[255]; // Cấp phát bộ nhớ cho chuỗi s
    char **tu = nullptr; // Khởi tạo mảng tu
    int n;
    cout << "Nhap vao chuoi s: ";
    cin.getline(s, 255);

    dem_so_luong_ky_tu_moi_tu_va_tim_mot_tu_dai_nhat(s, tu, n);

    // Giải phóng bộ nhớ
    for(int i = 0; i < 20; i++)
    {
        delete[] tu[i];
    }
    delete[] tu;
    delete[] s;

    return 0;
}
