/*
* File:			Fraction.h
* Author :		Ryan Ringer
* Purpose :		Fraction class declaration
* Created on :	September 4th, 2019
*/

// Write a class Fraction that defines adding, subtracting, multiplying, and
// dividing fractions by overloading standard operators for these operations.
// Write afunction member for reducing factors and overload I/O operators to 
// input and output fractions

#include <iostream>
class Fraction {
	private:
		int num; // Numerator
		int den; // Denominator

	public:
		

		Fraction(); // Default constructor
		Fraction(int); // Whole number constructor
		Fraction(int, int); // Fraction constructor
		Fraction(Fraction &); // Copy constructor
		void setNum(int); // Numerator setter
		void setDen(int); // Denominator setter
		int getNum(); // Numerator getter
		int getDen(); // Denominator getter
		Fraction& reduce(Fraction &); // Redicing function
		Fraction& operator +(Fraction &); // Addition overload
		Fraction& operator -(Fraction &); // Subtraction overload
		Fraction& operator *(Fraction &); // Multiplication overload
		Fraction& operator /(Fraction &); // Division overload

		friend std::ostream& operator <<(std::ostream &, Fraction &);
		friend std::istream& operator >>(std::istream &, Fraction &);

		
};