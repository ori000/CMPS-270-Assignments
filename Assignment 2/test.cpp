#include <iostream>

template <typename T>
struct treeNode 
{
    T data;
    struct treeNode * left;
    struct treeNode * right;

    treeNode(T value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
template<class T>
class binaryTree
{
    treeNode root;

    treeNode addNodes(T value, treeNode current)
    {
        if(current == NULL)
            current = new treeNode(value);
        else if(value > current.data)
            current.right = addNodes(value, root.right);
        else if(value < current.data)
            current.left = addNodes(value, root.left);
        return current;
    }
};

int main()
{
    treeNode node = new treeNode(10);
    treeNode node2 = new treeNode(15);
    treeNode node3 = new treeNode(5);

    std::cout << node.data;

    return 0;
}
