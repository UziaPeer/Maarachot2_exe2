// Email: peeruzia@gmail.com
#include <iostream>
#include "SquareMat.hpp"
#include "Queue.hpp"

using namespace mat;
using namespace ds;

int main() {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    std::cout << "Matrix A:\n" << a;
    std::cout << "Matrix B:\n" << b;

    // חיבור, חיסור, שינוי סימן
    std::cout << "A + B:\n" << (a + b);
    std::cout << "A - B:\n" << (a - b);
    std::cout << "-A:\n" << (-a);

    // טרנספוזיציה
    std::cout << "Transpose of A (~A):\n" << (~a);

    // כפל מטריצות
    std::cout << "A * B:\n" << (a * b);

    // כפל בסקלר
    std::cout << "A * 2:\n" << (a * 2);
    std::cout << "2 * A:\n" << (2 * a);

    // מודולו עם סקלר
    std::cout << "A % 3:\n" << (a % 3);

    // כפל איברי
    std::cout << "A % B (element-wise multiply):\n" << (a % b);

    // חלוקה בסקלר
    std::cout << "A / 2.0:\n" << (a / 2.0);

    // אופרטורים על מקום
    a += b;
    std::cout << "A += B:\n" << a;

    a -= b;
    std::cout << "A -= B:\n" << a;

    a *= 2;
    std::cout << "A *= 2:\n" << a;

    a *= b;
    std::cout << "A *= B:\n" << a;

    a /= 2.0;
    std::cout << "A /= 2:\n" << a;

    a %= b;
    std::cout << "A %= B:\n" << a;

    a %= 2;
    std::cout << "A %= 2:\n" << a;

    // אינקרמנט ודקרמנט
    ++a;
    std::cout << "++A:\n" << a;

    a++;
    std::cout << "A++:\n" << a;

    --a;
    std::cout << "--A:\n" << a;

    a--;
    std::cout << "A--:\n" << a;

    // דטרמיננטה
    std::cout << "Determinant of A (!A): " << !a << std::endl;

    // חזקה
    std::cout << "A ^ 2:\n" << (a ^ 2);

    // השוואות
    std::cout << "A == B? " << (a == b ? "Yes" : "No") << std::endl;
    std::cout << "A < B?  " << (a < b ? "Yes" : "No") << std::endl;

    // הדגמה של Queue
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    std::cout << "Queue Dequeue 1: " << q.dequeue() << std::endl;
    std::cout << "Queue Dequeue 2: " << q.dequeue() << std::endl;

    return 0;
}
