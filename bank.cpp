#include "bank.hpp"
#include <iostream>




// // this function is only for the shop 
// bool Bank::deposit(double amount , double dailylimit){
//     if (amount > dailylimit ){
//         std::cout<<"daily transfer limit is passed .";
//         return false;
//     }

//     if ((amount +  dailytransfered) > dailylimit ){
//         std::cout<<"daily transfer limit is passed .";
//         return false;
//     }

//     else 
//     balance += amount ;
//     dailytransfered += amount;
//     return true;

// }

Bank::Bank (std::string name, int number , double balance ): holder_name(name), account_number(number), balance(balance) {}


 double Bank::getBalance()const{

return balance;

}

void Bank::setBalance( double d){

    balance = d;

}
 double Bank::get_dailytranfered() const{

    return dailytransfered;

}
void Bank::set_dailytarnsfered(double d){

    dailytransfered = d;
}



