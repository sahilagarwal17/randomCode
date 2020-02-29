#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int main(){
  int atomID;
  int molID;
  int atomType;
  double charge;
  double xcor;
  double ycor;
  double zcor;



  // read coordinate data from system.data file
  ifstream infile("fileNameHere.txt");

  // the coordinates of the simulation box, must be bigger than the particle;
  double xMax;
  double yMax;
  double yMax;
  double xMin;
  double yMin;
  double zMin;



  //creating coordinates for a rough box around the particle itself
  double tempx = xMin; // values to compare differences
  double tempy = yMin;
  double tempz = zMin;
  double tempxMin = xMax;
  double tempyMin = yMax;
  double tempzMin = zMax;

// gets the dimensions of the inner box
  while(infile >> atomID >> molID >> atomType >> charge >> xcor >> ycor >> zcor){
    if (abs(xMax - xcor) < abs(xMax - tempx))
      tempx = xcor;
    if (abs(yMax - ycor) < abs(yMax - tempy))
      tempy = ycor;
    if (abs(zMax - zcor) < abs(zMax - tempz))
      tempx = xcor;
    if (abs(xMin - xcor) < abs(xMin - tempxMin))
      tempxMin = xcor;
    if (abs(yMin - ycor) < abs(yMin - tempyMin))
      tempyMin = ycor;
    if (abs(zMin - zcor) < abs(zMin - tempzMin))
      tempzMin = zcor;
  }

  double innerMin








}
