//
// Created by gyaru on 13/10/2023.
//

#include <cctype>
#include "automovel.h"

registration::registration(std::uint8_t num1, char letter1, char letter2, std::uint8_t num2) :
_m_num1{num1},
_m_num2{num2}
{
    _m_letters[0] = static_cast<char>(std::toupper(letter1));
    _m_letters[1] = static_cast<char>(std::toupper(letter2));
}

void registration::print(std::ostream &out) {
    out << int(_m_num1) << '-' << _m_letters[0] << _m_letters[1] << '-' << int(_m_num2);
}

automobile::automobile(std::string_view maker,
                       std::string_view model,
                       fuel_type fuelType,
                       registration registration,
                       std::uint16_t year) :
        _m_maker{maker},
        _m_model{model},
        _m_fuel_type{fuelType},
        _m_registration{registration},
        _m_year{year}
{

}

void automobile::print(std::ostream &out) {
    out << "MARCA: " << _m_maker << '\n'
        << "MODELO: " << _m_model << '\n'
        << "TIPO DE COMBUSTIVEL: " << fuel_type_to_str(_m_fuel_type) << '\n'
        << "ANO DE FABRICO: " << _m_year << '\n'
        << "MATRICULA: ";

    _m_registration.print(out);

    out << '\n';
}

void automobile::set_registration(registration newRegistration) {
    _m_registration = newRegistration;
}

const char *fuel_type_to_str(fuel_type type) {
    switch (type) {

        case fuel_type::unknown:
            return "Desconhecido";
        case fuel_type::gasoline:
            return "Gasolina";
        case fuel_type::diesel:
            return "Gasoleo";
    }
}
