#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next,*prev;
};
typedef struct node node ;
node *start = NULL ;

void display_options();
void display_dll(node *);

node* create_dll(node *);

node* insert_beg(node *);
node* insert_end(node *);
node* insert_after(node *);

node* delete_beg(node *);
node* delete_end(node *);
node* delete_after(node *);
node* delete_list(node *);

int count(node *);


int main()
{
    int option;
    do
    {
        display_options();
        printf("Your choice : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: start = create_dll(start);
                    printf("\ncreated\n");
                    break ;
            case 2: start = insert_beg(start);
                    printf("inserted\n");
                    break;
            case 3: start = insert_end(start);
                    printf("inserted\n");
                    break;
            case 4: start = insert_after(start);
                    printf("\ninserted\n");
                    break;
            case 5: start = delete_beg(start);
                    printf("\ndeleted\n");
                    break;
            case 6: start = delete_end(start);
                    printf("\ndeleted\n");
                    break;
            case 7: start = delete_after(start);
                    printf("\ndeleted\n");
                    break;
            case 8: start = delete_list(start);
                    printf("\ndeleted\n");
                    break;
            case 9: display_dll(start);
                    break;
        }
    }while(option != 10);
    getch();
    return 0;
}
void display_options()
{
    printf("***DLL***\n");
    printf("1.create Doubly Linked List\n2.insert in the beginning\n3.insert at end\n4.insert after a node\n");
    printf("5.delete beginning\n6.delete end\n7.delete after a node\n8.delete entire list\n");
    printf("9.display list\n10.exit\n");
}
 node* create_dll(node *start)
 {
     int val,c;
     printf("\nenter data: ");
     scanf("%d",&val);
     while(val != -1)
     {
         node *ptr,*new_node;
         if(start == NULL)
         {
             new_node = (node *)malloc(sizeof(node));
             new_node->data = val ;
             new_node->next = NULL ;
             new_node->prev = NULL ;
             start = new_node ;
         }
         else
         {
             ptr = start ;
             new_node = (node *)malloc(sizeof(node));
             while(ptr->next != NULL)
             {
                 ptr=ptr->next;
             }
             new_node->data = val ;
             new_node->prev = ptr ;
             ptr->next = new_node ;
             new_node->next = NULL ;
         }
         printf("\nenter data[enter -1 to end] : ");
         scanf("%d",&val);
     }
     //c = count(start);
     //printf("%d= count",c);
     return start ;
 }
 node* insert_beg(node *start)
 {
     int val,c ;
     node *new_node = (node *)malloc(sizeof(node));
     printf("\nenter data : ");
     scanf("%d",&val);
     new_node->data = val ;
     new_node->prev = NULL ;
     start->prev = new_node ;
     new_node->next = start ;
     start = new_node ;
     c=count(start);
     printf("\n number of nodes = %d\n",c);
     return start ;
 }
node* insert_end(node *start)
{
    int val,c;
    node *ptr,*new_node ;
    new_node = (node *)malloc(sizeof(node));
    printf("\nenter data : ");
    scanf("%d",&val);
    new_node->data = val ;
    ptr = start ;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new_node->prev = ptr ;
    ptr->next = new_node;
    new_node->next = NULL ;
    c=count(start);
    printf("\n number of nodes = %d\n",c);
    return start;
}
node* insert_after(node *start)
{
    int val,num,c;
    node *ptr,*new_node;
    new_node =(node *)malloc(sizeof(node));
    printf("\nenter value of node after which new node has to be inserted : ");
    scanf("%d",&num);
    printf("\nenter data : ");
    scanf("%d",&val);
    new_node->data = val ;
    ptr = start ;
    while(ptr->data != num)
    {
        ptr= ptr->next;
    }
    new_node->next = ptr->next ;
    new_node->prev = ptr ;
    ptr->next->prev = new_node ;
    ptr->next = new_node ;
    c=count(start);
    printf("\n number of nodes = %d\n",c);
    return start ;
}
node* delete_beg(node *start)
{
    int t;
    node *ptr = start ;
    t = count(start);
    if(start == NULL)
    {
        printf("\nunderflow\n");
    }
    else if (t == 1)
    {
        free(start);
        start = NULL ;
    }
    else{
        start->next->prev =NULL ;
        start = start->next ;
        free(ptr);
    }
    return start ;
}
node* delete_end(node *start)
{
    node *ptr = start ;
    int t ;
    t=count(start);
    if(start == NULL)
    {
        printf("underflow");
    }
    else
    {
        printf("in else");
        while(ptr->next != NULL)
        {
            printf("in while");
            ptr = ptr->next ;
        }
        if(t==1)
        {
            free(start);
            start = NULL;
        }
        else{
            ptr->prev->next = NULL;
            free(ptr);
        }

    }
    return start;
}
node* delete_after(node *start)
{
    int num;
    node *ptr,*temp;
    printf("\nenter value of node after which node has to be deleted : ");
    scanf("%d",&num);
    ptr = start;
    while(ptr->data != num)
    {
        printf("in while");
        ptr = ptr->next;
    }
    temp = ptr->next ;
    temp->next->prev = ptr;
    ptr->next = temp->next;

    free(temp);
    return start;
}
node* delete_list(node *start)
{
    node *ptr;
    if(start != NULL)
    {
        ptr = start ;
        while(ptr!= NULL)
        {
            start = delete_beg(start);
            ptr = start ;
        }
    }
    return start ;
}


void display_dll(node *start)
{
    node *ptr = start ;
    if(start == NULL)
    {
        printf("\nempty list\n");
    }
    while(ptr != NULL)
        {
            printf("\t%d\t",ptr->data);
            ptr=ptr->next;
        }
        printf("\n\n");
}
int count(node *start)
{
    int c=0;
    node *ptr = start ;
    if(ptr == NULL)
    {
        c=0;
    }
    else{
         while(ptr!=NULL)
        {
            c++;
            ptr= ptr->next;

        }
    }
    return c;
}
