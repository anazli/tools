#include "gtest/gtest.h"
#include "tools.h"

//--------------------------------------------
//     VEC2
//--------------------------------------------
//
void comparePoints(const Point3D& p1, const Point3D& p2) {
    EXPECT_FLOAT_EQ(p1.x(), p2.x());
    EXPECT_FLOAT_EQ(p1.y(), p2.y());
    EXPECT_FLOAT_EQ(p1.z(), p2.z());
}

void comparePointsApprox(const Point3D& p1, const Point3D& p2, float eps) {
    EXPECT_NEAR(p1.x(), p2.x(), eps);
    EXPECT_NEAR(p1.y(), p2.y(), eps);
    EXPECT_NEAR(p1.z(), p2.z(), eps);
}

void compareVectors(const Vec3D& v1, const Vec3D& v2) {
    EXPECT_FLOAT_EQ(v1.x(), v2.x());
    EXPECT_FLOAT_EQ(v1.y(), v2.y());
    EXPECT_FLOAT_EQ(v1.z(), v2.z());
}

void compareVectorsApprox(const Vec3D& v1, const Vec3D& v2, float eps) {
    EXPECT_NEAR(v1.x(), v2.x(), eps);
    EXPECT_NEAR(v1.y(), v2.y(), eps);
    EXPECT_NEAR(v1.z(), v2.z(), eps);
}


class Vector2Test : public testing::Test {
 public:
  Vec2<double> v;
};

TEST_F(Vector2Test, CreatesVector) {
  v = Vec2<double>(0., 0.);
  ASSERT_DOUBLE_EQ(v.x(), 0.);
  ASSERT_DOUBLE_EQ(v.y(), 0.);
}

TEST_F(Vector2Test, AssertsOutOfBounds) {
  v = Vec2<double>(1., 2.);
  ASSERT_DEATH(v[2], "");
  ASSERT_DEATH(v[-1], "");
}

TEST_F(Vector2Test, SetsCoords) {
  v.setX(5.);
  v[1] = 4.;
  ASSERT_DOUBLE_EQ(v.x(), 5.);
  ASSERT_DOUBLE_EQ(v[1], 4.);
}

TEST_F(Vector2Test, SetXY) {
  v.set(-1.24, -5.54);
  ASSERT_DOUBLE_EQ(v.x(), -1.24);
  ASSERT_DOUBLE_EQ(v.y(), -5.54);

  v.set(6.68);
  ASSERT_DOUBLE_EQ(v.x(), 6.68);
  ASSERT_DOUBLE_EQ(v.y(), 6.68);
}

TEST_F(Vector2Test, ChangesSign) {
  v.set(-1.55);
  v = -v;
  ASSERT_DOUBLE_EQ(v[0], 1.55);
  ASSERT_DOUBLE_EQ(v[1], 1.55);
}

TEST_F(Vector2Test, AddsVectorOrNumber) {
  v = Vec2<double>(0., 0.);
  v = v + 4.46;
  ASSERT_DOUBLE_EQ(v.x(), 4.46);
  ASSERT_DOUBLE_EQ(v.y(), 4.46);

  v = v + Vec2<double>(4., 6.);
  ASSERT_DOUBLE_EQ(v.x(), 8.46);
  ASSERT_DOUBLE_EQ(v.y(), 10.46);
}

TEST_F(Vector2Test, SubtractsVectorOrNumber) {
  v = Vec2<double>(0., 0.);
  v = v - 4.46;
  ASSERT_DOUBLE_EQ(v.x(), -4.46);
  ASSERT_DOUBLE_EQ(v.y(), -4.46);

  v = v - Vec2<double>(4., 6.);
  ASSERT_DOUBLE_EQ(v.x(), -8.46);
  ASSERT_DOUBLE_EQ(v.y(), -10.46);
}

TEST_F(Vector2Test, GetsLenghtOfVector) {
  v = Vec2<double>(0., 0.);
  auto eps = 1E-6;
  ASSERT_DOUBLE_EQ(v.length(), 0.);
  v = Vec2<double>(1., 1.);
  EXPECT_NEAR(v.length(), sqrt(2.), eps);
  v = Vec2<double>(3., 3.);
  EXPECT_NEAR(v.length(), sqrt(18.), eps);
  v = Vec2<double>(-5., -5.);
  EXPECT_NEAR(v.length(), sqrt(50.), eps);
}

TEST_F(Vector2Test, MultipliesVectorWithNumber) {
  v = Vec2<double>(1., 0.);
  v = v * 5.;
  ASSERT_DOUBLE_EQ(v.x(), 5.);
  ASSERT_DOUBLE_EQ(v.y(), 0.);
}

TEST_F(Vector2Test, NormalizesVector) {
  v = Vec2<double>(4.53, 93.5);
  v.normalize();
  ASSERT_DOUBLE_EQ(v.length(), 1.);
}

TEST_F(Vector2Test, DotProduct) {
  v = Vec2<double>(3., 3.);
  ASSERT_DOUBLE_EQ(dot(v, Vec2<double>(3., 3.)), 18.);
  v = Vec2<double>(-1., 5.);
  ASSERT_DOUBLE_EQ(dot(v, Vec2<double>(-3., 3.)), 18.);
}

TEST_F(Vector2Test, GetUnitVectorOf) {
  v = Vec2<double>(4.36, 7.62);
  v = getUnitVectorOf(v);
  ASSERT_DOUBLE_EQ(v.length(), 1.);
}

TEST_F(Vector2Test, AddsTwoVectors) {
  v = Vec2<double>(4.532, 45.67);
  v = v + Vec2<double>(0.3456, 124.67);
  ASSERT_DOUBLE_EQ(v.x(), 4.8776);
  ASSERT_DOUBLE_EQ(v.y(), 170.34);
}

TEST_F(Vector2Test, SubtractsTwoVectors) {
  v = Vec2<double>(40.54, 2.4);
  v = v - Vec2<double>(4.20, -1.7);
  ASSERT_DOUBLE_EQ(v[0], 36.34);
  ASSERT_DOUBLE_EQ(v[1], 4.1);
}

TEST_F(Vector2Test, DevidesVectorByNumber) {
  v = Vec2<double>(36.6, -30.6);
  v = v / 3.;
  ASSERT_DOUBLE_EQ(v.x(), 36.6 / 3.);
  ASSERT_DOUBLE_EQ(v.y(), -30.6 / 3.);
}

TEST_F(Vector2Test, DevidesVectorByVector) {
  v = Vec2<double>(434.5, 93.5);
  v = v / Vec2<double>(32.5, -16.2);
  ASSERT_DOUBLE_EQ(v.x(), 434.5 / 32.5);
  ASSERT_DOUBLE_EQ(v.y(), -93.5 / 16.2);
}

TEST_F(Vector2Test, TestsEquality) {
  v = Vec2<double>(4.2, -6.54);
  ASSERT_TRUE(v == Vec2<double>(4.2, -6.54));
}

TEST_F(Vector2Test, TestsInequality) {
  v = Vec2<double>(4.2, -6.54);
  ASSERT_TRUE(v != Vec2<double>(-4.2, -4.36));
}

//--------------------------------------------
//     VEC3
//--------------------------------------------

class Vector3Test : public testing::Test {
 public:
  Vec3D v;
};

