#include "../include/vec2.h"
#include "../include/vec3.h"
#include "../include/vec4.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

//--------------------------------------------
//     VEC3
//--------------------------------------------

class Vector2 : public Test {
 public:
  Vec2<double> v;
};

TEST_F(Vector2, CreatesVector) {
  v = Vec2<double>(0., 0.);
  ASSERT_DOUBLE_EQ(v.x(), 0.);
  ASSERT_DOUBLE_EQ(v.y(), 0.);
}

TEST_F(Vector2, AssertsOutOfBounds) {
  v = Vec2<double>(1., 2.);
  ASSERT_DEATH(v[2], "");
  ASSERT_DEATH(v[-1], "");
}

TEST_F(Vector2, SetsCoords) {
  v.setX(5.);
  v[1] = 4.;
  ASSERT_DOUBLE_EQ(v.x(), 5.);
  ASSERT_DOUBLE_EQ(v[1], 4.);
}

TEST_F(Vector2, SetXY) {
  v.setXY(-1.24, -5.54);
  ASSERT_DOUBLE_EQ(v.x(), -1.24);
  ASSERT_DOUBLE_EQ(v.y(), -5.54);

  v.setXY(6.68);
  ASSERT_DOUBLE_EQ(v.x(), 6.68);
  ASSERT_DOUBLE_EQ(v.y(), 6.68);
}

TEST_F(Vector2, ChangesSign) {
  v.setXY(-1.55);
  v = -v;
  ASSERT_DOUBLE_EQ(v[0], 1.55);
  ASSERT_DOUBLE_EQ(v[1], 1.55);
}

TEST_F(Vector2, AddsVectorOrNumber) {
  v = Vec2<double>(0., 0.);
  v += 4.46;
  ASSERT_DOUBLE_EQ(v.x(), 4.46);
  ASSERT_DOUBLE_EQ(v.y(), 4.46);

  v += Vec2<double>(4., 6.);
  ASSERT_DOUBLE_EQ(v.x(), 8.46);
  ASSERT_DOUBLE_EQ(v.y(), 10.46);
}

TEST_F(Vector2, SubtractsVectorOrNumber) {
  v = Vec2<double>(0., 0.);
  v -= 4.46;
  ASSERT_DOUBLE_EQ(v.x(), -4.46);
  ASSERT_DOUBLE_EQ(v.y(), -4.46);

  v -= Vec2<double>(4., 6.);
  ASSERT_DOUBLE_EQ(v.x(), -8.46);
  ASSERT_DOUBLE_EQ(v.y(), -10.46);
}

TEST_F(Vector2, GetsLenghtOfVector) {
  v = Vec2<double>(0., 0.);
  ASSERT_DOUBLE_EQ(v.length(), 0.);
  v = Vec2<double>(1., 1.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(2.));
  v = Vec2<double>(3., 3.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(18.));
  v = Vec2<double>(-5., -5.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(50.));
}

TEST_F(Vector2, MultipliesVectorWithNumber) {
  v = Vec2<double>(1., 0.);
  v *= 5.;
  ASSERT_DOUBLE_EQ(v.x(), 5.);
  ASSERT_DOUBLE_EQ(v.y(), 0.);
}

TEST_F(Vector2, NormalizesVector) {
  v = Vec2<double>(4.53, 93.5);
  ASSERT_DOUBLE_EQ(v.normalize().length(), 1.);
}

TEST_F(Vector2, DotProduct) {
  v = Vec2<double>(3., 3.);
  ASSERT_DOUBLE_EQ(dot(v, Vec2<double>(3., 3.)), 18.);
  v = Vec2<double>(-1., 5.);
  ASSERT_DOUBLE_EQ(dot(v, Vec2<double>(-3., 3.)), 18.);
}

TEST_F(Vector2, GetUnitVectorOf) {
  v = Vec2<double>(4.36, 7.62);
  v = getUnitVectorOf(v);
  ASSERT_DOUBLE_EQ(v.length(), 1.);
}

TEST_F(Vector2, AddsTwoVectors) {
  v = Vec2<double>(4.532, 45.67);
  v = v + Vec2<double>(0.3456, 124.67);
  ASSERT_DOUBLE_EQ(v.x(), 4.8776);
  ASSERT_DOUBLE_EQ(v.y(), 170.34);
}

