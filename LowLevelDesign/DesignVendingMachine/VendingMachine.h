#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H


#include "Inventory.h"
#include "Coin.h"
#include "State.h"
#include "IdleState.h"

#include <vector>
class VendingMachine {
private:
    State* vendingMachineState;
    Inventory* inventory;
    std::vector<Coin> coinList;

public:
    VendingMachine();
    ~VendingMachine(); // Destructor to clean up dynamically allocated memory

    State* getVendingMachineState() const;
    void setVendingMachineState(State* vendingMachineState);

    Inventory* getInventory() const;
    void setInventory(Inventory* inventory);

    std::vector<Coin> getCoinList() const;
    void setCoinList(const std::vector<Coin>& coinList);
};

#endif // VENDINGMACHINE_H
