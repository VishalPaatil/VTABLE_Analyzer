/*
THE APPLICATION WHICH DEMONSTARTE CONCEPT OF VIRTUAL TABLE 
-------------------VTABLE ANALYZER------------------------
*/


#include<iostream>

using namespace std;

//base class which have to be inherite
//class contains virtual functions 
class Base
{
  public:  // access specifier
	virtual void fun() 
	{
	 cout<<"inside base fun\n";
	}
	virtual void gun()
	{
	  cout<<"inside base gun\n";
	}
};	

//derived class which inherits base class which overrides function fun. 
class Derived:public Base
{
  public:
	void fun()
	{
	 cout<<"inside derived fun\n";
	}
	virtual void run()
	{
	 cout<<"inside derived run\n";
	}
};

int main()
{
  Base bobj;
  Derived dobj;

  //pointer which holds address of derived class

  long int *op=(long int *)&dobj;	//explicite typecasting  
  cout<<"base address of derive dobject is:"<<op<<"\n";


  //artificial virtual pointer which holds address of VTABLE 

  long int *vptr=(long int *)(*op);
  cout<<"address of VTABLE is:"<<vptr<<"\n";

  void (*fp)();  //function pointer

  fp=(void(*)())(*vptr);//typecasing where function pointer points to base address of VTABLE i.e. first virtual function

  fp(); //Derived Fun

  fp=(void(*)())(*(vptr+1));//typecasing where function pointer points to base address of  second virtual function

  fp(); //Base Gun

  fp=(void(*)())(*(vptr+2)); //typecasing where function pointer points to base address of third virtual function

  fp(); //Derived Run

  return 0;
}
