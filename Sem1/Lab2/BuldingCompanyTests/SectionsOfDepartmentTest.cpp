#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab2/SectionsOfDepartment.h"
#include "C:/Users/ASUS/source/repos/Lab2/Storage.h"

TEST(SectionsOfDepartmentTest, AddStorageTest) {
    SectionsOfDepartment section(2, "Section4");
    Storage storage(5, "Storage3", 15, 50, "Naming1");

    section.AddStorage(storage);

    EXPECT_EQ(section.getStorages().size(), 1);
}

TEST(SectionsOfDepartmentTest, EditSectionTest) {
    SectionsOfDepartment section(0, "Section2");

    testing::internal::CaptureStdout();
    section.EditSection();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Отдел Section2 необходимо отрегулировать"), std::string::npos);
}

TEST(SectionsOfDepartmentTest, ShowSectionsOfDepartmentTest) {
    SectionsOfDepartment section(3, "Section3");
    Storage storage1(150, "Storage1", 30, 0, "Naming1");
    Storage storage2(200, "Storage2", 20, 0, "Naming2");

    section.AddStorage(storage1);
    section.AddStorage(storage2);

    testing::internal::CaptureStdout();
    section.ShowSectionsOfDepartment();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Компания состоит из отделов Section3 количеством 3 штук."), std::string::npos);
}
