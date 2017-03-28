//
// Created by netherblood on 28.03.17.
//

#include <netinet/in.h>
#include "Energy.h"



MacroNutrient::MacroNutrient(unsigned int grams) :
grams(grams) {
    this->calories = this->grams * caloriesPerGram;
}

MacroNutrient::MacroNutrient() {}

unsigned int MacroNutrient::getCalories() const {
    return this->calories;
}
unsigned int MacroNutrient::getGrams() const {
    return this->grams;
}

Protein::Protein(unsigned int grams) : MacroNutrient(grams) {}
Protein::Protein() {}

Protein Protein::operator+=(Protein protein) {
    this->grams += protein.grams;
    this->calories = this->grams + this->caloriesPerGram;
    return *this;
}

/************ FATS ************/

Fat::Fat(unsigned int grams) : MacroNutrient(grams) {}
Fat::Fat() {}
Fat Fat::operator+=(Fat fat) {
    this->grams += fat.getGrams();
    this->calories = this->grams * this->caloriesPerGram;
    return *this;
}
UnsaturatedFat::UnsaturatedFat(unsigned int grams) : Fat(grams) {}
UnsaturatedFat::UnsaturatedFat() {}

MonounsaturatedFat::MonounsaturatedFat(unsigned int grams) : UnsaturatedFat(grams) {}
MonounsaturatedFat::MonounsaturatedFat() {}

PolyunsaturatedFat::PolyunsaturatedFat(unsigned int grams) : UnsaturatedFat(grams) {}
PolyunsaturatedFat::PolyunsaturatedFat() {}

SaturatedFat::SaturatedFat(unsigned int grams) : Fat(grams) {}
SaturatedFat::SaturatedFat() {}

TransFat::TransFat(unsigned int grams) : Fat(grams) {}
TransFat::TransFat() {}

/************ FATS ************/

/************ CARBS ************/

Carbohydrate::Carbohydrate(unsigned int grams) : MacroNutrient(grams) {}
Carbohydrate::Carbohydrate() {}
Carbohydrate Carbohydrate::operator+=(Carbohydrate carb) {
    this->grams += carb.grams;
    this->calories = this->grams * this->caloriesPerGram;
    return *this;
}
Starch::Starch(unsigned int grams) : Carbohydrate(grams) {}
Starch::Starch() {}

Sugar::Sugar(unsigned int grams) : Carbohydrate(grams) {}
Sugar::Sugar() {}

Fiber::Fiber(unsigned int grams) : Carbohydrate(grams) {}
Fiber::Fiber() {}

/************ CARBS ************/