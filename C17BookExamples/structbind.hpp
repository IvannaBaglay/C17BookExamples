#include "Customer.hpp"
#include <utility>

template<>
struct std::tuple_size<Customer>
{
    static constexpr int value = 3; // How many elements are in the tuple (the struct)
};

// specialization for each element
template<>
struct std::tuple_element<2, Customer> // only the 3rd element is different
{
    using type = long;
};

template<std::size_t Idx>
struct std::tuple_element<Idx, Customer> // Rest of the elements are the same
{
    using type = std::string;
};

//// generic get function template
//template<std::size_t> auto get(const Customer& c);
//
//// specialization for each element
//template<> auto get<0>(const Customer& c) { return c.getFirst(); }
//template<> auto get<1>(const Customer& c) { return c.getLast(); }
//template<> auto get<2>(const Customer& c) { return c.getValue(); }


// mutable lvalue
template<size_t Idx> decltype(auto) get(Customer& c)
{
    static_assert(Idx < 3, "Index out of bounds");
    if constexpr (Idx == 0)
        return c.getFirst();
    else if constexpr (Idx == 1)
        return c.getLast();
    else
        return c.getValue();
}

// const lvalue
template<size_t Idx> decltype(auto) get(const Customer& c)
{
    static_assert(Idx < 3, "Index out of bounds");
    if constexpr (Idx == 0)
        return c.getFirst();
    else if constexpr (Idx == 1)
        return c.getLast();
    else
        return c.getValue();
}

// rvalue
template<size_t Idx> decltype(auto) get(Customer&& c)
{
    static_assert(Idx < 3, "Index out of bounds");
    if constexpr (Idx == 0)
        return std::move(c.getFirst());
    else if constexpr (Idx == 1)
        return std::move(c.getLast());
    else
        return std::move(c.getValue());
}