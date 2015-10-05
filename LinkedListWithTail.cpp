#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;
struct listNode * tail;

void initializeList()
{
    list = 0;  //initially set to NULL
    tail = 0;
}


//add required codes to set up tail pointer
int insertItem(int item) //insert at the beginning
{
    struct listNode * newNode ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    //newNode->next = list ; //point to previous first node
    //list = newNode ; //set list to point to newnode as this is now the first node
    if(list==0)
    {
        list=newNode;
        newNode->next=0;
        tail=newNode;
    }
    else
    {
        newNode->next=list;
        list=newNode;
    }
    return SUCCESS_VALUE ;
}

//add required codes to set up tail pointer
int deleteItem(int item)
{
    struct listNode *temp, *prev ;

    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }
    if (temp == 0) return NULL_VALUE ; //item not found to delete
    else if (temp == list) //delete the first node
    {
        list = list->next;
        free(temp);
    }
    else if(temp==tail)
    {
        tail=prev;
        prev->next=0;
        free(temp);
    }
    else
    {
        prev->next = temp->next ;
        free(temp);
    }

    return SUCCESS_VALUE ;
}

//add required codes to set up tail pointer
struct listNode * searchItem(int item)
{
    struct listNode * temp ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) return temp ;
        temp = temp->next ; //move to next node
    }
    return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    struct listNode * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}


int insertLast(int item)
{
    //write your codes here
    struct listNode * newNode ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    newNode->next=0;
    if(list!=0)
    {
        tail->next=newNode;
        tail=newNode;
        return SUCCESS_VALUE;
    }
    else
    {
        list=newNode;
        tail=newNode;
    }
}


int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Insert Last. 5. Print. 6.exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d",&item);
            insertLast(item);
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            break;
        }
    }

}
