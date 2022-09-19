#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int value;
    struct node* next;
    struct node* pre;
}Node;
void insert(Node** head,int value)
{
    Node* cur = *head;
    Node* tmp = (Node*)malloc(sizeof(Node));
    Node*tmp2 = cur->next;
    tmp->value = value;
    tmp->pre = cur;
    cur->next = tmp;
    tmp->next = tmp2;
    tmp2->pre = tmp;
}
void erase(Node**head)
{
    Node* cur = *head;
    cur = cur->next;
    if(cur==*head)return;
    else
    {
        (*head)->next = cur->next;
        cur->next->pre = (*head);
        free(cur);
    }
}
void move(Node**head,int dir)
{
    if(dir)
    {
        (*head) = (*head)->next;
    }
    else
    {
        (*head) = (*head)->pre;
    }
}
void show(Node**head)
{
    Node*cur = *head;
    while(cur->next!=(*head))
    {
        printf("%d ",cur->value);
        cur = cur->next;
    }
    printf("%d\n",cur->value);
}
int current_len(Node** head)
{
    int ans = 0;
    Node* cur = *head;
    while(cur->next!=*head)
    {
        ans++;
        cur = cur->next;
    }
    return ++ans;
}
int main()
{
    int init,t;
    scanf("%d%d",&init,&t);
    Node* head = (Node*)malloc(sizeof(Node));
    head->value = init;
    head->next = head;
    head->pre  = head;
    while(t--)
    {
        char op[10];
        scanf("%s",op);
        if(!strcmp(op,"insert"))
        {
            int insert_value,times;
            scanf("%d%d",&insert_value,&times);
            while(times--)
            {
                insert(&head,insert_value);
            }
        }
        else if(!strcmp(op,"erase"))
        {
            int times;
            scanf("%d",&times);
            while(times--)
            {
                erase(&head);
            }
        }
        else if(!strcmp(op,"move"))
        {
            int times,dir=1;
            scanf("%d",&times);
            if(times<0)
            {
                times*=-1;
                dir = 0;
            }
            times %= current_len(&head); 
            while(times--)
            {
                
                move(&head,dir);
            }
        }
        else if(!strcmp(op,"show"))
        {
            show(&head);
        }
    }
    return 0;
}