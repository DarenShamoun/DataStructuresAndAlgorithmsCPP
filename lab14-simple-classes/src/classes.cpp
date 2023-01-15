#include "classes.h"

void mesa::clock::time(const double time)
{
	this->currentTime = time;
}

double mesa::clock::time() const
{
	return this->currentTime;
}

double complex::real() const
{
	return this->realNum;
}

double complex::imaginary() const
{
	return this->imaginaryNum;
}

void truck::pop_tire()
{
	if (this->tireCount != 0)
	{
		this->tireCount--;
	}
}

uint16_t truck::tires() const
{
	return this->tireCount;
}

