#include "s21_calc.h"

int parcer(const char *str, Data result[buff_size]) {
  int error = strlen(str) < buff_size ? OK : ERROR_SYNTAX;
  int i = 0, len;
  Token last = START;  // The type of the previous element
  int flag_num = 0;    // The degree of multiplication by 10 (or 0.1 if < 0); =0
                       // if it wasn't a number before
  char f;
  operators *head = NULL;

  zero_init(result);

  while (*str && error == OK) {
    len = strlen(str) - 1;  // Remaining line length
    if (digit_check(*str) && last != FUNC && last != RPAR && last != VAR) {
      if (flag_num != 0) i--;
      add_digit(result + i, *str, flag_num);
      i++;
      if (flag_num >= 0)
        flag_num++;
      else
        flag_num--;
      last = NUM;
    } else if (*str == '.' && flag_num > 0) {
      flag_num = -1;
    } else if (*str == '(' && flag_num == 0 && last != RPAR && last != VAR &&
               len != 0) {
      error = push(&head, *str);
      last = LPAR;
    } else if (*str == ')' && (flag_num != 0 || last == RPAR || last == VAR)) {
      error = add_oper(&head, *str, result, &i);
      last = RPAR;
    } else if (binary_check(str, last) && len != 0) {
      if (!strncmp(str, "mod", 3)) {
        error = add_oper(&head, '%', result, &i);
        str += 2;
      } else
        error = add_oper(&head, *str, result, &i);
      last = BI;
    } else if (unary_check(str, last) && len != 0) {
      if (*str == '-') error = add_oper(&head, 'm', result, &i);
      last = UNO;
    } else if (func_check(str, last) && len != 0) {
      str += set_func(str, &f);
      error = add_oper(&head, f, result, &i);
      last = FUNC;
    } else if (*str == 'x' && flag_num == 0 && last != RPAR && last != FUNC) {
      result[i].num = (int)*str;
      result[i].type = VAR;
      i++;
      last = VAR;
    } else if (*str != ' ' && *str != '\0') {
      error = ERROR_SYNTAX;
    }
    if (last != NUM) flag_num = 0;
    str++;
  }

  while (error == OK && head) {
    result[i].num = pop(&head);
    result[i].type = OPER;
    if ((char)result[i].num == '(') error = ERROR_SYNTAX;
    i++;
  }
  if (error != OK) delete_stack(&head);
  if (error == OK && result->type == EMPTY) error = ERROR_EMPTY;

  return error;
}

int add_oper(operators **head, char c, Data result[buff_size], int *i) {
  int error = OK;
  while (*head && (*head)->priority >= set_priority(c) &&
         (*head)->priority != 0) {  // 0 - a priority for ()
    result[*i].num = pop(head);
    result[*i].type = OPER;
    (*i)++;
  }
  if (c != ')') {
    error = push(head, c);
  } else {
    if (*head) {
      pop(head);
    } else {  // No closing bracket
      error = ERROR_SYNTAX;
    }
  }
  return error;
}

void add_digit(Data *elem, char c, int flag_num) {
  if (elem->type == 0) {
    elem->num = 0.0;
    elem->type = NUM;
  }
  if (flag_num > 0)
    elem->num = elem->num * 10 + (int)(c - '0');
  else
    elem->num += (int)(c - '0') * pow(10, flag_num);
}

void zero_init(Data str[buff_size]) {
  for (int i = 0; i < buff_size; i++) {
    str[i].num = 0.0;
    str[i].type = EMPTY;
  }
}

int digit_check(char c) { return (c >= '0' && c <= '9') ? 1 : 0; }

int binary_check(const char *str, int last) {
  char *list = "+-*/^";
  int is_mod = (strchr(list, *str) || strstr(str, "mod") - str == 0);
  int last_ok = (last == NUM || last == RPAR || last == VAR);
  return (is_mod && last_ok) ? 1 : 0;
}

int unary_check(const char *str, int last) {
  int last_ok = (last == START || last == BI || last == LPAR || last == VAR);
  return ((*str == '+' || *str == '-') && last_ok) ? 1 : 0;
}

int func_check(const char *str, int last) {
  int i;
  char list[][5] = {"sin",  "cos",  "tan", "asin", "acos",
                    "atan", "sqrt", "ln",  "log"};
  for (i = 0; i < 9 && strncmp(str, list[i], strlen(list[i])) != 0; i++)
    ;

  return (i < 9 && last != NUM && last != RPAR && last != FUNC && last != VAR &&
          strlen(str) > strlen(list[i]))
             ? 1
             : 0;
}

int set_priority(char c) {
  int res;
  if (c == '(' || c == ')') {
    res = 0;
  } else if (c == '+' || c == '-') {
    res = 1;
  } else if (c == '*' || c == '/' || c == '%') {
    res = 2;
  } else if (c == '^') {
    res = 3;
  } else if (c == 'm') {
    res = 4;
  } else {  // Functions
    res = 7;
  }
  return res;
}

int set_func(const char *str, char *f) {
  int len;
  if (strstr(str, "sin") && strstr(str, "sin") == str) {
    *f = 's';
    len = 2;
  } else if (strstr(str, "cos") && strstr(str, "cos") == str) {
    *f = 'c';
    len = 2;
  } else if (strstr(str, "tan") && strstr(str, "tan") == str) {
    *f = 't';
    len = 2;
  } else if (strstr(str, "asin") && strstr(str, "asin") == str) {
    *f = 'S';
    len = 3;
  } else if (strstr(str, "acos") && strstr(str, "acos") == str) {
    *f = 'C';
    len = 3;
  } else if (strstr(str, "atan") && strstr(str, "atan") == str) {
    *f = 'T';
    len = 3;
  } else if (strstr(str, "sqrt") && strstr(str, "sqrt") == str) {
    *f = 'V';
    len = 3;
  } else if (strstr(str, "ln") && strstr(str, "ln") == str) {
    *f = 'l';
    len = 1;
  } else if (strstr(str, "log") && strstr(str, "log") == str) {
    *f = 'g';
    len = 2;
  }
  return len;
}

// ------------ Stack of Operators ------------
// 1 - OK, 0 - error
int push(operators **head, char symb) {  // Adds an element to the stack
  int res = ERROR_MEM;
  operators *new_elem = (operators *)calloc(1, sizeof(operators));
  if (new_elem != NULL) {
    res = OK;
    new_elem->next = *head;
    new_elem->symb = symb;
    new_elem->priority = set_priority(symb);
    *head = new_elem;
  }
  return res;
}

char pop(operators **head) {  // Pops an element from the stack
  char symb;
  operators *top = *head;
  symb = (*head)->symb;
  *head = (*head)->next;
  free(top);
  return symb;
}

void delete_stack(operators **head) {  // Removes the stack
  while (*head) {
    pop(head);
  }
}
