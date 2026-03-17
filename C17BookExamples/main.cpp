#include "structbind.hpp"
#include <iostream>

int main()
{
    Customer c{ "Tim", "Starr", 42 };
    auto [f, l, v] = c;

    std::cout << "f/l/v " << f << ' ' << l << ' ' << v << '\n';

    std::string s{ std::move(f) };
    l = "Waters";
    v += 10;

    std::cout << "f/l/v " << f << ' ' << l << ' ' << v << '\n';

    std::cout << "Customer: " << c.getFirst() << ' ' << c.getLast() << ' ' << c.getValue() << '\n';

    std::cout << "s: " << s << '\n';

    auto& [rf, rl, rv] = c; // reference to the struct
    std::cout << "cf/cl/cv " << rf << ' ' << rl << ' ' << rv << '\n';

    rf = "John";
    rl = "Smith";
    rv = 100;

    std::cout << "cf/cl/cv " << rf << ' ' << rl << ' ' << rv << '\n';


    auto&& [f2, l2, v2] = c;
    std::string s2{ std::move(f2) };
    f2 = "Ringo";
    v2 += 10;
    std::cout << "f2/l2/v2: " << f2 << ' ' << l2 << ' ' << v2 << '\n';
    std::cout << "c: " << c.getFirst() << ' '
        << c.getLast() << ' ' << c.getValue() << '\n';

    std::cout << "s: " << s2 << '\n';

    return 0;
}