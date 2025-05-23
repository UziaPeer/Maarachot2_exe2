// Email: peeruzia@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include "Queue.hpp"

using namespace mat;
using namespace ds;


// טסטים ל-SquareMat


TEST_CASE("גישה לאיברים") {
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    CHECK(m.get(0,0) == 1);
    CHECK(m.get(0,1) == 2);
    CHECK(m.get(1,0) == 3);
    CHECK(m.get(1,1) == 4);
}

TEST_CASE("חיבור וחיסור מטריצות") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    SquareMat c = a + b;
    CHECK(c.get(0,0) == 6);
    CHECK(c.get(1,1) == 12);

    c = b - a;
    CHECK(c.get(0,0) == 4);
    CHECK(c.get(1,1) == 4);
}

TEST_CASE("כפל מטריצות") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 0;
    a[1][0] = 0; a[1][1] = 1;

    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    SquareMat c = a * b;
    CHECK(c.get(0,0) == 5);
    CHECK(c.get(0,1) == 6);
    CHECK(c.get(1,0) == 7);
    CHECK(c.get(1,1) == 8);
}

TEST_CASE("כפל בסקלר וחלוקה בסקלר") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    SquareMat b = a * 2;
    CHECK(b.get(0,0) == 2);
    CHECK(b.get(1,1) == 8);

    b = a / 2.0;
    CHECK(b.get(0,0) == 0.5);
    CHECK(b.get(1,1) == 2);
}

TEST_CASE("טרנספוזיציה ושינוי סימן") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    SquareMat t = ~a;
    CHECK(t.get(0,1) == 3);
    CHECK(t.get(1,0) == 2);

    SquareMat neg = -a;
    CHECK(neg.get(0,0) == -1);
    CHECK(neg.get(1,1) == -4);
}

TEST_CASE("דטרמיננטה וחזקה") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    CHECK(static_cast<int>(!a) == -2);

    SquareMat p = a ^ 2;
    CHECK(p.get(0,0) == 7);
    CHECK(p.get(1,1) == 22);
}

TEST_CASE("אופרטורים השוואה") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 1; b[0][1] = 2;
    b[1][0] = 3; b[1][1] = 4;

    CHECK(a == b);
    CHECK(!(a != b));
    CHECK(!(a < b));
    CHECK(a <= b);
    CHECK(!(a > b));
    CHECK(a >= b);
}

TEST_CASE("אופרטורים על מקום += -= *= /= %=") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 1;
    a[1][0] = 1; a[1][1] = 1;

    b[0][0] = 2; b[0][1] = 2;
    b[1][0] = 2; b[1][1] = 2;

    a += b;
    CHECK(a.get(0,0) == 3);

    a -= b;
    CHECK(a.get(0,0) == 1);

    a *= 2;
    CHECK(a.get(0,0) == 2);

    a /= 2;
    CHECK(a.get(0,0) == 1);

    a %= 2;
    CHECK(a.get(0,0) == 1);
}

TEST_CASE("אופרטורי ++ ו--") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    ++a;
    CHECK(a.get(0,0) == 2);
    a++;
    CHECK(a.get(0,0) == 3);

    --a;
    CHECK(a.get(0,0) == 2);
    a--;
    CHECK(a.get(0,0) == 1);
}

TEST_CASE("בדיקת מטריצה בגודל 4x4") {
    SquareMat m(4);
    
    // אתחול המטריצה
    int val = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            m[i][j] = val++;
        }
    }

    // בדיקה של גישה לאיברים
    CHECK(m.get(0,0) == 1);
    CHECK(m.get(0,3) == 4);
    CHECK(m.get(3,0) == 13);
    CHECK(m.get(3,3) == 16);
}


// טסטים ל-Queue


TEST_CASE("בדיקות בסיסיות לתור") {
    Queue q(3);
    CHECK(q.isEmpty());
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    CHECK(q.isFull());
    CHECK(q.dequeue() == 10);
    CHECK(q.dequeue() == 20);
    CHECK(!q.isFull());
    CHECK(!q.isEmpty());
    CHECK(q.dequeue() == 30);
    CHECK(q.isEmpty());
}

TEST_CASE("בדיקת בנאי העתקה ואופרטור השמה ב-Queue") {
    Queue q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    // בדיקת בנאי העתקה
    Queue q2(q1); // כאן אמור לפעול copy constructor
    CHECK(q2.dequeue() == 10);
    CHECK(q2.dequeue() == 20);
    CHECK(q2.dequeue() == 30);
    CHECK(q2.isEmpty());

    // בדיקת השמה
    Queue q3(5);
    q3 = q1; // כאן אמור לפעול operator=
    CHECK(q3.dequeue() == 10);
    CHECK(q3.dequeue() == 20);
    CHECK(q3.dequeue() == 30);
    CHECK(q3.isEmpty());

    // בדיקת השמה עצמית לא עושה בעיות
    q1 = q1;
    CHECK(q1.dequeue() == 10);
    CHECK(q1.dequeue() == 20);
    CHECK(q1.dequeue() == 30);
    CHECK(q1.isEmpty());
}


