#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int data;
    struct NODE *link; 
}node_t;
void create(node_t *,int);
void addFront(node_t **);
int display(node_t *);
void addBack(node_t *);
int main()
{
    int num,option;
    node_t *root=NULL;
    while(1)
    {
    printf("1.Create 2.Add Front 3.Add Back 4.Display 5.Exit:");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        root=(node_t*)malloc(sizeof(node_t));
        printf("Enter Element No:");
        scanf("%d",&num);
        printf("Enter Element 1:");
        scanf("%d",&root->data);
        root->link=NULL;
        create(root,num);
        break;
        case 2:
        addFront(&root);
        break;
        case 3:
        addBack(root);
        break;
        case 4:
        display(root);
        break;
        case 5:
        return 0;
        default:
        return 0;
    }
    }
}
void create(node_t *root,int num)
{
    int i=3;
    node_t *current=(node_t*)malloc(sizeof(node_t));
    printf("Enter Element 2:");
    scanf("%d",&current->data);
    current->link=NULL;
    root->link=current;
    while(i<=num)
    {
        node_t *node=(node_t*)malloc(sizeof(node_t));
        printf("Enter Element %d:",i);
        scanf("%d",&node->data);
        node->link=NULL;
        current->link=node;
        current=node;
        i++;
    }
}
int display(node_t *root)
{
    if(root==NULL)
    {
        printf("List is Empty\n");
        return 1;
    }
    node_t *temp=root;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("NULL\n");
    return 0;
}
void addBack(node_t *root)
{
    node_t *node=(node_t *)malloc(sizeof(node_t));
    printf("Enter Element to Add End of the List:");
    scanf("%d",&node->data);
    node->link=NULL;
    node_t *temp=root;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=node;
}
void addFront(node_t **root)
{
    node_t *node=(node_t *)malloc(sizeof(node_t));
    printf("Enter the Element to Add Begining of the List:");
    scanf("%d",&node->data);
    node->link=*root;
    *root=node;
}
