#include "s21_calc.h"


int main() {
    // char inf[buff_size];  // Входная строка в инфиксной нотации
    // scanf("%s", inf);
    // char *inf = "tan( 3.764) ^sin( 9.445-sin( 7.2889 /  8.0438 -cos( sin(cos( "
    //   "tan(8.4448))) - 4.482)  )  / tan(cos(cos(sin(cos( "
    //   "cos(2.003)) )  ) / 0.1315) ))  -    8.8453/ 0.3612";
    char *inf = "3^4+1*(2-4)/sin";
    // char *inf = "-sin(x)^2";
    // (3+1)*4)     1*(2-4)^4-5-(3+6)     )7+3     -6^(-3)+sin(30+3/cos(2 mod 4))
    // sin 1 + cos 2 + tan 3 *-asin 4 + acos 5    ln(3)^2-3
    // ((atan(1)+cos(2))^2 mod 1 - log(3))/sqrt(sin(3.14)) 
    // 1 + 6 mod 6 -    asin  ( 1 )  
    // 1 + 6 mod 6 -    sin ( 3.14/2 ) 
    printf("Inf_str:  %s\n", inf);
    
    Data post[buff_size];  // Входная строка в постфиксной нотации
    int res;

    res = parcer(inf, post);
    // parcer(inf, post);
    // printf("res = %s\n", res == 0 ? "OK" : "Error");
    // printf("res = %d\n", res);
    if (res == OK) {
        printf("Post_str: ");
        print_Data_str(post);
    } else {
        printf("res = %d\n", res);
        printf("Post_str: ");
        print_Data_str(post);
    }
    // tan( 3.764) ^sin( 9.445-sin( 7.2889 /  8.0438 -cos( sin(cos( tan(8.4448))) - 4.482)  )  / tan(cos(cos(sin(cos( cos(2.003)) )  ) / 0.1315) ))  -  8.8453/ 0.3612


    int res_calc;
    double a;
    Data x = {1, VAR};

    res_calc = calc(inf, x, &a);
    // printf("res_calc = %d\n", res_calc);
    if (res_calc == OK) {
        printf("VALUE = %lf\n", a);
    } else printf("res_calc = %d\n", res_calc);




    return 0;
}






// ----------- Print ----------
void print_Data_str(Data result[buff_size]) {
    char c;
    for (int i = 0; i < buff_size; i++) {
        if (result[i].type == NUM) {
            printf("%.3lf", result[i].num);
            printf(" ");
        } else if (result[i].type == OPER) {
            c = result[i].num;
            printf("%c", c);
            printf(" ");
        } else if (result[i].type == VAR) {
            // c = result[i].num;
            // printf("%c", c);
            printf("x ");
        }
        // else if (result[i].type == 0) {  // 0
        //     c = (char)((int)result[i].num + 48);
        //     printf("%c", c);
        // }
    }
    printf("\n");
}

