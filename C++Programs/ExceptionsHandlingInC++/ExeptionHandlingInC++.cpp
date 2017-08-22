#include <iostream>
using namespace std;
int getSum(int n1,int n2) {
   return n1+n2;
}

int main() {

int sum = getSum(5,6);
cout<<"sum = "<<sum<<endl;
//excpected result should be 11
return 0;
}
