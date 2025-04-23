#ifndef QUEUE_HPP
#define QUEUE_HPP

namespace ds {

class Queue {
private:
    int* data;
    int front, rear, capacity, count;

public:
    Queue(int size);
    ~Queue();

    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    bool isFull() const;
};

}

#endif