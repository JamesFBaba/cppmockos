#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/PasswordProxy.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include <iostream>

int main(int argc, char* argv[]) {
    SimpleFileSystem * system = new SimpleFileSystem();
    SimpleFileFactory * factory = new SimpleFileFactory();
    TouchCommand * command = new TouchCommand(system, factory);
    CommandPrompt cmd;
    cmd.setFileFactory(factory);
    cmd.setFileSystem(system);
    cmd.addCommand("touch", command);
    cmd.run();

    AbstractFile* txt = system->openFile("hello test.txt");

    std::cout <<  txt->getName() << std::endl;
}