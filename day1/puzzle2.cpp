#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <set>

using namespace std;

int main () 
{
  string line;
  ifstream myfile ("input.txt");
  int calorie;
  int sum_calorie = 0;
  int mem_sum = 0;
  int top_three = 0;
  std::set<int> tab_mem_cal;

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
            {
                mem_sum = sum_calorie;
                tab_mem_cal.insert(mem_sum);
                cout << mem_sum << endl;
            }
            sum_calorie = 0;
        }
    }
    for (std::set<int>::iterator it = --tab_mem_cal.end(); it != tab_mem_cal.begin(); --it) 
    {
        top_three += *it;
        cout << "VALUE SET : " << *it << '\n';
    }
    cout << "TOP THREE = " << top_three << '\n';
    myfile.close();
  }
  return 0;
}