#include<iostream>

class Book {
 
private:
    std::string m_title;
    std::string m_author;
    std::string m_isbn;

public:
    Book(const std::string& title,const std::string& author,const std::string& isbn)
    :m_title(title)
    ,m_author(author)
    ,m_isbn(isbn) {}

    void SetTilte(const std::string& litle) {
        this->m_title = litle;
    }

    void SetAuthor(const std::string& author) {
        this->m_author = author;
    }

    void SetIsbn(const std::string& isbn) {
        this->m_isbn = isbn;
    }

    std::string getTitle() const{
        return m_title;
    }

    std::string getIsbn() const{
        return m_isbn;
    }

    std::string getAuthor() const{
        return m_author;
    }
};

int main() {
    Book book("hello","world","ratr");
    std::cout << book.getTitle() << std::endl;
    std::cout << book.getAuthor() << std::endl;
    std::cout << book.getIsbn() << std::endl;


    book.SetAuthor("author");
    book.SetIsbn("isbn");
    book.SetTilte("title");


    std::cout << book.getTitle() << std::endl;
    std::cout << book.getAuthor() << std::endl;
    std::cout << book.getIsbn() << std::endl;
}