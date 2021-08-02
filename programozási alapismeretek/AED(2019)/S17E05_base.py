import random


def genera_vectores (n):
    vnum = n * [0]
    vcol = n * [0]
    ved = n * [0]
    vpref = n * [0]
    for i in range(n):
        vnum[i] = random.randint(25, 45)
        vcol[i] = random.choice((0, 1, 2))  # 0:blanco / 1:negro / 2:azul
        ved[i] = random.randint(10, 25)
        vpref[i] = random.choice((0, 1))  # 0:cuero / 1:tela
    return vnum, vcol, ved, vpref


def test():
    cantidad = 10
    vnum, vcol, ved, vpref = genera_vectores(cantidad)

    for i in range(cantidad):
        print(vnum[i], "\t", vcol[i], "\t", ved[i], "\t", vpref[i])
    print("")


test()