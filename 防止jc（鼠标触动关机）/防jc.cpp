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
struct Button{//��ť 
    int x,y,color;//��ťλ�ú���ɫ
    const char *name;//����
    int len;//���ֵĳ���
};
void gto(int x,int y){//�����ֵĹ���Ƶ�x��y��
    COORD pos;pos.X=y*2;pos.Y=x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void GetPos(POINT &pt){//�������������Ļ��λ��
    HWND hwnd=GetForegroundWindow();
    GetCursorPos(&pt);
    ScreenToClient(hwnd,&pt);
    pt.y=pt.y/16,pt.x=pt.x/16;
}
void color(int a){//�޸���ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
Button NewButton(int x,int y,int color,const char *name){//������ť 
    Button t;
    t.x=x,t.y=y,t.name=name;
    t.color=color;
    t.len=strlen(name);
    return t;//�½���ť��������
}
bool Preserve(Button A){//ά��һ����ť
    gto(A.x,A.y),color(A.color),printf("%s",A.name);
    POINT pt;
    GetPos(pt);
    if(pt.y==A.x&&(pt.x>=A.y&&pt.x<=A.y+A.len/2)){
        gto(A.x,A.y),printf("%s",A.name);
        if(KEY_DOWN(MOUSE_MOVED)) return 1;//��⵽�����ť
    }
    return 0;//û�м�⵽
}
int main(){
	kL:
	char n;
	gto(0,0);
	system("title ������jcϵͳ1.2.0 - By A_konjac");
	puts("��ʹ�ø�ϵͳǰ����Ӧ����ǰ���ݺ��������ݣ�����ػ�ʱ��ʧ��׼����Ϻ����������"); 
	n=getche();
	system("cls");
	gto(24,0);
	cout<<"������jcϵͳ1.2.0 by A_konjac"; 
	gto(0,0);
	system("cls");
	fore: 
	system("cls");
	color(7);
	cout<<"���������������������İ�����������μǣ����󽫻�ػ�������";
	char ch=getche();
	system("cls");
	cout<<"��������ǣ�"<<ch<<",ȷ����";
	while(1){
		if(Preserve(NewButton(3,1,10,"��")))break;
  	  	if(Preserve(NewButton(6,1,12,"��")))goto fore;
	}
	color(7);
	string s;
	system("cls");
	cout<<"�������Ľ������룬�س��������룺";
	cin>>s;
	system("cls");
	cout<<"���س�����ʼ����"; 
	n=getchar();
	Wrong:
	system("cls");
	cout<<"ϵͳ������������ʱ���𴥶���꣡";
	while(1){
		if(KEY_DOWN(MOUSE_MOVED))system("shutdown -s -t 0");
		if(kbhit()){
			n=getche();
			if(n==ch){
				system("cls");
				puts("��������,�س�����(��ֻ��һ��������ᣡ)��");
				string S;
				cin>>S;
				if(S==s){
					system("cls");
					puts("������ȷ��");
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
