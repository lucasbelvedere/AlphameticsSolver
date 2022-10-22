#ifndef __PROJ_1__HPP
#define __PROJ_1__HPP

#include <unordered_map>
#include <stack>
#include <set>

/* 
 * Project 1:  you need to implement this function.
 I promise that any of my test cases will have an empty 
 	map as the fourth parameter when called.
 If the puzzle IS solvable, return true AND make the mapping indicate the solution.
 If the puzzle is NOT solvable, it is enough to return false.

 See the project 1 write-up for a better description. 
 */


bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::unordered_map<char, unsigned> &mapping);

bool verifySolution(std::string s1, std::string s2, std::string s3, const std::unordered_map<char, unsigned> &mapping);

void fillStack(std::string letters, std::unordered_map<char, unsigned> mapping, std::set<int> set_l, std::stack<std::unordered_map<char, unsigned>> &stc);

bool emptyStack(std::string s1, std::string s2, std::string s3, std::stack<std::unordered_map<char, unsigned>> &stc, std::unordered_map<char, unsigned> &mapping);

bool checkSet(std::string letters, std::set<char> &set_l);

#endif
