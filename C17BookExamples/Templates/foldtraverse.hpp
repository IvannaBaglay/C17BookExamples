#pragma once

template<typename T>
struct Node
{
    T value;
    Node* subLeft = nullptr;
    Node* subRight = nullptr;

    Node(T i = 0)
        :value(i)
    {

    }
    T GetValue() const
    {
        return value;
    }

    // traverse helpers:
    static constexpr auto left = &Node<T>::subLeft;
    static constexpr auto right = &Node<T>::subRight;

    // traverse tree, uisng fold expression: c
    template<typename T, typename... TP>
    static Node* traverse(T np, TP... paths)
    {
        
        std::cout << "root: " << np->GetValue() << '\n';

        //std::cout << "traverse: " << paths->GetValue() << '\n'; // Error: paths parameter pack must be expanded in this context, so we can't use it directly here. We can only use it in a fold expression or by expanding it in a lambda or something like that.

        Node* current = np;
        //unary left fold
        ((std::cout << "traverse: " << (current = current->*paths)->GetValue() << '\n'), ...);

        return (np->*...->*paths);
    }
};