TEST_F(Vector3Test, CreatesVector) {
  v = Vec3D(0.f, 0.f, 0.f);
  compareVectors(v, Vec3D());
}

TEST_F(Vector3Test, AssertsOutOfBounds) {
  v = Vec3D(1.f, 2.f, 0.5f);
  ASSERT_DEATH(v[3], "");
  ASSERT_DEATH(v[-1], "");
}

TEST_F(Vector3Test, SetsCoords) {
  v.setX(5.);
  v[1] = 4.;
  v[2] = 0.2;
  compareVectors(v, Vec3D(5.f, 4.f, 0.2f));
}

TEST_F(Vector3Test, SetXYZ) {
  v.set(-1.24f, -5.54f, 45.6f);
  compareVectors(v, Vec3D(-1.24f, -5.54f, 45.6f));

  v.set(6.68f);
  compareVectors(v, Vec3D(6.68f, 6.68f, 6.68f));
}

TEST_F(Vector3Test, ChangesSign) {
  v.set(-1.55);
  v = -v;
  compareVectors(v, Vec3D(1.55f, 1.55f, 1.55f));
}

TEST_F(Vector3Test, AddsVectorOrNumber) {
  v = Vec3D(0.f, 0.f, 5.f);
  v = v + 4.46f;
  compareVectors(v, Vec3D(4.46f, 4.46f, 9.46f));

  v = v + Vec3D(4.f, 6.f, 0.f);
  compareVectors(v, Vec3D(8.46f, 10.46f, 9.46f));
}

TEST_F(Vector3Test, SubtractsVectorOrNumber) {
  v = Vec3D(0.f, 0.f, 3.f);
  v = v - 4.46f;
  compareVectors(v, Vec3D(-4.46f, -4.46f, -1.46f));

  v = v - Vec3D(4.f, 6.f, 0.f);
  compareVectors(v, Vec3D(-8.46f, -10.46f, -1.46f));
}

TEST_F(Vector3Test, GetsLenghtOfVector) {
  v = Vec3D(0.f, 0.f, 0.f);
  ASSERT_FLOAT_EQ(v.length(), 0.f);
  v = Vec3D(1.f, 1.f, 1.f);
  ASSERT_FLOAT_EQ(v.length(), sqrt(3.f));
  v = Vec3D(3.f, 3.f, 3.f);
  ASSERT_FLOAT_EQ(v.length(), sqrt(27.f));
  v = Vec3D(-5.f, -5.f, 5.f);
  ASSERT_FLOAT_EQ(v.length(), sqrt(75.f));
}

TEST_F(Vector3Test, MultipliesVectorWithNumber) {
  v = Vec3D(1.f, 0.f, 5.f) * 5.f;
  compareVectors(v, Vec3D(5.f, 0.f, 25.f));
}

TEST_F(Vector3Test, NormalizesVector) {
  v = Vec3D(4.53f, 93.5f, -56.3f);
  v.normalize();
  ASSERT_DOUBLE_EQ(v.length(), 1.f);
}

TEST_F(Vector3Test, DotProduct) {
  v = Vec3D(3.f, 3.f, 4.f);
  ASSERT_DOUBLE_EQ(dot(v, Vec3D(3.f, 3.f, 9.f)), 54.f);
  v = Vec3D(-1.f, 5.f, 9.f);
  ASSERT_FLOAT_EQ(dot(v, Vec3D(-3.f, 3.f, 6.f)), 72.f);
}

TEST_F(Vector3Test, GetUnitVectorOf) {
  v = Vec3D(4.36f, 7.62f, 0.466f);
  v = getUnitVectorOf(v);
  ASSERT_FLOAT_EQ(v.length(), 1.f);
}

TEST_F(Vector3Test, AddsTwoVectors) {
  v = Vec3D(4.532f, 45.67f, 0.83f);
  v = v + Vec3D(0.3456f, 124.67f, 1.f);
  compareVectors(v, Vec3D(4.8776f, 170.34f, 1.83f));
}

TEST_F(Vector3Test, SubtractsTwoVectors) {
  v = Vec3D(40.54f, 2.4f, 0.62f);
  v = v - Vec3D(4.20f, -1.7f, -1.f);
  compareVectors(v, Vec3D(36.34f, 4.1f, 1.62f));
}

TEST_F(Vector3Test, DevidesVectorByNumber) {
  v = Vec3D(36.6f, -30.6f, 120.2586f);
  v = v / 3.f;
  compareVectors(v, Vec3D(36.6f / 3.f, -30.6f / 3.f, 120.2586f / 3.f));
}

TEST_F(Vector3Test, DevidesVectorByVector) {
  v = Vec3D(434.5f, 93.5f, 3858.53f);
  v = v / Vec3D(32.5f, -16.2f, 0.567f);
  compareVectors(v, Vec3D(434.5f / 32.5f, -93.5f / 16.2f, 3858.53f / 0.567f));
}

TEST_F(Vector3Test, TestsEquality) {
  v = Vec3D(4.2f, -6.54f, 34855.38596f);
  ASSERT_TRUE(v == Vec3D(4.2f, -6.54f, 34855.38596f));
}

TEST_F(Vector3Test, TestsInequality) {
  v = Vec3D(4.2f, -6.54f, 0.f);
  ASSERT_TRUE(v != Vec3D(4.2f, -4.36f, 0.f));
}

TEST_F(Vector3Test, reflectsVector1) {
  v = Vec3D(1.f, -1.f, 0.f);
  Vec3D n(0.f, 1.f, 0.f);
  Vec3D r = reflect(v, n);
  ASSERT_TRUE(r == Vec3D(1.f, 1.f, 0.f));
}

TEST_F(Vector3Test, reflectsVector2) {
  v = Vec3D(0.f, -1.f, 0.f);
  Vec3D n(sqrt(2.f) / 2.f, sqrt(2.f) / 2.f, 0.f);
  Vec3D r = reflect(v, n);

  double eps = 10.E-8f;
  compareVectorsApprox(r, Vec3D(1.f, 0.f, 0.f), eps);
}

//--------------------------------------------
//     VEC4
//--------------------------------------------

class Vector4Test : public testing::Test {
 public:
  Vec4<double> v;
};

TEST_F(Vector4Test, CreatesVector) {
  v = Vec4<double>(0., 0., 0., 0.);
  ASSERT_DOUBLE_EQ(v.x(), 0.);
  ASSERT_DOUBLE_EQ(v.y(), 0.);
  ASSERT_DOUBLE_EQ(v.z(), 0.);
  ASSERT_DOUBLE_EQ(v.w(), 0.);
}

TEST_F(Vector4Test, AssertsOutOfBounds) {
  v = Vec4<double>(1., 2., 0.5, 7.5);
  ASSERT_DEATH(v[4], "");
  ASSERT_DEATH(v[-1], "");
}

TEST_F(Vector4Test, SetsCoords) {
  v.setX(5.);
  v[1] = 4.;
  v[2] = 0.2;
  v.setW(-5.2);
  ASSERT_DOUBLE_EQ(v.x(), 5.);
  ASSERT_DOUBLE_EQ(v[1], 4.);
  ASSERT_DOUBLE_EQ(v[2], 0.2);
  ASSERT_DOUBLE_EQ(v[3], -5.2);
}

