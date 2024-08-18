#ifndef ITEM_H
#define ITEM_H

enum class ItemType {
    // Define item types here (e.g., SNACK, DRINK, etc.)
    SNACK,
    DRINK,
    // Add more types as needed
};

class Item {
private:
    ItemType type;
    int price;

public:
    // Default constructor
    Item() : type(ItemType::SNACK), price(0) {}

    // Parameterized constructor
    Item(ItemType type, int price) : type(type), price(price) {}

    // Getter for type
    ItemType getType() const { return type; }

    // Setter for type
    void setType(ItemType type) { this->type = type; }

    // Getter for price
    int getPrice() const { return price; }

    // Setter for price
    void setPrice(int price) { this->price = price; }
};

#endif // ITEM_H
