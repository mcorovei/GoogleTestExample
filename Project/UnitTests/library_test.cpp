#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory.h>

#include "AClass.h"

using ::testing::_;
using ::testing::AnyNumber;
using ::testing::Gt;
using ::testing::Return;
using ::testing::NiceMock;

class AInterfaceMock : public AInterface {
public:
    MOCK_METHOD(void, doSomething, (), (override));
    MOCK_METHOD(int, doSomethingElse, (int), (override));
};

class LibraryTest : public ::testing::Test {
public:
    void SetUp() override {
        mockInterface = std::make_shared<NiceMock<AInterfaceMock>>();
        target = std::make_shared<AClass>(mockInterface); 
    }

    void TearDown() override {
        target.reset();
    }

    std::shared_ptr<AClass> target;
    std::shared_ptr<NiceMock<AInterfaceMock>> mockInterface;
};

TEST_F(LibraryTest, doSomething_is_called) {
    EXPECT_CALL(*mockInterface, doSomething());
    target->doSomething();
}

TEST_F(LibraryTest, doSomethingElse_is_called) {
    int value = 5;
    EXPECT_CALL(*mockInterface, doSomethingElse(_)).WillRepeatedly(Return(value));
    EXPECT_EQ(target->doSomethingElse(value), value);
    EXPECT_NE(target->doSomethingElse(value), ++value);
}