TEST_F(Vector4Test, SetXYZ) {
  v.set(-1.24, -5.54, 45.6, -0.5);
  ASSERT_DOUBLE_EQ(v.x(), -1.24);
  ASSERT_DOUBLE_EQ(v.y(), -5.54);
  ASSERT_DOUBLE_EQ(v.z(), 45.6);
  ASSERT_DOUBLE_EQ(v.w(), -0.5);

  v.set(6.68);
  ASSERT_DOUBLE_EQ(v.x(), 6.68);
  ASSERT_DOUBLE_EQ(v.y(), 6.68);
  ASSERT_DOUBLE_EQ(v.z(), 6.68);
  ASSERT_DOUBLE_EQ(v.w(), 6.68);
}

TEST_F(Vector4Test, ChangesSign) {
  v.set(-1.55);
  v = -v;
  ASSERT_DOUBLE_EQ(v[0], 1.55);
  ASSERT_DOUBLE_EQ(v[1], 1.55);
  ASSERT_DOUBLE_EQ(v[2], 1.55);
  ASSERT_DOUBLE_EQ(v[3], 1.55);
}

TEST_F(Vector4Test, AddsVectorOrNumber) {
  v = Vec4<double>(0., 0., 5., 3.5);
  v = v + 4.46;
  ASSERT_DOUBLE_EQ(v.x(), 4.46);
  ASSERT_DOUBLE_EQ(v.y(), 4.46);
  ASSERT_DOUBLE_EQ(v.z(), 9.46);
  ASSERT_DOUBLE_EQ(v.w(), 7.96);

  v = v + Vec4<double>(4., 6., 0., 45.);
  ASSERT_DOUBLE_EQ(v.x(), 8.46);
  ASSERT_DOUBLE_EQ(v.y(), 10.46);
  ASSERT_DOUBLE_EQ(v.z(), 9.46);
  ASSERT_DOUBLE_EQ(v.w(), 52.96);
}

TEST_F(Vector4Test, SubtractsVectorOrNumber) {
  v = Vec4<double>(0., 0., 3., -5.5);
  v = v - 4.46;
  ASSERT_DOUBLE_EQ(v.x(), -4.46);
  ASSERT_DOUBLE_EQ(v.y(), -4.46);
  ASSERT_DOUBLE_EQ(v.z(), -1.46);
  ASSERT_DOUBLE_EQ(v.w(), -9.96);

  v = v - Vec4<double>(4., 6., 0., -1.2);
  ASSERT_DOUBLE_EQ(v.x(), -8.46);
  ASSERT_DOUBLE_EQ(v.y(), -10.46);
  ASSERT_DOUBLE_EQ(v.z(), -1.46);
  ASSERT_DOUBLE_EQ(v.w(), -8.76);
}

TEST_F(Vector4Test, GetsLenghtOfVector) {
  v = Vec4<double>(0., 0., 0., 0.);
  ASSERT_DOUBLE_EQ(v.length(), 0.);
  v = Vec4<double>(1., 1., 1., 1.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(4.));
  v = Vec4<double>(3., 3., 3., 3.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(36.));
  v = Vec4<double>(-5., -5., 5., 5.);
  ASSERT_DOUBLE_EQ(v.length(), sqrt(100.));
}

TEST_F(Vector4Test, MultipliesVectorWithNumber) {
  v = Vec4<double>(1., 0., 5., -9.);
  v = v * 5.;
  ASSERT_DOUBLE_EQ(v.x(), 5.);
  ASSERT_DOUBLE_EQ(v.y(), 0.);
  ASSERT_DOUBLE_EQ(v.z(), 25.);
  ASSERT_DOUBLE_EQ(v.w(), -45.);
}

TEST_F(Vector4Test, NormalizesVector) {
  v = Vec4<double>(4.53, 93.5, -56.3, -100.00001);
  v.normalize();
  ASSERT_DOUBLE_EQ(v.length(), 1.);
}

TEST_F(Vector4Test, DotProduct) {
  v = Vec4<double>(3., 3., 4., 1.);
  ASSERT_DOUBLE_EQ(dot(v, Vec4<double>(3., 3., 9., -10.)), 44.);
  v = Vec4<double>(-1., 5., 9., -3.);
  ASSERT_DOUBLE_EQ(dot(v, Vec4<double>(-3., 3., 6., 0.)), 72.);
}

TEST_F(Vector4Test, GetUnitVectorOf) {
  v = Vec4<double>(4.36, 7.62, 0.466, -30485.55555555);
  v = getUnitVectorOf(v);
  ASSERT_DOUBLE_EQ(v.length(), 1.);
}

TEST_F(Vector4Test, AddsTwoVectors) {
  v = Vec4<double>(4.532, 45.67, 0.83, -44.6);
  v = v + Vec4<double>(0.3456, 124.67, 1., 9.);
  ASSERT_DOUBLE_EQ(v.x(), 4.8776);
  ASSERT_DOUBLE_EQ(v.y(), 170.34);
  ASSERT_DOUBLE_EQ(v.z(), 1.83);
  ASSERT_DOUBLE_EQ(v.w(), -35.6);
}

TEST_F(Vector4Test, SubtractsTwoVectors) {
  v = Vec4<double>(40.54, 2.4, 0.62, 0.);
  v = v - Vec4<double>(4.20, -1.7, -1., -99.99999);
  ASSERT_DOUBLE_EQ(v[0], 36.34);
  ASSERT_DOUBLE_EQ(v[1], 4.1);
  ASSERT_DOUBLE_EQ(v[2], 1.62);
  ASSERT_DOUBLE_EQ(v[3], 99.99999);
}

TEST_F(Vector4Test, DevidesVectorByNumber) {
  v = Vec4<double>(36.6, -30.6, 120.2586, -0.5555555);
  v = v / 3.;
  ASSERT_DOUBLE_EQ(v.x(), 36.6 / 3.);
  ASSERT_DOUBLE_EQ(v.y(), -30.6 / 3.);
  ASSERT_DOUBLE_EQ(v.z(), 120.2586 / 3.);
  ASSERT_DOUBLE_EQ(v.w(), -0.5555555 / 3.);
}

TEST_F(Vector4Test, DevidesVectorByVector) {
  v = Vec4<double>(434.5, 93.5, 3858.53, -0.99999999);
  v = v / Vec4<double>(32.5, -16.2, 0.567, -999.99999999);
  ASSERT_DOUBLE_EQ(v.x(), 434.5 / 32.5);
  ASSERT_DOUBLE_EQ(v.y(), -93.5 / 16.2);
  ASSERT_DOUBLE_EQ(v.z(), 3858.53 / 0.567);
  ASSERT_DOUBLE_EQ(v[3], -0.99999999 / (-999.99999999));
}

TEST_F(Vector4Test, TestsEquality) {
  v = Vec4<double>(4.2, -6.54, 34855.38596, -0.9938375);
  ASSERT_TRUE(v == Vec4<double>(4.2, -6.54, 34855.38596, -0.9938375));
}

TEST_F(Vector4Test, TestsInequality) {
  v = Vec4<double>(4.2, -6.54, 0.0, 100.);
  ASSERT_TRUE(v != Vec4<double>(4.2, -4.36, 0.0, 100.));
}

