//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

/* Hassan Raza
   i210465
   Z
*/

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include <fstream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 

int score = 0;
bool flag1 = 1;


// car cordinates
int xI = 65, yI = 770;

int cx2 = 70, cy2 = 200;
int cx1 = 70, cy1 = 80;
int cx3 = 610, cy3 = 780;



// this counts how much rides have been done by taxi
int ridecount = 0;


// loc of first destination
int loc1x = 950;
int loc1y = 400;



	
int loc2x = 150;
int loc2y = 470;


int loc3x = 250;
int loc3y = 350;

 
// this flag tells whether passenger has been picked
bool locflag1 = 0;
// this flag tells whether passenger has been dropped
bool locflag11 = 0;

// this flag tells whether passenger has been picked
bool locflag2 = 0;
// this flag tells whether passenger has been dropped
bool locflag22 = 0;

// this flag tells whether passenger has been picked
bool locflag3 = 0;
// this flag tells whether passenger has been dropped
bool locflag33 = 0;

//this array is storing the cordinates of the buildings and obstacles in the format x1,x2,y1,y2
int array[17][4] = {  
   {100, 400, 500, 600} ,    // 1
   {600, 900, 500, 600} , 
   {100, 200, 100, 200} ,   
   {200, 300, 100, 300} , 
   {450, 550, 300, 400} ,    // 5
   {600, 700, 100, 200} , 
   {700, 800, 100, 300} , 
   {900, 950, 100, 300} , 
   {950, 1000, 200, 250} ,  
   {100, 200, 400, 450} ,    // 10
   {800, 900, 700, 750} , 
   {450, 550, 100, 150} , 
   {400, 450, 200, 250} , 
   {400, 550, 700, 750} , 
   {550, 600, 700, 800} ,    // 15
   {300, 350, 420, 490} , 
   {700, 750, 325, 400} ,   
   };
   
 
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

// red car, this functions get called if user selects red car in the menu
void drawCar() {
	DrawSquare(xI, yI, 20, colors[RED]);
	DrawCircle(xI+2, yI-2, 5, colors[BLACK]);
	DrawCircle(xI+18, yI-2, 5, colors[BLACK]);
	glutPostRedisplay();
}

void drawCar0() {
	DrawSquare(xI, yI, 20, colors[ORANGE]);
	DrawCircle(xI+2, yI-2, 5, colors[BLACK]);
	DrawCircle(xI+18, yI-2, 5, colors[BLACK]);
	glutPostRedisplay();
}



void drawCar1() {
	DrawSquare(cx1, cy1, 20, colors[LIME]);
	DrawCircle(cx1+2, cy1-2, 5, colors[BLACK]);
	DrawCircle(cx1+18, cy1-2, 5, colors[BLACK]);
	glutPostRedisplay();
}


void drawCar2() {
	DrawSquare(cx2, cy2, 20, colors[TEAL]);
	DrawCircle(cx2+2, cy2-2, 5, colors[BLACK]);
	DrawCircle(cx2+18, cy2-2, 5, colors[BLACK]);
	glutPostRedisplay();
}

//this is the third car and gets on the screen only when 2 passenger rides have been completed
void drawCar3() {
	DrawSquare(cx3, cy3, 20, colors[BLUE]);
	DrawCircle(cx3+2, cy3-2, 5, colors[BLACK]);
	DrawCircle(cx3+18, cy3-2, 5, colors[BLACK]);
	glutPostRedisplay();
}

// function for drawing grid now
void drawHlines(){
	// drawing horizontal lines
	int count = 50;
	for (int i=0;i<=20;i++){
		DrawLine( 50 , count ,  1050 , count , 1 , colors[BLACK] );	
		count = count + 50;
	}
	
}

void drawVlines(){
	// drawing verical lines
	int count = 50;
	for (int i=0;i<=20;i++){
		DrawLine( count , 50 ,  count , 800 , 1 , colors[BLACK] );	
		count = count + 50;
	}
}

void drawtree(){
	DrawTriangle( 300, 450 , 350, 450 , 325 , 490, colors[LIME] ); 
	DrawLine( 325 , 450 ,  325 , 420 , 5 , colors[BROWN] );	
}


void drawtree1(){
	DrawTriangle( 700, 350 , 750, 350 , 725 , 400, colors[LIME] ); 
	DrawLine( 725 , 350 ,  725 , 325 , 10 , colors[BROWN] );	
}
	
	
	
	
	
	

int px1 = 370, py1 = 100;

