/*
  ==============================================================================

    Controller.h
    Created: 9 Jul 2014 2:15:44am

  ==============================================================================
*/

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "Model.h"

class Controller {
    public:
    Controller();
    ~Controller();
    
    
    private:
    
    Model *m_pModel;
};



#endif  // CONTROLLER_H_INCLUDED
