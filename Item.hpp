#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>

class Item {
    private : 

        int price;
        std::string name ; 
        int masurment;
        int available;

    public:
        Item(std::string , int ,int );
        void operator-( int i);
        bool virtual is_available() const = 0;
        virtual void buy(int b) = 0 ;
        virtual std::string getInfo() = 0;  
        int virtual get_available() const = 0 ; 
        int virtual getPrice() const = 0 ; 
        std::string virtual get_Name() const =0 ;
        void virtual set_available(int a) = 0 ;  

};
#endif