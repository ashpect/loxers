#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "token_type.h"
#include "common.h"


using namespace std;

void runFile(std::string filePath);
void runPrompt();
void run(std::string source);

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cout<<"Usage: cpplox [script]" <<std::endl;
        std::cout<<"Usage for REPL mode : cpplox" <<std::endl;
		std::exit(64);
    } else if (argc == 2) {
        runFile(argv[1]);
    } else {
        runPrompt();
    }
}

void runFile(std::string filePath) {
	std::cout<<"runFile";

    //std::ios::binary is flag used to read the file in binary mode
    std::ifstream file(filePath, std::ios::binary);
    //Handle error
    if (!file) {
        std::cout << "Error opening file" << std::endl;
        exit(1);
    }

    //creates oss object to store the file content
    std::ostringstream oss;
    //reads the file and stores it in oss object
    oss << file.rdbuf();
    //converts the oss object to string
    std::string content = oss.str();

    //Error check
    if (hadError){
        std::exit(65);
    }
    //run(content);
    return;

}

void runPrompt() {
    std::cout<<"runPrompt";
    std::string line;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        if (line == "exit" || line.empty()) {
            break;
        }
        //run(line);
        hadError = false;
    }
    return;
}


void run(std::string source) {

    //Onject of Scanner class
    //Scanner scanner = new Scanner(source);
    //std::vector<Token> tokens = scanner.scanTokens();

    std::cout<<"Testing";
    // for (Token token : tokens) {
    //     std::cout << token << std::endl;
    // }
    return;
}




