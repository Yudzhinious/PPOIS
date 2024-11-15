#include "Documents.h"

Documents::Documents(int pages, std::string name, std::string author, int age) : Book(pages, name, author) {
    this->age = age;
}
void Documents::IncreaseAge(Documents& doc, int years) {
    doc.age += years;
}
void Documents::ChangeAuthor(Documents& doc, const std::string& newAuthor) {
    doc.author = newAuthor;
}
void Documents::ShowInfo() {
    std::cout << "¬ архиве наход€тс€ документы на прот€жении уже " << age << " лет." << std::endl;
}