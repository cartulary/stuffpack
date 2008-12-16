//Includes
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "math.h"
#include "string.h"

//prototypes of functions
void displayShape(void);
void fill (int col, int row);
bool stringNull(string str);
string copyAndReplace(string str, int col, char replaceWith);

//Create global vars
string lines[31]; //30 spots
int intRow, intCol;
int maxRow, maxCol;

int main (void)
{
	int cols=0, rows=0;
	string line;
	bool cont=true;
	do
	{
		rows+=1;
		printf("%d:", rows);
		line=GetLine();
		lines[rows]=line;
		if (StringLength(line)>cols){cols=StringLength(line);}
		if (StringLength(line)==0){cont=false;} //exit for loop
		if (rows>=29){cont=false;}
	} while (cont);
	maxRow = rows;
	maxCol = cols;

	//assuming shape is closed and that point is inside shape.
	printf("The cols = %d \n", cols);
	printf("What row is the interior point in?");
	intRow=GetInteger();
	printf("What col is the interior point in?");
	intCol=GetInteger();
	
	//show the unfilled shape
	displayShape();

	fill(intRow,intCol);

	//show the filled shape
	displayShape();

}

inline void displayShape(void)
{
	int rows=0;
	string line;
	bool cont=true;
	//print the basic shape
	do
	{
		rows++;
		line=lines[rows];
		printf("%s\n",line);

		if (StringLength(line)==0)  {cont=false;}
		if (rows>=29){cont=false;}
		printf("\a");
	} while (cont);
}


void fill (int row, int col)
{
	/*
		If row, col is filled, go away
		if not fill it and then do it's neighbors also
	*/

	string line =lines[row];
	if (!stringNull(line))
	{
		char dealWith = IthChar(line,col-1);
		if (dealWith==' ')
		{
			lines[row]=copyAndReplace(line, col-1, '*');
			if (row>=2) {fill(row-1, col);}
			if (row<=maxRow-1) {fill(row+1, col);}
			if (col>=2) {fill(row, col-1);}
			if (col<=maxCol-1) {fill(row, col+1);}
		}
		else
		{
			printf(""); //do nothing
		}
	}
	else
	{
		printf(""); //do nothing
	}
}

//return true is string is null (testing as 0)
inline bool stringNull(string str)
{
	return (str==0);
}

string copyAndReplace(string str, int col, char replaceWith)
{
	string newstr="";
	char workWith;
	for (int counter=0;counter<=StringLength(str)-1;counter++)
	{
		workWith = IthChar(str,counter);
		if (counter == col) {workWith = replaceWith;}
		newstr = Concat(newstr, CharToString(workWith));
	}
	return newstr;
}
