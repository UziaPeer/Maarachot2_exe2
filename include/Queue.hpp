// Email: peeruzia@gmail.com
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
    Queue(const Queue& other);            // בנאי העתקה
    Queue& operator=(const Queue& other); // אופרטור השמה


    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    bool isFull() const;
};

}

#endif