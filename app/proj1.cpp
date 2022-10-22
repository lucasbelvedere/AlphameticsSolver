#include "proj1.hpp"
#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <stack>
#include <queue>

void fillStack(std::string letters, std::unordered_map<char, unsigned> mapping, std::set<int> set_l, std::stack<std::unordered_map<char, unsigned>> &stc){
    
    //base case
    if(letters == ""){
        stc.push(mapping);
        return;
    }
    
    // recursive case
    std::set<int> set_temp;
    for(auto it = set_l.begin(); it != set_l.end(); it++){
        set_temp = set_l;
        set_temp.erase(*it);
        mapping.insert_or_assign(letters[0], *it);
        fillStack(letters.substr(1, letters.length()), mapping, set_temp, stc);
    }
}

//bool emptyStack(std::string s1, std::string s2, std::string s3, std::stack<std::unordered_map<char, unsigned>> &stc, std::unordered_map<char, unsigned> &mapping){
//
//
//    if(stc.empty()) // base case: if stack is empty, returns false.
//        return false;
//
//
//    // recursive cases: pops one map of stack, verifies solution. If no solution was found, calls function recursively to check next value.
//    mapping = stc.top();
//    stc.pop();
//    if(verifySolution(s1, s2, s3, mapping))
//        return true;
//    return emptyStack(s1, s2, s3, stc, mapping);
//}

bool emptyStack(std::string s1, std::string s2, std::string s3, std::stack<std::unordered_map<char, unsigned>> &stc, std::unordered_map<char, unsigned> &mapping){

    while(!stc.empty()){
        mapping = stc.top();
        stc.pop();
        if(verifySolution(s1, s2, s3, mapping))
            return true;
    }
    return false;
}


//bool checkSet(std::string letters, std::set<char> &set_l){
//    //TODO: CREATE TEST CASES FOR THIS FUNCTION ON MAIN.CPP. ALSO, USE RECURSION ONLY ON MAIN FUNCTION TO AVOID STACK OVERFLOW.
//
//    if(set_l.size() > 10) // base cases: checks to see if there are more than 10 letters.
//        return false;
//    else if(letters.empty()) // checks if letters is already empty.
//        return true;
//
//    // recursive case: checks to see if there are more than 10 letters, returns false if so.
//    set_l.insert(letters[0]);
//    letters = letters.substr(1, letters.length()-1);
//    return checkSet(letters, set_l);
//}

bool checkSet(std::string letters, std::set<char> &set_l){
    //TODO: CREATE TEST CASES FOR THIS FUNCTION ON MAIN.CPP. ALSO, USE RECURSION ONLY ON MAIN FUNCTION TO AVOID STACK OVERFLOW.
    
    while(!letters.empty()){
        if(set_l.size() > 10)
            return false;
        set_l.insert(letters[0]);
        letters = letters.substr(1, letters.length()-1);
    }
    return true;
    
}


bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::unordered_map<char, unsigned> &mapping)
{
    // creating variables necessary for operations
    std::set<char> set_letters;
    std::set<int> set_int = {1,2,3,4,5,6,7,8,9,0};
    std::stack<std::unordered_map<char, unsigned>> stc;
    
    // first function checks amount of letters to see if case is viable
    std::string letters = s1 + s2 + s3;
    if(!checkSet(letters, set_letters))
       return false;
       
    // resets letters and prepares variables to see all possible outcomes.
    letters = "";
    std::set<char>::iterator it = set_letters.begin();
    while(it != set_letters.end()){
        letters += *it;
        it++;
    }
    
    // main function
    fillStack(letters, mapping, set_int, stc);
    return emptyStack(s1, s2, s3, stc, mapping);// recursive function
}

bool verifySolution(std::string s1, std::string s2, std::string s3, const std::unordered_map<char, unsigned> & mapping)
{
    if(s1 == "" && s2 == "" && s3 == "")
        return true;
    if(s3 == "" && (s1 != "" || s2 != "")) // case where s3 is empty.
        return false;
    
    auto power = [](int a, int b) { // lambda expression that calculates the power.
        return a * b;
    };
    
    // solution
    int temp = 0, temp2 = 0, powerTemp = 1;
    // each loop iterates through each string, summing and using the lambda expression.
    for(unsigned long m = s1.length() - 1 ; m != -1 ; m--){
        temp += powerTemp * mapping.at(s1[m]);
        powerTemp = power(powerTemp, 10);
    }
    powerTemp = 1;
    for(unsigned long m = s2.length() - 1 ; m != -1 ; m--){
        temp += powerTemp * mapping.at(s2[m]);
        powerTemp = power(powerTemp, 10);
    }
    powerTemp = 1;
    for(unsigned long m = s3.length() - 1 ; m != -1 ; m--){
        temp2 += powerTemp * mapping.at(s3[m]);
        powerTemp = power(powerTemp, 10);
    }
    
    if(temp == temp2) // if both values are equal, return true.
        return true;
    return false;
}


///TODO: CHECK IF SOLUTION WITH STACK HAS A BIGGER TIME COMPLEXITY.
/// Prototypes for a solution that used a stack that holds maps with possible solutions:
//bool emptyStack(std::string s1, std::string s2, std::string s3, std::stack<std::unordered_map<char, unsigned>> &stc, std::unordered_map<char, unsigned> &mapping){
//
//
//    if(stc.empty()) // base case: if stack is empty, returns false.
//        return false;
//
//
//    // recursive cases: pops one map of stack, verifies solution. If no solution was found, calls function recursively to check next value.
//    mapping = stc.top();
//    stc.pop();
//    if(verifySolution(s1, s2, s3, mapping))
//        return true;
//    return emptyStack(s1, s2, s3, stc, mapping);
//}

//bool fillStack(const std::string &s1, const std::string &s2, const std::string &s3, std::string letters, std::unordered_map<char, unsigned> &mapping, std::queue<int> &queue_l){
//    //TODO: CREATE A FUNCTION THAT RECURSIVELY CALLS EACH POSSIBLE CASE SCENARIO FOR AMOUNT OF LETTERS. THE FUNCTION SHOULD HAVE A LOOP FOR EACH RECURSION THAT WILL CALL A DIFFERENT LETTER. FOR EACH LETTER, THERE ARE 10 POSSIBLE CASES AND YOU SHOULD ADD A SET FOR PARAMETER TO DIMINISH TIME COMPLEXITY. IF A LETTER WAS ALREADY ASSIGNED TO A NUMBER, YOU WON'T USE THAT NUMBER AGAIN.
//    if(letters.empty()){ // base case
//        return verifySolution(s1, s2, s3, mapping);
//    }
//
//    // recursive case
//    mapping.insert_or_assign(letters[0], queue_l.front());
//    int x = queue_l.front();
//    queue_l.push(x);
//    queue_l.pop();
//
//    if(!fillStack(s1, s2, s3, letters.substr(1, letters.length()), mapping, queue_l)){
//        return fillStack(s1, s2, s3, letters, mapping, queue_l);
//    }
//    return true;
//}
