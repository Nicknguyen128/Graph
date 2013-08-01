#include<iostream>
#include<fstream>
using namespace std;

int main(){
   
   ofstream sonfile;
   sonfile.open("Tien.txt");
   sonfile << "Tam biet";
   sonfile.close();
}
