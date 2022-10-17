#include<stdio.h>
#include<stdlib.h>
typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;
Node* buildTree(int* Inorder, int* Preorder, int inorder_start, int inorder_end)
{
    //printf("start:%d end:%d\n",inorder_start,inorder_end);
    if(inorder_start > inorder_end)return NULL;
    Node* cur = (Node*)malloc(sizeof(Node));
    cur->number = Preorder[inorder_start];
    int cur_idx;
    for(int i=inorder_start;i<=inorder_end;i++)
    {
        if(Inorder[i]==Preorder[inorder_start])
        {
            cur_idx = i;
            break;
        }
    }
    cur->ptr_to_left_node = buildTree(Inorder,Preorder+1,0,cur_idx-1);
    cur->ptr_to_right_node = buildTree(Inorder+cur_idx+1,Preorder+cur_idx+1,0,inorder_end-cur_idx-1);
    return cur;
}
void showPostorder(Node* root)
{
    if(!root)return;
    showPostorder(root->ptr_to_left_node);
    showPostorder(root->ptr_to_right_node);
    printf("%d ",root->number);
}

void freeTree(Node *root)
{
    if(!root)return;
    if(root->ptr_to_left_node)
    {
        freeTree(root->ptr_to_left_node);
    }
    if(root->ptr_to_right_node)
    {
        freeTree(root->ptr_to_right_node);
    }
    free(root);
}

int n;
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