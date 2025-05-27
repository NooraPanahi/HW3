#include "Shopbank.hpp"
#include "bank.hpp"
#include <iostream>

Shopbank::Shopbank(std::string name, int acc_number, double bal): Bank(name, acc_number, bal){}

bool Shopbank::deposit(std::unique_ptr<Currency> amount , double dailylimit){

    
    double amount_usd = amount->to_usd();

     
    double newbalance;
    double balance = this->getBalance();
    double dailytransfered_2 ;
    double dailytransfered = this->get_dailytranfered();
    
    if (amount_usd <= 0 || amount_usd > dailylimit ){
        std::cout<<"sorry. daily transfer limit is passed .";
        return false; }

    else if (amount_usd + this->get_dailytranfered() > dailylimit ) {
        std::cout<< "sorry. daily transfer limit is passed .";
        return false; }  

       

        
     
        else {
    
            newbalance = balance  + amount_usd;
            this->setBalance(newbalance);
            
            dailytransfered_2= dailytransfered + amount_usd;
            this->set_dailytarnsfered(dailytransfered_2);
           
            return true;
            
        }
}

bool Shopbank::withdraw(std::unique_ptr<Currency> amount , double limit){    return true;}