TEST_F(Vector2, SubtractsTwoVectors) {
  v = Vec2<double>(40.54, 2.4);
  v = v - Vec2<double>(4.20, -1.7);
  ASSERT_DOUBLE_EQ(v[0], 36.34);
  ASSERT_DOUBLE_EQ(v[1], 4.1);
}

TEST_F(Vector2, DevidesVectorByNumber) {
  v = Vec2<double>(36.6, -30.6);
  v = v / 3.;
  ASSERT_DOUBLE_EQ(v.x(), 36.6 / 3.);
  ASSERT_DOUBLE_EQ(v.y(), -30.6 / 3.);
}

TEST_F(Vector2, DevidesVectorByVector) {
  v = Vec2<double>(434.5, 93.5);
  v = v / Vec2<double>(32.5, -16.2);
  ASSERT_DOUBLE_EQ(v.x(), 434.5 / 32.5);
  ASSERT_DOUBLE_EQ(v.y(), -93.5 / 16.2);
}

TEST_F(Vector2, TestsEquality) {
  v = Vec2<double>(4.2, -6.54);
  ASSERT_TRUE(v == Vec2<double>(4.2, -6.54));
}

TEST_F(Vector2, TestsInequality) {
  v = Vec2<double>(4.2, -6.54);
  ASSERT_TRUE(v != Vec2<double>(-4.2, -4.36));
}

//--------------------------------------------
//     VEC3
//--------------------------------------------

class Vector3 : public Test {
 public:
  Vec3<double> v;
};

TEST_F(Vector3, CreatesVector) {
  v = Vec3<double>(0., 0., 0.);
  ASSERT_DOUBLE_EQ(v.x(), 0.);
  ASSERT_DOUBLE_EQ(v.y(), 0.);
  ASSERT_DOUBLE_EQ(v.z(), 0.);
}

TEST_F(Vector3, AssertsOutOfBounds) {
  v = Vec3<double>(1., 2., 0.5);
  ASSERT_DEATH(v[3], "");
  ASSERT_DEATH(v[-1], "");
}

TEST_F(Vector3, SetsCoords) {
  v.setX(5.);
  v[1] = 4.;
  v[2] = 0.2;
  ASSERT_DOUBLE_EQ(v.x(), 5.);
  ASSERT_DOUBLE_EQ(v[1], 4.);
  ASSERT_DOUBLE_EQ(v[2], 0.2);
}

TEST_F(Vector3, SetXYZ) {
  v.setXYZ(-1.24, -5.54, 45.6);
  ASSERT_DOUBLE_EQ(v.x(), -1.24);
  ASSERT_DOUBLE_EQ(v.y(), -5.54);
  ASSERT_DOUBLE_EQ(v.z(), 45.6);

  v.setXYZ(6.68);
  ASSERT_DOUBLE_EQ(v.x(), 6.68);
  ASSERT_DOUBLE_EQ(v.y(), 6.68);
  ASSERT_DOUBLE_EQ(v.z(), 6.68);
}

TEST_F(Vector3, ChangesSign) {
  v.setXYZ(-1.55);
  v = -v;
  ASSERT_DOUBLE_EQ(v[0], 1.55);
  ASSERT_DOUBLE_EQ(v[1], 1.55);
  ASSERT_DOUBLE_EQ(v[2], 1.55);
}

TEST_F(Vector3, AddsVectorOrNumber) {
  v = Vec3<double>(0., 0., 5.);
  v += 4.46;
  ASSERT_DOUBLE_EQ(v.x(), 4.46);
  ASSERT_DOUBLE_EQ(v.y(), 4.46);
  ASSERT_DOUBLE_EQ(v.z(), 9.46);

  v += Vec3<double>(4., 6., 0.);
  ASSERT_DOUBLE_EQ(v.x(), 8.46);
  ASSERT_DOUBLE_EQ(v.y(), 10.46);
  ASSERT_DOUBLE_EQ(v.z(), 9.46);
}

