#include "printauto.hpp"
#include "foldtraverse.hpp"

void PrintAuto()
{
    std::cout << "\nPrintAuto:\n";

    print("Hello", "world", "!");
    print<','>("Hello", "world", "!");
    print<'\n'>("Hello", "world", "!");
    print<'-'>(7.5, "Hello", "world", 2, "!");
}

void FoldTraverse()
{
    std::cout << "\nFoldTraverse:\n";

    auto root = MakeNode(0);
    auto root1 = root->subLeft = MakeNode(1);
    auto root3= root->subRight = MakeNode(3);
    auto root5 = root->subRight->subLeft = MakeNode(5);
    auto root7 = root->subRight->subLeft->subLeft = MakeNode(7);
    auto root6 = root->subRight->subRight = MakeNode(6);
    auto root4 = root->subLeft->subLeft = MakeNode(4);
    auto root2 = root->subLeft->subRight = MakeNode(2);

    auto node = Node<int>::traverse(root, Node<int>::left, Node<int>::right);
    std::cout << "traverse result: " << node->GetValue() << '\n';

    node = root->*Node<int>::left->*Node<int>::right;
    std::cout << "traverse result: " << node->GetValue() << '\n';

    node = root->subLeft->subRight;
    std::cout << "traverse result: " << node->GetValue() << '\n';

    auto node2 = Node<int>::traverse(root, Node<int>::right, Node<int>::left, Node<int>::left);
    std::cout << "traverse result node2: " << node2->GetValue() << '\n';
}

int TemplateMain()
{
    PrintAuto();
    FoldTraverse();
    return 0;
}