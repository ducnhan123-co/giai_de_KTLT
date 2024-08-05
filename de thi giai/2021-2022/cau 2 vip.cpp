#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
void dem_ky_tu_khoang_trang_ky_tu_dau_dac_biet(char *s)
{
	int n=strlen(s);
	int dem_khoang_trang=0;
	int dem_ky_tu_dau=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]==' ')
		{
			dem_khoang_trang++;
		}
		else if(s[i]==',' || s[i]=='.' || s[i]==';' || s[i]=='?' || s[i]=='!' || s[i]==':')
		{
			dem_ky_tu_dau++;
		}
	}
	cout<<"Chuoi co : "<<dem_khoang_trang  <<" khoang trang va "<<dem_ky_tu_dau <<" ky tu dac biet "<<endl;
}

//conclusion: why are there so many programming languages?
void dem_so_luong_ky_tu_moi_tu(char *s, char **&tu, int &n) {
    tu = new char*[20];
    for (int i = 0; i < 20; i++) {
        tu[i] = new char[256];
    }
    
    char delim[] = " ";
    char *temp = new char[strlen(s) + 1];
    strcpy(temp, s);
    char *ptr = strtok(temp, delim);
    n = 0;
    while (ptr != NULL) {
        strcpy(tu[n], ptr);
        ptr = strtok(NULL, delim);
        n++;
    }

    // In số lượng ký tự của mỗi từ (không bao gồm các ký tự đặc biệt)
    for (int i = 0; i < n; i++) {
        int len = strlen(tu[i]);
        int count = 0;
        for (int j = 0; j < len; j++) {
            if (tu[i][j] != ',' && tu[i][j] != '.' && tu[i][j] != ';' && tu[i][j] != '?' && tu[i][j] != '!' && tu[i][j] != ':') {
                count++;
            }
        }
        cout << count << " ";
    }
    cout << endl;

 int max_length = 0;
    char longest_word[256] = {0};

    for (int i = 0; i < n; i++) {
        int len = strlen(tu[i]);
      //  int count = 0;
        char clean_word[256] = {0};
        int k = 0;

        for (int j = 0; j < len; j++) {
            if (tu[i][j] != ',' && tu[i][j] != '.' && tu[i][j] != ';' && tu[i][j] != '?' && tu[i][j] != '!' && tu[i][j] != ':') {
                clean_word[k] = tu[i][j];
                k++;
              //  count++;
            }
        }

        if (k > max_length) {
            max_length = k;
            strcpy(longest_word, clean_word);
        }
    }

    cout << "Tu dai nhat: " << longest_word << endl;

 
    // Giải phóng bộ nhớ động
    delete[] temp;
    for (int i = 0; i < 20; i++) {
        delete[] tu[i];
    }
    delete[] tu;
}
int main()
{
	char *s = new char[256];
	cout <<"Nhap chuoi s : ";
	cin.getline(s,256);
	dem_ky_tu_khoang_trang_ky_tu_dau_dac_biet(s);
	
	char **tu;
	int n=0;
	dem_so_luong_ky_tu_moi_tu(s,tu,n);
}