#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// Mutex: Stands for mutual exlusion

// RACE CONDITIONS
// - Situation where 2 or more threads/processes are accessing/changing a common piece of data at the same time
// - If there is a race condition then we have to protect it and the protected section is called the CRITICAL SECTION (Or critical region)

// MUTEX
// - They are used to avoid race conditions
// - lock() and unlock()
// We will see in the example below...

int myAmount = 0;
mutex m;

void incrementValue()
{
    m.lock();   // As one of the threads accesses myAmount first, m.lock() locks the other threads out
    myAmount++; // t1 t2 and t3 will be accessing this data... therefore we must protect it, making it the critical section
    m.unlock(); // The thread to change the data unlocks after it is done
}

int main()
{
    thread t1(incrementValue);
    thread t2(incrementValue);
    thread t3(incrementValue);

    t1.join();
    t2.join();
    t3.join();

    cout << myAmount << endl;

    return 0;
}