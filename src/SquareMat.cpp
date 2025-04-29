// Email: peeruzia@gmail.com
#include "SquareMat.hpp"

namespace mat
{

    // בנאי רגיל: יוצר מטריצה ריבועית מאופסת בגודל n
    SquareMat::SquareMat(int n) : size(n)
    {
        data = new double[size * size];
        for (int i = 0; i < size * size; ++i)
        {
            data[i] = 0;
        }
    }

    // בנאי העתקה: יוצר עותק חדש ממטריצה קיימת
    SquareMat::SquareMat(const SquareMat &other) : size(other.size)
    {
        data = new double[size * size];
        for (int i = 0; i < size * size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    // אופרטור השמה: השמת ערכים ממטריצה אחרת
    SquareMat &SquareMat::operator=(const SquareMat &other)
    {
        if (this != &other) // הגנה מהשמה עצמית
        {
            delete[] data;
            size = other.size;
            data = new double[size * size];
            for (int i = 0; i < size * size; ++i)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // מפרק: משחרר את הזיכרון הדינמי
    SquareMat::~SquareMat()
    {
        delete[] data;
    }

    // פונקציה להחזרת ערך של איבר במטריצה (לקריאה בלבד)
    double SquareMat::get(int i, int j) const
    {
        return data[i * size + j];
    }

    // פונקציה להצבת ערך באיבר במטריצה
    void SquareMat::set(int i, int j, double val)
    {
        data[i * size + j] = val;
    }

    // אופרטור גישה: מאפשר שימוש ב-matrix[row][col]
    SquareMat::RowProxy SquareMat::operator[](int row)
    {
        return RowProxy(&data[row * size]);
    }

    // אופרטור גישה קבוע: מאפשר קריאה בלבד ב-matrix[row][col]
    const SquareMat::RowProxy SquareMat::operator[](int row) const
    {
        return RowProxy(&data[row * size]);
    }

    // אופרטור חיבור מטריצות
    SquareMat SquareMat::operator+(const SquareMat &other) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    // אופרטור חיסור מטריצות
    SquareMat SquareMat::operator-(const SquareMat &other) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    // אופרטור שינוי סימן לכל איבר במטריצה
    SquareMat SquareMat::operator-() const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = -this->data[i];
        }
        return result;
    }

    // אופרטור טרנספוז: מחליף בין שורות לעמודות
    SquareMat SquareMat::operator~() const
    {
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result.set(j, i, get(i, j));
        return result;
    }

    // אופרטור += בין מטריצות
    SquareMat &SquareMat::operator+=(const SquareMat &other)
    {
        for (int i = 0; i < size * size; ++i)
        {
            data[i] += other.data[i];
        }
        return *this;
    }

    // אופרטור -= בין מטריצות
    SquareMat &SquareMat::operator-=(const SquareMat &other)
    {
        for (int i = 0; i < size * size; ++i)
        {
            data[i] -= other.data[i];
        }
        return *this;
    }

    // אופרטור כפל מטריצה בסקלר
    SquareMat SquareMat::operator*(double scalar) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = this->data[i] * scalar;
        }
        return result;
    }

    // כפל סקלר * מטריצה (חבר חיצוני)
    SquareMat operator*(double scalar, const SquareMat &mat)
    {
        return mat * scalar;
    }

    // אופרטור כפל מטריצות (כפל שורה בעמודה)
    SquareMat SquareMat::operator*(const SquareMat &other) const
    {
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                double sum = 0;
                for (int k = 0; k < size; ++k)
                {
                    sum += this->get(i, k) * other.get(k, j);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }

    // אופרטור == להשוואת מטריצות
    bool SquareMat::operator==(const SquareMat &other) const
    {
        if (size != other.size)
            return false;
        for (int i = 0; i < size * size; ++i)
        {
            if (data[i] != other.data[i])
                return false;
        }
        return true;
    }

    // אופרטור != אי-שוויון בין מטריצות
    bool SquareMat::operator!=(const SquareMat &other) const
    {
        return !(*this == other);
    }

    // אופרטור < השוואת סכומי איברים
    bool SquareMat::operator<(const SquareMat &other) const
    {
        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < size * size; ++i)
        {
            sum1 += data[i];
            sum2 += other.data[i];
        }
        return sum1 < sum2;
    }

