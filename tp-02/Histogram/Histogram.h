#pragma once

#include <iostream>
#include <string>
#include <vector>

class Histogram
{
public:
    Histogram(const Histogram& other);
    Histogram();
    void analyze(const std::string&); // analyse la string passée en paramètre
    void print() const;               // affiche l'histogramme

private:
    std::vector<unsigned int> _count = std::vector<unsigned int>(26, 0);
}; // tableau contenant le nombre d'occurrences de chaque lettre entre 'a' et 'z'
