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
    int heroPos = 0;
    char gameMap[5] = {'1', '1', '1', '1', '1'};
    drawMap (heroPos, gameMap);
    return 0;
}