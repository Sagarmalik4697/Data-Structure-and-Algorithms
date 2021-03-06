#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int is_full();
int is_empty();
void enqueue();
void dequeue();
void display();

int circularqueue[MAX];
int front = -1, rear = -1;

int main()
{
    int choice, res;
    while (1)
    {
        printf("\n1.Insert an element:");
        printf("\n2.Delete an element:");
        printf("\n3.Display:");
        printf("\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            res = is_full();
            if (res == 1)
                enqueue();
            break;
        case 2:
            res = is_empty();
            if (res == 1)
                dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Wrong choice...");
            break;
        }
    }
    return 0;
}
int is_full()
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\n Circular Queue is full..\n");
        return 0;
    }
    else
        return 1;
}
int is_empty()
{
    if (front == -1)
    {
        printf("\n Circular Queue is empty..");
        return 0;
    }
    else
        return 1;
}
void enqueue()
{
    int num;
    if (front == -1)
        front = 0;
    if ((front > 0) && (rear == MAX - 1))
        rear = 0;
    else
    {
        printf("Insert the element in queue : ");
        scanf("%d", &num);
        rear = rear + 1;
        circularqueue[rear] = num;
    }
}
void dequeue()
{
    printf("Deleted element is : %d", circularqueue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
}
void display()
{
    int f, r;
    f = front;
    r = rear;
    if (f == -1)
    {
        printf("\n Circular Queue is empty..");
        return 0;
    }
    printf("Queue is : \n");
    if (f <= r)
    {
        while (f <= rear)
        {
            printf("\t%d ", circularqueue[f]);
            f++;
        }
    }
    else
    {
        while (f <= MAX - 1)
        {
            printf("\t%d ", circularqueue[f]);
            f++;
        }
        f = 0;
        while (f <= rear)
        {
            printf("\t%d ", circularqueue[f]);
            f++;
        }
    }
}
