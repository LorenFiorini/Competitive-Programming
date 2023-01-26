
def solve(n, a, b):
    a_list = list(map(int, str(a)))
    b_list = list(map(int, str(b)))
    a_list.sort()
    b_list.sort()
    a_list.reverse()
    b_list.reverse()
    a_list = list(map(str, a_list))
    b_list = list(map(str, b_list))
    a_str = ''.join(a_list)
    b_str = ''.join(b_list)
    a_int = int(a_str)
    b_int = int(b_str)
    return a_int * b_int % 998244353


if __name__ == '__main__':
    n = int(input())
    a = int(input())
    b = int(input())
    print(solve(n, a, b))
