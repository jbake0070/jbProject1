#include "CommentAutomaton.h"
#include <iostream>
using namespace std;

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        if(input[index+1] == '|'){
            cout<<"bruh";

            Serr();
        }
        inputRead = 1;
        S1(input);
    }
    else {
        Serr();
    }

}

void CommentAutomaton::S1(const std::string& input){
    while(input[index] != '\n'){
        index++;
        inputRead++;
    }
    inputRead--;
}