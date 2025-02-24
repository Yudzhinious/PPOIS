#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Library.h"
#include "C:/Users/ASUS/source/repos/Lab3/Owner.h"
#include "C:/Users/ASUS/source/repos/Lab3/Shop.h"
#include "C:/Users/ASUS/source/repos/Lab3/Storage.h"

TEST(LibraryTest, ShowLibraryTest) {
    Library library(50, 500, 123.45, "Main St", "City Library");

    Owner owner1(45, 20, "John Doe");
    Shop shop1(1990, "BookStore");
    Storage storage1(300, "Storage1", "A");

    library.AddOwner(owner1);
    library.AddShop(shop1);
    library.AddStorage(storage1);

    testing::internal::CaptureStdout();
    library.ShowLibrary();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Библиотека City Library"), std::string::npos);
    EXPECT_NE(output.find("Main St"), std::string::npos);
    EXPECT_NE(output.find("50 лет назад"), std::string::npos);
    EXPECT_NE(output.find("может вместить в себя до 500 книг"), std::string::npos);
    EXPECT_NE(output.find("Вледелец John Doe"), std::string::npos);
    EXPECT_NE(output.find("занимается управленческим бизнесом на протяжении 20 лет"), std::string::npos);
    EXPECT_NE(output.find("Магазин BookStore для продажи сувенирных изделий был построен в 1990 году."), std::string::npos);
}
TEST(LibraryTest, AddOwnerTest) {
    Library library(50, 500, 123.45, "Main St", "City Library");

    Owner owner1(45, 20, "John Doe");
    library.AddOwner(owner1);

    EXPECT_EQ(library.getOwner().size(), 1);
}
TEST(LibraryTest, AddShopTest) {
    Library library(50, 500, 123.45, "Main St", "City Library");

    Shop shop1(1990, "BookStore");
    library.AddShop(shop1);

    EXPECT_EQ(library.getShop().size(), 1);
}
TEST(LibraryTest, AddStorageTest) {
    Library library(50, 500, 123.45, "Main St", "City Library");

    Storage storage1(300, "Storage1", "A");
    library.AddStorage(storage1);

    EXPECT_EQ(library.getStorage().size(), 1);
}
TEST(LibraryTest, CanAccommodateTest) {
    Library library(50, 500, 123.45, "Main St", "City Library");

    EXPECT_TRUE(library.CanAccommodate(300));
    EXPECT_FALSE(library.CanAccommodate(600));
}
TEST(LibraryTest, ExpandCapacityTest) {
    Library library(50, 500, 123.45, "Main St", "City Library");

    library.ExpandCapacity(200);
    EXPECT_EQ(library.GetAgeAndCapacity().second, 700);

    testing::internal::CaptureStdout();
    library.ExpandCapacity(-50);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка: дополнительная вместимость должна быть положительной."), std::string::npos);
}
TEST(LibraryTest, EmptyCollectionsTest) {
    Library library(50, 500, 123.45, "Main St", "City Library");

    EXPECT_EQ(library.getOwner().size(), 0);
    EXPECT_EQ(library.getStorage().size(), 0);
    EXPECT_EQ(library.getShop().size(), 0);
}