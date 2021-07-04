#ifndef VEC2_H
#define VEC2_H

#include<iostream>
#include<random>
#include<cassert>

/*! \brief A simple 2D vector class.
 *
 *  The Vec2 class creates a 2D vector (x,y) and provides some useful operations
 *  such as dot, normalization, random vectors. It also supports all
 *  the operations such as multiplication, addition, subtraction, division etc.
 *
 */

class Vec2 {

public:


    //! Constructor with default arguments. If no parameters
    //! are provided, a vector (0,0) is created. Otherwise
    //! a vector (x,y,z) is created.
    Vec2(double p1 = 0., double p2 = 0.):
    m_x{p1},
    m_y{p2}
    {   }

    //! Copy Constructor. Creates a vector that is a copy
    //! of an existing vector provided as argument.
    Vec2(const Vec2& v):
    m_x{v.x()},
    m_y{v.y()}
    {   }


    // Getters
    double x()const {return m_x;} //!< returns the x component.
    double y()const {return m_y;} //!< returns the y component.

    // Setters
    void setX(const double& p){m_x = p;} //!< sets the x component.
    void setY(const double& p){m_y = p;} //!< sets the y component.


    void setXY(const double& num)
    {setX(num);setY(num);} //!< sets the two components to a specific value.

    void setXY(const double& p1, const double& p2)
    {setX(p1);setY(p2);} //!< Every component gets a unique value.


    double operator[](int i) const
    {
        assert(i >= 0 && i <= 1);
        if(i == 0)return m_x;
        return m_y;
    }

    double& operator[](int i)
    {
        assert(i >= 0 && i <= 1);
        if(i == 0)return m_x;
        return m_y;
    }

    Vec2& operator=(const Vec2& v)
    {
        m_x = v.x();
        m_y = v.y();
        return *this;
    }

    Vec2  operator+() const{return Vec2(m_x, m_y);}; //!< Overloaded unary (+) operator. Returns the same vector.
    Vec2  operator-() const{return Vec2(-m_x, -m_y);} //!< Overloaded unary (-) operator. Returns the opposite vector.


    // Prefix
    Vec2& operator++(); //!< Overloaded prefix (++) operator. Returns the vector and increments its components by one.
    Vec2& operator--(); //!< Overloaded prefix (--) operator. Returns the vector and decrements its components by one.
    // Postfix
    Vec2 operator++(int); //!< Overloaded postfix (++) operator. Increments the vectors components by one and returns it.
    Vec2 operator--(int); //!< Overloaded postfix (--) operator. Decrements the vectors components by one and returns it.


    Vec2& operator+=(const double& num); //!< Overloaded unary (+=) operator. Increments the vector's components by a value num.
    Vec2& operator+=(const Vec2& v);
    Vec2& operator-=(const double& num); //!< Overloaded unary (-=) operator. Decrements the vector's components by a value num.
    Vec2& operator-=(const Vec2& v);
    Vec2& operator*=(const double& num); //!< Overloaded unary (*=) operator. Multiplies the vector's components by a value num.


    Vec2& normalize(); //!< Makes the vector a unit vector of length one.
    double length()const; //!< Returns the length of the vector.


private:

    double m_x;
    double m_y;

};

Vec2 operator+(const Vec2&, const Vec2&); //!< Overloaded binary (+) operator. Addition of two vectors.
Vec2 operator+(const Vec2&, const double&); //!< Overloaded binary (+) operator. Addition of a vector and a number.
Vec2 operator+(const double&, const Vec2&); //!< Overloaded binary (+) operator. Addition of a vector and a number.

Vec2 operator-(const Vec2&, const Vec2&); //!< Overloaded binary (-) operator. Subtraction of two vectors.
Vec2 operator-(const Vec2&, const double&); //!< Overloaded binary (-) operator. Subtraction of a vector and a number.
Vec2 operator-(const double&, const Vec2&);  //!< Overloaded binary (-) operator. Subtraction of a vector and a number.

Vec2 operator*(const Vec2&, const Vec2&); //!< Overloaded binary (*) operator. Multiplication of two vectors.
Vec2 operator*(const Vec2&, const double&); //!< Overloaded binary (*) operator. Multiplication of a vector and a number.
Vec2 operator*(const double&, const Vec2&); //!< Overloaded binary (*) operator. Multiplication of a vector and a number.

Vec2 operator/(const Vec2&, const Vec2&); //!< Overloaded binary (/) operator. Division of two vectors component by component.
Vec2 operator/(const Vec2&, const double&); //!< Overloaded binary (/) operator. Division of a vector's components by a number.

bool operator==(const Vec2&, const Vec2&); //!< Overloaded binary (==) operator. Checks if two vectors are identical.
bool operator!=(const Vec2&, const Vec2&); //!< Overloaded binary (!=) operator. Checks if two vectors are not identical.

std::istream& operator>>(std::istream& in, Vec2& v); //!< Overloaded binary (>>) operator. Reads a vector's components from a stream.
std::ostream& operator<<(std::ostream&, const Vec2&); //!< Overloaded binary (<<) operator. Prints a vector's components to a stream.

double dot(const Vec2&, const Vec2&); //!< The dot product of two vectors. Returns a number of type double.

Vec2 getUnitVectorOf(const Vec2&); //!< Gets the unit vector of a vector without changing the provided vector.


#endif // VEC2_H
