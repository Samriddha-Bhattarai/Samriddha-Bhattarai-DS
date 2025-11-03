#include<stdio.h>
#define N 5
int queue [N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
if((rear+1)%N==front)
{
    printf("Queue Overflow\n");
}
else if (front == -1 && rear == -1)
{
    front = rear = 0;
    queue[rear]=x;
}
else
{
    rear = (rear+1)%N;
    queue[rear]=x;
}
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        printf("dequeue =%d \n", queue[front]);
        front=rear-1;
    }
    else
    {
        printf("dequeue =%d \n", queue[front]);
        front = (front +1)%N;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("queue elements: \n");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
    else{
        for(int i = front; i < N; i++){
        printf("%d ", queue[i]);
        }
        for(int i= 0; i<= rear; i++){
            printf("%d ",queue[i]);
        }
    }
    printf("\n");
}
int main() {
    int choice, value;

    while (1) {

        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d ", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d ", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
