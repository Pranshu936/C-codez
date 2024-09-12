// the very basic functionality of a binary search tree is all the elements which are associated in a left subtree are smaller than root mean while all the elements associated in the right subtree greater than root.
#include<stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int Data) {
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode->data = Data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}

int max(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}

int tree_height( struct Node* root) {
    if (root == NULL) 
        return 0;
    else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        int h=max(left_height, right_height)+1;
        return h;
    }
}

struct Node* insert(struct Node* root, int Data) {
    if (root == NULL) {
        return createNode(Data);
    }
    if (Data < root->data) {
        root->left = insert(root->left, Data);
    } else {
        root->right = insert(root->right, Data);
    }
    return root;
}

int min(struct Node* root){
  struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
  temp=root;
  while(temp->left!=NULL){
    temp=temp->left;
  }
  int x=temp->data;
  return x;
}

struct Node* delNode(struct Node* root, int x) {
    if (root == NULL){
        return root;
    }  
    if (root->data > x){
        root->left = delNode(root->left, x);
    }
    else if (root->data < x){
        root->right = delNode(root->right, x);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
    struct Node* temp=min(root->right);
    root->data=temp->data;
    root->right=delNode(root->right,temp->data);
    }
    return root;
}

int main(){
    struct Node* root = createNode(3);
    // root->left=createNode(10);
    // root->right=createNode(20);
    // root->left->left=createNode(9);
    // root->left->right=createNode(11);
    // root->right->left=createNode(19);
    // root->right->right=createNode(24);
    insert(root,1);
    insert(root,7);
    insert(root,5);
    insert(root,4);
    // insert(root,6);
    // insert(root,7);
    //inorder(root);
    //delNode(root,11);
    //inorder(root);
    int y=tree_height(root);
    int hi=y-1;
    printf("%d",hi);
    return 0;
}
