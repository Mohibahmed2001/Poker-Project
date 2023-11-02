#include "Card.hpp"
using namespace std;
#include <iostream>

Card::~Card() {
    cout << "Destructor is called" << endl;
    delete[] this->bitmap_;
}

// Copy Constructor
Card::Card(const Card& rhs) {
    cout << "Copy constructor called" << endl;
    this->cardType_ = rhs.cardType_;
    this->instruction_ = rhs.instruction_;

    if (rhs.bitmap_) {
        this->bitmap_ = new int[80];
        for (int i = 0; i < 80; i++) {
            this->bitmap_[i] = rhs.bitmap_[i];
        }
    } else {
        this->bitmap_ = nullptr;
    }

    this->drawn_ = rhs.drawn_;
}

// Copy Assignment Operator
Card& Card::operator=(const Card& rhs) {
    if (this != &rhs) {
        cout << "Copy assignment called" << endl;

        this->cardType_ = rhs.cardType_;
        this->instruction_ = rhs.instruction_;

        // Release the existing bitmap
        delete[] this->bitmap_;

        if (rhs.bitmap_) {
            this->bitmap_ = new int[80];
            for (int i = 0; i < 80; i++) {
                this->bitmap_[i] = rhs.bitmap_[i];
            }
        } else {
            this->bitmap_ = nullptr;
        }

        this->drawn_ = rhs.drawn_;
    }
    return *this;
}

// Move Constructor
Card::Card(Card&& rhs) {
    cout << "Move constructor called" << endl;

    this->cardType_ = rhs.cardType_;
    this->instruction_ = std::move(rhs.instruction_);
    this->bitmap_ = rhs.bitmap_;
    rhs.bitmap_ = nullptr; // Reset rhs

    this->drawn_ = rhs.drawn_;
}

// Move Assignment Operator
Card& Card::operator=(Card&& rhs) {
    if (this != &rhs) {
        cout << "Move assignment called" << endl;

        this->cardType_ = rhs.cardType_;
        this->instruction_ = std::move(rhs.instruction_);
        delete[] this->bitmap_; // Release existing bitmap
        this->bitmap_ = rhs.bitmap_;
        rhs.bitmap_ = nullptr; // Reset rhs

        this->drawn_ = rhs.drawn_;
    }
    return *this;
}

// Default Constructor
Card::Card() = default;

// Rest of the member functions (getType, setType, setInstruction, getInstruction, getImageData, setImageData, getDrawn, setDrawn)


        /**
         * @return the string representation of the card type
         */
        string Card::getType() const
        {
                if(cardType_==POINT_CARD){
                        return "POINT_CARD";
                }else{
                        return "ACTION_CARD";
                }
        }
        /**
         * @post: set the card type
         * @param const reference to a CardType object
         */
        void Card::setType(const CardType& type){
                cardType_= type;
         }

        /**
         * @return the string representation of the card instruction
        */
        /**
         * @post: set the card instruction
         * @param: const reference to an instruction 
         */
        void Card::setInstruction(const std::string& instruction){
                instruction_ = instruction;
        }
        /**
         * @return the string representation of the card instruction
        */
       const string&Card::getInstruction() const{
                return instruction_;

        }
       
        /**
         * @return the image data
         */
        const int*Card::getImageData() const{
                return bitmap_;

        }
        /**
         * @post: Set the image data
         * @param pointer to an array of integers
         */
        void Card::setImageData(int* data){
                bitmap_ = data;
        }

        /**
         * @return the drawn status of the card
        */
       bool Card::getDrawn() const{
        return drawn_;

       }
        /**
         * @post: set the drawn status of the card
         * 
         * @param: const reference to a boolean
         */
        void Card::setDrawn(const bool& drawn){
                drawn_=drawn;
        }