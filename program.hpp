#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <vector>
#include "Item.hpp"
#include"bank.hpp"
#include "personalbank.hpp"
#include "shopbank.hpp"

class Program{
    private:
    
    static std::vector<Item*> items ; 
    static std::vector<std::string> names ;

    public:
        void SHOWresid() ; 
        void SAVEresid(std::string user , std::string itemName , int price , int available) ; 
        static void Run() ;
        static std::string showItems() ;  
        void Buying( const std::string ItemName , int tedad) ; 

};

#endif