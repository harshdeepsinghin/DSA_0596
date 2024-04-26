---
created-date: 2024-02-13 09:34
---

## Type of errors
1. Syntax
2. Semantic - When a code block is not logical.
3. Federal
4. Segmentation


## Observations

### 

### Is there any hybrid graph?

### What is Isolated vertex, Parallel edges and Isomorphic Graph?

### What is (Level, Height) of (Tree, Node). What is Depth of a tree

### Segmentation fault in fopen
> [!abstract]
> Happens when opening a file in wrong directory or path that does not exist. For example opening `hello.txt` as `FILE *fptr = fopen("data/hello.txt", "w");` will give the error whereas `FILE *fptr = fopen("hello.txt", "w");` will not give the error. It occurred because `data` directory does not exists and it cannot create directories. It can only create files.


### Incomplete format specifier

`scanf(" %", &var);`

> [!warning]
> incomplete format specifier [-Wformat]

> [!abstract] Conclusion
> It prints `0`
### Without ampersand it gives warning in scanning to pointers #pointers 

`scanf(" %d", newnode->data);` 

> [!warning]
> format specifies type `int *` but the argument has type `int` [-Wformat]



>[!success] Right way
> `scanf(" %d", &newnode->data)`

### Overflow even after dequeue #queue
Let's say, there's a queue of size 5 filled with 5 elements which means the Queue is full (OVERFLOW).
Now we dequeued the queue 4 times, which means now it's left with only one element at REAR. Which means `FRONT == REAR`. Now, if we try to enqueue, it will show OVERFLOW.

> [!abstract] Reason
> REAR is at (MAX/SIZE)-1 position which is the most rear position of the queue. Since, no more elements can be enqueued because REAR cannot increment further. Therefore, it shows OVERFLOW condition.

### Undefined or Uninitialised Pointer #pointer

> [!abstract]
> Pointer will contain an address of a garbage location.

### While passing Array in functions #array #functions

```C
function(ARRAY);
```

Above is right!



### & is not required while scanning strings



### Variable is a pointer by default

> [!abstract]
> A variable is a pointer by default, as it stores the value in frontend but in the memory it is only storing the address of it's value.


### Why it is better to store numbers as strings not integers when no calculations are going to be done?


### Memory

#### How memory actually works? #memory #pointers 

> Empty memory of 4 bytes looks like:

```
00000000 00000000 00000000 00000000
```

> Integer (255) memory of 4 bytes looks like:
```C
int A = 255;
```
```
00000000 00000000 00000000 11111111
```

> Integer (1050) memory of 4 bytes looks like:
```C
int A = 1050;
```
```
00000000 00000000 00000100 00011010
```

```C
char *K = (char *)B;    // char pointer K stores the type casted address of integer pointer B
printf("%d", *K);                  // 26
printf("%d", *(K+1));              // 4
```

> [!abstract] Why it's printing 26 and 4?
> - Since the char is of 1 byte memory, char pointer K is storing the first address of the elementary byte of the integer B. Therefore while printing the pointed value K gives `26` which is the decimal value of 1st byte of B that is `00011010` in binary.


### Declare Array inside any block scope

> [!error] Error
> error: cannot jump from switch statement to this case label
> note: jump bypasses initialization of variable length array

> [!info]
> In the above case, Array declaration was inside block scope of switch case

> [!hint] Solution
> Always declare the identifiers (Arrays, Variables etc.) in global scope, however define them wherever you want.

### Single Quotes v/s Double Quotes

- **Single Quotes (`'`):**
    - Used to represent a single character literal (ASCII value).
    - Encloses individual characters.
    - Typically used for assigning character values or representing character constants in switch-case statements.
- **Double Quotes (`"`) :**
    - Used to represent string literals, which are sequences of characters.
    - Encloses sequences of characters to form a string.
    - Used for initializing character arrays, specifying string literals in various contexts like printing or passing arguments to functions.

### No size to defined array

> [!check] No Errors

> [!abstract] Conclusion
> Automatically bounds the array size to the length of the elements defined.

### Referring to an element outside the array bounds/size

> [!check] No Errors

> [!abstract] Conclusion
> Prints garbage values

### Put semicolons at the end of preprocessor directives

> [!hint] Remember
> Preprocessor directives are not C statements.

