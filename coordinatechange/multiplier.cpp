#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <string>

int main(){
  string elem;
  int count= 1;
  double a,b,c;
  string temp = "NULL";
  ifstream infile("coordinates2.txt");
  while(infile >> elem >> a >> b >> c){
      a = a * 5.18;
      b = b* 8.98;
      c = c * 15.00;
      if (temp == elem){
        cout <<"$atom:" << elem << count  << " $mol:... " << "@atom:" << elem << " 0.0 ";
        count += 1;
      }
      else {
	cout << "$atom:" << elem << " $mol:... " << "@atom:" << elem << " 0.0 ";
	count = 1;
      }
      cout << fixed << setprecision(4) << a << " " << b << " " << c << endl;
      temp = elem;
    }

    return 0;
}
