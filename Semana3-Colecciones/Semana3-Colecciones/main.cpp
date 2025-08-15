#include "Biblioteca.h"


// funciones de menu
int menuPrincipal();

int menuTransacciones();

int menuReportes();

// funciones de control de flujo

void principal(Biblioteca& b);

void transacciones(Biblioteca& b);

void reportes(Biblioteca& b);


// handlers 

Libro* crearLibro();

void ingresarLibro(Biblioteca& b);

Estudiante* crearEstudiante();

void ingresarEstudiante(Biblioteca& b);

void crearPrestamo(Biblioteca& b);

void devolverLibro(Biblioteca& b);

void listarLibros(Biblioteca& b);

void listarEstudiantes(Biblioteca& b);

void listarPrestamos(Biblioteca& b);

void listarPrestamos(Biblioteca& b);

void listarPrestamosActivos(Biblioteca& b);




int main() {
	int opcion;
	Biblioteca* biblioteca = new Biblioteca();
	principal(*biblioteca);
	delete biblioteca;
	return 0;
}

// ----------------------------------------------------------------------

int menuPrincipal()
{
	int opcion;

	cout << "<1> Transacciones." << endl;
	cout << "<2> Reportes." << endl;
	cout << "<3> Salir." << endl;

	cin >> opcion;
	return opcion;
}

int menuTransacciones()
{
	int opcion;

	cout << "<1> Ingresar Estudiante." << endl;
	cout << "<2> Ingresar Libro." << endl;
	cout << "<3> Prestar un Libro." << endl;
	cout << "<4> Devolver un Libro." << endl;
	cout << "<5> Salir." << endl;

	cin >> opcion;
	return opcion;
}

int menuReportes()
{
	int opcion;

	cout << "<1> Listar todos los Estudiantes," << endl;
	cout << "<2> Listar todos los Libros." << endl;
	cout << "<3> Listar todos los Prestamos." << endl;
	cout << "<4> Listar los prestamos Activos." << endl;
	cout << "<5> Salir." << endl;

	cin >> opcion;
	return opcion;
}

void principal(Biblioteca& b)
{
	int opcion;
	do {
		system("cls");
		opcion = menuPrincipal();
		switch (opcion)
		{
			case 1: {transacciones(b); }break;

			case 2: {reportes(b); }break;

			case 3: {cout << "Saliendo..." << endl; }break;

			default: {cout << "Opcion invalida.." << endl; }
		}
		system("pause");
	} while (opcion != 3);
}

void transacciones(Biblioteca& b)
{
	int opcion;
	do {
		system("cls");
		opcion = menuTransacciones();
		switch (opcion)
		{
		case 1: {ingresarEstudiante(b); }break;

		case 2: {ingresarLibro(b); }break;

		case 3: {crearPrestamo(b); }break;

		case 4: {devolverLibro(b); }break;

		case 5: {cout << "Saliendo..." << endl; }break;

		default: {cout << "Opcion invalida.." << endl; }
		}
		system("pause");
	} while (opcion != 5);
}

void reportes(Biblioteca& b)
{
	int opcion;
	do {
		system("cls");
		opcion = menuReportes();
		switch (opcion)
		{
		case 1: {listarEstudiantes(b); }break;

		case 2: {listarLibros(b); }break;

		case 3: {listarPrestamos(b); }break;

		case 4: {listarPrestamosActivos(b); }break;

		case 5: {cout << "Saliendo..." << endl; }break;

		default: {cout << "Opcion invalida.." << endl; }
		}
		system("pause");
	} while (opcion != 5);
}

Libro* crearLibro()
{
	int ISBN;
	double precio;
	string nombre;
	string autor;

	cout << endl<< "Ingrese el ISBN del Libro" << endl;
	cin >> ISBN;

	cout << endl<< "Ingrese el precio del Libro" << endl;
	cin >> precio;

	cout << endl<< "Ingrese el nombre del Libro" << endl;
	cin >> nombre;

	cout << endl<< "Ingrese el nombre del autor" << endl;
	cin >> autor;

	return new Libro(ISBN, precio, nombre, autor);
}

void ingresarLibro(Biblioteca& b)
{
	Libro* l = crearLibro();

	if (b.agregarLibro(*l)) {
		cout << "libro ingresado exitosamente" << endl;
	}
	else {
		cout << "No se pudo ingresar el libro" << endl;
		delete l;
	}
}

Estudiante* crearEstudiante()
{
	string cedula;
	string telefono;
	string email;
	string nombre;

	cout << endl << "Ingrese la cedula del Estudiante" << endl;
	cin >> cedula;

	cout << endl << "Ingrese el telefono del Estudiante" << endl;
	cin >> telefono;

	cout << endl << "Ingrese el email del Estudiante" << endl;
	cin >> email;

	cout << endl << "Ingrese el nombre del Estudiante" << endl;
	cin >> nombre;

	return new Estudiante(cedula, telefono, email, nombre);
}

void ingresarEstudiante(Biblioteca& b)
{
	Estudiante* e = crearEstudiante();

	if (b.registrarEstudiante(*e)) {
		cout << "estudiante ingresado exitosamente" << endl;
	}
	else {
		cout << "No se pudo ingresar el estudiante" << endl;
		delete e;
	}
}

void crearPrestamo(Biblioteca& b)
{
	string cedula;
	int isbn;
	listarEstudiantes(b);
	cout << endl << "ingrese la cedula del estudiante" << endl;
	cin >> cedula;

	listarLibros(b);
	cout << endl << "ingrese el isbn del libro" << endl;
	cin >> isbn;

	if (b.prestarLibro(cedula, isbn)) {
		cout << "Prestamo realizado exitosamente" << endl;
	}
	else {
		cout << "No se pudo realizar el prestamo" << endl;
	}
}

void devolverLibro(Biblioteca& b)
{
	string cedula;
	int isbn;
	listarEstudiantes(b);
	cout << endl << "ingrese la cedula del estudiante" << endl;
	cin >> cedula;

	listarLibros(b);
	cout << endl << "ingrese el isbn del libro" << endl;
	cin >> isbn;

	if (b.devolverLibro(cedula, isbn)) {
		cout << "Devolucion realizada exitosamente" << endl;
	}
	else {
		cout << "No se pudo realizar la devolucion" << endl;
	}
}

void listarLibros(Biblioteca& b)
{
	cout << endl << endl;
	cout << "------------------------------------" << endl;
	cout << "--------------- Libros -------------" << endl;
	cout << b.listarLibros() << endl;
	cout << "------------------------------------" << endl;
	cout << endl << endl;
}

void listarEstudiantes(Biblioteca& b)
{
	cout << endl << endl;
	cout << "------------------------------------" << endl;
	cout << "------------ Estudiantes -----------" << endl;
	cout << b.listarEstudiantes() << endl;
	cout << "------------------------------------" << endl;
	cout << endl << endl;
}

void listarPrestamos(Biblioteca& b)
{
	cout << endl << endl;
	cout << "------------------------------------" << endl;
	cout << "------------- Prestamos ------------" << endl;
	cout << b.listarPrestamos() << endl;
	cout << "------------------------------------" << endl;
	cout << endl << endl;
}

void listarPrestamosActivos(Biblioteca& b)
{
	cout << endl << endl;
	cout << "------------------------------------" << endl;
	cout << "--------- Prestamos Activos --------" << endl;
	cout << b.listarEstudiantes() << endl;
	cout << "------------------------------------" << endl;
	cout << endl << endl;
}


