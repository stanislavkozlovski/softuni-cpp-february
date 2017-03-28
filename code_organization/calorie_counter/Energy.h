//
// Created by netherblood on 28.03.17.
//

#include <clocale>

#ifndef CALORIE_COUNTER_MACRO_NUTRIENT_H
#define CALORIE_COUNTER_MACRO_NUTRIENT_H

class MacroNutrient {
protected:
    MacroNutrient();
    MacroNutrient(unsigned int grams);
    unsigned int calories;
    unsigned const static int caloriesPerGram = NULL;
    unsigned int grams;
public:
    unsigned int getCalories() const;
    unsigned int getGrams() const;
};

#endif //CALORIE_COUNTER_MACRO_NUTRIENT_H


#ifndef CALORIE_COUNTER_PROTEIN_H
#define CALORIE_COUNTER_PROTEIN_H

class Protein : public MacroNutrient {
private:
    unsigned const static int caloriesPerGram = 4;
public:
    Protein(unsigned int grams);
    Protein();

    Protein operator+=(Protein protein);
};

#endif //CALORIE_COUNTER_PROTEIN_H


#ifndef CALORIE_COUNTER_FAT_H
#define CALORIE_COUNTER_FAT_H

class Fat: public MacroNutrient {
    friend class Person;
private:
    unsigned const static int caloriesPerGram = 9;
protected:
    Fat(unsigned int grams);
    Fat();

public:
    Fat operator+=(Fat fat);
};

#endif // CALORIE_COUNTER_FAT_H

#ifndef CALORIE_COUNTER_UNSATURATED_FAT_H
#define CALORIE_COUNTER_UNSATURATED_FAT_H

class UnsaturatedFat : public Fat {
protected:
    UnsaturatedFat(unsigned int grams);
    UnsaturatedFat();
};

#endif // CALORIE_COUNTER_UNSATURATED_FAT_H

#ifndef CALORIE_COUNTER_MONOUNSATURATED_FAT_H
#define CALORIE_COUNTER_MONOUNSATURATED_FAT_H

class MonounsaturatedFat : public UnsaturatedFat {
public:
    MonounsaturatedFat(unsigned int grams);

    MonounsaturatedFat();
};

#endif // CALORIE_COUNTER_MONOUNSATURATED_FAT_H

#ifndef CALORIE_COUNTER_POLYUNSATURATED_FAT_H
#define CALORIE_COUNTER_POLYUNSATURATED_FAT_H

class PolyunsaturatedFat : public UnsaturatedFat {
public:
    PolyunsaturatedFat(unsigned int grams);

    PolyunsaturatedFat();
};

#endif // CALORIE_COUNTER_POLYUNSATURATED_FAT_H

#ifndef CALORIE_COUNTER_SATURATED_FAT_H
#define CALORIE_COUNTER_SATURATED_FAT_H

class SaturatedFat : public Fat {
public:
    SaturatedFat(unsigned int grams);

    SaturatedFat();
};

#endif //CALORIE_COUNTER_SATURATED_FAT_H

#ifndef CALORIE_COUNTER_TRANS_FAT_H
#define CALORIE_COUNTER_TRANS_FAT_H

class TransFat : public Fat {
public:
    TransFat(unsigned int grams);

    TransFat();
};

#endif //CALORIE_COUNTER_TRANS_FAT_H


#ifndef CALORIE_COUNTER_CARBOHYDRATE_H
#define CALORIE_COUNTER_CARBOHYDRATE_H

class Carbohydrate : public MacroNutrient {
    friend class Person;
private:
    unsigned static const int caloriesPerGram = 4;

protected:

    Carbohydrate(unsigned int grams);
    Carbohydrate();

public:
    Carbohydrate operator+=(Carbohydrate carb);

};

#endif //CALORIE_COUNTER_CARBOHYDRATE_H

#ifndef CALORIE_COUNTER_STARCH_H
#define CALORIE_COUNTER_STARCH_H

class Starch : public Carbohydrate {
public:
    Starch(unsigned int grams);

    Starch();
};

#endif //CALORIE_COUNTER_STARCH_H

#ifndef CALORIE_COUNTER_SUGAR_H
#define CALORIE_COUNTER_SUGAR_H

class Sugar : public Carbohydrate {
public:
    Sugar(unsigned int grams);

    Sugar();
};

#endif // CALORIE_COUNTER_SUGAR_H

#ifndef CALORIE_COUNTER_FIBER_H
#define CALORIE_COUNTER_FIBER_H

class Fiber : public Carbohydrate {
public:
    Fiber(unsigned int grams);

    Fiber();
};

#endif //CALORIE_COUNTER_FIBER_H