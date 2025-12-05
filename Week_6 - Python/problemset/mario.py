
def create_row(n):
    for i in range(n):
        j = i + 1
        print(" " * (n-i), end="")
        print("#" * j, end="  ")
        print("#" * j)
    
    # using recursion
    pass
def create_row2(n, h):
    if n == h:
        return 0
    
    print(" " * (h-n), end="")
    print("#" * (n+1), end="  ")
    print("#" * (n+1))
    n += 1
    create_row2(n, h)
    pass

def get_size():
    h = int(input("How big will be the obstacle? "))

    # Used to decide the way to create_row
    # Opt = int(input("Would you desire to create the pyramid as recursive way (1) or for way(2)? (1/2)  "))

    # if opt == 2: create_row(h)
    # if opt == 1: create_row2(0,h)

    return h
    # Criar array se nn fosse aplicar o opt e enviar na array r[h, opt]!
    pass


def main():
    print("Bem vindo ao sistema de Mario-more")

    h = get_size()

    create_row(h)
    # ou mesmo create_row(get_size())


if __name__ == "__main__":
    main()