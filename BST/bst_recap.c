#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* left;
    int data;
    struct node* right; 
};

void inorder(struct node* temp){
    if(temp!=NULL){
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}

void preorder(struct node* temp){
    if(temp!=NULL){
        printf("%d ",temp->data);
        inorder(temp->left);
        inorder(temp->right);
    }

}

void postorder(struct node* temp){
    if(temp!=NULL){
        inorder(temp->left);
        inorder(temp->right);
        printf("%d ",temp->data);
    }
}

struct node* createNode(int val){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

struct node* insert(struct node* root,int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val < root->data){
        root->left= insert(root->left,val);
    }
    else if(val > root->data){
        root->right=insert(root->right,val);
    }

    return root;

}

int main(){
    struct node* root=NULL;
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,5);
    root=insert(root,100);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
}