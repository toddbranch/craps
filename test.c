#include <stdio.h>
#include "dice.h"

int main(int argc, const char *argv[])
{
    unsigned int currentRoll;
    int bankRoll = 500;
    unsigned int betUnit = 10;
    unsigned int point = 0, pointsHit = 0, pointsMissed = 0, numRolls = 0;

    init();

    while (numRolls < 500)
    {
        do {
            currentRoll = rollDice(2);
            switch (currentRoll) {
                case 7:
                case 11:
                    bankRoll += betUnit;
                    break;
                case 2:
                case 3:
                case 12:
                    bankRoll -= betUnit;
                    break;
                default:
                    point = currentRoll;
                    break;
            }
        } while(!point);

        do {
            currentRoll = rollDice(2);
            if (currentRoll == point)
            {
                bankRoll += betUnit;
                pointsHit++;
                point = 0;
            } else if (currentRoll == 7)
            {
                bankRoll -= betUnit;
                pointsMissed++;
                point = 0;
            }
        } while(point);
        numRolls++;
    }

    printf("Total rolls: %u\n", numRolls);
    printf("Points hit: %u\n", pointsHit);
    printf("Points missed: %u\n", pointsMissed);
    printf("Bank roll: %d\n", bankRoll);
    return 0;
}
