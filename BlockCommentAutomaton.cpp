#include "BlockCommentAutomaton.h"
#include <iostream>

void BlockCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void BlockCommentAutomaton::S1(const std::string& input){
    if(input[index] == '|'){
        index++;
        inputRead++;
        S2(input);
    }else{
        Serr();
    }
}
void BlockCommentAutomaton::S2(const std::string& input) {
    while ((input[index] != '|') && (index !=input.length())){
        index++;
        inputRead++;
    }
    if(index == input.length()){
        Serr();
    }else{
        index++;
        inputRead++;
        S3(input);
    }

}

void BlockCommentAutomaton::S3(const std::string& input){
    if(input[index] != '#') {
        S2(input);
    }
    index+=2;
    inputRead+=2;
}