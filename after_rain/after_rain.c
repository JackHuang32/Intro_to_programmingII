
//You may use the following code as your append code for testing:

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _NODE
{
    char color[10];
    struct _NODE *next;
} Node;
void insert(Node**head, char*color, int des)
{
    Node* cur = (*head)->next;
    Node* pre = *head;
    while(des-- && cur!=NULL)
    {
        pre = cur;
        cur = cur->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->color,color);
    new_node->next = cur;
    pre->next = new_node;
}

void erase1(Node**head, int des)
{
    Node* cur = *head;
    Node* pre = *head;
    while(des-- && cur->next!=NULL)
    {
        pre = cur;
        cur = cur->next;
    }
    if(cur != *head)
    {
        pre->next = cur->next;
        free(cur);
    }
}

void erase2(Node**head, char* color)
{
    Node* cur = *head;
    Node* pre = *head;
    while(cur)
    {
        Node* tmp = cur;
        if(strcmp(cur->color,color)==0)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre;
            cur = cur->next; 
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
}

void reverse(Node** head, int left, int right)
{
    if(left == right)return;
    int gaps = right - left+1;
    Node* pre = NULL;
    Node* cur = *head;
    while(left-- && cur!=NULL)
    {
        pre = cur;
        cur = cur->next;
    }
    if(cur)
    {
        Node* begin_left = pre;
        Node* begin = cur;
        
        while(gaps-- && cur)
        {
            //printf("cur:%s\n",cur->color);
            Node* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        begin->next = cur;
        begin_left->next = pre;
    }
}

void show(Node **head) {
    Node *now = (*head)->next;
    while(now!=NULL) {
        printf("%s ", now->color);
        now = now->next;
    }
    puts("");
}

int n;
char buf[100];
int num1, num2;
Node *head;

int main() {
    head = (Node*)malloc(sizeof(Node)); // create an empty node
    memset(head->color,'\0',sizeof(head->color));
    head->next = NULL;
    scanf("%d",&n);
    while(n--) {
        scanf("%s",buf);
        if(!strcmp(buf,"insert")) {
            scanf("%s%d",buf,&num1);
            insert(&head, buf, num1); // insert <color> <dest>
        }
        else if(!strcmp(buf,"erase1")) {
            scanf("%d",&num1);
            erase1(&head, num1); // erase1 <dest>
        }
        else if(!strcmp(buf,"erase2")) {
            scanf("%s",buf);
            erase2(&head, buf); // erase2 <color>
        }
        else if(!strcmp(buf,"reverse")) {
            scanf("%d%d",&num1,&num2);
            reverse(&head, num1, num2); // reverse <dest1> <dest2>
        }
        else if(!strcmp(buf,"show")) {
            show(&head);
        }
    }
    return 0;
}