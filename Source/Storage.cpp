/*
  ==============================================================================

    Storage.cpp
    Created: 13 Jul 2014 12:01:39pm

  ==============================================================================
*/

#include "Storage.h"

Storage::Storage() {
    File cExecutablePath =  File::getSpecialLocation(File::userDocumentsDirectory);
    // TODO V Figure out how to call the class instance with the parm.
    m_sAbsoluteStoragePath = cExecutablePath.getFullPathName();
}

Storage::Storage(String sAbsoluteStoragePath) {
    //m_sAbsoluteStoragePath = sAbsoluteStoragePath;
    m_sAbsoluteStoragePath = "TEST";
    
    std::cout << "III Storage(" << m_sAbsoluteStoragePath << ")" << std::endl;
}

void Storage::PrintBaseStorageDir() {
    std::cout << "DDD PrintBaseStorageDir(" << m_sAbsoluteStoragePath << ")" << std::endl;
}

Storage::~Storage() {
    std::cout << "DDD Storage DESTRUCTOR" << std::endl;
}

int Storage::SaveXmlFile(String sFileName) {
    // TODO N Lookup the path seperator (part of the 'File' class.
    String sTargetFile = m_sAbsoluteStoragePath + "/" + sFileName;
    // std::cout << "DDD m_sAbsoluteStoragePath = '" << m_sAbsoluteStoragePath << "'" << std::endl;
    std::cout << "III SaveXmlFile(" << sTargetFile << ")" << std::endl;
 
    XmlElement xmlRoot("ArmyList");
    xmlRoot.setAttribute("Version", "0.1.0");
    XmlElement *xmlArmyName = xmlRoot.createNewChildElement("ArmyName");
    xmlArmyName->addTextElement("Eldar");
    xmlRoot.writeToFile(File(sTargetFile), "", "UTF-8", 100);

    
}