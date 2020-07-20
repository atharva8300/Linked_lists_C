#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *start = NULL;

node* create_cll(node *);
void display_cll(node *);

node* insert_beg(node *);
node* insert_end(node *);
node* insert_after(node *);

node* delete_beg(node *);
node* delete_end(node *);
node* delete_after(node *);
node* delete_list(node *);

void display_options();

int main()
{
    int n;
    do
    {
     display_options();
     printf("\n your choice : ");
     scanf("%d",&n);
     switch(n)
     {
        case 1: start = create_cll(start);
                printf("\n created\n");
                break;
        case 2: start = insert_beg(start);
                printf("\n inserted at beginning \n");
                break;
        case 3: start = insert_end(start);
                printf("\n inserted at end \n");
                break ;
        case 4: start = insert_after(start);
                printf("\n inserted \n");
                break;
        case 5: start = delete_beg(start);
                printf("\n deleted \n");
                break ;
        case 6: start = delete_end(start);
                printf("\n deleted \n");
                break;
        case 7: start = delete_after(start);
                printf("\n deleted \n");
                break;
        case 8: start = delete_list(start);
                start = delete_beg(start);
                printf("\n deleted \n");
                break;
        case 9:display_cll(start);
                break;
     }
    }while(n != 10);
    getch();
    return 0;
}
void display_options()
{
     printf(" ****CLL****\n");
     printf(" 1.create circular linked list \n");
     printf(" 2.insert in beginning\n 3.insert at end\n 4.insert after a particular node\n");
     printf(" 5.delete first node\n 6.delete last node\n 7.delete after a particular node\n 8.delete entire list\n");
     printf(" 9.display the list\n 10.exit \n");
}
node* create_cll(node *start)
{
int val;
printf("\nenter data[enter -1 to end the list]: ");
scanf("%d",&val);
do
{
    node *ptr;
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = val;
    if(start == NULL)
    {
        start = new_node ;
        new_node->next = start;
    }
    else
    {
        ptr = start;
        while(ptr->next!= start)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start ;
    }
    printf("\n enter data:");
    scanf("%d",&val);
}while(val!=-1);
return start;
}
node* insert_beg(node *start)
{
    int value ;
    node *ptr ;
    node *new_node = (node *)malloc(sizeof(node));
    printf("\n enter data : ");
    scanf("%d",&value);
    new_node->data = value ;
    ptr = start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start ;
    start = new_node ;
    return start ;
}
node* insert_end(node *start)
{
    int val ;
    node *ptr ;
    node *new_node = (node *)malloc(sizeof(node));
    printf("\n enter data : ");
    scanf("%d",&val);
    new_node->data = val;
    if(start == NULL)
    {
        start = new_node;
        new_node->next = start ;

    }
    else{
        ptr = start ;
        while(ptr->next != start)
        {
            ptr = ptr->next ;
        }
        ptr->next = new_node;
        new_node->next = start ;
    }
    return start ;
}
node* insert_after(node *start)
{
    int val,after;
    node *ptr,*preptr;
    node *new_node = (node *)malloc(sizeof(node));
    printf("\n enter value after which new node has to be inserted: ");
    scanf("%d",&after);
    printf("enter value to be inserted : ");
    scanf("%d",&val);
    new_node->data = val ;
    preptr = start ;
    ptr = start ;
    while(preptr->data != after)
    {
        preptr = ptr ;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr ;
    return start ;
}
node* delete_beg(node *start)
{
    node *ptr;
    ptr = start ;
    if(start == NULL)
    {
        printf("underflow");
    }
    else
    {
        while(ptr->next!=start)
        {
            ptr = ptr->next;
        }
        //printf("out of while");
        ptr->next = start->next ;
        if(ptr->next != start)
        {
            start = ptr->next;
            printf("\nin if");
            free(ptr);

        }
        else
        {
            printf("in else");
            free(ptr);
            start = NULL;
        }
    }

    return start;
}
node *delete_end(node *start)
{
    node *ptr,*preptr,*temp;
    ptr =start;
    preptr = ptr;
    while(ptr->next!=start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    temp = ptr;
    preptr->next = start;
    free(temp);
    return start ;
}
node* delete_after(node *start)
{
    int after;
    node *ptr,*preptr,*temp;
    printf("\n enter value after which node has to be deleted: ");
    scanf("%d",&after);
    ptr = start;
    preptr = ptr ;
    while(preptr->data!= after)
    {
        preptr = ptr ;
        ptr = ptr->next;
    }
    temp = ptr;
    preptr->next = ptr->next;
    free(temp);
    return start ;
}
node* delete_list(node *start)
{
    node *ptr,*temp ;
    if(start != NULL)
    {
        ptr = start ;
        while(ptr->next != start)
        {
            start = delete_beg(start);
            ptr = start ;
        }
       // start =delete_beg(start);
    }
    return start ;
}
void display_cll(node *start)
{
    node *ptr;
    ptr = start;
    if(start == NULL){printf("empty\n");}
    else{while(ptr->next!=start)
    {
        printf("\t%d\t",ptr->data);
        ptr = ptr->next ;
    }
    printf("\t%d\t",ptr->data);
    printf("\n\n");}

}

