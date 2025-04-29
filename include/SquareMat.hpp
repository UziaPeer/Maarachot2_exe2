// Email: peeruzia@gmail.com
#ifndef SQUARE_MAT_HPP
#define SQUARE_MAT_HPP

#include <iostream>

namespace mat
{

    class SquareMat
    {
    private:
        int size;       // גודל המטריצה (n x n)
        double *data;   // מצביע למערך הנתונים של המטריצה

    public:
        SquareMat(int n); // בנאי: יוצר מטריצה ריבועית בגודל n
        SquareMat(const SquareMat &other); // בנאי העתקה: יוצר עותק עמוק של מטריצה ריבועית אחרת
        SquareMat &operator=(const SquareMat &other); // אופרטור השמה: מעתיק תוכן של מטריצה ריבועית אחת לאחרת
        ~SquareMat(); // דסטרקטור: משחרר את הזיכרון שהוקצה למטריצה

        double get(int i, int j) const; // מחזיר את הערך במיקום (i, j) במטריצה
        void set(int i, int j, double val); // מעדכן את הערך במיקום (i, j) במטריצה

        class RowProxy
        {
            double *row;

        public:
            RowProxy(double *rowPtr) : row(rowPtr) {} // בנאי: מקבל מצביע לשורה
            double &operator[](int col) { return row[col]; } // אופרטור גישה לעמודה בשורה (לא קבוע)
            const double &operator[](int col) const { return row[col]; } // אופרטור גישה לעמודה בשורה (קבוע)
        };

        RowProxy operator[](int row); // אופרטור גישה לשורה במטריצה (לא קבוע)
        const RowProxy operator[](int row) const; // אופרטור גישה לשורה במטריצה (קבוע)

        SquareMat operator+(const SquareMat &other) const; // אופרטור חיבור: מחבר שתי מטריצות
        SquareMat operator-(const SquareMat &other) const; // אופרטור חיסור: מחסר מטריצה אחת מהשנייה
        SquareMat operator*(const SquareMat &other) const; // אופרטור כפל: כפל מטריצה במטריצה אחרת
        SquareMat operator~() const; // אופרטור טרנספוזיציה: מחזיר את הטרנספוזיציה של המטריצה
        SquareMat operator-() const; // אופרטור שינוי סימן: מחזיר מטריצה עם ערכים הפוכים
        SquareMat operator%(const SquareMat &other) const; // כפל איברי: מבצע כפל איברי בין שתי מטריצות
        SquareMat operator%(int scalar) const; // מודולו עם סקלר: מבצע מודולו על כל איבר במטריצה עם סקלר
        SquareMat operator/(double scalar) const; // חלוקה בסקלר: מחלק את כל איברי המטריצה בסקלר
       
        SquareMat& operator*=(const SquareMat& other); // כפל במקום: כפל מטריצה במטריצה אחרת במקום
        SquareMat& operator*=(double scalar); // כפל במקום בסקלר: כפל כל איברי המטריצה בסקלר במקום
        SquareMat &operator%=(const SquareMat &other); // מודולו במקום עם מטריצה אחרת
        SquareMat &operator%=(int scalar); // מודולו במקום עם סקלר
        SquareMat &operator/=(double scalar); // חלוקה במקום בסקלר
        SquareMat &operator+=(const SquareMat &other); // חיבור במקום: מחבר מטריצה אחרת למטריצה הנוכחית
        SquareMat &operator-=(const SquareMat &other); // חיסור במקום: מחסר מטריצה אחרת מהמטריצה הנוכחית
        SquareMat operator*(double scalar) const; // כפל בסקלר: מחזיר מטריצה חדשה לאחר כפל בסקלר
        friend SquareMat operator*(double scalar, const SquareMat &mat); // כפל בסקלר (חבר): מחזיר מטריצה חדשה לאחר כפל בסקלר
        bool operator==(const SquareMat &other) const; // השוואה: בודק אם שתי מטריצות שוות
        bool operator!=(const SquareMat &other) const; // אי-שוויון: בודק אם שתי מטריצות אינן שוות
        bool operator<(const SquareMat &other) const; // השוואה: בודק אם מטריצה אחת קטנה מהשנייה
        bool operator<=(const SquareMat &other) const; // השוואה: בודק אם מטריצה אחת קטנה או שווה לשנייה
        bool operator>(const SquareMat &other) const; // השוואה: בודק אם מטריצה אחת גדולה מהשנייה
        bool operator>=(const SquareMat &other) const; // השוואה: בודק אם מטריצה אחת גדולה או שווה לשנייה

        SquareMat &operator++(); // אינקרמנט לפני: מגדיל את כל איברי המטריצה ב-1
        SquareMat operator++(int); // אינקרמנט אחרי: מגדיל את כל איברי המטריצה ב-1 (לאחר הפעולה)
        SquareMat &operator--(); // דקרמנט לפני: מקטין את כל איברי המטריצה ב-1
        SquareMat operator--(int); // דקרמנט אחרי: מקטין את כל איברי המטריצה ב-1 (לאחר הפעולה)

        double determinant() const; // חישוב דטרמיננטה של המטריצה
        double operator!() const; // אופרטור לחישוב דטרמיננטה (!)
        SquareMat operator^(int power) const; // העלאה בחזקה: מעלה את המטריצה לחזקה נתונה

        friend std::ostream &operator<<(std::ostream &os, const SquareMat &mat); // הדפסת מטריצה לזרם פלט
    };

}

#endif