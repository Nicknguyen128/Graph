// used to test function of fill
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
   int val = 0;
   int myarray[8] = {};
   fill(myarray,myarray+2,1);
   for(;val < 8;++val){
      cout << myarray[val];
      cout << endl;
   }
}
