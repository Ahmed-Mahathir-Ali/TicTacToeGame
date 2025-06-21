#include <iostream>
#include<string>
void drawGrid(char *spaces)
{
    std::cout << "       |       |      " << std::endl;
    std::cout << "   " << spaces[0] << "   " << "|   " << spaces[1] << "   " << "|   " << spaces[2] << "   " << std::endl;
    std::cout << "_______|_______|______" << std::endl;

    std::cout << "       |       |      " << std::endl;
    std::cout << "   " << spaces[3] << "   " << "|   " << spaces[4] << "   " << "|   " << spaces[5] << "   " << std::endl;
    std::cout << "_______|_______|______" << std::endl;

    std::cout << "       |       |      " << std::endl;
    std::cout << "   " << spaces[6] << "   " << "|   " << spaces[7] << "   " << "|   " << spaces[8] << "   " << std::endl;
    std::cout << "       |        |      " <<'\n'<<std::endl;

}
void playerMove(int value,char *spaces)
{
     if (spaces[value] == ' ')
     {
         spaces[value] = 'X';
     }
}
void pcMove(char *spaces)
{
    bool hasEmpty = false;
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            hasEmpty = true;
            break;
        }
    }

    if (!hasEmpty) return;

    srand(time(0));
    bool flag = true;
    while (flag)
    {
        int value = rand() % 9;
        if (spaces[value] == ' ')
        {
            spaces[value] = 'O';
            flag = false;
        }
    }
}
bool checkTie(char *spaces) {
    for (int i = 0 ; i < 9 ; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    return true;
}
char checkresult(char* spaces)
{
    int combos[][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for (int i = 0 ; i < sizeof(combos)/sizeof(combos[0]);i++)
    {
        if (spaces[combos[i][0]] == spaces[combos[i][1]] && spaces[combos[i][1]] == spaces[combos[i][2]])
        {
            if ( spaces[combos[i][0]]==' ')
            {
                return '\0';
            }
            else
            {
                return spaces[combos[i][0]];
            }
        }
    }
    return false;
}
int main() {
    char spaces[] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    bool running = true;
    drawGrid(spaces);
    while(running)
    {
        int value =-1;
        std::cout <<" Enter grid no (1-9) : ";
        std::cin >> value;
        value-=1;
        if (value<0 || value>8)
        {
           std::cout << "Invalid input. Please enter a number between 1 and 9";
           break;
        }
        else
        {
            if (spaces[value] == ' ') {
                playerMove(value, spaces);
                pcMove(spaces);
                if (checkresult(spaces)=='X')
                {
                    drawGrid(spaces);
                    std::cout << "You Won!!"<< std::endl;
                    running = false;
                    break;
                }
                else if (checkresult(spaces)=='O')
                {
                    drawGrid(spaces);
                    std::cout << "You Lost!!"<< std::endl;
                    running = false;
                    break;
                }
                if (checkTie(spaces)) {
                    drawGrid(spaces);
                    std::cout << "Its a tie"<< std::endl;
                    running = false;
                    break;
                }
                drawGrid(spaces);
            }
        }
    }
    return 0;
}