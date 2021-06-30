#ifndef MATCHERAUTOMATON_H
#define MATCHERAUTOMATON_H

#include "Automaton.h"

class MatcherAutomaton : public Automaton
{
private:
    std::string matchstr;
public:
    MatcherAutomaton(std::string toMatch, TokenType tokenType) : Automaton(tokenType) {
        matchstr = toMatch;
    }
    void S0(const std::string& input);
    int match(const std::string& input);
};

#endif // MULTIPLYAUTOMATON_H

