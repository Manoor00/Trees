#ifndef TREE_H
#define TREE_H
#include <iostream>

using namespace std;

class NODE
{
public:
    NODE *rLink;
    int data;
    NODE *lLink;
    NODE(int d = 0)
    {
        //cout<<"NewNode"<<endl;
        rLink = NULL;
        data = d;
        lLink = NULL;
    }
};
class Tree
{
private:
    NODE * root;
    public:
        Tree();
        virtual ~Tree();
        Tree(const Tree& other);
        Tree& operator=(const Tree& other);
        void printTree(NODE* node);
        void printTree();
        void insertNode(int data);
        NODE* searchNode(int data, NODE**parent = NULL);
        void deleteNode(int data);
        NODE* inOrderSuccessor(NODE* nodeToBeDeleted, NODE ** nodeWhichWillReplaceParent);

    protected:

    private:
};

#endif // TREE_H
