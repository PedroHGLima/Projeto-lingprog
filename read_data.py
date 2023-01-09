import pandas as pd
def clean_df():
    df = pd.read_csv('data/Covid_Live.csv')
    df = df.drop(['New Deaths', 'Serious, Critical', 'Tot Cases/1M pop', 'Deaths/1M pop', 'Total Tests', 'Tests/1M pop'], axis=1)
    df = df.drop(df.columns[0],axis=1)
    df.columns = ['Paises', 'Total de Casos', 'Total de Obitos', 'Total de Recuperados','Casos Ativos', 'Populacao']
    return df

def ler_paises(qtd:int):
    qtd = int(qtd)
    df = clean_df()
    cols = df.columns

    for col in cols[1:]:
        df[col] = df[col].str.replace(',', '').astype(float)   

    if qtd > len(df):
        qtd = len(df)
    if qtd < 0:
        return []
    if qtd == 0:
        qtd = len(df)
    
    df = df[cols][:qtd]
    return df.values.tolist(), df.columns.tolist()

if __name__ == '__main__':
    print(ler_paises(5))