> [!info] `#define SIZE 5;`
> If you terminate the `#define` preprocessor directive in with a semicolon, the  
preprocessor replaces all occurrences of the symbolic constant SIZE in the program with  
the text "5;". This may lead to syntax errors at compile time, or logic errors at execution  
time.

> [!hint] Remember
> The preprocessor is not the C compiler.

> [!warning]
> extra tokens at end of `#include` directive [-Wextra-tokens]

### Why The address of a variable keeps changing?

> [!abstract] Answer
> The address of a variable in C keeps changing because of a security feature called Address Space Layout Randomization (ASLR). ASLR is a security technique that randomizes the position of key data areas in memory, such as the stack, heap, and executable code. This makes it more difficult for attackers to exploit security vulnerabilities, such as buffer overflows and code injection attacks.


### Nested printf() statement

```C
printf("%d",printf("hello\n"));
```

Output:
```
hello
6⏎        
```

It will print the most inner printf() first then moves outwards.

### Declare an array then intialize it

```C
int size;
size = 5;
int A[size];
A[size] = {5,8,1,39}; //error
return 0;
```

> [!error] Error
> expected expression

```
cc     play.c   -o play
play.c:8:15: error: expected expression
    A[size] = {5,8,1,39}; //error
              ^
1 error generated.
make: *** [play] Error 1
```


In C, you can't assign values to an array using the syntax `A[size] = {1,2,3,4,5};` outside of the declaration. This syntax is only allowed at the time of declaration. 

If you want to initialize an array after declaration, you can assign values to individual elements using a loop or by direct assignment, as shown in the previous examples. 

Here's an example of how you can initialize an array after declaration:

```c
#include <stdio.h>

int main() {
    int size = 5;
    int A[size]; // Declaration

    // Initialization after declaration
    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 4;
    A[4] = 5;

    return 0;
}
```

Alternatively, if you want to initialize the array at the time of declaration, you can do it like this:

```c
#include <stdio.h>

int main() {
    int size = 5;
    int A[size] = {1, 2, 3, 4, 5}; // Declaration and initialization

    return 0;
}
```

But you cannot combine declaration and initialization after declaration with the syntax `A[size] = {1,2,3,4,5};`.

### C file with just a library header file

> [!error] Error
> linker command failed with exit code 1

