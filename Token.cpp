#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    ttype = type;
    desc = description;
    linenum = line;
    // TODO: initialize all member variables
}
string Token::toString() {
    string output = "(";
    switch(ttype){
        case TokenType::UNDEFINED:
            output+= "UNDEFINED";
            break;
        case TokenType::COLON:
            output+= "COLON";
            break;
        case TokenType::COLON_DASH:
            output+= "COLON_DASH";
            break;
        case TokenType::ENDOFFILE:
            output+= "EOF";
            break;
        case TokenType::COMMA:
            output+= "COMMA";
            break;
        case TokenType::PERIOD:
            output+= "PERIOD";
            break;
        case TokenType::Q_MARK:
            output+= "Q_MARK";
            break;
        case TokenType::LEFT_PAREN:
            output+= "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            output+= "RIGHT_PAREN";
            break;
        case TokenType::MULTIPLY:
            output+= "MULTIPLY";
            break;
        case TokenType::ADD:
            output+= "ADD";
            break;
        case TokenType::SCHEMES:
            output+= "SCHEMES";
            break;
        case TokenType::FACTS:
            output+= "FACTS";
            break;
        case TokenType::RULES:
            output+= "RULES";
            break;
        case TokenType::QUERIES:
            output+= "QUERIES";
            break;
        case TokenType::ID:
            output+= "ID";
            break;
        case TokenType::STRING:
            output+= "STRING";
            break;
        case TokenType::COMMENT:
            output+= "COMMENT";
            break;


        default:
            return "what?";
            break;
    }

    output+=",\""+ desc +"\","+ to_string(linenum)+")\n";
    return output;
}