#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

template <typename T1, typename T2, typename T3>
class Triplet {
public:
    T1 first;
    T2 second;
    T3 third;

    Triplet(const T1& f, const T2& s, const T3& t) : first(f), second(s), third(t) {}
};

std::vector<Triplet<int, int, int>> parse_input(std::string filename)
{
    std::vector<Triplet<int, int, int>> out;
    std::fstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "unable to open file\n" << std::endl;
    }

    std::string line;

    while (std::getline(file, line))
    {
        int l, w, h;
        int first_x = -1;
        int second_x = -1;
        for (int i = 0; i < line.size(); i++)
        {
            if (line.at(i) == 'x' && first_x < 0)
                first_x = i;
            else if (line.at(i) == 'x')
                second_x = i;
        }

        l = std::stoi(line.substr(0, first_x));
        w = std::stoi(line.substr(first_x+1, second_x - first_x - 1));
        h = std::stoi(line.substr(second_x+1, line.size() - second_x - 1));
        out.push_back(Triplet(l, w, h));
    }

    return out;
}

unsigned long int solution_part1(std::vector<Triplet<int, int, int>> problem_input)
{
    unsigned long int output = 0;

    for (auto triplet : problem_input)
    {
        int l = triplet.first;
        int w = triplet.second;
        int h = triplet.third;
        
        int side_0 = l*w;
        int side_1 = l*h;
        int side_2 = w*h;

        int min_dim= std::min({l, w, h});
        output += side_0 + side_1 + side_2;
        // output *=2;
        // output += min_dim;
    }

    return 2*output;
}

int main()
{
    std::vector<Triplet<int, int, int>> problem_input = parse_input("input.txt");

    int output = solution_part1(problem_input);
    std::cout << "Part 1: " << output << "\n";

    return 0;
}

