#include <iostream>
#include <typeinfo>
#include <cstring>

/*
TEST CASES

TEST CASE 1: Empty Tree with no root node	=> checked
TEST CASE 2: Tree with only the root node	=> checked
TEST CASE 3: Tree with a root and two direct children (left & right)	=> checked
TEST CASE 4: Tree with only left children	=> checked (Impossible due to requested method description)
TEST CASE 5: Tree with only right children	=> checked (Impossible due to requested method description)
TEST CASE 6: Tree with only left and right children (Inverse V shape)	=> checked
TEST CASE 7: Tree with no data values (neither int nor char)			=> checked (Impossible due to requested method description) / works as an empty tree with no nodes
TEST CASE 8: Tree with all nodes having two children					=> checked (Impossible due to requested method description)
TEST CASE 9: Tree with all nodes having two children except for a left node with one child	=> checked
TEST CASE 10:Tree with all nodes having two children except for a right node with one child	=> checked
TEST CASE 11:Tree with only one branch children (left, right, left, right, etc.)			=> checked
TEST CASE 12:Tree with all nodes having two children except for a right node with one child and a left node with one child (in another subtree)	=> checked

*/

template<class T>
struct treeNode 
{
	T data;
	treeNode* left;
	treeNode* right;

	treeNode(T value)
	{
		data = value;
		left = nullptr;
		right = nullptr;
	}
};
template<class T>
class binaryTree 
{
private:
	treeNode<T>* root;

	treeNode<T>* addNode(T value, treeNode<T>* current)
	{
		if (current == nullptr)
			current = new treeNode<T>(value);
		else if (current->left == nullptr && current->right != nullptr || (current->left == nullptr && current->right == nullptr))
			current->left = addNode(value, current->left);
		else if ((current->left != nullptr && current->right == nullptr))
			current->right = addNode(value, current->right);
		else if(current->left != nullptr && current->right != nullptr)
			current->left = addNode(value, current->left);
		return current;
	}
	void printPreOrder(treeNode<T>* root)
	{
		if (root == NULL)
			return;
		std::cout << root->data << std::endl;
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
	void printPostOrder(treeNode<T>* root)
	{
		if (root == NULL)
			return;
		printPostOrder(root->left);
		printPostOrder(root->right);
		std::cout << root->data << std::endl;
	}
	void printInOrder(treeNode<T>* root)
	{
		if (root == NULL)
			return;
		printInOrder(root->left);
		std::cout << root->data << std::endl;
		printInOrder(root->right);
	}
	int treeSize(treeNode<T>* root)
	{
		if (root == NULL)
			return 0;
		else
			return 1 + (treeSize(root->left) + treeSize(root->right));
	}
	int subTreeSize(treeNode<T>* root, T value, bool check)
	{
		if (root == NULL)
			return 0;
		else if (root->data == value || check == true)
		{
			check = true;
			return 1 + (subTreeSize(root->left, value, check) + subTreeSize(root->right, value, check));
		}
		else if (root->data < value)
			return subTreeSize(root->right, value, check);
		else if (root->data > value)
			return subTreeSize(root->left, value, check);
	}
	treeNode<T>* deleteNode(treeNode<T>* current, T value)
	{
		if (current == NULL)
			return NULL;
		if (current->left == NULL && current->right == NULL && current->data == value)
		{
			free(current);
			return NULL;
		}
		else if ((current->left != NULL || current->right != NULL) && current->data == value)
			std::cout << "CANNOT DELETE NODE" << std::endl;
		current->left = deleteNode(current->left, value);
		current->right = deleteNode(current->right, value);
		return current;
	}
public:
	binaryTree()
	{
		root = NULL;
	}
	void addNode(T value)
	{
		if (std::strcmp(typeid(value).name(), "int") || std::strcmp(typeid(value).name(), "char"))
			root = addNode(value, root);
		else std::cout << "Invalid Type: Value should be an int or char." << std::endl;
	}
	int treeSize()
	{
		return treeSize(root);
	}
	int subTreeSize(T value, bool check)
	{
		if (std::strcmp(typeid(value).name(), "int") || std::strcmp(typeid(value).name(), "char"))
			return subTreeSize(root, value, check);
		else std::cout << "Invalid Type: Value should be an int or char." << std::endl;
	}
	void deleteNode(T value)
	{
		if (std::strcmp(typeid(value).name(), "int") || std::strcmp(typeid(value).name(), "char"))
			root = deleteNode(root, value);
		else std::cout << "Invalid Type: Value should be an int or char." << std::endl;
	}
	void printPreOrder()
	{
		printPreOrder(root);
	}
	void printPostOrder()
	{
		printPostOrder(root);
	}
	void printInOrder()
	{
		printInOrder(root);
	}
};

int main() 
{
	binaryTree<int> node;
	binaryTree<char> node2;
	binaryTree<int> node3;
	node2.addNode('a');
	node2.printPreOrder();
	node3.printPreOrder();

	node.addNode(10);
	node.addNode(5);
	node.addNode(20);
	node.addNode(25);
	node.addNode(15);

	
	node.printPreOrder();
	//node.printPostOrder();
	
	//node2.printPostOrder();
	//node2.printInOrder();
	
	
	std::cout << node.treeSize() << std::endl;
	node.deleteNode(10);
	//node.deleteNode(';');
	//node.deleteNode('b');
	node.deleteNode('F');
	//node.printPreOrder();
	std::cout << node.treeSize() << std::endl;
	
	std::cout << node.subTreeSize(20, false) << std::endl;

	//return 0;
}