#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/PasswordProxy.h"
#include <iostream>

int main(int argc, char* argv[]) {
	// Create a file factory
	AbstractFileFactory* factory = new SimpleFileFactory();

	// Create a text file using the file factory
	AbstractFile* txt = factory->createFile("text_file.txt");

	// Create a password proxy to the file
	PasswordProxy* proxy_txt = new PasswordProxy(txt, "test_password");


	// Write to file
	proxy_txt->write({ '1', '2', '3' });

	// Create BasicDisplayVisitor
	BasicDisplayVisitor* dvisitor = new BasicDisplayVisitor;

	// Use accept to display
	proxy_txt->accept(dvisitor);

	// Create MetadataDisplayVistor
	MetadataDisplayVisitor* mvisitor = new MetadataDisplayVisitor();

	// Use accept to read metadata
	proxy_txt->accept(mvisitor);

	return SUCCESS;
}