#include <string>
#include <iostream>

#define FILENAME "input.txt"

int solution(std::string filename)
{
    int res = 0;
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line))
    {
        int dec_val = 10;
        for (int i = 0; i < line.size() && dec_val >= 0; i++)
        {
            // if the char is a digit
            if (line.at(i) >= 0x30 && line.at(i) <= 39)
            {
                res += ((int)line.at(i) - 0x30)*dec_val;
                dec_val /= 10;
            }
        }
    }
}

int main()
{
    std::cout << solution(FILENAME) << "\n";

    return 0;
}
