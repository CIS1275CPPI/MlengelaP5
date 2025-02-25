/***********************************************************************************
* Program: C++ Hardware Store in the paint department.
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: 1 November 2021.
* Purpose: Determine the amount of paint needed to paint a room.
************************************************************************************/
#include <iostream>
#include <sstream>
#include <cmath>
#include "Functions.h"

/*********************************************************
* Display Header to introduce the program. 
*********************************************************/
void WriteHeader(void)
{
	cout << "Clark Kent" << "\n";
	cout << "The Paint Estimator" << "\n";
	cout << "Objective: Determine the amount of paint needed to paint a room " << "\n";
}
/*************************************************************************************
* Calculates how many cans of paint needed for a rectangular room.
**************************************************************************************/
int HowManyGallons(
	double length,
	double width,
	double heigth,
	int    coverage,
	int    coats,
	bool   ceiling,
	int percentNoPaint
	)
{
    double totalArea = 0.0;

    // We always paint the floor

    totalArea += length * width;

    // Add the ceilng area if requested

    if (ceiling)
        totalArea += length * width;

    // Find the total area of the walls, then adjust for the
    // percent not painted

    double wallsArea = 2 * length * heigth + 2 * width * heigth;

    wallsArea *= (100 - percentNoPaint) / 100.0;

    // Now we can get the total area

    totalArea += wallsArea;

    double gallons = (coats * totalArea) / coverage;

    // Round up to number of gallons

    return(int(ceil(gallons)));
}
/*******************************************************************************
* Calculates how many cans of paint needed for a circular room.
********************************************************************************/
int HowManyGallons(
    double radius,
    double height,
    int    coverage,
    int    coats,
    bool   ceiling,
    int    percentNoPaint
)
{
    static const double PI = 3.14159265358979323846;

    double totalArea = 0.0;

    // We always paint the floor

    totalArea += PI * radius * radius;

    // Add the ceilng area if requested

    if (ceiling)
        totalArea += PI * radius * radius;

    // Find the total area of the walls, the adjust for the
    // percent not painted

    double wallsArea = 2 * PI * radius * height;

    wallsArea *= (100 - percentNoPaint) / 100.0;

    // Now we can get the total area

    totalArea += wallsArea;

    double gallons = (coats * totalArea) / coverage;

    return(int(ceil(gallons)));
}

/************************************************************************
* Gets info from customer.
************************************************************************/

void AskForNameAndShape(string& rName, bool& rIsRectangular)
{
    /***********************************************
    * Get name string.
    ***********************************************/
    cout << "Please enter your name: ";
    cin >> rName;
    /***********************************************
    * Ask the user the size of the room.
    ************************************************/
    rIsRectangular = true;
    {
        cout << "Is your room rectangular? (y/n) ";
    }

    /************************************************
    * Ask for input of the room.
    *************************************************/
    string input;
    cin >> input;

    if (input.size() > 0 && tolower(input[0]) == 'n')
        rIsRectangular = false;
}

/*******************************************************
* Gets dimensions of the circular room.
********************************************************/
void AskForDimensions(
    double* pRadius,
    double* pHeight,
    int* pPercentNoPaint,
    string* pDimens
)
{
    /**********************************************
    * Get radius of the room.  
    **********************************************/
    cout << "Enter the room radius: ";
    cin >> *pRadius;
    /*********************************************
    * Get the height of the room. 
    **********************************************/
    cout << "Enter the room height: ";
    cin >> *pHeight;
    /*********************************************
    * Get the percent to not paint. 
    **********************************************/
    cout << "What percent to not paint? ";
    cin >> *pPercentNoPaint;

    std::ostringstream out;

    out <<
        "Circular: " <<
        *pRadius << " radius, " <<
        *pHeight << " height, " <<
        *pPercentNoPaint << " percent no paint";

    *pDimens = out.str();
     cin.ignore();
}

/********************************************************
* Gets dimensions of the rectangular room.
*********************************************************/
void AskForDimensions(
    double* pLength,
    double* pWidth,
    double* pHeight,
    int* pPercentNoPaint,
    string* pDimens
)
{
    /******************************************************
    * Get the length.
    *******************************************************/
    cout << "Enter the room length: ";
    cin >> *pLength;
    /*****************************************************
    * Get the width.
    ******************************************************/
    cout << "Enter the room width: ";
    cin >> *pWidth;
    /******************************************************
    * Get the height.
    ******************************************************/
    cout << "Enter the room height: ";
    cin >> *pHeight;
    /****************************************************
    * Get the percent to not paint.
    *****************************************************/
    cout << "What percent to not paint? ";
    cin >> *pPercentNoPaint;

    std::ostringstream out;

    out <<
        "Rectangular: " <<
        *pLength << " length, " <<
        *pWidth << " width, " <<
        *pHeight << " height, " <<
        *pPercentNoPaint << " percent no paint";

    *pDimens = out.str();
     cin.ignore();
}

/*********************************************************************
* Gets info on the paint used.  
*********************************************************************/
void AskForPaintInfo(int& rCoats, int& rCoverage, bool& rPaintCeiling)
{
    /***********************************************************
    * Get the number of coats from the user. 
    ************************************************************/
    cout << "How many coats? ";
    cin >> rCoats;

    /***********************************************************
    * Get the coverage in square feet per gallon. 
    ************************************************************/
    cout << "Coverage in square feet per gallon? ";
    cin >> rCoverage;

    rPaintCeiling = true;
    {
        cout << "Paint the ceiling? (y/n) ";
    }
    /**********************************************************
    * Get the input. 
    **********************************************************/
    string input;
    cin >> input;

    if (input.size() > 0 && tolower(input[0]) == 'n')
        rPaintCeiling = false;
}
/*************************************************************
* Display goodbye message.
**************************************************************/
void Goodbye(void)
{
    cout << "Goodbye!\n";
}
/***********************************************************
 * Ask if the user want to calculate more rooms.
 ***********************************************************/
void DoAgain(void)
{
    bool keepGoing;
    /**************************************************
    * Get the option from the user. 
    **************************************************/
    {
        cout << "Calculate more rooms? ";
    }
    /*************************************************
    * Get the input string. 
    **************************************************/
    string input;
    cin >> input;

    if (input.size() > 0 && tolower(input[0]) == 'n')
        keepGoing = false;
 
}