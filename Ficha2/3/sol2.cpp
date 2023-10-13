//
// Created by gyaru on 29/09/2023.
//

#include <iostream>

using namespace std;


int multiplica(int a = 1, int b = 1, int c = 1){
    return a * b * c;
}

int main(){
    cout << "\n" << multiplica() << "\n" << multiplica(5);
    cout << endl << multiplica(2,3) << endl << multiplica(2,3,4);
}

//Resposta a C : O compilador falha a compilação do programa pois,
// como existem dois overloads da mesma função com argumentos de tipo semelhante,
// não é possível resolver a chamada de função sem ambiguidade.