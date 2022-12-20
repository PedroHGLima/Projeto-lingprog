def top_total(num):
    import pandas as pd    
    df = pd.read_csv('data/Covid Live.csv')

    df['Total Cases'] = df['Total Cases'].str.replace(',', '').astype(float)
    return list(df.sort_values(by='Total Cases', ascending=False)['Country, Other'].iloc[:num])

def top_deaths(num):
    import pandas as pd    
    df = pd.read_csv('data/Covid Live.csv')

    df['Total Deaths'] = df['Total Deaths'].str.replace(',', '').astype(float)
    return list(df.sort_values(by='Total Deaths', ascending=False)['Country, Other'].iloc[:num])

def top_recovered(num):
    import pandas as pd    
    df = pd.read_csv('data/Covid Live.csv')

    df['Total Recovered'] = df['Total Recovered'].str.replace(',', '').astype(float)
    return list(df.sort_values(by='Total Recovered', ascending=False)['Country, Other'].iloc[:num])

def top_active(num):
    import pandas as pd    
    df = pd.read_csv('data/Covid Live.csv')

    df['Active Cases'] = df['Active Cases'].str.replace(',', '').astype(float)
    return list(df.sort_values(by='Active Cases', ascending=False)['Country, Other'].iloc[:num])

def top_population(num):
    import pandas as pd    
    df = pd.read_csv('data/Covid Live.csv')

    df['Population'] = df['Population'].str.replace(',', '').astype(float)
    return list(df.sort_values(by='Population', ascending=False)['Country, Other'].iloc[:num])

if __name__ == '__main__':
    print(top_total(5))