#include<iostream>
#include<cstring>
#include<fstream>
#include <iomanip>
#include<cstdlib>
using namespace std;

int op[100]={0};                            //编号数组

class Book
{
    public:
    string b_name;
    string w;
    string she;
    int num;
    string d;
    string price;
    Book(){};
    void set(string a, string b, string c, int n, string p,string d)
    {
        ofstream fout("book.txt",ios_base::out|ios_base::app);
        fout << setw(7) << left<< n<<",";                           //","作为特征值
        fout << setw(8) << left<< a<<",";
        fout << setw(10) << left<< b<<",";
        fout << setw(11) << left<< c<<",";
        fout << setw(9) << left<<d<<",";
        fout << setw(9) << left<<p<<",";
        fout << endl;
        fout.close();
        b_name = a;
        w = b;
        she = c;
        num = n;
        price = p;
    }
    Book & operator = (const Book&rhs)
    {
        this->num = rhs.num;
        this->b_name = rhs.b_name;
        this->w = rhs.w;
        this->she = rhs.she;
        this->d = rhs.d;
        this->price = rhs.price;
        return *this;
    }
    void set1(int a)
    {
        num = a;
    }
    void set2(string pk)
    {
        b_name = pk;
    }
    void set3(string pk)
    {
        w = pk;
    }
    void set4(string pk)
    {
        she = pk;
    }
    void set5(string a)
    {
        d = a;
    }
    void set6(string a)
    {
        price = a;
    }
};
Book pp[100];                                        //对象数组
void dl()
{
    ofstream fout("book.txt");
    for (int k=1; k <= 100;k++)
    {
        if(pp[k].num==0)
        {
            continue;
        }
        
        fout << setw(7) << left << pp[k].num << ",";
        fout << setw(8) << left<< pp[k].b_name<<",";
        fout << setw(10) << left<< pp[k].w<<",";
        fout << setw(11) << left<< pp[k].she<<",";
        fout << setw(9) << left<<pp[k].d<<",";
        fout << setw(9) << left<<pp[k].price<<",";
        fout << endl;
        if(pp[k+1].num==0)
        {
            break;
        }
    }
    fout.close();
}
void g1()                                          //添加
{
    string b_name;
    string w;
    string she;
    int num;
    string price;
    string d;
    int k,i;
    ofstream fout("book.txt",ios_base::out|ios_base::app);
    cout << "请输入书籍信息："<<endl;
    cout << "编号：";
    cin >> k;
    for (i = 0; i <= 99;i++)
    {
        if(k==op[i])
        {
            cout << "此编号已存在" << endl
                 << "请输入其他编号：";
            cin >> k;
            op[k] = k;
            break;
        }
        else
        {
            if(i==99)
            {
                op[k] = k;
            }
            else
                continue;
        }
    }
    cout << "书名：";
    cin >> b_name;
    cout << "作者：";
    cin >> w;
    cout << "出版社：";
    cin >> she;
    cout << "出版时间：";
    cin >> d;
    cout << "价格：";
    cin >> price;
    pp[op[k]].set(b_name,w,she,op[k],price,d);
}
void g4()                                         //列表
{
    ifstream fin("book.txt", ios_base::in);
    string line;
    cout << endl;
    cout << "书籍列表："<<endl;
    cout << "num    ,name    ,writer    ,publish    ,time     ,price    ," << endl;
    while (getline (fin, line))
    { 
        cout << line << endl;
    }
    cout << endl;
}
int main();
void g3()                                           //删除
{
    int ip;
    int *ipp;
    ipp = &ip;
    int kl;
    string inFileName = "book.txt";
    ifstream infile;
    infile.open(inFileName.c_str());
    string text;
    cout << "请输入要删除的编号：";
    cin >> kl;
    op[kl] = 0;
    for (int i=1;i<=100;i++)
    {
        for (int k = 1; k <= 6;k++)
        {
            getline(infile, text, ',');
            ip = atoi(text.c_str());
            if(ip==kl)
            {
                for (int y = ip; y <= 90;y++)
                {
                    pp[y] = pp[y + 1];
                }
                dl();
                cout << "删除已完成"<<endl;
                main();
            }
            else
            {
                if(i==100)
                {
                    cout << "没有你想查找的编号";
                    break;
                }
            }
        }
    }
    cout << endl;
}
int main();
void g2() //查找
{
    int ip;
    int *ipp;
    ipp = &ip;
    int kl;
    string inFileName = "book.txt";
    ifstream infile;
    infile.open(inFileName.c_str());
    string text;
    cout << "请输入要查找的编号：";
    cin >> kl;
    for (int i=1;i<=100;i++)
    {
        for (int k = 1; k <= 6;k++)
        {
            
            getline(infile, text, ',');
            ip = atoi(text.c_str());
            if(ip==kl)
            {
                cout << "num    ,name    ,writer    ,publish    ,time     ,price    ," << endl;
                cout << setw(7) << left<< pp[ip].num<<",";                          
                cout << setw(8) << left<< pp[ip].b_name<<",";
                cout << setw(10) << left<< pp[ip].w<<",";
                cout << setw(11) << left<< pp[ip].she<<",";
                cout << setw(9) << left<<pp[ip].d<<",";
                cout << setw(9) << left<<pp[ip].price<<","<<endl;
                main();
            }
            else
            {
                if(i==100)
                {
                    cout << "没有你想查找的编号";
                    break;
                }
            }
        }
    }
    cout << endl;
}
void g5()                                        //排序
{
    int i, k;
    ofstream fout("book.txt",ios_base::out);
    for (i = 1; i <= 99;i++)
    {
        if(pp[i].num!=0)
        {
            if(pp[i].num!=pp[i-1].num)
            {
                fout << setw(7) << left<< pp[i].num<<",";
                fout << setw(8) << left<< pp[i].b_name<<",";
                fout << setw(10) << left<< pp[i].w<<",";
                fout << setw(11) << left << pp[i].she << ",";
                fout << setw(9) << left << pp[i].d << ",";
                fout << setw(9) << left << pp[i].price << ",";
                fout << endl; 
            }
            else
                continue;
        }
    }
    cout << "排序已完成" << endl;
}
int main();
void chushihua()                                //文件初始化
{
    int ip;
    int *ipp;
    ipp = &ip;
    string inFileName = "book.txt";
    ifstream infile;
    infile.open(inFileName.c_str());
    string text;
    for (int i=1;i<=100;i++)
    {
        for (int k = 1; k <= 6;k++)
        {
            if(k==1)
            {
                getline(infile, text, ',');
                
                ip = atoi(text.c_str());
                pp[atoi(text.c_str())].set1(ip);
                op[ip] = ip;
            }
            if(k==2)
            {
                getline(infile, text, ',');
                pp[ip].set2(text.c_str());
            }
            if(k==3)
            {
                getline(infile, text, ',');
                pp[ip].set3(text.c_str());
            }
            if(k==4)
            {
                getline(infile, text, ',');
                pp[ip].set4(text.c_str());
            }
            if(k==5)
            {
                getline(infile, text, ',');
                pp[ip].set5(text.c_str());
            }
            if(k==6)
            {
                getline(infile, text, ',');
                pp[ip].set6(text.c_str());
            }
        }
    }
}
int caidan()
{
    int i;
    cout << "———————————" << endl;
    cout << "1.添加书籍" << endl;
    cout << "2.查找书籍" << endl;
    cout << "3.删除书籍" << endl;
    cout << "4.书籍列表" << endl;
    cout << "5.书籍排序" << endl;
    cout << "6.退出" << endl;
    cout << "———————————" << endl;
    cout << "请选择功能：";
    cin >> i;
    switch(i)
    {
    case 1:g1();break;
    case 2:g2();break;
    case 3:g3();break;
    case 4:g4();break;
    case 5:g5();break;
    case 6:exit(0);break;
    }
    return main();
}
int main()
{
    chushihua();
    caidan();
    return 0;
}
