#include "pch.h"
#include "C:/Users/ASUS/source/repos/Lab3/Genre.h"
#include "C:/Users/ASUS/source/repos/Lab3/Fantastics.h"
#include "C:/Users/ASUS/source/repos/Lab3/Novel.h"
#include "C:/Users/ASUS/source/repos/Lab3/Scientific.h"

TEST(GenreTest, AddBooksTest) {
    Genre genre(3, "Фантастика", "Романы", "Научные книги");

    Fantastics fantastic(300, "Star Wars", "George Lucas", 90, 500);
    Novel novel(200, "War and Peace", "Leo Tolstoy", 85, 700);
    Scientific scientific(150, "Quantum Mechanics", "Albert Einstein", 95, 1200);

    genre.AddFantastics(fantastic);
    genre.AddNovel(novel);
    genre.AddScientific(scientific);

    EXPECT_EQ(genre.getFantastics().size(), 1);
    EXPECT_EQ(genre.getNovel().size(), 1);
    EXPECT_EQ(genre.getScientific().size(), 1);
}

TEST(GenreTest, ShowInfoGenreTest) {
    Genre genre(3, "Фантастика", "Романы", "Научные книги");

    Fantastics fantastic(300, "Star Wars", "George Lucas", 90, 500);
    Novel novel(200, "War and Peace", "Leo Tolstoy", 85, 700);
    Scientific scientific(150, "Quantum Mechanics", "Albert Einstein", 95, 1200);

    genre.AddFantastics(fantastic);
    genre.AddNovel(novel);
    genre.AddScientific(scientific);

    testing::internal::CaptureStdout();
    genre.ShowInfoGenre();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Фантастика"), std::string::npos);
    EXPECT_NE(output.find("Романы"), std::string::npos);
    EXPECT_NE(output.find("Научные книги"), std::string::npos);
    EXPECT_NE(output.find("Star Wars"), std::string::npos);
    EXPECT_NE(output.find("War and Peace"), std::string::npos);
    EXPECT_NE(output.find("Quantum Mechanics"), std::string::npos);
}

TEST(GenreTest, RemoveBookFromGenreTest) {
    Genre genre(3, "Фантастика", "Романы", "Научные книги");

    Fantastics fantastic(300, "Star Wars", "George Lucas", 90, 500);
    Novel novel(200, "War and Peace", "Leo Tolstoy", 85, 700);
    Scientific scientific(150, "Quantum Mechanics", "Albert Einstein", 95, 1200);

    genre.AddFantastics(fantastic);
    genre.AddNovel(novel);
    genre.AddScientific(scientific);

    genre.RemoveBookFromGenre("Fantastics", 0);
    genre.RemoveBookFromGenre("Novel", 0);

    EXPECT_EQ(genre.getFantastics().size(), 0);
    EXPECT_EQ(genre.getNovel().size(), 0);
    EXPECT_EQ(genre.getScientific().size(), 1); 
}

TEST(GenreTest, RemoveInvalidBookTest) {
    Genre genre(3, "Фантастика", "Романы", "Научные книги");

    Fantastics fantastic(300, "Star Wars", "George Lucas", 90, 500);
    genre.AddFantastics(fantastic);

    testing::internal::CaptureStdout();
    genre.RemoveBookFromGenre("Fantastics", 1);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ошибка: Неверный жанр или индекс."), std::string::npos);
}

TEST(GenreTest, AddMultipleBooksTest) {
    Genre genre(3, "Фантастика", "Романы", "Научные книги");

    Fantastics fantastic1(300, "Star Wars", "George Lucas", 90, 500);
    Fantastics fantastic2(350, "Dune", "Frank Herbert", 85, 600);
    Novel novel(200, "War and Peace", "Leo Tolstoy", 95, 700);
    Scientific scientific(150, "Quantum Mechanics", "Albert Einstein", 90, 1200);

    genre.AddFantastics(fantastic1);
    genre.AddFantastics(fantastic2);
    genre.AddNovel(novel);
    genre.AddScientific(scientific);

    EXPECT_EQ(genre.getFantastics().size(), 2);
    EXPECT_EQ(genre.getNovel().size(), 1);
    EXPECT_EQ(genre.getScientific().size(), 1);
}