/*
  ==============================================================================

    Controller.cpp
    Created: 9 Jul 2014 2:15:44am

  ==============================================================================
*/

#include "Controller.h"


Controller::Controller()
{
    m_pModel = new Model("../../../../Data/epic.xml");
}

Controller::~Controller()
{
    delete m_pModel;
}