#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include <iostream>

int main(int argc, char* argv[]) {
	// Create a file factory
	AbstractFileFactory* factory = new SimpleFileFactory();

	// Create a couple of files using the file factory
	AbstractFile* txt = factory->createFile("text_file.txt");
	AbstractFile* img = factory->createFile("image_file.img");

	// Write to both files
	txt->write({ '1', '2', '3' });
	img->write({ 'X', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', '3' });

	// Create BasicDisplayVisitor
	BasicDisplayVisitor* visitor = new BasicDisplayVisitor;

	// Use accept to read
	txt->accept(visitor);
	
	img->accept(visitor);


	return SUCCESS;
}