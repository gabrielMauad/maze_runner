#include <stdio.h>
#include <stack>
#include <cstdlib>

// Matriz representnado o labirinto
char **maze;
// Numero de linhas e colunas do labirinto
int num_rows;
int num_cols;

// Posição a ser explorada
struct pos_t
{
	int i;
	int j;
};

// Estrutura de dados contendo as próximas
// posicões a serem exploradas no labirinto
std::stack<pos_t> valid_positions;

/* Inserir elemento:

	 pos_t pos;
	 pos.i = 1;
	 pos.j = 3;
	 valid_positions.push(pos)
 */
// Retornar o numero de elementos: valid_positions.size();
// Retornar o primeiro elemento fo vetor: valid_positions.pop();
// Remover o elemento no topo: valid_positions.front();


pos_t load_maze(const char* file_name)
{
	// Abre o arquivo para leitura (fopen)
	// Le o numero de linhas e colunas (fscanf)
	// e salva em num_rows e num_cols

	pos_t initial_pos;
	FILE *file_maze;
	file_maze = fopen(file_name, "r");
	fscanf(file_maze, "%d %d\n", &num_rows, &num_cols);
	char c;

	maze = (char **)malloc(num_rows * sizeof(char*));

	// Aloca a matriz maze (malloc)
	for (int i = 0; i < num_rows; i++)
	{
		// Aloca cada linha da matriz
		maze[i] = (char *)malloc(num_cols * sizeof(char*));
	}
  
	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_cols; j++)
		{
			// Le o valor da linha i+1,j do arquivo e salva na posição maze[i][j]
			// Se o valor for 'e' salvar o valor em initial_pos

			fscanf(file_maze, "%c", &maze[i][j]);
			if(maze[i][j] == 'e')
			{
				initial_pos.i = i;
				initial_pos.j = j;
			}
		}
		fscanf(file_maze, "%c", &c);
	}
	return initial_pos;
}

void print_maze()
{
	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_cols; j++)
		{
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}



void walk(pos_t pos)
{
	// Marcar a posição atual com o símbolo '.'

	/* Dado a posição atual, verifica quais sao as próximas posições válidas
		Checar se as posições abaixo são validas (i>0, i<num_rows, j>0, j <num_cols)
		 e se são posições ainda não visitadas (ou seja, caracter 'x') e inserir
		 cada uma delas no vetor valid_positions
		 - pos.i, pos.j+1
		 - pos.i, pos.j-1
		 - pos.i+1, pos.j
		 - pos.i-1, pos.j
		 Caso alguma das posiçÕes validas seja igual a 's', terminar o programa
	 */

	// Imprime o labirinto

	// Verifica se o vetor nao esta vazio.
	// Caso não esteja, pegar o primeiro valor de
	// valid_positions, remove-lo e chamar a funçao walk com esse valor
	pos_t next_position = valid_positions.top();
	valid_positions.pop();
}

int main(int argc, char* argv[])
{
	// carregar o labirinto com o nome do arquivo recebido como argumento (argv[])
	pos_t initial_pos = load_maze("/workspaces/maze_runner/data/maze.txt");
	// printf("%d", initial_pos.i);
	// printf("\n");
	// printf("%d", initial_pos.j);
	print_maze();
	// walk(initial_pos);
}