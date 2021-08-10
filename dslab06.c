#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
struct Queue
{
    int *data;       //the array which has items
    int maxCapacity; // maxCapacity is allocated at the time of creation of the queue
    int front; //index of the front item, starts from 0
    int rear;  //index of the rear item, starts from 0
};

int noOfItems(struct Queue *queue)
{
     if (queue->rear == -1 && queue->front == -1) //for empty queue
    {
        return 0;
    }
    else if (queue->rear >= queue->front) 
    {
        return (queue->rear - queue->front) + 1;
    }
    else
    {
        return (((queue->maxCapacity) - queue->front)) + (queue->rear + 1); 
        // condition is used when front index is greater than rear index
    }
}

int isFull(struct Queue *queue)
{
    // input: the address of the queue
    // output: 1 if full, 0 if not full
    // it checks if the queue is full or not
    if (noOfItems(queue) == queue->maxCapacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int enQueue(struct Queue *queue, int item)
{
    printf("enQueue %d:\n", item);
    if (isFull(queue) == 0) // queue is not full
    {
        // increment the rear (circularly) and add one element at the rear
        if (noOfItems(queue) == 0) //queue is empty
        {
            queue->front = 0; //storing the elements from 0th index
        }
        queue->rear = (queue->rear + 1) % (queue->maxCapacity); // incrementing the rear circularly
        queue->data[queue->rear] = item;
        return 1;
    }
    else
    {
        return 0;
    }
}

int deQueue(struct Queue *queue)
{
    printf("\n\tinside deQueue function...\n");
    if (noOfItems(queue) != 0) //queue is not empty
    {
        // copy the front item in a variable (temp)
        int temp = queue->data[queue->front];
        if (queue->front == queue->rear) 
        {
            // queue is going to be empty after this operation
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1) % (queue->maxCapacity); //circular way
        }
        // returning the dequeued element to this function 
        return temp;
    }
    else
    {
        return INT_MIN;
    }
}

void printQueueDetails(struct Queue *queue)
{
    printf("maxCapacity=%d\t  front=%d\t  rear=%d\t \n", queue->maxCapacity, queue->front, queue->rear);
}

void printQueue(struct Queue *queue)
{
    int i;
    printf("queue: ");
    i = queue->front;
    if (noOfItems(queue) != 0)
    {
        // Aditya Kotwal
        do
        {
            printf("data[%d]= %d   ", i, queue->data[i]);
            i = (i + 1) % (queue->maxCapacity);
        } while (i != (queue->rear + 1) % queue->maxCapacity);
        printf("\n");
    }
}

int main()
{
    struct Queue queueA;
    int size, choice, element, deQueued, value;
    printf("Enter the size of the queue : ");
    scanf("%d", &size);
    queueA.maxCapacity = size;
    queueA.front = -1;                                            
    queueA.rear = -1;                                             
    queueA.data = (int *)malloc(queueA.maxCapacity * sizeof(int)); //memory allocation for the queue
    printf("noOfItems = %d", noOfItems(&queueA));
    do
    {
        printf("\t OPERATIONS \n");
        printf(" 1. enQueue \n 2. deQueue \n 3. Display elements \n 4. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice); // input choice from the user
        switch (choice)
        {
        case 1:
            printf("\n \t Pushing in queue. \n");
            printf("Enter the element you want to enQueue in the queue : ");
            scanf("%d", &element);
            if (noOfItems(&queueA) == size)
            {
                printf("element can't be enqueued!!! \n");
            }
            else
            {
                enQueue(&queueA, element);
                printf("\n%d is added.\n", element);
            }
            break;
        case 2:
            printf("deQueue the element from queue. \n");
            value = deQueue(&queueA);

            if (value != INT_MIN)
            {
                printf("\n%d is removed\n", value);
            }
            else
            {
                printf("element can't be dequeued \n");
            }
            break;

        case 3:
            printQueueDetails(&queueA);
            printQueue(&queueA); 
            break;
        case 4:
            exit(0);
        default:
            printf("\n \t WRONG CHOICE ENTERED !! \n");
            break;
        }
        printf("\nPress enter to continue... \n");
        getch();
    } while (1);
    return 0;
}