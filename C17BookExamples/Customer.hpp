#include <string>
#include <utility> 

class Customer
{
public:
    Customer(std::string f, std::string l, long v)
        : first{ std::move(f) }
        , last{ std::move(l) }
        , val(v)
    {
    }

    const std::string& getFirst() const { return first; }
    std::string& getFirst() { return first; }

    const std::string& getLast() const { return last; }
    std::string& getLast() { return last; }

    long getValue() const { return val; }
    long& getValue() { return val; }
private:
    std::string first;
    std::string last;
    long val;
};