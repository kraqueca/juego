#include <iostream>
using namespace std;

void drawMap(int heroPosX, int heroPosY, char gameMap[5][5]){
    for (int i = 0; i < 5; i++){
            for (int p = 0; p < 5; p++){
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
    int heroPosX = 1;
    int heroPosY = 1;
    bool isGameOver = false;
    char input = ' ';
    char gameMap[5][5] = {
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'}
    };
    drawMap (heroPosX, heroPosY, gameMap);

    while (isGameOver == false){
        cin >> input;
        if (input == 'd'){
            heroPosX += 1;
        }else if(input == 'a'){
            heroPosX -= 1;
        }else if (input == 'w'){
            heroPosY -= 1;
        }else if(input == 's'){
            heroPosY += 1;
        }else if(input == 'p'){
            isGameOver = true;
        }
        drawMap (heroPosX, heroPosY, gameMap);
    }
    return 0;
}