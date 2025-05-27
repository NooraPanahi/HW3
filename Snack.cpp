#include <string>
#include <algorithm>
#include "Snack.hpp"
using namespace std;


Snack::Snack (std::string n , int p , int a , string me) : Item(n , p , a) ,measurment(me){
    if (a <= 0 || p < 0 )
        throw invalid_argument("an item can not be negative!!");
    else{
        available = a ;
        price = p ; 
        name = n ; 
    }
}

string Snack::getInfo(){
    return get_Name() + " price: " + to_string(getPrice()) + ",available: " + to_string(get_available()) + " " + measurment ; 
}
std::string Snack::get_Name()const{
    return name ; 
}
int Snack::getPrice()const{
    return price ; 
}
int Snack::get_available()const{
    return available ; 
}
void Snack::buy(int b){
    if (!is_available())
        throw runtime_error("item not available") ; 
    else if(b > available)
        throw runtime_error("not enough item") ; 
    else if(b>0)
        set_available(available - b); 
}
void Snack::set_available(int a){
    available = a;
}
bool Snack::is_available()const{
    return available>0 ; 
}