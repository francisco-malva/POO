//
// Created by gyaru on 29/09/2023.
//

#include <string>
#include <iostream>


void imprime(std::string str){
    std::cout << str << '\n';
}

void imprime(std::string str, int num){
    std::cout << str << ": " << num << '\n';
}

void imprime(int num, std::string str){
    std::cout << num << " - " << str << '\n';
}

int main(){
    imprime("programação orientada a objetos");
    imprime("horas por aula teórica ", 2);
    imprime(3, " horas em cada aula prática");
    return 0;
}
