#include "proj1.hpp"
#include <unordered_map>
#include <string>

// Main should contain all test cases or anything to be printed on the screen.

int main()
{
    std::unordered_map<char, unsigned> mapping;
    assert(puzzleSolver("AB", "CD", "EF", mapping));
    mapping = {};
    assert(puzzleSolver("POT", "PAN", "BIB", mapping));
    mapping = {};
    assert(puzzleSolver("PAN", "POT", "BIB", mapping));
    mapping = {};
    assert(puzzleSolver("", "POT", "POT", mapping));
    mapping = {};
    assert(puzzleSolver("POT", "", "POT", mapping));
    mapping = {};
    assert(!puzzleSolver("POT", "POT", "", mapping));
    mapping = {};
    assert(puzzleSolver("PPPPP", "BB", "PPPAA", mapping));
    mapping = {};
    assert(puzzleSolver("BB", "PPPPP", "PPPAA", mapping));
    mapping = {};
    assert(puzzleSolver("", "", "", mapping));
    mapping = {};
    assert(puzzleSolver("SEND", "MORE", "MONEY", mapping));
    mapping = {};
    assert(puzzleSolver("UCI", "ALEX", "MIKE", mapping));
    mapping = {};
    assert(!puzzleSolver("ABCDE", "FGHIJ", "KLMNO", mapping));
    
    return 0;
}



