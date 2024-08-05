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
#include<cstring>
#include<cmath>
#include<limits.h>
using namespace std;
void dem_chuoi_s_co_bao_nhieu_tu_co_ky_ky_tu(char *s, int k) {
    int n = strlen(s);
    int demkytu = 0;
    int dem = 0;

    for (int i = 0; i <= n; i++) {
        if (s[i] != ' ' && s[i] != '\0') 
		{
            demkytu++;
        }
		 else 
		 {
            if (demkytu == k) 
			{
                dem++;
            }
            demkytu = 0; // Đặt lại đếm ký tự sau khi gặp dấu cách hoặc kết thúc chuỗi
        }
    }

    // Kiểm tra từ cuối cùng nếu chuỗi không kết thúc bằng dấu cách
    if (demkytu == k)
	 {
        dem++;
    }

    cout << dem << endl;
}

void dem_so_luong_tu_co_k_ky_tu(char *s)
{
	int n=strlen(s);
	int demkytu=0;
	int count_length[8]={0};
	for(int i=0;i<=n;i++)
	{
		if(s[i]!=' ' && s[i]!='\0')
		{
			demkytu++;
		}
		else
		{
			if(demkytu>=1 && demkytu<=7)
			{
				count_length[demkytu]++;
			}
			demkytu=0;
		}
	}
	if(demkytu>=1 && demkytu <=7)
	{
		count_length[demkytu]++;
	}
	for(int i=1;i<=7;i++)
	{
		cout <<count_length[i]<<" ";
	}
	cout<<endl;
}


	
	

int main()
{
	char *s;
	s=new char[256];
	cout <<"Nhap s : ";
	cin.getline(s,256);
	int k;
	cout <<"nhap k ky tu can dem : ";
	cin>>k;
	dem_chuoi_s_co_bao_nhieu_tu_co_ky_ky_tu(s,k);

	dem_so_luong_tu_co_k_ky_tu(s);
}
