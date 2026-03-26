#include <iostream>
#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <string>

int main() {
    int rootVal = 50;
    Tree<int> tree(rootVal);

    int values[] = {30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    for (int v : values) {
        tree.insertNode(v);
    }
    tree.levelOrder();
    return 0;
}
