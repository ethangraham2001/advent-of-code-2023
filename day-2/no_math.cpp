#include <iostream>
#include <fsteam>
#include <string>

#define FILENAME "input.txt"

/**
 * @brief solves the problem
 */
int solution_day2(std::string filename)
{
    std::ifstream file(filename);

    if (!file.isopen())
        return -1;

    std::string line;
    while(getline(file, line))
    {
        int first_x = -1;
        int second_x = -1;

        for (int i = 0; i < line.size(); i++)
        {
            if (line.at(i) == 'x' && first_x < 0)
                first_x = i;
            else if (line.at(i) == 'x')
                second_x = i;
        }
    }
}


int main()
{

}
