#include "IdAutomaton.h"


void IdAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead = 1;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomaton::S1(const std::string& input){
    while(isalpha(input[index]) || isalnum(input[index])  ){
            inputRead++;
            index++;
    }
    inputRead--;
    if(input.substr(0,index) == "Queries"){
        Serr();
    }
    if(input.substr(0,index) == "Rules"){
        Serr();
    }
    if(input.substr(0,index) == "Facts"){
        Serr();
    }
    if(input.substr(0,index) == "Schemes"){
        Serr();
    }


}