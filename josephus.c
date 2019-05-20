#include<stdio.h>
#include<stdlib.h>
//循环队列
//typedef int ElemType;
typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
}QueueNode;
typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
}Queue;

void InitQueue(Queue *q)
{
    q->front=q->rear=NULL;
}

void EnQueue(Queue *q , int value)
{
    QueueNode *temp=(QueueNode*)malloc(sizeof(QueueNode));
    temp->data=value;
    if(q->rear==NULL)
    {
        temp->next=temp;
        q->rear=q->front=temp;
    }
    else
    {
        temp->next=q->rear->next;
        q->rear->next=temp;
        q->rear=temp;
    }
}//enter a element from the tail

void DeQueue(Queue *q, int *value)
{
    QueueNode *temp=(QueueNode*)malloc(sizeof(QueueNode));

    if(q->rear==NULL)
    {
        return;
    }// It's null
    else  if(q->rear->next==q->rear)
    {
        *value=q->front->data;
        free(q->rear);
        q->rear=q->front=NULL;
    }//It just has one node
    else
    {
        *value=q->front->data;
        temp=q->front;
        q->front=temp->next;
        q->rear->next=q->front;        
    }//more one node
    free(temp);
}//delete a element from the head

int main()
{
    Queue *q=(Queue*)malloc(sizeof(Queue));
    int i,m,n,s,count,temp;
    printf("请输入人数n、s和循环要报的数m（两数之间留个空格）\n");
    scanf("%d%d%d",&n,&s,&m);
    for(i=1;i<=n;i++)
        EnQueue(q,i);
    printf("出圈序列：\n");
    while(q->front)
    {    count=s;
        while(count<m)
        {
            q->front=q->front->next;
            q->rear=q->rear->next;
            count++;
        }
        count=s;
        DeQueue(q,&temp);
        printf("%d ",temp);
    }
    return 0; //putchar('\n');
}