import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("resultados.csv")

# Converter para milissegundos
df["Selection"] = df["Selection"] * 1000
df["Insertion"] = df["Insertion"] * 1000
df["Quick"] = df["Quick"] * 1000
df["Merge"] = df["Merge"] * 1000

tipos = df["Tipo"].unique()

for tipo in tipos:
    dados = df[df["Tipo"] == tipo]

    plt.figure()
    plt.plot(dados["Tamanho"], dados["Selection"])
    plt.plot(dados["Tamanho"], dados["Insertion"])
    plt.plot(dados["Tamanho"], dados["Quick"])
    plt.plot(dados["Tamanho"], dados["Merge"])

    plt.yscale("log")

    plt.xlabel("Tamanho da Entrada")
    plt.ylabel("Tempo (ms)")
    plt.title(f"Comparação - {tipo}")
    plt.legend(["Selection", "Insertion", "Quick", "Merge"])
    plt.grid(True)

    plt.savefig(f"grafico_{tipo}.png")
    plt.close()

print("Graficos gerados com sucesso!")
