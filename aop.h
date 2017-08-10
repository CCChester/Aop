/**
 * File: aop.h
 * Enter a description of this file.
*/

// a module for handling people and their birthdays

struct date {
	int year;
	int month;
	int day;
};

struct person{
	char name[64];
	struct date birthday;
};

struct aop {
   int max;
   struct person **data;
};


// create_aop(max) returns a new aop structure with enough capacity to store max people
//     initially, it contains no people, so each entry is a NULL pointer
//   PRE:  max > 0
//   POST: caller must eventually call destroy_aop() to free
//   TIME: O(n), where n = max
struct aop *create_aop(int max);

// destroy_aop(a) will first free all of the people in a
//     and then will free the array of people in a
//     and then finally will free the structure a itself
//   PRE:  a was previously returned from create_aop
//   POST: a is no longer valid,
//           any entry (person *) obtained from a is invalid
//   TIME: O(n), where n = a->max
void destroy_aop(struct aop *a);


// add_person(a,n,b) adds a new person to a, with name n and birthday b, if possible
//   PRE: a is not NULL, n is not NULL, b is a valid date
//   POST: if a had a free space (a->data contained fewer than a->max entries), then the first free slot in a will contain a new person *, 
//          with name n, and birthday b.  In this case, 0 will be returned.
//       if a did not have free space, then no changes will be made to a, and -1 will be returned
//   TIME: O(n), where n = a->max
int add_person(struct aop *a, char *name, struct date birthday);


// get(a,i) gets the ith person from a, in whatever order they are contained within data.  Note that this begins with one, so to get the first person, use i=1.
// PRE: a is not NULL, i >= 1
// POST: returns the ith person from a.  
//           if there are fewer than i people, returns NULL
// TIME: O(n), where n = a->max
struct person* get(const struct aop *a, int i);




// count(a) counts the number of people contained in a.
//   PRE: a is not NULL
//   POST: returns the number of person * contained in a
//   TIME: O(n), where n = a->max
int count(const struct aop *a);


// count_birthdays(a,m) counts the number of people contained in a whose birthday is in the month m
//   PRE: a is not NULL, 1 <= month <= 12
//   POST: returns the number of people contained in a who have a birthday in month 
//   TIME: O(n), where n = a->max
int count_birthdays(const struct aop *a, int month);


// birthdays(a,m) returns a new aop containing all of the people from a whose birthday occurs in the month m
//        If there are no people with a birthday in this range, birthdays(a,m) instead returns NULL.
//        The capacity of the new aop should be exactly enough to hold all of the matching people.  
//        The people in the new aop should be sorted according to their birthday.  Ties should be broken according to the lexicographic order of their names.
//   PRE:  a is not NULL, 1 <= month <= 12
//   POST: returns a new aop containing all of the people from a whose birthday is in the range [start,end].
//         if there are no people with a birthday in this range, returns NULL 
//		   caller must eventually call destroy_aop() to free
//		   The values in the new aop should remain valid even is destroy_aop(a) is called (that is, they must be pointers to new person structures, existing pointers)
//  TIME: O(n log n + m), where n = count_birthdays(a,month), and m = a->max

struct aop *birthdays(const struct aop *a, int month);







