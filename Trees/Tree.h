#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

enum {
    BINARY_TREE,
    BINARY_SEARCH_TREE
}TYPE_OF_TREE;



class Tree
{
private:
    TYPE_OF_TREE typeOfTree_;
    NODE* head;

    public:
        Tree(TYPE_OF_TREE treeType)
        {
            typeOfTree_ = treeType;
            head = NULL;
        }

    bool insertNode(int data);
    bool deleteNode(int data);
    bool findNode(int data);

};

#endif // TREE_H_INCLUDED
