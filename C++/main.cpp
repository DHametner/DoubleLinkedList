#include <iostream>
#include "DoubleLinkedList.hpp"

int main() {
    DoubleLinkedList<int> list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    std::cout << list.size() << "\n";

    std::cout << "Remove 5:" << std::boolalpha << list.remove(5) << "\n";
    std::cout << "Contains 2:" << std::boolalpha << list.contains(2) << "\n";
    std::cout << "Remove 2:" << std::boolalpha << list.remove(2) << "\n";
    std::cout << "Contains 2:" << std::boolalpha << list.contains(2) << "\n";

    for(size_t i = 0; i < list.size(); i++)
    {
        std::cout << list.at(i).value << " ";
    }
    std::cout << "\n";

    std::cout << list.size() << "\n";

    list.clear();
    return EXIT_SUCCESS;
}
