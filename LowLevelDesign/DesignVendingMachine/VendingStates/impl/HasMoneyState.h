#ifndef HASMONEYSTATE_H
#define HASMONEYSTATE_H

#include <iostream>
#include <vector>
#include "State.h"
#include "VendingMachine.h"
#include "Coin.h"
#include "Item.h"
#include "IdleState.h"
#include "SelectionState.h"

class HasMoneyState : public State {
public:
    HasMoneyState() {
        std::cout << "Currently Vending machine is in HasMoneyState" << std::endl;
    }

    void clickOnInsertCoinButton(VendingMachine* machine) override {
        // No action needed, just return
    }

    void clickOnStartProductSelectionButton(VendingMachine* machine) override {
        machine->setVendingMachineState(new SelectionState());
    }

    void insertCoin(VendingMachine* machine, const Coin& coin) override {
        std::cout << "Accepted the coin" << std::endl;
        machine->getCoinList().push_back(coin);
    }

    void chooseProduct(VendingMachine* machine, int codeNumber) override {
        throw std::runtime_error("You need to click on start product selection button first");
    }

    int getChange(int returnChangeMoney) override {
        throw std::runtime_error("You cannot get change in HasMoneyState");
    }

    Item dispenseProduct(VendingMachine* machine, int codeNumber) override {
        throw std::runtime_error("Product cannot be dispensed in HasMoneyState");
    }

    std::vector<Coin> refundFullMoney(VendingMachine* machine) override {
        std::cout << "Returned the full amount back in the Coin Dispense Tray" << std::endl;
        machine->setVendingMachineState(new IdleState(machine));
        return machine->getCoinList();
    }

    void updateInventory(VendingMachine* machine, const Item& item, int codeNumber) override {
        throw std::runtime_error("You cannot update inventory in HasMoneyState");
    }
};

#endif // HASMONEYSTATE_H
