def main():
    szamok = []
    fbe = open('1_file.txt', 'r')
    for sor in fbe:
        sor = int(sor.strip())
        szamok.append(sor)
    fbe.close()
    print(min(szamok), max(szamok))
    print(sorted(szamok))
    
if __name__ == "__main__":
    main()
