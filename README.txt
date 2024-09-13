-)Para correr el programa, utlilizar "./tarea1" en consola en el directorio 
  corresponidente

-)Las llaves de los argumentos son los siguientes:
	*"-u" Ingresar el usuario 
	*"-p" Ingresa la contraseña
	*"-t" Ingresa una frase de cualquier caractér
	*"-v" Ingresa un vector, donde se deben ingresar digitos enteros, y 
	      después un símbolo no-numérico (ej: '1;3;72;')
	*"-n" Ingresa un número entero cualquiera

-)Para ingresar los argumentos, se ingresa la llave seguida de un espacio, y el 
  argumento entre comillas singulares.
  (ej: ./main -u 'juan' -p 'panguipulli1918' -t 'racecar car' -v '1;3;72;' -n '14')

-)Los usuarios registrados son:
	*usuario=Juan  contraseña=Panguipulli1918
	*usuario=Carla  contraseña=500!Cigarros
	*usuario=Hector  contraseña=S&N94
	*usuario=Johanna  contraseña=jLooP41_T
    
    agregar variable de entorno antes de ejecutar:
    
    export USUARIOS_PATH="/ruta/al/archivo/BD.txt"



-)Si es que se actualiza el código, borrar archivo genérico "tarea1" y "tarea1.o",
  después escribir "make" en la consola