#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
 class book {
private:
    int id;
    std::string title;
    std::string author;
    std::string publisher;
    int year;
    int pageCount;
    double price;
    std::string coverType;
public:
    book(int id, std::string title, std::string author, std::string publisher, int year, int pageCount, double price, std::string coverType)
        : id(id), title(title), author(author), publisher(publisher), year(year), pageCount(pageCount), price(price), coverType(coverType) {}

    // Getters
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getPublisher() const { return publisher; }
    int getYear() const { return year; }
    int getPageCount() const { return pageCount; }
    double getPrice() const { return price; }
    std::string getCoverType() const { return coverType; }
    // Setters
    void setId(int id) { this->id = id; }
    void setTitle(const std::string& title) { this->title = title; }
    void setAuthor(const std::string& author) { this->author = author; }
    void setPublisher(const std::string& publisher) { this->publisher = publisher; }
    void setYear(int year) { this->year = year; }
    void setPageCount(int pageCount) { this->pageCount = pageCount; }
    void setPrice(double price) { this->price = price; }
    void setCoverType(const std::string& coverType) { this->coverType = coverType; }
    std::string toString() const {
        return "Book: " + std::to_string(id) + ", " + title + ", "+ author + ", "+ publisher + ", "+ std::to_string(year) + ", "+ std::to_string(pageCount) + ", "+ std::to_string(price) + ", "+ coverType;
    }
    friend std::ostream& operator<<(std::ostream& os, const book& Book) {
        os << Book.toString();
        return os;
    }

};