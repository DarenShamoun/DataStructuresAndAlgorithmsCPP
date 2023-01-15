#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int read_value (const string& prompt);
int linear_search(int key, const vector<int>& data);
int binary_search(int key, const vector<int>& data, int first, int last);

constexpr int NOT_FOUND = -1;

int main(void) 
{

  vector<int> test_data = {3, 5, 8, 12, 25, 34, 57, 58, 59, 67, 87};
  int search_for = read_value("Please enter number to search for: ");

  int result = binary_search(search_for, test_data, 0, test_data.size()-1);

  if (result == NOT_FOUND) 
  {
    cout << "Element not found using binary search\n";
  } 
  else 
  {
    cout << "Element found in position '" << result
         << "' using binary search\n";
  }

  result = linear_search(search_for, test_data);

  if (result == NOT_FOUND) 
  {
    cout << "Element not found using linear search\n";
  } 
  else 
  {
    cout << "Element found in position '" << result
         << "' using linear search\n";
  }
  return 0;
}

int binary_search(int key, const vector<int>& data, int first, int last) 
{
  // base case
  if (first >= last) 
  {
    if (data[first] == key) 
    {
      return first;
    } 
    return NOT_FOUND;
  }
  int midpoint = (first+last) / 2;
  if (key > data[midpoint]) 
  {
    // look to the left (greater than) midpoint
    return binary_search(key, data, midpoint + 1, last);
  }
  // look to the right (less than) midpoint
  return binary_search(key, data, first, midpoint);
}

int linear_search(int key, const vector<int>& data) {
  // search for key and return index
  for (auto i = 0; i < int(data.size()); ++i) 
  {
    if (data[i] == key) 
    {
      return i;
    }
  }
  return NOT_FOUND;
}


int read_value (const string& prompt) 
{
  std::cout << prompt;
  string line;
  auto val = INT32_MAX;
  while (getline(std::cin, line)) 
  {
    try 
    {
      val = std::stoul(line);
    } 
    catch ( ... ) 
    {
      std::cerr << "bad input. try again\n";
    }
    if (!line.empty()) 
    {
      break;
    }
    line.clear();
  }
  return val;
}


