#include "proj1.hpp"
#include <unordered_map>
#include <string>

// If you really want to make a program for the app, be my guest.
// Or better yet, use gtest to automate your own test cases!
// Remember, we use gtest to grade, not your main.

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



