---
created-date: 2024-02-20 22:14
---

## Selection Sort
- The algorithm for selection sort in pseudocode is:
    
    ```
    For i from 0 to n–1
        Find smallest number between numbers[i] and numbers[n-1]
        Swap smallest number with numbers[i]
    ```
    
- Summarizing those steps, the first time iterating through the list took `n - 1` steps. The second time, it took `n - 2` steps. Carrying this logic forward, the steps required could be represented as follows:
    
    ```
    (n - 1) + (n - 2) + (n - 3) + ... + 1
    ```
    
- This could be simplified to $\frac{n(n-1)}{2}$ or, more simply, O($n^2$) and also &Theta;($n^2$) because in any case it will run $n^2$ times.

## Bubble Sort

- _ Bubble sort_ is another sorting algorithm that works by repeatedly swapping elements to “bubble” larger elements to the end.
- The pseudocode for bubble sort is:
    
    ```
    Repeat n-1 times
        For i from 0 to n–2
            If numbers[i] and numbers[i+1] out of order
                Swap them
        If no swaps
            Quit
    ```
    
- As we further sort the array, we know more and more of it becomes sorted, so we only need to look at the pairs of numbers that haven’t been sorted yet.
- Analyzing selection sort, we made only seven comparisons. Representing this mathematically, where _n_ represents the number of cases, it could be said that selection sort can be analyzed as:
    
    ```
      (n - 1) + (n - 2) + (n - 3) + ... + 1
    ```
    
    or, more simply �2/2−�/2.
    
- Considering that mathematical analysis, n2 is really the most influential factor in determining the efficiency of this algorithm. Therefore, selection sort is considered to be of the order of �(�2) in the worst case where all values are unsorted. Even when all values are sorted, it will take the same number of steps. Therefore, the best case can be noted as Ω(�2). Since both the upper bound and lower bound cases are the same, the efficiency of this algorithm as a whole can be regarded as Θ(�2).
- Analyzing bubble sort, the worst case is �(�2). The best case is Ω(�).