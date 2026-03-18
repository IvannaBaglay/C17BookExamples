#include <string>
#include <iostream>

struct MyData
{
    inline static std::string gName = "global"; // unique object across all threads 
    inline static thread_local std::string tName = "thread_local name"; // unique object per thread
    std::string lName = "local"; // unique object per instance of MyData, but since we have one instance per thread, it is also unique per thread

    void print(const std::string& message)
    {
        std::cout << message << '\n';
        std::cout << "- gName: " << gName << '\n';
        std::cout << "- tName: " << tName << '\n';
        std::cout << "- lName: " << lName << '\n';
    }
};

// Aggregate initialization of variables is not allowed with inline static
// only non-static data members are considered for aggregate status and initialization.
//inline thread_local MyData myThreadData{"global", "tln" "local_aggregateExt" }; // one object per thread

inline thread_local MyData myThreadData{"global_aggregateExt"}; // one object per thread
inline thread_local MyData myThreadData1{ "global_aggregateExt1" }; // one object per thread

inline MyData myGlobalData; // one global object