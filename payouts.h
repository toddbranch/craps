#ifndef _CRAPS_PAYOUT_H
#define _CRAPS_PAYOUT_H

#include "craps_types.h"

int payout(unsigned int roll, unsigned int point, enum gamestate currentState, struct bet_type bets);

#endif
