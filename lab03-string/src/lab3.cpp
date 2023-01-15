#include <iostream>
#include <string>
#include <cctype>
#include "lab3.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

std::string sentence_case(std::string words)
{
	if (words.empty())
	{
		return words;
	}

	if (words.back() == '.')
	{
		words[0] = char(toupper(static_cast <char>(words.front())));
	}
	return words;

}

std::string phone_format(std::string phone)
{
	std::string not_valid = "Not a phone number.";

	if (phone.size() == 10 && (phone.find_first_not_of("0123456789") == string::npos))
	{
		phone.insert(0, 1, '(');
		phone.insert(4, 1, ')');
		phone.insert(5, 1, ' ');
		phone.insert(9, 1, '-');
	}
	else
	{
		return not_valid;
	}
	
	return phone;

}

std::string name_format(std::string name)
{
	string firstName = "";
	string lastName = "";
	string result = "";
	//string name = "daren shamoun";
	int len = int (name.length());
	int spaces = 0;
	int spaceLocation;

	for (int i = 0; i <= len; i++)
	{
		if (name[i] == ' ')
		{
			spaces++;
			spaceLocation = i;
			cout << "Index " << i << endl;
		}
	}

	if (spaces == 1)
	{
		firstName = char(toupper(name[0]));
		lastName = name.substr(static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(spaceLocation) + 2, string::npos);
		char lastNameFirstChar = char(toupper(name[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(spaceLocation) + 1]));

		result += lastNameFirstChar;
		result += lastName;
		result += ", ";
		result += firstName;
		result += ".";

		return result;
	}

	cout << result;

	return name;
}
