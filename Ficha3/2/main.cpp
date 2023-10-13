//
// Created by gyaru on 13/10/2023.
//

#include <iostream>

#include "automovel.h"

int main(){

    automobile suzuki{"Suzuki",
                      "Swift",
                      fuel_type::diesel,
                      registration{00,'E', 'P', 87},
                      2007};

    suzuki.print(std::cout);

    suzuki.set_registration(registration{12,'a', 'i', 34});

    suzuki.print(std::cout);
    return 0;
}