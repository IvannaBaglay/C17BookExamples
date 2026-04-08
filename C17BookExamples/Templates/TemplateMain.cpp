#include "printauto.hpp"
#include "foldtraverse.hpp"

void PrintAuto()
{
    print("Hello", "world", "!");
    print<','>("Hello", "world", "!");
    print<'\n'>("Hello", "world", "!");
    print<'-'>(7.5, "Hello", "world", 2, "!");
}

void FoldTraverse()
{
    Node<int>* root = new Node<int>{ 0 };
    Node<int>* root1 = root->subLeft = new Node<int>{ 1 };
    Node<int>* root3= root->subRight = new Node<int>{ 3 };
    Node<int>* root5 = root->subRight->subLeft = new Node<int>{ 5 };
    Node<int>* root7 = root->subRight->subLeft->subLeft = new Node<int>{ 7 };
    Node<int>* root6 = root->subRight->subRight = new Node<int>{ 6 };
    Node<int>* root4 = root->subLeft->subLeft = new Node<int>{ 4 };
    Node<int>* root2 = root->subLeft->subRight = new Node<int>{ 2 };

    Node<int>* node = Node<int>::traverse(root, Node<int>::left, Node<int>::right);
    std::cout << "traverse result: " << node->GetValue() << '\n';

    node = root->*Node<int>::left->*Node<int>::right;
    std::cout << "traverse result: " << node->GetValue() << '\n';

    node = root->subLeft->subRight;
    std::cout << "traverse result: " << node->GetValue() << '\n';

    Node<int>* node2 = Node<int>::traverse(root, Node<int>::right, Node<int>::left, Node<int>::left);
    std::cout << "traverse result node2: " << node2->GetValue() << '\n';
}

int TemplateMain()
{
    //PrintAuto();
    FoldTraverse();
    return 0;
}