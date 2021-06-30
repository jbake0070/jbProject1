#include "UndefinedStringAutomaton.h"

void UndefinedStringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead = 1;
        S1(input);
    }
    else {
        Serr();
    }
}
void UndefinedStringAutomaton::S1(const std::string& input) {
    index++;
    inputRead++;
    while((input[index] != '\'') && (index != input.length())) {
        inputRead++;
        index++;

        if (input[index + 1] == '\'') {
            Serr();

        }
    }
}