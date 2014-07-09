/*
  ==============================================================================

    Controller.cpp
    Created: 9 Jul 2014 2:15:44am

  ==============================================================================
*/

#include "Controller.h"


Controller::Controller()
{
//    m_pModel = new Model("../../../../Data/epic.xml");
    m_pModel = new Model("../../Data/epic.xml");
//    m_pModel = new Model("../../Data/test.xml");

    m_nArmySelectionIndex = 0;
    
    m_pArmySelected = new Value(m_nArmySelectionIndex);
    
    m_pArmySelected->addListener(this);
   

    
    
}

Controller::~Controller()
{
    delete m_pModel;
}

ChoicePropertyComponent * Controller::PopulateArmyDropDownComponent()
{
    int nStatus = 0;
    
    m_cArmyChoices.clear();
    m_arArmyChoiceVars.clear();
    
    std::vector<String> ArmyNameList = m_pModel->GetArmyNameList();
    
    int nIndex = 0;
    std::vector<String>::const_iterator sEntry;
    for(sEntry=ArmyNameList.begin(); sEntry!=ArmyNameList.end(); ++sEntry){
        std::cout << "DDD " << *sEntry << std::endl;
        m_cArmyChoices.add(*sEntry);
        m_arArmyChoiceVars.add(nIndex);
       nIndex++;
    }
    
    // TODO V Only if the pSelectArmyDropDown is NULL allocate a new one.
    ChoicePropertyComponent *pSelectArmyDropDown = new ChoicePropertyComponent (*m_pArmySelected, "Select Army", m_cArmyChoices, m_arArmyChoiceVars);
    
    return(pSelectArmyDropDown);
}


void Controller::valueChanged(Value &value)
{
    
    if ( value.refersToSameSourceAs(*m_pArmySelected) ) {
        var nIndex = value.getValue();
        std::cout << "DropDown Changed: " << value.toString() << std::endl;
    }
}
