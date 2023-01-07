def ler_pais(nome:str):
    import pandas as pd
    cols = ['Country, Other', 'Total Cases', 'Total Deaths', 'Total Recovered', 'Active Cases', 'Population']

    df = pd.read_csv('data/Covid_Live.csv')

    pais = df.loc[df['Country, Other'] == nome].copy()

    for col in cols[1:]:
        pais[col] = pais[col].str.replace(',', '').astype(float)   

    pais = pais[cols]

    try:
        return pais.values.tolist()[0]
    except IndexError:
        return [nome, 0, 0, 0, 0, 0]

if __name__ == '__main__':
    print(ler_pais('Brazil'))
    print(ler_pais('USA'))