    // אופרטור <=
    bool SquareMat::operator<=(const SquareMat &other) const
    {
        return !(other < *this);
    }

    // אופרטור >
    bool SquareMat::operator>(const SquareMat &other) const
    {
        return other < *this;
    }

    // אופרטור >=
    bool SquareMat::operator>=(const SquareMat &other) const
    {
        return !(*this < other);
    }

    // קדם-אינקרמנט ++ על כל איבר במטריצה
    SquareMat &SquareMat::operator++()
    {
        for (int i = 0; i < size * size; ++i)
            ++data[i];
        return *this;
    }

    // פוסט-אינקרמנט ++
    SquareMat SquareMat::operator++(int)
    {
        SquareMat temp(*this);
        ++(*this);
        return temp;
    }

    // קדם-דקרמנט -- על כל איבר
    SquareMat &SquareMat::operator--()
    {
        for (int i = 0; i < size * size; ++i)
            --data[i];
        return *this;
    }

    // פוסט-דקרמנט --
    SquareMat SquareMat::operator--(int)
    {
        SquareMat temp(*this);
        --(*this);
        return temp;
    }

    // אופרטור ! מחשב דטרמיננטה
    double SquareMat::operator!() const
    {
        return this->determinant();
    }

    // חישוב דטרמיננטה ע"י הרחבת לפיתוח מינור
    double SquareMat::determinant() const
    {
        if (size == 1)
            return data[0];
        if (size == 2)
            return data[0] * data[3] - data[1] * data[2];

        double det = 0;
        for (int col = 0; col < size; ++col)
        {
            SquareMat minor(size - 1);
            for (int i = 1; i < size; ++i)
            {
                int k = 0;
                for (int j = 0; j < size; ++j)
                {
                    if (j == col)
                        continue;
                    minor.set(i - 1, k++, get(i, j));
                }
            }
            double cofactor = ((col % 2 == 0) ? 1 : -1) * get(0, col);
            det += cofactor * !minor;
        }
        return det;
    }

    // אופרטור חזקת מטריצה
    SquareMat SquareMat::operator^(int power) const
    {
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            result.set(i, i, 1); // התחלה כמטריצת זהות
        SquareMat base = *this;
        while (power > 0)
        {
            if (power % 2 == 1)
                result = result * base;
            base = base * base;
            power /= 2;
        }
        return result;
    }

    // אופרטור הדפסה של מטריצה
    std::ostream &operator<<(std::ostream &os, const SquareMat &mat)
    {
        for (int i = 0; i < mat.size; ++i)
        {
            for (int j = 0; j < mat.size; ++j)
            {
                os << mat.get(i, j);
                if (j < mat.size - 1)
                    os << " ";
            }
            os << std::endl;
        }
        return os;
    }

    // אופרטור % כפל איברי מטריצות
    SquareMat SquareMat::operator%(const SquareMat &other) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = this->data[i] * other.data[i];
        }
        return result;
    }

    // אופרטור % מודולו של כל איבר בסקלר
    SquareMat SquareMat::operator%(int scalar) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = static_cast<int>(this->data[i]) % scalar;
        }
        return result;
    }

    // אופרטור חלוקה בסקלר
    SquareMat SquareMat::operator/(double scalar) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = this->data[i] / scalar;
        }
        return result;
    }

    // אופרטור %= בין מטריצות
    SquareMat &SquareMat::operator%=(const SquareMat &other)
    {
        for (int i = 0; i < size * size; ++i)
        {
            data[i] *= other.data[i];
        }
        return *this;
    }

    // אופרטור %= מול סקלר
    SquareMat &SquareMat::operator%=(int scalar)
    {
        for (int i = 0; i < size * size; ++i)
        {
            data[i] = static_cast<int>(data[i]) % scalar;
        }
        return *this;
    }

    // אופרטור /= חלוקה בסקלר
    SquareMat &SquareMat::operator/=(double scalar)
    {
        for (int i = 0; i < size * size; ++i)
        {
            data[i] /= scalar;
        }
        return *this;
    }

    // אופרטור *= כפל בסקלר
    SquareMat& SquareMat::operator*=(double scalar) {
        for (int i = 0; i < size * size; ++i) {
            data[i] *= scalar;
        }
        return *this;
    }
    
    // אופרטור *= כפל במטריצה אחרת
    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        *this = *this * other;
        return *this;
    }

}
