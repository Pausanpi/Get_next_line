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
### 1) static char *ft_read(int fd, char *leftstr)
* Comprueba si 'leftstr' es nulo y, en ese caso, asigna memoria para un carácter nulo (se inicializa como una cadena vacía)
* Asigna memoria para un búfer temporal llamado 'buffer' con un tamaño de 'BUFFER_SIZE + 1'. 'BUFFER_SIZE' es una constante que define el tamaño del búfer para la lectura de datos desde el archivo.
* Inicializa 'bytes' en 1 para entrar en el bucle y comienza a leer desde el archivo a 'buffer'.
* Entra en un bucle mientras no encuentra un carácter de nueva línea ('\n') en 'buffer' y mientras 'bytes' es mayor que 0 (indicando que todavía hay datos por leer en el archivo).
* Si la lectura desde el archivo falla (bytes < 0), libera la memoria asignada para 'buffer' y 'leftstr' y devuelve un puntero nulo.
* Si la lectura tiene éxito, agrega un carácter nulo al final de 'buffer' para asegurarse de que sea una cadena de caracteres válida.
* Llama a 'ft_strjoin' para unir el contenido de 'leftstr' y 'buffer', almacenando el resultado en 'leftstr'.
* Si la unión de cadenas falla (es decir, 'ft_strjoin' devuelve nulo), libera la memoria asignada para 'buffer' y 'lefstr' y devuelve un puntero nulo.
* Continúa leyendo desde el archivo hasta encontrar una nueva línea o alcanzar el final del archivo.
* Finalmente, libera la memoria asignada para 'buffer' y devuelve 'leftstr', que ahora contiene datos acumulados del archivo.

### 2) static char *ft_line(char *leftstr)
* Verifica si 'leftstr' está vacío (es decir, 'leftstr[0]' es nulo). Si es así, devuelve un puntero nulo, lo que significa que no hay más líneas para leer.
* Entra en un bucle mientras 'leftstr[i]' no es nulo y 'leftstr[i]' no es carácter de nueva línea ('\n').
* Dentro del bucle, copia los caracteres de 'leftstr' en una nueva cadena llamada 'line' hasta que encuentre un carácter de nueva línea o llegue al final de 'leftstr'.
* Si encuentra un carácter de nueva línea, lo incluye en 'line'.
* Después de copiar la línea, agrega un carácter nulo al final de 'line' para que sea una cadena de caracteres válida.
* Devuelve 'line', que contiene la primera línea de 'leftstr'.
* Actualiza 'leftstr' para que apunte al contenido restante después de la línea leída.

### 3) static char *ft_next(char *leftstr)
* Busca la posición del primer carácter de nueva línea ('\n') en 'leftstr'.
* Si no encuentra un carácter de nueva línea (es decir, 'leftstr[i]' es nulo), libera la memoria asignada para 'leftstr' y devuelve un puntero nulo, lo que significa que no hay más para leer.
* Si encuentra un carácter de nueva línea, crea una cadena llamada 'tmp' y copia el contenida de 'leftstr' a partir de la posición después de la línea leída.
* Libera la memoria asignadad para el antiguo 'leftstr'.

### Por si todavía no entendió

Imagina que tienes un libro muy grande, pero solo puedes leer una línea a la vez. El libro es tan grande que no lo puedes sostener todo al mismo tiempo, así que usas un trozo de papel para recordar dónde te quedaste. Llamaremos a ese trozo de papel "leftstr".

1. _Función "ft_read"_: Esta función es como alguien que toma el libro y empieza a leerlo. Pero como solo puede leer una línea a la vez, cada vez que termina de leer una línea, la escribe en el trozo de papel "leftstr". Si el trozo de papel está en blanco, es decir, no había nada escrito en él antes, primero lo prepara. Luego, continúa leyendo el libro línea por línea y escribiéndolas en el trozo de papel "leftstr". Esto se repite hasta que encuentra una línea en blanco en el libro o llega al final del libro.
2. _Función "ft_line"_: Imagina que después de usar la función "ft_read", tienes una página del libro escrita en el trozo de papel "leftstr". Ahora, esta función es como alguien que toma el trozo de papel "leftstr" y copia la primera línea en otro papel llamado "line". Entonces, "line" tiene la primera línea del libro. Luego, la función actualiza el trozo de papel "leftstr" para que ahora solo tenga lo que queda del libro después de la primera línea.
3. _Función "ft_next"_:Después de usar "ft_line", el trozo de papel "leftstr" todavía tiene el resto del libro que no has leído. La función "ft_next" es como alguien que corta el trozo de papel "leftstr" justo después de la primera línea y te da el papel que contiene el resto del libro, sin la primera línea.

Entonces, cuando llamas a "get_next_line", estas funciones trabajan juntas para leer una línea completa del libro cada vez que las llamas. Y el trozo de papel "leftstr" se actualiza para que recuerdes dónde te quedaste en el libro para la próxima vez que llames a la función. Es como leer un libro grande página por página y no perderte ninguna parte del libro.
