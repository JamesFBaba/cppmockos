#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/SimpleFileFactory.h"

#include "mockos/SimpleFileSystem.h"

#include <iostream>

int main(int argc, char* argv[]) {
	// Create a file system and file factory
	AbstractFileSystem* system = new SimpleFileSystem();
	AbstractFileFactory* factory = new SimpleFileFactory();

	// Create a couple of files using the file factory
	AbstractFile* txt = factory->createFile("text_file.txt");
	AbstractFile* img = factory->createFile("image_file.img");

	// Add the files to the file system
	system->addFile("text_file.txt", txt);
	system->addFile("image_file.img", img);

	// Open each file
	AbstractFile* open_txt = system->openFile("text_file.txt");
	AbstractFile* open_img = system->openFile("image_file.img");

	// Write to each file
	open_txt->write({ '1', '2', '3' });
	open_img->write({ 'X', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', '3' });

	// Read each file
	open_txt->read();
	open_img->read();

	// Close each file
	system->closeFile(open_txt);
	system->closeFile(open_img);

	return SUCCESS;
}