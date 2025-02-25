/***********************************************************************************
* Program: C++ Hardware Store in the paint department.  
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: 1 November 2021. 
* Purpose: Determine the amount of paint needed to paint a room.
************************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include "Functions.h"

using namespace std;

bool keepGoing = true;

int main()
{
	WriteHeader();

    while (keepGoing);
	{
        bool  isRectangular = true;
        string name;

        AskForNameAndShape(name, isRectangular);

            cout << "Name: " << name << ", Rectangular? ";

            if (isRectangular)
            {
                cout << "yes\n";
            }

            else
            {
               cout << "no\n";
            }
            
        int numberOfCoats = 0;
        int coverage = 0;
        bool paintCeiling = true;

        AskForPaintInfo(numberOfCoats, coverage, paintCeiling);

        cout << "NumberOfCoats: " << numberOfCoats << ", Coverage: " <<
            coverage << ", PaintCeiling? ";

        if (paintCeiling)
        {
            cout << "yes\n";
        }

        else
        {
            cout << "no\n";
        }

        string dimensions;
        int percentNoPaint = 0;
        int gallons = 0;

        if (isRectangular)
        {
            double length = 0.0;
            double width = 0.0;
            double height = 0.0;

            AskForDimensions(&length, &width, &height, &percentNoPaint, &dimensions);

            gallons = HowManyGallons(length, width, height, coverage,
                numberOfCoats, paintCeiling, percentNoPaint);
        }
        else
        {
            double radius = 0.0;
            double height = 0.0;

            AskForDimensions(&radius, &height, &percentNoPaint, &dimensions);

            gallons = HowManyGallons(radius, height, coverage,
                numberOfCoats, paintCeiling, percentNoPaint);
        }

        cout << dimensions << ", Gallons Needed: " << gallons << "\n";

        DoAgain(); 

	}

    Goodbye();
}


