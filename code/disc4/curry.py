def foo(f):
    def identity(x):
        return x

    return identity


def boo(f, x):
    return x


print(foo(1)(2))
print(boo(1, 2))