TEST_F(Vector3, SubtractsVectorOrNumber) {
  v = Vec3<double>(0., 0., 3.);
  v -= 4.46;
  ASSERT_DOUBLE_EQ(v.x(), -4.46);
  ASSERT_DOUBLE_EQ(v.y(), -4.46);
  ASSERT_DOUBLE_EQ(v.z(), -1.46);

  v -= Vec3<double>(4., 6., 0.);
  ASSERT_DOUBLE_EQ(v.x(), -8.46);
  ASSERT_DOUBLE_EQ(v.y(), -10.46);
  ASSERT_DOUBLE_EQ(v.z(), -1.46);
}

TEST_F(Vector3, GetsLenghtOfVector) {
  v = Vec3<double>(0., 0., 0.);
  ASSERT_DOUBLE_EQ(v.length(), 0.);
  v = Vec3<double>(1., 1., 1.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(3.));
  v = Vec3<double>(3., 3., 3.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(27.));
  v = Vec3<double>(-5., -5., 5.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(75.));
}

TEST_F(Vector3, MultipliesVectorWithNumber) {
  v = Vec3<double>(1., 0., 5.);
  v *= 5.;
  ASSERT_DOUBLE_EQ(v.x(), 5.);
  ASSERT_DOUBLE_EQ(v.y(), 0.);
  ASSERT_DOUBLE_EQ(v.z(), 25.);
}

TEST_F(Vector3, NormalizesVector) {
  v = Vec3<double>(4.53, 93.5, -56.3);
  ASSERT_DOUBLE_EQ(v.normalize().length(), 1.);
}

TEST_F(Vector3, DotProduct) {
  v = Vec3<double>(3., 3., 4.);
  ASSERT_DOUBLE_EQ(dot(v, Vec3<double>(3., 3., 9.)), 54.);
  v = Vec3<double>(-1., 5., 9.);
  ASSERT_DOUBLE_EQ(dot(v, Vec3<double>(-3., 3., 6.)), 72.);
}

TEST_F(Vector3, GetUnitVectorOf) {
  v = Vec3<double>(4.36, 7.62, 0.466);
  v = getUnitVectorOf(v);
  ASSERT_DOUBLE_EQ(v.length(), 1.);
}

TEST_F(Vector3, AddsTwoVectors) {
  v = Vec3<double>(4.532, 45.67, 0.83);
  v = v + Vec3<double>(0.3456, 124.67, 1.);
  ASSERT_DOUBLE_EQ(v.x(), 4.8776);
  ASSERT_DOUBLE_EQ(v.y(), 170.34);
  ASSERT_DOUBLE_EQ(v.z(), 1.83);
}

TEST_F(Vector3, SubtractsTwoVectors) {
  v = Vec3<double>(40.54, 2.4, 0.62);
  v = v - Vec3<double>(4.20, -1.7, -1.);
  ASSERT_DOUBLE_EQ(v[0], 36.34);
  ASSERT_DOUBLE_EQ(v[1], 4.1);
  ASSERT_DOUBLE_EQ(v[2], 1.62);
}

TEST_F(Vector3, DevidesVectorByNumber) {
  v = Vec3<double>(36.6, -30.6, 120.2586);
  v = v / 3.;
  ASSERT_DOUBLE_EQ(v.x(), 36.6 / 3.);
  ASSERT_DOUBLE_EQ(v.y(), -30.6 / 3.);
  ASSERT_DOUBLE_EQ(v.z(), 120.2586 / 3.);
}

TEST_F(Vector3, DevidesVectorByVector) {
  v = Vec3<double>(434.5, 93.5, 3858.53);
  v = v / Vec3<double>(32.5, -16.2, 0.567);
  ASSERT_DOUBLE_EQ(v.x(), 434.5 / 32.5);
  ASSERT_DOUBLE_EQ(v.y(), -93.5 / 16.2);
  ASSERT_DOUBLE_EQ(v.z(), 3858.53 / 0.567);
}

TEST_F(Vector3, TestsEquality) {
  v = Vec3<double>(4.2, -6.54, 34855.38596);
  ASSERT_TRUE(v == Vec3<double>(4.2, -6.54, 34855.38596));
}

TEST_F(Vector3, TestsInequality) {
  v = Vec3<double>(4.2, -6.54, 0.0);
  ASSERT_TRUE(v != Vec3<double>(4.2, -4.36, 0.0));
}

