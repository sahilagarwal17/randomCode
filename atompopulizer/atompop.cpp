#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


// function to generate random numbers

double randomGenerator(double UpperBound, double LowerBound){
  // generates numbers as if the range was shifted to 0
  double r = (abs(UpperBound - LowerBound)) * (double) rand()/RAND_MAX;
    r = r + LowerBound;
  return r;
}

// main function

int main(){
  int atomID;
  int molID;
  int atomType;
  double charge;
  double xCor;
  double yCor;
  double zCor;

  ifstream infile("data.txt");

  infile >> atomID >> molID >> atomType >> charge >> xCor >> yCor >> zCor;

  double particleXMax = xCor;
  double particleYMax = yCor;
  double particleZMax = zCor;
  double particleXMin = xCor;
  double particleYMin = yCor;
  double particleZMin = zCor;

  do {
    if(xCor > particleXMax)
      particleXMax = xCor;
    if(yCor > particleYMax)
      particleYMax = yCor;
    if(zCor > particleZMax)
      particleZMax = zCor;
    if(xCor < particleXMin)
      particleXMin = xCor;
    if(yCor < particleYMin)
      particleYMin = yCor;
    if(zCor < particleZMin)
      particleZMin = zCor;
  }
  while(infile >> atomID >> molID >> atomType >> charge >> xCor >> yCor >> zCor);

  cout << "The particle is contained in the Box with the following coordinates:" <<endl;
  cout << "X max = " << particleXMax << endl;
  cout << "Y max = " << particleYMax << endl;
  cout << "Z max = " << particleZMax << endl;
  cout << "X min = " << particleXMin << endl;
  cout << "Y min = " << particleYMin << endl;
  cout << "Z min = " << particleZMin << endl;


  //simulation box dimensions
  double addedSize;

  cout << "How much bigger than the particle would you like the simbox to be in Angstroms?";
  cin >> addedSize;

  double simXMax = particleXMax + addedSize;
  double simYMax = particleYMax + addedSize;
  double simZMax = particleZMax + addedSize;
  double simXMin = particleXMin - addedSize;
  double simYMin = particleYMin - addedSize;
  double simZMin = particleZMin - addedSize;

  // find the volume of the SimBox - particleBox

  double simBoxVolume = (abs(simXMax - simXMin)) * (abs(simYMax - simYMin)) * (abs(simZMax - simZMin));
  double particleBoxVolume = (abs(particleXMax - particleXMin)) * (abs(particleYMax - particleYMin)) * (abs(particleZMax - particleZMin));

  double fillVolume = simBoxVolume - particleBoxVolume;

  double density = 55.5; // in mol/l;

  // assuming that fillVolume is in A^3, what is fill volume in l;

  fillVolume = fillVolume/(pow(10,27));
  int numMolecules = (density * fillVolume) * (6.0221409 * pow(10,23)); // avagadro's constant

  // need to generate numMolecules in range from simbox parameter's to particle parameters

  double outMolecules[numMolecules][3];

  // generate random molecules coordinates in the simulation box;

  srand(time(NULL)); // seed the random
  int molCount = 0;
  double molXCor;
  double molYCor;
  double molZCor;
  while(molCount < numMolecules){
  // this code needs to be cleaned up to work
    // creating Xcoordinate
    /* do{
     molXCor = randomGenerator(simXMax,simXMin);
   } while(molXCor > particleXMin && molXCor < particleXMax);

   outMolecules[molCount][0] = molXCor;

    do{
     molYCor = randomGenerator(simYMax,simYMin);
   } while(molYCor > particleYMin && molYCor < particleYMax);

   outMolecules[molCount][1] = molYCor;

    do{
     molZCor = randomGenerator(simZMax,simZMin);
   } while(molZCor > particleZMin && molZCor < particleZMax);

   outMolecules[molCount][2] = molZCor;
   */

   molXCor = randomGenerator(simXMax,simXMin);
   molYCor = randomGenerator(simYMax,simYMin);
   molZCor = randomGenerator(simZMax,simZMin);

   //highly ineffiecient because the code doesnt check if each coordinate works, instead if the whole triplet doesnt work they are all changed

   if((molXCor > particleXMax) || (molXCor < particleXMin) || (molYCor > particleYMax) || (molYCor < particleYMin) || (molZCor > particleZMax) || (molZCor < particleZMin)){
     outMolecules[molCount][0] = molXCor;
     outMolecules[molCount][1] = molYCor;
     outMolecules[molCount][2] = molZCor;
     molCount++;
   }
  }

  for (int i = numMolecules - 1; i >= 0; i--){
    cout << "mol" << i << " = new SPCE.move(";
      for(int j = 0; j <= 2; j++){
        cout << outMolecules[i][j];
        if (j != 2)
          cout << " , ";
      }
      cout << " )" << endl;
  }


return 0;

}
