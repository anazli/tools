#ifndef VEC4_H
#define VEC4_H

#include<iostream>
#include<random>
#include<cassert>

/*! \brief A simple 3D vector class.
 *
 *  The Vec4 class creates a 3D vector (x,y,z) and provides some useful operations
 *  such as dot, cross product, normalization, random vectors. It also supports all
 *  the operations such as multiplication, addition, subtraction, division etc.
 *
 */

class Vec4 {

public:


    //! Constructor with default arguments. If no parameters
    //! are provided, a vector (0,0,0) is created. Otherwise
    //! a vector (x,y,z) is created.
    Vec4(double p1 = 0., double p2 = 0., double p3 = 0., double p4 = 0.):
    m_x{p1},
    m_y{p2},
    m_z{p3},
    m_w{p4}
    {   }

    //! Copy Constructor. Creates a vector that is a copy
    //! of an existing vector provided as argument.
    Vec4(const Vec4& v):
    m_x{v.x()},
    m_y{v.y()},
    m_z{v.z()},
    m_w{v.w()}
    {   }


    // Getters
    double x()const {return m_x;} //!< returns the x component.
    double y()const {return m_y;} //!< returns the y component.
    double z()const {return m_z;} //!< returns the z component.
    double w()const {return m_w;} //!< returns the w component.

    // Setters
    void setX(const double& p){m_x = p;} //!< sets the x component.
    void setY(const double& p){m_y = p;} //!< sets the y component.
    void setZ(const double& p){m_z = p;} //!< sets the z component.
    void setW(const double& p){m_w = p;} //!< sets the w component.


    void setXYZW(const double& num)
    {setX(num);setY(num);setZ(num);setW(num);} //!< sets the four components to a specific value.

    void setXYZW(const double& p1, const double& p2, const double& p3, const double& p4)
    {setX(p1);setY(p2);setZ(p3);setW(p4);} //!< Every component gets a unique value.


    double operator[](int i) const
    {
        assert(i >= 0 && i <= 3);
        if(i == 0)return m_x;
        if(i == 1)return m_y;
        if(i == 2)return m_z;
        return m_w;
    }

    double& operator[](int i)
    {
        assert(i >= 0 && i <= 3);
        if(i == 0)return m_x;
        if(i == 1)return m_y;
        if(i == 2)return m_z;
        return m_w;
    }

    Vec4& operator=(const Vec4& v)
    {
        m_x = v.x();
        m_y = v.y();
        m_z = v.z();
        m_w = v.w();
        return *this;
    }

    Vec4  operator+() const{return Vec4(m_x, m_y, m_z, m_w);}; //!< Overloaded unary (+) operator. Returns the same vector.
    Vec4  operator-() const{return Vec4(-m_x, -m_y, -m_z, -m_w);} //!< Overloaded unary (-) operator. Returns the opposite vector.


    // Prefix
    Vec4& operator++(); //!< Overloaded prefix (++) operator. Returns the vector and increments its components by one.
    Vec4& operator--(); //!< Overloaded prefix (--) operator. Returns the vector and decrements its components by one.
    // Postfix
    Vec4 operator++(int); //!< Overloaded postfix (++) operator. Increments the vectors components by one and returns it.
    Vec4 operator--(int); //!< Overloaded postfix (--) operator. Decrements the vectors components by one and returns it.


    Vec4& operator+=(const double& num); //!< Overloaded unary (+=) operator. Increments the vector's components by a value num.
    Vec4& operator+=(const Vec4& v);
    Vec4& operator-=(const double& num); //!< Overloaded unary (-=) operator. Decrements the vector's components by a value num.
    Vec4& operator-=(const Vec4& v);
    Vec4& operator*=(const double& num); //!< Overloaded unary (*=) operator. Multiplies the vector's components by a value num.


    Vec4& normalize(); //!< Makes the vector a unit vector of length one.
    double length()const; //!< Returns the length of the vector.


private:

    double m_x;
    double m_y;
    double m_z;
    double m_w;

};

Vec4 operator+(const Vec4&, const Vec4&); //!< Overloaded binary (+) operator. Addition of two vectors.
Vec4 operator+(const Vec4&, const double&); //!< Overloaded binary (+) operator. Addition of a vector and a number.
Vec4 operator+(const double&, const Vec4&); //!< Overloaded binary (+) operator. Addition of a vector and a number.

Vec4 operator-(const Vec4&, const Vec4&); //!< Overloaded binary (-) operator. Subtraction of two vectors.
Vec4 operator-(const Vec4&, const double&); //!< Overloaded binary (-) operator. Subtraction of a vector and a number.
Vec4 operator-(const double&, const Vec4&);  //!< Overloaded binary (-) operator. Subtraction of a vector and a number.

Vec4 operator*(const Vec4&, const Vec4&); //!< Overloaded binary (*) operator. Multiplication of two vectors.
Vec4 operator*(const Vec4&, const double&); //!< Overloaded binary (*) operator. Multiplication of a vector and a number.
Vec4 operator*(const double&, const Vec4&); //!< Overloaded binary (*) operator. Multiplication of a vector and a number.

Vec4 operator/(const Vec4&, const Vec4&); //!< Overloaded binary (/) operator. Division of two vectors component by component.
Vec4 operator/(const Vec4&, const double&); //!< Overloaded binary (/) operator. Division of a vector's components by a number.

bool operator==(const Vec4&, const Vec4&); //!< Overloaded binary (==) operator. Checks if two vectors are identical.
bool operator!=(const Vec4&, const Vec4&); //!< Overloaded binary (!=) operator. Checks if two vectors are not identical.

std::istream& operator>>(std::istream& in, Vec4& v); //!< Overloaded binary (>>) operator. Reads a vector's components from a stream.
std::ostream& operator<<(std::ostream&, const Vec4&); //!< Overloaded binary (<<) operator. Prints a vector's components to a stream.

double dot(const Vec4&, const Vec4&); //!< The dot product of two vectors. Returns a number of type double.

Vec4 getUnitVectorOf(const Vec4&); //!< Gets the unit vector of a vector without changing the provided vector.


#endif // VEC4_H
