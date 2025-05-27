#ifndef CURRENCY_HPP
#define CURRENCY_HPP
#include <iostream>

// این فایل فقط برای پیاده سازی کلاس های مشتق شدست
class Currency {
    friend std::ostream& operator<<(std::ostream & output , Currency& c);
    public:
        virtual double to_usd() const = 0;
        virtual ~Currency() = default;
    };

#endif