/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    m_fCurrentFontHeight = 14.0f;

    std::vector<String> cArmyNameList;
    
    cArmyNameList.push_back("tut");

    XmlDocument myDocument (File ("../../../../Data/epic.xml"));
    XmlElement* mainElement = myDocument.getDocumentElement();
    if (mainElement == nullptr) {
        String error = myDocument.getLastParseError();
    } else {
        XmlElement* xmlFirstArmyElement = mainElement->getChildByName("Army");
        cArmyNameList.push_back(xmlFirstArmyElement->getStringAttribute("Name"));
        
        XmlElement* xmlArmyElement;
        while ( ( xmlArmyElement = mainElement->getNextElementWithTagName("Army") ) != NULL ) {
            cArmyNameList.push_back(xmlArmyElement->getStringAttribute("Name"));
        }
        
        
        StringArray choices;
        Array<var> choiceVars;
        
        int nIndex = 0;
        std::vector<String>::const_iterator sEntry;
        for(sEntry=cArmyNameList.begin(); sEntry!=cArmyNameList.end(); ++sEntry){
            choices.add(*sEntry);
            choiceVars.add(nIndex);
            nIndex++;
        }
        
        //for (int nIndex = 0; nIndex < cArmyNameList.max_size(); nIndex++) {
        //    choices.add(cArmyNameList.at(nIndex));
        //    choiceVars.add(nIndex);
        //}
        
        var nMyVar = 0;
        
        
        Value nArmySelected(nMyVar);
        m_pSelectArmyDropDown = new ChoicePropertyComponent (nArmySelected, "Select Army", choices, choiceVars);
        m_pButton1 = new TextButton("Click");
        
        addAndMakeVisible(m_pSelectArmyDropDown);
        addAndMakeVisible(m_pButton1);
        
    }

    setSize (500, 400);
}

MainContentComponent::~MainContentComponent()
{
    delete m_pSelectArmyDropDown;
    delete m_pButton1;
}

void MainContentComponent::paint (Graphics& g)
{
    
    g.fillAll (Colour (0xffeeddff));

    g.setFont (Font (16.0f));
    g.setColour (Colours::black);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
//    File("./DragonHere.txt").create();
    
    
    //      g.drawText (szArmyName, getLocalBounds(), Justification::centred, true);
    
    // TODO V Find a way to find the XML file, that works on OSX, Windows and Linnux.
    // TODO C Select Army to choose from.
      //  Imperial can choose, Emperial, Marine, and I think Squad.
    // TODO C Then request Points
    // TODO C Read the selected army info.
    // TODO C Allow selection of units/Cards.
    // TODO V Enable saving the configured army in xml.
}



/*  get file location
 Depends on OS and ENVIRONMENT
 
 getSpecialLocation()
   currentApplicationFile
 See: http://www.juce.com/api/classFile.html#details
 */

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    //int nTextHeight = int( m_fCurrentFontHeight * 1.1 ) + 3;
    //m_pSelectArmyDropDown->setBounds(0,0, getWidth(), nTextHeight);
    m_pSelectArmyDropDown->setBoundsRelative (0.05, 0.05, 0.90, 0.25);
    m_pButton1->setBounds(0, 0, 23, 40);
}
