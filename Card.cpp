#include "Card.hpp"
#include <iostream>
using namespace std;

Card::~Card(){
        cout<< "destructor is called" << endl;
        delete[] this->bitmap_;
}

// Copy constructor
Card::Card(const Card& rhs) {
    cout << "Copy constructor called" << endl;
    this->cardType_ = rhs.cardType_;
    this->instruction_ = rhs.instruction_;

    // Allocate memory for the bitmap and copy the data
    this->bitmap_ = new int[80];
    for (int i = 0; i < 80; i++) {
        this->bitmap_[i] = rhs.bitmap_[i];
    }

    this->drawn_ = rhs.drawn_;
}

// Copy assignment operator
Card& Card::operator=(const Card& rhs) {
    if (this != &rhs) {
        cout << "Copy assignment called" << endl;

        // Release the existing bitmap
        delete[] this->bitmap_;

        this->cardType_ = rhs.cardType_;
        this->instruction_ = rhs.instruction_;

        // Allocate memory for the new bitmap and copy the data
        this->bitmap_ = new int[80];
        for (int i = 0; i < 80; i++) {
            this->bitmap_[i] = rhs.bitmap_[i];
        }

        this->drawn_ = rhs.drawn_;
    }
    return *this;
}

// Move constructor
Card::Card(Card&& rhs) {
    cout << "Move constructor called" << endl;

    this->cardType_ = rhs.cardType_;
    this->instruction_ = std::move(rhs.instruction_);

    // Move the existing bitmap and reset rhs
    this->bitmap_ = rhs.bitmap_;
    rhs.bitmap_ = nullptr;

    this->drawn_ = rhs.drawn_;
}

// Move assignment operator
Card& Card::operator=(Card&& rhs) {
        if (this != &rhs) {
                cout << "Move assignment called" << endl;

                // Release the existing bitmap
                 delete[] this->bitmap_;

                this->cardType_ = rhs.cardType_;
                this->instruction_ = std::move(rhs.instruction_);

                 // Move the existing bitmap and reset rhs
                this->bitmap_ = rhs.bitmap_;
                rhs.bitmap_ = nullptr;

                 this->drawn_ = rhs.drawn_;
    }
    return *this;
}
        
        /**
         * Default Constructor
         * @post: Construct a new Card object 
         */
        Card::Card()=default;

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