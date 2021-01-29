#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAZE_X 20
#define MAZE_Y 20
typedef int Status;
typedef struct{
 int x;
 int y;
}PosType;//����λ��
typedef struct{
  int maze[MAZE_X][MAZE_Y];//�Թ���ͼ
  PosType size;//ʵ�ʵ��Թ�������
  PosType start;//��������
  PosType end;//�ص������
}MazeType;
typedef struct{
 int ord; //ͨ������·���ϵ���ţ�
 PosType seat;
 int di ;//ͨ����������һ��ͨ����ķ���
}SElemType;// ջ��Ԫ������
typedef struct{
  SElemType* base;
  SElemType* top;
  int stacksize;
}SqStack;
int InitStack(SqStack &s){
 //����һ����ջ
 s.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
 if(!s.base) exit(OVERFLOW);
 s.top=s.base;
 s.stacksize=STACK_INIT_SIZE;
 return OK;
}
int GetTop(SqStack s,SElemType &sElem){
    //���ջ���գ���sElem����s��ջ��Ԫ�أ�������OK
    if(s.top==s.base) return ERROR;
    sElem = *(s.top-1);
    return OK;
 
}
int Push(SqStack &s,SElemType sElem){
  //����sElemԪ��Ϊ�µ�ջ��Ԫ��
  if(s.top-s.base>=s.stacksize){
    //ջ����׷�Ӵ洢�ռ�
    s.base = (SElemType*) realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SElemType));
    if(!s.base) return OVERFLOW;
    s.top = s.base+s.stacksize;//����ʹtopָ��ջ��
    s.stacksize+=STACKINCREMENT;
  }
  *s.top=sElem;
  s.top++;
  return OK;
 
}
int Pop(SqStack &s,SElemType &sElem){
   //��ջ����
   //��ջ���գ���ɾ��ջ��Ԫ�أ�����sElem������ֵ
   //ʧ�ܷ���ERROR���ɹ�����OK
   if(s.base==s.top) return ERROR;
   sElem=*(--s.top);
   return OK;
}
int StackLength(SqStack s){//���·���1
  //����ջ��Ԫ�ظ�������ջ�ĳ���
  return s.top-s.base;
}
int StackEmpty(SqStack s){
     if(StackLength(s)==0) return TURE;
     else return FALSE;
}
int FootPrint(MazeType &m,PosType seat){//�����߹��ı��
    m.maze[seat.x][seat.y]=2;//���߹���λ�ñ��Ϊ2
    return TURE;
}
int MazeInit(MazeType &m){ // ��ʼ���Թ�
    int x,y;
    printf("�����Թ��ĳ��Ϳ�������%d���� ",MAZE_X);
    scanf("%d%d",&x,&y);//�Թ���ʵ�ʳ���
    if(x>MAZE_X||x<0||y>MAZE_Y||y<0){
        printf("x,y��Χ���Ϸ�");
        return ERROR;}
    printf("\n������%d * %d ���Թ���1����ͨ·��0����ǽ\n",x,y);
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf("%d",&m.maze[i][j]);//��ʼ���Թ�
        }
    }
    printf("\n������������꣺");
    scanf("%d%d",&(m.start.x),&(m.start.y));//�������
    printf("\n�������յ�����: ");
    scanf("%d%d",&(m.end.x),&(m.end.y));// �ص�
    m.size.x=x;m.size.y=y;
    return OK;
}
int NextPos(MazeType m,SElemType &e,SqStack &s){//���������ҷ����Ƿ�����ߣ� ������ e ������һ��ͨ��������
    //���·���1 
    //���ҷ���2 
    //���Ϸ���3
    //������4
     if(e.seat.x<MAZE_X-1&&m.maze[e.seat.x+1][e.seat.y]==1){//�������������
            (s.top-1)->di=1;//����ջ��Ԫ����һ��Ԫ�ص�λ��
            e.seat.x++;//������
            return TURE;}
     if(e.seat.y<MAZE_Y-1&&m.maze[e.seat.x][e.seat.y+1]==1){//����
            (s.top-1)->di=2;
            e.seat.y++;
            return TURE;}
     if(e.seat.x>0&&m.maze[e.seat.x-1][e.seat.y]==1){// ����
            (s.top-1)->di=3;
            e.seat.x--;
            return TURE;}
     if(e.seat.y>0&&m.maze[e.seat.x][e.seat.y-1]==1){ //����
            (s.top-1)->di=4;
            e.seat.y--;
            return TURE;}
     return FALSE; //����������㣬˵����ǰͨ������·
     }
int MazePath(MazeType &maze , SqStack &s){
    InitStack(s);//����һ����ջ
    SElemType e;
    e.seat.x = maze.start.x; //��ó�ʼ����
    e.seat.y = maze.start.y;
    e.ord=1; 
       Push(s,e);
       FootPrint(maze,e.seat);
    do{
        if(NextPos(maze,e,s)){ //��ǰ·�����Լ��������ߣ�e ������һ��·��������
            e.ord=s.top-s.base+1;//��ǰ����
            Push(s,e);// ����һ��·����Ϊ��ǰ·��
            FootPrint(maze,e.seat);//���ºۼ�
            if((e.seat.x==maze.end.x)&&(e.seat.y==maze.end.y)) return TURE;//��������յ㣬��ֹͣ
        }else{//��ǰ·�����������ߣ���·
              Pop(s,e);//����һ��
              GetTop(s,e);//�Ѻ�һ��������ǰ·��
        }
 
    }while(!StackEmpty(s)); //���ջ��Ϊ�գ�˵������ͨ��������
    return FALSE;
}
void visitmaze(MazeType m){ //�鿴�߹�����Թ�
   for(int i=0;i<m.size.x;i++){
        printf("\n");
    for(int j=0;j<m.size.y;j++){
        printf("%d ",m.maze[i][j]);
    }
   }
}
int StackTraverse(SqStack s){
  SElemType* p=s.base;
 
  for(;p<s.top;p++){
  printf("��%d�� ��ǰ����:��%d,%d) ��һ����%d \n",p->ord,(p->seat.x),(p->seat.y),p->di);
  }
 
}
int main()
{
    MazeType maze;
    SqStack s;
    MazeInit(maze);
    int i=MazePath(maze,s);
    printf("%d",i);
    visitmaze(maze);
    printf("\n");
    StackTraverse(s);
}
 
