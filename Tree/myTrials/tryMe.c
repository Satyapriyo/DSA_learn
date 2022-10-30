#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node* left,*right;
};
struct node* newNode(int data){
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->left=NULL;
    t->key= data;
    t->right=NULL;
    return t;
}
struct node* insert(struct node* root,int key){
    if(root==NULL){
        return newNode(key);
    }
    else{
        if(key>root->key){
            root->right = insert(root->right,key);
        }
        else if(key<root->key){
            root->left =insert(root->left,key);
        }
        return root;
    }
}
struct node* inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}
int search(struct node* root,int key){
    if(root==NULL || root->key ==key)
        return 1;
    if(root->key <key)
        search(root->left,key);
    search (root->right,key);
}
int main(){
    struct node* root =NULL;
    root = insert(root,50);
    insert(root,10);
    insert(root,80);
    insert(root,40);
    insert(root,20);
    insert(root,70);
    inorder(root);
    if(search(root,20))
        printf("\nfound " );
    else
        printf("\n not found " );

    return 0;
}