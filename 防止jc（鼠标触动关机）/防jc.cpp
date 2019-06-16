#include<io.h>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<algorithm>
#include<iostream>
int n,m,g[10001],z,x,y,p;
using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
struct Button{//按钮 
    int x,y,color;//按钮位置和颜色
    const char *name;//名字
    int len;//名字的长度
};
void gto(int x,int y){//将打字的光标移到x行y列
    COORD pos;pos.X=y*2;pos.Y=x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void GetPos(POINT &pt){//获得鼠标相对于屏幕的位置
    HWND hwnd=GetForegroundWindow();
    GetCursorPos(&pt);
    ScreenToClient(hwnd,&pt);
    pt.y=pt.y/16,pt.x=pt.x/16;
}
void color(int a){//修改颜色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
Button NewButton(int x,int y,int color,const char *name){//创建按钮 
    Button t;
    t.x=x,t.y=y,t.name=name;
    t.color=color;
    t.len=strlen(name);
    return t;//新建按钮，返回它
}
bool Preserve(Button A){//维护一个按钮
    gto(A.x,A.y),color(A.color),printf("%s",A.name);
    POINT pt;
    GetPos(pt);
    if(pt.y==A.x&&(pt.x>=A.y&&pt.x<=A.y+A.len/2)){
        gto(A.x,A.y),printf("%s",A.name);
        if(KEY_DOWN(MOUSE_MOVED)) return 1;//检测到点击按钮
    }
    return 0;//没有检测到
}
int main(){
	kL:
	char n;
	gto(0,0);
	system("title 机房防jc系统1.2.0 - By A_konjac");
	puts("在使用该系统前，您应当提前备份好您的数据，避免关机时丢失，准备完毕后按任意键启动"); 
	n=getche();
	system("cls");
	gto(24,0);
	cout<<"机房防jc系统1.2.0 by A_konjac"; 
	gto(0,0);
	system("cls");
	fore: 
	system("cls");
	color(7);
	cout<<"输入您进入输入密码界面的按键（请务必牢记，错误将会关机！）：";
	char ch=getche();
	system("cls");
	cout<<"您输入的是："<<ch<<",确定吗？";
	while(1){
		if(Preserve(NewButton(3,1,10,"是")))break;
  	  	if(Preserve(NewButton(6,1,12,"否")))goto fore;
	}
	color(7);
	string s;
	system("cls");
	cout<<"输入您的解锁密码，回车结束输入：";
	cin>>s;
	system("cls");
	cout<<"按回车键开始防护"; 
	n=getchar();
	Wrong:
	system("cls");
	cout<<"系统已启动！解密时请勿触动鼠标！";
	while(1){
		if(KEY_DOWN(MOUSE_MOVED))system("shutdown -s -t 0");
		if(kbhit()){
			n=getche();
			if(n==ch){
				system("cls");
				puts("输入密码,回车结束(您只有一次输入机会！)：");
				string S;
				cin>>S;
				if(S==s){
					system("cls");
					puts("密码正确！");
					system("pause");
					break;
				}
				else system("shutdown -s -t 0");;
			}
			else system("shutdown -s -t 0");
		}
	}
	goto kL;
	return 0;
}
