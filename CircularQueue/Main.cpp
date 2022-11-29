#include <iostream>
#include "CircularQueue.h"
#include <vector>

//This is my first project in C++. I have attempted to implement a simple generic circular queue in C++.

int main()
{
    //Simply Testing.
    CircularQueue<int> queue = CircularQueue<int>(5);

    queue.Enqueue(0);
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    std::cout << "Dequeuing: " << *queue.Dequeue() << std::endl;
    std::cout << "Dequeuing: " << *queue.Dequeue() << std::endl;
    std::cout << "Dequeuing: " << *queue.Dequeue() << std::endl;
    std::cout << "Dequeuing: " << *queue.Dequeue() << std::endl;
    std::cout << "Dequeuing: " << *queue.Dequeue() << std::endl;

    std::cout << "Is empty: " << queue.IsEmpty() << std::endl;

    queue.Enqueue(6);
    
    std::cout << "Dequeuing: " << *queue.Dequeue() << std::endl;
    std::cin.get();
}
