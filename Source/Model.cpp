/*
  ==============================================================================

    Model.cpp
    Created: 9 Jul 2014 2:25:08am

  ==============================================================================
*/

#include "Model.h"
#include <iostream>


Model::Model(String szFileName)
{
    m_nMaximumArmySizeInPoints = 0;
    std::cout << szFileName << std::endl;
    // TODO V Support absolute paths as well.
    File cXmlFile = File::getCurrentWorkingDirectory().getChildFile(szFileName);
    if ( cXmlFile.exists() ) {
        std::cout << " exists" << std::endl;
        m_pXmlDocument = new XmlDocument(cXmlFile);
        m_pXmlRootElement = m_pXmlDocument->getDocumentElement();
        if (m_pXmlRootElement == nullptr) {
            String error = m_pXmlDocument->getLastParseError();
            std::cout << "!!! " << error << std::endl;
        } 
    } else {
        std::cout << " does NOT exist !!!" << std::endl;  
        m_pXmlRootElement = new XmlElement("ArmyList");
        m_pXmlRootElement->setAttribute("Version", "0.1.0");
        XmlElement *xmlArmyName = m_pXmlRootElement->createNewChildElement("ArmyName");
        xmlArmyName->addTextElement("Eldar");
    }
    
}

Model::~Model()
{
    delete m_pXmlDocument;
}

std::vector<String> Model::GetArmyNameList()
{
    std::vector<String> cArmyNameList;
  
    /*
    XmlElement* xmlFirstArmyElement = m_pXmlRootElement->getChildByName("Army");
    cArmyNameList.push_back(xmlFirstArmyElement->getStringAttribute("Name"));
        
    XmlElement* xmlArmyElement;
    while ( ( xmlArmyElement = m_pXmlRootElement->getNextElementWithTagName("Army") ) != NULL ) {
        cArmyNameList.push_back(xmlArmyElement->getStringAttribute("Name"));
    }
    */
    forEachXmlChildElementWithTagName (*m_pXmlRootElement, xmlArmyElement, "Army")
    {
      //  std::cout << xmlArmyElement->getStringAttribute("Name") << std::endl;
      cArmyNameList.push_back(xmlArmyElement->getStringAttribute("Name"));
    }

    return(cArmyNameList);
}


int Model::SetArmySizeInPoints(int nPoints)
{
    if ( nPoints > 0 ){
        m_nMaximumArmySizeInPoints = nPoints;
    } else {
        m_nMaximumArmySizeInPoints = 0;
    }
    std::cout << "SetArmySizeInPoints(): " << m_nMaximumArmySizeInPoints << std::endl;
    return(m_nMaximumArmySizeInPoints);
}