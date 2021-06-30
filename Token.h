#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using namespace std;
enum class TokenType {
    COLON,
    COLON_DASH,
    UNDEFINED,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    ENDOFFILE
};

class Token
{
private:
    TokenType ttype;
    string desc;
    int linenum;
    // TODO: add member variables for information needed by Token

public:
    Token(TokenType type, std::string description, int line);
    string toString();


};


#endif // TOKEN_H