//--------------------------------------------
//     MAT2
//--------------------------------------------

class Matrix2Test : public testing::Test {
 public:
  Mat2<double> m;
};

TEST_F(Matrix2Test, CreatesMatrix) {
  Vec2<double> v1(0., 0.);
  Vec2<double> v2(1., -1.);

  m = Mat2<double>(v1, v2);
  ASSERT_DOUBLE_EQ(m[0][0], v1[0]);
  ASSERT_DOUBLE_EQ(m[0][1], v1[1]);
  ASSERT_DOUBLE_EQ(m[1][0], v2[0]);
  ASSERT_DOUBLE_EQ(m[1][1], v2[1]);

  m = Mat2<double>(3.14);
  ASSERT_DOUBLE_EQ(m[0][0], 3.14);
  ASSERT_DOUBLE_EQ(m[0][1], 3.14);
  ASSERT_DOUBLE_EQ(m[1][0], 3.14);
  ASSERT_DOUBLE_EQ(m[1][1], 3.14);
}

TEST_F(Matrix2Test, AddsAmatrixOrNumber) {
  m = Mat2<double>(0.);
  m = m + Mat2<double>(-1.);
  ASSERT_DOUBLE_EQ(m[0][0], -1.);
  ASSERT_DOUBLE_EQ(m[0][1], -1.);
  ASSERT_DOUBLE_EQ(m[1][0], -1.);
  ASSERT_DOUBLE_EQ(m[1][1], -1.);
  m = m + 5.05;
  ASSERT_DOUBLE_EQ(m[0][0], 4.05);
  ASSERT_DOUBLE_EQ(m[0][1], 4.05);
  ASSERT_DOUBLE_EQ(m[1][0], 4.05);
  ASSERT_DOUBLE_EQ(m[1][1], 4.05);
}

TEST_F(Matrix2Test, SubtractsAmatrixOrNumber) {
  m = Mat2<double>(0.);
  m = m - Mat2<double>(1.);
  ASSERT_DOUBLE_EQ(m[0][0], -1.);
  ASSERT_DOUBLE_EQ(m[0][1], -1.);
  ASSERT_DOUBLE_EQ(m[1][0], -1.);
  ASSERT_DOUBLE_EQ(m[1][1], -1.);
  m = m - 5.05;
  ASSERT_DOUBLE_EQ(m[0][0], -6.05);
  ASSERT_DOUBLE_EQ(m[0][1], -6.05);
  ASSERT_DOUBLE_EQ(m[1][0], -6.05);
  ASSERT_DOUBLE_EQ(m[1][1], -6.05);
}

TEST_F(Matrix2Test, MultipliesWithNumber) {
  m = Mat2<double>(6.28);
  m = m * 0.;
  ASSERT_DOUBLE_EQ(m[0][0], 0.);
  ASSERT_DOUBLE_EQ(m[0][1], 0.);
  ASSERT_DOUBLE_EQ(m[1][0], 0.);
  ASSERT_DOUBLE_EQ(m[1][1], 0.);
}

TEST_F(Matrix2Test, GetsTheDeterminant) {
  m = Mat2<double>(Vec2<double>(5.36, 2.28), Vec2<double>(-1.5, 85.));
  ASSERT_DOUBLE_EQ(m.determinant(), 459.02);
}

TEST_F(Matrix2Test, AddsTwoMatrices) {
  m = Mat2<double>(Vec2<double>(1.36, 1.28), Vec2<double>(1.5, 0.));
  m = m + Mat2<double>(Vec2<double>(9., -5.8), Vec2<double>(-6.5, 5.3));
  ASSERT_DOUBLE_EQ(m[0][0], 10.36);
  ASSERT_DOUBLE_EQ(m[0][1], -4.52);
  ASSERT_DOUBLE_EQ(m[1][0], -5.);
  ASSERT_DOUBLE_EQ(m[1][1], 5.3);
}

TEST_F(Matrix2Test, MultipliesTwoMatrices) {
  m = Mat2<double>(Vec2<double>(1.36, 1.28), Vec2<double>(1.5, 0.));
  m = m * Mat2<double>(Vec2<double>(9., -5.8), Vec2<double>(-6.5, 5.3));
  ASSERT_DOUBLE_EQ(m[0][0], 3.92);
  ASSERT_DOUBLE_EQ(m[0][1], -1.104);
  ASSERT_DOUBLE_EQ(m[1][0], 13.5);
  ASSERT_DOUBLE_EQ(m[1][1], -8.7);
}

//--------------------------------------------
//     MAT3
//--------------------------------------------

class Matrix3Test : public testing::Test {
 public:
  Mat3<double> m;
};

TEST_F(Matrix3Test, CreatesMatrix) {
  Vec3<double> v1(0., 0., 0.);
  Vec3<double> v2(1., -1., 1.);
  Vec3<double> v3(5., -9., 5.);

  m = Mat3<double>(v1, v2, v3);
  ASSERT_DOUBLE_EQ(m[0][0], v1[0]);
  ASSERT_DOUBLE_EQ(m[0][1], v1[1]);
  ASSERT_DOUBLE_EQ(m[0][2], v1[2]);

  ASSERT_DOUBLE_EQ(m[1][0], v2[0]);
  ASSERT_DOUBLE_EQ(m[1][1], v2[1]);
  ASSERT_DOUBLE_EQ(m[1][2], v2[2]);

  ASSERT_DOUBLE_EQ(m[2][0], v3[0]);
  ASSERT_DOUBLE_EQ(m[2][1], v3[1]);
  ASSERT_DOUBLE_EQ(m[2][2], v3[2]);

  m = Mat3<double>(3.14);
  ASSERT_DOUBLE_EQ(m[0][0], 3.14);
  ASSERT_DOUBLE_EQ(m[0][1], 3.14);
  ASSERT_DOUBLE_EQ(m[0][2], 3.14);

  ASSERT_DOUBLE_EQ(m[1][0], 3.14);
  ASSERT_DOUBLE_EQ(m[1][1], 3.14);
  ASSERT_DOUBLE_EQ(m[1][2], 3.14);

  ASSERT_DOUBLE_EQ(m[2][0], 3.14);
  ASSERT_DOUBLE_EQ(m[2][1], 3.14);
  ASSERT_DOUBLE_EQ(m[2][2], 3.14);
}

TEST_F(Matrix3Test, AddsAmatrixOrNumber) {
  m = Mat3<double>(0.);
  m = m + Mat3<double>(-1.);
  ASSERT_DOUBLE_EQ(m[0][0], -1.);
  ASSERT_DOUBLE_EQ(m[0][1], -1.);
  ASSERT_DOUBLE_EQ(m[0][2], -1.);

  ASSERT_DOUBLE_EQ(m[1][0], -1.);
  ASSERT_DOUBLE_EQ(m[1][1], -1.);
  ASSERT_DOUBLE_EQ(m[1][2], -1.);

  ASSERT_DOUBLE_EQ(m[2][0], -1.);
  ASSERT_DOUBLE_EQ(m[2][1], -1.);
  ASSERT_DOUBLE_EQ(m[2][2], -1.);
  m = m + 5.05;
  ASSERT_DOUBLE_EQ(m[0][0], 4.05);
  ASSERT_DOUBLE_EQ(m[0][1], 4.05);
  ASSERT_DOUBLE_EQ(m[0][2], 4.05);

  ASSERT_DOUBLE_EQ(m[1][0], 4.05);
  ASSERT_DOUBLE_EQ(m[1][1], 4.05);
  ASSERT_DOUBLE_EQ(m[1][2], 4.05);

  ASSERT_DOUBLE_EQ(m[2][0], 4.05);
  ASSERT_DOUBLE_EQ(m[2][1], 4.05);
  ASSERT_DOUBLE_EQ(m[2][2], 4.05);
}

