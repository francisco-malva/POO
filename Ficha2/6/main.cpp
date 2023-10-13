//
// Created by gyaru on 29/09/2023.
//

#include <exception>
#include <iostream>

constexpr int TAB_SIZE = 16;


struct Tabela {
    int data[TAB_SIZE] = {0};

    void set_all(int val);
    void list();

    int& get_at(int pos);
};

void Tabela::set_all(int val) {
    for(auto& v : data){
        v = val;
    }
}

void Tabela::list() {

    std::cout << "[TABELA]\n\t";

    for(auto& v : data){

        if(&v == std::end(data) - 1){
            std::cout << v << ";\n";
        }
        else {
            std::cout << v << ", ";
        }
    }
}

int &Tabela::get_at(int pos) {

    if(pos < 0 || pos >= TAB_SIZE){
        throw std::out_of_range("Index out of range");
    }

    return data[pos];
}


int main(){

    Tabela tabela{};

    for(size_t i = 0; i < 100; i++){
        tabela.set_all(static_cast<int>(i));
        tabela.list();
    }


    try{
        for(int i = 0; i < 101; i++){
            tabela.get_at(i) *= i;
            std::cout << tabela.get_at(i) << '\n';
        }
    }
    catch(std::out_of_range& exception)
    {
        std::cerr << exception.what() << '\n';
    }


    return 0;
}
