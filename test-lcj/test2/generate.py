N = 20


def fib(n):
    prev = 0
    curr = 1
    for i in range(0, n):
        (prev, curr) = (curr, prev + curr)

    return prev


for i in range(1, N + 1):
    with open(f"{i}.inp", "w") as inp:
        inp.write(f"{i}\n")

    with open(f"{i}.out", "w") as out:
        out.write(f"{fib(i)}\n")
