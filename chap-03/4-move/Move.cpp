#include <iostream>
#include <memory>
#include <utility>
void display(const std::string& variable_name, const std::unique_ptr<int>& variable) {
    if (variable)
    { std::cout << variable_name << " contains " << *variable << std::endl; }
    else
    { std::cout << variable_name << " is empty" << std::endl; }
}
std::unique_ptr<int> passthrough(std::unique_ptr<int> a) {
    std::unique_ptr<int> b = std::move(a);
    return b;
}

int main() {
    auto i1 = std::make_unique<int>(3);
    auto i2 = std::make_unique<int>(4);
    display("i1 before call", i1);
    display("i2 before call", i2);

    i2 = passthrough(std::move(i1));
    display("i1 after call", i1);
    display("i2 after call", i2);
    return 0;
}