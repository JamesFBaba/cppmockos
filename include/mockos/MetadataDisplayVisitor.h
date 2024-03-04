/**
 * MetadataDisplayVisitor.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations for MetadataDisplayVisitor class.
*/

#ifndef METADATA_DISPLAY_VISITOR_H
#define METADATA_DISPLAY_VISITOR_H

#include"AbstractFileVisitor.h"


class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	void visit_img(ImageFile* img);
	void visit_txt(TextFile* txt);
private:
};


#endif // METADATA_DISPLAY_VISITOR_H