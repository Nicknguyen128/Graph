// Try tie function
// Tie function used to unpack tuple and assign as variables

#include<iostream>
#include<fstream>
#include<tuple>
#include<string>
using namespace std;
int main(){

   int myint = 0;
   string mychar = "aaaa";
   std::tuple<int,int,string> mytuple;
   mytuple = make_tuple(3,4,"456");
   mytuple = tie(myint,ignore,mychar):
   cout << myint << " " << mychar;
   cout << endl; 
   
}