//--------------------------------------------
//     VEC4
//--------------------------------------------

class Vector4 : public Test {
 public:
  Vec4<double> v;
};

TEST_F(Vector4, CreatesVector) {
  v = Vec4<double>(0., 0., 0., 0.);
  ASSERT_DOUBLE_EQ(v.x(), 0.);
  ASSERT_DOUBLE_EQ(v.y(), 0.);
  ASSERT_DOUBLE_EQ(v.z(), 0.);
  ASSERT_DOUBLE_EQ(v.w(), 0.);
}

TEST_F(Vector4, AssertsOutOfBounds) {
  v = Vec4<double>(1., 2., 0.5, 7.5);
  ASSERT_DEATH(v[4], "");
  ASSERT_DEATH(v[-1], "");
}

TEST_F(Vector4, SetsCoords) {
  v.setX(5.);
  v[1] = 4.;
  v[2] = 0.2;
  v.setW(-5.2);
  ASSERT_DOUBLE_EQ(v.x(), 5.);
  ASSERT_DOUBLE_EQ(v[1], 4.);
  ASSERT_DOUBLE_EQ(v[2], 0.2);
  ASSERT_DOUBLE_EQ(v[3], -5.2);
}

TEST_F(Vector4, SetXYZ) {
  v.setXYZW(-1.24, -5.54, 45.6, -0.5);
  ASSERT_DOUBLE_EQ(v.x(), -1.24);
  ASSERT_DOUBLE_EQ(v.y(), -5.54);
  ASSERT_DOUBLE_EQ(v.z(), 45.6);
  ASSERT_DOUBLE_EQ(v.w(), -0.5);

  v.setXYZW(6.68);
  ASSERT_DOUBLE_EQ(v.x(), 6.68);
  ASSERT_DOUBLE_EQ(v.y(), 6.68);
  ASSERT_DOUBLE_EQ(v.z(), 6.68);
  ASSERT_DOUBLE_EQ(v.w(), 6.68);
}

TEST_F(Vector4, ChangesSign) {
  v.setXYZW(-1.55);
  v = -v;
  ASSERT_DOUBLE_EQ(v[0], 1.55);
  ASSERT_DOUBLE_EQ(v[1], 1.55);
  ASSERT_DOUBLE_EQ(v[2], 1.55);
  ASSERT_DOUBLE_EQ(v[3], 1.55);
}

TEST_F(Vector4, AddsVectorOrNumber) {
  v = Vec4<double>(0., 0., 5., 3.5);
  v += 4.46;
  ASSERT_DOUBLE_EQ(v.x(), 4.46);
  ASSERT_DOUBLE_EQ(v.y(), 4.46);
  ASSERT_DOUBLE_EQ(v.z(), 9.46);
  ASSERT_DOUBLE_EQ(v.w(), 7.96);

  v += Vec4<double>(4., 6., 0., 45.);
  ASSERT_DOUBLE_EQ(v.x(), 8.46);
  ASSERT_DOUBLE_EQ(v.y(), 10.46);
  ASSERT_DOUBLE_EQ(v.z(), 9.46);
  ASSERT_DOUBLE_EQ(v.w(), 52.96);
}

TEST_F(Vector4, SubtractsVectorOrNumber) {
  v = Vec4<double>(0., 0., 3., -5.5);
  v -= 4.46;
  ASSERT_DOUBLE_EQ(v.x(), -4.46);
  ASSERT_DOUBLE_EQ(v.y(), -4.46);
  ASSERT_DOUBLE_EQ(v.z(), -1.46);
  ASSERT_DOUBLE_EQ(v.w(), -9.96);

  v -= Vec4<double>(4., 6., 0., -1.2);
  ASSERT_DOUBLE_EQ(v.x(), -8.46);
  ASSERT_DOUBLE_EQ(v.y(), -10.46);
  ASSERT_DOUBLE_EQ(v.z(), -1.46);
  ASSERT_DOUBLE_EQ(v.w(), -8.76);
}

