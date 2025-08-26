#pragma once

class IVA
{
private:
	int iva;
	
public:
	IVA();
	IVA(int iva);
	~IVA();

	int getIva();
	void setIva(int iva);

	int calcularIva(int precio);
	int calcularPrecioConIva(int precio);
};

