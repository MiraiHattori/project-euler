#include <algorithm>
#include <iostream>
#include <vector>

long long calcTriangle(const long long& n)
{
    return n * (n + 1) / 2;
}
long long calcPentagonal(const long long& n)
{
    return n * (3 * n - 1) / 2;
}
long long calcHexagonal(const long long& n)
{
    return n * (2 * n - 1);
}

enum class FormulaeType : int {
    None = 0b000,
    Triangle = 0b001,
    Pentagonal = 0b010,
    Hexagonal = 0b100,
    TriAndPenta = 0b011,
    PentaAndHexa = 0b110,
    HexaAndTri = 0b101,
    All = 0b111,
};

FormulaeType min(
    const long long& triangle,
    const long long& pentagonal,
    const long long& hexagonal)
{
    uint8_t type = 0b000;
    long long min_num = std::min(triangle, std::min(pentagonal, hexagonal));
    if (triangle == min_num) {
        type |= static_cast<uint8_t>(FormulaeType::Triangle);
    }
    if (pentagonal == min_num) {
        type |= static_cast<uint8_t>(FormulaeType::Pentagonal);
    }
    if (hexagonal == min_num) {
        type |= static_cast<uint8_t>(FormulaeType::Hexagonal);
    }
    switch (static_cast<FormulaeType>(type)) {
    case FormulaeType::Triangle:
        break;
    case FormulaeType::Pentagonal:
        break;
    case FormulaeType::Hexagonal:
        break;
    case FormulaeType::TriAndPenta:
        break;
    case FormulaeType::PentaAndHexa:
        break;
    case FormulaeType::HexaAndTri:
        break;
    case FormulaeType::All:
        break;
    default:
        // FormulaeType::Noneかその他
        std::cerr << "error: " << static_cast<int>(type) << std::endl;
        break;
    }
    return static_cast<FormulaeType>(type);
}

int main()
{
    // レースのように計算していく
    int i = 1;
    int j = 1;
    int k = 1;
    while (true) {
        switch (min(calcTriangle(i), calcPentagonal(j), calcHexagonal(k))) {
        case FormulaeType::Triangle:
            i++;
            break;
        case FormulaeType::Pentagonal:
            j++;
            break;
        case FormulaeType::Hexagonal:
            k++;
            break;
        case FormulaeType::TriAndPenta:
            i++;
            j++;
            break;
        case FormulaeType::PentaAndHexa:
            j++;
            k++;
            break;
        case FormulaeType::HexaAndTri:
            k++;
            i++;
            break;
        case FormulaeType::All:
            if (calcTriangle(i) != 1 and calcTriangle(i) != 40755) {
                std::cout << "The answer is " << calcTriangle(i) << "." << std::endl;
                return 0;
            }
            i++;
            j++;
            k++;
            break;
        default:
            // FormulaeType::Noneかその他
            std::cerr << "error: " << std::endl;
            break;
        }
    }
    return 0;
}
