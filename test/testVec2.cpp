#include "gmock/gmock.h"
#include "../include/vec2.h"

using namespace testing;

class Vector2 : public Test {
    public:
        Vec2<double> v;
};


TEST_F(Vector2, CreatesVector)
{
    v = Vec2<double>(0., 0.);
    ASSERT_DOUBLE_EQ(v.x(), 0.);
    ASSERT_DOUBLE_EQ(v.y(), 0.);
}