#ifndef CISC_MESA_LAB14_CLASSES_H
#define CISC_MESA_LAB14_CLASSES_H
#include <ostream>

namespace mesa 
{
	class clock
	{
	private:
		double currentTime = 0.0;
	public:
		void time(const double time);
		double time() const;
	};
}

class complex
{
	double realNum;
	double imaginaryNum;
public:
	complex()
		:realNum{ 0 },
		imaginaryNum{ 0 }
	{}
	complex(double real, double imaginary)
		:realNum{real},
		imaginaryNum{imaginary}
	{}
	
	double real() const;
	double imaginary() const;
};

class truck
{
	uint16_t tireCount;
public:
	truck()
		:tireCount{ 6 }
	{}
	truck(uint16_t tires)
		:tireCount{ tires }
	{}
	void pop_tire();
	uint16_t tires() const;
};


enum class dog_size { SMALL, MEDIUM, LARGE };
class dog
{
	std::string dogName;
	dog_size dogSize;
public:
	dog()
		:dogName{ "Fido" },
		dogSize{ dog_size::MEDIUM }
	{}
	dog(std::string name, dog_size sz)
		:dogName{ name },
		dogSize{ sz }
	{}
	
	void name(std::string input)
	{
		this->dogName = input;
	}
	
	std::string name() { return this->dogName; }
	
	dog_size size() { return this->dogSize; }
	
	std::string bark() const
	{
		switch (this->dogSize)
		{
		case dog_size::SMALL:
			return "Yip";
		case dog_size::MEDIUM:
			return "Ruff";
		case dog_size::LARGE:
			return "Woof";
		}
		return "Woof";
	}
};
#endif // !CISC_MESA_LAB14_CLASSES_H