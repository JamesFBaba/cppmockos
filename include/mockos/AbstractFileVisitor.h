/**
 * AbstractFileVisitor.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations for AbstractFileVisitor class.
*/

#ifndef ABSTRACT_FILE_VISITOR_H
#define ABSTRACT_FILE_VISITOR_H

class ImageFile;
class TextFile;

class AbstractFileVisitor {
public:
	virtual void visit_img(ImageFile* img) = 0;
	virtual void visit_txt(TextFile* txt) = 0;

private:
};


#endif // ABSTRACT_FILE_VISITOR_H