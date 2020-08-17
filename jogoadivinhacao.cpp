#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
    srand(time(NULL));
    const int SECRET_NUMBER = rand() % 100;;
    int kick = 0;
    int win = 0;
    int attemptCount = 1;
    int difficulty = 0;
    char level;
	double point = 1000;
	
    cout << "*******************************************" << endl;	
    cout << "*    Bem vindo ao Jogo de Adivinhação!    *" << endl;
    cout << "*******************************************" << endl;

    
    cout << "Qual o nível de dificuldade?" << endl;
    cout << "(F) Fácil (M) Médio (D) Difícil" << endl;
    cout << "Escolha: " << endl;
    cin >> level;
    
    switch(level)
    {
        case 'F':
            difficulty = 20;
            break;
        case 'M':
            difficulty = 13;
            break;
        default:
            difficulty = 6;
            break;
    }
    
    for(int i = 0; i < difficulty && !win; i++)
    {
         cout << "Tentativa " << attemptCount << endl;
        do
        {
            cout << "Qual é o seu chute? " << endl;
            cin >> kick;
            cout << "Seu chute foi, " << kick << endl;
            if(kick < 0)
            {
                cout << "Você não pode chutar números negativos!" << endl;
            }
        }while(kick < 0);
        
        if(SECRET_NUMBER == kick)
        {
            win = 1;
        }
        else
        {
            cout << "Você errou!" << endl;
            cout << "Mas não desanime, tente de novo e para isso vou te dar uma dica!" << endl;
        
            if(SECRET_NUMBER > kick)
            {
                cout << "Seu chute foi menor que o número secreto!" << endl;
            }
            else
            {
                cout << "Seu chute foi maior que o número secreto!" << endl;
            }
        }
        attemptCount++;
        point = point - abs(kick - SECRET_NUMBER) / 2.0;
    }
    //print end game
    cout << "*****************************************" << endl;
    cout << "************* Fim do jogo!! *************" << endl;
    cout << "*****************************************" << endl;
    
    if(win)
    {
        cout << "Parabéns! Você acertou!" << endl;
        cout << "Você gastou " << attemptCount << " tentativas!" << endl;
        cout << "Total de pontos: " << point << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Jogue de novo, você é um bom jogador!" << endl;
    }
    else
    {
        cout << "Infelismente não foi dessa vez, você perdeu!!" << endl;
    }
    return 0;
}