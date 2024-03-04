#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // File #1
    ImageFile image("image");
    AbstractFile* ptr = &image;
    std::string name = ptr->getName();
    unsigned int size = ptr->getSize();
    std::cout << name << size << std::endl;
    std::vector<char> v;
    ptr->write({' ', 'X', ' ', 'X', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', '5'});
    ptr->read();

    // Test Case 1: No number
//    return ptr->write({'X', ' ', 'X'});

    // Test Case 2: Wrong n value
//    return ptr->write({'X', ' ', 'X', '9'});

    // Test Case 3: Wrong characters
//    return ptr->write({'F', ' ', '3', 'j', '2'});

    // Test Case 4: Append
//    return ptr->append({'3'});

    // File #2
    TextFile text("text");
    AbstractFile* ptr2 = &text;
    std::string name2 = ptr2->getName();
    unsigned int size2 = ptr2->getSize();
    std::vector<char> v2;
    v2.push_back('1');
    v2.push_back('2');
    v2.push_back('3');
    ptr2->write(v2);

    //File #3
    TextFile text2("text2");
    AbstractFile* ptr3 = &text2;
    std::string name3 = ptr3->getName();
    unsigned int size3 = ptr3->getSize();
    std::vector<char> v3;
    v3.push_back('4');
    v3.push_back('5');
    v3.push_back('6');
    ptr3->write(v3);

    SimpleFileSystem fileSystem;

    fileSystem.addFile("image", ptr);
    fileSystem.addFile("text", ptr2);
    fileSystem.addFile("text2", ptr3);


    fileSystem.createFile("file4.txt");
    fileSystem.createFile("file5.img");
    std::vector<char> v4 = {'a', 'b', 'c'};
    std::vector<char> v5 = {'X', ' ', 'X', ' ', '2'};

    AbstractFile* file4 = fileSystem.openFile("file4.txt");
    AbstractFile* file5 = fileSystem.openFile("file5.img");
    file4->write(v4);
    file5->write(v5);
    file4->read();
    file5->read();
    fileSystem.closeFile(file4);
    fileSystem.closeFile(file5);
    fileSystem.deleteFile("file4.txt");
    fileSystem.deleteFile("file5.img");

    return SUCCESS;

}