/*
* File:			Fraction.cpp
* Author :		Ryan Ringer
* Purpose :		Fraction class declaration
* Created on :	September 4th, 2019
*/

#include <iostream>
#include <string>
#include <sstream>

#include "Fraction.h"

using namespace std;


// default constructor
Fraction::Fraction() {
	this->num = 0;
	this->den = 1;
}

// whole number constructor
Fraction::Fraction(int n) {
	this->num = n;
	this->den = 1;
}

// given values constrctor
Fraction::Fraction(int n, int d) {
	this->num = n;
	this->den = d;
}

// copy constructor
Fraction::Fraction(Fraction& f) {
	this->num = f.getNum();
	this->den = f.getDen();
}

// numerator mutator
void Fraction::setNum(int n) {
	this->num = n;
}

// denominator mutator
void Fraction::setDen(int d) {
	this->den = d;
}

// numerator accessor
int Fraction::getNum() {
	return this->num;
}

// denominator accessor
int Fraction::getDen() {
	return den;
}

// reduction fraction
Fraction& Fraction::reduce(Fraction& f) { // using the Euclidian Algorithm

	bool zero = false; // sentinel
	int gnum = 0, lnum = 0; // greater number and lesser number
	int rem = 0; //  remainder from modulus operation

	// assigning greater and lesser number
	if (f.getNum() == f.getDen()) { // if numerator is equal to denominator
		f.setNum(1);
		f.setDen(1);
	}
	else if (f.getNum() > f.getDen()) { // numerator > denominator
		gnum = f.getNum();
		lnum = f.getDen();
	}
	else { // denominator > numerator
		lnum = f.getNum();
		gnum = f.getDen();
	}
	
	do{										//
		rem = gnum % lnum;					//
		if (rem == 0) {						// Euclidian Algorithm 
			zero = true;					//
			f.setNum(f.getNum() / lnum);	//
			f.setDen(f.getDen() / lnum);	
		}
		else {
			gnum = lnum;
			lnum = rem;
		}

	} while (!zero);
	return f;
}

// addition overload
Fraction& Fraction::operator +(Fraction& f) {
	Fraction newFrac;

	newFrac.setDen(this->den * f.getDen());

	newFrac.setNum((this->num * f.getDen()) + (f.getNum() * this->den));

	return newFrac;
}

// subtraction overload
Fraction& Fraction::operator -(Fraction& f) {
	Fraction newFrac;

	newFrac.setDen(this->den * f.getDen());

	newFrac.setNum((this->num * f.getDen()) - (f.getNum() * this->den));

	return newFrac;
}

// multiplication overload
Fraction& Fraction::operator *(Fraction& f) {
	Fraction newFrac;

	newFrac.setNum(this->num * f.getNum());

	newFrac.setDen(this->den * f.getDen());


	return newFrac;
}

// division overload
Fraction& Fraction::operator /(Fraction& f) {
	Fraction newFrac;

	newFrac.setNum(this->num * f.getDen());

	newFrac.setDen(this->den * f.getNum());

	return newFrac;
}

// insertion overload
ostream& operator <<(ostream& os, Fraction& f) {
	os << f.getNum() << "/" << f.getDen();

	return os;
}

// extraction overload version 1
/*istream& operator >>(istream& is, Fraction& f) {
	
	cout << "Enter the Numerator: ";
	is >> f.num;
	cout << "Enter the Denominator: ";
	is >> f.den;

	return is;


}*/

// extraction overload version 2
istream& operator >>(istream& is, Fraction& f) {
	
	string s = "";
	string n = "";
	string d = "";
	int slashL = 0; // slash location
	cout << "Enter the Fraction with the numerator" << endl 
		<< "and the denominator separated by a '/': ";
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if ((int)s.at(i) == 47) {
			slashL = i;
		}
	}
	
	for (int i = 0; i < s.size(); i++) {
		if (i < slashL) {
			n.append(1, s.at(i));
		}
		else if (i > slashL) {
			d.append(1, s.at(i));
		}
	}
	stringstream str1(n);
	stringstream str2(d);

	str1 >> f.num;
	str2 >> f.den;
	return is;

}