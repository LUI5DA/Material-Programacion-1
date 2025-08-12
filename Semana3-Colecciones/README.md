# README — Sistema de Biblioteca (tareas)

Este documento resume las tareas a realizar y cómo probarlas desde un `main`.

El objetivo es practicar \*\*punteros\*\*, \*\*memoria dinámica\*\* y \*\*colecciones\*\* con `Libro`, `Estudiante` y `Prestamo`.



---



## 1) Implementar \*\*tres contenedores\*\* de libros (ver `ContenedorLibros.h`)



Debes ofrecer \*\*tres variantes\*\* con la \*\*misma interfaz\*\* (`insert`, `search`, `getAt`, `deleteL`, `toString`, `size`, `capacity`). Supondremos clases: `ContenedorLibros1`, `ContenedorLibros2`, `ContenedorLibros3`.



### 1.1 `ContenedorLibros1` — Arreglo \*\*estático\*\* de objetos

- Interno: `Libro vec\[TAMANO]; int can;`

- \*\*No\*\* usa `new/delete` (no liberar en destructor).

- `insert` falla si está lleno.

- Útil para repasar aritmética de punteros en arreglos fijos.



### 1.2 `ContenedorLibros2` — Arreglo \*\*dinámico\*\* de objetos

- Interno: `Libro\* vec; int tam; int can;` con `new\[]`/`delete\[]`.

- \*\*Resize\*\* cuando `can == tam` (p. ej. duplicar `tam`).

- Implementar \*\*regla de tres\*\* (ctor copia, `operator=`, dtor).

- El contenedor posee el \*\*arreglo\*\*, los elementos son \*\*por valor\*\* (no punteros).



### 1.3 `ContenedorLibros3` — Arreglo \*\*dinámico de objetos dinámicos\*\*

- Interno: `Libro\*\* vec; int tam; int can;`.

- Cada `insert` hace `vec\[can++] = new Libro(l);`.

- El contenedor es \*\*dueño\*\* de los `Libro` (liberar en `deleteL` y en destructor).

- Implementar \*\*regla de tres\*\* (copia profunda de los `Libro`).

- Helpers recomendados (útiles para préstamos):

&nbsp; - `Libro\* getPtr(int i) const;`

&nbsp; - `Libro\* findPtr(int isbn) const;`



\*\*Sugerencia:\*\* impedir duplicados por `ISBN` en `insert` (retornar `false` si ya existe).



---



## 2) Implementar los \*\*métodos de `Biblioteca`\*\*



La clase orquesta todo usando:

- `ContenedorEstudiantesDyn` (dinámico de \*\*objetos dinámicos\*\* `Estudiante\*`).

- Uno de los tres contenedores de libros (recomendado: `ContenedorLibros3`).

- `ContenedorPrestamosDyn` (dinámico de \*\*objetos dinámicos\*\* `Prestamo\*`).



> Diseño: `Prestamo` \*\*no\*\* es dueño de `Estudiante\*` ni `Libro\*` (punteros no-propietarios).

> Los contenedores de estudiantes y libros \*\*sí\*\* son dueños de sus objetos.



### 2.1 Estudiantes

- `bool registrarEstudiante(const Estudiante\& e)` — Inserta si \*\*no\*\* existe cédula duplicada.

- `bool eliminarEstudiante(const string\& cedula)` — Solo si \*\*no\*\* tiene préstamos activos.

- `Estudiante\* buscarEstudiantePtr(const string\& cedula) const` — Puntero interno o `nullptr`.

- `string listarEstudiantes() const`.



### 2.2 Libros

- `bool agregarLibro(const Libro\& l)` — Inserta si \*\*no\*\* existe ISBN duplicado.

- `bool eliminarLibro(int isbn)` — Solo si \*\*no\*\* está prestado activamente.

- `Libro\* buscarLibroPtr(int isbn) const` — Puntero interno o `nullptr`.

