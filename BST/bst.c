// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left , *right;
};

struct node* createNode(int val){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void inorder(struct node* root){

    if(root!=NULL){
        inorder(root->left);
        printf("%d -> ",root->data);
        inorder(root->right);
    }

}

void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

struct node* insert(struct node* root,int val){
    if(root==NULL){
       return createNode(val);
    }
    


    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else if(val> root->data) {
        root->right=insert(root->right,val);
    }
    
    return root;

}

struct node* search(struct node* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }

    if (val < root->data) {
        return search(root->left, val);
    } 
    else {
        return search(root->right, val);
    }
}   

struct node* minNode(struct node* root){
    struct node* temp=root;
     while(temp->left!=NULL && temp!=NULL){
        temp=temp->left;
     }

     return root;   
}

struct node* delete(struct node* root , int val){
    if(root==NULL) return root;

    else if(val < root->data){
        root->left=delete(root->left,val);
    }
    else if(val > root->data){
        root->right=delete(root->right , val);
    }

    else{
        if(root->left==NULL){
            struct node* temp1=root->right;
            free(root);
            return temp1;
        }

        else if(root->right==NULL){
            struct node* temp2=root->left;
            free(root);
            return temp2;
        }

        struct node* temp=minNode(root->right);
        root->data=root->data;
        root->right=delete(root->right,val);
    }
    return root;
}

int main() {
    struct node* root=NULL;
    root = insert (root, 9);
    insert (root, 7);
    insert (root, 5);
    insert (root, 8);
    insert (root, 14);
    insert (root, 11);
    insert (root, 16);
    insert(root,90);
    insert(root,80);
    insert(root,100);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    int find=9;
    struct node* result=search(root,find);
    printf("\n");
    if(result!=NULL){
        printf("%d is found ",find);
    }
    else printf("Not found");
    printf("\n");
    delete(root ,8);
    inorder(root);
    

    return 0;
}