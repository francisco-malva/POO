//
// Created by gyaru on 22/09/2023.
//

#include <iostream>
#include <string>

int main(int argc, char* argv[]){

    std::string name{};
    int age{};


    std::cout << "Insira o seu nome: ";
    std::getline(std::cin, name);

    do{
        std::cout << "Por favor introduza a sua idade: ";

        if((std::cin >> age)) {
            break;
        }
        else {

            std::cout << "Introduziu um valor invalido!";

            std::cin.clear();
            std::cin.ignore(999, '\n');
        }
    } while(true);

    std::cout
        <<  "Voce chama-se "
        << name
        << " (um nome com "
        << name.size()
        << " caracteres, incluindo espaços) e tem "
        << age
        << (age == 1 ? " ano.\n" : " anos.\n");



    std::cout << "Nome impresso linha a linha: \n";

    for(char character : name) {

        if(std::isspace(character))
            continue;

        std::cout << '\t' << character << '\n';
    }
    return 0;
}
