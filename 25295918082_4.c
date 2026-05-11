#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100

//bianry search tree
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

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


TreeNode* insert_bst(TreeNode* root, int value)
{
    if(root == NULL)
    {
        return create_tree_node(value);
    }
    if(value < root->data)
    {
        root->left = insert_bst(root->left, value);
    }
    else
    {
        root->right = insert_bst(root->right, value);
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

void post_order(TreeNode* root)
{
    if (root!=NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d",root->data);
    }
}


//heap
typedef struct {
    int items[MAX_SIZE];
    int size;
} Heap;

int swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}

int heapify_up(Heap *heap, int index) {
    if (index == 0) {
        return -1;
    }
    while (index>0){
        int parent_index = (index - 1) / 2;
        if (heap->items[parent_index] > heap->items[index]) {
            swap(&heap->items[parent_index], &heap->items[index]);
            index = parent_index;
        }
        else{
            break;
        }
    }

    return 0;
}

int insert_heap(Heap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap is full\n");
        return -1;
    }
    heap->items[heap->size] = value;
    heap->size++;
    heapify_up(heap, heap->size-1);
    return 0;
}

void display(Heap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->items[i]);
    }
    printf("\n");
}

int delete_root(Heap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1;
    }
    printf("Deleted root: %d\n", heap->items[0]);
    heap->items[0] = heap->items[heap->size - 1];
    heap->size--;
    for (int i = 1; i < heap->size; i++) {
        heapify_up(heap, i);
    }
    return 0;
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
    for(int i=1; i<5; i++)
    {
        root=insert_bst(root,arr[i]);
    }
    printf("In order treversel:");
    in_order(root);
    printf("\nPost order treversel:");
    post_order(root);
    Heap heap= { .size = 0 };
    for(int i=0; i<5; i++)
    {
        insert_heap(&heap, arr[i]);
    }
    printf("\n");
    display(&heap);
    delete_root(&heap);
    display(&heap);
    return 0;
}