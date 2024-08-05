#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

// Nhập mảng
void nhap_mang(int **&a, int &m, int &n)
{
    a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Nhap a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
}

// Xuất mảng
void xuat_mang(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Sắp xếp tăng dần theo từng cột
void sap_xep_tang_dan_theo_tung_cot(int **&a, int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m - 1; i++)
        {
            for (int k = i + 1; k < m; k++)
            {
                if (a[i][j] > a[k][j])
                {
                    swap(a[i][j], a[k][j]);
                }
            }
        }
    }
}

// Tính tổng các chữ số của một số
int tong_chu_so_1_so(int n)
{
    int tong = 0;
    while (n != 0)
    {
        tong += n % 10;
        n = n / 10;
    }
    return tong;
}

// Tạo mảng b từ mảng a
void tao_mang_b(int **a, int **&b, int m, int n)
{
    b = new int *[m];
    for (int i = 0; i < m; i++)
    {
        b[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = tong_chu_so_1_so(a[i][j]);
        }
    }
}

// Kiểm tra số nguyên tố
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Tìm số nguyên tố gần nhất
int so_nguyen_to_gan_nhat(int n)
{
    if (isPrime(n))
        return n;
    int duoi = n - 1;
    int tren = n + 1;
    while(duoi >1 && !isPrime(duoi))
    {
    	duoi--;
	}
	while(!isPrime(tren))
	{
		tren++;
	}
	if(isPrime(duoi)) return duoi;
	if(isPrime(tren)) return tren;
    
}

// Tạo mảng c từ mảng a
void tao_mang_c(int **a, int **&c, int m, int n)
{
    c = new int *[m];
    for (int i = 0; i < m; i++)
    {
        c[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = so_nguyen_to_gan_nhat(a[i][j]);
        }
    }
}

// Đếm số lượng số chẵn bao quanh aij
int dem_so_chan_xung_quanh(int **a, int m, int n, int i, int j)
{
    int dem = 0;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (x == 0 && y == 0)
                continue;
            int ni = i + x;
            int nj = j + y;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[ni][nj] % 2 == 0)
            {
                dem++;
            }
        }
    }
    return dem;
}

// Tạo mảng d từ mảng a
void tao_mang_d(int **a, int **&d, int m, int n)
{
    d = new int *[m];
    for (int i = 0; i < m; i++)
    {
        d[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = dem_so_chan_xung_quanh(a, m, n, i, j);
        }
    }
}

int main()
{
    int **a;
    int m, n;
    cout << "Nhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    
    nhap_mang(a, m, n);
    cout << "Mang a:\n";
    xuat_mang(a, m, n);
    
    sap_xep_tang_dan_theo_tung_cot(a, m, n);
    cout << "Mang a sau khi sap xep tang dan theo tung cot:\n";
    xuat_mang(a, m, n);

    int **b;
    tao_mang_b(a, b, m, n);
    cout << "Mang b (tong cac chu so):\n";
    xuat_mang(b, m, n);

    int **c;
    tao_mang_c(a, c, m, n);
    cout << "Mang c (so nguyen to gan nhat):\n";
    xuat_mang(c, m, n);

    int **d;
    tao_mang_d(a, d, m, n);
    cout << "Mang d (so luong so chan xung quanh):\n";
    xuat_mang(d, m, n);

    // Giải phóng bộ nhớ
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
        delete[] d[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;

    return 0;
}
