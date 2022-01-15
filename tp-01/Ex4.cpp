#include <iostream>
#include <string>
#include <vector>

std::vector<unsigned int> count_lower(const std::string& input) {
    std::vector<unsigned int> occ;
    for (int i = 0; i <= 'z' - 'a'; i++)
    { occ.emplace_back(0); }
    for (char letter : input)
    { occ[letter - 'a']++; }
    return occ;
}

void display_lower_occ(const std::vector<unsigned int>& lower_occ) {
    std::cout << '[';
    for (unsigned long i = 0; i < lower_occ.size(); i++)
    {
        std::cout << char(i + 'a') << ": " << lower_occ[i];
        if (i < lower_occ.size() - 1)
        { std::cout << ", "; }
    }
    std::cout << ']' << std::endl;
}

int main() {
    std::string input;
    std::string acc;

    do
    {
        std::cin >> input;
        acc.append(input);
    }
    while (input != "QUIT");
    auto count = count_lower(acc);
    display_lower_occ(count);
    std::cout << acc << std::endl;
    return 0;
}