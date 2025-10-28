/*
    레이스 컨디션 Race Condition, std::atomic, std::scoped_lock
*/
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

int main()
{
    int shared_memory(0);
    //atomic<int> shared_memory(0);

    auto count_func = [&]() {
        for (int i = 0; i < 500; i++)
        {
            this_thread::sleep_for(chrono::milliseconds(1));
            
            // error
            shared_memory++;

            // option 1
            //mtx.lock();
            //shared_memory++;
            //mtx.unlock();
            
            // safer
            //std::lock_guard lock(mtx);
            //shared_memory++;

            // recommended
            //std::scoped_lock lock(mtx);
            //shared_memory++;

            // option 2
            //shared_memory.fetch_add(1);
        }
    };

    thread t1 = thread(count_func);
    thread t2 = thread(count_func);

    t1.join();
    t2.join();

    cout << "After" << endl;
    cout << shared_memory << endl;

    return 0;
}