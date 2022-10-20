#include <iostream>

int main() {
    std::string question[] = {
            "1. What is the name of the network of computers from which the Internet has emerged?",
            "2. In what year was Google launched on the web?",
            "3. What is the country top-level domain of Belgium?",
            "4. Which unit is an indication for the sound quality of MP3?"
    };

    std::string answers[][4]{
        {"A- Arpanet", "B- arnet","C- net", "D- et"},
        {"A- 1998", "B- 1900","C- 1989", "D- 1999"},
        {"A- The .bel domain", "B- The .e domain","C- The .be domain", "D- The .ble domain"},
        {"A- bps", "B- Kbps","C- Gbps", "D- Mbps"},
    };

    char ansKey[] {'A','B','C','D'};
    char geuss;
    int score;
    bool correct;

    for (int i = 0; i < sizeof(question)/sizeof(question[0]); ++i) {
        std::cout << question[i] << std::endl;
        std::cout << "******************************\n";
        for(int j = 0; j < sizeof(answers[i])/ sizeof(answers[i][0]); j++){
            std::cout << answers[i][j] << std::endl;
        }
        do {
            std::cout << "******************************\n";
            std::cout << ">>> ";
            std::cin >> geuss;
            if (geuss != 'A' && geuss != 'B' && geuss != 'C' && geuss != 'D'){
                std::cout << "This character cant recognize! Try again...\n";
                correct = false;
            }else{
                correct = true;
            }
        } while (correct != true);

        if (geuss != ansKey[i]){
            std::cout << "Wrong\n";
            std::cout << "******************************\n";
        } else{
            std::cout << "Correct\n";
            std::cout << "******************************\n";
            score++;
        }
    }

    std::cout << score;
    return 0;
}
