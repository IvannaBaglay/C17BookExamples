#pragma once

#include <iostream>

// using auto for templates parametes
template<auto Sep = ' ', typename First, typename ... Args>
void print(const First& first, const Args& ... args)
{
    std::cout << first;
    auto outWithSep = [](const auto& arg)
        {
            std::cout << Sep << arg;
        };
    //(..., outWithSep(args));
    (outWithSep(args), ...); // here the order doesn't matter 
    std::cout << std::endl;
}