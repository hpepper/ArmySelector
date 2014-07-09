/*
  ==============================================================================

    Model.h
    Created: 9 Jul 2014 2:25:07am

  ==============================================================================
*/

#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <string>

#include "../JuceLibraryCode/JuceHeader.h"

class Model {
    public:
    Model(std::string);
    ~Model();
    
    private:
    XmlDocument *m_pXmlDocument;
};



#endif  // MODEL_H_INCLUDED
