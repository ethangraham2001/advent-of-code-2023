#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <chrono>

#define FILENAME "../inputs/trebuchet_input.txt"

/**
 * @brief solves part 1
 *
 * @param filename name of input file
 */
int solution_part1(std::string filename)
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

#define IS_DIG(c) ((c) >= '0' && (c) <= '9')

/**
 * @brief solves part 2
 *
 * @param filename name of input file
 */
int solution_part2(std::string filename)
{
    /* string-to-digit conversion */
    std::unordered_map<std::string, int> str_to_int = {
        {"one",   1},
        {"two",   2},
        {"three", 3},
        {"four",  4},
        {"five",  5},
        {"six",   6},
        {"seven", 7},
        {"eight", 8},
        {"nine",  9},
    };

    int res = 0;
    std::fstream file(filename);
    std::string line;

    while (getline(file, line))
    {
        int first = -1;
        int last = -1;
        int i = 0; 
        while (i < line.size())
        {
            int value = -1;

            // search for value starting at current position
            if (IS_DIG(line.at(i))) {
                value = line.at(i) - '0';
            } else {
                int j = i + 1; 

                while (j < line.size() && !IS_DIG(line.at(j)))
                {
                    std::string substr = line.substr(i, j-i+1);

                    if (str_to_int[substr]) {
                        value = str_to_int[substr];
                        i = j - 1;
                        break;
                    }

                    j++;
                }
            }
            i++;
            if (value > 0) {
                if (first < 0) {
                    first = value;
                }

                last = value;
            }
        }

        res += first*10 + last;
    }
    return res;
}

int main()
{
    int res;
    std::chrono::duration<double> duration;

    // BEGIN: Part 1
    auto start = std::chrono::high_resolution_clock::now();
    res = solution_part1(FILENAME);
    auto end = std::chrono::high_resolution_clock::now();
    duration = end - start; 
    std::cout << "Elapsed time: " << duration.count() 
        << "seconds; \tres_1 = " << res << std::endl;
    // END: Part 1
    
    // BEGIN: Part 2
    start = std::chrono::high_resolution_clock::now();
    res = solution_part2(FILENAME);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start; 
    std::cout << "Elapsed time: " << duration.count() 
        << "seconds; \tres_2 = " << res << std::endl;
    // END: Part 2
    return 0;
}
