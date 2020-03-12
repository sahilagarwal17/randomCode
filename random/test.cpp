#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;




double randomGenerator(double UpperBound, double LowerBound){
  // generates numbers as if the range was shifted to 0 
  double r = (abs(UpperBound - LowerBound)) * (double) rand()/RAND_MAX;
  if (LowerBound >= 0)
    r = r + LowerBound;
  else if(LowerBound < 0 && UpperBound > 0)
    r = r + LowerBound;
  else
    r = r + LowerBound;

  return r;
}

int main(){

srand(time(NULL));
int count = 0;
while(count < 100){

cout<< randomGenerator(3.00,-5.00)<< endl;

count++;
}
return 0;
}
