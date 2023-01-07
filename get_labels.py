import pandas as pd

def clean_df():
    df = pd.read_csv('Covid_Live.csv')
    df = df[['Country,\nOther', 'Total\nCases', 'Total\nDeaths', 'Total\nRecovered', 'Active\nCases', 'Population']]
    novas_colunas = ['Paises', 'Total de Casos', 'Total de Mortes', 'Total de Recuperados', 'Casos Ativos', 'Populacao']
    df.columns = novas_colunas
    
    return df

def get_labels(num):
    df = clean_df()

    if num == 1:
        label = str.replace(df.columns[0], '\n', ' ')
        return label
    elif num == 2:
        label = str.replace(df.columns[1], '\n', ' ')
        return label
    elif num == 3:
        label = str.replace(df.columns[2], '\n', ' ')
        return label
    elif num == 4:
        label = str.replace(df.columns[3], '\n', ' ')
        return label
    elif num == 5:
        label = str.replace(df.columns[4], '\n', ' ')
        return label
    else:
        print('Opcao invalida, tente novamente')