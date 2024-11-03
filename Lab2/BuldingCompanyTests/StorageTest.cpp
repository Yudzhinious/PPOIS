#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/Storage.h"

TEST(StorageTest, OccupancyTest) {
    Storage storage(10, "WarehouseB", 500, 60, "Furniture");

    testing::internal::CaptureStdout();
    storage.Occupancy();
    std::string output = testing::internal::GetCapturedStdout();

    int initialAmount = 200;
    int initialPercentage = 90;

    if (initialPercentage < 100) {

    }
    else {
        EXPECT_NE(output.find("Заполнение склада невозможно, используйте другой склад"), std::string::npos);
    }
}
