#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// X means loose
// Y means egality
// Z means win
int main () 
{
  string line;
  int score = 0;
  ifstream myfile ("input.txt");

  if (myfile.is_open())
  {
    while (getline (myfile,line))
    {
        if(line[0] == 'A') //rock
        {
            if(line[2] == 'Y') // paper draw
            {
                score += 3;
                score += 1;
            }
            else if(line[2] == 'X') // rock lose
            {
                score += 3;
            }
            else if(line[2] == 'Z') // scissors win
            {
                score += 6;
                score += 2;
            }
        }
        else if (line[0] == 'B') // paper
        {
            if(line[2] == 'Z') // win
            {
                score += 6;
                score += 3;
            }
            else if(line[2] == 'Y') // paper draw
            {
                score += 3;
                score += 2;
            }
            else if(line[2] == 'X') // rock lose
                score += 1;
        }
        else if (line[0] == 'C') // scissors
        {
            if(line[2] == 'X') // rock lose
            {
                score += 2;
            }
            else if(line[2] == 'Z') // scissors win
            {
                score += 6;
                score += 1;
            }
            else if(line[2] == 'Y') //paper draw
            {
                score += 3;
                score += 3;
            }
        }
        cout << "SCORE :" << score << endl;
        // cout << line << endl;
    }
    myfile.close();
  }
  return 0;
}