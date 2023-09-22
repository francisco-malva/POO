#include <iostream>
#include <unordered_map>


static const std::unordered_map<std::string, int> ComparisonMap = {
        {"zero",0},
        {"um", 1},
        {"dois", 2},
        {"tres", 3},
        {"quatro", 4},
        {"cinco", 5},
        {"seis", 6},
        {"sete", 7},
        {"oito", 8},
        {"nove", 9},
        {"dez", 10}
};

bool get_number(std::string& input, int* out){

    try{

        int val = stoi(input, nullptr,0);

        if(out) {
            *out = val;
        }

        return true;
    }
    catch(...) {
        return false;
    }
}

int main() {

    std::string input{};

    bool wrote_number{}, wrote_text{};

    std::string ext{};
    int val{};

    bool running = true;

    while(running) {

        std::cout << "Insira uma numero em extenso ou em formato decimal (0 a 10):";

        std::getline(std::cin, input);


        if(input == "fim"){
            running = false;
            continue;
        }
        else if(get_number(input, &val))
        {
            if(wrote_number) {
                std::cout << "\nO numero em decimal ja foi escrito!\n";
            }
            else if(val < 0 || val > 10){
                std::cout << "\nO numero e invalido!\n";
            }
            else {
                wrote_number = true;
            }
        }
        else {
            if(ComparisonMap.find(input) == ComparisonMap.end()){
                std::cout << "\nEste numero em extenso e invalido!\n";
            }
            else if(wrote_text) {
                std::cout << "\nO numero em extenso ja foi escrito!\n";
            }
            else{
                ext = input;
                wrote_text = true;
            }

        }

        if(wrote_text && wrote_number){

            int correctVal = ComparisonMap.at(ext);

            std::cout << (correctVal == val ? "Certo" : "Errado") << "\n";
            wrote_text = wrote_number = false;
        }

    }

    return 0;
}