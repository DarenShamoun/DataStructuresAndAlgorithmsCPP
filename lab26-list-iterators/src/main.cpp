#include "list.h"
#include <iostream>
#include <iterator>


int main()
{
    // create a list
    mesa::list<int> lst;

    // add some elements to the list
    lst.push_front(5);
    lst.push_front(4);
    lst.push_front(3);
    lst.push_front(2);
    lst.push_front(1);

    // print the list using a range-for loop
    std::cout << "List: ";
    for (const auto& elem : lst)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // use the size() and empty() functions
    std::cout << "Size: " << lst.size() << std::endl;
    std::cout << "Empty: " << std::boolalpha << lst.empty() << std::endl;

    // use the front() and pop_front() functions
    std::cout << "Front: " << lst.front() << std::endl;
    lst.pop_front();
    std::cout << "Front after pop: " << lst.front() << std::endl;

    // use the insert_after() function
    auto it = lst.begin();
    std::advance(it, 2);
    lst.insert_after(it, 99);

    // print the list after the insert
    std::cout << "List after insert: ";
    for (const auto& elem : lst)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // use the erase_after() function
    it = lst.begin();
    std::advance(it, 3);
    lst.erase_after(it);

    // print the list after the erase
    std::cout << "List after erase: ";
    for (const auto& elem : lst)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

