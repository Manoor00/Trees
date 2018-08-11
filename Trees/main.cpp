#include <iostream>
#include <Tree.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Tree t;

    t.insertNode(7);
    t.insertNode(2);
    t.insertNode(18);
    t.insertNode(1);
    t.insertNode(3);
    t.insertNode(21);
    t.insertNode(19);
    t.insertNode(25);
    t.insertNode(20);
    t.insertNode(27);
    t.insertNode(23);

    t.printTree();
    t.deleteNode(1);
    t.printTree();
}
