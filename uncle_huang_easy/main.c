#include<stdio.h>
#include<stdlib.h>
typedef struct _Node{
    int number;
    struct _Node* next;
}Node;
void show(Node*);
Node *createList(int n)
{
    Node* head = (Node*)malloc(sizeof(Node));
    Node* cur = head;
    head->number = 1;
    for(int i=2;i<=n;i++)
    {
        cur->next = (Node*)malloc(sizeof(Node));
        cur->next->number = i;
        cur = cur->next;
    }
    cur->next = head;
    return head;
}
void freeList(Node* head)
{
    Node* cur = head;
    while(cur!=head)
    {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(cur);
}
int get_len(Node** head)
{
    Node* cur = *head;
    int ans = 1;
    while(cur->next!=(*head))
    {
        ans++;
        cur = cur->next;
    }
    return ans;
}
int solveJosephus(Node **head, int step)
{
    int len = get_len(head);
    Node* cur = *head;
    Node* pre = NULL;
    if(step==1)return len;
    while(len>1)
    {
        int times = (step-1)%len;
        while(times--)
        {
            pre = cur;
            cur = cur->next;
        }
        if(cur==(*head))
        {
            *head = cur->next;
            pre->next = cur->next;
            Node* tmp = cur;
            cur = cur->next;
            free(tmp);
           // show(*head);
        }
        else
        {
            pre->next = cur->next;
            Node* tmp = cur;
            cur = cur->next;
            free(tmp);
            //show(*head);
        }
        len--;
    }    
    return cur->number;
}
void show(Node* head)
{
    Node* cur = head;
    while(cur->next!=head)
    {
        printf("%d ",cur->number);
        cur = cur->next;
    }
    printf("%d\n",cur->number);
}
int main()
{
    int n, k;
    while( scanf("%d%d", &n, &k)!=EOF )
    {
        Node *head;
        head = createList(n);
        //show(head);
        //printf("%d\n",get_len(&head));
        printf( "%d\n", solveJosephus(&head, k) );
        freeList(head);
    }
    return 0;
}