def main():
    with open('Covid Live.csv', 'r') as arquivo:
        titulos = arquivo.readline().strip().split(',')
        print(titulos)

if __name__ == '__main__':
    main()
