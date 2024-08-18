#ifndef SELECTIONSTATE_H
#define SELECTIONSTATE_H

#include <iostream>
#include <vector>
#include "State.h"
#include "VendingMachine.h"
#include "Coin.h"
#include "Item.h"
#include "IdleState.h"
#include "DispenseState.h"

class SelectionState : public State {
public:
    SelectionState() {
        std::cout << "Currently Vending machine is in SelectionState" << std::endl;
    }

    void clickOnInsertCoinButton(VendingMachine* machine) override {
        throw std::runtime_error("You cannot click on insert coin button in SelectionState");
    }

    void clickOnStartProductSelectionButton(VendingMachine* machine) override {
        // No action needed, just return
    }

    void insertCoin(VendingMachine* machine, const Coin& coin) override {
        throw std::runtime_error("You cannot insert a coin in SelectionState");
    }

    void chooseProduct(VendingMachine* machine, int codeNumber) override {
        // 1. Get item of this codeNumber
        Item item = machine->getInventory().getItem(codeNumber);

        // 2. Total amount paid by the user
        int paidByUser = 0;
        for (const Coin& coin : machine->getCoinList()) {
            paidByUser += static_cast<int>(coin);
        }

        // 3. Compare product price and amount paid by user
        if (paidByUser < item.getPrice()) {
            std::cout << "Insufficient Amount, Product you selected is for price: "
                      << item.getPrice() << " and you paid: " << paidByUser << std::endl;
            refundFullMoney(machine);
            throw std::runtime_error("Insufficient amount");
        } else if (paidByUser >= item.getPrice()) {
            if (paidByUser > item.getPrice()) {
                getChange(paidByUser - item.getPrice());
            }
            machine->setVendingMachineState(new DispenseState(machine, codeNumber));
        }
    }

    int getChange(int returnExtraMoney) override {
        // Actual logic should be to return coins in the dispense tray, but for simplicity, we are just printing the amount to be refunded
        std::cout << "Returned the change in the Coin Dispense Tray: " << returnExtraMoney << std::endl;
        return returnExtraMoney;
    }

    std::vector<Coin> refundFullMoney(VendingMachine* machine) override {
        std::cout << "Returned the full amount back in the Coin Dispense Tray" << std::endl;
        machine->setVendingMachineState(new IdleState(machine));
        return machine->getCoinList();
    }

    Item dispenseProduct(VendingMachine* machine, int codeNumber) override {
        throw std::runtime_error("Product cannot be dispensed in SelectionState");
    }

    void updateInventory(VendingMachine* machine, const Item& item, int codeNumber) override {
        throw std::runtime_error("Inventory cannot be updated in SelectionState");
    }
};

#endif // SELECTIONSTATE_H

