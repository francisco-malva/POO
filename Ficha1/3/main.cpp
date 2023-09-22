#include <iostream>
#include <string>
#include <sstream>


std::string get_string() {
    std::string str{};

    std::getline(std::cin, str);

    return str;
}

int main(int argc, char* argv[]){
    std::istringstream sstream{get_string()};

    std::string name{};

    while(!sstream.eof()) {
        std::getline(sstream, name, ' ');

        if(name == "Fernando"){
            std::cout << "Hmm... Fernando? Eu conheco-te.\n";
        }
        else{
            std::cout << name << '\n';
        }
    }
    return 0;
}