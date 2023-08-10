#include "gtest/gtest.h"

#include "mVector.h"

using namespace mStd;

class mVectorTests : public ::testing::Test
{
     protected:
     virtual void SetUp()
     {      

     }

     virtual void TearDown()
    {

    }
};

TEST_F(mVectorTests, pushBack) {
    int testVal = 10;
    mVector vec;
    vec.pushBack(testVal);
    EXPECT_EQ(testVal, vec.at(0));
}