[[#C file with just a library header file|reference]]
### Using printf without including library header file

> [!error] Error
> call to undeclared library function 'printf' with type 'int (const char *, ...)'; ISO C99 and later do not support implicit function declarations

### Remove # from header file include

> [!error] 
> unknown type name 'include'

> Compiler took include as a data type.

>[!error]
> expected identifier or '('

> Compiler took header file name as an identifier

### Remove data type of main ()

> [!warning] Warning
>  type specifier missing, defaults to 'int'; ISO C99 and later do not support implicit int.

> [!success] But it still runs.

### Empty main body
> [!check] No errors, it does not print anything.


### Remove semicolons
> [!error] Error
> expected ';' after expression

[[#expected ';' after expression | Solution]]

### Remove curl braces

## Errors

- [[#expected ';' after expression]]
- Too many initializers
- Pointer to integer conversion error
- Incompatible integer to pointer conversion
- fish: Job 1, './play' terminated by signal SIGSEGV (Address boundary error)
- 

## Warnings
- [[#format specifies type void * but the argument has type int]]

#### expected ';' after expression
```
play.c:11:28: error: expected ';' after expression
    printf("Hello World\n")
                           ^
                           ;
1 error generated.
```
> [!hint] Solution
> Put a semicolon (statement terminater) after every statement.

##### Occurs when
- [[#Remove semicolons]]

#### format specifies type void * but the argument has type int
```
array.c:18:65: warning: format specifies type void * but the argument has type 'int' [-Wformat]
        printf("%dst element: %d at address: %p\n",i+1,ARRAY[i],ARRAY[i]);
                                             ~~                 ^~~~~~~~
                                             %d
```

> [!hint] Solution
> This error occurs when we try to print hexadecimal addresses by passing integers in format specifier.
use ampersand (&) as a prefix to point addresses


#### C file with just a library header file
```
ld: Undefined symbols:
  _main, referenced from:
      <initial-undefines>
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make: *** [play] Error 1
```


---

```C
  
  

/*

  

---

  

// This will print the values till the values defined rest will be garbage values. Also here the size of array become 7.

  

CODE:

  

int A[] = {3,4,0,4,5,8,9};

for (int i=0;i<10;i++)

{

printf("element %d: %d\n", i, A[i]);

}

return 0;

  

---

  

// This will print the values till 5th index from the defined list, rest will be discarded hence garbage values will be displayed.

  

CODE:

  

int A[5] = {3,4,0,4,5,8,9};

for (int i=0;i<10;i++)

{

printf("element %d: %d\n", i, A[i]);

}

return 0;

  

WARNING:

  

play.c:5:27: warning: excess elements in array initializer [-Wexcess-initializers]

int A[5] = {3,4,0,4,5,8,9};

  

---

  

// int is of 4 bytes

  

int A[100];

printf("%d", sizeof(A)); // 400

  

---

  

// This will print 10 values where the first 5 values are 0 and the rest 5 are garbage values

  

int A[5] = {};

for (int i=0;i<10;i++)

{

printf("element %d: %d\n", i, A[i]);

}

return 0;

  

---

  

// This will print 10 values where first 2 are the defined values, other 3 values are 0 and the rest 5 are garbage values

  

int A[5] = {2,3};

for (int i=0;i<10;i++)

{

printf("element %d: %d\n", i, A[i]);

}

return 0;

  

---

  

// This prints 10 garbage values however the array size is 5

  

int A[5];

for (int i=0;i<10;i++)

{

printf("element %d: %d\n", i, A[i]);

}

return 0;

  

---

// This gives error of intialization and declaration

  

int size;

size = 5;

int A[size];

A[size] = {5,8,1,39};

return 0;

  

---

  

// To print the size of array using sizeof()

  

int A[5] = {1,2,3};

int size = sizeof(A)/sizeof(int);

printf("%d",size);

---

  

printf("Hello World\n");

return 0;

  

---

  

int main (void)

{

int *p;

printf("%p address have %d decimal value.", p,*p);

return 0;

}

  
  

*/
```


### What is size_t?

> [!abstract]
> `size_t` is a data type in C and C++ that is used to represent sizes of objects. It is an unsigned integer type and its size varies depending on the platform, typically being the same size as the machine's native word size. It is commonly used for array indexing and loop counting.

### Shifting from 2-byte to 4-byte size for int

> [!abstract]
> The shift from a 2-byte size to a 4-byte size for the `int` data type typically occurs due to architectural changes in computer systems. As technology advances, newer processors and architectures are designed to handle larger data sizes more efficiently. Therefore, transitioning from 2-byte to 4-byte `int`s allows for better performance and compatibility with modern systems.

### What is (`->`) called?

> [!abstract]
> `->` is called the dereferencing operator in C and C++. It is used to access members of a structure or a union through a pointer to that structure or union. It combines pointer dereferencing (`*`) with member access (`.`), making it convenient for accessing members of a structure or union using a pointer to it.

### Removal of Small Elements from Code

> [!error] Error
> Error occurs: cannot jump from switch statement to this case label. Note: jump bypasses initialization of variable length array.

> [!info]
> In the given scenario, the error occurs because array declaration was inside the block scope of a switch case. Jumping from a switch statement to this case label bypasses initialization of the variable length array.

> [!hint] Solution
> Always declare identifiers (arrays, variables, etc.) in the global scope and define them wherever needed to avoid such errors.

### 5. Error in `while (choice == "Y" || choice == 'Y')`

> [!error] Error
> The expression `while (choice == "Y" || choice == 'Y')` gives error due to a mismatch in data types. Comparing a string literal `"Y"` with a character literal `'Y'` is not valid. To fix this, use either double quotes for both string literals or single quotes for both character literals.

### 6. Difference in Size between Char and Integer

> [!abstract]
> Although both `char` and `int` represent numeric values, they have different memory sizes. In most systems, a `char` typically occupies 1 byte of memory, while an `int` occupies 4 bytes. This is because the size of a data type is determined by the compiler and the architecture of the system. Even though both `char` and `int` can represent integer values, they have different memory footprints due to their different data types and requirements.

### 7. Declaration of Functions above `main()`

> [!abstract]
> It is necessary to declare functions above `main()` in C and C++ if those functions are defined below `main()` but used before their definitions. This is because C and C++ follow a top-down execution flow. The compiler reads code sequentially from top to bottom. If a function is used before its definition, the compiler needs to know its signature (return type and parameters) beforehand. By declaring the function above `main()`, its signature becomes visible to the compiler, allowing it to resolve function calls correctly.