void passenger1(){
	
	DrawCircle(px1, py1, 5, colors[BLACK]);
	DrawLine( px1 , py1-4 ,  px1 , py1-30 , 2 , colors[BLACK] );
	DrawLine( px1 , py1-10 ,  px1-10 , py1-20 , 2 , colors[BLACK] );
	DrawLine( px1 , py1-10 ,  px1+10 , py1-20 , 2 , colors[BLACK] );
	DrawLine( px1 , py1-30 ,  px1-10 , py1-40 , 2 , colors[BLACK] );
	DrawLine( px1 , py1-30 ,  px1+10 , py1-40 , 2 , colors[BLACK] );
	glutPostRedisplay();
}

int px2 = 450, py2 = 600;

void passenger2(){
	
	DrawCircle(px2, py2, 5, colors[BLACK]);
	DrawLine( px2 , py2-4 ,  px2 , py1-30 , 2 , colors[BLACK] );
	DrawLine( px2 , py2-10 ,  px2-10 , py2-20 , 2 , colors[BLACK] );
	DrawLine( px2 , py2-10 ,  px2+10 , py2-20 , 2 , colors[BLACK] );
	DrawLine( px2 , py2-30 ,  px2-10 , py2-40 , 2 , colors[BLACK] );
	DrawLine( px2 , py2-30 ,  px2+10 , py2-40 , 2 , colors[BLACK] );
	glutPostRedisplay();
}

int px3 = 850, py3 = 150;

void passenger3(){
	
	DrawCircle(px3, py3, 5, colors[BLACK]);
	DrawLine( px3 , py3-4 ,  px3 , py1-30 , 2 , colors[BLACK] );
	DrawLine( px3 , py3-10 ,  px3-10 , py3-20 , 2 , colors[BLACK] );
	DrawLine( px3 , py3-10 ,  px3+10 , py3-20 , 2 , colors[BLACK] );
	DrawLine( px3 , py3-30 ,  px3-10 , py3-40 , 2 , colors[BLACK] );
	DrawLine( px3 , py3-30 ,  px3+10 , py3-40 , 2 , colors[BLACK] );
	glutPostRedisplay();
}





// these are flags for car2
bool flag = true;
bool cflag1 = false;
bool cflag2 = false;
bool cflag3 = false;

// flag for car1
bool cflag4 = true;

//flag for car 3
bool cflag5 = true;

void moveCar() {

	
	// 1st car
	if (cx1 > 10 && cflag4) {
		
		if (ridecount >= 3) {
			cx1 -= 20;
			if(cx1 < 50){
				cflag4 = false;
			}
		}
		else{
		cx1 -= 10;
		if(cx1 < 50){
			cflag4 = false;
		}
		}
		
	}
	else if (cx1 < 350 && !cflag4) {
		if (ridecount >= 3) {
			cx1 += 20;
			if (cx1 > 320){
				cflag4 = true;
			}	
		}
		else{
		cx1 += 10;
		if (cx1 > 320){
			cflag4 = true;
		}	
		}
	}
	
	// for car 3 which should only get activated if 2 rides completed
	
	if (ridecount >= 3) {
	if (cx3 > 609 && cflag5) {
		cx3 -= 10;
		if(cx3 < 650){
			cflag5 = false;
		}
	}
	else if (cx3 < 1020 && !cflag5) {
		cx3 += 10;
		if (cx3 > 1000){
			cflag5 = true;
		}	
	}
	}
	
	
	// for the second car
	if (flag){
	if (cy2 >= 620){
		flag = false;
		cflag1 = true;
	}
	else{
		if (ridecount >= 3) {
			cy2 += 25;
		}
		else{
		cy2 += 10;
		}
	}
	}
			
	
	if (cflag1){
		cx2 += 10;
		if (cx2 > 400){
			cflag2 = true;
			cflag1 = false;
		}
		else{
			if (ridecount >= 3) {
				cx2 += 25;
			}
			else{
			cx2 += 10;
			}
		}
	}
	if (cflag2){
		cy2 -= 10;
		if ( cy2 < 345){
			cflag3 = true;
			cflag2 = false;
		}
		else{
			if (ridecount >= 3) {
				cy2 -= 25;
			}
			else{
			cy2 -= 10;
			}
		}
	}
	if (cflag3){
		cx2 -= 10;
		if (cx2 <= 70){
			flag = true;
			cflag3 = false;
		}
		else{
			if (ridecount >= 3) {
				cx2 -= 25;
			}
			else{
			cx2 -= 10;
			}
		}
	}
	
		
}


