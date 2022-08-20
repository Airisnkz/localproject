#include <iostream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;

class Student
{
public:
    string number;
    string name;
    double score;
    friend Student Sort(Student *s);
};

Student Sort(Student *s)
{
    for (int i=0; i <2; i++)
    {
        for (int j = 1; j < 3 ; j++)
        {
            if (s[i].score < s[j].score)
            {
                Student temp;
                temp.score = s[j].score;
                s[j].score = s[i].score;
                s[i].score = temp.score;

                temp.name = s[j].name;
                s[j].name = s[i].name;
                s[i].name = temp.name;

                temp.number = s[j].number;
                s[j].number = s[i].number;
                s[i].number = temp.number;
            }
        }
    }
    return *s;
}

int main()
{
    ifstream fin("D:/data.txt",ios_base::in);
    ofstream fout("D:/data.txt");
    char c;
    string xx;
    int n = 0;
    Student* s = new Student[3];
    for (int i = 0; i < 3; i++) 
    {
        for(int j=0;j<3;j++)
        {
            if(j==0)
            {
                getline(fin, xx);
                xx = s[i].name;
            }
            if(j==1)
            {
                getline(fin, xx);
                xx=s[i].number;
            }
            if(j==2)
            {
                getline(fin, xx);
                xx=s[i].score;
            }
        }  
    }
    for (int i = 0; i < 3; i++)
    {
        cout << s[i].name <<" " << s[i].number<<" " << s[i].score<<endl;
    }
    Sort(s);
    ofstream data1("D:/data1.txt");
    for (int i = 0; i < 3; i++)
    {
        data1 << s[i].name <<" " << s[i].number<<" " << s[i].score<<endl;
    }
    fin.close();
    dose(ata1.cl);
    return 0;
}