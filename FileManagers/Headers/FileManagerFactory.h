//
// Created by gunther on 25/11/20.
//

#include "FileManager.h"
#include "XmlManager.h"

#ifndef KINDERCOLORING_FILEMANAGERFACTORY_H
#define KINDERCOLORING_FILEMANAGERFACTORY_H

enum class FileType{

    Xml,
    Txt
};

class FileManagerFactory {

public:

    FileManager* createManager(FileType fileType);

};


#endif //KINDERCOLORING_FILEMANAGERFACTORY_H