- `string listarLibros() const`.



### 2.3 Préstamos

- `bool prestarLibro(const string\& cedula, int isbn)` — Estudiante y libro existen; libro \*\*no\*\* prestado.

- `bool devolverLibro(const string\& cedula, int isbn)` — Marca préstamo como devuelto/finalizado.

- `string listarPrestamos() const` y `string listarPrestamosActivos() const`.



---



## 3) `main` con menú para manejar la biblioteca



### 3.1 Opciones del menú

1\. Registrar estudiante  

2\. Agregar libro  

3\. Eliminar estudiante  

4\. Eliminar libro  

5\. Prestar libro  

6\. Devolver libro  

7\. Listar estudiantes  

8\. Listar libros  

9\. Listar préstamos (todos)  

10\. Listar préstamos activos  

11\. Buscar estudiante por cédula  

12\. Buscar libro por ISBN  

0\. Salir



### 3.2 Esqueleto sugerido (`main.cpp`)

```cpp

\#include <iostream>

\#include <limits>

\#include "Biblioteca.h"

using namespace std;



int menu() {

&nbsp;   cout << "\\n=== MENU BIBLIOTECA ===\\n"

&nbsp;        << "1) Registrar estudiante\\n"

&nbsp;        << "2) Agregar libro\\n"

&nbsp;        << "3) Eliminar estudiante\\n"

&nbsp;        << "4) Eliminar libro\\n"

&nbsp;        << "5) Prestar libro\\n"

&nbsp;        << "6) Devolver libro\\n"

&nbsp;        << "7) Listar estudiantes\\n"

&nbsp;        << "8) Listar libros\\n"

&nbsp;        << "9) Listar prestamos\\n"

&nbsp;        << "10) Listar prestamos activos\\n"

&nbsp;        << "11) Buscar estudiante por cedula\\n"

&nbsp;        << "12) Buscar libro por ISBN\\n"

&nbsp;        << "0) Salir\\n"

&nbsp;        << "Opcion: ";

&nbsp;   int op; cin >> op;

&nbsp;   if (cin.fail()) { cin.clear(); cin.ignore(numeric\_limits<streamsize>::max(), '\\n'); return -1; }

&nbsp;   return op;

}



int main() {

&nbsp;   ios::sync\_with\_stdio(false);

&nbsp;   cin.tie(nullptr);



&nbsp;   Biblioteca biblio;



&nbsp;   while (true) {

&nbsp;       int op = menu();

&nbsp;       if (op == 0) break;



&nbsp;       if (op == 1) {

&nbsp;           string ced, tel, mail, nom;

&nbsp;           cout << "Cedula: "; cin >> ced;

&nbsp;           cout << "Telefono: "; cin >> tel;

&nbsp;           cout << "Email: "; cin >> mail;

&nbsp;           cout << "Nombre: "; cin.ignore(); getline(cin, nom);

&nbsp;           Estudiante e(ced, tel, mail, nom);

&nbsp;           cout << (biblio.registrarEstudiante(e) ? "OK\\n" : "Error: ya existe\\n");

&nbsp;       }

&nbsp;       else if (op == 2) {

&nbsp;           int isbn; double precio; string nom, autor;

&nbsp;           cout << "ISBN: "; cin >> isbn;

&nbsp;           cout << "Precio: "; cin >> precio;

&nbsp;           cout << "Titulo: "; cin.ignore(); getline(cin, nom);

&nbsp;           cout << "Autor: "; getline(cin, autor);

&nbsp;           Libro l; l.setISBN(isbn); l.setPrecio(precio); l.setNombre(nom); l.setAutor(autor);

&nbsp;           cout << (biblio.agregarLibro(l) ? "OK\\n" : "Error: ISBN duplicado\\n");

&nbsp;       }

&nbsp;       else if (op == 3) {

&nbsp;           string ced; cout << "Cedula: "; cin >> ced;

&nbsp;           cout << (biblio.eliminarEstudiante(ced) ? "Eliminado\\n" : "No se puede eliminar (no existe o tiene prestamos activos)\\n");

&nbsp;       }

&nbsp;       else if (op == 4) {

&nbsp;           int isbn; cout << "ISBN: "; cin >> isbn;

&nbsp;           cout << (biblio.eliminarLibro(isbn) ? "Eliminado\\n" : "No se puede eliminar (no existe o esta prestado)\\n");

&nbsp;       }

&nbsp;       else if (op == 5) {

&nbsp;           string ced; int isbn;

&nbsp;           cout << "Cedula estudiante: "; cin >> ced;

&nbsp;           cout << "ISBN libro: "; cin >> isbn;

&nbsp;           cout << (biblio.prestarLibro(ced, isbn) ? "Prestamo registrado\\n" : "Error: datos invalidos o libro ya prestado\\n");

&nbsp;       }

&nbsp;       else if (op == 6) {

&nbsp;           string ced; int isbn;

&nbsp;           cout << "Cedula estudiante: "; cin >> ced;

&nbsp;           cout << "ISBN libro: "; cin >> isbn;

&nbsp;           cout << (biblio.devolverLibro(ced, isbn) ? "Devuelto\\n" : "Error: prestamo no encontrado o ya devuelto\\n");

&nbsp;       }

&nbsp;       else if (op == 7) {

&nbsp;           cout << biblio.listarEstudiantes();

&nbsp;       }

&nbsp;       else if (op == 8) {

&nbsp;           cout << biblio.listarLibros();

&nbsp;       }

&nbsp;       else if (op == 9) {

&nbsp;           cout << biblio.listarPrestamos();

&nbsp;       }

&nbsp;       else if (op == 10) {

&nbsp;           cout << biblio.listarPrestamosActivos();

&nbsp;       }

&nbsp;       else if (op == 11) {

&nbsp;           string ced; cout << "Cedula: "; cin >> ced;

&nbsp;           auto p = biblio.buscarEstudiantePtr(ced);

&nbsp;           cout << (p ? p->toString() : string("No encontrado")) << "\\n";

&nbsp;       }

&nbsp;       else if (op == 12) {

&nbsp;           int isbn; cout << "ISBN: "; cin >> isbn;

&nbsp;           auto p = biblio.buscarLibroPtr(isbn);

&nbsp;           cout << (p ? p->toString() : string("No encontrado")) << "\\n";

&nbsp;       }

&nbsp;       else {

&nbsp;           cout << "Opcion invalida\\n";

&nbsp;       }

&nbsp;   }

&nbsp;   cout << "Hasta luego!\\n";

&nbsp;   return 0;

}

```



---



\## 4) Notas y recomendaciones



- \*\*Propiedad de memoria\*\*

&nbsp; - `ContenedorEstudiantesDyn` y `ContenedorLibros3` son \*\*dueños\*\* de los objetos almacenados (`delete` en destructor y al eliminar).

&nbsp; - `Prestamo` guarda \*\*punteros no-propietarios\*\* a `Estudiante` y `Libro` (no los borra).

&nbsp; - `ContenedorPrestamosDyn` es \*\*dueño\*\* de los `Prestamo` que almacena.



- \*\*Duplicados\*\*

&nbsp; - Evita cédulas e ISBN duplicados en `insert` (retorna `false`).



- \*\*Regla de tres\*\*

&nbsp; - Para contenedores con `new`, implementa: constructor de copia, asignación y destructor.



- \*\*Compilación rápida (ejemplo C++17)\*\*

&nbsp; ```bash

&nbsp; g++ -std=c++17 -O2 -Wall -Wextra -I./include ./src/\*.cpp -o biblioteca\_app

&nbsp; ```



---



¡Éxitos! Con esto tienes la guía para implementar los contenedores, completar `Biblioteca` y ejecutar un `main` con menú
