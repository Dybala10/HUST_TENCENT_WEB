#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW 0
struct LNode
{
    int data;
    struct LNode * next;
};
typedef struct LNode LNode;
typedef struct LNode * LinkList;
void InitList(LinkList *L)
{
    *L = (LinkList*)malloc(sizeof(struct LNode));
    (*L)->next=NULL;

}
int InsertList(LinkList * L,int j,int num)  //�ڵ�j���ڵ�ǰ�����µĽڵ㣬����Ϊdata
{
    int i;
    LinkList * s = L;
    LinkList tmp;
    for( i = 1;i<j;i++)  // ���ڵڶ����ڵ�ǰ���������ǲ���ı�sָ��
    {
        *s = (*s)->next;
    }
    if(j<i || !(*s) )   //������ͷ�ڵ�ǰ����ڵ���s����Ϊ��ָ��
    {
        printf("error");
        return 0;
    }
    else{
        tmp=(LinkList)malloc(sizeof(struct LNode));
        tmp->next = *s;
        tmp->data = num;
        *s = tmp;
        return 0;
    }
}
int DeleteList(LinkList * L,int j,int * num) //ɾ����j���ڵ�
{
    int i;
    LinkList * s = L;
    LinkList tmp;
    for(i = 1;i<j;i++)
    {
        *s = (*s)->next;
    }
    if(j<i || !(*s)->next)
    {
        printf("error");
        return 0;
    }
    else{
        tmp->next = (*s)->next;
        *num = (*s)->data;
        *s = tmp->next;
        free(tmp);
        return 0;
    }
}
int ResearchList(LinkList * L,int j,int * num)
{
    int i;
    LinkList * s = L;
    for(i = 1;i<j;i++)
        *s = (*s)->next;
    if(j<i || !(*s)->data)
    {
        printf("error");
        return 0;
    }
    else{
        *num = (*s)->data;
        return 0;
    }
}
int main(void)
{
    int length;
    LinkList S;
    InitList(&S);
    printf("����һ������,���򽫴���һ������Ϊ������ֵ�����\n�������а�˳�򴢴���Ȼ��");
    printf("Ȼ������Ļ�ϴ�ӡ������������\n");
    scanf("%d",&length);
    for(int i=length;i>0;i--)
    {
        InsertList(&S,1,i);
    }
    LinkList tmp = S;
    for(int i = 0;i<length;i++)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n�����������ֱ���Ϊ���������λ�ú�����\n"
           "֮������ٴδ�ӡ�������\n");
    int num,e;
    scanf("%d %d",&num,&e);
    InsertList(&S,num,e);
    printf("%d",S->data);
    tmp = S;
    for(int i = 0;i<length+1;i++)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n����һ�����֣�����ɾ�����λ�ò���ӡ��λ�õ�����\n");
    scanf("%d",&num);
    int * w;
    DeleteList(&S,num,w);
    printf("%d\n",*w);
    printf("����һ������,���򽫲��Ҹ�λ�����ݲ���ӡ");
    scanf("%d",&num);
    ResearchList(&S,num,w);
    printf("%d",*w);

    return 0;
}

