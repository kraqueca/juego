#include <iostream>
using namespace std;

void drawMap(int heroPos, char gameMap[5]){
    for (int i = 0; i < 5; i++){
        if(i != heroPos){
            cout << gameMap [i];
        }else{
            cout << 'H';
        }
    }
}

int main (){
    int heroPos = 1;
    bool isGameOver = false;
    char input = ' ';
    char gameMap[5] = {'1', '1', '1', '1', '1'};
    drawMap (heroPos, gameMap);

    while (isGameOver == false){
        cin >> input;
        if (input == 'd'){
            heroPos += 1;
        }else if(input == 'a'){
            heroPos -= 1;
        }else if(input == 'p'){
            isGameOver = true;
        }
        drawMap (heroPos, gameMap);
    }
    return 0;
}