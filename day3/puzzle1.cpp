#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main(void)
{
    string line;
    ifstream myfile ("input.txt");
    int i;
    int j = 0;
    int priority = 0;
    int sum = 0;
    int found = 0;
    while(getline(myfile, line))
    {
        i = 0;
        found = 0;
        j = line.size() / 2;
        cout << line << endl;
        while(line[i] && i < line.size() / 2)
        {
            while(line[j] && j < line.size())
            {
                if(line[i] == line[j])
                {
                    if(line[i] >= 'a' && line[i] <= 'z')
                    {
                        priority = line[i] - 96;
                        sum  += priority;
                        cout << "PRIORITY " << priority << ' ' << sum << endl;
                    }
                    else if (line[i] >= 'A' && line[i] <= 'Z')
                    {
                        priority = line[i] - 64 + 26;
                        sum += priority;
                        cout << "PRIORITY " << priority << ' ' << sum << endl;
                    }
                    cout << "LETTRE COMMUNE " << line[i] << ' ' << line[j] << endl;
                    found = 1;
                    break;
                }
                j++;
            }
            if (found)
                break;
            i++;
            j = line.size() / 2;
        }
    }
    return 0;
}