#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Registro {
    int id;
    double val;
    char activo;
public:
    Registro() : id(0), val(0), activo(1) {}
    Registro(int i, double v, char a = 1) : id(i), val(v), activo(a) {}
    int getId() const { return id; }
    double getVal() const { return val; }
    char getActivo() const { return activo; }
    void setVal(double v) { val = v; }
    void setActivo(char a) { activo = a; }
    void write(fstream& f) const { f.write((char*)&id, sizeof(id)); f.write((char*)&val, sizeof(val)); f.write((char*)&activo, sizeof(activo)); }
    bool read(fstream& f) { return (bool)f.read((char*)&id, sizeof(id)).read((char*)&val, sizeof(val)).read((char*)&activo, sizeof(activo)); }
};

class DB {
    string dataName;
    string logName;
public:
    DB(string d, string l) : dataName(d), logName(l) {}
    long buscar(int id) {
        fstream f(dataName, ios::in | ios::binary);
        if (!f) return -1;
        Registro r; long pos = 0;
        while (true) {
            long p = f.tellg();
            if (!r.read(f)) break;
            if (r.getId() == id) { f.close(); return p; }
            pos++;
        }
        f.close();
        return -1;
    }
    void upsert(int id, double v) {
        long p = buscar(id);
        if (p < 0) {
            fstream f(dataName, ios::out | ios::app | ios::binary);
            Registro r(id, v, 1); r.write(f); f.close();
        }
        else {
            fstream f(dataName, ios::in | ios::out | ios::binary);
            f.seekp(p);
            Registro r; f.read((char*)&r, sizeof(Registro));
            f.seekp(p);
        }
        fstream g(dataName, ios::in | ios::out | ios::binary);
        if (!g) { fstream h(dataName, ios::out | ios::binary); h.close(); }
        fstream k(dataName, ios::in | ios::out | ios::binary);
        if (p >= 0) {
            k.seekp(p);
            Registro r(id, v, 1); r.write(k); k.close();
        }
        else {
            k.seekp(0, ios::end);
            Registro r(id, v, 1); r.write(k); k.close();
        }
    }
    void logInsert(int id, double v) {
        ofstream l(logName, ios::app);
        l << "I " << id << " " << v << "\n";
        l.close();
    }
    void logUpdate(int id, double v) {
        ofstream l(logName, ios::app);
        l << "U " << id << " " << v << "\n";
        l.close();
    }
    void aplicarLog(const string& op, int id, double v) {
        upsert(id, v);
    }
    void recover() {
        ifstream l(logName);
        if (!l) return;
        string line;
        while (getline(l, line)) {
            if (line.empty()) continue;
            istringstream iss(line);
            string op; int id; double v;
            iss >> op >> id >> v;
            if (op == "I" || op == "U") aplicarLog(op, id, v);
        }
        l.close();
        ofstream clr(logName, ios::trunc); clr.close();
    }


    void txInsert(int id, double v) { logInsert(id, v); upsert(id, v); }
    void txUpdate(int id, double v) { logUpdate(id, v); upsert(id, v); }
    void listar() {
        fstream f(dataName, ios::in | ios::binary);
        if (!f) return;
        Registro r;
        while (r.read(f)) {
            if (r.getActivo()) cout << r.getId() << " " << r.getVal() << "\n";
        }
        f.close();
    }
};

int main() {
    DB db("data_journal.dat", "journal.log");
    db.recover();
    db.txInsert(1, 10.5);
    db.txInsert(2, 20.0);
    db.txUpdate(1, 11.0);
    db.listar();
    return 0;
}

// un archivo log o bitacora es un archivo que registra eventos que suceden en un sistema
// que un usuario se logueo queda un registro en el log
// que un usuario realizo una transaccion queda un registro en el log

// fulanito se logeo a las 3:00 pm

/*
El archivo de bitácora es: 
A) data_journal.dat 
B) journal.log 
C) recover.log 
D) log.bin

Respuesta: B) journal.log ☑

------------------------------------------------------------

El método que aplica operaciones del log es: 
A) listar 
B) aplicarLog 
C) buscar 
D) upsert

Respuesta: B) aplicarLog ☑  

------------------------------------------------------------

Las operaciones registradas son: 
A) A/R 
B) I/U 
C) D/C 
D) O/K

Respuesta: B) I/U ☑

------------------------------------------------------------

recover() al final: 
A) Borra el data 
B) Trunca el log 
C) Cierra sin cambios 
D) Duplica el log

Respuesta: B) Trunca el log ☑

------------------------------------------------------------

upsert inserta cuando: 
A) buscar < 0 
B) buscar > 0 
C) buscar==0 
D) Nunca

Respuesta: A) buscar < 0 ☑


------------------------------------------------------------

El dato persistido es: 
A) id y activo 
B) id, val, activo 
C) id y val 
D) val y activo

Respuesta : B) id, val, activo ☑

------------------------------------------------------------

El método que lista registros es: 

A) listar 

B) recover 

C) logInsert 

D) logUpdate

Respuesta: A) listar ☑




txInsert ejecuta: A) Solo upsert B) Solo logInsert C) logInsert y upsert D) Nada

Registro::write escribe en: A) Texto B) Binario C) JSON D) CSV

Registro::read devuelve: A) void B) bool C) int D) size_t

activo permite: A) Control de borrado B) Cifrado C) Compresión D) Indización

El formato del log es: A) Binario B) Texto C) XML D) YAML

buscar retorna: A) Posición o -1 B) bool C) string D) double

aplicarLog llama a: A) listar B) recover C) upsert D) buscar

txUpdate registra: A) I B) U C) D D) C

listar muestra solo cuando: A) activo==0 B) activo!=0 C) Siempre D) Nunca

El nombre del archivo de datos es: A) "data_journal.dat" B) "journal.log" C) "data.bin" D) "main.dat"

Registro serializa con: A) write/read B) << >> C) printf/scanf D) getline

recover se llama: A) Antes de transacciones B) Después C) Nunca D) Solo al final

upsert sobreescribe cuando: A) No hay id B) Ya existe id C) Log vacío D) Siempre inserta


*/