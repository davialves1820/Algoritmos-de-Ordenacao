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

## Algoritmos Avaliados

- Selection Sort
- Insertion Sort
- Quick Sort
- Merge Sort

---

# 🔵 1. Instâncias Aleatórias

## Comportamento Observado

- **Selection Sort:** Crescimento quadrático evidente.
- **Insertion Sort:** Também apresenta crescimento Θ(n²).
- **Quick Sort:** Crescimento aproximadamente Θ(n log n).
- **Merge Sort:** Crescimento estável Θ(n log n).

## Análise Teórica

| Algoritmo       | Melhor Caso | Caso Médio | Pior Caso |
|---------------|------------|------------|------------|
| Selection     | Θ(n²)     | Θ(n²)     | Θ(n²)     |
| Insertion     | Θ(n)      | Θ(n²)     | Θ(n²)     |
| Quick         | Θ(n log n)| Θ(n log n)| Θ(n²)     |
| Merge         | Θ(n log n)| Θ(n log n)| Θ(n log n)|

## Conclusão

Para dados aleatórios, algoritmos Θ(n log n) escalam muito melhor.  
A diferença entre crescimento quadrático e n log n torna-se extremamente significativa para grandes entradas.

---

# 🟢 2. Instâncias com Alta Repetição de Valores

## Comportamento Observado

- **Selection Sort:** Sem alterações significativas.
- **Insertion Sort:** Pequena melhora dependendo da organização.
- **Quick Sort:** Pode apresentar melhor balanceamento nas partições.
- **Merge Sort:** Mantém comportamento estável.

## Análise

A repetição de valores pode favorecer o Quick Sort, pois o particionamento tende a gerar divisões mais equilibradas.  
O Merge Sort permanece constante, pois sua complexidade não depende da distribuição dos dados.

## Conclusão

Algoritmos baseados em divisão e conquista mantêm estabilidade, enquanto algoritmos quadráticos continuam pouco escaláveis.

---

# 🟡 3. Instâncias Já Ordenadas

## Comportamento Observado

- **Selection Sort:** Continua Θ(n²).
- **Insertion Sort:** Aproxima-se de Θ(n) (melhor caso).
- **Quick Sort:** Pode piorar dependendo da escolha do pivô.
- **Merge Sort:** Mantém Θ(n log n).

## Análise

O Insertion Sort é altamente eficiente quando os dados já estão ordenados, pois realiza poucas trocas.  
O Selection Sort não se beneficia da ordenação prévia, pois sempre realiza o mesmo número de comparações.

## Conclusão

Para dados quase ordenados, Insertion Sort pode ser uma escolha eficiente.  
Merge Sort mantém desempenho previsível.

---

# 🔴 4. Instâncias Inversamente Ordenadas

## Comportamento Observado

- **Selection Sort:** Mantém Θ(n²).
- **Insertion Sort:** Apresenta pior caso Θ(n²).
- **Quick Sort:** Pode se aproximar de Θ(n²) se o pivô for mal escolhido.
- **Merge Sort:** Mantém Θ(n log n).

## Análise

O Insertion Sort sofre forte degradação neste cenário, pois cada elemento precisa ser deslocado diversas posições.  
Merge Sort mantém estabilidade, independentemente da ordem inicial.

## Conclusão

Algoritmos quadráticos são altamente sensíveis à organização inicial dos dados.  
Merge Sort demonstrou maior robustez geral.

---

# 🏁 Conclusão Geral

- Algoritmos Θ(n²) são adequados apenas para entradas pequenas.
- Algoritmos Θ(n log n) apresentam melhor escalabilidade.
- Merge Sort é o mais estável em todos os cenários.
- Quick Sort apresenta excelente desempenho médio, mas depende da escolha do pivô.
- A análise experimental confirmou a teoria da complexidade assintótica.

---

# 📌 Considerações Finais

Os experimentos demonstraram na prática o impacto da complexidade assintótica no desempenho real dos algoritmos.  
A escolha do algoritmo adequado deve considerar:

- Tamanho da entrada
- Distribuição dos dados
- Sensibilidade a pior caso
- Requisitos de estabilidade