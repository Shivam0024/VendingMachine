#include "DispenseState.h"

DispenseState::DispenseState(VendingMachine* machine, int codeNumber) {
    std::cout << "Currently Vending machine is in DispenseState" << std::endl;
    dispenseProduct(machine, codeNumber);
}

void DispenseState::clickOnInsertCoinButton(VendingMachine* machine) {
    throw std::runtime_error("Insert coin button cannot be clicked in Dispense state");
}

void DispenseState::clickOnStartProductSelectionButton(VendingMachine* machine) {
    throw std::runtime_error("Product selection button cannot be clicked in Dispense state");
}

void DispenseState::insertCoin(VendingMachine* machine, const Coin& coin) {
    throw std::runtime_error("Coin cannot be inserted in Dispense state");
}

void DispenseState::chooseProduct(VendingMachine* machine, int codeNumber) {
    throw std::runtime_error("Product cannot be chosen in Dispense state");
}

int DispenseState::getChange(int returnChangeMoney) {
    throw std::runtime_error("Change cannot be returned in Dispense state");
}

std::vector<Coin> DispenseState::refundFullMoney(VendingMachine* machine) {
    throw std::runtime_error("Refund cannot happen in Dispense state");
}

Item DispenseState::dispenseProduct(VendingMachine* machine, int codeNumber) {
    std::cout << "Product has been dispensed" << std::endl;

    Item item = machine->getInventory()->getItem(codeNumber);
    machine->getInventory()->updateSoldOutItem(codeNumber);

    delete machine->getCurrentState();
    machine->setVendingMachineState(new IdleState(machine));

    return item;
}

void DispenseState::updateInventory(VendingMachine* machine, const Item& item, int codeNumber) {
    throw std::runtime_error("Inventory cannot be updated in Dispense state");
}
