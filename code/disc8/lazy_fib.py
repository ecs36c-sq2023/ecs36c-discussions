class Fibonacci:
    def __init__(self):
        self.cache = [0, 1]
        self.idx = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.idx < len(self.cache):
            res = self.cache[self.idx]
        else:
            res = self.cache[-1] + self.cache[-2]
            self.cache.append(res)
        self.idx += 1
        return res


fib = Fibonacci()
print(fib)
for i in range(10):
    print(next(fib))