TEST_F(Matrix3Test, SubtractsAmatrixOrNumber) {
  m = Mat3<double>(0.);
  m = m - Mat3<double>(1.);
  ASSERT_DOUBLE_EQ(m[0][0], -1.);
  ASSERT_DOUBLE_EQ(m[0][1], -1.);
  ASSERT_DOUBLE_EQ(m[0][2], -1.);
  ASSERT_DOUBLE_EQ(m[1][0], -1.);
  ASSERT_DOUBLE_EQ(m[1][1], -1.);
  ASSERT_DOUBLE_EQ(m[1][2], -1.);
  ASSERT_DOUBLE_EQ(m[2][0], -1.);
  ASSERT_DOUBLE_EQ(m[2][1], -1.);
  ASSERT_DOUBLE_EQ(m[2][2], -1.);
  m = m - 5.05;
  ASSERT_DOUBLE_EQ(m[0][0], -6.05);
  ASSERT_DOUBLE_EQ(m[0][1], -6.05);
  ASSERT_DOUBLE_EQ(m[0][2], -6.05);
  ASSERT_DOUBLE_EQ(m[1][0], -6.05);
  ASSERT_DOUBLE_EQ(m[1][1], -6.05);
  ASSERT_DOUBLE_EQ(m[1][2], -6.05);
  ASSERT_DOUBLE_EQ(m[2][0], -6.05);
  ASSERT_DOUBLE_EQ(m[2][1], -6.05);
  ASSERT_DOUBLE_EQ(m[2][2], -6.05);
}

TEST_F(Matrix3Test, MultipliesWithNumber) {
  m = Mat3<double>(6.28);
  m = m * 0.;
  ASSERT_DOUBLE_EQ(m[0][0], 0.);
  ASSERT_DOUBLE_EQ(m[0][1], 0.);
  ASSERT_DOUBLE_EQ(m[0][2], 0.);
  ASSERT_DOUBLE_EQ(m[1][0], 0.);
  ASSERT_DOUBLE_EQ(m[1][1], 0.);
  ASSERT_DOUBLE_EQ(m[1][2], 0.);
  ASSERT_DOUBLE_EQ(m[2][0], 0.);
  ASSERT_DOUBLE_EQ(m[2][1], 0.);
  ASSERT_DOUBLE_EQ(m[2][2], 0.);
}

TEST_F(Matrix3Test, GetsTheDeterminant) {
  m = Mat3<double>(Vec3<double>(5.36, 2.28, 0.93), Vec3<double>(-1.5, 85., 0.),
                   Vec3<double>(45.8, -50., 0.14));
  ASSERT_DOUBLE_EQ(m.determinant(), -3486.4772);
}

TEST_F(Matrix3Test, AddsTwoMatrices) {
  m = Mat3<double>(Vec3<double>(1.36, 1.28, 1.), Vec3<double>(1.5, 0., -1.),
                   Vec3<double>(6.3, 0.5, 0.8));
  m = m + Mat3<double>(Vec3<double>(9., -5.8, 0.),
                       Vec3<double>(-6.5, 5.3, -1.5),
                       Vec3<double>(-5., 0.4, 90.));
  ASSERT_DOUBLE_EQ(m[0][0], 10.36);
  ASSERT_DOUBLE_EQ(m[0][1], -4.52);
  ASSERT_DOUBLE_EQ(m[0][2], 1.);

  ASSERT_DOUBLE_EQ(m[1][0], -5.);
  ASSERT_DOUBLE_EQ(m[1][1], 5.3);
  ASSERT_DOUBLE_EQ(m[1][2], -2.5);

  ASSERT_DOUBLE_EQ(m[2][0], 1.3);
  ASSERT_DOUBLE_EQ(m[2][1], 0.9);
  ASSERT_DOUBLE_EQ(m[2][2], 90.8);
}

TEST_F(Matrix3Test, MultipliesTwoMatrices) {
  m = Mat3<double>(Vec3<double>(1.36, 1.28, 0.85), Vec3<double>(1.5, 0., -6.58),
                   Vec3<double>(4.5, 0., -3.));
  Mat3<double> m2(
      Vec3<double>(9., -5.8, -4.5), Vec3<double>(-6.5, 5.3, 20.),
      Vec3<double>(8.6, 33.,
                   -5.));  // With an anonymous object, it doesn't pass
  m = m * m2;

  ASSERT_DOUBLE_EQ(m[0][0], 11.23);
  ASSERT_DOUBLE_EQ(m[0][1], 26.946);
  ASSERT_DOUBLE_EQ(m[0][2], 15.23);

  ASSERT_DOUBLE_EQ(m[1][0], -43.088);
  ASSERT_DOUBLE_EQ(m[1][1], -225.84);
  ASSERT_DOUBLE_EQ(m[1][2], 26.15);

  ASSERT_DOUBLE_EQ(m[2][0], 14.7);
  ASSERT_DOUBLE_EQ(m[2][1], -125.1);
  ASSERT_DOUBLE_EQ(m[2][2], -5.25);
}

TEST_F(Matrix3Test, GetTransposeOfMatrix) {
  m = Mat3<double>(Vec3<double>(1.36, 1.28, 0.85), Vec3<double>(1.5, 0., -6.58),
                   Vec3<double>(4.5, 0., -3.));

  Mat3<double> mt = m.transpose();
  ASSERT_DOUBLE_EQ(mt[0][0], 1.36);
  ASSERT_DOUBLE_EQ(mt[0][1], 1.5);
  ASSERT_DOUBLE_EQ(mt[0][2], 4.5);

  ASSERT_DOUBLE_EQ(mt[1][0], 1.28);
  ASSERT_DOUBLE_EQ(mt[1][1], 0.);
  ASSERT_DOUBLE_EQ(mt[1][2], 0.);

  ASSERT_DOUBLE_EQ(mt[2][0], 0.85);
  ASSERT_DOUBLE_EQ(mt[2][1], -6.58);
  ASSERT_DOUBLE_EQ(mt[2][2], -3.);
}

TEST_F(Matrix3Test, GetInverseOfMatrix) {
  m = Mat3<double>(Vec3<double>(1.36, 1.28, 0.85), Vec3<double>(1.5, 0., -6.58),
                   Vec3<double>(4.5, 0., -3.));

  m = m.inverse();

  ASSERT_DOUBLE_EQ(m[0][0], 0.);
  ASSERT_DOUBLE_EQ(m[0][1], -0.11947431302270011946);
  ASSERT_DOUBLE_EQ(m[0][2], 0.26204699322978892872);

  ASSERT_DOUBLE_EQ(m[1][0], 0.78125);
  ASSERT_DOUBLE_EQ(m[1][1], 0.24594907407407407407);
  ASSERT_DOUBLE_EQ(m[1][2], -0.31809413580246913581);

  ASSERT_DOUBLE_EQ(m[2][0], 0.);
  ASSERT_DOUBLE_EQ(m[2][1], -0.17921146953405017921);
  ASSERT_DOUBLE_EQ(m[2][2], 0.059737156511350059737);
}

