#include<iostream>
int main(){
   
   int a = 0, b = 0, c = 0;
   int &rel = a = b = c;
   rel = 19;
   std::cout << a << b << c << std::endl;
}
