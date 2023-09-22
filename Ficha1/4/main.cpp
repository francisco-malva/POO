#include <iostream>


std::string get_string(){
    std::string str{};

    std::getline(std::cin, str);

    return str;
}

int main(){

    std::string input{};
    std::string reversed{};

    bool running = true;

    while(running) {

        std::cout << "Insira uma palavra: ";

        std::getline(std::cin, input);

        if(input.empty())
        {
            continue;
        }

        if(input == "fim"){
            running = false;
        }
        else {
            reversed.clear();

            for(int i = static_cast<int>(input.length() - 1); i >= 0; i--) {
                reversed += input[i];
            }

            std::cout << reversed << (reversed == input ? ", palíndromo." : "") << '\n';


            std::cout << "Pressione ENTER para continuar...\n";

            while(std::cin.get() != '\n') {}
        }

    }

    return 0;
}