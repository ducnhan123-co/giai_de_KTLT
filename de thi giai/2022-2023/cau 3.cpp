/*Cho file văn bản input.txt có cấu trúc như sau: dòng đầu ghi số nguyên dương n;trong n dòng tiếp theo mỗi dòng ghi n số :0 hoặc 1.
Hãy viết chương trình đọc file văn bản input.txt ra mảng 2 chiều a tương ứng có n dòng,n cột;
trong đó vị trí dòng, vị trí cột bắt đầu từ 1.Đường chéo chính của mảng bắt đầu từ góc trên trái
xuống góc dưới phải;tức các phần tử thuộc đường chéo chính có chỉ số dòng bằng chỉ số cột;giả thiết rằng các phần tử thuộc đường chéo chính đều có giá trị bằng 0.
a) tính tổng các phần tử trên từng dòng của mảng a
b) kiểm tra xem tất cả các phần tử của mảng a có đối xứng với nhau qua đường chéo chính hay không ? nếu có giá trị trả về giá trị 1;nếu không trả về giá trị 0
c) sắp xếp các chỉ số dòng của mảng a theo thứ tự tổng các phần tử trên đó giảm dần
vis du
input.txt
6
0 1 1 1 0 0
1 0 1 0 1 0
1 1 0 1 0 1
1 0 1 0 0 1
0 1 0 0 0 1
0 0 1 1 1 0

output.txt
kết quả câu a : 3 3 4 3 2 3
kết quả câu b: 1
kết quả câu c : 3 1 2 4 6 5
*/
#include<iostream>
#include<fstream>
using namespace std;

void doc_file(int **&a,int &n )
{
	ifstream inputfile("input.txt");
	
		if(!inputfile.is_open())
		{
			cout <<"Khong mo duoc file" <<endl;
			return;
		}
     inputfile >> n;
	a=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			inputfile >>a[i][j];
		}
	}
	
	inputfile.close();
}
void tong_phan_tung_dong(int **a,int n,ofstream &outputfile)
{
	for(int i=0;i<n;i++)
	{
		int tong_dong=0;
		for(int j=0;j<n;j++)
		{
			tong_dong +=a[i][j];
			}	
	outputfile << tong_dong <<" ";
	}
}
int kiem_tra_doi_xung(int **&a, int &n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j =0; j < n; j++) 
        {
            if(a[i][j] != a[j][i])
            {
                return -1; // Không đối xứng
            }
        }
    }
    return 1; // Đối xứng
}
// sắp xếp các chỉ số dòng của mảng a theo thứ tự tổng các phần tử trên đó giảm dần
void sap_xep_chi_so_dong_theo_tong_giam_dan(int **&a, int &n,ofstream &outputfile)
{
    // Mảng để lưu trữ tổng các phần tử trên mỗi dòng và chỉ số dòng
    int* tong_ptu = new int[n];
    int* chi_so_dong = new int[n];

    // Tính tổng các phần tử trên mỗi dòng và lưu chỉ số dòng
    for (int i = 0; i < n; i++)
    {
        int tong_dong = 0;
        for (int j = 0; j < n; j++)
        {
            tong_dong += a[i][j];
        }
        tong_ptu[i] = tong_dong;
        chi_so_dong[i] = i;
    }

    // Sắp xếp các chỉ số dòng dựa trên tổng các phần tử giảm dần bằng bubble sort
      for (int i = 0; i < n - 1; i++)
    {
        for (int j = n-1; j >i; j--)
        {
            if (tong_ptu[j] > tong_ptu[j - 1])
            {
                swap(tong_ptu[j], tong_ptu[j - 1]);
                swap(chi_so_dong[j], chi_so_dong[j - 1]);
            }
        }
    }

    
    for (int i = 0; i < n; i++)
    {
        outputfile<< chi_so_dong[i]+1 << " ";
    }

    // Giải phóng bộ nhớ cho các mảng động
    delete[] tong_ptu;
    delete[] chi_so_dong;
}
void ghi_file(int **&a,int &n)
{
	ofstream outputfile("output.txt");
	if(!outputfile.is_open())
	{
		cout <<"Khong ghi duoc file "<<endl;
	}
	tong_phan_tung_dong(a,n,outputfile);
	outputfile <<endl;
	int check=kiem_tra_doi_xung(a,n);
	if(check==1)
	{
		outputfile << "1"<<endl;
	}
	else {
		outputfile <<"Khong phai chuoi doi xung"<<endl;
	}
	
	sap_xep_chi_so_dong_theo_tong_giam_dan(a,n,outputfile);
	
}

int main()
{
	int **a;
	int n;

	doc_file(a,n);
	
	ghi_file(a,n);
		return 0;
	
}