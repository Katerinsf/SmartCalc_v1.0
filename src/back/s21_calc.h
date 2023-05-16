#ifndef SRC_BACK_S21_CALC_H_
#define SRC_BACK_S21_CALC_H_

/*! \mainpage Drawing Shapes
 *
 *
 * Very Smart Calculator
 */

/*!
\file
*Header for Calculator
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Max size of string
#define buff_size 256
#define eps 1e-7

/// Code of error for parcer() and calc(). Expressions was parsed and calculated
#define OK 0
/// Code of error for parcer() and calc(). There is error of syntax
#define ERROR_SYNTAX 1
/// Code of error for parcer() and calc(). There is error of memory
#define ERROR_MEM 2
/// Code of error for parcer() and calc(). There is error of calculations
#define ERROR_CULC 3
/// Code of error for parcer() and calc(). No find varible
#define ERROR_X 4
/// Code of error for parcer() and calc(). The string is empty
#define ERROR_EMPTY 5

/// Costant for Data.type
#define EMPTY 0
/// Costant for Data.type
#define OPER 2

/// Token for last persed element of the string
typedef enum Token {
  START,
  /// Also it is costant for Data.type
  NUM,
  LPAR,
  RPAR,
  BI,
  UNO,
  FUNC,
  /// Also it is costant for Data.type
  VAR
} Token;

/// Struct for elements output string(array)
typedef struct Data {
  double num;  ///< Symbol of number, operator and function
  int type;    ///< Type of symbol. Vales: 1 - number, 2 - operator, 0 - empty
} Data;

// ------------ Notation ------------
/// Stack of operators and functions
typedef struct operators {
  char symb;               ///< Symbol of operator and function
  int priority;            ///< Priority of operator and function
  struct operators *next;  ///< Pointer to the next element
} operators;

/*!
    Converts string to RPN
    \param str Input string
    \param result String in RPN
    \result Code of error
*/
int parcer(const char *str, Data result[buff_size]);
/*!
    Adds operator to the stack or pops it from the stack, if the priority is
   less
*/
int add_oper(operators **head, char c, Data result[buff_size], int *i);
/*!
    Adds digit to the output array(string)
*/
void add_digit(Data *elem, char c, int flag_num);

/*!
    Initializes output array by zero
*/
void zero_init(Data str[buff_size]);

/*!
    Checks that lexeme is digit
*/
int digit_check(char c);

/*!
    Checks that lexeme is binary operator
*/
int binary_check(const char *str, int last);

/*!
    Checks that lexeme is unary operator
*/
int unary_check(const char *str, int last);

/*!
    Checks that lexeme is function
*/
int func_check(const char *str, int last);

/*!
    Determinates the priority
*/
int set_priority(char c);

/*!
    Determinates function and lenth of it
*/
int set_func(const char *str, char *f);

/*!
    Adds element to stack
*/
int push(operators **head, char symb);

/*!
    Pops element from stack
*/
char pop(operators **head);

/*!
    Deletes stack
*/
void delete_stack(operators **head);

// ------------ Calculation ------------
/// Stack of values during calculatoins
typedef struct Stack_calc {
  double value;             ///< Value
  struct Stack_calc *next;  ///< Pointer to the next element
} Stack_calc;

/*!
    Calculates the value of expression
    \param str Input string
    \param x Varible
    \param result Value of expression
    \result Code of error
*/
int calc(const char *str, Data x, double *result);

/*!
    Calculates value of expression with current operator
*/
int operation(Stack_calc **head, char oper);

/*!
    Checks if there is varible in a string
*/
int check_x(Data post_str[buff_size]);

/*!
    Substitutes a value into the varible
*/
void add_value_x(Data post_str[buff_size], double x);

/*!
    Adds
*/
int push_value(Stack_calc **head, double value);

/*!
    Adds element to stack
*/
double pop_value(Stack_calc **head);

/*!
    Pops element from stack
*/
void delete_stack_value(Stack_calc **head);

#endif  // SRC_BACK_S21_CALC_H_
