def ler_paises(qtd:int):
    import pandas as pd
    qtd = int(qtd)
    cols = ['Country, Other', 'Total Cases', 'Total Deaths', 'Total Recovered', 'Active Cases', 'Population']
    df = pd.read_csv('data/Covid_Live.csv')

    for col in cols[1:]:
        df[col] = df[col].str.replace(',', '').astype(float)   

    if qtd > len(df):
        qtd = len(df)
    if qtd < 0:
        return []
    if qtd == 0:
        qtd = len(df)
    
    df = df[cols][:qtd]
    return df.values.tolist()

if __name__ == '__main__':
    print(ler_paises(5))