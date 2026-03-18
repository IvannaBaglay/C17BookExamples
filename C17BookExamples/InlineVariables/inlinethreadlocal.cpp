#include "inlinethreadlocal.hpp"
#include <thread>

void foo()
{
    myThreadData.print("foo() begin:");
    myThreadData1.print("foo() begin:");
    myGlobalData.print("foo() begin:");
    /*
    *foo() begin:
    *- gName: thread1_1 name // global variable is shared across all threads, so it is changed by myThreadData1 in main() before thread
    *- tName: thread_local name // thread_local variable is unique per thread, so it is not changed by myThreadData1 in main() before thread
    *- lName: global_aggregateExt 
    *foo() begin:
    *- gName: thread1_1 name
    *- tName: thread_local name
    *- lName: global_aggregateExt1
    */

    myThreadData.gName = "thread2 name";
    myThreadData.tName = "thread2 name";
    myThreadData.lName = "thread2 name";

    myThreadData1.gName = "thread2_2 name";
    myThreadData1.tName = "thread2_2 name";
    myThreadData1.lName = "thread2_2 name";

    myGlobalData.gName = "thread 2 global data name";
    myGlobalData.tName = "thread 2 global data name";
    myGlobalData.lName = "thread 2 global data name";

    myThreadData.print("foo() end:");
    myThreadData1.print("foo() end:");
    myGlobalData.print("foo() end:");

    /*
    *foo() end:
    *- gName: thread2_2 name
    *- tName: thread2_2 name
    *- lName: thread2 name
    *foo() end:
    *- gName: thread2_2 name
    *- tName: thread2_2 name
    *- lName: thread2_2 name
    */
}

int InlineVariableMain()
{
    myThreadData.print("main() begin:");
    myThreadData1.print("main() begin:");
    myGlobalData.print("main() begin:");
    /*
    *main() begin:
    *- gName: global
    *- tName: thread_local name
    *- lName: global_aggregateExt
    *main() begin:
    *- gName: global
    *- tName: thread_local name
    *- lName: global_aggregateExt1
    */

    myThreadData.gName = "thread1 name";
    myThreadData.tName = "thread1 name";
    myThreadData.lName = "thread1 name";

    myThreadData1.gName = "thread1_1 name";
    myThreadData1.tName = "thread1_1 name";
    myThreadData1.lName = "thread1_1 name";


    myGlobalData.gName = "thread 1 global data name";
    myGlobalData.tName = "thread 1 global data name";
    myGlobalData.lName = "thread 1 global data name";

    myThreadData.print("main() before thread:");
    myThreadData1.print("main() before thread:");
    myGlobalData.print("main() before thread:");

    /*
    *main() before thread:
    *- gName: thread1_1 name // change by myThreadData1 because gName is shared across all threads
    *- tName: thread1_1 name // change by myThreadData1 because tName is shared across threads
    *- lName: thread1 name // local variable is not shared across threads, so it is not changed by myThreadData1
    *main() before thread:
    *- gName: thread1_1 name
    *- tName: thread1_1 name
    *- lName: thread1_1 name
    */

    std::thread t{ foo };
    t.join();
    myThreadData.print("main() end:");
    myThreadData1.print("main() end:");
    myGlobalData.print("main() end:");

    /*
    main() end:
    *- gName: thread2_2 name
    *- tName: thread1_1 name
    *- lName: thread1 name
    *main() end:
    *- gName: thread2_2 name
    *- tName: thread1_1 name
    *- lName: thread1_1 name
    */

    return 0;
}