/*
A Base class pointer can point to its any Derived class object.
A Base class reference can refer to its any Derived class object.
ex:
A<-B<-C<-D

in pointer of class A we can store the address of object of class A or B or C or D.
A oba,*ap;
B obb;
C obc;
D obd;

ap=&oba;
ap=&obb;//valid
ap=&obc;//valid
ap=&obd;

But its vice versa is not possible
--------------------------------------------
we cant store the address of object of class A in pointer of class B or C or D

If a derived class' object's address in stored in Base class pointer the only the member available in base class is accessible.
*/

#include<iostream>
using namespace std;
class A
{
	protected:
		int a;
	public:
		A(int a=0)
		{
			this->a=a;
		}
		void setA(int a)
		{
			this->a=a;
		}
		virtual void show()
		{
			cout<<"\na="<<a;
		}
 } ;
 class B:public A
 {
 	protected:
 		int b;
 	public:
 		B(int b=0)
 		{
 			this->b=b;
		 }
		 void setB(int b)
		 {
		 	this->b=b;
		 }
		 //override show()
		 void show()
		 {
		 	cout<<"\na="<<a<<", b="<<b;
		 }
 };
 
 int main()
 {
 	A oba,*ap;
 	//store the address of oba on ap
 	ap=&oba;
 	
 	oba.show();
 	ap->show();
 	
 	ap->setA(10);
 	ap->show();
 	
 	B obb,*bp;
 	//store the address of obb in bp
 	bp=&obb;
 	bp->show();
 	
 	bp->setA(15);
 	bp->setB(30);
 	bp->show();
 	
 	//store the address of obb (object of class B) in pointer ap(pointer of class A
 	ap=&obb;//valid
 	//now ap is storing the address of object of class B while ap is pointer of class A
 	//here we can access only members that are available in class A 
 	ap->show();
	 ap->setA(10);
 	//ap->setB(20);
 	ap->show();
 	
 	
 	//reference Example
 	A &ar=obb;//here class a type reference is refering to class b type object
 	ar.show();
 	
 	
 	return 0;
 }


