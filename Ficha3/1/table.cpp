//
// Created by gyaru on 13/10/2023.
//

#include <stdexcept>
#include <iostream>

#include "table.h"

void Table::Fill(int value) {

    for(int& val : _m_table){

        val = value;
    }
}

int &Table::At(size_t idx) {
    if(idx >= TABLE_SIZE){
        throw std::out_of_range("Out of range access on table.");
    }

    return _m_table[idx];
}

std::span<int> Table::GetSpan() {
    return _m_table;
}

Table::Table(int val) {
    Fill(val);

    SayHi();
}

Table::Table(int a, int b) {
    for(size_t i = 0; i < TABLE_SIZE; i++){
        _m_table[i] = a + static_cast<int>(b * i);
    }

    SayHi();
}

Table::Table(std::initializer_list<int> list) {

    size_t pos = 0;

    for(const int val : list) {
        _m_table[pos] = val;

        ++pos;

        if(pos >= TABLE_SIZE)
            return;
    }

    SayHi();
}

bool Table::HasInstanceOf(int val) {

    for(auto t : _m_table) {
        if(t == val) {
            return true;
        }
    }

    return false;
}

bool Table::Equals(Table &other) {
    for(size_t i = 0; i < TABLE_SIZE; i++){

        if(other._m_table[i] != _m_table[i]){
            return false;
        }
    }

    return true;
}

Table::~Table() {
    std::cout << "A tabela morreu :(\n";
}

void Table::SayHi() {
    std::cout << "Bom dia, eu sou a tabela!\n";
}

Table::Table() {

    SayHi();
}
