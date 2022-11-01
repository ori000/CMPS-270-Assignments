#include <iostream>
#include <typeinfo>
#include <cstring>
#include <ctime>

/*
TEST CASES

TEST CASE 1: Empty Tree with no root node	=> checked: add root: treeNode<int>
TEST CASE 2: Tree with only the root node	=> checked: add to left
TEST CASE 3: Tree with a root and two direct children (left & right)	=> checked: add arbitrarily
TEST CASE 4: Tree with only left children	=> checked (Impossible due to requested method description)
TEST CASE 5: Tree with only right children	=> checked (Impossible due to requested method description)
TEST CASE 6: Tree with only left and right children (Inverse V shape)	=> checked (Impossible due to requested method description)
TEST CASE 7: Tree with no data values (neither int nor char)			=> checked (Impossible due to requested method description) / works as an empty tree with no nodes
TEST CASE 8: Tree with all nodes having two children					=> checked (Impossible due to requested method description)
TEST CASE 9: Tree with all nodes having two children except for a left node with one child	=> checked: add leaf node
TEST CASE 10:Tree with all nodes having two children except for a right node with one child	=> checked: add leaf node
TEST CASE 11:Tree with only one branch children (left, right, left, right, etc.)			=> checked: (Impossible due to requested method description)
TEST CASE 12:Tree with all nodes having two children except for a right node with one child and a left node with one child (in another subtree)	=> checked: add leaf node

*/

