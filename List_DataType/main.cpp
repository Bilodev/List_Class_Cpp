#include <iostream>
#include "List.cpp"
using namespace std;
int main(){
    int size = 5;
    List<int>a(size);
    a.init({1,2,3,4,5});
    a.kill("List 'A' destroyed");



    List<int>arr1({1,2,3,4,5,6,7});

    arr1.pop();         //1,2,3,4,5,6           //length = 6 
    arr1.push(7);       //1,2,3,4,5,6,7         //length = 7

    arr1.add(5);        //5,1,2,3,4,5,6,7       //length = 8
    arr1.shift();       //1,2,3,4,5,6,7         //length = 7


    arr1.in(1,10);      //1,10,3,4,5,6,7        //length = 7 
    arr1.insert(1,12);  //1,12,2,3,4,5,6,7                      //length = 8

    arr1.expand(3);     //1,2,3,4,5,6,7,garbage //length = 7+3    

    cout << "First Position: " <<arr1.at(0) << endl;   //10 


    cout << "Length: " << arr1.length() << endl;
    arr1.display();  
    arr1.kill("List Destroyed");
    

    



}