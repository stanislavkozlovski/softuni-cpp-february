//
// Created by netherblood on 28.03.17.
//

#ifndef CALORIE_COUNTER_PERSON_H
#define CALORIE_COUNTER_PERSON_H


#include "Energy.h"
#include "Diet.h"

class Person {
    Protein ingestedProtein;

    Carbohydrate ingestedCarbs;
    Starch ingestedStarch;
    Sugar ingestedSugar;
    Fiber ingestedFiber;

    Fat ingestedFat;

    int ingestedCalories;
    unsigned int excessCalories;
    double kilograms;
    const static unsigned int maintenanceCalories = 2000;
    bool brokeDiet = false;
    Diet diet;

    void ingestCalories(MacroNutrient &macroNutrient);
public:
    Person(Diet diet, double kilograms);

    void sleep();

    void ingestFat(Fat &fat);

    void ingestProtein(Protein &protein);

    void ingestStarch(Starch &starch);
    void ingestSugar(Sugar &sugar);
    void ingestFiber(Fiber &fiber);
};


#endif //CALORIE_COUNTER_PERSON_H
