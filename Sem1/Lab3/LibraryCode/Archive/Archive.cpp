#include "Archive.h"

Archive::Archive(int amount, std::string name) {
    this->amount = amount;
    this->name = name;
}

void Archive::InfoArchive() {
    std::cout << "В архиве находятся " << amount << " документов." << std::endl;
}
void Archive::AddDocs(Documents& doc) {
    docs.push_back(std::move(doc));
}
void Archive::ShowAllDocs() const {
    if (docs.empty()) {
        std::cout << "Архив пуст." << std::endl;
    }
    else {
        std::cout << "Документы в архиве" << std::endl;
    }
}

std::vector<Documents> Archive::getDocs() {
    return docs;
}