/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.5f/*Red Component*/, 0.8f,	//148.0/255/*Green Component*/,
			1.0f/*Blue Component*/, 0.0f /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	
	// left square (1)
	{
	int count = 100;
	for (int i=0;i<3;i++){
		DrawSquare(count, 500, 101, colors[BLACK]);
		count += 100;
	}
	}
	
	// right square (2)
	{
	int count = 600;
	for (int i=0;i<3;i++){
		DrawSquare(count, 500, 101, colors[BLACK]);
		count += 100;
	}
	}
	
	// curved path left side (3) and (4)
	DrawRectangle(100,100,101,100, colors[BLACK]);
	DrawRectangle(200,100,101,200, colors[BLACK]);
	
	//middle rectangle (5)
	DrawRectangle(450,300,101,101, colors[BLACK]);
	
	// curved path right side (6 and 7)
	DrawRectangle(600,100,101,100, colors[BLACK]);
	DrawRectangle(700,100,101,200, colors[BLACK]);
	
	// 8 and 9
	DrawRectangle(900,100,51,200, colors[BLACK]);
	DrawRectangle(950,200,51,50, colors[BLACK]);
	
	
	
	//Green Square
	DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	//Display Strings on screen
	DrawString( 834, 10, "Score=0", colors[BLACK]);
	DrawString( 4, 10, "HR Presents", colors[BLACK]);
	DrawString( 424, 10, "RUSH HOUR", colors[BLACK]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	// draw tree	
	drawtree();
	drawtree1();
		
	
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );
	
	drawHlines();
	drawVlines();
			
	
	// x axis of grid goes from 50 to 1050 and y axis of grid goes from 50 to 800
		
	
	//10
	//DrawRoundRect(500,700,50,50,colors[BLACK],70);
	
	DrawRectangle(400,700,151,50, colors[BLACK]);
	DrawRectangle(550,700,51,100, colors[BLACK]);
	
	//11
	//DrawRectangle(100,400,101,50, colors[INDIGO]);
	DrawRoundRect(100,400,100,50,colors[INDIGO],20);
	DrawString( 115, 420, "MASJID", colors[BLACK]);	
	
	//DrawRoundRect(0,100,50,100,colors[DARK_OLIVE_GREEN],30);
	//12
	DrawRoundRect(800,700,100,50,colors[BLUE],40);
	DrawString( 825, 718, "Hotel", colors[BLACK]);
	
	//13
	DrawRoundRect(450,100,100,50,colors[ORANGE],20);
	DrawString( 465, 120, "PARK", colors[BLACK]);
	
	//14
	DrawSquare(400, 200, 51, colors[BLACK]);
	
	drawCar();
	drawCar1();
	drawCar2();
	
	
	if (ridecount >= 3) {
		drawCar3();
	}
	
	
	passenger1();
	passenger2();
	passenger3();
	
	// for 1st passenger
	if (locflag1 == 1){
		DrawCircle(loc1x,loc1y,10,colors[GREEN]);
	}
	
	
	// for 2nd passenger
	if (locflag2 == 1){
		DrawCircle(loc2x,loc2y,10,colors[GREEN]);
	}
	
	
	
	//for 3rd passenger
	if (locflag3 == 1){
		DrawCircle(loc3x,loc3y,10,colors[GREEN]);
	}
	
		
	glutSwapBuffers(); // do not modify this line..

}

