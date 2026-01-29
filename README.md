 ARBOL BINARIO DE BUSQUEDA CON RECORRIDOS CONCURRENTES (C)



Proyecto académico desarrollado en lenguaje C que implementa recorridos secuenciales y concurrentes (PreOrder, InOrder y PostOrder) sobre un árbol binario de búsqueda, utilizando la biblioteca pthread.h para la gestión de concurrencia.



El trabajo compara el comportamiento y rendimiento de ambas versiones, evaluando el uso de múltiples hilos de ejecución en función del tamaño del árbol y los núcleos disponibles del sistema.



Fue diseñado e implementado por el autor como parte del trabajo practico final de Programacion Concurrente.



--



 OBJETIVOS DEL PROYECTO



* Implementar un árbol binario de búsqueda con datos aleatorios únicos
* Desarrollar recorridos clásicos del árbol en versión secuencial
* Implementar recorridos concurrentes utilizando hilos (pthreads)
* Controlar dinámicamente la cantidad de hilos según los núcleos disponibles
* Comparar tiempos de ejecución entre enfoques secuenciales y concurrentes
* Analizar el impacto del paralelismo en árboles de distintos tamaños

--



 CONCEPTOS APLICADOS



* Programación en lenguaje C
* Programación Concurrente
* Uso de pthreads
* Creación y sincronización de hilos
* Estructuras de datos dinámicas
* Árbol binario de búsqueda
* Recorridos PreOrder, InOrder y PostOrder
* Medición de tiempos de ejecución (clock)
* Encapsulamiento mediante getters y setters
* Diseño modular del código
* Control adaptativo de concurrencia



--



 ESTRUCTURA DEL PROYECTO



src/



* arbol.c
* arbol.h
* main.c
* utils.c
* utils.h



docs/



* Informe\_Programacion\_Concurrente\_Arbol\_Binario.pdf



 src: contiene la implementación del árbol, los recorridos y la lógica concurrente



 docs: documentación técnica del trabajo práctico final



--



 EJECUCION



El proyecto puede ejecutarse directamente desde un entorno de desarrollo como Code::Blocks, importando el proyecto y compilándolo normalmente.



 DOCUMENTACION



El archivo PDF incluido en la carpeta docs contiene:



* Explicación detallada del problema
* Justificación del enfoque concurrente
* Descripción de la solución implementada
* Comparación entre recorridos secuenciales y concurrentes
* Análisis de resultados y conclusiones



--



 NOTAS



* Proyecto realizado como trabajo práctico final de la materia Programación Concurrente
* El algoritmo concurrente fue desarrollado íntegramente por el autor
* No se utilizan frameworks ni librerías externas fuera de pthread
* El enfoque concurrente permite reducir los tiempos de ejecución en árboles grandes, aprovechando el paralelismo disponible en sistemas multinúcleo
* La versión concurrente no replica la lógica secuencial, sino que introduce control explícito de creación y sincronización de hilos



--



 AUTOR



Leandro Vera

