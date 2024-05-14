#include <SFML/Graphics.hpp>
#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "book1.cpp"
#include "Loger.cpp"

// Функція для шифрування рядка за допомогою XOR
std::string encryptXOR(const std::string& plaintext, char key) {
    std::string encrypted;
    for (char c : plaintext) {
        encrypted += c ^ key;
    }
    return encrypted;
}

void renderWindow(sf::RenderWindow& window, sf::Text& text) {
    while (window.isOpen()) {
        sf::Event event;
     
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        window.clear(sf::Color::White);
        window.draw(text);
        window.display();
    }
}

// Функція для відображення книг, випущених після заданого року, у вікні SFML
void displayBooksPublishedAfterYear(sf::RenderWindow& window, const std::vector<book>& books, int year) {
    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Failed to load font file\n";
        return;
    }

    // Створюємо текстовий об'єкт для відображення списку книг
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(10, 10);

    // Формуємо рядок з книгами, випущеними після заданого року
    std::string bookListStr = "Books published after " + std::to_string(year) + ":\n";
    for (const auto& book : books) {
        if (book.getYear() > year) {
            bookListStr += book.toString() + "\n";
        }
    }
    text.setString(bookListStr);
    renderWindow(window, text);

  
}
// Функція для відображення книг за автором у вікні SFML
void displayBooksByAuthor(sf::RenderWindow& window, const std::vector<book>& books, const std::string& author ) {
    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Failed to load font file\n";
        return;
    }

    // Створюємо текстовий об'єкт для відображення списку книг
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(10, 10);

    // Формуємо рядок з книгами заданого автора
    std::string bookListStr = "Books by " + author + ":\n";
    for (const auto& book : books) {
        if (book.getAuthor() == author) {
            bookListStr += book.toString() + "\n";
        }
    }
    text.setString(bookListStr);

        renderWindow(window, text);
  
}
void displayBooksByPublisher(sf::RenderWindow& window, const std::vector<book>& books, const std::string& publisher) {
        // Задаємо видавництво для відображення
        sf::CircleShape shape(100.f);

        sf::Font font;
        if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
            std::cerr << "Failed to load font file\n";
            return;
        }
        float x = 10.f;
        float y = 10.f;
        shape.setFillColor(sf::Color::Green);
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x, y);

        // Формуємо рядок з книгами заданого видавництва
        std::string bookListStr = "Books published by " + publisher + ":\n";
        for (const auto& book : books) {
            if (book.getPublisher() == publisher) {
                bookListStr += book.toString() + "\n";
            }
        }
        text.setString(bookListStr);

            renderWindow(window, text);
        
       
    }
int main()
{
    std::vector<book> books = {
          book(1, "Prokliatie", "Kukshinov", "Publisher1", 2000, 300, 20.5, "Tverda "),
          book(2, "Title2", "Pechkov", "Publisher2", 2005, 250, 15.0, "Type2"),
          book(3, "Title3", "Oleksiy", "Publisher3", 2010, 400, 25.5, "Type3"),
          book(4, "Title4", "Tyger1", "Publisher1", 2015, 350, 18.5, "Type1"),
          book(5, "Title5", "Panserfagen", "Publisher2", 2020, 280, 22.0, "Type2"),
          book(6, "Title5", "Tyger1", "Publisher2", 2020, 280, 22.0, "Type2")
    };

    // Створення консольного меню
    std::cout << "Choose an option:\n";
    std::cout << "1. Search books by author\n";
    std::cout << "2. Search books by publisher\n";
    std::cout << "3. Search books published after a certain year\n";

    int choice;
    std::cin >> choice;
    sf::RenderWindow window(sf::VideoMode(800, 200), "SFML works!");
    bool flag = 0;
    switch (choice) {
    case 1: {
        std::string author;
        std::cout << "Enter author's name: ";
        std::cin.ignore(); // Clear input buffer
        std::getline(std::cin, author);
        Logger::log("Searching books by author: " + author);
        displayBooksByAuthor(window, books, author);
        break;
    }
    case 2: {
        std::string publisher;
        std::cout << "Enter publisher's name: ";
        std::cin.ignore(); // Clear input buffer
        std::getline(std::cin, publisher);
        Logger::log("Searching books by publisher: " + publisher);
        displayBooksByPublisher(window, books, publisher);
        break;
    }
    case 3: {
        int year;
        std::cout << "Enter the year: ";
        std::cin >> year;
        Logger::log("Searching books published after year: " + std::to_string(year));
        displayBooksPublishedAfterYear(window, books, year);
        break;
    }
    default:
        std::string author;
        std::cout << "Enter author's name: ";
        std::cin.ignore(); // Clear input buffer
        std::getline(std::cin, author);
        Logger::log("Searching books by author: " + author);
        displayBooksByAuthor(window, books, author);
        sf::RenderWindow window1(sf::VideoMode(800, 200), "SFML works!");
        std::string publisher;
        std::cout << "Enter publisher's name: ";
        std::cin.ignore(); // Clear input buffer
        std::getline(std::cin, publisher);
        Logger::log("Searching books by publisher: " + publisher);
        displayBooksByPublisher(window1, books, publisher);
        sf::RenderWindow window3(sf::VideoMode(800, 200), "SFML works!");
        int year;
        std::cout << "Enter the year: ";
        std::cin >> year;
        Logger::log("Searching books published after year: " + std::to_string(year));
        displayBooksPublishedAfterYear(window3, books, year);
        break;
        std::ofstream file("books.txt");
        if (file.is_open()) {
            // Прохід по всіх книгах
            for (const auto& book : books) {
                // Отримання рядка з інформацією про книгу
                std::string bookInfo = book.toString();
                // Шифрування рядка за допомогою XOR з ключем 'X'
                std::string encryptedInfo = encryptXOR(bookInfo, 'X');
                // Запис зашифрованого рядка у файл
                file << encryptedInfo << std::endl;
            }
            // Закриття файлу
            file.close();
            Logger::log("Books information has been encrypted and written to file.");
        }
        else {
            std::cerr << "Failed to open file for writing." << std::endl;
        }

       
  }  
    return 0; 
}
/*void alllist(sf::RenderWindow& window, const std::vector<book>& books, const std::string& message, const sf::Font& font, int fontSize, const sf::Color& color, float x, float y) {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setFillColor(color);
    text.setPosition(x, y);
    // Формуємо рядок з книгами, випущеними після заданого року
     std::string bookListStr = "Books published by " + message + ":\n";
    for (const auto& book : books) {
        if (book.getAuthor() == message) {
            bookListStr += book.toString() + "\n";
        }
    }
    text.setString(bookListStr);
    window.draw(text);
}*/
/* std::string publisher = "Publisher1";
    displayBooksByPublisher(window, books, publisher);*/
    // Задаємо автора для відображення
   // std::string author = "Kukshinov";
    // Відображення списку книг заданого автора у вікні SFML
   // displayBooksByAuthor(window, books, author);

    // Задаємо рік для відображення
   // int year = 2010;
    // Відображення списку книг, випущених після заданого року, у вікні SFML
   // displayBooksPublishedAfterYear(window, books, year);
    // Відкриття файлу для запису з шифруванням