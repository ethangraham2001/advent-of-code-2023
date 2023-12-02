#include <string>
#include <iostream>
#include <fstream>

#define FILENAME "trebuchet_input.txt"

int solution(std::string filename)
{
    int res = 0;
    std::fstream file(filename);
    std::string line;

    while (getline(file, line))
    {
        int first = -1;
        int last = 0;

        for (int i = 0; i < line.size(); i++)
        {
            int curr = line.at(i) - '0';
            if (curr >= 0 && curr <= 9) {
                last = curr;
                if (first < 0)
                    first = curr;
            }
        }

        res += first*10 + last;
    }
    return res;
}

int main()
{
    std::cout << solution(FILENAME) << "\n";

    return 0;
}
