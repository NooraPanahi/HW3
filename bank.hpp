#ifndef BANK_HPP
#define BANK_HPP

#include <string>
#include <iostream>
#include <memory>
#include "currency.hpp"
class Bank{

    public:
    Bank (std::string name, int number , double balance );
    virtual bool withdraw(std::unique_ptr<Currency> , double  ) = 0; //only use for person
    virtual bool deposit(std::unique_ptr<Currency> , double ) = 0; // only used for shop
    double getBalance()const ;
    void setBalance( double);
    double get_dailytranfered() const;
    void set_dailytarnsfered( double);
     


    // void change_money();
    
    
    private:
    double dailytransfered = 0 ;
    int account_number;
    std::string holder_name;
    double balance ;

    
};

#endif