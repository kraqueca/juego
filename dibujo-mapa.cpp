#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void drawMap(int heroPosX, int heroPosY, char gameMap[11][11]){
    for (int i = 0; i < 11; i++){
            for (int p = 0; p < 11; p++){
            if(i != heroPosY){
                cout << gameMap [p][i];
            }else{
                if (p != heroPosX){
                    cout << gameMap [p][i];
                }else{
                    cout << 'H';   
                }
            }
        }   
        cout << endl;
    }
}

int main (){
    int heroPosX = 0;
    int heroPosY = 0;
    bool isGameOver = false;
    char input = ' ';
    char newGame = ' ';
    char gameMap[11][11] = {
        {'E','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','1','1','1','S'},
    };

    string line;
    ifstream mapaSaveRead("mapaSave.txt");
    getline(mapaSaveRead, line);
    if (mapaSaveRead.is_open()){
        if ( line == "MAPA RAPIDOSO COMPROBADO"){
            for (int lol = 0; lol<2; lol++){
                getline(mapaSaveRead, line);
                switch(lol){
                    case 0: heroPosX = stoi(line);
                    break;
                    case 1: heroPosY = stoi(line);
                    break;
                    mapaSaveRead.close();
                }
            }
        }
    }    
    cout << "Presiona las teclas awsd para poder moverte; Ganas cuando llegas a S" << endl;
    drawMap (heroPosX, heroPosY, gameMap);

    
    while (isGameOver == false){
        cin >> input;
        switch (input){
        case 'd':
            heroPosX += 1;            
            break;
        case 'a':
            heroPosX -= 1;
            break;
        case 'w':
            heroPosY -= 1; 
            break;
        case 's':
            heroPosY += 1;
            break;          
        }
        switch(heroPosX){
            case-1: heroPosX += 1;
                break;
            case 11: heroPosX -= 1;
                break;
        }
        drawMap (heroPosX, heroPosY, gameMap);           
        switch(heroPosY){
            case-1: heroPosY += 1;
                break;
            case 11: heroPosY -= 1;
                break;
            }

        if (heroPosX == 10 && heroPosY == 10){
            cout << "Felicidade, has llegado a la meta" << endl;
            cout << " "<<endl;
            cout << "¿Quieres volver a jugar? (y/n)"<<endl;
            cin >> newGame;
            if (newGame == 'n'){
                isGameOver == true;
                break;
            }
            system("clear");
            heroPosX = 0;
            heroPosY = 0;
            drawMap (heroPosX, heroPosY, gameMap);
        }
    ofstream mapaSaveWrite("mapaSave.txt");
    mapaSaveWrite << "MAPA RAPIDOSO COMPROBADO" << endl;
    mapaSaveWrite << heroPosX << endl;
    mapaSaveWrite << heroPosY << endl;
    mapaSaveWrite.close();
    }
    return 0;
}

