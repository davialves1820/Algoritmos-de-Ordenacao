# Algoritmos de Ordenação

## 📄 Descrição
Implementação de diversos algoritmos de ordenação em linguagem C:  
**Bubble Sort**, **Selection Sort**, **Insertion Sort**, **Quick Sort**, **Merge Sort** e **Heap Sort**.  

O programa compara o desempenho desses algoritmos medindo o tempo de execução e armazena os números ordenados em arquivos de saída.

Os números a serem ordenados são lidos de arquivos de entrada, e os resultados são salvos em arquivos de saída separados para cada algoritmo.

---

## 🗂️ Estrutura dos Arquivos

- **src**: Contém os arquivos de implementação;
- **include**: Contém os arquivos de cabeçalho;
- **instancias-num**: Contém os arquivos de entrada com os números a serem ordenados;
- **instancias_output**: Contém os arquivos de saida com os números já ordenados;
-  **Makefile:** Arquivo de configuração para a compilação.

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
O programa exibirá no terminal o tempo de execução de cada algoritmo em segundos. Esses valores variam, mas a média é por volta desse intervalo com o insertion sort sendo mais rápido.

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

