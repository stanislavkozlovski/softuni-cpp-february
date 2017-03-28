//
// Created by netherblood on 28.03.17.
//

#ifndef CALORIE_COUNTER_FOOD_H
#define CALORIE_COUNTER_FOOD_H


#include "Energy.h"

class Food {
private:
    Starch starch;
    Sugar sugar;
    Fiber fiber;

    PolyunsaturatedFat polyFat;
    MonounsaturatedFat monoFat;
    SaturatedFat satFat;
    TransFat transFat;

    Protein protein;
public:
    Food(Starch starch, Sugar sugar, Fiber fiber, PolyunsaturatedFat polyFat, MonounsaturatedFat monoFat, SaturatedFat saturatedFat,
    TransFat transFat);
};


#endif //CALORIE_COUNTER_FOOD_H
