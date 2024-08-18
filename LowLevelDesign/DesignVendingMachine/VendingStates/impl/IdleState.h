#ifndef IDLESTATE_H
#define IDLESTATE_H

#include <iostream>
#include <vector>
#include "State.h"
#include "VendingMachine.h"
#include "Coin.h"
#include "Item.h"
#include "HasMoneyState.h"

class IdleState : public State {
public:
    IdleState() {
        std::cout << "Currently Vending machine is in IdleState" << std::endl;
    }

    IdleState(VendingMachine* machine) {
        std::cout << "Currently Vending machine is in IdleState" << std::endl;
        machine->setCoinList(std::vector<Coin>());
    }

    void clickOnInsertCoinButton(VendingMachine* machine) override {
        machine->setVendingMachineState(new HasMoneyState());
    }

    void clickOnStartProductSelectionButton(VendingMachine* machine) override {
        throw std::runtime_error("First you need to click on insert coin button");
    }

    void insertCoin(VendingMachine* machine, const Coin& coin) override {
        throw std::runtime_error("You cannot insert coin in IdleState");
    }

    void chooseProduct(VendingMachine* machine, int codeNumber) override {
        throw std::runtime_error("You cannot choose a product in IdleState");
    }

    int getChange(int returnChangeMoney) override {
        throw std::runtime_error("You cannot get change in IdleState");
    }

    std::vector<Coin> refundFullMoney(VendingMachine* machine) override {
        throw std::runtime_error("You cannot get refunded in IdleState");
    }

    Item dispenseProduct(VendingMachine* machine, int codeNumber) override {
        throw std::runtime_error("Product cannot be dispensed in IdleState");
    }

    void updateInventory(VendingMachine* machine, const Item& item, int codeNumber) override {
        machine->getInventory().addItem(item, codeNumber);
    }
};

#endif // IDLESTATE_H
