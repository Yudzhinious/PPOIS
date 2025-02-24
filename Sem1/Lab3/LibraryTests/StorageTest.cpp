#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Storage.h"

TEST(StorageTest, ShowInfoStorageTest) {
    Storage storage(5, "Основное хранилище", "А1");
    testing::internal::CaptureStdout();
    storage.ShowInfoStorage();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Хранилище Основное хранилище состоит из разделовА1 количеством 5 штук."), std::string::npos);
}
TEST(StorageTest, AddGenreTest) {
    Storage storage(5, "Основное хранилище", "А1");
    Genre genre(3, "Фантастика", "Космос", "Приключения");
    storage.AddGenre(genre);

    testing::internal::CaptureStdout();
    storage.ShowInfoStorage(); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Фантастика"), std::string::npos); 
    EXPECT_NE(output.find("Космос"), std::string::npos); 
    EXPECT_NE(output.find("Приключения"), std::string::npos); 
}
TEST(StorageTest, AddMultipleGenresTest) {
    Storage storage(5, "Основное хранилище", "А1");
    Genre genre1(3, "Фантастика", "Космос", "Приключения");
    Genre genre2(4, "Детектив", "Криминал", "Драма");

    storage.AddGenre(genre1);
    storage.AddGenre(genre2);

    testing::internal::CaptureStdout();
    storage.ShowInfoStorage();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Фантастика"), std::string::npos); 
    EXPECT_NE(output.find("Космос"), std::string::npos);   
    EXPECT_NE(output.find("Приключения"), std::string::npos); 
    EXPECT_NE(output.find("Детектив"), std::string::npos);  
    EXPECT_NE(output.find("Криминал"), std::string::npos); 
    EXPECT_NE(output.find("Драма"), std::string::npos);      
}