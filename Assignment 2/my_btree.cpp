#include <iostream>

using namespace std;

/*
TEST CASES

TEST CASE 1: Empty Tree with no root node
TEST CASE 2: Tree with only the root node
TEST CASE 3: Tree with a root and two direct children (left & right)
TEST CASE 4: Tree with only left children
TEST CASE 5: Tree with only right children
TEST CASE 6: Tree with only left and right children (Inverse V shape)
TEST CASE 7: Tree with no data values (neither int nor char)
TEST CASE 8: Tree with all nodes having two children
TEST CASE 9: Tree with all nodes having two children except for a left node with one child
TEST CASE 10:Tree with all nodes having two children except for a right node with one child
TEST CASE 11:Tree with only one branch children (left, right, left, right, etc.)
TEST CASE 12:Tree with all nodes having two children except for a right node with one child and a left node with one child (in another subtree)

*/

template <typename T>
struct treeNode 
{

T *data;
struct treeNode * left;
struct treeNode * right;

};

/*
Requires: nothing

Effects: add a new node with data based on parameter preference
*/
void addNode(struct treeNode<T>* root, struct treeNode<T> node)
{
    if(root->left == nullptr && root->right == nullptr)
        root->left = new node;
    else if(root ->left == nullptr && root->right != nullptr)
        root->left = new node;
    else if(root ->left != nullptr && root->right == nullptr)
        root->right = new node;
    else
    {
        addNode(root->left);
        addNode(root->right);
    }
}

/*
Requires: nothing

Effects: delete ANY node that has no children (leaf node)
*/
void deleteNode(struct treeNode<T>* root)
{
    if(root == nullptr)
        return;
    else if(root->left == nullptr && root->right == nullptr)
        delete root;
    else
    {
        deleteNode(root->left);
        deleteNode(root->right);
    }
}

/*
Requires: nothing

Effects: calculate and return tree size recursively
*/
int treeSize(struct treeNode<T>* root)
{
    if(root != nullptr && root->data != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}

/*
Requires: valid data parameter

Effects: calculate and return the size of subtree recursively
*/
int subtreeSize(struct treeNode<T>* root, T data)
{
    if(root != nullptr && root->data = data)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    else
    {
        countnodes(root->left);
        countnodes(root->right);
    }
    return count;
}

/*
Requires: nothing

Effect: print the values of each node in post order format
*/
void postOrderPrint(struct treeNode<T>* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    printf("%d ", node->data);
}

/*
Requires: nothing

Effect: print the values of each node in pre order format
*/
void preOrderPrint(struct treeNode<T>* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    printf("%d ", node->data);
 
    /* then recur on left subtree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}

/*
Requires: nothing

Effect: print the values of each node in inOrder format
*/
void inOrderPrint(struct treeNode<T>* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder(node->right);
}

//this function will return the new node with the given value
struct node *getNewNode(int val)
{
    struct node *newNode = new node;
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val)
{
    /*
     * It will handle two cases,
     * 1. if the tree is empty, return new node in root
     * 2. if the tree traversal reaches NULL, it will return the new node
     */
    if(root == NULL)
        return getNewNode(val);
    /*
     * if given val is greater than root->key,
     * we should find the correct place in right subtree and insert the new node
     */
    if(root->left == nullptr && root-> right == nullptr)
        root->left = insert(root->left,val);
    /*
     * if given val is smallar than root->key,
     * we should find the correct place in left subtree and insert the new node
     */
    else if(root-> left == nullptr && root->right != nullptr)
        root->right = insert(root->right,val);
    
    else if(root-> left != nullptr && root->right == nullptr)
        root->left = insert(root->left,val);
    /*
     * It will handle two cases
     * (Prevent the duplicate nodes in the tree)
     * 1.if root->key == val it will straight away return the address of the root node
     * 2.After the insertion, it will return the original unchanged root's address
     */
    return root;
}
