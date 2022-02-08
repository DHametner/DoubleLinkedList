#include <iostream>
#include "DoubleLinkedList.hpp"

void test_with_num()
{
    IList<int>* list = new DoubleLinkedList<int>;

    std::cout << "TESTING(with numbers):" << "\n";
    std::cout << "Is empty: " << std::boolalpha << list->isEmpty() << "\n";

    list->insert(1);
    list->insert(2);
    list->insert(3);
    list->insert(4);

    std::cout << "List size: " << list->size() << "\n";
    std::cout << "Is empty: " << std::boolalpha << list->isEmpty() << "\n";

    std::cout << "Contains 2:" << std::boolalpha << list->contains(2) << "\n";
    std::cout << "Contains 5:" << std::boolalpha << list->contains(5) << "\n";

    std::cout << "Remove 3:" << std::boolalpha << list->remove(3) << "\n";
    std::cout << "Remove 5:" << std::boolalpha << list->remove(5) << "\n";
    std::cout << "Contains 3:" << std::boolalpha << list->contains(3) << "\n";

    for (size_t i = 0; i < list->size(); i++)
    {
        std::cout << list->at(i) << " ";
    }
    std::cout << "\n";

    list->clear();
    std::cout << "END TESTING(with numbers)..." << "\n";
    delete (DoubleLinkedList<int>*) list;
}

void test_with_str()
{
    IList<std::string>* list = new DoubleLinkedList<std::string>;

    std::cout << "TESTING(with strings):" << "\n";
    std::cout << "Is empty: " << std::boolalpha << list->isEmpty() << "\n";

    list->insert("Apple");
    list->insert("Microsoft");
    list->insert("IBM");
    list->insert("Nokia");

    std::cout << "List size: " << list->size() << "\n";
    std::cout << "Is empty: " << std::boolalpha << list->isEmpty() << "\n";

    std::cout << "Contains Apple:" << std::boolalpha << list->contains("Apple") << "\n";
    std::cout << "Contains Samsung:" << std::boolalpha << list->contains("Samsung") << "\n";

    std::cout << "Remove IBM:" << std::boolalpha << list->remove("IBM") << "\n";
    std::cout << "Remove Samsung:" << std::boolalpha << list->remove("Samsung") << "\n";
    std::cout << "Contains IBM:" << std::boolalpha << list->contains("IBM") << "\n";

    for (size_t i = 0; i < list->size(); i++)
    {
        std::cout << list->at(i) << " ";
    }
    std::cout << "\n";

    list->clear();
    std::cout << "END TESTING(with strings)..." << "\n";
    delete (DoubleLinkedList<std::string>*) list;
}

int main()
{
    test_with_num();
    test_with_str();
    return EXIT_SUCCESS;
}
