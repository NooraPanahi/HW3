#include "program.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "Snack.hpp"
#include "Seasoning.hpp"
#include "bank.hpp"
#include "personalbank.hpp"
#include "shopbank.hpp"
#include "currency.hpp"
#include "USD.hpp"
#include "IRR.hpp"
#include "EUR.hpp"
#include <memory>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std ;

vector<Item*> Program::items ; 
vector<string> Program::names ; 

string Program::showItems(){
    string result ; 
    for(const auto & item : items)
    result += item->getInfo() + '\n' ; 
    
    return result ; 
}

void Program::SAVEresid(std::string user, std::string itemName, int price, int quantity) { 
    fstream file("UserBasket.txt", ios::app); 
    file << "user: " << user << " " << itemName << " , price " << price << "$, " << quantity << "." << endl ; 
    file.close() ; 
}
void Program::SHOWresid(){
    cout << "-------------" << endl ;  
    cout << "your resid: " << endl ; 
    fstream file("UserBasket.txt", ios::in) ; 
    string line ; 
    while(getline(file , line))
        cout << line << endl ;
    cout << "-------------" << endl ; 
    file.close() ;  
}

void Program::Run(){
    try
    { 
        items.push_back(new Fruit("apple",10,1))  ; 
        names.push_back("apple") ; 
        items.push_back(new Fruit ("kiwi" , 6, 7)) ;
        names.push_back("kiwi") ;  
        items.push_back(new Snack("sandwitch" , 4 , 15)) ;
        names.push_back("sandwitch") ; 
        items.push_back(new Seasoning("salt" , 4 , 12)) ;  
        names.push_back("salt") ; 
        
        string targetItem  ;
        int TedadTarget ; 
        bool found ; 
        
        cout << "Hello welcome to our shop!" << endl << "here are the items: " << endl ; 
        
        while(true){
            cout << showItems() ;
            cout<<"-----------------------------------\n";
            
            cout << "what do you want to buy ? (type bye to leave the shop)" ;
            
            cin >> targetItem ; 
            if(targetItem == "bye") {
                cout << "bye bye!" << endl ; 
                break  ;
            }   
            
            auto it  = find(names.begin() , names.end() , targetItem) ; 
            
            if(it != names.end()){
                found = true ; 
            }
            else{
                found = false ;  
            }
            
            if(found){                
                cout << "how many " << targetItem << " do you want to buy? " ; 
                cin >> TedadTarget ; 
                if(TedadTarget <0)
                    return ; 
                
                Program p;
                p.Buying(targetItem,  TedadTarget) ;
      
            }
            else
                cerr << "not found!!" << endl ; 
            
            cout << "\nwhat else do you want to buy? " << endl;        
        }
    }
    catch(const exception & e){
        std::cerr << e.what() << '\n';
    }
}
Bank *costoumer = new  Personbank ("tina" ,1234 , 10000 );
Bank *shop  = new Shopbank ("shop" , 2345 , 0);

void Program::Buying( const std::string ItemName , int tedad){

    cout<<"\nperson balance before :"<<costoumer->getBalance();
     
    for(auto item : items){
        if(item ->get_Name() == ItemName){
            if(tedad> item->get_available() || !(item->is_available()))
                throw runtime_error("\nwe dont have that item anymore.") ; 
            int price = item->getPrice();
            int amount = tedad * price;
            cout<<"\nit will cost : "<<amount;
            
            double user_amount;
            string currency_code;
            
            cout << "\n Enter currency (USD / EUR / IRR): ";
            cin >> currency_code;
            cout << "\n Enter the amount you want to pay: ";
            cin >> user_amount;


            unique_ptr<Currency> payment;

            
            if (currency_code == "IRR" || currency_code == "irr") {
                payment = make_unique<IRR>(user_amount);
            } else if (currency_code == "USD" || currency_code == "usd") {
                payment = make_unique<USD>(user_amount);
            } else if (currency_code == "EUR" || currency_code == "eur") {
                payment = make_unique<EUR>(user_amount);
            } else {
                cerr << "Unknown currency entered.\n";
                return;
            }

            double payment_in_usd = payment->to_usd();

            if (payment_in_usd < amount) {
                cerr << "Payment is not enough.\n";
                 return;
            }

           

            if (costoumer->withdraw(std::move(payment), 1000)) {
                
                auto usd_payment = make_unique<USD>(amount);
                shop->deposit(std::move(usd_payment), 10000);

                cout << "\nYou bought " << tedad << " " << ItemName << " !!\n";

                double change = payment_in_usd - amount;
                if (change > 0.0) {
                    auto refund = make_unique<USD>(change);
                    costoumer->deposit(std::move(refund), 0);
                    cout << "Refunded $" << change << " to customer account.\n";
                }
                

            }
            
           
            item->buy(tedad) ; 
            SAVEresid("tina" , ItemName , amount , tedad) ;
            SHOWresid() ;  

             cout<<"\nperson balance after : "<<costoumer->getBalance()<<"$";
            
             cout<<"\nshop balance after :"<<shop->getBalance()<<"$";
            
            
            
            // cout<<"\n-----------------------------------\n";
            return; 
        }
    }
    cout << "item not found!! " << endl ;
    cout<<"-----------------------------------\n";
   
}