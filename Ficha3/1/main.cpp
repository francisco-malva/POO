//
// Created by gyaru on 13/10/2023.
//

#include <cstdint>
#include <stdexcept>
#include <iostream>

#include "table.h"


template<typename SpanType>
void PrintSpan(std::span<SpanType> span){
    std::cout << "[TABELA]\n";

    for(size_t i = 0; i < span.size(); i++) {
        std::cout << '\t' << i << ": " << span[i] << '\n';
    }

    std::cout << "\n";
}

int main() {
    Table table{};

    std::cout << "Usando fill: \n";
    table.Fill(2);
    PrintSpan(table.GetSpan());


    std::cout << "Usando construtor:\n";
    table = Table(3);
    PrintSpan(table.GetSpan());

    //Só zeros
    std::cout << "Só zeros:\n";
    table = Table();
    PrintSpan(table.GetSpan());

    //Começa em A e progride em incrementos de B
    std::cout << "Em incrementos:\n";
    table = Table(2, 3);
    PrintSpan(table.GetSpan());

    //Usa o valor da lista inicializadora
    std::cout << "Com lista inicializadora:\n";
    table = Table({1,2,3,4,5});
    PrintSpan(table.GetSpan());

    return 0;
}
