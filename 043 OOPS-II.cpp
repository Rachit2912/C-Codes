#include<iostream>
#include <string>
using namespace std;

/*encapsulation : wrapping up data members and fns. in a single entity 
fully encapsulated class : all data members are private marked 
adv. of encapsulation : 
-information/data hiding so security increases
-if we want, we can make it only 'read only' 
- code reusability 
- unit testing 
*/

class student{
string name;
int age; 
int height;

public:
int getage(){
    return this->age;
}
};

/*
inheritance:
some data members or fns. will be inherited from parent/super class to child/sub class
syntax : class male private human{};
*/


/*
base class member access specifier|       public      protected     private

                            public        public      protected     private 
                            protected     protected   protected     private
                            private       not acessible  in any of the cases 

*/

class human{
    public:
    int height;
    int weight;
    int age;
    int getage(){
        return this->age;
    }

    void setweight(int w){
        this->weight = w;
    }
};

class male: public human{
    public:
    string color;
    void sleep(){
        cout<<"male sleeping"<<endl;
    }
};

/*
types of inheritance : 
1) single  : class A --> class B 
2) multilevel  : class A --> class B --> class C 
3) multiple : class A, class B  --> class C 
4) hierarchical :  class A --> class B, class C 
5) hybrid : mixture of all of the above 
*/

/*
inheritance ambiguity : 
- if in multiple inheritance, base classes have same fns. with similar names and then inherited to child class then on the fn. call , which fn. will be called ? 
this is the inheritance ambiguity.
so we'll use  "Scope Resolution Operator (::)" to remove the ambiguity.
like eg: class C: public class A, public class B & both class A & B have fns. with similar names "fn()"
then, C object :
-> object.A::fn() for calling the fn. fn() in class A and object.B::fn() for calling the fn. fn() in class B.
*/

/*
Polymorphism : 
- many forms / 1 chiz multiple forms me exist kre 
1) compile/static time polymorphism :
-kya chiz kin kin form me exist kregi ye ni pta hota h bcz hm before runtime pr hote h 
2 ways to achieve : 
(i) fn. overloading and (ii) operator overloading 

(i) fn. overloading:
- 1 hi class me 2 fn. same name se ni hone chahiye bcz it creates confusion
isliye isko overload krne k 2 methods h : 
i} by number of params , ii} by type of params


(ii) operator overloading : 
- 4 operators can't be overloaded which are  
:: (scope resolution)
. (member selection)
.* (member selection through pointer to function)
?: (ternary operator)


2) runtime/dynamic time polymorphism : 
- ye keval runtime pr hi pta chlta h 
-methods to achieve : (i) method overriding


Rules for method overriding:
-> The parent class method and the method of the child class must have the same name.
-> The parent class method and the method of the child class must have the same parameters.
-> It is possible through inheritance only.
*/

/*
abstraction:
- implementation hiding 
*/

class a{
    public:
    int c,d;
    //fn.overloading:
    void sayhello(){
        cout<< "hello rachit joshi"<< endl;
    }

    void sayhello(string name){
        cout<< "hello rachit joshi"<< endl;
    }

    void sayhello(int i){
        cout<< "hello rachit joshi"<< endl;
    }

    //operator overloading
    void add(){
        cout<<"add() fn. : "<< c+d<<endl;
    }

    void operator+ (a &obj){
        cout<<"sum of c's are "<< this->c +  obj.c <<endl;
        cout<<"sum of d's are "<< this->d + obj.d << endl;
    }

    // an unary operator
    void operator()(){
        cout<< "hm to 2 chote wale brackets h bhaii ..."<< this->c<< " "<< this->d <<endl;
    }

};

// method overriding
class animal{
    public:
    void speak(){
        cout<<"speak"<<endl;
    }
};

class dog : public animal {
    public:
    void speak(){
        cout<<"bark!"<<endl;
    }
};

int main(){


student first;

male m1;
cout<<m1.height<<m1.weight<<m1.age<<endl;
cout<<m1.getage()<<endl;
cout<<m1.color<<endl;
m1.sleep();

m1.setweight(60);
cout<<m1.weight<<endl;
 

// fn. overloading 
a o;
o.sayhello();
o.sayhello("rachit");
o.sayhello(2);
// it's working having 3 fns. with the same name


// operator overloading
o.c= 10; o.d = 12;
a p;
p.c = 20; p.d = 23;
p.add();
o+p; // calling operator fn. which is defined in class a
o();


// method overriding 
// parent class 
animal a;
a.speak();
// child class
dog d;
d.speak();



return 0;

}