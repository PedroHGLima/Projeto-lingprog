def clean_df():
    df = pd.read_csv('Covid_Live.csv')
    df = df[['Country, Other', 'Total Cases', 'Total Deaths', 'Total Recovered', 'Active Cases', 'Population']]
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

def top_total(num):
    df = pd.read_csv('data/Covid_Live.csv')

    df['Total Cases'] = df['Total Cases'].str.replace(',', '').astype(float)
    return list(df.sort_values(by='Total Cases', ascending=False)['Country, Other'].iloc[:num])

def top_deaths(num):
    df = pd.read_csv('data/Covid_Live.csv')

    df['Total Deaths'] = df['Total Deaths'].str.replace(',', '').astype(float)
    return list(df.sort_values(by='Total Deaths', ascending=False)['Country, Other'].iloc[:num])

def top_recovered(num):
    df = pd.read_csv('data/Covid_Live.csv')

    df['Total Recovered'] = df['Total Recovered'].str.replace(',', '').astype(float)
    return list(df.sort_values(by='Total Recovered', ascending=False)['Country, Other'].iloc[:num])

def top_active(num):
    df = pd.read_csv('data/Covid_Live.csv')

    df['Active Cases'] = df['Active Cases'].str.replace(',', '').astype(float)
    return list(df.sort_values(by='Active Cases', ascending=False)['Country, Other'].iloc[:num])

def top_population(num):
    df = pd.read_csv('data/Covid_Live.csv')

    df['Population'] = df['Population'].str.replace(',', '').astype(float)
    return list(df.sort_values(by='Population', ascending=False)['Country, Other'].iloc[:num])

if __name__ == '__main__':
    import pandas as pd
    print(top_total(5))