//
// Created by gyaru on 29/09/2023.
//

#include "other.h"

using DataStore::dadosSaoValidos;

int main(int argc, char* argv[]){

    bool foo = dadosSaoValidos(std::string{});
    bool bar = UserInterface::dadosSaoValidos(std::string{});
    return 0;
}
