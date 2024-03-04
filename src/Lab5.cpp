/**
 * Lab5.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains main method for Lab5. Used to test command prompt with various commands.
*/

#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/PasswordProxy.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/LSCommand.h"
#include"mockos/RemoveCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/CopyCommand.h"
#include "mockos/SizeCommand.h"
#include "mockos/MacroCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/CatDSParsingStrategy.h"

#include <iostream>

int main(int argc, char* argv[]) {
    // Basic Commands
    SimpleFileSystem system;
    SimpleFileFactory factory;
    TouchCommand touch(&system, &factory);
    LSCommand ls(&system);
    RemoveCommand rm(&system);
    CatCommand cat(&system);
    DisplayCommand ds(&system);
    CopyCommand copy(&system);
    // Rename Macro Command
    MacroCommand rename(&system);
    RenameParsingStrategy rename_parse;
    rename.addCommand(&copy);
    rename.addCommand(&rm);
    rename.setParseStrategy(&rename_parse);
    // Cat + ds Macro Command
    MacroCommand catds(&system);
    CatDSParsingStrategy catds_parse;
    catds.addCommand(&cat);
    catds.addCommand(&ds);
    catds.setParseStrategy(&catds_parse);
    // Extra credit command
    SizeCommand size(&system);

    CommandPrompt cmd;
    cmd.setFileFactory(&factory);
    cmd.setFileSystem(&system);
    // Adds commands
    cmd.addCommand("touch", &touch);
    cmd.addCommand("ls", &ls);
    cmd.addCommand("rm", &rm);
    cmd.addCommand("cat", &cat);
    cmd.addCommand("ds", &ds);
    cmd.addCommand("cp", &copy);
    cmd.addCommand("rn", &rename);
    cmd.addCommand("catds", &catds);
    cmd.addCommand("size", &size);

    cmd.run();

    return SUCCESS;
}