#include "dice.h"
#include <time.h>
#include <stdlib.h>

void init(void)
{
    srand(time(NULL));
}

unsigned int rollDice(unsigned int numberOfDice)
{
    unsigned int diceTotal = 0;
    unsigned int i;
    for (i = 0; i < numberOfDice; i++) {
        diceTotal += rand() % 6 + 1;
    }
    return diceTotal;
}
