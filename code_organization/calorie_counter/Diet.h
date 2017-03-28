//
// Created by netherblood on 28.03.17.
//

#ifndef CALORIE_COUNTER_DIET_H
#define CALORIE_COUNTER_DIET_H


#include "Energy.h"

class Diet {
private:
    // the amount of macro nutrients this diet aims for
    Protein proteinGoal;

    Carbohydrate carbGoal;
    Starch starchGoal;
    Sugar sugarGoal;
    Fiber fiberGoal;

    Fat fatGoal;
    MonounsaturatedFat monoFatGoal;
    PolyunsaturatedFat polyFatGoal;
    SaturatedFat saturatedFatGoal;
    TransFat transFatGoal;

    unsigned int calorieGoal;
public:
    Diet(Protein proteinGoal, Carbohydrate carbGoal, Fat fatGoal, unsigned int calorieGoal);

    unsigned int getCalorieGoal();
};


#endif //CALORIE_COUNTER_DIET_H
