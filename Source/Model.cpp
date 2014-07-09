/*
  ==============================================================================

    Model.cpp
    Created: 9 Jul 2014 2:25:08am

  ==============================================================================
*/

#include "Model.h"
#include <iostream>


Model::Model(std::string szFileName)
{
    std::cout << szFileName << std::endl;
    if ( File(szFileName).exists() ) {
        std::cout << " exists" << std::endl;
    } else {
        std::cout << " does NOT exist !!!" << std::endl;      
    }
    m_pXmlDocument = new XmlDocument(File(szFileName));
    m_pXmlRootElement = m_pXmlDocument->getDocumentElement();
    if (m_pXmlRootElement == nullptr) {
        String error = m_pXmlDocument->getLastParseError();
        std::cout << "!!! " << error << std::endl;
    } 
    
}

Model::~Model()
{
    delete m_pXmlDocument;
}

std::vector<String> Model::GetArmyNameList()
{
    std::vector<String> cArmyNameList;
    
    XmlElement* xmlFirstArmyElement = m_pXmlRootElement->getChildByName("Army");
    cArmyNameList.push_back(xmlFirstArmyElement->getStringAttribute("Name"));
        
    XmlElement* xmlArmyElement;
    while ( ( xmlArmyElement = m_pXmlRootElement->getNextElementWithTagName("Army") ) != NULL ) {
        cArmyNameList.push_back(xmlArmyElement->getStringAttribute("Name"));
    }

    return(cArmyNameList);
}