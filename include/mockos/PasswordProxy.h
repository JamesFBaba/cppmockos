/**
 * PasswordProxy.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for PasswordProxy class.
*/

#ifndef PASSWORD_PROXY_H
#define PASSWORD_PROXY_H
#include "mockos/AbstractFile.h"

class PasswordProxy : public AbstractFile {
private:
	AbstractFile* file_;
	std::string password_;
public:
	PasswordProxy(AbstractFile* file, std::string password);
	~PasswordProxy();

	std::vector<char> read();
	int write(std::vector<char> v);
	int append(std::vector<char> v);
	unsigned int getSize();
	std::string getName();
	void accept(AbstractFileVisitor* visitor);
    virtual AbstractFile* clone(std::string newName);

protected:
	std::string passwordPrompt();
	bool correctPassword(std::string input);
};

#endif // PASSWORD_PROXY_H