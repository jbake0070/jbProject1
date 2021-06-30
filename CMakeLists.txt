cmake_minimum_required(VERSION 3.10.2)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp  ColonDashAutomaton.cpp ColonDashAutomaton.h Lexer.cpp Lexer.h Token.cpp Token.h StringAutomaton.cpp StringAutomaton.h MatcherAutomaton.cpp MatcherAutomaton.h IdAutomaton.cpp IdAutomaton.h CommentAutomaton.cpp CommentAutomaton.h BlockCommentAutomaton.cpp BlockCommentAutomaton.h UndefinedAutomaton.cpp UndefinedAutomaton.h UndefinedStringAutomaton.cpp UndefinedStringAutomaton.h)