/*********************************************** 
 * Name: Chen Chen
 * Student ID: 20518383
 * File: aop.c 
 * CS 136 Fall 2014 - Assignment 8, Problem 4
 * Description: 
***********************************************/
#include "aop.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct aop *create_aop(int max){
    assert(max>0);
    struct aop *new = malloc(sizeof(struct aop));
    new->max = max;
    struct person **fun = malloc(max * (sizeof (int)));
    for (int i = 0; i<max; i++){
        fun[i] = NULL;
    }
    new->data = fun;
    return new;
}

void destroy_aop(struct aop *a){
    int i = 0;
    while(i < a->max){
        if (a->data[i] != NULL){
            free(a->data[i]);
        }
        ++i;
    }
    free(a->data);
    free(a);
}

//is_leap(struct date d) determine d is a leap year.
// PRE: True
// POST: Produced result is a boolean.
//       Produced valuse is true or false.
bool is_leap(struct date d){
    return (d.month==1 && d.day>=1&&d.day<=31)? true:
    (d.month==2 && d.day>=1&&d.day<=29)? true:(d.month==3 && d.day>=1&&d.day<=31)? true:
    (d.month==4 && d.day>=1&&d.day<=30)? true:(d.month==5 && d.day>=1&&d.day<=31)? true:
    (d.month==6 && d.day>=1&&d.day<=30)? true:(d.month==7 && d.day>=1&&d.day<=31)? true:
    (d.month==8 && d.day>=1&&d.day<=31)? true:(d.month==9 && d.day>=1&&d.day<=30)? true:
    (d.month==10 && d.day>=1&&d.day<=31)? true:(d.month==11 && d.day>=1&&d.day<=30)? true:
    (d.month==12 && d.day>=1&&d.day<=31)? true:false;
}

//not_leap(struct date d) determine d is not a leap year.
// PRE: True
// POST: Produced result is a boolean.
//       Produced valuse is true or false.
bool not_leap(struct date d){
    return (d.month==1 && d.day>=1&&d.day<=31)? true:
    (d.month==2 && d.day>=1&&d.day<=28)? true:(d.month==3 && d.day>=1&&d.day<=31)? true:
    (d.month==4 && d.day>=1&&d.day<=30)? true:(d.month==5 && d.day>=1&&d.day<=31)? true:
    (d.month==6 && d.day>=1&&d.day<=30)? true:(d.month==7 && d.day>=1&&d.day<=31)? true:
    (d.month==8 && d.day>=1&&d.day<=31)? true:(d.month==9 && d.day>=1&&d.day<=30)? true:
    (d.month==10 && d.day>=1&&d.day<=31)? true:(d.month==11 && d.day>=1&&d.day<=30)? true:
    (d.month==12 && d.day>=1&&d.day<=31)? true:false;
}

//is_valid(d) determines if d is a valid date
//PRE: d is a date
//POST: returns true if d is a valid date, false otherwise
bool is_valid(struct date d) {
    return ((d.year%4!=0) || (d.year%100==0 && d.year%400!=0))?
    not_leap(d):is_leap(d);
    return false;
}

int add_person(struct aop *a, char *name, struct date birthday){
    assert(a != NULL);
    assert(name != NULL);
    assert(is_valid(birthday));
    int pos = 0;
    while(pos < a->max){
        if (a->data[pos] == NULL){
           struct person *new = malloc(sizeof(struct person));
           strcpy(new->name, name);
           (new->birthday).year = birthday.year;
           (new->birthday).month = birthday.month;
           (new->birthday).day = birthday.day;
           a->data[pos] = new;
           return 0;
        }
        ++pos;
    }
    return -1;
}

struct person* get(const struct aop *a, int i){
    assert(a != NULL);
    assert(i >= 1);
    int count = 0;
    while (count < a->max){
        if((count == (i-1)) && (a->data[count] != NULL)){
            return a->data[count];
        }
        ++count;
    }
    return NULL;
}


int count(const struct aop *a){
    assert(a != NULL);
    int i = 0;
    int count=0;
    while (i < a->max){
        if (a->data[i] != NULL){
           ++count;
        }
        ++i;
    }
    return count;
}


int count_birthdays(const struct aop *a, int month){
    assert(a != NULL);
    assert(1 <= month <= 12);
    int i = 0;
    int count =0;
    while (i < a->max){
        if ((a->data[i] != NULL)
            && (month == (a->data[i]->birthday).month)){
            ++count;
        }
        ++i;
    }
    return count;
}

struct aop *birthdays(const struct aop *a, int month){
    assert(a != NULL);
    assert(1 <= month <= 12);
    struct aop *new = malloc(sizeof (struct aop));
    return new;
    free(new);
}


