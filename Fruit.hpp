#ifndef FRUIT_H
#define FRUIT_H
#include <string>
#include <vector>
#include "Item.hpp"

class Fruit : public Item {
    
    int price;
    int available;
    std::string measurment ;
    std::string name ; 

    public:
        Fruit( std::string name ,int p , int a ,std::string me = "kg");
        void buy(int b) override; 
        std::string getInfo() override ;
        std::string get_Name() const override ;  
        int getPrice() const override; 
        int get_available()const override ; 
        void set_available(int a) override; 
        bool is_available() const override; 

};
#endif