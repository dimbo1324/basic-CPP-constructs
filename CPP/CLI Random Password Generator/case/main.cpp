#include <iostream>
#include <string>
#include <random>
#include <cctype>
#include <string_view>

int main()
{
    const std::string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string LOWER = "abcdefghijklmnopqrstuvwxyz";
    const std::string DIGITS = "0123456789";
    const std::string SPECIAL = "!@#$%^&*()_+-=[]{}|;:'\",.<>?";

    /*
    (1)
        - reading the specification with lengths and codes of the character groups
        - determining the length of the password and preparing an array of available groups
    */
    std::string inputInfo;
    if (!(std::cin >> inputInfo))
    {
        return 1;
    }

    size_t position = 0;
    const bool conditional = (position < inputInfo.size()) && (std::isdigit(inputInfo[position]));

    while (conditional)
    {
        ++position;
    }

    size_t len = std::stoul(inputInfo.substr(0, position));
    std::string charset;
    std::string_view groups[] = {UPPER, LOWER, DIGITS, SPECIAL};

    /*
    (2)
        - using the a-d symbols, we add the corresponding groups to the charset
        - if the user has not specified any groups, we output an error and terminate the program
    */

    for (const auto &c : inputInfo.substr(position))
    {
        if (c >= 'a' && c <= 'd')
        {
            charset += groups[c - 'a'];
        }
    }

    if (charset.empty())
    {
        std::cerr << "No valid groups (a - d).\n";
        return 1;
    }

    /*
    (3)
        - creating a generator and distribution to evenly choose symbols from a set
    */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, charset.size() - 1);
    std::string pwd;
    pwd.reserve(len);

    while (pwd.size() < len)
    {
        pwd += charset[dist(gen)];
    }
    std::cout << "Password: " << pwd << "\n";

    return 0;
}