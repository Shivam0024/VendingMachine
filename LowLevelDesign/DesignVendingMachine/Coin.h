#ifndef COIN_H
#define COIN_H

#include <stdexcept>

enum class Coin {
    PENNY = 1,
    NICKEL = 5,
    DIME = 10,
    QUARTER = 25
};

// Utility function to get the value of a Coin
inline int getCoinValue(Coin coin) {
    switch (coin) {
        case Coin::PENNY: return 1;
        case Coin::NICKEL: return 5;
        case Coin::DIME: return 10;
        case Coin::QUARTER: return 25;
        default: throw std::invalid_argument("Unknown Coin");
    }
}

#endif // COIN_H
