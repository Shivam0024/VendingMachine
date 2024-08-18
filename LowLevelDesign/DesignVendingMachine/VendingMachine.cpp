#include "VendingMachine.h"

VendingMachine::VendingMachine() {
    vendingMachineState = new IdleState();
    inventory = new Inventory(10);
}

VendingMachine::~VendingMachine() {
    delete vendingMachineState;
    delete inventory;
    // No need to delete coinList as it's managed by std::vector
}

State* VendingMachine::getVendingMachineState() const {
    return vendingMachineState;
}

void VendingMachine::setVendingMachineState(State* state) {
    // Assuming ownership of the previous state is managed elsewhere
    delete vendingMachineState; 
    vendingMachineState = state;
}

Inventory* VendingMachine::getInventory() const {
    return inventory;
}

void VendingMachine::setInventory(Inventory* newInventory) {
    delete inventory; // Clean up old inventory
    inventory = newInventory;
}

std::vector<Coin> VendingMachine::getCoinList() const {
    return coinList;
}

void VendingMachine::setCoinList(const std::vector<Coin>& newCoinList) {
    coinList = newCoinList;
}
