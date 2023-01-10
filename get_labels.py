import pandas as pd

def clean_df():
    df = pd.read_csv('data/Covid_Live.csv')
    df = df.drop(['New Deaths', 'Serious, Critical', 'Tot Cases/1M pop', 'Deaths/1M pop', 'Total Tests', 'Tests/1M pop'], axis=1)
    df = df.drop(df.columns[0],axis=1)
    df.columns = ['Paises', 'Total de Casos', 'Total de Obitos', 'Total de Recuperados','Casos Ativos', 'Populacao']
    return df

def list_labels():
    df = clean_df()

    return list(df.columns)