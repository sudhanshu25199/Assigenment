#include <stdio.h>

int stack[5], top = -1;
int queue[5], front = 0, rear = -1;

void insertionSort(int a[], int n)
{
    int i, j, key;

    for(i=1;i<n;i++)
    {
        key = a[i];
        j = i-1;

        while(j>=0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
    }
}

void push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    int x;
    x = stack[top];
    top--;
    return x;
}

void enqueue(int x)
{
    rear++;
    queue[rear] = x;
}

int dequeue()
{
    int x;
    x = queue[front];
    front++;
    return x;
}

int main()
{

 int a[5] = {1,8,0,2,8};
 int b[5];
 int i, x;

    for(i=0;i<5;i++)
    {
        b[i] = a[i];
    }

    // Insertion Sort
    insertionSort(a,5);

  
    printf("Sorted Array: ");
    for(i=0;i<5;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");

    
    for(i=0;i<5;i++)
    {
        push(b[i]);
    }

    printf("Stack Output: ");
    for(i=0;i<5;i++)
    {
        x = pop();
        printf("%d",x);
        enqueue(x);
    }
    printf("\n");

    printf("Queue Output: ");
    for(i=0;i<5;i++)
    {
        printf("%d",dequeue());
    }
    printf("\n");

    return 0;
}