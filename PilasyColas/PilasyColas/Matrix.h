#pragma once
#include "Coleccion.h"
#include <sstream>

class Matrix : public Coleccion
{
private:
	Base*** mat;
	int canFilas;
	int canColumnas;
	int can;
public:
	Matrix(int fil, int col) {
		canFilas = fil;
		canColumnas = col;
		can = 0;
		mat = new Base**[fil];
		for (int i = 0; i < fil; i++) {
			mat[i] = new Base * [col];
			for (int j = 0; j < col; j++) {
				mat[i][j] = nullptr;
			}
		}
		
	}
	virtual ~Matrix() {
		for (int i = 0; i < canFilas; i++) {
			for (int j = 0; j < canColumnas; j++) {
				delete mat[i][j];
			}
			delete[] mat[i];
		}
		delete[] mat;
	}

	virtual void agregar(Base* b) {
		if (!b) {
			return;
		}
		for (int i = 0; i < canFilas; i++) {
			for (int j = 0; j < canColumnas; j++) {
				if (mat[i][j] != nullptr) {
					mat[i][j] = b;
					return;
				}
			}
		}
	}
	virtual void eliminar(Base* filter) {
		for (int i = 0; i < canFilas; i++) {
			for (int j = 0; j < canColumnas; j++) {
				if (mat[i][j] == filter) {
					delete mat[i][j];
					mat[i][j] = nullptr;
					return;
				}
			}
		}
	}
	virtual Base* buscar(Base* filter) {
		for (int i = 0; i < canFilas; i++) {
			for (int j = 0; j < canColumnas; j++) {
				if (mat[i][j] == filter) {
					return mat[i][j];
				}
			}
		}
		return nullptr;
	
	}
	virtual string toString() {
		stringstream ss;
		for (int i = 0; i < canFilas; i++) {
			for (int j = 0; j < canColumnas; j++) {
				ss << mat[i][j]->toString() << " ";
			}
			ss << endl;
		}
		return ss.str();
	
	}
};