//--------------------------------------------
//     MAT4
//--------------------------------------------

class Matrix4Test : public testing::Test {
 public:
  Mat4<double> m4;
};

TEST_F(Matrix4Test, CreatesMatrix) {
  Vec4<double> v1(0., 0., 0., 0.);
  Vec4<double> v2(1., -1., 1., -1.);
  Vec4<double> v3(5., -9., 5., 9.);
  Vec4<double> v4(0., -1., 0., 0.);

  m4 = Mat4<double>(v1, v2, v3, v4);
  ASSERT_DOUBLE_EQ(m4[0][0], v1[0]);
  ASSERT_DOUBLE_EQ(m4[0][1], v1[1]);
  ASSERT_DOUBLE_EQ(m4[0][2], v1[2]);
  ASSERT_DOUBLE_EQ(m4[0][3], v1[3]);

  ASSERT_DOUBLE_EQ(m4[1][0], v2[0]);
  ASSERT_DOUBLE_EQ(m4[1][1], v2[1]);
  ASSERT_DOUBLE_EQ(m4[1][2], v2[2]);
  ASSERT_DOUBLE_EQ(m4[1][3], v2[3]);

  ASSERT_DOUBLE_EQ(m4[2][0], v3[0]);
  ASSERT_DOUBLE_EQ(m4[2][1], v3[1]);
  ASSERT_DOUBLE_EQ(m4[2][2], v3[2]);
  ASSERT_DOUBLE_EQ(m4[2][3], v3[3]);

  ASSERT_DOUBLE_EQ(m4[3][0], v4[0]);
  ASSERT_DOUBLE_EQ(m4[3][1], v4[1]);
  ASSERT_DOUBLE_EQ(m4[3][2], v4[2]);
  ASSERT_DOUBLE_EQ(m4[3][3], v4[3]);

  m4 = Mat4<double>(3.14);
  ASSERT_DOUBLE_EQ(m4[0][0], 3.14);
  ASSERT_DOUBLE_EQ(m4[0][1], 3.14);
  ASSERT_DOUBLE_EQ(m4[0][2], 3.14);
  ASSERT_DOUBLE_EQ(m4[0][3], 3.14);

  ASSERT_DOUBLE_EQ(m4[1][0], 3.14);
  ASSERT_DOUBLE_EQ(m4[1][1], 3.14);
  ASSERT_DOUBLE_EQ(m4[1][2], 3.14);
  ASSERT_DOUBLE_EQ(m4[1][3], 3.14);

  ASSERT_DOUBLE_EQ(m4[2][0], 3.14);
  ASSERT_DOUBLE_EQ(m4[2][1], 3.14);
  ASSERT_DOUBLE_EQ(m4[2][2], 3.14);
  ASSERT_DOUBLE_EQ(m4[2][3], 3.14);

  ASSERT_DOUBLE_EQ(m4[3][0], 3.14);
  ASSERT_DOUBLE_EQ(m4[3][1], 3.14);
  ASSERT_DOUBLE_EQ(m4[3][2], 3.14);
  ASSERT_DOUBLE_EQ(m4[3][3], 3.14);
}

TEST_F(Matrix4Test, AddsAmatrixOrNumber) {
  m4 = Mat4<double>(0.);
  m4 = m4 + Mat4<double>(-1.);
  ASSERT_DOUBLE_EQ(m4[0][0], -1.);
  ASSERT_DOUBLE_EQ(m4[0][1], -1.);
  ASSERT_DOUBLE_EQ(m4[0][2], -1.);
  ASSERT_DOUBLE_EQ(m4[0][3], -1.);

  ASSERT_DOUBLE_EQ(m4[1][0], -1.);
  ASSERT_DOUBLE_EQ(m4[1][1], -1.);
  ASSERT_DOUBLE_EQ(m4[1][2], -1.);
  ASSERT_DOUBLE_EQ(m4[1][3], -1.);

  ASSERT_DOUBLE_EQ(m4[2][0], -1.);
  ASSERT_DOUBLE_EQ(m4[2][1], -1.);
  ASSERT_DOUBLE_EQ(m4[2][2], -1.);
  ASSERT_DOUBLE_EQ(m4[2][3], -1.);

  ASSERT_DOUBLE_EQ(m4[3][0], -1.);
  ASSERT_DOUBLE_EQ(m4[3][1], -1.);
  ASSERT_DOUBLE_EQ(m4[3][2], -1.);
  ASSERT_DOUBLE_EQ(m4[3][3], -1.);
  m4 = m4 + 5.05;
  ASSERT_DOUBLE_EQ(m4[0][0], 4.05);
  ASSERT_DOUBLE_EQ(m4[0][1], 4.05);
  ASSERT_DOUBLE_EQ(m4[0][2], 4.05);
  ASSERT_DOUBLE_EQ(m4[0][3], 4.05);

  ASSERT_DOUBLE_EQ(m4[1][0], 4.05);
  ASSERT_DOUBLE_EQ(m4[1][1], 4.05);
  ASSERT_DOUBLE_EQ(m4[1][2], 4.05);
  ASSERT_DOUBLE_EQ(m4[1][3], 4.05);

  ASSERT_DOUBLE_EQ(m4[2][0], 4.05);
  ASSERT_DOUBLE_EQ(m4[2][1], 4.05);
  ASSERT_DOUBLE_EQ(m4[2][2], 4.05);
  ASSERT_DOUBLE_EQ(m4[2][3], 4.05);

  ASSERT_DOUBLE_EQ(m4[3][0], 4.05);
  ASSERT_DOUBLE_EQ(m4[3][1], 4.05);
  ASSERT_DOUBLE_EQ(m4[3][2], 4.05);
  ASSERT_DOUBLE_EQ(m4[3][3], 4.05);
}

