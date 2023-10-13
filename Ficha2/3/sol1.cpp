//
// Created by gyaru on 29/09/2023.
//

#include <iostream>

using namespace std;


int multiplica(){
    return 1;
}

int multiplica(int num){
    return num;
}

int multiplica(int n1, int n2){
    return n1 * n2;
}

int multiplica(int n1, int n2, int n3){
    return n1*n2*n3;
}

int main(){
    cout << "\n" << multiplica() << "\n" << multiplica(5);
    cout << endl << multiplica(2,3) << endl << multiplica(2,3,4);
}