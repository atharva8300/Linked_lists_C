//a program to store 2 polynomials using 2 LLs and also perform addition/subtraction on these 2 polynomials
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int coeff,exp;
    struct node *next;
};
typedef struct node node ;
node *start1 = NULL ;//poly1
node *start2 = NULL ;//poly2
node *start3 = NULL ;//addition LL
node *start4 = NULL ;//subtraction LL

void display_options();
void display_poly(node *);

node* create_poly(node *);
node* add_poly(node *,node *,node *);
node* sub_poly(node *,node *,node *);
node* add_node(node *,int ,int);


int main()
{
    int option ;
    do
    {
        display_options();
        printf("\nenter your choice : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: start1 = create_poly(start1);
                    break ;
            case 2: display_poly(start1);
                    break ;
            case 3: start2 = create_poly(start2);
                    break ;
            case 4: display_poly(start2);
                    break ;
            case 5: start3 = add_poly(start1,start2,start3);
                    printf("\nadded poly:\n");
                    display_poly(start3);
                    break;
            case 6: start4 = sub_poly(start1,start2,start3);
                    printf("\nsubtracted poly:\n");
                    display_poly(start4);
                    break;

        }
    }while(option != 7);
    getch();
    return 0;
}
void display_options()
{
    printf("****POLYNOMIALS****\n");
    printf("1.enter poly 1\n2.display poly 1\n3.enter poly 2\n4.display poly 2\n");
    printf("5.addition\n6.subtraction\n7.exit\n");
}
node* create_poly(node *start)
{
    node *new_node ;
    node *ptr;
    int  co,ex;
    printf("\nenter coeff: ");
    scanf("%d",&co);
    printf("nenter expo: ");
    scanf("%d",&ex);
    while(co!=-1)
    {
    if(start == NULL)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node->coeff = co ;
        new_node->exp = ex ;
        new_node->next = NULL;
        start = new_node;
    }
    else
    {
        new_node = (node *)malloc(sizeof(node));
        new_node->coeff = co ;
        new_node->exp = ex ;
        ptr = start ;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node ;
        new_node->next = NULL;
    }
    printf("\nenter coeff[-1 to end]: ");
    scanf("%d",&co);
    printf("nenter expo[if coeff is -1 enter any random number it wont be stored anyways]: ");
    scanf("%d",&ex);
    }
    return start ;
}
node* add_poly(node *start1,node *start2,node *start3)
{
    int sum=0;
    node *ptr1,*ptr2;
    ptr1=start1;
    ptr2=start2;
    printf("in addpoly");
    while(ptr1 != NULL && ptr2!=NULL)
    {
        printf("in while");
        if(ptr1->exp == ptr2->exp)
        {
            printf("in if");
            sum = ptr1->coeff + ptr2->coeff;
            start3 = add_node(start3,sum,ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp)
        {
            start3 = add_node(start3,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next ;
        }
        else if(ptr1->exp < ptr2->exp)
        {
            start3 = add_node(start3,ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    if(ptr1 == NULL)
    {
        while(ptr2!= NULL)
        {
            start3 = add_node(start3,ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next ;
        }
    }
    else if(ptr2 == NULL)
    {
        while(ptr1!= NULL)
        {
            start3 = add_node(start3,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next ;
        }
    }
    return start3;
}



node* sub_poly(node *start1,node *start2,node *start4)
{
    int diff=0;
    node *ptr1,*ptr2;
    ptr1=start1;
    ptr2=start2;
    while(ptr1 != NULL && ptr2!=NULL)
    {
        if(ptr1->exp == ptr2->exp)
        {
            diff = ptr1->coeff - ptr2->coeff;
            start4 = add_node(start4,diff,ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp)
        {
            start4 = add_node(start4,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next ;
        }
        else if(ptr1->exp < ptr2->exp)
        {
            start4 = add_node(start4,ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    if(ptr1 == NULL)
    {
        while(ptr2!= NULL)
        {
            start4 = add_node(start4,ptr2->coeff,ptr2->exp);
            ptr2 = ptr2->next ;
        }
    }
    else if(ptr2 == NULL)
    {
        while(ptr1!= NULL)
        {
            start4 = add_node(start4,ptr1->coeff,ptr1->exp);
            ptr1 = ptr1->next ;
        }
    }
    return start4;
}
node* add_node(node *start,int coefficient,int exponent)
{
    node *new_node,*ptr ;

    printf("in add node");
    if(start == NULL)
    {   new_node = (node*)malloc(sizeof(node));
        printf("in addnode if");
        new_node->coeff = coefficient ;
        new_node->exp = exponent ;
        new_node->next = NULL ;
        start = new_node ;
    }
    else
    {
        new_node = (node*)malloc(sizeof(node));
        printf("in addnode else");
        ptr = start ;
        while(ptr -> next != NULL)
        {
            ptr = ptr->next ;
        }
        ptr->next = new_node ;
        new_node->coeff = coefficient;
        new_node->exp = exponent;
        new_node->next = NULL;
    }
    return start ;
}
void display_poly(node *start)
{
    node *ptr = start ;
    if(ptr == NULL){printf("empty");}
    else{
    while(ptr != NULL)
    {
        printf("%d%d\n",ptr->coeff,ptr->exp);
        ptr = ptr->next ;
    }
    }

}
