#include <QCoreApplication>
#include "gtest/gtest.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    int returnValue = RUN_ALL_TESTS();
    return returnValue;
}
