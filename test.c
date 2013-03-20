#include <stdio.h>
#include "dice.h"
#include "craps_types.h"
#include "payouts.h"

int main(int argc, const char *argv[])
{
    unsigned int currentRoll;
    int bankRoll = 500;
    unsigned int point, pointsHit = 0, pointsMissed = 0, numRolls = 0;
    enum gamestate currentState = comeOutState;
    struct bet_type player1bets;

    player1bets.pass = 10;
    player1bets.passOdds = 50;

    player1bets.pass = 10;
    player1bets.passOdds = 50;

    init();

    while (numRolls < 10000)
    {
        do {
            currentRoll = rollDice(2);
            switch (currentRoll) {
                case 7:
                case 11:
                    bankRoll += payout(currentRoll, point, currentState, player1bets);
                    break;
                case 2:
                case 3:
                case 12:
                    bankRoll += payout(currentRoll, point, currentState, player1bets);
                    break;
                default:
                    currentState = pointState;
                    point = currentRoll;
                    break;
            }
        } while(currentState == comeOutState);

        do {
            currentRoll = rollDice(2);
            if (currentRoll == point)
            {
                bankRoll += payout(currentRoll, point, currentState, player1bets);
                pointsHit++;
                currentState = comeOutState;
                point = 0;
            } else if (currentRoll == 7)
            {
                bankRoll += payout(currentRoll, point, currentState, player1bets);
                pointsMissed++;
                currentState = comeOutState;
                point = 0;
            }
        } while(currentState == pointState);
        numRolls++;
    }

    printf("Total rolls: %u\n", numRolls);
    printf("Points hit: %u\n", pointsHit);
    printf("Points missed: %u\n", pointsMissed);
    printf("Bank roll: %d\n", bankRoll);
    return 0;
}

unsigned int odds(unsigned int number, unsigned int bet)
{
    unsigned int payout;

    switch (number) {
        case 4:
        case 10:
            payout = 2 * bet;
            break;
        case 5:
        case 9:
            payout = (3 * bet) / 2;
            break;
        case 6:
        case 8:
            payout = (6 * bet) / 5;
            break;
    }

    return payout;
}
