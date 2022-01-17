#include <iostream>
#include <string>

class Person
{
public:
    Person() {}

    Person(const std::string& name, const std::string& surname)
        : _name { name }
        , _surname { surname } {}

    const std::string& get_full_name() const { return _name + " " + _surname; }
    unsigned int       get_age() const { return _age; }

    void wait(unsigned int time) { _age += time; }

private:
    const std::string _surname;
    const std::string _name;
    unsigned int      _age = 0u;
};

int main() {
    Person p { "Batman" };

    p.set_age(23);

    std::cout << "Person named '" << p.get_name() << "' is " << p.get_age() << " years old." << std::endl;

    return 0;
}
