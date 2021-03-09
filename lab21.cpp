#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define PI 3.14159265

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
		
		friend ostream & operator<<(ostream &os, const ComplexNumber &x);
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &j){
	return ComplexNumber(real*j.real - imag*j.imag, real*j.imag + imag*j.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &j){
	double holder = j.real*j.real + j.imag*j.imag;
	return ComplexNumber((real*j.real - imag*j.imag*-1)/holder, (real*j.imag*-1 + imag*j.real)/holder);
}

bool ComplexNumber::operator==(const ComplexNumber &j){
	if(real==j.real&&imag==j.imag)return true;
	else return false;
}	

double ComplexNumber::abs(){
	return sqrt(real*real+imag*imag);
}

double ComplexNumber::angle(){
	return atan2(imag,real)*180/PI;
}

bool operator==(double x,const ComplexNumber &j){
	if(x==j.real&&j.imag==0)return true;
	else return false;
}

ComplexNumber operator/(double x, const ComplexNumber &j){
	double holder = j.real*j.real + j.imag*j.imag;
	return ComplexNumber((x*j.real - 0*j.imag*-1)/holder, (x*j.imag*-1 + 0*j.real)/holder);
}

ComplexNumber operator*(double x, const ComplexNumber &a){
	return ComplexNumber(x*a.real,x*a.imag);
}

ComplexNumber operator+(double x, const ComplexNumber &a){
	return ComplexNumber(x+a.real,a.imag);
}

ComplexNumber operator-(double x, const ComplexNumber &a){
	return ComplexNumber(x-a.real,a.imag*-1);
}

ostream & operator<<(ostream &os, const ComplexNumber &x){
	string s1="",s2="i";
	if(x.imag>0)s1 ="+";
	if(x.imag==0) return os << x.real;	
	else if(x.real==0) return os << x.imag << s2;
	return os << x.real << s1 << x.imag << s2;		
}

//Write your code here

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
 	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";

	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";

	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";

	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n"; 
}





