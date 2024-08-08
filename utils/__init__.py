from random import sample

def input_number():
    while True:
        n = input('Entrez un nombre: ')
        try:
            return int(n)
        except ValueError:
            print('Ce n\'est pas un nombre')
        except:
            print('Une erreur est survenue')

def random_list(n: int) -> list:
    if n < 0:
        raise ValueError("n must be non-negative")
    return sample(range(n), n)

def display_list(L: list) -> None:
    if not isinstance(L, list):
        raise TypeError('List must be of type list')
    if not L:
        raise ValueError('List must not be empty')
    print(' '.join(str(x) for x in L))

def main() -> None:
    while True:
        try:
            n = input_number()
            break
        except ValueError:
            print("Invalid number")
    L = random_list(n)
    display_list(L)

if __name__ == "__main__":
    main()
# 18446744073700551616