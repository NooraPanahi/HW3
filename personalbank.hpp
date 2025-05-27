#ifndef PERSONALBANK_HPP
#define PERSONALBANK_HPP
#include <string>
#include <iostream>
#include "bank.hpp"

class Personbank : public Bank {

    public:
    Personbank(std::string name, int acc_number, double bal);

     bool withdraw(std::unique_ptr<Currency> , double ) override ; //only use for person
     bool deposit(std::unique_ptr<Currency> , double ) override; // only used for shop
    

    // void change_money();      
    
    
    // private:
    // // int dailytransfered;
    // // int account_number;
    // // std::string holder_name;
    // // double balance ;



};

#endif 