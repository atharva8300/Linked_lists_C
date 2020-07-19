#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next ;
};
typedef struct node node ;
node *start = NULL ;

node* create_ll(node *);

node* insert_begin(node *);
node* insert_end(node *);
node* insert_after(node *);
node* insert_before(node *);

node* delete_first(node *);
node* delete_end(node *);
node* delete_after(node *);
node* delete_node(node *);
node* delete_list(node *);

void display_sll(node *);

node* sort_sll(node *);

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
        case 1: start = create_ll(start);
                printf("\n created\n");
                break;
        case 2: start = insert_begin(start);
                printf("\n inserted at beginning \n");
                break;
        case 3: start = insert_end(start);
                printf("\n inserted at end \n");
                break ;
        case 4: start = insert_after(start);
                printf("\n inserted \n");
                break;
        case 5: start = insert_before(start);
                printf("\n inserted \n");
                break;
        case 6: start = delete_first(start);
                printf("\n deleted \n");
                break ;
        case 7: start = delete_end(start);
                printf("\n deleted \n");
                break;
        case 8: start = delete_after(start);
                printf("\n deleted \n");
                break;
        case 9: start = delete_node(start);
                printf("\n deleted \n");
                break;
        case 10:start = delete_list(start);
                printf("\n deleted \n");
                break;
        case 11:display_sll(start);
                break;
        case 12:start = sort_sll(start);
                printf("\n sorted \n");
                break;
     }
    }while(n != 13);
    getch();
    return 0;
}
void display_options()
{
     printf(" ****SLL****\n");
     printf("1.create singly linked list \n");
     printf(" 2.insert in beginning\n 3.insert at end\n 4.insert after a particular node\n 5.insert before a particular node\n");
     printf(" 6.delete first node\n 7.delete last node\n 8.delete after a particular node\n 9.delete a node\n 10.delete entire list\n");
     printf(" 11.display the list\n 12.sort list\n 13.exit");
}

node* create_ll(node *start)
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
        new_node->next = NULL;
        start = new_node ;
    }
    else
    {
        ptr = start;
        while(ptr->next!= NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = NULL ;
    }
    printf("\n enter data:");
    scanf("%d",&val);
}while(val!=-1);
return start;
}
node* insert_begin(node *start)
{
    int value ;
    node *new_node = (node *)malloc(sizeof(node));
    printf("\n enter data : ");
    scanf("%d",&value);
    new_node->data = value ;
    new_node->next = start ;
    start = new_node;
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
        new_node->next = NULL ;
        start = new_node;
    }
    else{
        ptr = start ;
        while(ptr->next != NULL)
        {
            ptr = ptr->next ;
        }
        ptr->next = new_node;
        new_node->next = NULL ;
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
        printf("in while");
        preptr = ptr ;
        ptr = ptr->next;
    }
    printf("out of while");
    preptr->next = new_node;
    printf("out of while");
    new_node->next = ptr ;
    return start ;
}
node* insert_before(node *start)
{
    int val,before;
    node *ptr,*preptr;
    node *new_node = (node *)malloc(sizeof(node));
    printf("\n enter value before which new node has to be inserted: ");
    scanf("%d",&before);
    printf("enter value to be inserted : ");
    scanf("%d",&val);
    new_node->data = val ;
    ptr = start ;
    preptr = start ;
    while(ptr->data != before)
    {
        preptr = ptr;
        ptr=ptr->next;
    }
    preptr->next = new_node ;
    new_node->next = ptr;
    return start;
}
node* delete_first(node *start)
{
    node *ptr ;
    ptr = start ;
    start = start->next ;
    free(ptr);
    return start ;
}
node *delete_end(node *start)
{
    node *ptr,*preptr,*temp;
    ptr =start;
    preptr = ptr;
    while(ptr->next!=NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    temp = ptr;
    preptr->next = NULL;
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
    preptr->next = ptr->next;
    temp = ptr;
    free(temp);
    return start ;
}
node* delete_node(node *start)
{
    int tobedeleted;
    node *ptr,*preptr,*temp;
    printf("\n enter node which has to be deleted: ");
    scanf("%d",&tobedeleted);
    ptr = start;
    preptr = ptr ;
    while(ptr->data != tobedeleted)
    {
        preptr = ptr ;
        ptr = ptr->next;
    }
    temp = ptr ;
    preptr->next = ptr->next ;
    free(temp);
    return start;

}
node* delete_list(node *start)
{
    node *ptr ;
    if(start != NULL)
    {
        ptr = start;
        while(ptr != NULL)
        {
            printf("\n %d is to be deleted next",ptr->data);
            start = delete_first(ptr);
            ptr = start ;
        }
    }
    return start;
}
node* sort_sll(node *start)
{
    node *ptr1,*ptr2;
    int temp;
    ptr1=start;
    while(ptr1->next!=NULL)
    {
        ptr2 = ptr1->next ;
        while(ptr2!=NULL)
        {
            if(ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp ;
            }
            ptr2 = ptr2->next ;
        }
        ptr1 = ptr1->next ;
    }
    return start ;
}
void display_sll(node *start)
{
    node *ptr;
    ptr = start;
    if(start == NULL){printf("empty");}
    while(ptr!=NULL)
    {
        printf("\t%d\t",ptr->data);
        ptr = ptr->next ;
    }
    printf("\n\n");
}








