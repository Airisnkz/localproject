#include<iostream>
#include<cstring>
#include<string>
#include<cassert>
using namespace std;
int pu;      //对象上限个数
int j;       //对象查询特征码
class Myword
{
    public:
    char *pdata;
    int length;
    Myword(){};
    set_word(char *pp,int size=0)                                  //构造
    {
        pu++;
        length=size;
        pdata=new char[length+1];
        strcpy(pdata,pp);
        assert(pdata!=NULL);
        pdata[length+1]='\0';
        return 0;
    }
    ~Myword()                                                        //析构
    {
        if(pdata!=NULL)
        {
            pdata=NULL;
        }
    }
    Myword(const Myword&sb)                                              //深复制
    {
        pdata=new char[sb.length+1];
        strcpy(pdata,sb.pdata);
        length=sb.length;
    }
    Myword & operator=(const Myword&rhs)                               //深赋值
    {
        if(this!=&rhs)
        {
            this->pdata=rhs.pdata;
        }
        return *this;
    }
    void change(char *pp,int size=0)
    {
        strcpy(pdata,pp);
    }
    char* getdata()
    {
        cout<<pdata<<endl;
        return pdata;
    }
};
Myword a[100];                                                       //全局对象数组
Myword fuzhi(Myword x)                                               //复制
{
    Myword y;
    y.pdata=x.pdata;
    return y;
}
istream & operator >> (istream & is,const Myword&rhs)                    //流插入
{
    is>>rhs.pdata;
    return is;
}
ostream& operator << (ostream &os,const Myword&rhs)                        //流提取
{
    os<<rhs.pdata;
    return os;
}
Myword operator+(Myword &a,Myword &b)                                  //加法重载
{
    Myword temp;
    temp.length=a.length+b.length;
    temp.pdata=new char [temp.length+1];
    strcpy(temp.pdata,a.pdata);
    strcat(temp.pdata,b.pdata);
    temp.pdata[temp.length+1]='\0';
    return temp;
}
void out_put()                                                       //输出现有对象
{ 
    int i;
    for(i=0;i<=pu;i++)
    {
        cout<<"a["<<i<<"]"<<"="<<a[i].pdata<<endl;
    }
}
int tihuan()                                                            //替换
{
    string x;
    int k;
    k=j;
    cout<<"请输入替换的单词：";
    cin>>x;
    a[k].change(&x[0],strlen(x.c_str()));
    cout<<"已修改该单词"<<endl;
    cout<<"a["<<k<<"]"<<":"<<a[k].pdata<<endl;
    return 0;
}
void xiugai()                                                          //修改对象数据成员
{
    int oh;
    cout<<"是否要修改该单词？"<<endl;
    cout<<"1.是  2.否"<<endl;
    cin>>oh;
    switch(oh)
    {
        case 1:tihuan();break;
        case 2:break;
    }
}
void search(char *pp,int size)                                        //查找
{
    for(j=0;j<100;j++)
    {
        if(strcmp(a[j].pdata,pp)==0)
        {
            cout<<"已找到该单词，位于对象a["<<j<<"]"<<endl<<endl;
            xiugai();break;
        }
        else
        {
            if(j==pu)
            {
                cout<<"未查询到该对象"<<endl;break;
            }
            else continue;
        }
    }
}




if(f!=(n-1))
            {
                if()
                {
                    continue;
                }
            }
int main()
{   
    string x;
    string se;
    int p,q,oh;
    cout<<"请输入单词：";
    cin>>x;
    p=strlen(x.c_str());
    a[0].set_word(&x[0],p);
    a[1].set_word(&x[0],p);
    cin>>a[1];
    ////////////////////////加法重载测试案例
    a[2]=a[0]+a[1];    
    ////////////////////////查找，替换测试案例                                         
    out_put();
    cout<<"请输入要查找的单词：";
    cin>>se;
    search(&se[0],strlen(se.c_str()));
    ////////////////////////输出现有对象
    cout<<"现有对象为："<<endl;
    out_put();
    return 0;
}




