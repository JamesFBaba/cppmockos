/**
 * PasswordProxy.cpp
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains constructor and all function definitions for PasswordProxy class.
*/

#include "mockos/PasswordProxy.h"

#include<iostream>

PasswordProxy::PasswordProxy(AbstractFile* file, std::string password) : file_(file), password_(password) {
}


PasswordProxy::~PasswordProxy() {
	delete file_;
}

// Prompt user for a password and record it. Return the password.
std::string PasswordProxy::passwordPrompt() {
	std::cout << "Please enter the password for file." << std::endl;
	std::string input;
	std::getline(std::cin, input);
	return input;
}

// Given a password 'input', check if it matches password_ and return true/false
bool PasswordProxy::correctPassword(std::string input) {
	if (input == password_) {
		return true;
	}
	else {
        std::cout << "Incorrect password." << std::endl;
		return false;
	}
}



/// Implementations of the original virtual AbstractFile methods:

// Read and return raw data from proxied file if given correct password
std::vector<char> PasswordProxy::read() {
	// Get user's password
	std::string input = passwordPrompt();

	// Return data if correct password, else empty vector
	if (correctPassword(input)) {
		return file_->read();
	}
	else {
		std::vector<char> v = {};
		return(v);
	}
}

// Write vector<char> v to proxied file if password is correct
int PasswordProxy::write(std::vector<char> v) {
	// Get user's password
	std::string input = passwordPrompt();

	// Write if password is correct, otherwise print and return error
	if (correctPassword(input)) {
		return file_->write(v);
	}
	else {
		return INCORRECT_PASSWORD;
	}
}

// Append vector<char> v to proxied file if password is correct
int PasswordProxy::append(std::vector<char> v) {
	// Get user's password
	std::string input = passwordPrompt();

	// Append if password is correct, otherwise print and return error
	if (correctPassword(input)) {
		return file_->append(v);
	}
	else {
		return INCORRECT_PASSWORD;
	}
}

// Return size of the proxied file
unsigned int PasswordProxy::getSize() {
	return file_->getSize();
}

// Return name of the proxied file
std::string PasswordProxy::getName() {
	return file_->getName();
}

// Allow the proxied file to accept visitors if the password is correct
void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	std::string input = passwordPrompt();
	if (correctPassword(input)) {
		file_->accept(visitor);
	}
}

// Allow proxied files to be copied
AbstractFile* PasswordProxy::clone(std::string newName) {
    AbstractFile* newFile = file_->clone(newName);
    if (newFile == nullptr) {
        return nullptr;
    } else {
        return new PasswordProxy(newFile, password_);
    }
}