# Get_next_line

## UTILS
* char *ft_challoc(size_t count): Esta función asigna dinámicamente memoria para un arreglo de caracteres (char) y llena la memoria con caracteres nulos ('\0'). Devuelve un puntero al arreglo recién creado.

* bool ft_nlsrch(char *str): Esta función toma una cadena de caracteres como entrada y busca si coincide un carácter de nueva línea ('\n'). Si lo encuentra, devuelve 'true'; de lo contrario, devuelve 'false'.

* size_t ft_strlen(const char *s): Esta función calcula la longitud de una cadena de caracteres (cadena terminada en '\0') y devuelve el número de caracteres en la cadena.

* char *ft_strjoin(char *s1, char const *s2): Esta función toma dos cadena de caracteres como entrada, 's1' y 's2', y las concatena para crear una nueva cadena de caracteres. Asigna memoria dinámicamente para la nueva cadena y la llena con los caracteres de 's1' seguidos por los caracteres de 's2'. Luego, devuelve un puntero a la nueva cadena y libera la memoria asignada previamente para 's1'.

## GET_NEXT_LINE

Hay tres funciones estáticas (funciones definidas con 'static' que solo son visibles dentro de este archivo)

* static char *ft_read(int fd, char *leftstr): Esta función se encarga de leer el contenido del archivo identificado por el descriptor 'fd' y almacenar cualquier contenido no procesado en el puntero 'leftstr'. Utiliza un buffer llamado 'buffer' de tamaño 'BUFFER_SIZE + 1' (el 1 es para el retorno de linea) para leer datos del archivo y almacena en 'leftstr'. Continúa leyendo hasta encontrar una nueva línea ('\n') o llegar al final del archivo.

* static char *ft_line(char *leftstr): Esta función toma el contenido almacenado en 'leftstr' (que debería contener una línea completa o parte de ella) y extrae la primera línea de texto (hasta el primer '\n') y la devuelve como una cadena. También actualiza 'leftstr' para que contenga el contenido restante después de la primera línea.

* static char *ft_next(char *leftstr): Está función toma el contenido almacenado en 'leftstr' después de que se haya leído una línea (obtenido con 'ft_line') y devuelve el contenido restante, excluyendo la línea leída.

La función principal 'get_next_line(int fd)' es la función que debe llamarse para obtener la siguiente línea del archivo identificado por el descriptor 'fd'. Se utiliza un puntero estático 'leftstr' para almacenar cualquier contenido no procesado de lecturas anteriores. En cada llamada a 'get_next_line', primero llama a 'ft_read' para cargar más contenido en 'leftstr', luego llama a 'ft_line' para obtener la siguiente línea, y finalmente llama a 'ft_next' para actualizar 'leftstr' con el contenido restante.

### Explicación más detallada de las funciones estáticas anteriores
1. *static char* **ft_read(int fd, char* **leftstr)*
Esta función se utiliza para leer datos de un archivo identificado por el descriptor de archivo 'fd' y almacenarlos en el puntero 
2. 
