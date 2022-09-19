#include<stdio.h>
#include<stdlib.h>
typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;
int n;
int pre_idx = 0;
int find_in_idx(int val,int* Inorder,int in_start,int in_end)
{
    for (int i=in_start;i<=in_end;i++)
    {
        if(Inorder[i]==val)return i;
    }
}
Node* buildTree(int* Inorder, int* Preorder, int inorder_start, int inorder_end)
{
    if(inorder_start>inorder_end)return NULL;
    Node* new = (Node*)malloc(sizeof(Node));
    new->number = Preorder[pre_idx];
    new->ptr_to_left_node = NULL;
    new->ptr_to_right_node = NULL;
    pre_idx++;
    int in_idx = find_in_idx(new->number,Inorder,inorder_start,inorder_end);
    new->ptr_to_left_node = buildTree(Inorder,Preorder,inorder_start,in_idx-1);
    new->ptr_to_right_node = buildTree(Inorder,Preorder,in_idx+1,inorder_end);
    return new;
}
void showPostorder(Node* root)
{
    if(root == NULL)return;
    showPostorder(root->ptr_to_left_node);
    showPostorder(root->ptr_to_right_node);
    printf("%d ",root->number);
}

void freeTree(Node *root)
{
    if(root==NULL)return;
    freeTree(root->ptr_to_left_node);
    freeTree(root->ptr_to_right_node);
    free(root);
    pre_idx=0;
}

int main(void)
{
    int id = 1;
    while( ~scanf( "%d", &n ) )
    {
        int inorder[100], preorder[100];
        for( int i = 0; i < n; i++ )
            scanf( "%d", &inorder[i] );
        for( int i = 0; i < n; i++ )
            scanf( "%d", &preorder[i] );
        Node *root = buildTree( inorder, preorder, 0, n-1 );
        printf( "testcase%d: ", id++ );
        showPostorder( root );
        printf( "\n" );
        freeTree( root );
    }
    return 0;
}