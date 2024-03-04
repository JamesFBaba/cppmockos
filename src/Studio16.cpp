#include "mockos/textFile.h"
#include <iostream>

int main(int argc, char* argv[]) {
    TextFile text("text");

    AbstractFile* ptr = &text;


    std::string name = ptr->getName();
    unsigned int size = ptr->getSize();
    std::cout << name << size << std::endl;
    std::vector<char> v;
    v.push_back('1');
    v.push_back('2');
    v.push_back('3');
    ptr->write(v);
    ptr->read();
    std::cout << std::endl;

    std::vector<char> v2;
    v2.push_back('4');
    v2.push_back('5');
    v2.push_back('6');
    ptr->append(v2);
    ptr->read();
    std::cout << std::endl;


    ptr->write({'a', 'b', 'c'});
    ptr->read();
    std::cout << std::endl;

    size = ptr->getSize();
    std::cout << size << std::endl;

}