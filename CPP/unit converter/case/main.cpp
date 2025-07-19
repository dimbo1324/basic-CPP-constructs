#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <stdexcept>

class Converter
{
    double value_;
    std::string fromUnit_;
    std::string toUnit_;

    static const std::unordered_set<std::string> supported_;

    static const std::unordered_map<std::string, double> base_;

public:
    Converter(double value, const std::string &from, const std::string &to)
        : value_(value), fromUnit_(from), toUnit_(to)
    {
        if (!supported_.count(fromUnit_) || !supported_.count(toUnit_))
        {
            throw std::invalid_argument("Неподдерживаемая единица: " + (supported_.count(fromUnit_) ? toUnit_ : fromUnit_));
        }
    }

    double convert() const
    {
        double inBase = value_ * base_.at(fromUnit_);
        return inBase / base_.at(toUnit_);
    }
};

const std::unordered_set<std::string> Converter::supported_ = {"m", "cm", "km", "g", "kg", "l", "ml"};

const std::unordered_map<std::string, double> Converter::base_ = {
    {"m", 1.0},
    {"cm", 0.01},
    {"km", 1000.0},
    {"g", 1.0},
    {"kg", 1000.0},
    {"l", 1.0},
    {"ml", 0.001}
};

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Использование: " << argv[0] << " <значение> <из_единицы> <в_единицу>\n" << "Пример: " << argv[0] << " 150 cm m\n";
        return 1;
    }

    try
    {
        double value = std::stod(argv[1]);
        std::string from = argv[2];
        std::string to = argv[3];

        Converter conv(value, from, to);
        double result = conv.convert();

        std::cout << std::fixed << std::setprecision(2) << value << " " << from << " = " << result << " " << to << "\n";
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Ошибка: " << e.what() << "\n";
        return 2;
    }
    catch (const std::out_of_range &)
    {
        std::cerr << "Ошибка: число слишком большое или невалидное.\n";
        return 3;
    }
    catch (...)
    {
        std::cerr << "Неожиданная ошибка.\n";
        return 4;
    }

    return 0;
}
