# Algoritmos de Ordenação

## 📄 Descrição
Implementação de diversos algoritmos de ordenação em linguagem C:  
**Bubble Sort**, **Selection Sort**, **Insertion Sort**, **Quick Sort**, **Merge Sort**, **Heap Sort**,**Counting Sort**, **Bucket Sort** e **Radix Sort**.  

O programa compara o desempenho desses algoritmos medindo o tempo de execução e armazena os números ordenados em arquivos de saída.

Os números a serem ordenados são lidos de arquivos de entrada, e os resultados são salvos em arquivos de saída separados para cada algoritmo.

---

## 🗂️ Estrutura dos Arquivos

- **src**: Contém os arquivos de implementação;
- **include**: Contém os arquivos de cabeçalho;
- **instancias**: Contém os arquivos de entrada com os números a serem ordenados;
- **resultados.csv**: Contém o arquivo com os resultados de análise de cada algoritmo;
- **grafico_TIPODOVETOR**: Contém o gráfico comparando os algoritmos para cada tipo de entrada;
- **gerar_grafico.py**: Arquivo que gera os gráficos a partir do arquivo csv;
- **Makefile:** Arquivo de configuração para a compilação.

---

## ⚙️ Como Compilar e Executar

### Compilando o Código

```bash
make
```

### Executando o Programa

```bash
./bin/programa
```

O programa irá:
- Ler os números do arquivo de entrada;
- Ordenar os números usando os algoritmos;
- Medir o tempo de execução de cada algoritmo;
- Salvar os resultados em arquivos de saída.

---

## 🖥️ Saída do Programa
Os resultados estarão no arquivo csv.

### Gerar os gráficos de comparação dos algoritmos

```bash
python gerar_grafico.py
```

---

## 📚 Detalhes dos Algoritmos

### Bubble Sort
- **Descrição:** Compara pares de elementos adjacentes e troca-os se estiverem na ordem errada. Repete o processo até que o vetor esteja ordenado.
- **Complexidade de tempo:** O(n²) no pior caso.
- **Vantagens:** Simples de implementar.
- **Desvantagens:** Muito lento para vetores grandes.

---

### Selection Sort
- **Descrição:** Procura o menor elemento do vetor e troca de posição com o elemento da posição atual. Repete até o vetor estar ordenado.
- **Complexidade de tempo:** O(n²) no pior caso.
- **Vantagens:** Simples e com número mínimo de trocas.
- **Desvantagens:** Ineficiente para grandes volumes de dados.

---

### Insertion Sort
- **Descrição:** Insere cada elemento na posição correta, considerando as partes já ordenadas do vetor.
- **Complexidade de tempo:** O(n²) no pior caso, mas O(n) no melhor caso (vetor já ordenado).
- **Vantagens:** Bom para vetores pequenos ou quase ordenados.
- **Desvantagens:** Ineficiente para vetores grandes.

---

### Quick Sort
- **Descrição:** Algoritmo de divisão e conquista. Escolhe um pivô e particiona o vetor em sub-vetores menores, ordenando-os recursivamente.
- **Complexidade de tempo:** O(n log n) no caso médio, O(n²) no pior caso.
- **Vantagens:** Geralmente rápido, com bom desempenho prático.
- **Desvantagens:** Pior caso pode ser ruim sem escolha adequada do pivô.

---

### Merge Sort
- **Descrição:** Divide o vetor em sub-vetores menores, ordena cada um e faz a fusão ordenada.
- **Complexidade de tempo:** O(n log n) no pior caso.
- **Vantagens:** Estável (mantém ordem relativa) e previsível.
- **Desvantagens:** Usa memória extra proporcional ao tamanho do vetor.

---

### Heap Sort
- **Descrição:** Constrói uma heap a partir do vetor e extrai o maior elemento sucessivamente, reconstruindo a heap.
- **Complexidade de tempo:** O(n log n) no pior caso.
- **Vantagens:** Desempenho consistente, sem pior caso degenerado.
- **Desvantagens:** Mais lento que Quick Sort na prática para muitos casos.

---

### Counting Sort

- **Descrição:** Conta a frequência de cada valor e usa essa contagem para reconstruir o vetor em ordem.

- **Complexidade de tempo:** O(n + k), onde k é o valor máximo no vetor.

- **Vantagens:** Extremamente eficiente para intervalos pequenos de valores inteiros.

- **Desvantagens:** Requer memória proporcional ao valor máximo, não é comparativo.

---

### Bucket Sort

- **Descrição:** Distribui os elementos em "baldes" (intervalos), ordena individualmente cada balde (geralmente com Insertion Sort) e os combina.

- **Complexidade de tempo:** O(n + k), no caso médio, dependendo da distribuição dos dados.

- **Vantagens:** Muito eficiente para dados uniformemente distribuídos.

- **Desvantagens:** Desempenho pode degradar se os dados não forem bem distribuídos.

---

### Radix Sort

- **Descrição:** Ordena números processando dígito por dígito, geralmente da menor posição para a maior, utilizando Counting Sort como sub-rotina estável.

- **Complexidade de tempo:** O(d × (n + k)), onde d é o número de dígitos.

- **Vantagens:** Muito eficiente para números inteiros de tamanho fixo.

- **Desvantagens:** Requer que o algoritmo auxiliar (como Counting Sort) seja estável.
