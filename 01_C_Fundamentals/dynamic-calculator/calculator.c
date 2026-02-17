#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

/**
 * @brief Adds two double-precision numbers.
 * @return The sum of addend_a and addend_b.
 */
double add(double addend_a, double addend_b) {
    return addend_a + addend_b;
}

/**
 * @brief Subtracts subtrahend from minuend.
 * @return The result of minuend - subtrahend.
 */
double subtract(double minuend, double subtrahend) {
    return minuend - subtrahend;
}

/**
 * @brief Multiplies two double-precision numbers.
 * @return The product of factor_a and factor_b.
 */
double multiply(double factor_a, double factor_b) {
    return factor_a * factor_b;
}

/**
 * @brief Divides dividend by divisor.
 * @return The result of dividend / divisor.
 * @note If divisor is 0, behavior is undefined unless handled elsewhere.
 */
double divide(double dividend, double divisor) {
    return dividend / divisor;  // Could add a check here if desired
}