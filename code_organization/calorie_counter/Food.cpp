//
// Created by netherblood on 28.03.17.
//

#include "Food.h"

Food::Food(Starch starch, Sugar sugar, Fiber fiber, PolyunsaturatedFat polyFat, MonounsaturatedFat monoFat,
           SaturatedFat saturatedFat, TransFat transFat) :
starch(starch), fiber(fiber), polyFat(polyFat), monoFat(monoFat), satFat(saturatedFat), transFat(transFat) {}
