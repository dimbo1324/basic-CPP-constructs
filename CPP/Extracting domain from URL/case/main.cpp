#include <iostream>
#include <cctype>
#include "Extracter/Extracter.hpp"

int main()
{
    const std::string url = "HTTPS://Site.com/PageOne";
    Extracter ex(url);

    if (!ex.isValidUrl())
    {
        std::cerr << "Invalid URL\n";
        return 1;
    }

    std::cout << "Domain: " << ex.extractDomain() << "\n";
    return 0;
}