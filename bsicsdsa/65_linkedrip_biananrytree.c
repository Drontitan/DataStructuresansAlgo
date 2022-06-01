#include <stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *left;
    struct node *right ;
};
struct node * createnode (int data){
    struct node *n;// creating the node pointer 
    n = (struct node *)malloc(sizeof(struct node));// allocating the memory in the heap 
    n->data = 2;// setting the data
    n->left = NULL;// setting the left and right children to null
    n->right = NULL; // setting the left and right children to null
    return n;// finally returning the second node 
}
int main(){
   /*
    // constructing the root node
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;
    // constructing the second node
    struct node * p1;
    p1 =  (struct node *)malloc(sizeof( struct node));
    p1->data = 1;
    p1->left= NULL;
    p1->right= NULL;
   // constructing the third node
    struct node * p2;
    p2 =  (struct node *)malloc(sizeof( struct node));
    p2->data = 4;
    p2->left= NULL;
    p2->right= NULL;
  // linking the root node with left and children
    p->left = p1;
    p->right = p2;
    struct node *p1;
    */
   // constructing the root node -using the function 
   struct node *p =createnode(2);
   struct node *p1 =createnode(1);
   struct node *p2=createnode(4);

   //linking the root node with left and right children
   p->left = p1;
   p->right = p2;

   return 0;
}