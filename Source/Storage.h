/*
  ==============================================================================

    Storage.h
    Created: 13 Jul 2014 12:01:39pm

  ==============================================================================
*/

#ifndef STORAGE_H_INCLUDED
#define STORAGE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
// TODO V later support more than XML storage, but handle that in sub classes.

class Storage {
    
    public: 
    Storage();
    Storage(String);
    ~Storage();
    
    int SaveXmlFile(String sFileName, String sArmyName, var nMaxArmyPointSize);
    
    void PrintBaseStorageDir();
    
    
    private:
    String m_sAbsoluteStoragePath;
};





#endif  // STORAGE_H_INCLUDED
