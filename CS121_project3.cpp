#include <cstdlib>
#include <iostream>
#include <ctime>


const int NUM_HORSES = 5;
const int raceLen = 15;

void advance(int horseNum, int* horses) {
    if (rand() % 2 == 1) {
        horses[horseNum]++;
    }
}

void printLane(int horseNum, int* horses) {
    for (int position = 0; position < raceLen; ++position) {
        if (position == horses[horseNum]) {
            std::cout << horseNum; 
        } else {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

bool isWinner(int horseNum, int* horses) {
    return horses[horseNum] >= raceLen;
}

int main() {
    srand(time(NULL));
    int horses[NUM_HORSES] = {0};
    bool raceOver = false;

    while (!raceOver) {
        system("clear");

       
        for (int i = 0; i < NUM_HORSES; ++i) {
            advance(i, horses);
            printLane(i, horses);
        }

        
        for (int i = 0; i < NUM_HORSES; ++i) {
            if (isWinner(i, horses)) {
                std::cout << "Horse " << i << " WINS!!!" << std::endl;
                raceOver = true;
            }
        }

        if (!raceOver) {
            std::cout << "Press Enter for another turn  :";
            std::cin.get();  
        }
    }
    return 0;
}





