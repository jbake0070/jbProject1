#include "UndefinedAutomaton.h"

void UndefinedAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void UndefinedAutomaton::S1(const std::string& input){
    if(input[index] == '|'){
        index++;
        inputRead++;
        S2(input);
    }else{
        Serr();
    }
}
void UndefinedAutomaton::S2(const std::string& input) {
    while ((input[index] != '|') && (index !=input.length())){
        index++;
        inputRead++;
    }
    if(index == input.length()){
        index++;
        inputRead++;
    }else{
        Serr();
    }

}
