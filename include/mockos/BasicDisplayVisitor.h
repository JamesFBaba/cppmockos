/**
 * BasicDisplayVisitor.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations for BasicDisplayVisitor class.
*/

#ifndef BASIC_DISPLAY_VISITOR_H
#define BASIC_DISPLAY_VISITOR_H

#include"AbstractFileVisitor.h"


class BasicDisplayVisitor : public AbstractFileVisitor {
public:
	void visit_img(ImageFile* img);
	void visit_txt(TextFile* txt);
private:
};


#endif // BASIC_DISPLAY_VISITOR_H