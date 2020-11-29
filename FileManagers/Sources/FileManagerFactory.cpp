//
// Created by gunther on 25/11/20.
//

#include "../Headers/FileManagerFactory.h"

FileManager* FileManagerFactory::createManager(FileType fileType) {

    switch (fileType) {

        case FileType::Xml:

            return (FileManager*) new XmlManager();


    }
}