TEST_F(Matrix4Test, SubtractsAmatrixOrNumber) {
  m4 = Mat4<double>(0.);
  m4 = m4 - Mat4<double>(1.);
  ASSERT_DOUBLE_EQ(m4[0][0], -1.);
  ASSERT_DOUBLE_EQ(m4[0][1], -1.);
  ASSERT_DOUBLE_EQ(m4[0][2], -1.);
  ASSERT_DOUBLE_EQ(m4[0][3], -1.);

  ASSERT_DOUBLE_EQ(m4[1][0], -1.);
  ASSERT_DOUBLE_EQ(m4[1][1], -1.);
  ASSERT_DOUBLE_EQ(m4[1][2], -1.);
  ASSERT_DOUBLE_EQ(m4[1][3], -1.);

  ASSERT_DOUBLE_EQ(m4[2][0], -1.);
  ASSERT_DOUBLE_EQ(m4[2][1], -1.);
  ASSERT_DOUBLE_EQ(m4[2][2], -1.);
  ASSERT_DOUBLE_EQ(m4[2][3], -1.);

  ASSERT_DOUBLE_EQ(m4[3][0], -1.);
  ASSERT_DOUBLE_EQ(m4[3][1], -1.);
  ASSERT_DOUBLE_EQ(m4[3][2], -1.);
  ASSERT_DOUBLE_EQ(m4[3][3], -1.);
  m4 = m4 - 5.05;
  ASSERT_DOUBLE_EQ(m4[0][0], -6.05);
  ASSERT_DOUBLE_EQ(m4[0][1], -6.05);
  ASSERT_DOUBLE_EQ(m4[0][2], -6.05);
  ASSERT_DOUBLE_EQ(m4[0][3], -6.05);

  ASSERT_DOUBLE_EQ(m4[1][0], -6.05);
  ASSERT_DOUBLE_EQ(m4[1][1], -6.05);
  ASSERT_DOUBLE_EQ(m4[1][2], -6.05);
  ASSERT_DOUBLE_EQ(m4[1][3], -6.05);

  ASSERT_DOUBLE_EQ(m4[2][0], -6.05);
  ASSERT_DOUBLE_EQ(m4[2][1], -6.05);
  ASSERT_DOUBLE_EQ(m4[2][2], -6.05);
  ASSERT_DOUBLE_EQ(m4[2][3], -6.05);

  ASSERT_DOUBLE_EQ(m4[3][0], -6.05);
  ASSERT_DOUBLE_EQ(m4[3][1], -6.05);
  ASSERT_DOUBLE_EQ(m4[3][2], -6.05);
  ASSERT_DOUBLE_EQ(m4[3][3], -6.05);
}

TEST_F(Matrix4Test, MultipliesWithNumber) {
  m4 = Mat4<double>(6.28);
  m4 = m4 * 0.;
  ASSERT_DOUBLE_EQ(m4[0][0], 0.);
  ASSERT_DOUBLE_EQ(m4[0][1], 0.);
  ASSERT_DOUBLE_EQ(m4[0][2], 0.);
  ASSERT_DOUBLE_EQ(m4[0][3], 0.);

  ASSERT_DOUBLE_EQ(m4[1][0], 0.);
  ASSERT_DOUBLE_EQ(m4[1][1], 0.);
  ASSERT_DOUBLE_EQ(m4[1][2], 0.);
  ASSERT_DOUBLE_EQ(m4[1][3], 0.);

  ASSERT_DOUBLE_EQ(m4[2][0], 0.);
  ASSERT_DOUBLE_EQ(m4[2][1], 0.);
  ASSERT_DOUBLE_EQ(m4[2][2], 0.);
  ASSERT_DOUBLE_EQ(m4[2][3], 0.);

  ASSERT_DOUBLE_EQ(m4[3][0], 0.);
  ASSERT_DOUBLE_EQ(m4[3][1], 0.);
  ASSERT_DOUBLE_EQ(m4[3][2], 0.);
  ASSERT_DOUBLE_EQ(m4[3][3], 0.);
}

TEST_F(Matrix4Test, GetsTheDeterminant) {
  m4 = Mat4<double>(
      Vec4<double>(5.36, 2.28, 0.93, 13.), Vec4<double>(-1.5, 85., 0., 5.),
      Vec4<double>(45.8, -50., 0.14, -1.5), Vec4<double>(0.48, -38.5, 0., -1.));
  ASSERT_DOUBLE_EQ(m4.determinant(), -4401.55547);

  Mat4<float> m4f = Mat4<float>(
      Vec4<float>(-2.f, -8.f, 3.f, 5.f), Vec4<float>(-3.f, 1.f, 7.f, 3.f),
      Vec4<float>(1.f, 2.f, -9.f, 6.f), Vec4<float>(-6.f, 7.f, 7.f, -9.f));
  ASSERT_DOUBLE_EQ(m4f.determinant(), -4071.f);
}

TEST_F(Matrix4Test, AddsTwoMatrices) {
  m4 = Mat4<double>(
      Vec4<double>(1.36, 1.28, 1., 0.), Vec4<double>(1.5, 0., -1., -2.),
      Vec4<double>(6.3, 0.5, 0.8, -6.), Vec4<double>(0.5, 3.38, -2., 5.));

  m4 = m4 + Mat4<double>(Vec4<double>(9., -5.8, 0., 0.),
                         Vec4<double>(-6.5, 5.3, -1.5, -2.5),
                         Vec4<double>(-5., 0.4, 90., 3.5),
                         Vec4<double>(5., 0.4, 0.5, 3.5));

  ASSERT_DOUBLE_EQ(m4[0][0], 10.36);
  ASSERT_DOUBLE_EQ(m4[0][1], -4.52);
  ASSERT_DOUBLE_EQ(m4[0][2], 1.);
  ASSERT_DOUBLE_EQ(m4[0][3], 0.);

  ASSERT_DOUBLE_EQ(m4[1][0], -5.);
  ASSERT_DOUBLE_EQ(m4[1][1], 5.3);
  ASSERT_DOUBLE_EQ(m4[1][2], -2.5);
  ASSERT_DOUBLE_EQ(m4[1][3], -4.5);

  ASSERT_DOUBLE_EQ(m4[2][0], 1.3);
  ASSERT_DOUBLE_EQ(m4[2][1], 0.9);
  ASSERT_DOUBLE_EQ(m4[2][2], 90.8);
  ASSERT_DOUBLE_EQ(m4[2][3], -2.5);

  ASSERT_DOUBLE_EQ(m4[3][0], 5.5);
  ASSERT_DOUBLE_EQ(m4[3][1], 3.78);
  ASSERT_DOUBLE_EQ(m4[3][2], -1.5);
  ASSERT_DOUBLE_EQ(m4[3][3], 8.5);
}

TEST_F(Matrix4Test, MultipliesTwoMatrices) {
  m4 = Mat4<double>(
      Vec4<double>(1.36, 1.28, 0.85, -1.), Vec4<double>(1.5, 0., -6.58, 0.),
      Vec4<double>(4.5, 0., -3., 0.), Vec4<double>(5.8, -3.4, 0., -1));
  Mat4<double> m2(
      Vec4<double>(9., -5.8, -4.5, -1.1), Vec4<double>(-6.5, 5.3, 20., 2.2),
      Vec4<double>(8.6, 33., -5., -4.),
      Vec4<double>(0., -5., 8.,
                   -3.));  // With an anonymous object, it doesn't pass
  m4 = m4 * m2;

  ASSERT_DOUBLE_EQ(m4[0][0], 11.23);
  ASSERT_DOUBLE_EQ(m4[0][1], 31.946);
  ASSERT_DOUBLE_EQ(m4[0][2], 7.23);
  ASSERT_DOUBLE_EQ(m4[0][3], 0.92);

  ASSERT_DOUBLE_EQ(m4[1][0], -43.088);
  ASSERT_DOUBLE_EQ(m4[1][1], -225.84);
  ASSERT_DOUBLE_EQ(m4[1][2], 26.15);
  ASSERT_DOUBLE_EQ(m4[1][3], 24.67);

  ASSERT_DOUBLE_EQ(m4[2][0], 14.7);
  ASSERT_DOUBLE_EQ(m4[2][1], -125.1);
  ASSERT_DOUBLE_EQ(m4[2][2], -5.25);
  ASSERT_DOUBLE_EQ(m4[2][3], 7.05);

  ASSERT_DOUBLE_EQ(m4[3][0], 74.3);
  ASSERT_DOUBLE_EQ(m4[3][1], -46.66);
  ASSERT_DOUBLE_EQ(m4[3][2], -102.1);
  ASSERT_DOUBLE_EQ(m4[3][3], -10.86);
}

