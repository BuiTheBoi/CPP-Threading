// TO COMPILE: g++ -std=c++17 -pthread detachingThreads.cpp

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

// JOIN NOTES
// - Once a thread is started we wait for this thread to finish by calling join() function on thread object
// - Double joins will result in program termination (Good to call if <threadname>.joinable() before calling the .join())

// DETACH NOTES
// - Used to detach newly created thread from the parent thread (In this case, main)
// - Always check before detaching a thread that it is joinable otherwise we may end up double detaching, which results in termination
// - If we detached a thread and main function is returning then the detached thread execution is suspended

// NOTES
// Either join() or detach() should be called on thread object, otherwise during thread object's destructor it will terminate
// the program bc inside desctructor it checks if thread is joinable(). If so, then terminate program 


void run(int n)
{
    for (int i = 0; i < n; ++i)
        cout << "Hello World " << i << endl;

    cout << "t1 thread complete" << endl;


}

int main()
{
    thread t1(run, 10);
    cout << "Main thread running..." << endl;

    if (t1.joinable())
    {
        t1.detach();    // detach allows t1 to run a seperate thread, so parent thread (main) doesn't have to wait til t1 finishes
    }

    
    // We are letting main() thread to wait for 5 seconds for time for t1 to process.
    // If we comment this out, t1 would still process while main finishes because t1 takes longer than main to process all n loops
    this_thread::sleep_for(chrono::seconds(5));

    cout << "Main thread finished!" << endl;

    return 0;
}
