


# Differences: 1° -> we use # and not //
# 2° -> There is no ; and {}
# 3° > Faster to code, but usually C is faster 

#*
#  int main(void){
#   printf("Hello World!\n")/
# }
# *#


print("Hello!") # the cursor also have a function arguments verifies in python

#def = way to create function:

words = set() # What is set()?



def check(word):
    """Return true if word is in dictionary else false"""
    return word.lower() in words # -> Made all in lower case
## Interessant: Markdwon """asdas""" used because we can always remember what the fuction do, by using help check(word) - The def you have create


def load(dictionary):
    """Load dictionary into memory, returning true if successful else false"""
    with open(dictionary) as file: 
        words.update(file.read().splitlines()) 
    return True


def size():
    """Returns number of words in dictionary if loaded else 0 if not yet loaded"""
    return len(words) # len => Important function to find length of a string


def unload():
    """Unloads dictionary from memory, returning true if successful else false"""
    return True

# Way to import function from a libraries!
from PIL import Image, ImageFilter

# Blur image
before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.BoxBlur(1)) # 1 => How much blured will be, to understand what is happen,
after.save("out.bmp")
# A lot easier than the one in C, but in C was more interessant and funny
# Edges image
before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("out.bmp") 

# A lot easier to understand what happened!

answer = input("What's your name")

print("hello, " + answer) # or without the + but with , but will have a sep as " ", you can change it using sep="Separator you desire"
print(f"hello, {answer}") # Most used nowadays way

# from cs50 import get_string
# why uses get_string from Cs50x and not input from python?

# We don't need to assign a data type

# positional parameter

# Python don't have x++ or y--

#  function in py to convert input in string as int
x = int(input("Text a number: "))
y = int(input("Text a number: "))

if x<y:
    print("x is less than y")
# we have else
# and elif => else if

s = str(input("Do you agree? "))

# we use or and not ||,  we use and.
# We don't have the compare string problem in python strcmp isn't more used. 
if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")

# a more fun and beutiful way to write it is:
# That's a list
if s in ['Y', "Yes"]: # AMAZING! 
    print("Agreed.")

# Have a way to upper chars of a word our got lower

s.lower()
s.upper()

# upper = void function

# you can insert this method even after other function!

s = input("sasd").lower()

# OBS! Notice that input is a function that returns a string as a object, while .lower() = a METHOD that opperetes the string!

# We can also copy a string a lot easier!
t = s 
# OBS.: It's possible to use .capitalize() xxxxx => Xxxx

i = 0
while i<3:
    print("meow")
    i += 1
# We don't have the other for(int i =0; i < x; i++)

for i in range(s):
    print(i)

    # OBS! Range is a way to create a list [0,1,2, ..., s], what is the same thing to while i<len(s)

for i in s:
    print("What you want:")
    # in this way 

# Improve by creating things as functions. That's really interessant way to work.

# we usually create all in main and other function and in the end we call main()

# Prompt user for an integer -> This is amazing!, but don't grow your try, try is for the minimun number of lines possible!
try:
    n = int(input("Input: "))
except ValueError:
    print("Not integer.")
else:
    print("Integer.")

# we can utilize * to multiply the print statemen
# sum a lists comes without the need of a for loop

scores = [1,2,3]
sum(scores)

listname = []

what_you_desire_to_add = "nothing"
# You can add something in a list by using

listname.append(what_you_desire_to_add)

#We can also search within a data structure.

# Implements linear search for names using loop

# A list of names
names = ["Yuliia", "David", "John"]

# Ask for name
name = input("Name: ")

# Search for name
for n in names:
    if name == n:
        print("Found")
        break
else:
    print("Not found")
# We don't need this for loop!
# Easier way to search in lists.
# Someone built this code in documentation.

if name in names:
    print("Found")
else:
    print("Not found")

people = {
    "Yuliia": "+1-617-495-1000",
    "David": "+1-617-495-1000",
    "John": "+1-949-468-2750",
}

# Search for name
name = input("Name: ")
if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")

# Prints a command-line argument
import sys # Really interessant, but I don't know how this will impact 

if len(sys.argv) == 2:
    print(f"hello, {sys.argv[1]}")
else:
    print("hello, world")


# Modificar documento!

# Exits with explicit value, importing sys

if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)

# Modifiying a document - AMAZING

import csv

name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv", "a") as file:

    writer = csv.writer(file)
    writer.writerow([name,number])

# We can use file.close() and file = open(...), but com oq ta acima já fecha automaticamente!
