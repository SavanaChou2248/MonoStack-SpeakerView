/*
Savana Chou
2428859
sachou@chapman.edu
CPSC350-02
Programming Assignment 3: Do You See What I See?
*/


#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include <fstream>
#include "MonoStack.h"

class SpeakerView {
public:
    SpeakerView(string& inputFileName);
    virtual ~SpeakerView();
    void processInput();
    void createOutput();
private:
    ifstream m_inputFileName;
    double** heightData;
    int numRows;
    int numCols;
};

#endif