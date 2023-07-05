// Lista 9 - Registros
// 17/06/2023

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct Ponto{
	float x;
	float y;
	
	float distancia(Ponto &p);
	void atribuir(float a, float b);
};

float Ponto::distancia(Ponto &p){
	return (sqrt((this->x-p.x)*(this->x-p.x) + (this->y-p.y)*(this->y-p.y)));
}

void Ponto::atribuir(float a, float b){
	this->x = a;
	this->y = b;
}

struct Triangulo{
	Ponto p1, p2, p3;
	float perimetro();
	float area();
	bool equilatero();
	bool semelhante(Triangulo &t);
};

float Triangulo::perimetro(){
	return (this->p1.distancia(this->p2) + this->p1.distancia(this->p3) + this->p2.distancia(this->p3));
}

float Triangulo::area(){
	return (this->p1.distancia(this->p2) * this->p1.distancia(this->p3)/2);
}

bool Triangulo::equilatero(){
	float p1p2 = this->p1.distancia(this->p2);
	float p1p3 = this->p1.distancia(this->p3);
	float p2p3 = this->p2.distancia(this->p3);
	if (p1p2 == p1p3 && p1p2 == p2p3){
		return true;
	}
	return false;
}

bool Triangulo::semelhante(Triangulo &t){
	if (
		(this->p1.distancia(this->p2)/t.p1.distancia(t.p2) == this->p2.distancia(this->p3)/t.p2.distancia(t.p3))
		&&
		(this->p1.distancia(this->p2)/t.p1.distancia(t.p2) == this->p1.distancia(this->p3)/t.p1.distancia(t.p3))
	   ){
		return true;
	   }
	return false;
}

struct Retangulo{
	Ponto p1, p2, p3, p4;
	float perimetro();
	float area();
	bool quadrado();
};

float Retangulo::perimetro(){
	return p1.distancia(p2) + p2.distancia(p3) + p3.distancia(p4) + p4.distancia(p1);
}

float Retangulo::area(){
	return p1.distancia(p2) * p2.distancia(p3);
}

bool Retangulo::quadrado(){
	if(	p1.distancia(p2) == p2.distancia(p3) &&
		p1.distancia(p2) == p3.distancia(p4) &&
		p1.distancia(p2) == p4.distancia(p1))
	{
		return 1;
	}
	return 0;
}

struct Circunferencia{
	float raio;
	Ponto centro;
	float perimetro();
	float area();
	bool contem(Ponto &p);
	bool contem(Triangulo &t);
	bool contem(Retangulo &r);
	bool pertence(Ponto &p);
	bool circunscrita(Triangulo &t);
	bool circunscrita(Retangulo &r);
};

float Circunferencia::perimetro(){
	return 2*M_PI*raio;
}

float Circunferencia::area(){
	return M_PI*raio*raio;
}

bool Circunferencia::contem(Ponto &p){
	if(centro.distancia(p) <= raio){
		return 1;
	}
	return 0;
}

bool Circunferencia::contem(Triangulo &t){
	if(	centro.distancia(t.p1) <= raio &&
		centro.distancia(t.p2) <= raio &&
		centro.distancia(t.p3) <= raio
	){
		return 1;
	}
	return 0;
}

bool Circunferencia::contem(Retangulo &r){
	if(
		centro.distancia(r.p1) <= raio &&
		centro.distancia(r.p2) <= raio &&
		centro.distancia(r.p3) <= raio &&
		centro.distancia(r.p4) <= raio
	){
		return 1;
	}
	return 0;
}

bool Circunferencia::pertence(Ponto &p){
	if(centro.distancia(p) == raio){
		return 1;
	}
	return 0;
}

bool Circunferencia::circunscrita(Triangulo &t){
	if(
		centro.distancia(t.p1) == raio &&
		centro.distancia(t.p2) == raio &&
		centro.distancia(t.p3) == raio
	){
		return 1;
	}
	return 0;
}

bool Circunferencia::circunscrita(Retangulo &r){
	if(
		centro.distancia(r.p1) == raio &&
		centro.distancia(r.p2) == raio &&
		centro.distancia(r.p3) == raio &&
		centro.distancia(r.p4) == raio
	){
		return 1;
	}
	return 0;
}

int main(){
	// Um exemplo de uso:
	Circunferencia c;
	c.centro.atribuir(0, 0);
	c.raio = 5;
	Triangulo t;
	t.p1.atribuir(0, 4);
	t.p2.atribuir(-3, 0);
	t.p3.atribuir(3, -3);
	if (c.contem(t)){
		printf("Triangulo dentro da circunferencia\n");
	} else{
		printf("Triangulo nao esta dentro da circunferencia\n");
	}
	return 0;
}