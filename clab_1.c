#include<stdio.h>
#include <stdlib.h>
int insertAtEmpty(int *list,  int size)
{
    int i;
    for(i=0;i<size;i++){
    printf("Enter the elements at the list[%d]: ",i);
    scanf("%d",(list+i));
    }
}

int insert(int *list, int size, int item, int insertAt)
{
    int  i, sizeOfList;
    sizeOfList = size;
    list = realloc(list, ((size + 1) * sizeof(int)));
    for (i = size; i >= insertAt; i--)
        list[i + 1] = list[i];

    list[insertAt] = item;
    sizeOfList = ++size;
    return sizeOfList;
}
int printlist(int *list, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("list[%d] = %d\n", i, *(list + i));
    }

}
int search(int *list, int value, int size)
{
    int i, key = 0;
    for (i = 0; i < size; ++i)
    {
        if (list[i] == value)
        {
            key = 1;
            break;
        }
    }
    if (key == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int del(int *list, int index, int size)
{
    int sizeOfList,count;
    for (count=index;count<size-1;count++)
        list[count]=list[count+1];
    sizeOfList=--size;
    return sizeOfList;

}
int main()
{
    int *list, sizeOfList;
    int size, item, count = 0;
    int choice, value, result;
    int insertAt,index;
    // fill the list with elements.
    printf("enter the size\n");
    scanf("%d", &size);
    list = (int *)malloc(size * sizeof(int));
    insertAtEmpty(list, size);
  do
    {
        printf("Implimentation of list\nchoose any operation\n");
        printf("1.Insert an element\n 2.Delete an element\n 3.Search\n 4. View list\n 5. Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the position where you want to insert\n");
            scanf("%d",&insertAt);
            printf("enter the value to insert \n");
            scanf("%d", &item);
            sizeOfList = insert(list, size, item , insertAt );
            size = sizeOfList;
            printf("element is inserted");
            printf("updated array\n");
            printlist(list, size);
            break;

        case 2:
            printf("enter the index you want to delete\n");
            scanf("%d",&index); 
            sizeOfList = del(list, index, size);
            size = sizeOfList;
            printf("element is deleted\n");
            printf("Updated array is :\n");
            printlist(list, size);
            break;
        case 3:
            printf("Enter the value you want to search\n\t");
            scanf("%d", &value);
            result = search(list, value, size);
            if (result == -1 || size == 0)
                printf("Element not found or array is empty");
            else
                printf("Element found on index: %d", result);
            break;
        case 4:

            printlist(list, size);
            break;
        case 5:
            printf("press enter to exit...");

            exit(0);
            break;
        default:

            printf("Wrong choice");
            break;
        }
        printf("\nPress enter to continue");
    }while(1);
    return 0;
}