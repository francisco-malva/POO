#include <iostream>
#include <fstream>
#include <unordered_map>

std::string get_string(){
    std::string str{};

    std::getline(std::cin, str);

    return str;
}


void process_stream(std::istream& stream){

    std::string input{};

    while(!stream.eof()){

        std::getline(stream, input);

        try{
            int val = std::stoi(input, nullptr, 0);

            if(val < 0 || val > 10){
                std::cout << "Valor tem de estar entre 0 e 10!" << '\n';
                continue;
            }
            else{
                static const char* Values[] = {
                        "zero",
                        "um",
                        "dois",
                        "tres",
                        "quatro",
                        "cinco",
                        "seis",
                        "sete",
                        "oito",
                        "nove",
                        "dez"
                };

                std::cout << Values[val] <<'\n';
            }
        }
        catch(...) {
            static const std::unordered_map<std::string, int> TextToNumber{
                    {"zero", 0},
                    {"um", 1},
                    {"dois", 2},
                    {"tres", 3},
                    {"quatro", 4},
                    {"cinco", 5},
                    {"seis", 6},
                    {"sete", 7},
                    {"oito", 8},
                    {"nove", 9},
                    {"dez", 10}
            };


            if(TextToNumber.find(input) != TextToNumber.end()){
                std::cout << TextToNumber.at(input) << '\n';
            }
            else{
                std::cout << "Forma em extenso inválida!" << '\n';
            }
        }
    }


}

int main() {
    std::string input{};

    bool running = true;

    while(running) {

        std::cout << "Insira o nome de um ficheiro:";

        std::getline(std::cin, input);


        if(input == "fim"){
            running = false;
        }
        else {

            std::ifstream file{input};

            if(file.good()){
                process_stream(file);
            }
            else{
                std::cerr << "Erro ao abrir o ficheiro!\n";
            }
        }

    }

    return 0;
}


