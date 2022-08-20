#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

string replaceSpace(string s) 
    {
        int i=0,k=0;
        string pp;
        for(i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                pp[k]='%';k++;
                pp[k]='2';k++;
                pp[k]='0';
            }
            else
            {
                pp[k]=s[i];
                k++;
            }
        }
        return pp;
    }
int main()
{
    string pp;
    pp=replaceSpace("I am human");
    cout<<pp;
    system("pause");
}