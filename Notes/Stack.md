---
created-date: 2024-02-21 15:50
---

## Introduction
> Stack is a data structure that uses LIFO or FILO principle.

### Rules
LIFO (Last In First Out) or FILO (First In Last Out) both means the same that is:
> "The element that came first will go at last or the element that came last will go first."

### Analogies
Clothes that were worn first will be removed last.
Clothes that were worn last will be removed first.
> Since the last layer is the top layer, Stack also have a top which points to the top element or the outermost element

## Implementation
There are mainly two ways in which we can implement Stack. Those are:
1. [[#Stack using Array|Array]]
2. [[#Linked List way]]

### Stack using Array
#### Algorithms
1. Creation
2. Insertion (PUSH)
3. Deletion (POP)
4. Traverse
5. Peak

##### Creation
```
1. Ask stack size from user
2. Create an array of that size
3. Ask if user wants to have 
```

##### Insertion
```
1. Check OVERFLOW
	1. If true, then return
	2. If false
		1. Increment TOP
		2. Assign VALUE to STACK[TOP]
```

##### Deletion
```
1. Check UNDERFLOW
	1. If true, then return
	2. If false
		1. Assign STACK[TOP] to VALUE
		2. Decrement TOP
		3. return VALUE
```


### Linked List way

#### Algorithm
```
1. Create newnode
2. set data in new node
3. if new node is empty
	1. stop
4. else if
	1. set newnode->next = top
	2. set top to newnode
5. 
```

POP
```
1. if top is empty
	1. underflow
2. else
	1. set tmp to top
	2. 
```



---

## Applications
### Parenthesis Checker
### Infix to Postfix Conversion

- Infix form
	- `a+b` here, `+` is the operator and `a` and `b` are the operands.
- Postfix form
	- `ab+` here, `+` is the operator and `a` and `b` are the operands.
- Prefix form
	- `+ab` here, `+` is the operator and `a` and `b` are the operands.

> [!abstract] Algorithm
> 1. Add `)` at the end of infix expression.
> 2. PUSH `(` onto the stack.
> 3. Repeat until each expression in the infix notation is scanned.
> 	1. If a `(` is encountered, PUSH it onto stack.
> 	2. If an operand is encountered, add it to the postfix expression
> 	3. If a `)` is encountered
> 		1. Repeatedly POP from the stack and add it to the postfix expression until a `(` is encountered.
> 		2. Discard the `(` and remove it from the stack and do not add to the postfix expression.
> 	4. If an operator is encountered, then
> 		1. Repeatedly POP from stack and add each operator which has the same or higher precedence than that of current scanned operator.
> 		2. PUSH the current operator onto the stack.
> 4. Repeatedly POP from the stack and add it to the postfix expression until the stack is empty.
> 5. Exit.


#### Example: `EXP = A-(B/C+(D%E*F)/G)*H`

New expression after adding a `)` to end of the infix expression `EXP = A-(B/C+(D%E*F)/G)*H)`

| Infix Expression | Stack     | Postfix Expression |
| ---------------- | --------- | ------------------ |
| A                | (         | A                  |
| -                | (-        | A                  |
| (                | (-(       | A                  |
| B                | (-(       | AB                 |
| /                | (-(/      | AB                 |
| C                | (-(/      | ABC                |
| +                | (-(+      | ABC/               |
| (                | (-(+(     | ABC/               |
| D                | (-(+(     | ABC/D               |
| %                | (-(+(%    | ABC/D               |
| E                | (-(+(%    | ABC/DE              |
| *                | (-(+(%*   | ABC/DE              |
| F                | (-(+(%*   | ABC/DEF             |
| )                | (-(+      | ABC/DEF*%           |
| /                | (-(+/     | ABC/DEF*%           |
| G                | (-(+/     | ABC/DEF*%G          |
| )                | (-        | ABC/DEF*%G/+        |
| *                | (-*       | ABC/DEF*%G/+        |
| H                | (-*       | ABC/DEF*%G/+H       |
| )                | UNDERFLOW | ABC/DEF\*%G/+H\*-     |

Postfix Expression: `ABCDEF*%G/+H*-`n

### Postfix Evaluation

> [!abstract] Algorithm
> 1. Add `)` at the end of the postfix expression.
> 2. Scan every character of the postfix expression and repeat step 3-5 until `)` is encountered.
> 3. If an operand is encountered push it onto stack.
> 4. If an operator is encountered then
> 	1. POP the top two elements of the stack in $A and $B.
> 	2. Evaluate $B operator $A where $A is the top most element and $B is next to it.
> 	3. Push the result of the evaluation onto the stack.
> 5. Set (result) = (topmost element of the stack).
> 6. Exit.


### Infix to Prefix Evaluation
> [!abstract] Algorithm 1
> 1. Reverse the infix string.
> 2. Obtain the postfix expression.
> 3. Reverse the postfix expression to get the prefix expression.
> 4. Exit.

#### Prefix Evaluation
> [!abstract] Algorithm
> 1. Accept 
> 2. Repeat until all the character of the prefix expression are scanned.
> 3. Scan the prefix expression from right, one character at a time.
> 4. If the scanned character is an operand than push it onto the stack.
> 5. If the scanned character is an operator than
> 	1. POP the top two elements of the stack in $A and $B.
> 	2. Evaluate $B operator $A where $A is the top most element and $B is next to it.
> 	3. Push the result of the evaluation onto the stack.