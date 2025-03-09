/*Q2. Implement the Cohen-Sutherland line-clipping algorithm

Algorithm:
Step 1: Start
Step 2: Start graphics mode using initgraph().
Step 3: Get xmin, ymin, xmax, ymax from the user.
Step 4: Ask for the number of lines and store their coordinates.
Step 5: Draw the clipping window and all lines before clipping.
Step 6: Sutherland Algorithm:
Step 7: Fully inside → Accept the line.
        Fully outside → Reject the line.
        Partially inside → Find intersection points and clip the line.
Step 8: Redraw the clipping window and show the clipped lines.
Step 9: Pause before closing graphics mode.
Step 10: End*/

#include<iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>

using namespace std;

// Region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;	  // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;	  // 1000

// Clipping Window Boundaries
int xmin, ymin, xmax, ymax;

// Function to find the region code of a point (x, y)
int computeCode(int x, int y)
{
	int code = INSIDE;

	if (x < xmin)
		code |= LEFT;
	if (x > xmax)
		code |= RIGHT;
	if (y < ymin)
		code |= BOTTOM;
	if (y > ymax)
		code |= TOP;
	return code;
}

// Cohen-Sutherland clipping algorithm
void cohenSutherClip(int x0, int y0, int x1, int y1)
{
	int code0 = computeCode(x0, y0);
	cout<<"code 0 is:"<<code0<<endl;
	int code1 = computeCode(x1, y1);
	cout<<"code 1 is:"<<code1<<endl;
	int accept = 0;

	while (1)
	{
		if ((code0 == 0) && (code1 == 0))
		{
			accept = 1;
			break;
		}
		else if (code0 & code1)
		{
			break;
		}
		else
		{
			int codeOut;
			int x, y;

			if (code0 != 0)
				codeOut = code0;
			else
				codeOut = code1;

			if (codeOut & TOP)
			{
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
				cout<<"Top Clipped"<<endl;
			}
			else if (codeOut & BOTTOM)
			{
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
				cout<<"Bottom Clipped"<<endl;
			}
			else if (codeOut & RIGHT)
			{
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
				cout<<"Right Clipped"<<endl;
			}
			else if (codeOut & LEFT)
			{
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
				cout<<"Left Clipped"<<endl;
			}

			if (codeOut == code0)
			{
				x0 = x;
				y0 = y;
				code0 = computeCode(x0, y0);
			}
			else
			{
				x1 = x;
				y1 = y;
				code1 = computeCode(x1, y1);
			}
		}
	}

	if (accept)
	{
		line(x0, y0, x1, y1);
	}
}

int mainLine()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	cout<<"Enter clipping window coordinates as xmin, ymin, xmax, ymax: "<<endl;
	cin>>xmin>>ymin>>xmax>>ymax;
	int number;
	cout<<"Enter the number of lines you want: "<<endl;
	cin>>number;
	int lines[number][4];
	for (int i = 0; i < number; i++)
	{
		cout<<"Enter coordinates of line (x0, y0, x1, y1): "<< i + 1<<endl;
		cin>>lines[i][0]>>lines[i][1]>>lines[i][2]>>lines[i][3];
	}

	// Draw the clipping window
	rectangle(xmin, ymin, xmax, ymax);

	// Draw lines before clipping
	for (int i = 0; i < number; i++)
	{
		line(lines[i][0], lines[i][1], lines[i][2], lines[i][3]);
	}
	cout<<"Before Line Clipping:" <<endl;
	getch();
	cleardevice();
	cout <<"After Line Clipping:"<<endl;
	// Draw the clipping window again
	rectangle(xmin, ymin, xmax, ymax);

	// Clip lines using Cohen-Sutherland algorithm and draw clipped lines
	for (int i = 0; i < number; i++)
	{
		cohenSutherClip(lines[i][0], lines[i][1], lines[i][2], lines[i][3]);
	}

	getch();
	closegraph();
	return 0;
}

