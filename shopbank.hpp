#ifndef SHOPBANK_HPP
#define SHOPBANK_HPP
#include "bank.hpp"


class Shopbank : public Bank{

    public:
    Shopbank(std::string name, int acc_number, double bal);

    bool withdraw(std::unique_ptr<Currency> , double ) override ; //only use for person
    bool deposit(std::unique_ptr<Currency> , double ) override;


};




#endif