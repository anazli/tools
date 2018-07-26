#define CATCH_CONFIG_MAIN
#include<cmath>
#include "../catch.hpp"
#include "../include/vec3.h"

Vec3 origin = Vec3();
double x = 1.;
double y = 3.;
double z = 4.;
double num = 9.;
Vec3 v = Vec3(x,y,z);

TEST_CASE("vector is properly created", "[vector]")
{
    REQUIRE(origin == Vec3(0,0,0));
    REQUIRE(Vec3(v) == v);
}

TEST_CASE("check addition", "[vector]")
{
    REQUIRE(origin + v == v);
    REQUIRE(origin + v == v + origin);
    REQUIRE(v + num == Vec3(v.x()+num, v.y()+num, v.z()+num));
    REQUIRE(v - num == Vec3(v.x()-num, v.y()-num, v.z()-num));
    REQUIRE(v + num == num + v);
    REQUIRE(v - num == num - v);
}

TEST_CASE("check multiplication", "[vector]")
{
    REQUIRE(origin * v == origin);
    REQUIRE(origin * v == v * origin);
    REQUIRE(v * num == Vec3(v.x()*num, v.y()*num, v.z()*num));
    REQUIRE(v * num == num * v);
}

TEST_CASE("check division", "[vector]")
{
    REQUIRE_THROWS_WITH(v/0., "Division by zero!");
    REQUIRE_THROWS_WITH(v/origin, "Division by zero!");
    REQUIRE(v/1. == v);
    REQUIRE(v/num == v * 1./num);
    REQUIRE(v/num == Vec3(v.x()/num, v.y()/num, v.z()/num));
    REQUIRE(v/v == Vec3(v.x()/v.x(), v.y()/v.y(), v.z()/v.z()));
}

TEST_CASE("is vector's length correct?", "[vector]")
{
    REQUIRE(origin.magnitude() == 0.);
    REQUIRE(Vec3(2.,2.,4.).magnitude() == sqrt(24.));
    REQUIRE(Vec3(1.,3.,4.).magnitude() == sqrt(26.));
}

TEST_CASE("check normalization", "[vector]")
{
    REQUIRE_THROWS_WITH(origin.normalize(), "Division by zero!");
    REQUIRE(Vec3(4.,5.,6.).normalize().magnitude() == 1.);
}

TEST_CASE("check dot product", "[vector]")
{
    REQUIRE(dot(origin, origin) == Vec3());
    REQUIRE(dot(v, v) == v.magnitude() * v.magnitude());
    REQUIRE(dot(Vec3(1.,0.,0.), Vec3(0.,1.,0.)) == 0.);
    REQUIRE(dot(Vec3(1.,0.,0.), Vec3(1.,0.,0.)) == 1.);
}

TEST_CASE("check cross product", "[vector]")
{
    REQUIRE(cross(Vec3(1.,0.,0.),Vec3(0.,1.,0.)) == Vec3(0.,0.,1.));
}

TEST_CASE("check getUnitVectorOf", "[vector]")
{
    Vec3 t = getUnitVectorOf(Vec3(7.,5.,3.));
    REQUIRE(t.magnitude() == 1.);
    REQUIRE_THROWS_WITH(getUnitVectorOf(origin), "Division by zero!");
}
