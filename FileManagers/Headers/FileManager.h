//
// Created by gunther on 25/11/20.
//

#ifndef KINDERCOLORING_FILEMANAGER_H
#define KINDERCOLORING_FILEMANAGER_H


class FileManager {

public:

    //File Management System
    virtual void readFile(char* filePath) = 0;
    virtual void writeFile(char* filePath) = 0;

};


#endif //KINDERCOLORING_FILEMANAGER_H
