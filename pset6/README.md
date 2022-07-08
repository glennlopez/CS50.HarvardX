<!--
https://www.makeareadme.com/
-->

# Week 6: Python

This week is  focused on learning a new programming language.

## Lab 6

[Write a program](https://cs50.harvard.edu/x/2022/labs/6/) to run simulations of the FIFA World Cup.

## PSET 6
Re-write all Pset 1-5 in python.
* Hello
* Mario
* Cash or Credit
* Readability
* DNA

## Key concepts learned in week 6

In week 6, we make use of the following imports.
The code behind getting inputs from the user is abstracted in cs50's library, eventually being removed as we get more familiar with Python

```python
from cs50 import get_float
from cs50 import get_int
from cs50 import get_string
```

For loops are written differently in Python when compared to C
```python
# For loop written in python
for i in range(3)
   print("Meow.")
```
```c
// For loop written in C
for (int i = 0; i < 3; i++)
{
   printf("Meow.")
}
```

There is no num++ concept in Python like in C
```c
// iteration in c
num = 10;
num++ // add 1 to num (num = 11)
```

In Python, we use num = num + 1 or num +=1
```python
#iteration in python
num = 10;
num += 1; # adds 1 to num (num = 11)
```

## Key takeaway from week 6
* Python takes away memory management from the programmer
* There are no pointers to worry about it Python
* There are no do-while loops in Python