// a different display if user selects different colour of taxi
void GameDisplay1()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.8f/*Red Component*/, 0.5f,	//148.0/255/*Green Component*/,
			0.5f/*Blue Component*/, 0.0f /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	
	// left square (1)
	{
	int count = 100;
	for (int i=0;i<3;i++){
		DrawSquare(count, 500, 101, colors[BLACK]);
		count += 100;
	}
	}
	
	// right square (2)
	{
	int count = 600;
	for (int i=0;i<3;i++){
		DrawSquare(count, 500, 101, colors[BLACK]);
		count += 100;
	}
	}
	
	// curved path left side (3) and (4)
	DrawRectangle(100,100,101,100, colors[BLACK]);
	DrawRectangle(200,100,101,200, colors[BLACK]);
	
	//middle rectangle (5)
	DrawRectangle(450,300,101,101, colors[BLACK]);
	
	// curved path right side (6 and 7)
	DrawRectangle(600,100,101,100, colors[BLACK]);
	DrawRectangle(700,100,101,200, colors[BLACK]);
	
	// 8 and 9
	DrawRectangle(900,100,51,200, colors[BLACK]);
	DrawRectangle(950,200,51,50, colors[BLACK]);
	
	
	
	//Green Square
	DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	//Display Strings on screen
	DrawString( 834, 10, "Score=0", colors[BLACK]);
	DrawString( 4, 10, "HR Presents", colors[BLACK]);
	DrawString( 424, 10, "RUSH HOUR", colors[BLACK]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	// draw tree	
	drawtree();
	drawtree1();
		
	
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );
	
	drawHlines();
	drawVlines();
			
	
	// x axis of grid goes from 50 to 1050 and y axis of grid goes from 50 to 800
		
	
	//10
	//DrawRoundRect(500,700,50,50,colors[BLACK],70);
	
	DrawRectangle(400,700,151,50, colors[BLACK]);
	DrawRectangle(550,700,51,100, colors[BLACK]);
	
	//11
	//DrawRectangle(100,400,101,50, colors[INDIGO]);
	DrawRoundRect(100,400,100,50,colors[INDIGO],20);
	DrawString( 115, 420, "MASJID", colors[BLACK]);	
	
	//DrawRoundRect(0,100,50,100,colors[DARK_OLIVE_GREEN],30);
	//12
	DrawRoundRect(800,700,100,50,colors[BLUE],40);
	DrawString( 825, 718, "Hotel", colors[BLACK]);
	
	//13
	DrawRoundRect(450,100,100,50,colors[LIME_GREEN],20);
	DrawString( 465, 120, "PARK", colors[BLACK]);
	
	//14
	DrawSquare(400, 200, 51, colors[BLACK]);
	
	drawCar0();
	drawCar1();
	drawCar2();
	
	
	if (ridecount >= 3) {
		drawCar3();
	}
	
	
	passenger1();
	passenger2();
	passenger3();
	
	// for 1st passenger
	if (locflag1 == 1){
		DrawCircle(loc1x,loc1y,10,colors[GREEN]);
	}
	
	
	// for 2nd passenger
	if (locflag2 == 1){
		DrawCircle(loc2x,loc2y,10,colors[GREEN]);
	}
	
	
	
	//for 3rd passenger
	if (locflag3 == 1){
		DrawCircle(loc3x,loc3y,10,colors[GREEN]);
	}
		
	glutSwapBuffers(); // do not modify this line..

}

//displaying menu function
void Menu()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.5f/*Red Component*/, 1.0f,	//148.0/255/*Green Component*/,
			0.5f/*Blue Component*/, 0.0f /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	DrawString( 400, 750, "WELCOME TO THE GAME", colors[BLACK]);
	DrawString( 450, 720, "RUSH HOUR", colors[BLACK]);
	DrawString( 400, 600, "MADE BY 21i-0465 - Z", colors[BLACK]);
	DrawString( 400, 550, "HASSAN RAZA", colors[BLACK]);
	
	DrawString( 115, 70, "PRESS H TO VIEW  THE GAME HIGHSCORES", colors[BLACK]);
	DrawString( 115, 220, "PRESS R/r TO PLAY THE GAME WITH RED TAXI", colors[BLACK]);
	DrawString( 115, 370, "PRESS Y/y TO PLAY THE GAME WITH YELLOW TAXI", colors[BLACK]);
	
	int x1 = 800 ;
	int y1 = 150;
	int x2 = 800;
	int y2 = 370;

	DrawSquare(x1, y1, 100, colors[RED]);
	DrawCircle(x1+10, y1-10, 25, colors[BLACK]);
	DrawCircle(x1+90, y1-10, 25, colors[BLACK]);


	DrawSquare(x1, y2, 100, colors[ORANGE]);
	DrawCircle(x1+10, y2-10, 25, colors[BLACK]);
	DrawCircle(x1+90, y2-10, 25, colors[BLACK]);
	
	glutSwapBuffers(); // do not modify this line..

}




