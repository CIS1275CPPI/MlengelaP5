/***********************************************************************************
* Program: C++ Hardware Store in the paint department.
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: 1 November 2021.
* Purpose: Determine the amount of paint needed to paint a room.
************************************************************************************/

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <string>
#include <cmath>
#include<sstream>
#include<cctype>

using namespace std;

void WriteHeader(void);

int HowManyGallons(
    double length,
    double width,
    double height,
    int    coverage,
    int    coats,
    bool   ceiling,
    int    percentNoPaint
);

int HowManyGallons(
    double radius,
    double height,
    int    coverage,
    int    coats,
    bool   ceiling,
    int    percentNoPaint
);

void AskForNameAndShape(string& rName, bool& rIsRectangular);

void AskForDimensions(
    double* pRadius,
    double* pHeight,
    int* pPercentNoPaint,
    string* pDimens
);

void AskForDimensions(
    double* pLength,
    double* pWidth,
    double* pHeight,
    int* pPercentNoPaint,
    string* pDimens
);

void AskForPaintInfo(int& rCoats, int& rCoverage, bool& rPaintCeiling);

void Goodbye(void);

void DoAgain(void);


#endif
