
/*
in this example we define two thread wchich perform two different works with different time
interval.
We add also mutex for each thread in order to coordinate the output.
WITH MUTEX:
first whole job is done by thread 1 and after the thread 2 can continue. Thread 2 is blocked by thread 1

WITHOUT MUTEX

Each thread fights to acceass

*/

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex m;

auto get_time()
{

    return std::chrono::high_resolution_clock::now();
}

void worker_1(int x)
{
    std::lock_guard <std::mutex> g(m);
    auto start = get_time();
    for (int i = 0; i < 10; i++)
    {

        std::cout << "\n"<<"worker 1 " << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(x));
    }
    auto finish = get_time();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    std::cout<<"this worker 1 needs :: "<< duration.count() << std::endl;
}


void worker_2(int x){
std::lock_guard<std::mutex> g(m);
    auto start = get_time();

    for (int i = 0; i < 10; i++){

        std::cout << "\n" << "_____worker 2 _________" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(x));

    }
    auto finish = get_time();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(finish-start);

    std::cout<<"this worker needs :: " << duration.count() << std::endl;

}

int main()
{

    auto start = get_time();
    
    std::thread thr1(worker_1, 500);
    std::thread thr2(worker_2, 200);

    thr1.join();
    thr2.join();

    auto finish = get_time();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    std::cout << "time elapsed :: " << duration.count() << std::endl;
    std::cout << "Done" << std::endl;
}