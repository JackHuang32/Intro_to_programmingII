#include<stdio.h>
#include<stdlib.h>
typedef struct _NODE {
    int level;
    struct _NODE *left_child, *right_child;
} Node;
void build_tree(Node **now, int *arr, int l, int r)
{
    if(l>r)return;
    else
    {
        int mid = (l+r)/2;
        Node* new = (Node*)malloc(sizeof(Node));
        new->level = arr[mid];
        (*now) = new;
        (*now)->left_child = NULL;
        (*now)->right_child = NULL;
        build_tree(&(*now)->left_child,arr,l,mid-1);
        build_tree(&(*now)->right_child,arr,mid+1,r);
    }
}
int query_heatstroke(Node *now, int x)
{
    if(now==NULL)return 0;
    else if(now->level>x)
    {
        return query_heatstroke(now->left_child,x);
    }
    else if(now->level<x)
    {
        return query_heatstroke(now->right_child,x);
    }
    else
    {
        return 1;
    }
}
void eat_rat(Node **root, int x)
{
    Node* cur = (*root);
    Node* par = NULL;
    while(cur->level!=x)
    {
        if(cur->level>x)
        {
            par = cur;
            cur = cur->left_child;
        }
        else if(cur->level<x)
        {
            par = cur;
            cur = cur->right_child;
        }
    }
    if(cur->left_child==NULL&&cur->right_child==NULL)
    {
        if(cur==(*root))(*root) = NULL;
        else 
        {
            if(cur==par->left_child)par->left_child = NULL;
            else if(cur==par->right_child)par->right_child = NULL;
            free(cur);
        }
        return;
    }
    if(cur->left_child!=NULL&&cur->right_child==NULL)
    {
        if(cur==(*root))
        {
            (*root) = cur->left_child;
            free(cur);
            return;
        }
        else if(par->left_child==cur)
        {
            par->left_child = cur->left_child;
            free(cur);
            return;
        }
        else if(par->right_child==cur)
        {
            par->right_child = cur->left_child;
            free(cur);
        }
        return;
    }
    if(cur->left_child==NULL&&cur->right_child!=NULL)
    {
        if(cur==(*root))
        {
            (*root) = cur->right_child;
            free(cur);
            return;
        }
        else if(par->left_child==cur)
        {
            par->left_child = cur->right_child;
            free(cur);
        }
        else if(par->right_child==cur)
        {
            par->right_child = cur->right_child;
            free(cur);
        }
        return;
    }
    else
    {
        Node* tmp = cur->left_child;
        while(tmp->right_child!=NULL)
        {
            tmp = tmp->right_child;
        }
        cur->level = tmp->level;
        eat_rat(&cur->left_child,cur->level);
    }
}
void show(Node* root)
{
    if(root==NULL)return;
    printf("%d ",root->level);
    show(root->left_child);
    
    show(root->right_child);
}
int main()
{
    Node* head;
    int arr[12];
    for(int i=1;i<=11;i++)arr[i] = i;
    build_tree(&head,arr,1,11);
    show(head);
    return 0;
}
