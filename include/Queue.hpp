// Email: peeruzia@gmail.com
#ifndef QUEUE_HPP
#define QUEUE_HPP

namespace ds {

class Queue {
private:
    int* data; // מערך לשמירת הנתונים בתור
    int front; // אינדקס של התחלת התור
    int rear; // אינדקס של סוף התור
    int capacity; // הקיבולת המקסימלית של התור
    int count; // מספר האלמנטים הנוכחיים בתור

public:
    Queue(int size); // בנאי: יוצר תור בגודל נתון
    ~Queue(); // דסטרקטור: משחרר את הזיכרון שהוקצה לתור
    Queue(const Queue& other); // בנאי העתקה: יוצר עותק של תור קיים
    Queue& operator=(const Queue& other); // אופרטור השמה: מעתיק תוכן של תור אחד לאחר

    void enqueue(int value); // מוסיף ערך חדש לסוף התור
    int dequeue(); // מסיר ומחזיר את הערך מהחזית של התור
    bool isEmpty() const; // בודק אם התור ריק
    bool isFull() const; // בודק אם התור מלא
};

}

#endif