TEST_F(Vector4, GetsLenghtOfVector) {
  v = Vec4<double>(0., 0., 0., 0.);
  ASSERT_DOUBLE_EQ(v.length(), 0.);
  v = Vec4<double>(1., 1., 1., 1.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(4.));
  v = Vec4<double>(3., 3., 3., 3.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(36.));
  v = Vec4<double>(-5., -5., 5., 5.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(100.));
}

TEST_F(Vector4, MultipliesVectorWithNumber) {
  v = Vec4<double>(1., 0., 5., -9.);
  v *= 5.;
  ASSERT_DOUBLE_EQ(v.x(), 5.);
  ASSERT_DOUBLE_EQ(v.y(), 0.);
  ASSERT_DOUBLE_EQ(v.z(), 25.);
  ASSERT_DOUBLE_EQ(v.w(), -45.);
}

TEST_F(Vector4, NormalizesVector) {
  v = Vec4<double>(4.53, 93.5, -56.3, -100.00001);
  ASSERT_DOUBLE_EQ(v.normalize().length(), 1.);
}

TEST_F(Vector4, DotProduct) {
  v = Vec4<double>(3., 3., 4., 1.);
  ASSERT_DOUBLE_EQ(dot(v, Vec4<double>(3., 3., 9., -10.)), 44.);
  v = Vec4<double>(-1., 5., 9., -3.);
  ASSERT_DOUBLE_EQ(dot(v, Vec4<double>(-3., 3., 6., 0.)), 72.);
}

TEST_F(Vector4, GetUnitVectorOf) {
  v = Vec4<double>(4.36, 7.62, 0.466, -30485.55555555);
  v = getUnitVectorOf(v);
  ASSERT_DOUBLE_EQ(v.length(), 1.);
}

TEST_F(Vector4, AddsTwoVectors) {
  v = Vec4<double>(4.532, 45.67, 0.83, -44.6);
  v = v + Vec4<double>(0.3456, 124.67, 1., 9.);
  ASSERT_DOUBLE_EQ(v.x(), 4.8776);
  ASSERT_DOUBLE_EQ(v.y(), 170.34);
  ASSERT_DOUBLE_EQ(v.z(), 1.83);
  ASSERT_DOUBLE_EQ(v.w(), -35.6);
}

TEST_F(Vector4, SubtractsTwoVectors) {
  v = Vec4<double>(40.54, 2.4, 0.62, 0.);
  v = v - Vec4<double>(4.20, -1.7, -1., -99.99999);
  ASSERT_DOUBLE_EQ(v[0], 36.34);
  ASSERT_DOUBLE_EQ(v[1], 4.1);
  ASSERT_DOUBLE_EQ(v[2], 1.62);
  ASSERT_DOUBLE_EQ(v[3], 99.99999);
}

TEST_F(Vector4, DevidesVectorByNumber) {
  v = Vec4<double>(36.6, -30.6, 120.2586, -0.5555555);
  v = v / 3.;
  ASSERT_DOUBLE_EQ(v.x(), 36.6 / 3.);
  ASSERT_DOUBLE_EQ(v.y(), -30.6 / 3.);
  ASSERT_DOUBLE_EQ(v.z(), 120.2586 / 3.);
  ASSERT_DOUBLE_EQ(v.w(), -0.5555555 / 3.);
}

TEST_F(Vector4, DevidesVectorByVector) {
  v = Vec4<double>(434.5, 93.5, 3858.53, -0.99999999);
  v = v / Vec4<double>(32.5, -16.2, 0.567, -999.99999999);
  ASSERT_DOUBLE_EQ(v.x(), 434.5 / 32.5);
  ASSERT_DOUBLE_EQ(v.y(), -93.5 / 16.2);
  ASSERT_DOUBLE_EQ(v.z(), 3858.53 / 0.567);
  ASSERT_DOUBLE_EQ(v[3], -0.99999999 / (-999.99999999));
}

TEST_F(Vector4, TestsEquality) {
  v = Vec4<double>(4.2, -6.54, 34855.38596, -0.9938375);
  ASSERT_TRUE(v == Vec4<double>(4.2, -6.54, 34855.38596, -0.9938375));
}

TEST_F(Vector4, TestsInequality) {
  v = Vec4<double>(4.2, -6.54, 0.0, 100.);
  ASSERT_TRUE(v != Vec4<double>(4.2, -4.36, 0.0, 100.));
}