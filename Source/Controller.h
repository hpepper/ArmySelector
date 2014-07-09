/*
  ==============================================================================

    Controller.h
    Created: 9 Jul 2014 2:15:44am

  ==============================================================================
*/

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "Model.h"

class Controller : public Component, Value::Listener {
    public:
    Controller();
    ~Controller();
    
    void valueChanged(Value &value);

    ChoicePropertyComponent * PopulateArmyDropDownComponent();
    
    private:
    
    Model *m_pModel;
    Value *m_pValue;
    
    var m_nArmySelectionIndex;
    
    Value *m_pArmySelected;
    
    StringArray m_cArmyChoices;
    Array<var> m_arArmyChoiceVars;

};



#endif  // CONTROLLER_H_INCLUDED
