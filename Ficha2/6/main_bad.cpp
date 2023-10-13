//
// Created by gyaru on 29/09/2023.
//

#include <exception>
#include <iostream>

constexpr int TAB_SIZE = 16;


struct Tabela {
    int data[TAB_SIZE] = {0};
};

void set_all(Tabela& tab, int val) {
    for(auto& v : tab.data){
        v = val;
    }
}

void list(Tabela& tab) {

    std::cout << "[TABELA]\n\t";

    for(auto& v : tab.data){

        if(&v == std::end(tab.data) - 1){
            std::cout << v << ";\n";
        }
        else {
            std::cout << v << ", ";
        }
    }
}

int& get_at(Tabela& tab, int pos) {

    if(pos < 0 || pos >= TAB_SIZE){
        throw std::out_of_range("Index out of range");
    }

    return tab.data[pos];
}


int main(){

    Tabela tabela{};

    for(size_t i = 0; i < 100; i++){
        set_all(tabela, static_cast<int>(i));
        list(tabela);
    }


    try{
        for(int i = 0; i < 101; i++){
            get_at(tabela, i) *= i;
            std::cout << get_at(tabela, i) << '\n';
        }
    }
    catch(std::out_of_range& exception)
    {
        std::cerr << exception.what() << '\n';
    }


    return 0;
}
