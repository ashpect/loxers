#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <map>

enum TokenType {
    // Single-character tokens.
    TOKEN_LEFT_PAREN,TOKEN_RIGHT_PAREN,TOKEN_LEFT_BRACE,TOKEN_RIGHT_BRACE,
    TOKEN_COMMA,TOKEN_DOT,TOKEN_MINUS,TOKEN_PLUS,TOKEN_SEMICOLON,TOKEN_SLASH,TOKEN_STAR,

    // One or two character tokens.
    TOKEN_BANG,TOKEN_BANG_EQUAL,
    TOKEN_EQUAL,TOKEN_EQUAL_EQUAL,
    TOKEN_GREATER,TOKEN_GREATER_EQUAL,
    TOKEN_LESS,TOKEN_LESS_EQUAL,

    // Literals.
    TOKEN_IDENTIFIER,TOKEN_STRING,TOKEN_NUMBER,

    // Keywords.
    TOKEN_AND,TOKEN_CLASS,TOKEN_ELSE,TOKEN_FALSE,TOKEN_FUN,TOKEN_FOR,TOKEN_IF,TOKEN_NIL,TOKEN_OR,
    TOKEN_PRINT,TOKEN_RETURN,TOKEN_SUPER,TOKEN_THIS,TOKEN_TRUE,TOKEN_VAR,TOKEN_WHILE,
    TOKEN_EOF 
    
};

//Identifiers

std::map<std::string, TokenType> keywords =
{
    {"and", TokenType::TOKEN_AND},
    {"class", TokenType::TOKEN_CLASS},
    {"else", TokenType::TOKEN_ELSE},
    {"false", TokenType::TOKEN_FALSE},
    {"for", TokenType::TOKEN_FOR},
    {"fun", TokenType::TOKEN_FUN},
    {"if", TokenType::TOKEN_IF},
    {"nil", TokenType::TOKEN_NIL},
    {"or", TokenType::TOKEN_OR},
    {"print", TokenType::TOKEN_PRINT},
    {"return", TokenType::TOKEN_RETURN},
    {"super", TokenType::TOKEN_SUPER},
    {"this", TokenType::TOKEN_THIS},
    {"true", TokenType::TOKEN_TRUE},
    {"var", TokenType::TOKEN_VAR},
    {"while", TokenType::TOKEN_WHILE},
};

class Token {
    public: 
        const TokenType type;
        const std::string lexeme;
        const void* literal;
        const int line;

        Token(TokenType type, const std::string& lexeme, const void* literal, int line)
            : type(type), lexeme(lexeme), literal(literal), line(line) {}

        std::string toString() const {
            return std::to_string(static_cast<int>(type)) + " " + lexeme ;
            //+ " " + std::to_string(reinterpret_cast<std::intptr_t>(literal))  //ask doubt
        }
};

#endif