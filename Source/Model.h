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
    Model(String);
    ~Model();
    
    std::vector<String> GetArmyNameList();
    
    var GetArmySizeInPoints();
    var SetArmySizeInPoints(var nPoints);
    
    private:
    XmlDocument *m_pXmlDocument;
    XmlElement *m_pXmlRootElement;
    
    var m_nMaximumArmySizeInPoints;
};



#endif  // MODEL_H_INCLUDED
