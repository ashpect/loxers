#include <string>
#include <vector>
#include "token_type.h"
#include "error.h"

class Scanner {
    public:
        const std::string source;
        std::vector<Token> tokens = {};
        int start = 0;
        int current = 0;
        int line = 1;

        Scanner(const std::string& source) : source(source) {}


        std::vector<Token> scanTokens() {

            while (!isAtEnd()) {
             //why do we need to reset start?
                start = current;
                scanToken();
            }

            //appends one final “end of file” token.
            tokens.push_back(Token(TOKEN_EOF, "", nullptr, line));
            return tokens;
        }

    private:

        bool isAtEnd() {
            return current >= source.length();

            //this is the same as:
            //if (current >= source.length()) {
            //    return true;
            //} else {
            //    return false;
            //}
        }

        void scanToken() {

            char c = advance();

            switch (c)
            {
            case '(': addToken(TOKEN_LEFT_PAREN);break;
            case ')': addToken(TOKEN_RIGHT_PAREN);break;
            case '{': addToken(TOKEN_LEFT_BRACE); break;
            case '}': addToken(TOKEN_RIGHT_BRACE); break;
            case ',': addToken(TOKEN_COMMA); break;
            case '.': addToken(TOKEN_DOT); break;
            case '-': addToken(TOKEN_MINUS); break;
            case '+': addToken(TOKEN_PLUS); break;
            case ';': addToken(TOKEN_SEMICOLON); break;
            case '*': addToken(TOKEN_STAR); break;
            case '!': addToken(match('=') ? TOKEN_BANG_EQUAL : TOKEN_AND); break;
            case '=': addToken(match('=') ? TOKEN_EQUAL_EQUAL : TOKEN_EQUAL); break;
            case '<': addToken(match('=') ? TOKEN_LESS_EQUAL : TOKEN_LESS); break;
            case '>': addToken(match('=') ? TOKEN_GREATER_EQUAL : TOKEN_GREATER); break;
            //handles comments
            case '/': if (match('/')) { while (peek() != '\n' && !isAtEnd()) advance();} else {addToken(TOKEN_SLASH);}
            //ignore these meaningless characters
            case ' ':
            case '\r':
                //Homework: handle \r
            case '\t':
                // Ignore whitespace.
                break;
            case '\n':
                line++;
                break;
            
            default:
                error(line,"Unexpected character.");
                break;
            }
        }

        //advance consumes the next character in the source code and returns it
        char advance() {
            current++;
            return source[current-1];
        }

        //match checks if the current character is the expected one
        bool match(char expected){
            if (isAtEnd()) return false;
            if (source[current] != expected) return false;

            current++;
            return true;
        }
        
        //peak finds the next character in the source code without consuming it
        char peek() {
            if (isAtEnd()) return '\0';
            return source[current];
        }

        //adds a token to the tokens vector
        //example of function overloading
        void addToken(TokenType type) {
            addToken(type, nullptr);
        }
        void addToken(TokenType type, const void* literal) {
            std::string text = source.substr(start, current-start);
            tokens.push_back(Token(type, text, literal, line));
        }



};

int main() {
    return 0;
}