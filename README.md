# The Paint Estimator
## Begin by writing pseudocode for Program Five

Then write the calculations for this test case:
The room is 14 ft long, 12.8 in wide, and 8 ft high.  Paint the ceiling. Coverage is 2500 $ft^2$ /gallon.
_PercentNoPaint_ = 10.  Compare it to your program to see if it is running correctly.

## This will be a multi-file program
You just got a job at the **C++ Hardware Store** in the paint department.  Customers come in and ask you how much paint they will need to paint a room, walls, and ceiling.  You do not paint windows or doors.  You want to make use of your programming skills, so you write a program to calculate the gallons of paint needed.

In the main function, you will need to declare the variables needed.  After you write your course header function, _WriteHeader_, open a do-while or while loop.  Then you will call these functions:

1. _AskForNameAndShape_, in which you will ask for the customer's name and then ask him/her whether the room is rectangular or circular.  The function has a void return and is passed the customer’s name and shape (rectangular or circular) by reference.  Shape may be represented by an int, a string, or even a bool.   Your choice.  Comment to explain your choice.
2. _AskForPaintInfor_, in which you ask the user the number of coats to paint, the coverage of the paint chosen (in square feet per gallon), and whether to paint the ceiling (the user enters true /false or 1/2 or a string, your choice).  The functions also have a void return and are passed the number of coats, the paint coverage, and whether to paint the ceiling using references. If the shape is rectangular, call the rectangle-based AskForDimensions and HowManyGallons.If the shape is circular, call the circle-based overloaded functions. 
3. _AskForDimensions_, which asks the user for the appropriate dimensions and a description of the data:
   
	**Rectangular**: length, width,  height, and a description string like: "Your room is length feet by width feet and height feet high." You may want to use a _stringstream_ to build the string.

	**Circular**: radius, height, and a similarly constructed string description
These are two overloaded functions with this name, one for the rectangular room, one for the circular room.  These functions also ask the user to provide an estimate of wall space that consists of doors and windows. (in %).  Both functions have void returns and are passed the dimensions and percent of the walls not to paint, and a description using pointers. 

5. _HowManyGallons_, which passes the dimensions, the paint info, and the percent of walls not to be painted.  It returns an int, the number of full gallons to buy.  The function calculates the wall area to be painted, the ceiling area (if any), and, using the number of coats and the paint coverage, calculates the exact amount of paint, and then figures out how many whole gallons to buy.

## This function is also overloaded. 
There will be one function for the rectangular shape, and one for the circular room.  They will be passed the dimensions, the paint coverage, the number of coats, whether the ceiling will be painted, and the percentNoPaint.

## To Summarize the functions:

| **Return Type**  | **Function Name** | **Function Arguments** | **Function Description** |
| -----------------| ----------------- | -----------------------| -------------------------|
| __void__         | WriteHeader       | ()                     | Intro to the program     |
| __int__          | HowManyGallons    | (double length, double width, double height, int coverage, int coats, string ceiling, int percentNoPaint)| Calculations how many cans of paint needed for a rectangular room |
| __int__          | HowManyGallons    | (double radius, double height, in coverage, int coats, string ceiling, int percentNoPaint) | Calculates how many cans of paint needed for a circular room |
| __void__         | AskForNameAndShape | (string &rName, int rShape) | Gets info from customer |
| __void__         | AskForDimensions  | (double *pRadius, double *pHeight, int *pPercentNoPaint string *pDimens)| Gets dimensions of the circular room |
| __void__         | AskForDimensions  | (double *plength, double *pWidth, double *pHeight, int *pPercentNoPaint, string *pDimens| Gets dimensions for the rectangular room |
| __void__         | AskForPaintInfo   | (int&rCoats, int&rCoverage, string &rCeiling) | Gets info on the paint used |
| __void__         | Goodbye           | () | Say Goodbye |
| __void__         | DoAgain           | () | Ask if the user want to calculate more rooms|



# Core Features
  * Overloaded Functions
  * Pointers and References
# The Library Usage
  * Cmath
# Contributions
