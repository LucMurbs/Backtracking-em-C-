# Backtracking em C

Implementação clássica do algoritmo de Backtracking para resolução de labirintos, com visualização gráfica via terminal.

## Tech Stack & Conceitos

### Linguagem & Ferramentas
* **C**
* **Console I/O**: Renderização visual do labirinto diretamente no terminal utilizando caracteres Unicode/Emoji para representar paredes e caminhos.

### Algoritmos & Lógica
* **Backtracking (Recursão)**: Implementação de um algoritmo recursivo que explora caminhos possíveis e "volta atrás" (backtracks) quando encontra um beco sem saída.
* **Depth-First Search (DFS)**: A lógica de exploração segue o princípio de busca em profundidade para encontrar a saída (meta `2`).

### Estruturas de Dados
* **Matriz Bidimensional (2D Array)**: Utilização de vetores multidimensionais para a representação espacial do labirinto e controle de estados de visitação (células visitadas, paredes e caminho final).