template<class T>
struct treeNode 
{
	T data;
	treeNode* left;
	treeNode* right;
	/*
	REQUIRES: nothing

	EFFECTS: assigns data to input value, and left & right nodes to null
	*/
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
	/*
	REQUIRES: nothing

	EFFECTS: returns 1 if the maxdepth is through the left branching, 2 if it is through the right one
	*/
	int maxDepth(treeNode<T>* node)
	{
		if (node == NULL)
			return 0;
		else {

			int leftDepth = maxDepth(node->left);
			int rightDepth = maxDepth(node->right);

			if (leftDepth > rightDepth)
				return 1;
			else
				return 2;
		}
	}
	/*
	REQUIRES: nothing

	EFFECTS: adds either char or int nodes to the tree prioritizing adding to the left and arbitrary
	*/
	treeNode<T>* addNode(T value, treeNode<T>* current)
	{
		if (std::strcmp(typeid(value).name(), "char"))
		{
			char c = (char)value;
			if (current == nullptr)
				current = new treeNode<T>((char)c);
			else if (current->left == nullptr && current->right != nullptr || (current->left != nullptr && current->right == nullptr))
			{
				if (maxDepth(root) == 1)
					current->left = addNode(c, current->left);
				else
					current->right = addNode(c, current->right);
			}
			else if ((current->left == nullptr && current->right == nullptr))
				current->left = addNode(c, current->left);
			else if (current->left != nullptr && current->right != nullptr)
			{
				srand((unsigned)time(0));
				if (rand() % 2 == 0)
					current->left = addNode(c, current->left);
				else
					current->right = addNode(c, current->left);
			}
			return current;
		}
		else if (std::strcmp(typeid(value).name(), "int")) 
		{
			if (current == nullptr)
				current = new treeNode<T>(value);
			else if (current->left == nullptr && current->right != nullptr || (current->left != nullptr && current->right == nullptr))
			{
				if (maxDepth(root) == 1)
					current->left = addNode(value, current->left);
				else
					current->right = addNode(value, current->right);
			}
			else if ((current->left == nullptr && current->right == nullptr))
				current->left = addNode(value, current->left);
			else if (current->left != nullptr && current->right != nullptr)
			{
				srand((unsigned)time(0));
				if (rand() % 2 == 0)
					current->left = addNode(value, current->left);
				else
					current->right = addNode(value, current->left);
			}
			return current;
		}
	}
	/*
	REQUIRES: nothing

	EFFECTS: print nodes of tree in preorder
	*/
	void printPreOrder(treeNode<T>* root)
	{
		if (root == NULL)
			return;
		/*
		if (std::strcmp(typeid(root->data).name(), "char"))
		{
			char c = root->data;
			std::cout << (char)c << std::endl;
		}
		else if(std::strcmp(typeid(root->data).name(), "int"))
			std::cout << (int)root->data << std::endl;
		*/
		std::cout << root->data << std::endl;
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
		/*
	REQUIRES: nothing

	EFFECTS: print nodes of tree in postorder
	*/
	void printPostOrder(treeNode<T>* root)
	{
		if (root == NULL)
			return;
		printPostOrder(root->left);
		printPostOrder(root->right);
		std::cout << root->data << std::endl;
	}
		/*
	REQUIRES: nothing

	EFFECTS: print nodes of tree in inorder
	*/
	void printInOrder(treeNode<T>* root)
	{
		if (root == NULL)
			return;
		printInOrder(root->left);
		std::cout << root->data << std::endl;
		printInOrder(root->right);
	}
		/*
	REQUIRES: nothing

	EFFECTS: returns size of the tree
	*/
	int treeSize(treeNode<T>* root)
	{
		if (root == NULL)
			return 0;
		else
			return 1 + (treeSize(root->left) + treeSize(root->right));
	}
		/*
	REQUIRES: nothing

	EFFECTS: returns size of the subtree starting at specified input node
	*/
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
		/*
	REQUIRES: nothing

	EFFECTS: deletes the node at specified value only if it has no children
	*/
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
	/*
	REQUIRES: nothing

	EFFECTS: assigns root to null
	*/
	binaryTree()
	{
		root = NULL;
	}
		/*
	REQUIRES: private implementation

	EFFECTS: adds int or char nodes to the tree, prints invalid in case types were different
	*/
	void addNode(T value)
	{
		if (std::strcmp(typeid(value).name(), "int") || std::strcmp(typeid(value).name(), "char"))
			root = addNode(value, root);
		else std::cout << "Invalid Type: Value should be an int or char." << std::endl;
	}
		/*
	REQUIRES: private implementation

	EFFECTS: returns size of tree starting at root
	*/
	int treeSize()
	{
		return treeSize(root);
	}
		/*
	REQUIRES: private implementation

	EFFECTS: returns size of sub tree starting at given value in case it was of type int or char, print invalid otherwise
	*/
	int subTreeSize(T value, bool check)
	{
		if (std::strcmp(typeid(value).name(), "int") || std::strcmp(typeid(value).name(), "char"))
			return subTreeSize(root, value, check);
		else std::cout << "Invalid Type: Value should be an int or char." << std::endl;
	}
		/*
	REQUIRES: private implementation

	EFFECTS: ATTEMPT to delete int or char nodes at given value , print invalid if type was different
	*/
	void deleteNode(T value)
	{
		if (std::strcmp(typeid(value).name(), "int") || std::strcmp(typeid(value).name(), "char"))
			root = deleteNode(root, value);
		else std::cout << "Invalid Type: Value should be an int or char." << std::endl;
	}
		/*
	REQUIRES:  private implementation

	EFFECTS: print preorder traversal
	*/
	void printPreOrder()
	{
		printPreOrder(root);
	}
		/*
	REQUIRES:  private implementation

	EFFECTS: print postorder traversal
	*/
	void printPostOrder()
	{
		printPostOrder(root);
	}
		/*
	REQUIRES:  private implementation

	EFFECTS: print inorder traversal
	*/
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
	node.addNode('c');
	node.addNode(25);
	node.addNode(15);

	
	node.printPreOrder();
	node.printPostOrder();
	
	
	std::cout << node.treeSize() << std::endl;
	node.deleteNode(10);
	node.deleteNode(';');
	node.deleteNode(15);
	node.deleteNode('F');
	std::cout << node.treeSize() << std::endl;
	
	std::cout << node.subTreeSize(10, false) << std::endl;

	return 0;
}