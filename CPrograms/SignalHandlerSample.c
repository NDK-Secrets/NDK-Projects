#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signal) {

      printf("Signal %d has been caught by Instabug\n",signal);
}

int main() {
 signal(15,signalHandler);
 int i=0;
 
 while(1) {
   printf("i=  %d \n",i++);
   sleep(1);
 }

 return 0;
}
