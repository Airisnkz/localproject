#include <graphics.h>
#include <conio.h>
#include <Windows.h>
 
#define N 30 //确定数组的容量
 
int GameOver(int chess[N][N],int flag);
 
//游戏背景
void Background(){
	initgraph(540,540);
 
	setfillcolor(RGB(128,64,64));
	fillrectangle(0,0,800,800);
 
	//画棋盘
	setlinecolor(BLACK);
	for(int i=10;i<=530;i+=20){
		line(10,i,530,i);
		line(i,10,i,530);
	}
 
}
 
//玩游戏
void PlayGame(){
	MOUSEMSG m;
	int x,y;//用来修正棋子坐标x,y
	int chess[N][N] = {0};//用来记录棋盘坐标(一个格子为一个单位)下,每个位置的棋子情况:0位无,1为黑,2为白
 
	while(1){
		m = GetMouseMsg();
		switch(m.uMsg){
		case WM_LBUTTONDOWN://鼠标左键按下黑棋
 
			x = (m.x-10)%20;      //m.x-10是将画布坐标系转换为棋盘格子坐标系
			if(x<=10){            //用来校准棋子下的位置x
				m.x = m.x - x;
			}else{
				m.x = m.x - x + 20;
			}
 
			y = (m.y-10)%20;
			if(y<=10){            //用来校准棋子下的位置y
				m.y = m.y - y;
			}else{
				m.y = m.y - y + 20;
			}
			//画棋子
			setfillcolor(BLACK);
			setlinecolor(BLACK);
			fillcircle(m.x,m.y,10);
 
			chess[m.x/20][m.y/20] = 1;//存放棋子位置信息
 
			//判断是否胜利
			if(GameOver(chess,1))
				outtextxy(200,200,"这一局黑棋胜利!");//L是为了适应VS编译器
 
			break;
		case WM_RBUTTONDOWN:
 
				x = (m.x-10)%20;      //m.x-10是将画布坐标系转换为棋盘格子坐标系
			if(x<=10){            //用来校准棋子下的位置x
				m.x = m.x - x;
			}else{
				m.x = m.x - x + 20;
			}
 
			y = (m.y-10)%20;
			if(y<=10){            //用来校准棋子下的位置y
				m.y = m.y - y;
			}else{
				m.y = m.y - y + 20;
			}
 
			setfillcolor(WHITE);
			setlinecolor(WHITE);//目的是为了去除白棋的黑色边缘
			fillcircle(m.x,m.y,10);
 
			chess[m.x/20][m.y/20] = 2;//存放棋子位置信息
 
			if(GameOver(chess,2))
				outtextxy(200,200,"这一局白棋胜利!");
 
			break;
		}
	}
}
 
//游戏结束
int GameOver(int chess[N][N],int flag){  //chess为了共享棋盘棋子分布情况,flag标志哪个棋子
	int countCro;//用来统计行是否满足条件
	int countRaw;
	int countDia1,countDia2;//两种对角情况
 
	for(int i=0;i<=30;i++){
		for(int j=0;j<=30;j++){       //双重循环遍历棋盘每个坐标
			countCro = 0;
			countRaw = 0;
			countDia1 = 0;
			countDia2 = 0;//每更换一个位置,统计重计
			for(int count=0;count<5;count++){  //计数器用来统计这个坐标+-5范围内是否有满足条件
				if(chess[i][j+count]==flag)
					countRaw++;
				if(chess[i+count][j]==flag)
					countCro++;
				if(chess[i+count][j+count]==flag)
					countDia1++;
				if(chess[i+count][j-count]==flag)
					countDia2++;
			}
 
			if(countCro == 5||countRaw == 5||countDia1 == 5||countDia2 ==5)
				return 1;  //满足任何一种胜利条件,就返回胜利标志1;
		}
	}
	return 0;//否则返回0
}
 
int main(void){
	Background();
 
	PlayGame();
 
	
	system("pause");
	closegraph();
}