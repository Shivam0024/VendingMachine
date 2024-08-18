#ifndef ITEM_SHELF_H
#define ITEM_SHELF_H

#include "Item.h"

class ItemShelf {
private:
    int code;
    Item item;
    bool soldOut;

public:
    // Default constructor
    ItemShelf() : code(0), soldOut(true) {}

    // Parameterized constructor
    ItemShelf(int code, const Item& item, bool soldOut) 
        : code(code), item(item), soldOut(soldOut) {}

    // Getter for code
    int getCode() const { return code; }

    // Setter for code
    void setCode(int code) { this->code = code; }

    // Getter for item
    Item getItem() const { return item; }

    // Setter for item
    void setItem(const Item& item) { this->item = item; }

    // Getter for soldOut
    bool isSoldOut() const { return soldOut; }

    // Setter for soldOut
    void setSoldOut(bool soldOut) { this->soldOut = soldOut; }
};

#endif // ITEM_SHELF_H
