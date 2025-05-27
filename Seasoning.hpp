#ifndef SEASONING_HPP
#define SEASONING_HPP

#include <string>
#include "Item.hpp"

class Seasoning : public Item {

    private:
    
        int price;
        int available;
        std::string measurment ;
        std::string name ; 

    public:
        Seasoning( std::string name ,int p , int a ,std::string me = "g");
        void buy(int b) override; 
        std::string getInfo() override ;
        std::string get_Name() const override ;  
        int getPrice() const override; 
        int get_available()const override ; 
        void set_available(int a) override; 
        bool is_available() const override; 
};

#endif