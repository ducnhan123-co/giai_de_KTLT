/*Câu 4
CHo file văn bản input.txt,mỗi dòng của file chứa một chuỗi;chiều dài tối đa của mỗi chuỗi là 512 ký tự.Hãy viết chương trình tìm một từ bên trái của mỗi chuỗi trong file văn bản input.txt
ghi các chuỗi tìm được vào file văn bản output.txt;mỗi dòng ghi một chuỗi.
ví dụ:
Alesandr Sergeyevich Pushkin
Lev Nikolayevich Tolstoy
Charles John Huffam Dickens
William Shakespeare

output.txt
Alesandr
Lev
Charles
William

*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void doc_file (char *s)
{
	ifstream inputfile ("input.txt");
	if(!inputfile.is_open())
	{
		cout <<"Khong mo duoc file";
	}
	
	char *line=new char[256];
	while (inputfile.getline(line,256))
	{
		strcat(s,line);
		strcat(s,"\n");
	}
	inputfile.close();
	delete [] line;
}
void tach_1_tu_ben_trai(char *s,ofstream &outputfile)
{
    char *spacesos=strchr(s,' ');
    if(spacesos==NULL)
    {
        return;
    }
    int len = spacesos-s;
    char *tu_trai= new char[len+1];
    strncpy(tu_trai,s,len);
    tu_trai[len]='\0';
    
    outputfile << tu_trai <<endl;
    delete []tu_trai;
}

void ghi_file(char *s)
{
	ofstream outputfile ("output.txt");
	if(!outputfile.is_open())
	{
		cout <<"Khong ghi duoc file ";
		
	}
	outputfile << s;
	//tao mot copy
    char *copy = new char[strlen(s) + 1];
    strcpy(copy, s);

    char *line = strtok(copy, "\n");
    while (line != NULL)
    {
        tach_1_tu_ben_trai(line, outputfile);
        line = strtok(NULL, "\n");
    }

    delete[] copy;
	
//	outputfile << s;
	
	outputfile.close();
	
}
int main()
{
	char *s;
	s=new char[256];
	doc_file(s);
	ghi_file(s);
	return 0;
}