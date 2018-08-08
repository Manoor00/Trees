#include "Tree.h"
using namespace std;

Tree::Tree()
{
    root = NULL;
    //ctor
}

Tree::~Tree()
{
    root = NULL;
    //dtor
}

Tree::Tree(const Tree& other)
{
    //copy ctor
}

Tree& Tree::operator=(const Tree& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Tree::printTree(NODE *node)
{
    if(node == NULL)
        return;
    printTree(node->lLink);
    cout<<node->data<<" ";
    printTree(node->rLink);

}
void Tree::printTree()
{
    printTree(root);
    cout<<endl;

}
NODE* Tree::searchNode(int data, NODE **parentNode)
{
    NODE *curNode = root;

    while(curNode != NULL)
    {
        if(curNode->data == data)
        {
            cout<<"Node found"<<endl;
            return curNode;
        }
        else
        {
            if(parentNode != NULL)
                *parentNode = curNode;
            if(curNode->data > data)
                curNode = curNode->lLink;
            else
                curNode = curNode->rLink;
        }
    }
    cout<<"Node not found"<<endl;
    return NULL;
}

void Tree::insertNode(int data)
{
    cout<<"insertingNode "<<data<<endl;
    NODE *dataNode = new NODE(data);
    if(root == NULL)
    {
        cout<<"inserting root"<<endl;
        root = dataNode;
        return;
    }
    else
    {
        NODE* cur = root, *prev = NULL;
        while(cur != NULL)
        {
            prev = cur;
            if(cur->data < data)
            {
                cur = cur->rLink;
            }
            else
            {
                cur = cur->lLink;
            }
        }

        if(prev->data > data)
            prev->lLink = dataNode;
        else
            prev->rLink = dataNode;
    }
}

void Tree::deleteNode(int data)
{
    NODE *nodeToBeDeleted = NULL, *nodeToBeDeletedParent = NULL;
    nodeToBeDeleted= searchNode(data, &nodeToBeDeletedParent);
    if(nodeToBeDeleted == NULL)
    {
        cout<<"Node not found"<<endl;
        return;
    }

    NODE* nodeWhichWillReplace = NULL, *nodeWhichWillReplaceParent = NULL;
    nodeWhichWillReplace = inOrderSuccessor(nodeToBeDeleted, &nodeWhichWillReplaceParent);

    //Node is a leaf Node or has no in order successors like a node with only left Link
    if(nodeWhichWillReplace == NULL)
    {
        cout<<"Node to deleted has the rSubtree as empty"<<endl;

        //Leaf Node with parent
        if(nodeToBeDeletedParent != NULL)
        {
            //ita right leaf Node which is being deleted. so rLink of the parent should be NULL
            if(nodeToBeDeletedParent->rLink == nodeToBeDeleted)
                nodeToBeDeletedParent->rLink = NULL;
            // Node to be deleted is Left leaf node, or Its a node which has no rLink but only left childs.
            // In this case the l child of the parent of the node being deleted should point to the left child of the
            //node being deleted. if the node being deleted as no left child then it'll be NULL which also taken care by
            //this statement
            else
                nodeToBeDeletedParent->lLink = nodeToBeDeleted->lLink;
        }
        else
        {
            cout<<"Node to be deleted is the root";
            root = NULL;
        }
        delete nodeToBeDeleted;
    }
    else
    {
        cout<<"In Order successor = "<<nodeWhichWillReplace->data<<endl;
        cout<<"replacing the inorder successor of the deleted node"<<endl;

        //Moving the node to its new position so re-establish the links
        if(nodeWhichWillReplaceParent != NULL)
        {
            cout<<"1"<<endl;
            //If the node being deleted is the same as the parent of the inOrder successor
            //If we dont do this then, in the below step of assigning rLink of the ReplacedNode with the deleted node rlink, will point to itself.
            if(nodeWhichWillReplaceParent->rLink == nodeWhichWillReplace)
            {
                cout<<"11"<<endl;
                nodeWhichWillReplaceParent->rLink = nodeWhichWillReplace->rLink;
            }
            //node being deleted is some other Node which has no left child's so this Node's parent should point to its r child
            else
            {
                cout<<"12"<<endl;
                nodeWhichWillReplaceParent->lLink = nodeWhichWillReplace->rLink;
            }
        }
        //restablishing the links of the deleted node.
        if(nodeToBeDeletedParent != NULL)
        {
            cout<<"2"<<endl;
            // we are deleting the r child, so assign the parent node r child to inOrder successor
            if(nodeToBeDeletedParent->rLink == nodeToBeDeleted)
            {
                    cout<<"21"<<endl;
                    nodeToBeDeletedParent->rLink = nodeWhichWillReplace;
            }
            // we are deleting the l child, so assign the parent node l child to inOrder successor
            else
            {
                cout<<"23"<<endl;
                nodeToBeDeletedParent->lLink = nodeWhichWillReplace;
            }
        }

        //Now assign the deleted node's link to the replaced Nodes.
        if(nodeToBeDeleted->rLink == nodeWhichWillReplace)
        {
            cout<<"3"<<endl;
            nodeWhichWillReplace->rLink = NULL;
            nodeWhichWillReplace->lLink = nodeToBeDeleted->lLink;

        }
        else
        {
            cout<<"4"<<endl;
            nodeWhichWillReplace->rLink = nodeToBeDeleted->rLink;
            nodeWhichWillReplace->lLink = nodeToBeDeleted->lLink;
        }
        if(nodeToBeDeleted == root)
            root = nodeWhichWillReplace;

        delete nodeToBeDeleted;
    }
}

NODE* Tree::inOrderSuccessor(NODE* nodeToBeDeleted, NODE ** nodeWhichWillReplaceParent)
{
    NODE* current = nodeToBeDeleted->rLink;
    *nodeWhichWillReplaceParent = NULL;

    if(current == NULL)
    {
        cout<<"rightSubtree is NULL"<<endl;
        return NULL;
    }
    *nodeWhichWillReplaceParent = nodeToBeDeleted;
    while(current->lLink != NULL)
    {
        *nodeWhichWillReplaceParent = current;
        current = current->lLink;
    }

    return current;
}
