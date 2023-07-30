#include <iostream>

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cout<<"Usage: cpplox [script]" <<std::endl;
        std::cout<<"Usage for REPL mode : cpplox" <<std::endl;
		std::exit(64);
    } else if (argc == 2) {
        std::cout<<argv[1]<<std::endl;
        //runFile(argv[1]);
    } else {
        //runPrompt();
    }
}