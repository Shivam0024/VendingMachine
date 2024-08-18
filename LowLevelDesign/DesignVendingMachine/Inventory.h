#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <stdexcept>

// Forward declaration of Item class
class Item;

// ItemShelf class
class ItemShelf {
private:
    int code;
    bool soldOut;
    Item item;

public:
    ItemShelf() : code(0), soldOut(true) {}

    int getCode() const { return code; }
    void setCode(int code) { this->code = code; }

    bool isSoldOut() const { return soldOut; }
    void setSoldOut(bool soldOut) { this->soldOut = soldOut; }

    Item getItem() const { return item; }
    void setItem(const Item& item) { this->item = item; }
};

// Inventory class
class Inventory {
private:
    std::vector<ItemShelf> inventory;

public:
    // Constructor
    Inventory(int itemCount);

    // Getter for inventory
    const std::vector<ItemShelf>& getInventory() const;

    // Setter for inventory
    void setInventory(const std::vector<ItemShelf>& newInventory);

    // Initialize inventory with empty items
    void initialEmptyInventory();

    // Add an item to the inventory
    void addItem(const Item& item, int codeNumber);

    // Get an item from the inventory
    Item getItem(int codeNumber) const;

    // Update the item to sold out
    void updateSoldOutItem(int codeNumber);
};

#endif // INVENTORY_H
