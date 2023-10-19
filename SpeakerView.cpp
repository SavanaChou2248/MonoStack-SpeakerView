/*
Savana Chou
2428859
sachou@chapman.edu
CPSC350-02
Programming Assignment 3: Do You See What I See?

Brief Overview:
Processes a file and identifies who is able to see the front looking at the height in each column.
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "SpeakerView.h"

using namespace std;

/*
Constructor for SpeakerView Class
Parameter(s): inputFileName - a reference to a string containing the name of the input file
Description: Opens the input file name specified by inputFileName and initializes class variables
*/
SpeakerView::SpeakerView(string& inputFileName) {
    m_inputFileName.open(inputFileName);
    numCols = 0;
    numRows = 0;

    if (!m_inputFileName.is_open()) {
        cout << "Error: Unable to open input file." << endl;
    }
}

/*
Destructor for SpeakerView Class
*/
SpeakerView::~SpeakerView() {
    m_inputFileName.close();
    for (int i = 0; i < numRows; ++i) {
        delete[] heightData[i];
    }
    delete[] heightData;
}

/*
Name: processInput
Parameter(s): none
Description: Processes the file input by determining the number of rows and columns then populate a 2D array with the values in the file input.
*/
void SpeakerView::processInput() {
    string line;

    getline(m_inputFileName, line); //skips first line
    while(getline(m_inputFileName, line)) { //finding number of rows
        if (line == "END.") {
            break;
        }
        ++numRows;
        istringstream lineStream(line);
        double value;
        while (lineStream >> value) { //finding number of columns
            ++numCols;
        }
    }
    numCols /= numRows;

    m_inputFileName.clear(); //clear instance of an input file stream
    m_inputFileName.seekg(0); // resets to position beginning of the file

    heightData = new double*[numRows];
    for (int i = 0; i < numRows; ++i) {
        heightData[i] = new double[numCols];
    }
    
    getline(m_inputFileName, line); //skips first line
    for (int i = 0; i < numRows; ++i) {
        getline(m_inputFileName, line);
        istringstream lineStream(line);
        for (int j = 0; j < numCols; ++j) {
            if (lineStream >> heightData[i][j]) { //populates array
            } 
        }
    }
}

/*
Name: createOutput
Parameter(s): none
Description: processes the data using MonoStack call to find the heights that are able to see in each column. 
The 2D array is being iterated by each column and backwards to get accurate results. Then prints the results to the console.
*/
void SpeakerView::createOutput() {
    processInput();
    MonoStack<double> myMonoStack(10, 'd');
    for (int i = 0; i < numCols; ++i) {
        for (int j = numRows - 1; j >= 0; --j) {
            myMonoStack.push(heightData[j][i]);
        }
        cout << "In column " << i << " there are " << myMonoStack.size() << " that can see. Their heights are: ";
        while(!myMonoStack.isEmpty()) {
            if (myMonoStack.size() == 1) {
                cout << myMonoStack.pop() << " inches.";
            } else {
                cout << myMonoStack.pop() << ", ";
            }
        }
        cout << endl;
    }
}