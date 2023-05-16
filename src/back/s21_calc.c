#include "s21_calc.h"

int calc(const char *str, Data x, double *result) {
  Data post_str[buff_size];
  Stack_calc *head = NULL;
  int i = 0;
  int error = parcer(str, post_str);

  if (error == OK && check_x(post_str)) {
    if (x.type == VAR)
      add_value_x(post_str, x.num);
    else
      error = ERROR_X;
  }

  while (error == OK && post_str[i].type != EMPTY) {
    if (post_str[i].type == NUM) {  // Number
      error = push_value(&head, post_str[i].num);
    } else {  // Operator
      error = operation(&head, post_str[i].num);
    }
    i++;
  }

  if (error == OK) *result = pop_value(&head);
  if (head != NULL) {
    error = ERROR_SYNTAX;
    delete_stack_value(&head);
  }

  return error;
}

int operation(Stack_calc **head, char oper) {
  int error;
  double a, b, c;
  a = pop_value(head);
  if (oper == '+') {
    b = pop_value(head);
    c = b + a;
  } else if (oper == '-') {
    b = pop_value(head);
    c = b - a;
  } else if (oper == '*') {
    b = pop_value(head);
    c = b * a;
  } else if (oper == '/') {
    b = pop_value(head);
    c = b / a;
  } else if (oper == '^') {
    b = pop_value(head);
    c = pow(b, a);
  } else if (oper == '%') {
    b = pop_value(head);
    c = fmod(b, a);
  } else if (oper == 'm') {
    c = -a;
  } else if (oper == 's') {
    c = sin(a);
  } else if (oper == 'c') {
    c = cos(a);
  } else if (oper == 't') {
    c = tan(a);
  } else if (oper == 'S') {
    c = asin(a);
  } else if (oper == 'C') {
    c = acos(a);
  } else if (oper == 'T') {
    c = atan(a);
  } else if (oper == 'V') {
    c = sqrt(a);
  } else if (oper == 'l') {
    c = log(a);
  } else if (oper == 'g') {
    c = log10(a);
  }
  error = push_value(head, c);
  return error;
}

int check_x(Data post_str[buff_size]) {
  int res = 0;
  for (int i = 0; i < buff_size; i++)
    if (post_str[i].type == VAR) res = 1;
  return res;
}

void add_value_x(Data post_str[buff_size], double x) {
  for (int i = 0; i < buff_size; i++)
    if (post_str[i].type == VAR) {
      post_str[i].num = x;
      post_str[i].type = NUM;
    }
}

// ------------ Stack of Number ------------
int push_value(Stack_calc **head,
               double value) {  // Adds an element to the stack
  int res = ERROR_MEM;
  Stack_calc *new_elem = (Stack_calc *)calloc(1, sizeof(Stack_calc));
  if (new_elem != NULL) {
    res = OK;
    new_elem->next = *head;
    new_elem->value = value;
    *head = new_elem;
  }
  return res;
}

double pop_value(Stack_calc **head) {  // Pops an element from the stack
  double value;
  Stack_calc *top = *head;
  value = (*head)->value;
  *head = (*head)->next;
  free(top);
  return value;
}

void delete_stack_value(Stack_calc **head) {  // Removes the stack
  while (*head) {
    pop_value(head);
  }
}
