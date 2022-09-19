#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _NODE
{
    char character;
    struct _NODE *ptr_to_next_node;
    struct _NODE *ptr_to_prev_node;
}Node;
Node *head, *tail, *cursor;
void insert(Node**cur, char arr)
{
    Node* new = (Node*)malloc(sizeof(Node));
    new->character = arr;
    if((*cur)->ptr_to_next_node == head)tail = new;
    new->ptr_to_next_node = (*cur)->ptr_to_next_node;
    new->ptr_to_prev_node = (*cur);
    (*cur)->ptr_to_next_node->ptr_to_prev_node = new;
    (*cur)->ptr_to_next_node = new;

}
void deletion(Node **cur)
{
    if((*cur)->ptr_to_next_node == head)return;
    Node* tmp = (*cur)->ptr_to_next_node;
    (*cur)->ptr_to_next_node = tmp->ptr_to_next_node;
    tmp->ptr_to_next_node->ptr_to_prev_node = (*cur);
    if((*cur)->ptr_to_next_node == head)tail = (*cur);
    free(tmp);
    
}
void backspace(Node**cur)
{
    if((*cur) == head)return;
    Node* tmp = (*cur);
    (*cur) = (*cur)->ptr_to_prev_node;
    tmp->ptr_to_next_node->ptr_to_prev_node = (*cur);
    (*cur)->ptr_to_next_node = tmp->ptr_to_next_node;
    free(tmp);
}
void go_left(Node**cur, int times)
{
    while(times--)
    {
        (*cur) = (*cur)->ptr_to_prev_node;

    }
}
void go_right(Node**cur, int times)
{
    while(times--)
    {
        (*cur) = (*cur)->ptr_to_next_node;
 
    }
}
void go_home(Node**cur)
{
    (*cur) = head;
}
void go_end(Node**cur)
{
    (*cur) = tail;
}
void show()
{
    if(head == NULL) {
        printf("\n");
        return;
    }
    Node *now = head->ptr_to_next_node;
    while(now != head)
    {
        printf("%c ", now->character);
        now = now->ptr_to_next_node;
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    head = (Node*)malloc(sizeof(Node));
    head->ptr_to_next_node = head->ptr_to_prev_node = head;
    cursor = tail = head;
    while(n--)
    {
        char buf[20];
        scanf("%s",buf);
        if(!strcmp(buf,"insert"))
        {
            getchar();
            char intype;
            scanf("%c",&intype);
            insert(&cursor, intype); 
        }
        else if(!strcmp(buf,"deletion"))
        {
            deletion(&cursor); 
        }
        else if(!strcmp(buf,"backspace"))
        {
            backspace(&cursor); 
        }
        else if(!strcmp(buf,"go_left"))
        {
            int num;
            scanf("%d", &num);
            go_left(&cursor, num); 
        }
        else if(!strcmp(buf,"go_right"))
        {
            int num;
            scanf("%d", &num);
            go_right(&cursor, num); 
        }
        else if(!strcmp(buf,"go_home"))
        {
            go_home(&cursor); 
        }
        else if(!strcmp(buf,"go_end"))
        {
            go_end(&cursor); 
        }
        else if(!strcmp(buf,"show"))
        {
            show();
        }
    }
    return 0;
}