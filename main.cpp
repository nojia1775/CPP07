#include <iostream>

int main() {
    double num1, num2;
    int op;

    for(int i = 0; i < 20; i++) {
            std::cout << "Entre un nombre : ";
    std::cin >> num1;
    std::cout << "\nEntre un autre nombre : ";
    std::cin >> num2;
    std::cout << "\nChoisis une operation :\n+[1]\n-[2]\n/[3]\n*[4]\n";
    std::cin >> op;

    double resultat;

    switch(op) {

        case 1 :
            resultat = num1 + num2;
            std::cout << "\nLe resultat est : " << resultat << "\n\n";
            break;

        case 2 :
            resultat = num1 - num2;
            std::cout << "\nLe resultat est : " << resultat << "\n\n";
            break;

        case 3 :
            resultat = num1 / num2;
            std::cout << "\nLe resultat est : " << resultat << "\n\n";
            break;

        case 4 :
            resultat = num1 * num2;
            std::cout << "\nLe resultat est : " << resultat << "\n\n";
            break;

        default : 
            break;
    }

    }

    return 0;
}