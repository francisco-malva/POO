//
// Created by gyaru on 29/09/2023.
//

#include <iostream>

void list_vars(const char* label, int a, int b){
    std::cout << '[' << label << "]\n\ta = " << a << ", b = " << b << '\n';
}

int& seleciona(int& a, int&b, char code) {
    switch (code) {
        case 'm':
            return a < b ? a : b;
        case 'M':
            return a > b ? a : b;
        case 'p':
            return a;
        case 'u':
            return b;
        default:
            throw std::invalid_argument("bad character code");
    }
}


int main(){
    int a = 100, b = 80;

    list_vars("Normal", a, b);

    seleciona(a, b, 'm') -= 3;
    list_vars("Subtrair 3 ao menor", a, b);

    seleciona(a,b,'M') *= 3;
    list_vars("Multiplicar 3 ao maior", a,b);

    seleciona(a,b,'p') += 5;
    list_vars("Adicionar 5 ao primeiro", a,b);

    seleciona(a,b,'u') += 9;
    list_vars("Adicionar 9 ao ultimo", a,b);


    try{
        //Deve acionar uma exceção
        seleciona(a,b,'&');
    }
    catch(std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
    }



    return 0;
}