#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COUNT 5

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}node;

node* root=NULL;

int max(int a,int b){
	return (a>b)?a:b;
}

/*Function for node creation*/

node* createNode(int data){
	node * leaf=(node*)malloc(sizeof(node));
	leaf->left=NULL;
	leaf->right=NULL;
	leaf->data=data;
	return leaf;
}


/*Auxillary functions for Trees*/

node* findmax(node* temp){
	
	if(temp->right==NULL){
		return temp;
	}
	findmax(temp->right);
}

node* findmin(node* temp){
	if(temp->left==NULL){
		return temp;
	}
	findmax(temp->left);
}

int countParents(node* temp){
	if(temp==NULL){
		return 0;
	}
	 if(temp->right==NULL && temp->left==NULL){
		return 0;
	}
	else{
		return countParents(temp->right)+countParents(temp->left)+1;
	}
	
}

int countLeaves(node*temp){
	if(temp==NULL){
		return 0;
	}
	 if(temp->right==NULL && temp->left==NULL){
		return 1;
	}
	return countLeaves(temp->left)+countLeaves(temp->right);
	
}
/*
similar issues trash code/optimise later ...
int countParents_iter(node* temp){
	if(root==NULL){
		return 0;
	}
	int c=0;
	while(temp->right!=NULL){
		temp=temp->right;
		c++;
	}
	temp=root;
	while(temp->left!=NULL){

		temp=temp->left;
		c++;
	}
	return c;
}
*/
/*Insertion recursively and iteratively */

node* insert(node* temp,int data){
	if(root==NULL){
		root=createNode(data);
		return root;
	}
	else if(temp==NULL){
		temp=createNode(data);
		return temp;
	}
	if (temp->data>data){
		temp->left=insert(temp->left,data);
	}
	else if(temp->data<data){
		temp->right=insert(temp->right,data);
	}
	return temp;
}

void insert_iter(node* temp,int data){
	node* parent=NULL;
	if(root==NULL){
		root=createNode(data);
		return;
	}
	while(temp!=NULL){
		parent=temp;
			if(temp->data<data){
				temp=temp->right;

			}
			else{
				temp=temp->left;
			}
		}
	if(parent->data<data){
		parent->right=createNode(data);
	}
	else{
		parent->left=createNode(data);
	}
}
/*
iterative delete hv to try someother time .issues persist here.trashy code
node* delete(node* temp,int data){
	if(root==temp){
		root=NULL;
		return NULL;
	}
	node* parent=NULL;

	while(temp!=NULL){
		parent=temp;
		if(temp->data>data){
			temp=temp->left;
		}
		else {
			temp=temp->right;
		}
	}
	if(temp->left==NULL ||temp->right==NULL){
		node* new;
		if(temp->left==NULL){
			new=temp->right;
		}
		else{
			new=temp->left;
		}
		if (parent==NULL){
			return new;
		}
		if(temp=parent->left){
			parent->left=new;

		}
		else{
			parent->right=new;
		}
		//free(temp);
	}
	else{
		node* max=findmax(temp->left);
		temp=max;

	}
	return temp;
}
*/
/*recursive Function for deletion of a node*/

node* delete(node*temp,int data){
	if(temp==NULL){
		return NULL;
	}
	if(data<temp->data){
		temp->left=delete(temp->left,data);
	}
	else if(data>temp->data){
		temp->right=delete(temp->right,data);
	}
	else{
		if(temp->left==NULL && temp->right==NULL){
			return NULL;
		}
		else if(temp->left==NULL){
			node* t=temp->right;
			return t;
		}
		else if(temp->right==NULL){
			node* t1=temp->left;
			return t1;
		}
		node* t2=findmax(temp->left);
		temp->data=t2->data;
		temp->left=delete(temp->left,temp->data);

	}
	return temp;
}



/*Find and wrapper functions*/

int find(node* temp,int data){
	
	while(temp!=NULL){
		if(temp->data<data){
			temp=temp->right;
		}
		else if(temp->data>data){
			temp=temp->left;
			
		}
		else{
			return 1;
		}
	}

	return 0;

}


void find_wrap(node* temp,int data){
	int k=find(temp,data);
	(k==1)?printf("Found\n"):printf("Not Found\n");

}

/*Height and depth of binary tree*/

int height(node* temp){
	if (temp==NULL){
		return 0;
	}
	return max(height(temp->left),height(temp->right))+1;
}

int depth(node* temp,int data){
	int i=-1;
	while(temp!=NULL){
		i++;
		if(temp->data<data){
			temp=temp->right;

		}
		else if(temp->data>data){
			temp=temp->left;
			
		}
		else{
			break;
		}
	}
	return i;
}

/*Functions for All types of traversals and printing the structure of the tree*/

void inorder(node* temp){
	if(temp==NULL){
		
		return;
	}
	inorder(temp->left);
	printf("%d\t",temp->data);
	inorder(temp->right);

}

void preorder(node* temp){
	if(temp==NULL){
		
		return;
	}
	printf("%d\t",temp->data);
	preorder(temp->left);
	preorder(temp->right);

}

void postorder(node* temp){
	if(temp==NULL){
		
		return;
	}
	
	postorder(temp->left);
	postorder(temp->right);
	printf("%d\t",temp->data);


}


void print(node* root,int space){
	if(root==NULL){
		return;
	}
	space+=COUNT;
	print(root->right,space);
	for(int i=COUNT;i<space;i++){
		printf(" ");
	}
	printf("%d\n",root->data);
	print(root->left,space);

}
/*Testing all functions */
int main(){
/*insertions*/
insert_iter(root,8);
insert_iter(root,3);
insert_iter(root,10);
insert_iter(root,14);
insert_iter(root,13);
insert_iter(root,1);
insert_iter(root,6);
insert_iter(root,4);
insert_iter(root,7);
/*Aux functions*/
node* k=findmax(root->left);
/*deletions*/
delete(root,7);
find_wrap(root,8);
printf("\n%d\n",k->data);
/*traversals*/
print(root,10);
inorder(root);
printf("\n");
preorder(root);
printf("\n");
postorder(root);
printf("\n");
printf("%d\n",height(root));
printf("%d\n",countLeaves(root));
printf("%d\n",depth(root,4));
}
