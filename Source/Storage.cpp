/*
  ==============================================================================

    Storage.cpp
    Created: 13 Jul 2014 12:01:39pm

  ==============================================================================
*/

#include "Storage.h"

Storage::Storage() {
    File cExecutablePath =  File::getSpecialLocation(File::userDocumentsDirectory);
    Storage(cExecutablePath.getFullPathName());
}

Storage::Storage(String sAbsoluteStoragePath) {
    m_sAbsoluteStoragePath = sAbsoluteStoragePath;
    
    std::cout << m_sAbsoluteStoragePath << std::endl;
}

Storage::~Storage() {
}