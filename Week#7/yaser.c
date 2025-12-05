#include <stdio.h>

const int MAX_STUDENTS = 30;
//define variables
int n , m;
int yaserX , yaserY , yaserType;
int numberOfStudents;

void checkYaserNeighbor(int x, int y, int type);
void yaserMove();
int checkTouch(int x, int y);
void studentMove(int &x, int &y, int &type);

int main() {
    scanf("%d %d" , &n , &m);
    scanf("%d %d %d", &yaserX , &yaserY , &yaserType);
    scanf("%d" , &numberOfStudents);

    int studentX[MAX_STUDENTS] , studentY[MAX_STUDENTS] , studentType[MAX_STUDENTS];//type 0 : left , type 1 : right
    for(int i = 0 ; i < numberOfStudents ; i++) scanf("%d %d %d" , &studentX[i] , &studentY[i] , &studentType[i]);

    int kill = 0;

    while (!kill && yaserX < n){
        for (int i = 0; i < numberOfStudents; ++i) checkYaserNeighbor(studentX[i], studentY[i], studentType[i]);

        yaserMove();

        for (int i = 0; i < numberOfStudents; ++i)
            if (!kill)
                kill = checkTouch(studentX[i], studentY[i]);//check touch before moving

        for (int i = 0; i < numberOfStudents; ++i) studentMove(studentX[i], studentY[i], studentType[i]);

        for (int i = 0; i < numberOfStudents; ++i)
            if (!kill)
                kill = checkTouch(studentX[i], studentY[i]);//check touch after moving
    }

    if(!kill) printf("Not killed :(");

    return 0;
}

void checkYaserNeighbor(int x, int y, int type) {
    if(x == yaserX){
        if((y == yaserY - 2 || y == yaserY + 2 || y == yaserY - 1 || y == yaserY + 1)
            && type != yaserType){
            yaserType = (yaserType + 1) % 2;
        }
    }
}

void yaserMove() {
    if (!yaserType) yaserY -= 1;
    else yaserY += 1;

    if(yaserY >= m){
        yaserY = m - 1;
        yaserX ++;
        yaserType = (yaserType + 1) % 2;
    }
    if(yaserY < 0){
        yaserY = 0;
        yaserX++;
        yaserType = (yaserType + 1) % 2;
    }
}

int checkTouch(int x, int y) {
    if(x == yaserX && y == yaserY){
        printf("%d" , yaserX);
        return 1;
    }
    return 0;
}

void studentMove(int &x, int &y, int &type) {
    if (!type) y -= 1;
    else y += 1;

    if(y >= m){
        y = m - 1;
        if(yaserX > x) {
            x++;
        }else if(yaserX < x){
            x--;
        }
        type = (type + 1) % 2;
    }

    if(y < 0){
        y = 0;
        if(yaserX > x) {
            x++;
        }else if(yaserX < x){
            x--;
        }
        type = (type + 1) % 2;
    }
}