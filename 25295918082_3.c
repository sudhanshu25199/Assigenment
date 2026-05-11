#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100


typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


typedef struct {
    TreeNode* items[MAX_SIZE];
    int level[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize_queue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}


int is_empty(Queue *q) {
    return q->front == -1;
}


int is_full(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}


int enqueue(Queue *q, TreeNode* value, int l) {

    if (is_full(q)) {
        printf("Queue is full\n");
        return -1;
    }
    else {

        if (is_empty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        q->level[q->rear] = l;
        return 0;
    }
}


TreeNode* dequeue(Queue *q, int *l) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    else {

        TreeNode* item = q->items[q->front];
        *l = q->level[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }

        return item;
    }
}


int level_order_traversal(TreeNode *root) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return -1;
    }

    Queue q;
    int l;
    initialize_queue(&q);
    enqueue(&q, root,1);

    while (!is_empty(&q)) {
        TreeNode *current = dequeue(&q,&l);
        printf("L%d,",l);

        if (current->left != NULL) {
            enqueue(&q, current->left,l+1);
        }
        if (current->right != NULL) {
            enqueue(&q, current->right,l+1);
        }
    }
    printf("\n");
    return 0;
}


TreeNode* create_tree_node(int data) {
    TreeNode* new_node = (TreeNode*) malloc(sizeof(TreeNode));

    if (new_node == NULL) {
        printf("Memory not available!\n");
        return NULL;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}


TreeNode* insert(TreeNode* root, int value)
{
    if(root == NULL)
    {
        return create_tree_node(value);
    }
    if(value <=root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}


void in_order(TreeNode*root)
{
    if (root!=NULL)
    {
        in_order(root->left);
        printf("%d",root->data);
        in_order(root->right);
    }
}

void pre_order(TreeNode*root)
{
    if (root!=NULL)
    {
        printf("%d",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

int height(TreeNode* root) {
    if (root == NULL) return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh ? lh : rh) + 1;
}

void post_order(TreeNode* root,int depth)
{
    if (root!=NULL)
    {
        post_order(root->left, depth + 1);
        post_order(root->right,depth + 1);
        printf("Heigth of node %d=%d, depth of node %d=%d\n",root->data,height(root),root->data,depth);
    }
}



int main()
{
    int arr[5];
    printf("enter the array elements:");
    for(int i=0; i<5; i++)
    {
        scanf("%d",&arr[i]);
    }
    TreeNode *root = create_tree_node(arr[0]);
    root=insert(root,arr[1]);
    root=insert(root,arr[2]);
    root=insert(root,arr[3]);
    root=insert(root,arr[4]);
    printf("In order treversel:");
    in_order(root);
    printf("\nPre order traversel:");
    pre_order(root);
    printf("\nlevel order traversal of nodes 1,0,8,3,4=");
    level_order_traversal(root);
    post_order(root,0);
    return 0;
}