#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int data;
    struct NODE *link; 
}node_t;
void create(node_t *,int);
int addFront(node_t **);
int addBack(node_t **);
int display(node_t *);
int insert(node_t **);
int delFront(node_t **);
int delBack(node_t **);
int delByPos(node_t **);
int search(node_t *);
int main()
{
    int num,option;
    node_t *root=NULL;
    while(1)
    {
    printf("1.Create 2.Add Front 3.Add Back 4.Display 5.Insert by Position 6.Del Front 7.Del Back 8.Del by Position 9.Search 10.Exit:");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        root=(node_t*)malloc(sizeof(node_t));
        printf("Enter Element No(Min 02):");
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
        addBack(&root);
        break;
        case 4:
        display(root);
        break;
        case 5:
        insert(&root);
        break;
        case 6:
        delFront(&root);
        break;
        case 7:
        delBack(&root);
        break;
        case 8:
        delByPos(&root);
        break;
        case 9:
        search(root);
        break;
        case 10:
        return 0;
        break;
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
    int count=0;
    if(root==NULL)
    {
        printf("List is Empty\n");
        return count;
    }
    node_t *temp=root;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
        count++;
    }
    printf("NULL\n");
    return count;
}
int addBack(node_t **root)
{
    node_t *node=(node_t *)malloc(sizeof(node_t));
    printf("Enter Element to Add End of the List:");
    scanf("%d",&node->data);
    node->link=NULL;
    if(*root==NULL)
    {
      *root=node;
      return 1;
    }
    node_t *temp=*root;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=node;
    return 0;
}
int addFront(node_t **root)
{
  node_t *node=(node_t *)malloc(sizeof(node_t));
  printf("Enter the Element to Add Begining of the List:");
  scanf("%d",&node->data);
  if(*root==NULL)
  {
    *root=node;
    return 1;
  }
  node->link=*root;
  *root=node;
  return 0;
}
int insert(node_t **root)
{
    int count=display(*root);
    int pos,i;
    int element;
    if(count==0)
    {
        return 0;
    }
    printf("Enter Position to insert(index from 1):");
    scanf("%d",&pos);
    if(pos>count+1||pos<1)
    {
        printf("Enter Valid Position\n");
    }
    else
    {
        if(pos==1)
        {
            addFront(root);
        }
        else if(pos==count+1)
        {
            addBack(root);
        }
        else
        {
            printf("Enter Element to insert at %d Position:",pos);
            scanf("%d",&element);
            node_t *node=(node_t *)malloc(sizeof(node_t));
            node->data=element;
            node->link=NULL;
            node_t *temp=*root;
            for(i=1;i<pos-1;i++)
            {
                temp=temp->link;
            }
            node->link=temp->link;
            temp->link=node;
        }
    }   
    return 0;
}
int delFront(node_t **root)
{
  if(*root==NULL)
  {
    printf("List is Empty\n");
    return 1;
  }
  node_t *temp=*root;
  *root=(*root)->link;
  free(temp);
  temp=NULL;
  return 0;
}
int delBack(node_t **root)
{
  if(*root==NULL)
  {
    printf("List is Empty\n");
    return 1;
  }
  else if((*root)->link==NULL)
  {
    free(*root);
    *root=NULL;
    return 1;
  }
  else
  {
  node_t *temp=*root;
  node_t *temp2=NULL;
  while(temp->link!=NULL)
  {
    temp2=temp;
    temp=temp->link;
  }
  temp2->link=NULL;
  free(temp);
  temp=NULL;
  }
  return 0;
}
int search(node_t *root)
{
  if(root==NULL)
  {
    printf("List is Empty\n");
    return 1;
  }
  int element;
  int found=0;
  printf("Enter Element to Search in the List:");
  scanf("%d",&element);
  node_t *temp=root;
  while(temp!=NULL)
  {
    if(temp->data==element)
    {
      printf("Element Found\n");
      found=1;
      break;
    }
    temp=temp->link;
  }
  if(!found)
  {
    printf("Element Not Found\n");
  }
  return 0;
}
int delByPos(node_t **root)
{
  int i,pos,count=display(*root);
  if(*root==NULL)
  {
    printf("List is Empty\n");
    return 1;
  }
  printf("Enter the Postion to Delete:");
  scanf("%d",&pos);
  if(pos>count||pos<1)
  {
    printf("Enter Valid Position !\n");
    return 1;
  }
  else if(pos==count&&pos!=1)
  {
    delBack(root);
  }
  else if(pos==1)
  {
    delFront(root);
  }
  else
  {
    node_t *node=*root;
    node_t *pnode=NULL;
    for(i=1;i<pos;i++)
    { 
      pnode=node;
      node=node->link;
    }
    pnode->link=node->link;
    free(node);
    node=NULL;
  }
  return 0;
}
