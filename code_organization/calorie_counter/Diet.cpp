//
// Created by netherblood on 28.03.17.
//

#include "Diet.h"

Diet::Diet(Protein proteinGoal, Carbohydrate carbGoal, Fat fatGoal, unsigned int calorieGoal) :
proteinGoal(proteinGoal), carbGoal(carbGoal), fatGoal(fatGoal), calorieGoal(calorieGoal) {}

unsigned int Diet::getCalorieGoal() {
    return this->calorieGoal;
}
