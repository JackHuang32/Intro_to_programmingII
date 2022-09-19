#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char expr[300];
int cur_idx = 0;
typedef struct Node_
{
    char op;
    int isnum;
    int isvar;
    int val;
    struct Node_* left;
    struct Node_* right;
}Node;
int isnum(char op)
{
    if(op!='+'&&op!='-'&&op!='*'&&op!='/'&&op!='x'&&op!='y'&&op!='z'&&!isspace(op))
    {
        return 1;
    }
    return 0;
}
Node* new_node(char op,int len)
{
    Node* new = (Node*)malloc(sizeof(Node));
    if(isnum(op))
    {
        new->isnum = 1;
        new->isvar = 0;
        int num_len = 1;
        //printf("start_num_idx:%d",cur_idx);
        while(cur_idx+1<len)
        {
            if(isnum(expr[cur_idx+1]))
            {
                num_len++;
                cur_idx++;
            }
            else break;
        }
        if(num_len==3)new->val = 100;
        if(num_len==2)new->val = 10*(expr[cur_idx-1]-'0')+(expr[cur_idx]-'0');
        if(num_len==1)new->val = (expr[cur_idx]-'0');
        //printf("end_num_idx:%d numlen:%d value:%d\n",cur_idx,num_len,new->val);
    }
    else if(op=='x'||op=='y'||op=='z')
    {
        new->isnum = 0;
        new->isvar = 1;
        new->op = op;
    }
    else
    {
        new->isnum = 0;
        new->isvar = 0;
        new->op = op;
    }
    new->left = NULL;
    new->right = NULL;
    return new;
}
Node* build(int len)
{ 
    if(cur_idx>=len)return NULL;
    while(expr[cur_idx]==' '&&cur_idx<len)
    {
        cur_idx++;
    }
    Node* root = new_node(expr[cur_idx],len);
    cur_idx++;
    if(root->isnum||root->isvar)return root;
    else
    {
        root->left = build(len);
        root->right = build(len);
        return root;
    }
}
int calculate(Node* head,int x,int y,int z)
{
    if(head->isnum)return head->val;
    else if(head->isvar)
    {
        if(head->op=='x')return x;
        if(head->op=='y')return y;
        if(head->op=='z')return z;
    }
    else
    {
        if(head->op=='+')
        {
            return (calculate(head->left,x,y,z)+calculate(head->right,x,y,z));
        }
        if(head->op=='-')
        {
            return (calculate(head->left,x,y,z)-calculate(head->right,x,y,z));
        }
        if(head->op=='*')
        {
            return (calculate(head->left,x,y,z)*calculate(head->right,x,y,z));
        }
        if(head->op=='/')
        {
            return (calculate(head->left,x,y,z)/calculate(head->right,x,y,z));
        }
    }
}
void print_tree(Node*head)
{
    if(head==NULL)return;
    print_tree(head->left);
    if(head->isnum)printf("%d",head->val);
    else
    {
        printf("%c",head->op);
    }
    print_tree(head->right);
}
int main()
{
    fgets(expr,100,stdin);
    //printf("len:%d\n",strlen(expr));
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    int len = strlen(expr);
    Node* head = build(len);
    int ans = calculate(head,x,y,z);
    print_tree(head);
    printf("\n%d\n",ans);
    return 0;
}