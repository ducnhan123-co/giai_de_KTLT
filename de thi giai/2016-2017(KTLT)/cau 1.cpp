#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
void doc_file(int *&a,int &n)
{
    ifstream inputfile("input.txt");
    if(!inputfile.is_open())
    {
        cout<<"Khong mo duoc file ."<<endl;
        return;
    }
    a=new int[n];
    inputfile>>n;
    for(int i=0;i<n;i++)
    {
        inputfile>>a[i];
    }
    inputfile.close();
}
void dem_so_chan_so_le(int *a,int n,ofstream &outputfile)
{
    int demchan=0;
    int demle=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            demchan++;
        }
        else if(a[i]%2!=0)
        {
            demle++;
        }
    }
    outputfile<<demchan<<endl;
    outputfile<<demle<<endl;
}

void ghi_file(int *&a,int &n)
{
    ofstream outputfile("output.txt");
    if(!outputfile.is_open())
    {
        cout<<"Khong ghi duoc file ."<<endl;
        return;
    }
    dem_so_chan_so_le(a,n,outputfile);
    
    
    outputfile.close();
}
int main()
{
    int *a;
    int n;
    doc_file(a,n);
    ghi_file(a,n);
}