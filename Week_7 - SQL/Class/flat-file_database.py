
import csv

# Open CSV file - simple
with open("favorites.csv", "r") as file:

    # Create reader -> Create a variable that we can call in things in file.
    reader = csv.reader(file)

    # Skip the header row - the first one!
    next(reader)

    # Iterate over CSV file, printing each favorite
    # simples way
    
    for row in reader:
        # Aprender a fazer isso
        while 
            print(row[i], end=' | ')
        print(row[-1])

# Transformas csv num dicionário, mais interessante!

with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)
    # Como fica acumulado as rows?, me parece "Column name"[row]: , mas não sei se isso faz sentido

    # Iterate over CSV file, printing each favorite
    for row in reader:
        d_column = row["Column name"]
        print(d_column)


# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    scratch, c, python = 0, 0, 0

    # Iterate over CSV file, manipulate variables with data in csv
    for row in reader:
        favorite = row["language"]
        if favorite == "Scratch":
            scratch += 1
        elif favorite == "C":
            c += 1
        elif favorite == "Python":
            python += 1

# Quantifie n_types of data in a csv
# GENIAL, muito interessante 

with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts - Perceba que isso aqui é um dicionário
    counts = {}
    

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
            # Notice that the value in counts with the key favorite is incremented when it exists already. 
            # If it does not exist, we define counts[favorite] and set it to 1.
        else:
            counts[favorite] = 1

# MUITO INTERESSANTE!

# Print counts
for favorite in counts:
    print(f"{favorite}: {counts[favorite]}")

# Python também tem uma função para sort automático
# Sorted é super interessante estudar parametros no futuro
# key how are you going to sort the list, reverse= default => False, crescente
for favorite in sorted(counts, key=counts.get, reverse=True):
    print(f"{favorite}: {counts[favorite]}")


# Sorts favorites by value using .get
# Qual a vantagem dessa forma? Quais os outros comandos interessanter do Counter ou do collections?
from collections import Counter

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    counts = Counter() # Já atua criando o valor quando acha novo.

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["language"]
        counts[favorite] += 1

# Print counts
# count in counts ".most_common()" > Com maior número
for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")