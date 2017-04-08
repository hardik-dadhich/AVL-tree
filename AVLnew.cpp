//Avl tree code...


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node 
 {
 	struct node *left,*right;
 	int key;
 	int height;
 	
 };
 int max(int a,int b)
   {
     	 return (a>b) ? a:b;
   }
   int height(struct node *node)
       {
       	if(node ==NULL)
       	 return 0;
       	 return node->height;
       	
       }
       struct node *rotateRight(struct node *y)
          {
          	  struct Node *x = *y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;

          	
          	
          	
          }
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
   struct node *newNode(int key)
      {
      	 struct node *node=(struct node *)malloc(sizeof(struct node));
      	 node->key=key;
      	 node->left=NULL;
      	 node->right=NULL;
      	 node->height=1;
      	 return node;
      }
     int getbalance(struct node *N)
        {
          if(N ==NULL)
		  return NULL;
		  return height(N->left)- height(N->right);	
        }
   struct node *insert(struct node *node,int key)
      
      {
      	  //if the node is fresh or new..
      	if(node ==NULL) 
      	{
      		return newNode(key);
      		
      	}
         else
         {
         	if(key < node->key)    
         	  {
         	  	node->left=insert(node->left,key);
         	  	
         	  }
         	  else if( key > node->key)
         	    {
         	    	node->right=insert(node->right,key);
         	    	
         	    	
         	    }
         	
         	else   // because equal value not considerd in AVL
         	{
         		return node;
         	
			}
			//update node hight
			 node->height=1 + max(height(node->left),height(node->right));
			 //cheak balance factore!!!
			 int balance=getbalance(node);
			 
			 //according to height there are 4 cases
			 
         	if(balance > 1 && key < node->left->key)// right rotation
         	return rotateRight(node);
         	if(balance < -1 && key >node->right->key)   //left rotation
         	return leftRotate(node);
          	if(balance > 1 && key > node->left->key)   //left ->right rotation
         	node->left=leftRotate(node->left);
         	return leftRotate(node);
         	if(balance < -1 && key <node->right->key)   //right->left rotation
         	node->right=rotateRight(node->right);
			 return rotateRight(node);         	
         	
         }
      	
      	
      	
      	return node;   	
      }
      void preorder(struct node *node)
        {
        	while(node!=NULL)
        	  {
        	  	printf("---->%d",node->key);
        	  	preorder(node->left);
        	  	preorder(node->right);
        	  }
        }
int main()
    {
    	struct node *root=NULL;
         root=insert(root,10);
		 root=insert(root,20);
		 root=insert(root,30);
		 root=insert(root,40);
		 root=insert(toot,50);
		 root=insert(root,25);
		 printf("your avl tre is\n");
		  preorder(root);	
    	
    }
