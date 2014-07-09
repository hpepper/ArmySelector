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
   
    std::vector<String> ArmyNameList = m_pModel->GetArmyNameList();
    
    int nIndex = 0;
    std::vector<String>::const_iterator sEntry;
    for(sEntry=ArmyNameList.begin(); sEntry!=ArmyNameList.end(); ++sEntry){
        std::cout << "DDD " << *sEntry << std::endl;
       nIndex++;
    }

    
    
}

Controller::~Controller()
{
    delete m_pModel;
}