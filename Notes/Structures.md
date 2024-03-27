---
created-date: 2024-02-26 21:04
---

Structures are derived data types. They’re constructed using objects of other types. Consider the following structure definition:  
```C
struct card {  
	char *face;  
	char *suit;  
} aCard, deck[52], *cardPtr;
```

`aCard` is Variable, `deck[52]` is an Array and `*cardPtr` is a pointer of type struct card.

Members of the same structure type must have unique names, but two different structure types may contain members of the same name without conflict (we’ll soon see why). Each structure definition must end with a semicolon.

Common Programming Error 10.1Forgetting the semicolon that terminates a structure definition is a syntax error.

A structure containing a member that’s  
a pointer to the same structure type is referred to as a self-referential structure. Self-referential  
structures are used in Chapter 12, to build linked data structures.

A structure cannot contain an instance of itself.

Good Programming Practice 10.1 Always provide a structure tag name when creating a structure type. The structure tagname is required for declaring new variables of the structure type later in the program.

Structures may not be compared using operators == and !=, because structure members  
are not necessarily stored in consecutive bytes of memory. Sometimes there are “holes” in a  
structure, because computers may store specific data types only on certain memory bound-  
aries such as half-word, word or double-word boundaries. A word is a memory unit used to  
store data in a computer—usually 4 bytes or 8 bytes. Consider the following structure defi-  
nition, in which sample1 and sample2 of type struct example are declared:

```C
struct example
{
	char c;
	int i;
} sample1, sample2;
```

A computer with 4-byte words might require that each member of struct example be aligned on a word boundary, i.e., at the beginning of a word—this is machine dependent. Figure 10.1 shows a sample storage alignment for a variable of type struct example that has been assigned the character 'a' and the integer 97 (the bit representations of the values  
are shown). If the members are stored beginning at word boundaries, there’s a three-byte  
hole (bytes 1–3 in the figure) in the storage for variables of type struct example. The value  
in the three-byte hole is undefined. Even if the member values of sample1 and sample2 are  
in fact equal, the structures are not necessarily equal, because the undefined three-byte  
holes are not likely to contain identical values.

![[Attachments/Pasted image 20240226211526.png]]

### Initializing structures

```C
struct card aCard = { "Three", "Hearts" };
```

Since `aCard` contains two `char *` members which are `strings`, the above statements assigns `Three` to `face` and `Hearts` to `Suit`.

If there are fewer initializers in  
the list than members in the structure, the remaining members are automatically initial-  
ized to 0 (or NULL if the member is a pointer).

### Accessing Structure Members

#### (.) Structure Member Operator / Dot Operator

```C
printf("%s", aCard.suit);  // displays Hearts
```

#### (->) Structure Pointer Operator / Arrow Operator

```C
printf("%s", cardPtr->suit);  // displays Hearts
```

The expression `cardPtr->suit` is equivalent to `(*cardPtr).suit`, which dereferences the pointer and accesses the member suit using the structure member operator.

The parentheses are needed here because the structure member operator (.) has a higher precedence than the pointer dereferencing operator (\*).

> [!hint] Good Programming Practice 10.2
> Do not put spaces around the -> and . operators. Omitting spaces helps emphasize that the expressions the operators are contained in are essentially single variable names.

> [!hint] Good Programming Practice 10.2
> Do not put spaces around the -> and . operators. Omitting spaces helps emphasize that the expressions the operators are contained in are essentially single variable names.

> [!hint] Good Programming Practice 10.2
> Do not put spaces around the -> and . operators. Omitting spaces helps emphasize that the expressions the operators are contained in are essentially single variable names.


> [!hint] Common Programming Error 10.7  
> Assuming that structures, like arrays, are automatically passed by reference and trying to  
modify the caller’s structure values in the called function is a logic error.

Consider the following code snippet:

```c
#include <stdio.h>

struct Point {
    int x;
    int y;
};

void modifyPoint(struct Point p) {
    p.x = 10;
    p.y = 20;
}

int main() {
    struct Point point = {5, 5};
    
    printf("Before modification: x = %d, y = %d\n", point.x, point.y);
    
    modifyPoint(point);
    
    printf("After modification: x = %d, y = %d\n", point.x, point.y);
    
    return 0;
}
```

In this example, we have a `Point` structure and a function `modifyPoint` that takes a `Point` structure as an argument. Inside the function, we attempt to modify the values of `x` and `y`. However, when we run this code, we will see that the values of `x` and `y` remain unchanged in the `main` function after calling `modifyPoint`.

This behavior occurs because structures are passed by value in C. When `modifyPoint` is called, a copy of the `point` structure is created within the function scope. Any modifications made to this copy do not affect the original structure in the `main` function.

To actually modify the caller's structure within a function, you would need to pass a pointer to the structure as an argument. This way, you can directly access and modify the original structure's contents.

I hope this example clarifies how modifications to structures within functions do not affect the caller's structures when passed by value in C.

> [!hint] Performance Tip 10.1  
> Passing structures by reference is more efficient than passing structures by value (which re-  
quires the entire structure to be copied).

Passing structures by reference is more efficient than passing structures by value in C due to the overhead involved in copying the entire structure when passed by value. When a structure is passed by value, a complete copy of the structure is made and passed to the function, which can be inefficient for large structures or frequent function calls. On the other hand, passing structures by reference (using pointers) avoids this overhead by passing only the memory address of the structure.

Here's an explanation with an example:

Consider the following code snippet:

```c
#include <stdio.h>

struct Point {
    int x;
    int y;
};

void modifyPointByValue(struct Point p) {
    p.x = 10;
    p.y = 20;
}

void modifyPointByReference(struct Point *p) {
    p->x = 10;
    p->y = 20;
}

int main() {
    struct Point point = {5, 5};
    
    // Passing structure by value
    modifyPointByValue(point);
    
    printf("After modification by value: x = %d, y = %d\n", point.x, point.y);
    
    // Passing structure by reference
    modifyPointByReference(&point);
    
    printf("After modification by reference: x = %d, y = %d\n", point.x, point.y);
    
    return 0;
}
```

In this example, we have two functions `modifyPointByValue` and `modifyPointByReference` that attempt to modify a `Point` structure. When we pass the structure by value to `modifyPointByValue`, any modifications made inside the function do not affect the original structure in `main`. However, when we pass the structure by reference (using a pointer) to `modifyPointByReference`, the modifications directly affect the original structure.

Passing structures by reference (using pointers) is more efficient because it avoids making unnecessary copies of large structures, leading to better performance especially when dealing with complex data structures or frequent function calls.

The keyword typedef provides a mechanism for creating synonyms (or aliases) for previously defined data types. Names for structure types are often defined with typedef to create shorter type names. For example, the statement  
```C
typedef struct card Card;
```
defines the new type name Card as a synonym for type struct card. C programmers often use typedef to define a structure type, so a structure tag is not required. For example, the following definition  
```C
typedef struct
{
	char *face;
	char *suit;
} Card;
```
creates the structure type Card without the need for a separate typedef statement.

> [!hint] Good Programming Practice 10.3  
> Capitalize the first letter of typedef names to emphasize that they’re synonyms for other  
type names.

Card can now be used to declare variables of type struct card. The declaration  
```C
Card deck[52];
```
declares an array of 52 Card structures (i.e., variables of type struct card). Creating a new name with typedef does not create a new type; typedef simply creates a new type name, which may be used as an alias for an existing type name. A meaningful name helps make the program self-documenting. For example, when we read the previous declaration, we  
know "deck is an array of 52 Cards."
