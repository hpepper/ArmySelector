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
    m_pXmlDocument = new XmlDocument(File(szFileName));
}

Model::~Model()
{
    delete m_pXmlDocument;
}