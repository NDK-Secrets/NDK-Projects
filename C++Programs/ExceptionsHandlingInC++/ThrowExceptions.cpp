#include <iostream>
using namespace std;
int getSum(int n1,int n2) {
   return n1+n2;
}

int main() {

int sum = getSum(5,6);
try{

//cout<<"sum = "<<sum/0<<endl;
  throw 56;
}
catch(int n){
cout<<"Error Integer has been throwen = "<<n<<endl;
}
catch(...){
cout<<"Error has been occured division by zero"<<endl; 
}
//excpected result should be 11
return 0;
}


