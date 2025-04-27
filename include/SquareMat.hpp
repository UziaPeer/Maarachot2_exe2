// Email: peeruzia@gmail.com
#ifndef SQUARE_MAT_HPP
#define SQUARE_MAT_HPP

#include <iostream>

namespace mat
{

    class SquareMat
    {
    private:
        int size;
        double *data;

    public:
        SquareMat(int n);
        SquareMat(const SquareMat &other);
        SquareMat &operator=(const SquareMat &other);
        ~SquareMat();

        double get(int i, int j) const;
        void set(int i, int j, double val);

        class RowProxy
        {
            double *row;

        public:
            RowProxy(double *rowPtr) : row(rowPtr) {}
            double &operator[](int col) { return row[col]; }
            const double &operator[](int col) const { return row[col]; }
        };

        RowProxy operator[](int row);
        const RowProxy operator[](int row) const;

        SquareMat operator+(const SquareMat &other) const;
        SquareMat operator-(const SquareMat &other) const;
        SquareMat operator*(const SquareMat &other) const;
        SquareMat operator~() const;
        SquareMat operator-() const;
        SquareMat operator%(const SquareMat &other) const; // כפל איברי
        SquareMat operator%(int scalar) const;             // מודולו עם סקלר
        SquareMat operator/(double scalar) const;          // חלוקה בסקלר
       
        SquareMat& operator*=(const SquareMat& other);
        SquareMat& operator*=(double scalar);
        SquareMat &operator%=(const SquareMat &other);
        SquareMat &operator%=(int scalar);
        SquareMat &operator/=(double scalar);
        SquareMat &operator+=(const SquareMat &other);
        SquareMat &operator-=(const SquareMat &other);
        SquareMat operator*(double scalar) const;
        friend SquareMat operator*(double scalar, const SquareMat &mat);
        bool operator==(const SquareMat &other) const;
        bool operator!=(const SquareMat &other) const;
        bool operator<(const SquareMat &other) const;
        bool operator<=(const SquareMat &other) const;
        bool operator>(const SquareMat &other) const;
        bool operator>=(const SquareMat &other) const;

        SquareMat &operator++();
        SquareMat operator++(int);
        SquareMat &operator--();
        SquareMat operator--(int);

        double determinant() const;
        double operator!() const;
        SquareMat operator^(int power) const;

        friend std::ostream &operator<<(std::ostream &os, const SquareMat &mat);
    };

}

#endif