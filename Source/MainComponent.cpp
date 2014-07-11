/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    m_pController = new Controller();
    m_pButton1 = new TextButton("Test");
    addAndMakeVisible(m_pButton1);
    
    m_pSelectArmyDropDown = m_pController->PopulateArmyDropDownComponent();
    addAndMakeVisible(m_pSelectArmyDropDown);
    
    m_pMaxPointField = m_pController->CreatePointField();
    addAndMakeVisible(m_pMaxPointField);
    
    
    setSize (500, 400);
}

MainContentComponent::~MainContentComponent()
{
    delete m_pButton1;
    delete m_pController;
    delete m_pSelectArmyDropDown;
    
    // This variable will be deleted in the Controller class.
    //delete m_pMaxPointField;
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));

    g.setFont (Font (16.0f));
    g.setColour (Colours::black);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    m_pButton1->setBounds(10,10,40,15);
    m_pMaxPointField->setBounds(10,30,250,15);
    m_pSelectArmyDropDown->setBounds(10,50,120,15);
}
