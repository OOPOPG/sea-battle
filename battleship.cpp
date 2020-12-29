#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Game.h"
#include "Bot.h"
using namespace std;


//створюємо бота
IPlayer* InitBotEasy()
{
    return new Bot();
}
//створюємо бота
IPlayer* InitBotMedium()
{
    return new Bot2();
}
//створюємо людину
IPlayer* InitHuman()
{
    return new Human();
}


int main()
{
    system("title Battle Ship");
    srand((unsigned int)time(nullptr));
    bool start = true;
    char ch;
    IPlayer* p_player1;
    IPlayer* p_player2;
    char mode;
    char bot_lvl;
    char bot_lvl_1;
    char bot_lvl_2;
    while (start)
    {
        system("CLS");
        cout << "Start game(1)" << endl << "Quit(0)" << endl;
        ch = getch();
        if (ch == '1')
        {
            while (start)
            {
                system("CLS");
                cout << "Choose game mode:"  << endl << "Human vs Bot(1)" << endl << "Bot vs Bot(2)" << endl;
                mode = getch();
                if (mode == '1')
                {
                    system("CLS");
                    cout << "Choose bot level:" << endl << "Easy(1)" << endl << "Medium(2)" << endl;
                    bot_lvl = getch();
                    if (bot_lvl == '1')
                    {
                        p_player2 = InitBotEasy();
                        p_player1 = InitHuman();
                    }
                    else if (bot_lvl == '2')
                    {
                        p_player2 = InitBotMedium();
                        p_player1 = InitHuman();
                    }
                    else
                    {
                        system("CLS");
                        cout << "See ya next time" << endl;
                        exit(0);
                    }



                }
                else if (mode == '2')
                {
                    system("CLS");
                    cout << "Choose bot_1 level:" << endl << "Easy(1)" << endl << "Medium(2)" << endl;
                    bot_lvl_1 = getch();
                    if (bot_lvl_1 == '1')
                    {
                        p_player1 = InitBotEasy();

                    }
                    else
                    {
                        p_player1 = InitBotMedium();

                    }
                    system("CLS");
                    cout << "Choose bot_2 level:" << endl << "Easy(1)" << endl << "Medium(2)" << endl;
                    bot_lvl_2 = getch();
                    if (bot_lvl_2 == '1')
                    {
                        p_player2 = InitBotEasy();

                    }
                    else
                    {
                        p_player2 = InitBotMedium();

                    }
                }
                else
                {
                    system("CLS");
                    cout << "See ya next time" << endl;
                    exit(0);
                }

                system("CLS");
                cout << "Game is started" << endl;
                Game g;
                g.SetPlayers(p_player1, p_player2);
                g.Start();
                g.PlayRound();
                g.Finish();
                delete p_player1;
                delete p_player2;
                system("pause");
                break;
            }

        }
        else
        {
            system("CLS");
            cout << "See ya next time" << endl;
            exit(0);
        }

    }

}