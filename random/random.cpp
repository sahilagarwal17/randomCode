#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
int count = 0;
srand( time(0));
while(count < 50){
    double r = (68.556*rand()/RAND_MAX - 32.768);
    cout << r << endl;
    count++;
}
    return 0;
}
