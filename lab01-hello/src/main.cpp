#include <iostream>
#include "echo.h"

int main() 
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << echo("Hello, world") << '\n';
	}
  
	return 0;
}

