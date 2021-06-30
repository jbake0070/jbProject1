#ifndef UNDEFINEDSTRINGAUTOMATON_H
#define UNDEFINEDSTRINGAUTOMATON_H

#include "Automaton.h"

class UndefinedStringAutomaton : public Automaton
{
public:
    UndefinedStringAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
};

#endif // UNDEFINEDSTRINGAUTOMATON_H

