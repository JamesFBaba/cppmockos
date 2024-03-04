/**
 * Constants.h
 * CSE 332S
 * Lab Num: 5
 * Authors: Aaron Jeck <a.h.jeck@wustl.edu> and James Baba <baba.j@wustl.edu>
 * Contains error enums used throughout program.
*/

#ifndef CONSTANTS_H
#define CONSTANTS_H

enum errors {
    SUCCESS = 0,
    INVALID_IMAGE_DIM = 1,
    INVALID_IMAGE_CONTENTS = 2,
    APPEND_NOT_SUPPORTED_FOR_FILETYPE = 3,
    FILE_ALREADY_EXISTS = 4,
    NULL_POINTER = 5,
    INVALID_FILE_EXTENSION = 6,
    FILE_NOT_OPEN = 7,
    CANNOT_DELETE_OPEN_FILE = 8,
    FILE_DOES_NOT_EXIST = 9,
    INCORRECT_PASSWORD = 10,
    FAILED_TO_INSERT_CMD = 11,
    QUIT = 12,
    FAILED_TO_CREATE_FILE = 13,
    FAILED_TO_ADD_FILE = 14,
    INVALID_CMD_OPTION = 15,
    INVALID_CMD_ARGS = 16
};

#endif //CONSTANTS_H
