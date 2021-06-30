#include "Lexer.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(int argc, char** argv) {

    // TODO
    string input = "";
    ifstream in(argv[1]);
    string output;
    string full = "";
    while (getline(in,output)){
        full+=output;
        full+="\n";
    }
    cout << full;
    Lexer* lexer = new Lexer(full);
    delete lexer;

    return 0;
}