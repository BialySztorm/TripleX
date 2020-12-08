#include <iostream>
#include <ctime>

void PlayGameAtDifficulty(int & difficulty)
{
    std::cout<<"Jestes tajnym agentem wlamujacym sie na pietro "<<difficulty-1<<" organizacji przestepczej Hydra\n";
    std::cout<<"Twoj UltraHacker 3000 mowi ci zebys sledzil informacje...\n";

    srand(time(NULL));// tworzy nowa randomowa sekwencje bazujac na godzinei dnia
    const int CodeA = rand() % difficulty + difficulty;
    const int CodeB = rand() % difficulty + difficulty;
    const int CodeC = rand() % difficulty + difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProdukt = CodeA * CodeB * CodeC;

    std::cout<<std::endl;
    std::cout<< "+ Sa 3 liczby w kodzie\n";
    std::cout<< "+ pomnozono kod by dostac: "<<CodeProdukt<<std::endl;
    std::cout<< "+ dodane liczby kodu to: "<< CodeSum<<std::endl;

    std::cout<<std::endl;
    std::cout<< "Wprowadz 3 liczby kodu zakonczone X\n";
    std::cout<<std::endl;

    int CodeAnswer;
    int TrialSum = 0;
    int TrailProduct = 1;

    bool koniec = 0;

    while(std::cin >> CodeAnswer)
    {
        if (CodeAnswer==0)
        {
            koniec = 1;
            break;
        }
        TrialSum += CodeAnswer;
        TrailProduct *= CodeAnswer;
    }

    if (koniec == true)
    {
        difficulty = 15;
    }
    else
    {
    system("cls");

    std::cout<<std::endl;
    if(TrialSum == CodeSum && TrailProduct == CodeProdukt)
    {
        std::cout<<"Gratulacje!!! Przechodzisz na kolejne pietro tajnej organizacji Hydra\n";
        std::cout<<"=====================================================================\n";
    }
    else
    {
        std::cout<<"BOOM! Odnalezli cie straznicy Hydry i zadzgali na smierc\n";
        difficulty = 1;
    } 
    std::cout<<std::endl;
    system("pause");
    system("cls");
    }
}

int main()
{
    setlocale( LC_ALL, "pl_PL" );
    int difficulty = 2;
    int maxDifficulty = 11;
    while (difficulty <= maxDifficulty)
    {
        PlayGameAtDifficulty(difficulty);
        std::cin.clear();
        std::cin.ignore();
        ++difficulty;
    }
    if(difficulty>13)
        return 0;
    std::cout << "WOW = jestes lepszy niz Hydra!\n";
    system("pause");
    return 0;
}
