
if __name__ == '__main__':
    import os
    from random import randint
    from random import shuffle
    print("---------------------")
    for i in range(1, 6):
        for j in range (1, 6):
            for k in range(1, 6):
                for l in range(1, 6):
                    for m in range(1, 6):
                        if i != j and i != k and i != l and i != m and j != k and j != l and j != m and k != l and k != m and l != m:
                            os.system(f'./push_swap {i} {j} {k} {l} {m} | ./checker_linux {i} {j} {k} {l} {m}')
                            os.system(f'./push_swap {i} {j} {k} {l} {m} | wc -l')
    print("---------------------")
    for i in range(1, 5):
        for j in range(1, 5):
            for k in range(1, 5):
                for l in range(1, 5):
                    if i != j and i != k and i != l and j != k and j != l and k != l:
                        os.system(f'./push_swap {i} {j} {k} {l} | ./checker_linux {i} {j} {k} {l}')
                        os.system(f'./push_swap {i} {j} {k} {l} | wc -l')
    print("---------------------")
    for i in range(1, 4):
        for j in range(1, 4):
            for k in range(1, 4):
                if i != j and i != k and j != k:
                    os.system(f'./push_swap {i} {j} {k} | ./checker_linux {i} {j} {k}')
                    os.system(f'./push_swap {i} {j} {k} | wc -l')
    print("---------------------")
    for i in range(1, 3):
        for j in range(1, 3):
            if i != j:
                os.system(f'./push_swap {i} {j} | ./checker_linux {i} {j}')
                os.system(f'./push_swap {i} {j} | wc -l')
    print("---------------------")
    sum = 0
    for i in range(100):
        numbers = [i for i in range(1, 101)]
        shuffle(numbers)
        numbers = ' '.join([str(i) for i in numbers])
        sum += int(os.popen(f'./push_swap {numbers} | wc -l').read())
        os.system(f'./push_swap {numbers} | ./checker_linux {numbers}')
    print(sum / 100)
    sum = 0
    print("---------------------")
    for i in range(100):
        numbers = [i for i in range(1, 501)]
        shuffle(numbers)
        numbers = ' '.join([str(i) for i in numbers])
        sum += int(os.popen(f'./push_swap {numbers} | wc -l').read())
        os.system(f'./push_swap {numbers} | ./checker_linux {numbers}')
    print(sum / 100)
    print("---------------------")
    exit(0)