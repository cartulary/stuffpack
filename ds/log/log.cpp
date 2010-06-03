#include <iostream>
#include <cmath>
#include <stdexcept>
#include "exp.h"

namespace cows {

class DivideByZeroException : public std::logic_error {
public:
	DivideByZeroException() : logic_error("Every time you divide by zero you kill a camel") {};
};


class log {
	//thrown when attempting operations on multiple logs with different bases
	public:
	class BaseMismatchException : public std::logic_error
	{
		public:
		BaseMismatchException() : logic_error("Attempted operations on logs with different bases") {};
	};

	//thrown when log base is set to illegal number (<=0)
	class InvalidBaseException : public std::logic_error
	{
	public:
		InvalidBaseException() : logic_error("Attempted to use invalid base for log") {};
	};
private:
	double coefficient, number, base;

	void applyBase (double newBase)
	{
		this->setNumber( exp( this->getBase(), this->getValue() / this->getCoefficient() ) );
		this->setBase( newBase );
	}

public:

	log(double w_base, double w_number);

	log operator*= ( const double b );

	double operator+ ( const double b ) const;
	log operator* ( const double b ) const;
	double operator- ( const double b ) const;
	double operator/ ( const double b ) const;

	void setCoefficient( double coeff );
	void setBase( double base );
	void setNumber( double number );

	double getCoefficient() const;
	double getBase() const;
	double getNumber() const;
	double getValue() const;

	void changeBase( const double base );

	friend double operator-( const double lhs, const log &rhs )
	{
		return lhs - rhs.getValue();
	}

	friend std::ostream &operator<<( std::ostream &mycout, const log &myLog )
	{
		const double coeff = myLog.getCoefficient();
		if (coeff == 0)
		{
				mycout << coeff;
		}
		else if (coeff == 1)
		{
			mycout << "log(" << myLog.getBase() << ") " << myLog.getNumber();
		}
		else
		{
			mycout << coeff << " * log(" << myLog.getBase() << ") " << myLog.getNumber();
		}
		return mycout;
	}

};

log::log( const double w_base, const double w_number ) : coefficient(1), number(w_number), base(w_base)
{
	if (w_base <= 0)
	{
		throw InvalidBaseException();
	}
}

double log::getValue() const
{
	return this->coefficient * ( ( std::log( this->number ) / std::log( this->base ) ) );
}

void log::setCoefficient( double coeff )
{
	this->coefficient = coeff;
}

void log::setBase( const double newBase )
{
	if ( newBase <= 0 )
	{
		throw InvalidBaseException();
	}
	this->base = newBase;
}

void log::setNumber( const double newNumber )
{
	this->number = newNumber;
}

double log::getCoefficient() const
{
	return this->coefficient;
}

double log::getBase() const
{
	return this->base;
}

double log::getNumber() const
{
	return this->number;
}

void log::changeBase( double newBase )
{
	this->applyBase( newBase );
}

double log::operator+( const double b ) const
{
	// transform both numbers ( this and b ) into 'a', add, then take log base 1
	return ( b + this->getValue() );
}

log log::operator*( const double b ) const
{
	return log(this->base, this->number * b);
}

log log::operator*=( const double b )
{
	this->number *= b;
	this->applyBase( this->base );
	return *this;
}

//TODO: dealing with doubles correctly is a PITA -- fix later
double log::operator-( const double b ) const
{
	return ( this->getValue() - b );
}

double log::operator/( const double b ) const
{
	if( b == 0 ) {
		throw DivideByZeroException();
	}
	return ( this->getValue() / b );
}

}

int main(void)
{

	cows::log logOne(10,100);
	cows::log logTwo(2,1024);

	try
	{
		cows::log logThree(0,10);
	}
	catch (cows::log::InvalidBaseException &e)
	{
		std::cerr << "We don't like killing cows\n";
	}
	logOne.setCoefficient( 5 );

	std::cout << logOne << std::endl;

	logTwo.setBase( 10.0 );
	logTwo.setCoefficient( 1.0 );
	logTwo.setNumber( 1000.0 );

	logOne *= 5;

	std::cout << logOne.getValue() << "\n";

	std::cout << "logOne + 15: " << ( logOne + 15 ) << std::endl;
	std::cout << "logOne - 15: " << ( logOne - 15 ) << std::endl;

	try
	{
		std::cout << logOne / 0 << "\n"; //should throw exception
	}
	catch( cows::DivideByZeroException &e )
	{
		std::cout << "You killed a cow. Happy now?\n";
	}
	std::cout << 25 - logOne << "\n";
	std::cout << logOne - 25 << "\n";
	std::cout << logOne / 2 << "\n";
	std::cout << logTwo << "\n";
	logOne = logOne * 5;
	std::cout << logOne << "\n";

	char a;
	std::cin >> a;
	return 0;
}
