#include <iostream>
#include "VendingMachine.h"
#include "Inventory.h"
#include "Item.h"
#include "ItemShelf.h"
#include "ItemType.h"
#include "State.h"
#include "HasMoneyState.h"
#include "SelectionState.h"
#include "DispenseState.h"
#include "IdleState.h"

// Fill up inventory with items
void fillUpInventory(VendingMachine& vendingMachine) {
    ItemShelf* slots = vendingMachine.getInventory()->getInventory();
    for (int i = 0; i < vendingMachine.getInventory()->getSize(); i++) {
        Item newItem;
        if (i < 3) {
            newItem.setType(ItemType::COKE);
            newItem.setPrice(12);
        } else if (i < 5) {
            newItem.setType(ItemType::PEPSI);
            newItem.setPrice(9);
        } else if (i < 7) {
            newItem.setType(ItemType::JUICE);
            newItem.setPrice(13);
        } else {
            newItem.setType(ItemType::SODA);
            newItem.setPrice(7);
        }
        slots[i].setItem(newItem);
        slots[i].setSoldOut(false);
    }
}

// Display inventory details
void displayInventory(const VendingMachine& vendingMachine) {
    const ItemShelf* slots = vendingMachine.getInventory()->getInventory();
    for (int i = 0; i < vendingMachine.getInventory()->getSize(); i++) {
        std::cout << "CodeNumber: " << slots[i].getCode()
                  << " Item: " << static_cast<int>(slots[i].getItem().getType())
                  << " Price: " << slots[i].getItem().getPrice()
                  << " isAvailable: " << !slots[i].isSoldOut() << std::endl;
    }
}

int main() {
    VendingMachine vendingMachine;
    try {
        std::cout << "Filling up the inventory" << std::endl;
        fillUpInventory(vendingMachine);
        displayInventory(vendingMachine);

        std::cout << "Clicking on InsertCoinButton" << std::endl;
        State* vendingState = vendingMachine.getVendingMachineState();
        vendingState->clickOnInsertCoinButton(vendingMachine);

        vendingState = vendingMachine.getVendingMachineState();
        vendingState->insertCoin(vendingMachine, Coin::NICKEL);
        vendingState->insertCoin(vendingMachine, Coin::QUARTER);

        std::cout << "Clicking on ProductSelectionButton" << std::endl;
        vendingState->clickOnStartProductSelectionButton(vendingMachine);

        vendingState = vendingMachine.getVendingMachineState();
        vendingState->chooseProduct(vendingMachine, 102);

        displayInventory(vendingMachine);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        displayInventory(vendingMachine);
    }

    return 0;
}
