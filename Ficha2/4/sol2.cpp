//
// Created by gyaru on 29/09/2023.
//
#include <iostream>

void troca(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void list_vars(int a, int b){
    std::cout << "\na = " << a << ", b = " << b << '\n';
}
int main(){
    int a = 2, b = 3;

    list_vars(a, b);

    troca(a, b);

    list_vars(a, b);

    return 0;
}


//Resposta à alínea b: Todos os parâmetros em funções C são passados copiando o valor introduzido na função.
//Por isso, para ser possível modificar diretamente o valor de uma variável fora do escopo da função,
//é necessário passar um ponteiro ao seu endereço de memória e operar nele.