
//------------------------------------------------------------//
/*
Playing with mutex
*/
//------------------------------------------------------------//

#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mut1, mut2;

void worker(int index)
{
  for (int i = 0; i < 5; i++)
  {
    std::cout << "Worker " << index << " begins times ::" << i << std::endl;
    
    if (index == 1)
    {
      //std::lock_guard<std::mutex> g1(mut1);  
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }


    if (index == 2)
    {
      //std::lock_guard<std::mutex> g2(mut1);
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Worker " << index << " ends" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}

int main()
{
  std::thread worker1(worker, 1);
  std::thread worker2(worker, 2);
  worker1.join();
  worker2.join();
  std::cout << "Done" << std::endl;
}
