/*
Markus Buchholz

*/

#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>

std::mutex m_dev;
int value{99};
int *ptr_value = &value;


void worker(int index, int t)
{

    for (int i = 0; i < 5; i++)
    {
        {
            std::lock_guard<std::mutex> g(m_dev);
            std::cout << "worker: " << index << " begins " << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(t));
            *ptr_value = *ptr_value + t;
            std::cout << "worker: " << index << " ends " << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int main()
{
    std::cout<<" *ptr_value :: " << *ptr_value << " ptr_value :: " << ptr_value << "&value ::  "<<&value << std::endl;
    std::cout<<"value before :: " << temp_value << std::endl;
    std::thread worker1(worker, 1, 500);
    std::thread worker2(worker, 2, 50);

    


    worker1.join();
    worker2.join();
    
    std::cout<<" *ptr_value ::" << *ptr_value << std::endl;

    std::cout << "DONE" << std::endl;
}