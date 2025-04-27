// Email: peeruzia@gmail.com
#include "SquareMat.hpp"

namespace mat
{

    SquareMat::SquareMat(int n) : size(n)
    {
        data = new double[size * size];
        for (int i = 0; i < size * size; ++i)
        {
            data[i] = 0;
        }
    }

    SquareMat::SquareMat(const SquareMat &other) : size(other.size)
    {
        data = new double[size * size];
        for (int i = 0; i < size * size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    SquareMat &SquareMat::operator=(const SquareMat &other)
    {
        if (this != &other)
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

    SquareMat::~SquareMat()
    {
        delete[] data;
    }

    double SquareMat::get(int i, int j) const
    {
        return data[i * size + j];
    }

    void SquareMat::set(int i, int j, double val)
    {
        data[i * size + j] = val;
    }

    SquareMat::RowProxy SquareMat::operator[](int row)
    {
        return RowProxy(&data[row * size]);
    }

    const SquareMat::RowProxy SquareMat::operator[](int row) const
    {
        return RowProxy(&data[row * size]);
    }

    SquareMat SquareMat::operator+(const SquareMat &other) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    SquareMat SquareMat::operator-(const SquareMat &other) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    SquareMat SquareMat::operator-() const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = -this->data[i];
        }
        return result;
    }

    SquareMat SquareMat::operator~() const
    {
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result.set(j, i, get(i, j));
        return result;
    }

    SquareMat &SquareMat::operator+=(const SquareMat &other)
    {
        for (int i = 0; i < size * size; ++i)
        {
            data[i] += other.data[i];
        }
        return *this;
    }

    SquareMat &SquareMat::operator-=(const SquareMat &other)
    {
        for (int i = 0; i < size * size; ++i)
        {
            data[i] -= other.data[i];
        }
        return *this;
    }

    SquareMat SquareMat::operator*(double scalar) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = this->data[i] * scalar;
        }
        return result;
    }

    SquareMat operator*(double scalar, const SquareMat &mat)
    {
        return mat * scalar;
    }

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

    bool SquareMat::operator!=(const SquareMat &other) const
    {
        return !(*this == other);
    }

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

    bool SquareMat::operator<=(const SquareMat &other) const
    {
        return !(other < *this);
    }

    bool SquareMat::operator>(const SquareMat &other) const
    {
        return other < *this;
    }

    bool SquareMat::operator>=(const SquareMat &other) const
    {
        return !(*this < other);
    }

    SquareMat &SquareMat::operator++()
    {
        for (int i = 0; i < size * size; ++i)
            ++data[i];
        return *this;
    }

    SquareMat SquareMat::operator++(int)
    {
        SquareMat temp(*this);
        ++(*this);
        return temp;
    }

    SquareMat &SquareMat::operator--()
    {
        for (int i = 0; i < size * size; ++i)
            --data[i];
        return *this;
    }

    SquareMat SquareMat::operator--(int)
    {
        SquareMat temp(*this);
        --(*this);
        return temp;
    }

    double SquareMat::operator!() const
    {
        return this->determinant();
    }

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

    SquareMat SquareMat::operator^(int power) const
    {
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            result.set(i, i, 1); // identity
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

    SquareMat SquareMat::operator%(const SquareMat &other) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = this->data[i] * other.data[i]; // כפל איברי
        }
        return result;
    }

    SquareMat SquareMat::operator%(int scalar) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = static_cast<int>(this->data[i]) % scalar;
        }
        return result;
    }

    SquareMat SquareMat::operator/(double scalar) const
    {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
        {
            result.data[i] = this->data[i] / scalar;
        }
        return result;
    }

    SquareMat &SquareMat::operator%=(const SquareMat &other)
    {
        for (int i = 0; i < size * size; ++i)
        {
            data[i] *= other.data[i];
        }
        return *this;
    }

    SquareMat &SquareMat::operator%=(int scalar)
    {
        for (int i = 0; i < size * size; ++i)
        {
            data[i] = static_cast<int>(data[i]) % scalar;
        }
        return *this;
    }

    SquareMat &SquareMat::operator/=(double scalar)
    {
        for (int i = 0; i < size * size; ++i)
        {
            data[i] /= scalar;
        }
        return *this;
    }

    SquareMat& SquareMat::operator*=(double scalar) {
        for (int i = 0; i < size * size; ++i) {
            data[i] *= scalar;
        }
        return *this;
    }
    
    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        *this = *this * other;
        return *this;
    }
    

}