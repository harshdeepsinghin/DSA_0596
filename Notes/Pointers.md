---
created-date: 2024-03-17 17:20
---

> [!abstract] What are pointers?
> Pointers are the variables that stores address of other variables.

```C
int *P;    // P is a variable pointer
int A = 5; // A is an integer variable that contains 5

P = &A;    // P contains the address of A

printf("%p", P);    // address of A
printf("%p", &P);   // address of P
printf("%d", *P);    // value of A
```

> `*P` is called dereferencing of the pointer P as it was referencing to A.