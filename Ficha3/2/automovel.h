//
// Created by gyaru on 13/10/2023.
//

#ifndef POO_AUTOMOVEL_H
#define POO_AUTOMOVEL_H

#include <cstdint>

#include <string>
#include <string_view>
#include <ostream>

enum class fuel_type : std::uint8_t {
    unknown,
    gasoline,
    diesel
};


const char* fuel_type_to_str(fuel_type type);

class registration {
private:
    std::uint8_t _m_num1{ 99 };
    char _m_letters[2]{ 'N', 'A' };
    std::uint8_t _m_num2{ 00 };
public:
    registration() = default;
    registration(std::uint8_t num1, char letter1, char letter2, std::uint8_t num2);

    void print(std::ostream& out);
};

class automobile {
private:
    std::string _m_maker, _m_model;
    fuel_type _m_fuel_type;
    registration _m_registration;
    std::uint16_t _m_year;
public:
    automobile(std::string_view maker, std::string_view model, fuel_type fuelType, registration registration, std::uint16_t year);



    void set_registration(registration newRegistration);

    void print(std::ostream& out);
};


#endif //POO_AUTOMOVEL_H
