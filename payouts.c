#include "payouts.h"

int payout(unsigned int roll, unsigned int point, enum gamestate currentState, struct bet_type bets)
{
    int total = 0;
    if (currentState == comeOutState)
    {
        switch (roll)
        {
            case 7:
            case 11:
                total += bets.pass;
                break;
            case 2:
            case 3:
            case 12:
                total -= bets.pass;
                break;
            default:
                break;
        }
    } else
    {
        if (roll == point)
        {
            total += bets.pass;
            total += odds(roll, bets.passOdds);
        } else if (roll == 7)
        {
            total -= bets.pass;
            total -= bets.passOdds;
        }
    }
    return total;
}
