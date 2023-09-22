#include <iostream>
#include <unordered_map>

std::string get_string(){
    std::string str{};

    std::getline(std::cin, str);

    return str;
}

int main() {

    std::string input{};

    bool running = true;

    while(running) {

        std::cout << "Insira uma numero em extenso ou em formato decimal (0 a 10):";

        std::getline(std::cin, input);


        if(input == "fim"){
            running = false;
        }
        else{

            size_t idx = 0;

            try{
                int val = std::stoi(input, &idx, 0);

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

    return 0;
}