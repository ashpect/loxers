#include <token_type.hpp>

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