//
//  main.cpp
//  cpplab
//
//  Created by Артамонов Степан on 17.09.2021.
//

#include "hypocycloid.hpp"
#include "gtest/gtest.h"

TEST(HypocycloidConstructor, Get)
{
    Hypocycloid hypocycloid(10, 3, 2);
    ASSERT_EQ(3, hypocycloid.get_r());
    ASSERT_EQ(10, hypocycloid.get_R());
    ASSERT_EQ(2, hypocycloid.get_d());
}

TEST(HypocycloidMetods, test_1)
{
    Hypocycloid hypocycloid(7, 3, 5);
    ASSERT_NEAR(-6.50053, hypocycloid.x(3.1415), 0.0001);
    ASSERT_NEAR(4.33019, hypocycloid.y(3.1415), 0.0001);
}

TEST(HypocycloidMetods, test_2)
{
    Hypocycloid hypocycloid(6, 3, 1);
    ASSERT_NEAR(7.98985, hypocycloid.radius_of_curvature(1.5372), 0.0001);
}

TEST(HypocycloidMetods, test_3)
{
    Hypocycloid hypocycloid(12, 4, 5);
    ASSERT_NEAR(46.5746409, hypocycloid.sector_area(1.0415), 0.0001);
}

TEST(HypocycloidMetods, test_4)
{
    Hypocycloid hypocycloid(20.4, 6.15, 8.88);
    hypocycloid.set_R(17.77);
    ASSERT_FLOAT_EQ(17.77, hypocycloid.get_R());
    hypocycloid.set_r(2.1119);
    ASSERT_FLOAT_EQ(2.1119, hypocycloid.get_r());
    hypocycloid.set_d(9.01);
    ASSERT_FLOAT_EQ(9.01, hypocycloid.get_d());
}

TEST(HypocycloidMetods, test_5)
{
    Hypocycloid hypocycloid00(11.001, 4.1, 4.1);
    ASSERT_EQ(0, hypocycloid00.type());
    Hypocycloid hypocycloid02(34.001, 4.0, 4.1);
    ASSERT_EQ(1, hypocycloid02.type());
    Hypocycloid hypocycloid03(21.201, 4.1, 4.0);
    ASSERT_EQ(-1, hypocycloid03.type());
}


// g++ test.cpp -lhypocycloid -lgtest --std=c++11 -L ../lib -I ../include -o test
// g++ test.cpp -lhypocycloid -lgtest --std=c++11 -L ../lib -I ../include

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