/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;
		
	// do not let it go out of grid
	if (xI <= 50 && xI <= 1030 && yI >= 50 && yI <= 800){
		xI += 10;
	}
	
	// this loop checks for buildings and obstacles, these 2 block of codes are reused for other button function as well
	for (int i=0;i<17;i++){
   	int j = 0;
   	if (xI >=array[i][j] && xI <= array[i][j+1] && yI >= array[i][j+2] && yI <= array[i][j+3]){
   		xI += 10;
   	} 
	}
	

	} else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	
	if (xI >= 50 && xI >= 1030 && yI >= 50 && yI <= 800){
		xI -= 10;
	}	
	
	for (int i=0;i<17;i++){
   	int j = 0;
   	if (xI >=array[i][j] && xI <= array[i][j+1] && yI >= array[i][j+2] && yI <= array[i][j+3]){
   		xI -= 10;
   	} 
	}	
		
	
	} else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	
	
		
	if (xI >= 50 && xI <= 1030 && yI >= 50 && yI >= 800){
		yI -= 10;
	}			
	
	for (int i=0;i<17;i++){
   	int j = 0;
   	if (xI >=array[i][j] && xI <= array[i][j+1] && yI >= array[i][j+2] && yI <= array[i][j+3]){
   		yI -= 10;
   	} 
	}
	
	
	
	
	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	
	if (xI >= 50 && xI <= 1030 && yI <= 50 && yI <= 800){
		yI += 10;
	}	
	
	for (int i=0;i<17;i++){
   	int j = 0;
   	if (xI >=array[i][j] && xI <= array[i][j+1] && yI >= array[i][j+2] && yI <= array[i][j+3]){
   		yI += 10;
   	} 
	}
	
	}
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}



/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		fstream file_out;
   	 	file_out.open("highscores.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    		file_out << "\n" << score;
    		file_out.close();
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'S' || key == 's') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "SCORE IS" << score << endl;
	}
	
	if (key == 'r' || key == 'R' /* pressing r*/) {
		glutDisplayFunc(GameDisplay);
	}
	
	if (key == 'y' || key == 'Y' /* pressing y*/) {
		glutDisplayFunc(GameDisplay1);
	}
	
	// for 1st passenger
	if (key==32 && ( ((xI == px1) && (xI == px1)) || (( (yI == py1) && (yI == py1))))) {
		px1 = -100;
		py1 = 2000;
		locflag1 = 1;
	}
	if (key==32 && (xI == loc1x || yI == loc1y)){
		locflag11 = 1;
	}
	
	if (locflag11 == 1){
		px1 = loc1x;
		py1 = loc1y;
		locflag1 = 0;
		ridecount = ridecount + 1;
		score += 5;
		cout << score;
	}
	
	// for 2nd passenger
	if (key==32 && ( ((xI == px2) && (xI == px2)) || (( (yI == py2) && (yI == py2))))) {
		px2 = -100;
		py2 = 2000;
		locflag2 = 1;
	}
	if (key==32 && (xI == loc2x || yI == loc2y)){
		locflag22 = 1;
	}
	
	if (locflag22 == 1){
		px2 = loc2x;
		py2 = loc2y;
		locflag2 = 0;
		ridecount = ridecount + 1;
		score += 5;
		cout << score;
	}
	
	// for 3rd passenger
	if (key==32 && ( ((xI == px3) && (xI == px3)) || (( (yI == py3) && (yI == py3))))) {
		px3 = -100;
		py3 = 2000;
		locflag3 = 1;
	}
	if (key==32 && (xI == loc3x || yI == loc3y)){
		locflag33 = 1;
	}
	
	if (locflag33 == 1){
		px3 = loc3x;
		py3 = loc3y;
		locflag3 = 0;
		ridecount = ridecount + 1;
		score += 5;
		cout << score;
	}
	
	
	
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	moveCar(); 

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	int width = 1110, height = 840; // i have set my window size to be 800 x 600
	
	char choice;
	int temp;
	int scores[10];
	int count = 0;
	int lowestScore = -9999;
	
	
	cout << "Hello welcome to the game, if you want to view the leaderboards, press Y only: ";
	cin >> choice;
	
	if (choice=='Y'){
		ifstream in_file;
		in_file.open("highscores.txt");
		while (! in_file.eof()){
			in_file >> temp;
			scores[count] = temp;
			
			// now checking for lowest score at the same time so we can update it in future if our score is greater than it
			if (scores[count] < lowestScore){
				lowestScore = scores[count];
			}
			count++;
		}
		for (int i=0;i<count;i++){
			if (i > 10){
				break;
			}
			cout << i+1 << ": " <<  scores[i] << endl;
		}
		in_file.close();
		
	}
		
	
	

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Hassan Raza"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutDisplayFunc(Menu); 
	

	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	
	
	glutTimerFunc(1000.0, Timer, 0);
	
	
	
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	
	

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	
	
	return 1;
}
#endif /* RushHour_CPP_ */
