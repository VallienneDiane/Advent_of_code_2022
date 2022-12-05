#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main () 
{
  std::string line;
  int calorie;
  int sum_calorie = 0;
  int mem_sum = 0;
  ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
    while (getline (myfile,line))
    {
        if(line.size() != 0)
        {
            calorie = std::stoi(line);
            sum_calorie += calorie;
        }
        else
        {
            if (sum_calorie > mem_sum)
                mem_sum = sum_calorie;
            sum_calorie = 0;
        }
    }
    myfile.close();
  }
  return 0;
}