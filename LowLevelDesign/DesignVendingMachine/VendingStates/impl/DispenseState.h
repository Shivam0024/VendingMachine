#ifndef DISPENSESTATE_H
#define DISPENSESTATE_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "VendingMachine.h"
#include "Coin.h"
#include "Item.h"
#include "State.h"
#include "IdleState.h"

class DispenseState : public State {
public:
    DispenseState(VendingMachine* machine, int codeNumber);

    void clickOnInsertCoinButton(VendingMachine* machine) override;
    void clickOnStartProductSelectionButton(VendingMachine* machine) override;
    void insertCoin(VendingMachine* machine, const Coin& coin) override;
    void chooseProduct(VendingMachine* machine, int codeNumber) override;
    int getChange(int returnChangeMoney) override;
    std::vector<Coin> refundFullMoney(VendingMachine* machine) override;
    Item dispenseProduct(VendingMachine* machine, int codeNumber) override;
    void updateInventory(VendingMachine* machine, const Item& item, int codeNumber) override;
};

#endif // DISPENSESTATE_H
