#include "MatcherAutomaton.h"

int MatcherAutomaton::match(const std::string& input) {
    bool isMatch = true;
    inputRead = 0; // member variable inherited from Automaton class
    for (int i = 0; i < (int)matchstr.size() && isMatch; i++) {
        if (input[i] != matchstr[i]) {
            isMatch = false;
        }
    }
    if (isMatch) {
        inputRead = matchstr.size();
    }
    return inputRead;
}

void MatcherAutomaton::S0(const std::string &input) {
    match(input);
}
