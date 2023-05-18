#include <iostream>
#include <vector>
#include <random>

int main() {
    std::vector<std::string> names;
    std::string name;
    int luckyCount;

    std::cout << "Cekilis icin isimleri girin (Cikmak icin 'q' ya da 'Q' girin):\n";

    while (true) {
        std::cout << "Ýsim: ";
        std::getline(std::cin, name);

        if (name == "q" || name == "Q") {
            break;
        }

        names.push_back(name);
    }

    std::cout << "Kac sansli kisi secmek istersiniz? ";
    std::cin >> luckyCount;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0, names.size() - 1);

    std::cout << "Kazananlar:\n";

    for (int i = 0; i < luckyCount; ++i) {
        int randomIndex = uni(rng);
        std::cout << names[randomIndex] << std::endl;
        names.erase(names.begin() + randomIndex);
    }

    return 0;
}

