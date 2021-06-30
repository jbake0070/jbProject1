#include "StringAutomaton.h"
#include <iostream>
void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead = 1;
        S1(input);
    }
    else {
        Serr();
    }
}
void StringAutomaton::S1(const std::string& input) {
    index++;
    inputRead++;
    while((input[index] != '\'') && (index != input.length())){
        if(index == input.length()){
            Serr();
        }else{
            inputRead++;
            index++;
            }
    }
    if(input[index+1] == '\'') {
        index++;
        inputRead++;
        S1(input);
    }
}