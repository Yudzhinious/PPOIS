#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Shop.h"

TEST(ShopTest, ShowInfoShopTest) {
    Shop shop(2022, "Souvenir Shop");
    Rent rent1(6, 2024, "John Doe");
    Customers customer1(500, 5, "Customer1", 100);
    rent1.AddCustomer(customer1);
    shop.AddRent(rent1);

    std::stringstream output;
    std::streambuf* originalCout = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    shop.ShowInfoShop();

    std::cout.rdbuf(originalCout);

    std::string result = output.str();
    EXPECT_NE(result.find("Магазин Souvenir Shop для продажи сувенирных изделий был построен в 2022 году."), std::string::npos);
    EXPECT_NE(result.find("John Doe взял книгу в пользование на 6 месяцев в 2024 году."), std::string::npos);
}

TEST(ShopTest, ShowLatestRentTest) {
    Shop shop(2022, "Souvenir Shop");

    std::stringstream output;
    std::streambuf* originalCout = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    shop.ShowLatestRent();

    std::cout.rdbuf(originalCout); 
    std::string result = output.str();
    EXPECT_NE(result.find("В магазине Souvenir Shop нет аренд."), std::string::npos);

    Rent rent1(6, 2024, "John Doe");
    Customers customer1(500, 5, "Customer1", 100);
    rent1.AddCustomer(customer1);
    shop.AddRent(rent1);

    std::stringstream output2;
    std::cout.rdbuf(output2.rdbuf()); 

    shop.ShowLatestRent();

    std::cout.rdbuf(originalCout);  

    result = output2.str();
    EXPECT_NE(result.find("Самая последняя аренда в магазине Souvenir Shop:"), std::string::npos);
}

TEST(ShopTest, AddRentTest) {
    Shop shop(2022, "Souvenir Shop");
    Rent rent1(6, 2024, "John Doe");
    Customers customer1(500, 5, "Customer1", 100);
    rent1.AddCustomer(customer1);

    shop.AddRent(rent1);

    std::stringstream output;
    std::streambuf* originalCout = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf()); 

    shop.ShowInfoShop();

    std::cout.rdbuf(originalCout); 

    std::string result = output.str();
    EXPECT_NE(result.find("Магазин Souvenir Shop для продажи сувенирных изделий был построен в 2022 году."), std::string::npos);
    EXPECT_NE(result.find("John Doe взял книгу в пользование на 6 месяцев в 2024 году."), std::string::npos);
}
