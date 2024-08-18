#include "Inventory.h"

Inventory::Inventory(int itemCount) {
    inventory.resize(itemCount);
    initialEmptyInventory();
}

const std::vector<ItemShelf>& Inventory::getInventory() const {
    return inventory;
}

void Inventory::setInventory(const std::vector<ItemShelf>& newInventory) {
    inventory = newInventory;
}

void Inventory::initialEmptyInventory() {
    int startCode = 101;
    for (auto& space : inventory) {
        space.setCode(startCode);
        space.setSoldOut(true);
        startCode++;
    }
}

void Inventory::addItem(const Item& item, int codeNumber) {
    for (auto& itemShelf : inventory) {
        if (itemShelf.getCode() == codeNumber) {
            if (itemShelf.isSoldOut()) {
                itemShelf.setItem(item);
                itemShelf.setSoldOut(false);
                return;
            } else {
                throw std::runtime_error("Item already present, cannot add item here");
            }
        }
    }
    throw std::runtime_error("Invalid Code");
}

Item Inventory::getItem(int codeNumber) const {
    for (const auto& itemShelf : inventory) {
        if (itemShelf.getCode() == codeNumber) {
            if (itemShelf.isSoldOut()) {
                throw std::runtime_error("Item already sold out");
            } else {
                return itemShelf.getItem();
            }
        }
    }
    throw std::runtime_error("Invalid Code");
}

void Inventory::updateSoldOutItem(int codeNumber) {
    for (auto& itemShelf : inventory) {
        if (itemShelf.getCode() == codeNumber) {
            itemShelf.setSoldOut(true);
            return;
        }
    }
}
