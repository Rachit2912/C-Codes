// OOPS

#include <cstring>
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Hero{

    // properties
    public:
    int health;
    char level;
    char* name;
    static int timetocomplete;


    int gethealth(){
        return health;
    }

    char getlevel(){
        return level;
    }

    void sethealth(int h){
        health = h;
    }

    void setlevel(char ch){
        level = ch;
    }

    void setname(char name[]){
        strcpy(this->name, name);
    }

    Hero(){
        cout<<"default constructor called"<<endl;
        name = new char[100];
    }

    static void random(){
        cout<<"static fn. h ye to "<<endl;
        cout<<"accesing static members only "<<timetocomplete<<endl;
    }

     //copy constructor
     // used for deep copy 
    // Hero(Hero& temp) {

    //     char *ch = new char[strlen(temp.name) + 1];
    //     strcpy(ch, temp.name);
    //     this->name = ch;

    //     cout << "apna constructor called" << endl;
    //     this->health = temp.health;
    //     this->level = temp.level;
    // }

    Hero(int health){
    this->health = health;
}
    


};

int Hero::timetocomplete = 5;
 
class Emptyclass{
//no properties
};

int main() {

// object is an instance of class

//creation of object OR object instantiate
Hero hero1;

cout<<"size of Hero object h1 is : "<<sizeof(hero1)<<endl;  // size is in bytes, not characters.

// agar class empty h means koi bhi attributes nhi h usme to bhi agar uska object bnayenge to usko 1 byte ki memory allocate hogi naa ki 0 bytes
Emptyclass e;
cout<<"size of empty class is : "<< sizeof(e) << endl;   

// we can also add a class as a file with name #inlcude "filename.cpp" & uss file me class ki proper declaration honi chahhiye alongwith its properties


// how to access its properties
Hero ramesh;
cout<<" health of hero ramesh is:  "<<ramesh.health<<endl;   //accessing property through dot operator
cout<<"level of hero ramesh is : "<<ramesh.level<<endl;
// it'll give an error bcz both data members are private by default

/*
access modifiers: private (default), public and protected
public: anywhere accessible
private: accessible only inside class 
protected:

getter & setter fns. are used to get & set private data members
*/

// padding and greedy alignment to determine the size of a class

// DMA syntax in cpp : int* i = new int;
//  same for the DMA for class : Hero* h = new Hero;
// accessing it properties : (*h).level  OR h->level ;

/*
- when u create an object, foremost its constructor is called
- its a fn. with no return type
- default bhi hota h with no input param.
- statically & dynamically 2 me same constructor hi call hota h 
- after making a new constructor, default will be deleted
*/

// parameterised constructor : 
// this is a pointer used to access the current object address 
// Hero(int health){
//     this->health = health;
// }
// object instantiation with the parameterised constructor :
// statically
Hero suresh(10);
// dynamically
Hero* jignesh = new Hero(10);


/* copy constructor:
poore object ko copy karna h
Hero ritesh(suresh); OR Hero ritesh = suresh;   :   it'll make ritesh same as suresh
- yeh pehle se default hota hi h but agr hm chahe to khud ka bna bhi skte h 
Hero(Hero& t){
    this->health = t.health;
    this->level = t.level;
}
- isme abhi pass by value ho rha h to firse copy constructor hoga or ese hi loop chlta rhega 
- ilsiye we'll use by reference 
- after making ur own, default will be deleted automaticallly
*/

/*
Deep and shallow copy:
- default copy constructor shallow copy krta h 
*/


// making an object 
Hero h1;
h1.sethealth(12);
h1.setlevel('D');
char name[7] = "babbar";
h1.setname(name);
cout<<" h1 "<<h1.name << h1.health << h1.level << endl;

//use default copy constructor 
Hero h2 = h1;
cout<<" h2 "<< h2.name << h2.health << h2.level << endl;

// now making changes to h1 
h1.name[0] = 'g';
cout<<" h1 "<< h1.name << h1.health << h1.level << endl;

// and tracking h2 also 
cout<<" h2 "<< h2.name << h2.health << h2.level << endl;

/* changes are there in h2 also but how ?
- bcz default copy constructor shallow copy krta h 
jese 'name' data member jo h vo 1 pointer h to vo address hi h to shallow copy krte waqt whi address copy ho jayega & jo bhi changes honge vo uss address pr hi honge so we r accessing same memory with 2 different names 
- but deep copy me uss copy ki bhi 1 copy bn jayegi 
- shallow copy k liye nya constructor bna denge

*/

/*
copy assignment operator : 
obj 1 = obj 2  : obj1 will become like obj 2
*/

/*
destructor:
- memory ko deallocate / free krne k lye 
- ~Hero() : defined as the same for the class name 
- no return type
- default se hi hota h alrdy
- static :  automatic call ho jata h 
- dynamic : Hero *b = new Hero();
delete b ;
but manually call krna pdta h destructor for dynamic way 
*/

// topics : const keyword and use in object creation & initialisation list 

/*
static keyword :
ye 1 esa member banata h jo instance of class hota h naa ki object ka instance mtlb isko object k hone ni hone se koi farq nhi pdta 
isko bin object k bhi access kr skte h 
syntax: datatype class_name::data_membr_name = value ; declared outside the class definition ; 

*/
//bin object k 
cout<<Hero::timetocomplete<<endl;
// object k saath
Hero a;
cout<<a.timetocomplete<<endl;

// and when u'll update it for an object ; it'll update for the whole class
Hero b;
b.timetocomplete = 10;
cout<<b.timetocomplete<<endl;
cout<<a.timetocomplete<<endl;
// updated for object 'a' also 
// but try to access it through class only and not through object

/*
static fns. :
object ki need nhi hoti same as static data member
they don't have 'this' keyword bcz inka current object hi nhi hota 
they can only access static members only  

*/

Hero::random(); // calling static function using class name
a.random(); // calling static fn. through making an object

// hw: padding, greedy alignment, const keyword, const fns., initialisation list

return 0;
}