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

Following concepts were learned in week 6:
 * Importing python libraries
 * Python datatype abstractions
 * Pythonic way of programming
 * Loops, conditions, and commandline arguments
 * Reading and writing files

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

#### Writing into a CSV file can be done in two ways:

1. Opening a csv file into an object variable
```python
# open a file using open(file,a/r/w)
csv_file = open("phonebook.csv", "a")

# ask user for Name
name = get_string("Name: ")

# ask user for Number
num = get_string("Number: ")

# write the name and number to the newly opened csv file
writer = csv.writer(csv_file)
writer.writerow([name, num])

# close the file
csv_file.close()
```

2. Using the with open() as file:

```python
# ask user for Name
name = get_string("Name: ")

# ask user for Number
num = get_string("Number: ")

# open a file using open(file,a/r/w)
with open("phonebook.csv", "a") as csv_file:

    # write the name and number to the newly opened csv file
    writer = csv.writer(csv_file)
    writer.writerow([name, num])
```

#### Reading a CSV file can be done in two ways:

1. Using the **reader** in the csv library
```python
reader = csv.reader(file)
```

```python
from cs50 import get_string
import csv

snacks = {
    "Chips": 0,
    "Chocolate": 0,
    "Fruit": 0,
    "Others": 0
}

with open("snacks.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        person = row[0]     #row[0] is the Person
        snack = row[1]      #row[1] is the Snack
        try:
            snacks[snack] += 1
        except:
            snacks["Others"] += 1



for snack in snacks:
    print(f"{snack}:{snacks[snack]}")
```

2. Using the **DictReader** in the csv library:

```python
reader = csv.DictReader(file)
```

```python
from cs50 import get_string
import csv

snacks = {
    "Chips": 0,
    "Chocolate": 0,
    "Fruit": 0,
    "Others": 0
}

with open("snacks.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        snack = row["Snack"]
        try:
            snacks[snack] += 1
        except:
            snacks["Others"] += 1



for snack in snacks:
    print(f"{snack}:{snacks[snack]}")
```

## Key takeaway from week 6
* Python takes away memory management from the programmer
* There are no pointers to worry about it Python
* There are no do-while loops in Python

