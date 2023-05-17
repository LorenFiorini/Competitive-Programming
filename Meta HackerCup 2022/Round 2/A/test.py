import random
import string

def main():
    f = open("input.txt", 'w')
    f.write("1\n")
    s = ''.join(random.choices(string.ascii_lowercase, k=4000000))
    f.write(s + "\n")

    q = 1000000
    f.write(str(q) + "\n")
    for i in range(q):
        a = random.randint(1, 4000000)
        b = random.randint(a+1, 4000000)
        f.write(str(a) + " " + str(b) + "\n")
    

main()
