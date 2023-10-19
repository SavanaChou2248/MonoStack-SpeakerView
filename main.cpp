/*
Savana Chou
2428859
sachou@chapman.edu
CPSC350-02
Programming Assignment 3: Do You See What I See?
*/

#include <iostream>
#include <string>
#include <sstream>
#include "MonoStack.h"
#include "SpeakerView.h"


using namespace std;

int main(int argc, char* argv[]) {
    
    string inputFile = argv[1];
    SpeakerView test(inputFile);

    test.createOutput();

    return 0;
}