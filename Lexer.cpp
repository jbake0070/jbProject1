#include "Lexer.h"
#include "ColonDashAutomaton.h"
#include "StringAutomaton.h"
#include "MatcherAutomaton.h"
#include "IdAutomaton.h"
#include "CommentAutomaton.h"
#include "BlockCommentAutomaton.h"
#include "UndefinedAutomaton.h"
#include "UndefinedStringAutomaton.h"
#include <cctype>
using namespace std;
#include <iostream>


Lexer::Lexer(string input1) {
    vector<Token*> tokens;
    CreateAutomata();
    Run(input1);
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    for(auto& itr: automata){
        delete itr;
    }
    for(auto itr: tokens){

    }
}

void Lexer::CreateAutomata() {

//    automata.push_back(new ColonAutomaton());

 //   automata.push_back(new EOFAutomaton());
//    automata.push_back(new CommaAutomaton());
//    automata.push_back(new PeriodAutomaton());
//    automata.push_back(new QMarkAutomaton());
//    automata.push_back(new RightParenAutomaton());
//    automata.push_back(new LeftParenAutomaton());
//    automata.push_back(new AddAutomaton());
//    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new UndefinedAutomaton());
    automata.push_back(new UndefinedStringAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new CommentAutomaton());

    automata.push_back(new BlockCommentAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new ColonDashAutomaton());

    automata.push_back(new MatcherAutomaton(":", TokenType::COLON));
    automata.push_back(new MatcherAutomaton(",", TokenType::COMMA));
    automata.push_back(new MatcherAutomaton(".", TokenType::PERIOD));
    automata.push_back(new MatcherAutomaton("?", TokenType::Q_MARK));
    automata.push_back(new MatcherAutomaton(")", TokenType::RIGHT_PAREN));
    automata.push_back(new MatcherAutomaton("(", TokenType::LEFT_PAREN));
    automata.push_back(new MatcherAutomaton("+", TokenType::ADD));
    automata.push_back(new MatcherAutomaton("*", TokenType::MULTIPLY));
    automata.push_back(new MatcherAutomaton("Schemes", TokenType::SCHEMES));
    automata.push_back(new MatcherAutomaton("Facts", TokenType::FACTS));
    automata.push_back(new MatcherAutomaton("Rules", TokenType::RULES));
    automata.push_back(new MatcherAutomaton("Queries", TokenType::QUERIES));




    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
        Token* newToken;
        int maxRead = 0;
        lineNumber = 1;
        int inputRead = 0;
        Automaton *maxAuto = automata[0];
        while(input.size()>1) {
            if((input.at(0) == '\n')) {
            lineNumber++;
            //input.erase(0,1);
            }
            while( (input.at(0) == '\t') || (input.at(0) == ' ') ){
                input.erase(0,1);
            }

            maxRead = 0;
            for (int i = 0; i < automata.size(); i++) {
                inputRead = automata[i]->Start(input);
                if(inputRead > maxRead){
                    maxRead = inputRead;
                    maxAuto = automata[i];
                }

            }
            if (maxRead > 0){
                newToken = maxAuto->CreateToken(input.substr(0,maxRead),lineNumber);
            }else{
                maxRead = 1;
                newToken = maxAuto->CreateInvalidToken(input.substr(0,maxRead),lineNumber);
            }
            if(input.at(0) != '\n') {
                tokens.push_back(newToken);
            }
            //lineNumber+=maxAuto->NewLinesRead();
            input.erase(0,maxRead);
        }
        Token* EOFToken = new Token(TokenType::ENDOFFILE,"",lineNumber);
        tokens.push_back(EOFToken);

        for(int i = 0; i < tokens.size(); i++) {
            cout << tokens.at(i)->toString();
        }

//}


    /*
    set lineNumber to 1

    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata

        // TODO: you need to handle whitespace inbetween tokens

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */
}
