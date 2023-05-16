#include <check.h>

#include "../back/s21_calc.h"

// #include "../tests/test.h"

// ------------------ num ------------------
START_TEST(parcer_error_num_1) {  // ERROR_SYNTAX
  char *inf = "3^4+1*(2-4)1";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_num_2) {
  char *inf = "1*(2-4)^4-5(3+6)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_num_3) {
  char *inf = "3^4+1*(2-4)/1sin(2)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_num_4) {
  char *inf = "1*(2-4)^4-sin 5/(3+6)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_num_5) {
  char *inf = "3^4+1*(2-4x)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_num_6) {
  char *inf = "1*(2-4)^4-sin(5)-x3";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

// START_TEST(parcer_ok_num_1) {
//   Data post[buff_size];
//   char *inf = "33+1.1";
//   int res = parcer(inf, post);
//   ck_assert_int_eq(res, OK);
// }
// END_TEST

// START_TEST(parcer_ok_num_2) {
//   Data post[buff_size];
//   char *inf = "33+1.1";
//   int res = parcer(inf, post);
//   ck_assert_int_eq(res, OK);
// }
// END_TEST

// ------------------ point ------------------
START_TEST(parcer_error_point_1) {
  char *inf = "1..+3";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_point_2) {
  char *inf = "1.1.1+3";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_point_3) {
  char *inf = ".1+3";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_point_4) {
  char *inf = "1.(4-6)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_point_5) {
  char *inf = "3^4+1*(.2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_point_6) {
  char *inf = "3^4+1*(2-4).1";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_point_7) {
  char *inf = "3^4+1*(2-4)/.1";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_point_8) {
  char *inf = "3^4+1*(2-4)/-.1";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_point_9) {
  char *inf = "3^4+sin .2";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_point_10) {
  char *inf = "3^4+1.ln(2)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_point_11) {
  char *inf = "3^4+1*(2-4)^x.1";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_point_12) {
  char *inf = "3^4+1*(2-4)/1.x";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_ok_point_1) {
  char *inf = "11.1+2.2";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(parcer_ok_point_2) {
  char *inf = "3.+2.2";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(parcer_ok_point_3) {
  char *inf = "3.11+2.";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

// ------------------ left parenthesis ------------------
START_TEST(parcer_error_leftpar_1) {
  char *inf = "3^4+1*9(2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_leftpar_2) {
  char *inf = "3^4+9.(2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_leftpar_3) {
  char *inf = "3^4+1*(.2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_leftpar_4) {
  char *inf = "3^4*1^()";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_leftpar_5) {
  char *inf = "7*(2-4)(6+9)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_leftpar_6) {
  char *inf = "3^4+1*9+(*2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_leftpar_7) {
  char *inf = "3^4+1*(";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_leftpar_8) {
  char *inf = "3^4+1*x(-2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_ok_leftpar_1) {
  char *inf = "3^4+7*9/(2^(5+6)-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(parcer_ok_leftpar_2) {
  char *inf = "3^4+7*9/((5+6)^2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(parcer_ok_leftpar_3) {  // Унарный(
  char *inf = "-(7+1)*8^3";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(parcer_ok_leftpar_4) {  // Бинарный(
  char *inf = "3^4*2+(9-1)/6";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(parcer_ok_leftpar_5) {  // (Унарный
  char *inf = "7*(-2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(parcer_ok_leftpar_6) {
  char *inf = "(4-5)^7";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

// ------------------ right parenthesis ------------------
START_TEST(parcer_error_rightpar_1) {
  char *inf = "3^4+1*(2-4)7";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_rightpar_2) {
  char *inf = "3^4+1*(2-4).7";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_rightpar_3) {
  char *inf = "3^4+1*()";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_rightpar_4) {
  char *inf = "3^4+1*(2-4)(7)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_rightpar_5) {
  char *inf = "3^4+1*(2-4+)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_rightpar_6) {
  char *inf = ")7+3";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_rightpar_7) {
  char *inf = "3^4+1*(2-atan)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_rightpar_8) {
  char *inf = "3^4+1*(2-4)sqrt(3)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_rightpar_9) {
  char *inf = "3^4+1*(2-4)x";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_ok_rightpar_1) {
  char *inf = "3^4+7*9/(2^(5+6)-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(parcer_ok_rightpar_2) {
  char *inf = "3^4+7.1*9/((5+6.)^2-4.)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(parcer_ok_rightpar_3) {
  char *inf = "-(7+1)*8^(2-(4.2-5.1))";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(parcer_ok_rightpar_4) {  // )Бинарный
  char *inf = "3^4*2+(9-1)/6";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(parcer_ok_rightpar_5) {
  char *inf = "7*(-2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, OK);
}
END_TEST

// ------------------ binary ------------------
START_TEST(parcer_error_binary_1) {
  char *inf = "3^4+1*.7";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_binary_2) {
  char *inf = "3^4+1*(2-4^)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_binary_3) {
  char *inf = "3^4+1*/5";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_binary_4) {
  char *inf = "3^4+1*(-^2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_binary_5) {
  char *inf = "3^4+1*cos*(2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_binary_6) {
  char *inf = "5^(*2-3)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_binary_7) {
  char *inf = "^3";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_binary_8) {
  char *inf = "3^4+1*(2-4)^";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

// ------------------ unary ------------------
START_TEST(parcer_error_unary_1) {
  char *inf = "3^4+1*(-.7)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_unary_2) {
  char *inf = "2-4.-";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_unary_3) {
  char *inf = "3^4+1*(8/5-)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_unary_4) {
  char *inf = "3^4+1*(-+2-4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_unary_5) {
  char *inf = "-";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_unary_6) {
  char *inf = "x-*7";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

// ------------------ function ------------------
START_TEST(parcer_error_func_1) {
  char *inf = "3^4+1*(2-4)^sin 8";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_func_2) {
  char *inf = "3^4+1*(2-4)-sin -8";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_func_3) {
  char *inf = "3^4+1*sin sin (7)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_func_4) {
  char *inf = "3^4+1*(2-4)-4 sin(3)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_func_5) {
  char *inf = "3^4+1*(2-4+4.1 sin(10))";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_func_6) {
  char *inf = "3+sin .1";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_func_7) {
  char *inf = "3^4+1*(2-1)atan(6)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_func_8) {
  char *inf = "3^4+1*(2-4*sqrt)/(3)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_func_9) {
  char *inf = "3^4+1*(2-4)/sin *x";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_func_10) {
  char *inf = "3^4+1*(2-4)/sin";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_func_11) {
  char *inf = "3^4+1*(2-4)/sin x";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_func_12) {
  char *inf = "3^4+1*(2-4)/x sin(3)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

// ------------------ X ------------------
START_TEST(parcer_error_x_1) {
  char *inf = "3^4+1 x";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_x_2) {
  char *inf = "3^4+1*(2-x 4)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_x_3) {
  char *inf = "3^4+1*5/x(5)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_x_4) {
  char *inf = "3^4+1*(-2-4)x";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_x_5) {
  char *inf = "3^4+1*cos(2-4. x)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_x_6) {
  char *inf = "5^(2-x.3)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_x_7) {
  char *inf = "1^3-sin x";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parcer_error_x_8) {
  char *inf = "3^4+1*(2-4)^x sin(19)";
  Data post[buff_size];
  int res = parcer(inf, post);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

// ------------------ input error ------------------
START_TEST(parser_error_input_1) {
  char *inf =
      "123456789012345678901234567890123456789012345678901234567890123456789012"
      "345678901234567890123456789012345678901234567890123456789012345678901234"
      "567890123456789012345678901234567890123456789012345678901234567890123456"
      "7890123456789012345678901234567890123456";
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parser_error_input_2) {
  char *inf = "123456789/(11.1+4";
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, ERROR_SYNTAX);
}
END_TEST

START_TEST(parser_error_input_3) {
  char *inf = "123456789/11.1+x";
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, ERROR_X);
}
END_TEST

// ------------------ Calc ------------------
START_TEST(calc_1) {
  char *inf = "1234.9824+89812.1246";
  double value_real = 1234.9824 + 89812.1246;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_2) {
  char *inf = "1234.9824+x";
  double value_real = 1234.9824 + 89812.1246;
  double value;
  Data x = {89812.1246, VAR};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_3) {
  char *inf = "1.2+2.3-4.5+6.7-9.8-2.3*10.11/12.13";
  double value_real = 1.2 + 2.3 - 4.5 + 6.7 - 9.8 - 2.3 * 10.11 / 12.13;
  double value;
  Data x = {0.0, EMPTY};
  ;
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_4) {
  char *inf =
      "tan( 3.764) ^sin( 9.445-sin( 7.2889 /  8.0438 -cos( sin(cos( "
      "tan(8.4448))) - 4.482)  )  / tan(cos(cos(sin(cos( "
      "cos(2.003)) )  ) / 0.1315) ))  -  8.8453/ 0.3612";
  double value_real = -23.76667454586336;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_5) {
  char *inf = "1234.9824-89812.1246";
  double value_real = 1234.9824 - 89812.1246;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_6) {
  char *inf = "-3-4+5";
  double value_real = -3 - 4 + 5;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_7) {
  char *inf = "-3*-2";
  double value_real = -3 * -2;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_8) {
  char *inf = "sin(-3)";
  double value_real = sin(-3);
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_9) {
  char *inf = "1234.98234*89812.12456";
  double value_real = 1234.98234 * 89812.12456;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_10) {
  char *inf = "1234.98234 / 89812.12456";
  double value_real = 1234.98234 / 89812.12456;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_11) {
  char *inf = "12^3.123";
  double value_real = pow(12, 3.123);
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_12) {
  char *inf = "2^(2^3)";
  double value_real = 256.0;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_13) {
  char *inf = "sqrt(980987)";
  double value_real = sqrt(980987);
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_14) {
  char *inf = "1235.432mod12398793.234";
  double value_real = fmod(1235.432, 12398793.234);
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_15) {
  char *inf = "1235.432mod12398793.234 * 37";
  double value_real = fmod(1235.432, 12398793.234) * 37;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_16) {
  char *inf = "cos(1.98087)";
  double value_real = cos(1.98087);
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_17) {
  char *inf = "tan(1.98087)";
  double value_real = tan(1.98087);
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_18) {
  char *inf = "asin(0.98087)";
  double value_real = asin(0.98087);
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_19) {
  char *inf = "asin(1.98087)";
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_nan(value);
}
END_TEST

START_TEST(calc_20) {
  char *inf = "acos(0.123)";
  double value_real = 1.44748405;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_21) {
  char *inf = "atan(1.98087)";
  double value_real = 1.103293234;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_22) {
  char *inf = "ln(1.98087)";
  double value_real = 0.683536142;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_23) {
  char *inf = "log(1.98087)";
  double value_real = 0.29685597;
  double value;
  Data x = {0.0, EMPTY};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

START_TEST(calc_24) {
  char *inf = "(1+2)*4*cos(x*7-2)+sin(x*2)";
  double value_real = 9.36944500948197;
  double value;
  Data x = {2.0, VAR};
  int res = calc(inf, x, &value);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(value_real, value, eps);
}
END_TEST

Suite *s21_parser(void) {
  // void s21_parser(Suite *s) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_parcer");
  tc_core = tcase_create("Core");

  // ------------------ num ------------------
  tcase_add_test(tc_core, parcer_error_num_1);
  tcase_add_test(tc_core, parcer_error_num_2);
  tcase_add_test(tc_core, parcer_error_num_3);
  tcase_add_test(tc_core, parcer_error_num_4);
  tcase_add_test(tc_core, parcer_error_num_5);
  tcase_add_test(tc_core, parcer_error_num_6);

  // ------------------ point ------------------
  tcase_add_test(tc_core, parcer_error_point_1);
  tcase_add_test(tc_core, parcer_error_point_2);
  tcase_add_test(tc_core, parcer_error_point_3);
  tcase_add_test(tc_core, parcer_error_point_4);
  tcase_add_test(tc_core, parcer_error_point_5);
  tcase_add_test(tc_core, parcer_error_point_6);
  tcase_add_test(tc_core, parcer_error_point_7);
  tcase_add_test(tc_core, parcer_error_point_8);
  tcase_add_test(tc_core, parcer_error_point_9);
  tcase_add_test(tc_core, parcer_error_point_10);
  tcase_add_test(tc_core, parcer_error_point_11);
  tcase_add_test(tc_core, parcer_error_point_12);

  tcase_add_test(tc_core, parcer_ok_point_1);
  tcase_add_test(tc_core, parcer_ok_point_2);
  tcase_add_test(tc_core, parcer_ok_point_3);

  // ------------------ left parenthesis ------------------
  tcase_add_test(tc_core, parcer_error_leftpar_1);
  tcase_add_test(tc_core, parcer_error_leftpar_2);
  tcase_add_test(tc_core, parcer_error_leftpar_3);
  tcase_add_test(tc_core, parcer_error_leftpar_4);
  tcase_add_test(tc_core, parcer_error_leftpar_5);
  tcase_add_test(tc_core, parcer_error_leftpar_6);
  tcase_add_test(tc_core, parcer_error_leftpar_7);
  tcase_add_test(tc_core, parcer_error_leftpar_8);

  tcase_add_test(tc_core, parcer_ok_leftpar_1);
  tcase_add_test(tc_core, parcer_ok_leftpar_2);
  tcase_add_test(tc_core, parcer_ok_leftpar_3);
  tcase_add_test(tc_core, parcer_ok_leftpar_4);
  tcase_add_test(tc_core, parcer_ok_leftpar_5);
  tcase_add_test(tc_core, parcer_ok_leftpar_6);

  // ------------------ right parenthesis ------------------
  tcase_add_test(tc_core, parcer_error_rightpar_1);
  tcase_add_test(tc_core, parcer_error_rightpar_2);
  tcase_add_test(tc_core, parcer_error_rightpar_3);
  tcase_add_test(tc_core, parcer_error_rightpar_4);
  tcase_add_test(tc_core, parcer_error_rightpar_5);
  tcase_add_test(tc_core, parcer_error_rightpar_6);
  tcase_add_test(tc_core, parcer_error_rightpar_7);
  tcase_add_test(tc_core, parcer_error_rightpar_8);
  tcase_add_test(tc_core, parcer_error_rightpar_9);

  tcase_add_test(tc_core, parcer_ok_rightpar_1);
  tcase_add_test(tc_core, parcer_ok_rightpar_2);
  tcase_add_test(tc_core, parcer_ok_rightpar_3);
  tcase_add_test(tc_core, parcer_ok_rightpar_4);
  tcase_add_test(tc_core, parcer_ok_rightpar_5);

  // ------------------ binary ------------------
  tcase_add_test(tc_core, parcer_error_binary_1);
  tcase_add_test(tc_core, parcer_error_binary_2);
  tcase_add_test(tc_core, parcer_error_binary_3);
  tcase_add_test(tc_core, parcer_error_binary_4);
  tcase_add_test(tc_core, parcer_error_binary_5);
  tcase_add_test(tc_core, parcer_error_binary_6);
  tcase_add_test(tc_core, parcer_error_binary_7);
  tcase_add_test(tc_core, parcer_error_binary_8);

  // ------------------ unary ------------------
  tcase_add_test(tc_core, parcer_error_unary_1);
  tcase_add_test(tc_core, parcer_error_unary_2);
  tcase_add_test(tc_core, parcer_error_unary_3);
  tcase_add_test(tc_core, parcer_error_unary_4);
  tcase_add_test(tc_core, parcer_error_unary_5);
  tcase_add_test(tc_core, parcer_error_unary_6);

  // ------------------ function ------------------
  tcase_add_test(tc_core, parcer_error_func_1);
  tcase_add_test(tc_core, parcer_error_func_2);
  tcase_add_test(tc_core, parcer_error_func_3);
  tcase_add_test(tc_core, parcer_error_func_4);
  tcase_add_test(tc_core, parcer_error_func_5);
  tcase_add_test(tc_core, parcer_error_func_6);
  tcase_add_test(tc_core, parcer_error_func_7);
  tcase_add_test(tc_core, parcer_error_func_8);
  tcase_add_test(tc_core, parcer_error_func_9);
  tcase_add_test(tc_core, parcer_error_func_10);
  tcase_add_test(tc_core, parcer_error_func_11);
  tcase_add_test(tc_core, parcer_error_func_12);

  // ------------------ X ------------------
  tcase_add_test(tc_core, parcer_error_x_1);
  tcase_add_test(tc_core, parcer_error_x_2);
  tcase_add_test(tc_core, parcer_error_x_3);
  tcase_add_test(tc_core, parcer_error_x_4);
  tcase_add_test(tc_core, parcer_error_x_5);
  tcase_add_test(tc_core, parcer_error_x_6);
  tcase_add_test(tc_core, parcer_error_x_7);
  tcase_add_test(tc_core, parcer_error_x_8);

  // ------------------ input error ------------------
  tcase_add_test(tc_core, parser_error_input_1);
  tcase_add_test(tc_core, parser_error_input_2);
  tcase_add_test(tc_core, parser_error_input_3);

  // ------------------ Calc ------------------
  tcase_add_test(tc_core, calc_1);
  tcase_add_test(tc_core, calc_2);
  tcase_add_test(tc_core, calc_3);
  tcase_add_test(tc_core, calc_4);
  tcase_add_test(tc_core, calc_5);
  tcase_add_test(tc_core, calc_6);
  tcase_add_test(tc_core, calc_7);
  tcase_add_test(tc_core, calc_8);
  tcase_add_test(tc_core, calc_9);
  tcase_add_test(tc_core, calc_10);
  tcase_add_test(tc_core, calc_11);
  tcase_add_test(tc_core, calc_12);
  tcase_add_test(tc_core, calc_13);
  tcase_add_test(tc_core, calc_14);
  tcase_add_test(tc_core, calc_15);
  tcase_add_test(tc_core, calc_16);
  tcase_add_test(tc_core, calc_17);
  tcase_add_test(tc_core, calc_18);
  tcase_add_test(tc_core, calc_19);
  tcase_add_test(tc_core, calc_20);
  tcase_add_test(tc_core, calc_21);
  tcase_add_test(tc_core, calc_22);
  tcase_add_test(tc_core, calc_23);
  tcase_add_test(tc_core, calc_24);

  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int no_failed;
  Suite *s;
  SRunner *sr;

  s = s21_parser();
  sr = srunner_create(s);

  // srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  // srunner_run_all(sr, CK_VERBOSE);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
