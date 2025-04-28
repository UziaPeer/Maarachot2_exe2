// Email: peeruzia@gmail.com
#include "Queue.hpp"

namespace ds {

Queue::Queue(int size) : capacity(size), front(0), rear(0), count(0) {
    data = new int[capacity];
}

// בנאי העתקה 
Queue::Queue(const Queue& other) : capacity(other.capacity), front(other.front), rear(other.rear), count(other.count) {
    data = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        data[i] = other.data[i];
    }
}

// אופרטור השמה
Queue& Queue::operator=(const Queue& other) {
    if (this != &other) { // הגנה מהשמה עצמית
        delete[] data; // משחררים את המערך הישן

        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        count = other.count;

        data = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Destructor
Queue::~Queue() {
    delete[] data;
}

void Queue::enqueue(int value) {
    if (isFull()) return;
    data[rear] = value;
    rear = (rear + 1) % capacity;
    count++;
}

int Queue::dequeue() {
    if (isEmpty()) return -1;
    int value = data[front];
    front = (front + 1) % capacity;
    count--;
    return value;
}

bool Queue::isEmpty() const {
    return count == 0;
}

bool Queue::isFull() const {
    return count == capacity;
}

}