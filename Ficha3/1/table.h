//
// Created by gyaru on 13/10/2023.
//

#ifndef POO_TABLE_H
#define POO_TABLE_H

#include <span>
#include <initializer_list>

class Table {
private:
    static constexpr size_t TABLE_SIZE = 10;

private:
    int _m_table[TABLE_SIZE]{};

    static void SayHi();
public:

    Table();

    ~Table();

    explicit Table(int val);
    Table(int a, int b);
    Table(std::initializer_list<int> list);

    void Fill(int value);
    int& At(size_t idx);

    bool HasInstanceOf(int val);
    bool Equals(Table& other);

    [[nodiscard]] std::span<int> GetSpan();
};

#endif //POO_TABLE_H
