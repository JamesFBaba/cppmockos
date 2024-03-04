/**
 * SizeVisitor.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains all function declarations and member variables for SizeVisitor class. Also contains enums for
 * stats vector positions.
*/

#ifndef SIZE_VISITOR_H
#define SIZE_VISITOR_H

#include"AbstractFileVisitor.h"
#include <vector>


class SizeVisitor : public AbstractFileVisitor {
public:
    SizeVisitor();
	void visit_img(ImageFile* img);
	void visit_txt(TextFile* txt);
    std::vector<int> getStats();
private:
    int num_txt;
    int num_img;
    int space_txt;
    int space_img;
    int largest_txt;
    int largest_img;
};

enum statVectorPositions {
    NUM_TXT = 0,
    NUM_IMG = 1,
    SPACE_TXT = 2,
    SPACE_IMG = 3,
    LARGEST_TXT = 4,
    LARGEST_IMG = 5
};


#endif // SIZE_VISITOR_H