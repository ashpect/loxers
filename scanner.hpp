#include <string>
#include <vector>
#include "token_type.hpp"
#include "error.hpp"

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
            case '"': string(); break;   
            default:
                if (isDigit())
                {
                    number();
                }
                else if(isAlpha(c)) {
                    identifier();
                }
                else{
                    error(line,"Unexpected character.");
                    break;
                }
                
            }
        };

        void identifier() {
            while (isAlphaNumeric(peek())) advance();

            std::string text = source.substr(start, current-start);

            TokenType type = keywords[text];
            TokenType* ptr = &type;

            if (ptr == nullptr) type = TOKEN_IDENTIFIER;
            addToken(type);
        }

        bool isAlpha(char c) {
            return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
        }

        bool isAlphaNumeric(char c) {
            return (isAlpha(c) || isDigit());
        }

        bool isDigit(){
            return (source[current] >= '0' && source[current] <= '9');
            //compares ascii code bw 48 and 57
        }

        void number(){

            //while(end not reached and {next character is a digit or a decimal point with a digit followed})
            while((!isAtEnd()) && ((peek() >= '0' && peek() <= '9') || (peek() == '.' && isDigitNext()))){
                advance();
            }

            //gave double as a literal type
            double value = std::stod(source.substr(start, current-start));
            addToken(TOKEN_NUMBER, &value);
        }

        bool isDigitNext() {
            if (current+1 >= source.length()) return false;
            return (source[current+1] >= '0' && source[current+1] <= '9');
        }

        void string() {

            while (peek() != '"' && !isAtEnd())
            {
                //If someone writes a string without closing it and closes it in the next line.
                //supports multi-line strings.
                if (peek() == '\n') line++;
                advance();
            }
            
            //in case you run out of source code before finding the closing quote
            if (isAtEnd())
            {
                error(line, "Unterminated string.");
                return;
            }

            //Take in the closing ", basically you can also just do current++ or even just trim with current-start-1 and then current++.
            advance();
            
            //Trim the surrounding quotes
            std::string value = source.substr(start+1, current-start-2);

            addToken(TOKEN_STRING,&value);

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
