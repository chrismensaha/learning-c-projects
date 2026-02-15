#ifndef CALCULATOR_H
#define CALCULATOR_H

/**
 * @file calculator.h
 * @brief Basic arithmetic operation declarations.
 * 
 * This header provides function declarations for basic double-precision
 * floating-point arithmetic operations: addition, subtraction,
 * multiplication, and division.
 */

/**
 * @brief Adds two double-precision numbers.
 * 
 * @param addend_a The first number.
 * @param addend_b The second number.
 * @return The sum of addend_a and addend_b.
 */
double add(double addend_a, double addend_b);

/**
 * @brief Subtracts one double-precision number from another.
 * 
 * @param minuend The number from which to subtract.
 * @param subtrahend The number to subtract.
 * @return The result of minuend - subtrahend.
 */
double subtract(double minuend, double subtrahend);

/**
 * @brief Multiplies two double-precision numbers.
 * 
 * @param factor_a The first number.
 * @param factor_b The second number.
 * @return The product of factor_a and factor_b.
 */
double multiply(double factor_a, double factor_b);

/**
 * @brief Divides one double-precision number by another.
 * 
 * @param dividend The number to be divided.
 * @param divisor The number to divide by.
 * @return The quotient of dividend / divisor.
 * @note If divisor is zero, behavior is undefined unless handled elsewhere.
 */
double divide(double dividend, double divisor);

#endif // CALCULATOR_H