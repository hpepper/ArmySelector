/*
  ==============================================================================

    Controller.h
    Created: 9 Jul 2014 2:15:44am

  ==============================================================================
*/

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "Model.h"
#include "Storage.h"

class Controller : public Component, Value::Listener {
    public:
    Controller();
    ~Controller();
    
    void valueChanged(Value &value);

    ChoicePropertyComponent * PopulateArmyDropDownComponent();
    TextPropertyComponent * CreatePointField();
    
    int Save();
    
    private:
    
    Model *m_pModel;
    Value *m_pValue;
    Storage *m_pStorage;
    
    var m_nArmySelectionIndex;
    
    Value *m_pArmySelected;
    
    StringArray m_cArmyChoices;
    Array<var> m_arArmyChoiceVars;
    
    TextPropertyComponent *m_pMaxPointField;
    Value *m_pMaxPointFieldValue;
    var m_nMaxArmyPointSize;

};



#endif  // CONTROLLER_H_INCLUDED
