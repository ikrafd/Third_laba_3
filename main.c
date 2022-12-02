#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <complex.h>
float a, b, c, p, q, d, u, v, r, fi, first_root, second_root, third_root, first_x, second_x, third_x, sum_root;
float complex second_root_com, third_root_com;
char er, symbol;
void check_number();
void check_root ();
int main() {
    do //Введення a
    {
        er = 0;
        printf("First coefficient a=");
        scanf("%f%c", &a, &symbol);
        check_number();
    } while (er != 0);
    symbol = 0;

    do //Введення b
    {
        er = 0;
        printf("Second coefficient b=");
        scanf("%f%c", &b, &symbol);
        check_number();
    } while (er != 0);
    symbol = 0;

    do //Введення c
    {
        er = 0;
        printf("Third coefficient c= ");
        scanf("%f%c", &c, &symbol);
        check_number();
    } while (er != 0);

    p = b - ((powf(a,2)) / 3);
    q = 2 * powf(a,3)/ 27 - a*b / 3 + c;
    d = powf(p,3) / 27 + powf(q,2) / 4;
    printf("d=%f\n",d);

    if (d>0){
        u = cbrtf((-q/2)+sqrtf(d));
        if (u==0){
            printf("Impossible to calculate");
        } else {
            v = -p / (3 * u);
            first_root = u + v - (a / 3);
            second_root_com = (-(u + v) / 2) - (a / 3) + ((sqrtf(3) * (u - v)) / 2) * I;
            third_root_com = (-(u + v) / 2) - (a / 3) + (-(sqrtf(3) * (u - v)) / 2) * I;
            printf("First root =%f\n"
                   "Second root =%f%+fi\n"
                   "Third root =%f%+fi\n", first_root, crealf(second_root_com), cimagf(second_root_com),
                   crealf(third_root_com), cimagf(third_root_com));
        }
    } else if (d==0) {
        if (p==0) {
            printf("Impossible to calculate");
        } else{
            first_root = (3 * q) / p;
            second_root = third_root = -(3 * q) / (2 * p);
            check_root ();
        }
    }else if (d<0) {
        r=(- powf(p,3) / 27);
        if (r>=0) {
            r = sqrtf(r);
            fi = acosf(-q / (2 * r));
            first_root = 2 * fabsf(cbrtf(r)) * cosf(fi / 3);
            second_root = 2 * fabsf(cbrtf(r)) * cosf((fi + 2 * M_PI) / 3);
            third_root = 2 * fabsf(cbrtf(r)) * cosf((fi + 4 * M_PI) / 3);
            check_root ();
        } else {
            printf("Error \n");
        }

    }
    getch();
  return 0;
}

void check_number(){
    if (symbol != '\n')
    {
        er = 1;
        while ((getchar()) != '\n');
        printf("Enter number without symbol\n");
    }
}

void check_root () {
    first_x = first_root - (a/3);
    second_x = second_root - (a/3);
    third_x = third_root - (a/3);
    if (((powf(first_x,3)+a*powf(first_x,2)+b*first_x+c)==0)&&((powf(second_x,3)+a*powf(second_x,2)+b*second_x+c)==0)&&
            ((powf(third_x,3)+a*powf(third_x,2)+b*third_x+c)==0)
    ){
        printf("First root =%f\n"
               "Second root =%f\n"
               "Third root =%f\n", first_x, second_x, third_x);
    }else {
        sum_root = (powf(first_x, 3) + a * powf(first_x, 2) + b * first_x + c) +
                   (powf(second_x, 3) + a * powf(second_x, 2) + b * second_x + c)
                   + (powf(third_x, 3) + a * powf(third_x, 2) + b * third_x + c);
        sum_root = roundf(sum_root * 100) / 100;
        if ((sum_root > 0.01) || (sum_root < -0.01)) {
            printf("No roots");
        } else {
            printf("First root =%f\n"
                   "Second root =%f\n"
                   "Third root =%f\n", first_x, second_x, third_x);
        }
    }
}