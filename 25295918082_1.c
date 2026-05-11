#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main()
{
    int a[5] = {1,8,0,8,2};
    int b[5];
    int i;

    // Copy original array
    for(i=0;i<5;i++)
    {
        b[i] = a[i];
    }

    // Quick Sort because 18082 % 3 = 1
    quicksort(a,0,4);

    // Print sorted array
    printf("Sorted Array: ");
    for(i=0;i<5;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");

    // Reverse original array
    for(i=0;i<2;i++)
    {
        int temp = b[i];
        b[i] = b[4-i];
        b[4-i] = temp;
    }

    // Print reversed array
    printf("Reversed Array: ");
    for(i=0;i<5;i++)
    {
        printf("%d",b[i]);
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = b[i];
        newnode->next = NULL;
        newnode->prev = NULL;

        if(head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    // Forward Traversal

    struct node *temp;
    temp = head;

    printf("DLL Forward: ");
    while(temp != NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Backward Traversal

    temp = tail;

    printf("DLL Backward: ");
    while(temp != NULL)
    {
        printf("%d",temp->data);
        temp = temp->prev;
    }
    printf("\n");

    return 0;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j,temp;

    for(j=low;j<high;j++)
    {
        if(a[j] < pivot)
        {
            i++;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        }
    
    }

    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;

    return i+1;
}

void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(a,low,high);

        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}