TEST_F(Matrix4Test, GetTransposeOfMatrix) {
  m4 = Mat4<double>(
      Vec4<double>(1.36, 1.28, 0.85, -1.), Vec4<double>(1.5, 0., -6.58, -5.),
      Vec4<double>(4.5, 0., -3., 0.), Vec4<double>(3., 4., 5., 6.));

  Mat4<double> mt = m4.transpose();
  ASSERT_DOUBLE_EQ(mt[0][0], 1.36);
  ASSERT_DOUBLE_EQ(mt[0][1], 1.5);
  ASSERT_DOUBLE_EQ(mt[0][2], 4.5);
  ASSERT_DOUBLE_EQ(mt[0][3], 3.);

  ASSERT_DOUBLE_EQ(mt[1][0], 1.28);
  ASSERT_DOUBLE_EQ(mt[1][1], 0.);
  ASSERT_DOUBLE_EQ(mt[1][2], 0.);
  ASSERT_DOUBLE_EQ(mt[1][3], 4.);

  ASSERT_DOUBLE_EQ(mt[2][0], 0.85);
  ASSERT_DOUBLE_EQ(mt[2][1], -6.58);
  ASSERT_DOUBLE_EQ(mt[2][2], -3.);
  ASSERT_DOUBLE_EQ(mt[2][3], 5.);

  ASSERT_DOUBLE_EQ(mt[3][0], -1.);
  ASSERT_DOUBLE_EQ(mt[3][1], -5.);
  ASSERT_DOUBLE_EQ(mt[3][2], 0.);
  ASSERT_DOUBLE_EQ(mt[3][3], 6.);
}

TEST_F(Matrix4Test, GetInverseOfMatrix) {
  m4 = Mat4<double>(
      Vec4<double>(1.36, 1.28, 0.85, -7.), Vec4<double>(1.5, 0., -6.58, 1.),
      Vec4<double>(4.5, 0., -3., 10.), Vec4<double>(0., 1., 6.68, -9.));

  m4 = m4.inverse();

  ASSERT_DOUBLE_EQ(m4[0][0], -0.57644611789241018751);
  ASSERT_DOUBLE_EQ(m4[0][1], 0.58235744432430050861);
  ASSERT_DOUBLE_EQ(m4[0][2], 0.20231790085493935382);
  ASSERT_DOUBLE_EQ(m4[0][3], 0.73785103090228503992);

  ASSERT_DOUBLE_EQ(m4[1][0], 2.7182004600554049173);
  ASSERT_DOUBLE_EQ(m4[1][1], -2.1123170380215781781);
  ASSERT_DOUBLE_EQ(m4[1][2], -0.1173949041428852046);
  ASSERT_DOUBLE_EQ(m4[1][3], -2.4792965888709182942);

  ASSERT_DOUBLE_EQ(m4[2][0], -0.096380322259081321122);
  ASSERT_DOUBLE_EQ(m4[2][1], -0.06186698781201981947);
  ASSERT_DOUBLE_EQ(m4[2][2], 0.049750604442306739096);
  ASSERT_DOUBLE_EQ(m4[2][3], 0.12336681249162409103);

  ASSERT_DOUBLE_EQ(m4[3][0], 0.23048665637386018803);
  ASSERT_DOUBLE_EQ(m4[3][1], -0.28062094628954117469);
  ASSERT_DOUBLE_EQ(m4[3][2], 0.023882125947969312508);
  ASSERT_DOUBLE_EQ(m4[3][3], -0.29502292015854104069);

  Mat4<float> m4f = Mat4<float>(
      Vec4<float>(-5.f, 2.f, 6.f, -8.f), Vec4<float>(1.f, -5.f, 1.f, 8.f),
      Vec4<float>(7.f, 7.f, -6.f, -7.f), Vec4<float>(1.f, -3.f, 7.f, 4.f));

  m4f = m4f.inverse();

  float eps{10E-5f};

  EXPECT_NEAR(m4f[0][0], 0.218045f, eps);
  EXPECT_NEAR(m4f[0][1], 0.45113f, eps);
  EXPECT_NEAR(m4f[0][2], 0.24060f, eps);
  EXPECT_NEAR(m4f[0][3], -0.04511f, eps);

  EXPECT_NEAR(m4f[1][0], -0.80827f, eps);
  EXPECT_NEAR(m4f[1][1], -1.456777f, eps);
  EXPECT_NEAR(m4f[1][2], -0.44361f, eps);
  EXPECT_NEAR(m4f[1][3], 0.52068f, eps);

  EXPECT_NEAR(m4f[2][0], -0.07895f, eps);
  EXPECT_NEAR(m4f[2][1], -0.22368f, eps);
  EXPECT_NEAR(m4f[2][2], -0.05263f, eps);
  EXPECT_NEAR(m4f[2][3], 0.19737f, eps);

  EXPECT_NEAR(m4f[3][0], -0.52256f, eps);
  EXPECT_NEAR(m4f[3][1], -0.81391f, eps);
  EXPECT_NEAR(m4f[3][2], -0.30075f, eps);
  EXPECT_NEAR(m4f[3][3], 0.30639f, eps);
}

//--------------------------------------------
//     Point3
//--------------------------------------------

class Point3Test : public testing::Test {
 public:
  Point3<int> p;
};

TEST_F(Point3Test, createsPoint) {
  p = Point3<int>();
  ASSERT_EQ(p.x(), 0);
  ASSERT_EQ(p.y(), 0);
  ASSERT_EQ(p.z(), 0);
  p = Point3<int>(1, -8, 0);
  ASSERT_EQ(p.x(), 1);
  ASSERT_EQ(p.y(), -8);
  ASSERT_EQ(p.z(), 0);
  p = Point3<int>(9, 0, 0);
  ASSERT_EQ(p.x(), 9);
  ASSERT_EQ(p.y(), 0);
  ASSERT_EQ(p.z(), 0);
}

TEST_F(Point3Test, subtractsPointFromPoint) {
  Point3D pf = Point3D(1, 0, 4);
  Point3D p1 = Point3D(0, 2, 4);
  Vec3D v = p1 - pf;
  ASSERT_EQ(v.x(), -1);
  ASSERT_EQ(v.y(), 2);
  ASSERT_EQ(v.z(), 0);
  ASSERT_FLOAT_EQ(v.length(), sqrt(5));
}

TEST_F(Point3Test, subtractsVectorFromPoint) {
  p = Point3<int>(3, 4, 5);
  auto v = Vec3<int>(3, 4, 5);
  p = p - v;
  ASSERT_EQ(p.x(), 0);
  ASSERT_EQ(p.y(), 0);
  ASSERT_EQ(p.z(), 0);
}

TEST_F(Point3Test, addsVectorToPoint) {
  p = Point3<int>(0, -1, -8);
  auto v = Vec3<int>(-4, 5, 9);
  p = p + v;
  ASSERT_EQ(p.x(), -4);
  ASSERT_EQ(p.y(), 4);
  ASSERT_EQ(p.z(), 1);
}
