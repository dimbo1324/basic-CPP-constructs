#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

class Extracter
{
private:
    std::string url_;

public:
    Extracter() = delete;
    explicit Extracter(const std::string &url);

    bool isValidUrl() const;
    std::string extractDomain() const;
};
