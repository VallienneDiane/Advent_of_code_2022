#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// A ROCK       X  SCORE    1
// B PAPER      Y           2
// C SCISSORS   Z           3
// +
// WIN 6
// LOST 0
// EGALITY 3
// X beats C
// Y beats A
// Z beats B
int main () 
{
  string line;
  int score = 0;
  ifstream myfile ("input.txt");

  if (myfile.is_open())
  {
    while (getline (myfile,line))
    {
        if(line[0] == 'A')
        {
            if(line[2] == 'Y')
            {
                score += 6;
                score += 2;
            }
            else if(line[2] == 'X')
            {
                score += 3;
                score += 1;
            }
            else if(line[2] == 'Z')
                score += 3;
        }
        else if (line[0] == 'B')
        {
            if(line[2] == 'Z')
            {
                score += 6;
                score += 3;
            }
            else if(line[2] == 'Y')
            {
                score += 3;
                score += 2;
            }
            else if(line[2] == 'X')
                score += 1;
        }
        else if (line[0] == 'C')
        {
            if(line[2] == 'X')
            {
                score += 6;
                score += 1;
            }
            else if(line[2] == 'Z')
            {
                score += 3;
                score += 3;
            }
            else if(line[2] == 'Y')
                score += 2;
        }
        cout << "SCORE :" << score << endl;
        // cout << line << endl;
    }
    myfile.close();
  }
  return 0;
}