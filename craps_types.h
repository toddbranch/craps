#ifndef _CRAPS_TYPES_H
#define _CRAPS_TYPES_H

struct bet_type {
    unsigned int pass;
    unsigned int passOdds;
};

enum gamestate {
    comeOutState,
    pointState
};

#endif
