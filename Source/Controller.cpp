/*
  ==============================================================================

    Controller.cpp
    Created: 9 Jul 2014 2:15:44am

  ==============================================================================
*/

#include "Controller.h"

#define SINGLE_LINE_FIELD false
#define MULTI_LINE_FIELD true

Controller::Controller()
{
//    m_pModel = new Model("../../../../Data/epic.xml");
    m_pModel = new Model("../../Data/epic.xml");
//    m_pModel = new Model("../../Data/test.xml");

    m_nArmySelectionIndex = 0;
    
    m_pArmySelected = new Value(m_nArmySelectionIndex);
    
    m_pArmySelected->addListener(this);
    
    m_nMaxArmyPointSize = 0;
    m_pMaxPointFieldValue = new Value(m_nMaxArmyPointSize); 
    m_pMaxPointFieldValue->addListener(this);
}

Controller::~Controller()
{
    delete m_pModel;
    delete m_pMaxPointField;
    delete m_pMaxPointFieldValue;
}

TextPropertyComponent * Controller::CreatePointField()
{
    m_pMaxPointField = new TextPropertyComponent(*m_pMaxPointFieldValue, "Army maximum point size:", 5, SINGLE_LINE_FIELD);
    // TODO C grab the value from the Model.
    // TODO V filter the entry thingy so that it will only take numbers.
    return(m_pMaxPointField);
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
    } else if ( value.refersToSameSourceAs(*m_pMaxPointFieldValue) ) {
        // Get the 'var' out of the 'Value'
        var nPointsVar = value.getValue();
        
        // Convert the 'var' to an int.
        int nPoints = (nPointsVar.toString()).getIntValue();
        
        // Find out if the input contained any char or was a clean integer.
        var cVarCompare(nPoints);
        if ( ! nPointsVar.equals(cVarCompare) ) {
            std::cout << "Point value invalid: " << value.toString() << std::endl;
            m_nMaxArmyPointSize = 0;
            value.setValue(m_nMaxArmyPointSize);
        } else if ( nPoints < 0 ) {
            std::cout << "Negative point values not allowed: " << value.toString() << std::endl;
            m_nMaxArmyPointSize = 0;
            value.setValue(m_nMaxArmyPointSize);
        } else {
            std::cout << "Point value Changed: " << value.toString() << std::endl;
            // Re-caclulate the 'Unused'/'Poits left' points label.
        }
    }
}
