//
// Created by netherblood on 28.03.17.
//

#include "Person.h"
#include "constants.h"

Person::Person(Diet diet, double kilograms) : diet(diet), kilograms(kilograms){
    this->ingestedCarbs = Carbohydrate(0);
    this->ingestedFat = Fat(0);
    this->ingestedProtein = Protein(0);
}

void Person::ingestCalories(MacroNutrient &macroNutrient) {
    this->ingestedCalories += macroNutrient.getCalories();

    if (this->ingestedCalories > this->diet.getCalorieGoal()) {
        // We've passed the recommended calories
        this->brokeDiet = true;
        this->excessCalories = this->ingestedCalories - this->diet.getCalorieGoal();
    }
}

void Person::ingestStarch(Starch &starch) {
    this->ingestedStarch += starch;
    this->ingestedCarbs += starch;
    this->ingestCalories(starch);
}

void Person::ingestSugar(Sugar &sugar) {
    this->ingestedSugar += sugar;
    this->ingestedCarbs += sugar;
    this->ingestCalories(sugar);
}

void Person::ingestFiber(Fiber &fiber) {
    this->ingestedFiber += fiber;
    this->ingestedCarbs += fiber;
    this->ingestCalories(fiber);
}

void Person::ingestFat(Fat &fat) {
    this->ingestedFat += fat;
    this->ingestCalories(fat);
}

void Person::ingestProtein(Protein &protein) {
    this->ingestedProtein += protein;
    this->ingestCalories(protein);
}

void Person::sleep() {
    /* Restart the day for the person, gain/lose weight and clear all calories */
    if (this->ingestedCalories > this->maintenanceCalories) {
        /* Gained weight */
        unsigned int excessCalories = this->ingestedCalories - this->maintenanceCalories;
        double kilogramsGained = excessCalories * KILOGRAMS_PER_1_CALORIE;
        this->kilograms += kilogramsGained;
    } else {
        /* Lost weight*/
        unsigned int deficientCalories = this->maintenanceCalories - this->ingestedCalories;
        double kilogramsLost = deficientCalories * KILOGRAMS_PER_1_CALORIE;
        this->kilograms -= kilogramsLost;
    }

    this->ingestedCalories = 0;
    this->ingestedCarbs = Carbohydrate();
    // TODO: reset others
//    delete this->ingestedCarbs;
//
//    delete this->ingestedStarch;
//    delete this->ingestedSugar;
//    delete this->ingestedFiber;
//
//    delete this->ingestedProtein;
//
//    delete this->ingestedFat;
}


