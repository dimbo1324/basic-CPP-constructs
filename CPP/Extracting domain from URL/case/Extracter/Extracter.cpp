#include "Extracter.hpp"

Extracter::Extracter(const std::string &url) : url_(url) {};

bool Extracter::isValidUrl() const
{
    return url_.find('.') != std::string::npos && url_.find(' ') == std::string::npos;
};

std::string Extracter::extractDomain() const
{
    auto protocolEnd = url_.find("://");
    auto start = (protocolEnd == std::string::npos) ? 0 : protocolEnd + 3;
    auto end = url_.find('/', start);
    std::string target = url_.substr(start, end - start);
    std::transform(target.begin(), target.end(), target.begin(), [](unsigned char c){ 
        return std::tolower(c);
    });
    return target;
};