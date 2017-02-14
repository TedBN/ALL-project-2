//
// Created by Oskars Pozdnakovs on 12/02/2017.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Manager.h"


class TestFixture : public ::testing::Test {

public:
    virtual ~TestFixture() {
        delete m;
    }

protected:
    virtual void SetUp() {
        m = new Manager();
    }

    Manager * m;
};

TEST_F(TestFixture, nineRegions) {
    EXPECT_EQ(9, m->all_Regions.size());
    ASSERT_EQ(m->all_Regions[0].name, "Region_0");

}



//int main(int argc, char* argv[]) {
//    testing::InitGoogleTest(&argc, argv);
//    RUN_ALL_TESTS();
//
//
//    Manager startGame;
//
//
//}