---
created-date: 2024-03-12 14:27
---

## Queue
Queue is a data structure that uses LIFO or FILO principle.
- It has two ends:
	1. Front - Deletion
	2. Rear - Insertion

Front is not a lower bound or a first index (it contains the address of first value).
Rear is like an upper bound (it contains the address of last filled element).
### LILO or FIFO
LILO (Last In Last Out) or FIFO (First In First Out) both means the same that is:
> "The element that came first will go first or the element that came last will go last."

### Analogies
- Car toll lines
- Public lines

### Operations in Queue
1. Creation
2. Insertion
3. Deletion
4. Traversing

### Types of Queue
1. Linear Queue
2. Circular Queue
3. Doubly Queue
4. Priority Queue

## Linear Queue
### Queue by Array

#### Underflow
```C
if (front < 0)
{
	return -1;
}
else if ()
```

#### Traversing

```C
tmp = Front;
while (tmp <= Rear)
{
printf("%d", Q[tmp]);
tmp++;
}
```

### Queue by Linked List
#### Insertion
```C
if (newnode == NULL)
{
	// Memory full
}
else
{
	newnode->data = element;
	newnode->next = NULL;
	if underflow()
	{
		Rear = Front = newnode;
	}
	else
	{
		Rear->next=newnode;
		Rear=newnode
	}
}
```

#### Deletion
```C
if underflow()
{
	// underflow
}
else if (Front == Rear)
{
	tmp = Front;
	
}
```

## Circular Queue

