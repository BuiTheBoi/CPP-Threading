// TO COMPILE: g++ -std=c++17 -pthread multithreading.cpp

#include<iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void printEvenTerms(int start, int end)
{
    for (int i = start; i <= end; ++i)
    {
        if (i % 2 == 0)
            cout << "EVEN: " << i << endl;
    }
}

void printOddTerms(int start, int end)
{
    for (int i = start; i <= end; ++i)
    {
        if (i % 2 == 1)
            cout << "ODD: " << i << endl;
    }
}


const int START = 0;
const int END = 1000;

int main() 
{
    auto startTime = high_resolution_clock::now();

    // Creating threads for each function
    thread t1(printEvenTerms, START, END);
    thread t2(printOddTerms, START, END);

    // These threads created will not be joined with the main thread.
    // Instead will be running, while main thread waits for it to continue running
    // NOTE: When creating multiple threads, it does not guarantee which one will start first

    // Good practice to check if thread is joinable before joining
    // This is because if you join the same thread twice, it can end in program termination
    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();

    // printEvenTerms(START, END);
    // printOddTerms(START, END);

    auto stopTime = high_resolution_clock::now();
    auto elapsedTime = duration_cast<microseconds>(stopTime - startTime);
    
    cout << "Elapsed time: " << elapsedTime.count()/1000000.0 << endl;
    return 0;
}