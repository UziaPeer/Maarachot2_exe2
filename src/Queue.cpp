// Email: peeruzia@gmail.com
#include "Queue.hpp"

namespace ds {

// בנאי רגיל: יוצר תור בגודל נתון, מאתחל מצביעים וסופר איברים
Queue::Queue(int size) : capacity(size), front(0), rear(0), count(0) {
    data = new int[capacity]; // הקצאת זיכרון למערך בגודל קיבולת
}

// בנאי העתקה: יוצר עותק עמוק של תור אחר
Queue::Queue(const Queue& other) 
    : capacity(other.capacity), front(other.front), rear(other.rear), count(other.count) 
{
    data = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        data[i] = other.data[i];
    }
}

// אופרטור השמה: השמה עמוקה בין תורים
Queue& Queue::operator=(const Queue& other) {
    if (this != &other) { // הגנה מהשמה עצמית
        delete[] data;     // משחררים את המערך הישן

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

// מפרק: משחרר את הזיכרון שהוקצה למערך
Queue::~Queue() {
    delete[] data;
}

// פונקציה להוספת ערך לסוף התור
void Queue::enqueue(int value) {
    if (isFull()) return; // אם מלא - לא מוסיפים
    data[rear] = value;
    rear = (rear + 1) % capacity; // מעגליות של המצביע
    count++;
}

// פונקציה להוצאת ערך מהתחלת התור
int Queue::dequeue() {
    if (isEmpty()) return -1; // אם ריק - מחזירים ערך שגיאה
    int value = data[front];
    front = (front + 1) % capacity; // מעגליות של המצביע
    count--;
    return value;
}

// בדיקה אם התור ריק
bool Queue::isEmpty() const {
    return count == 0;
}

// בדיקה אם התור מלא
bool Queue::isFull() const {
    return count == capacity;
}

} // end namespace ds
