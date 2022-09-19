#include<stdio.h>
#include<stdlib.h>
int n,post_now;
int post[100],in[100];
typedef struct Node_
{
    int val;
    struct Node_* left;
    struct Node_* right;
}Node;
int find_in(int cur_post)
{
    for(int i=0;i<n;i++)
    {
        if(in[i]==cur_post)return i;
    }
}
Node* build(int start,int end)
{
    if(start>end)return NULL;
    int cur_post = post[post_now];
    Node* new = (Node*)malloc(sizeof(Node));
    new->left = NULL;
    new->right = NULL;
    new->val = cur_post;
    int in_idx = find_in(cur_post);
    post_now--;
    new->right = build(in_idx+1,end);
    new->left = build(start,in_idx-1);
    
    return new;       
}

void pre(Node*head)
{
    if(head==NULL)return;
    printf("%d ",head->val);
    pre(head->left);
    pre(head->right);
    return;
}
void free_tree(Node* head)
{
    if(head==NULL)return;
    if(head->left!=NULL)free_tree(head->left);
    if(head->right!=NULL)free_tree(head->right);
    free(head);
}
int main()
{
    int t=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)scanf("%d",&in[i]);
        for(int i=0;i<n;i++)scanf("%d",&post[i]);
        post_now = n-1;
        Node* head = build(0,n-1);
        printf("testcase%d: ",t++);
        pre(head);
        printf("\n");
        free_tree(head);
    }
    return 0;
}