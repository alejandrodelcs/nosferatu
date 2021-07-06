#include "Contadores.h"
#include <iostream>
Contadores::Contadores() {
	// TODO Auto-generated constructor stub
	this->contador_humanos = 0;
	this->contador_zombis = 0;
	this->contador_vampiros = 0;
	this->contador_agua = 0;
	this->contador_cruces = 0;
	this->contador_estacas = 0;
	this->contador_escopetas = 0;
	this->contador_balas = 0;
}

void Contadores::reiniciar_contadores(){
	this->contador_humanos = 0;
	this->contador_zombis = 0;
	this->contador_vampiros = 0;
	this->contador_cruces = 0;
	this->contador_cruces = 0;
	this->contador_estacas = 0;
	this->contador_escopetas = 0;
	this->contador_balas = 0;
}

float Contadores::obtener_porcentaje_escopetas(){
	float escopeta_float = contador_escopetas;
	float balas_float = contador_balas;
	float porcentaje_escopetas = escopeta_float / balas_float;
	return porcentaje_escopetas;
}

float Contadores::obtener_porcentaje_balas(){
	return (contador_balas / contador_escopetas)*CIEN;
}

float Contadores::obtener_porcentaje_humanos(){
	float poblacion_total = contador_humanos + contador_vampiros + contador_zombis;
	float porcentaje_humano = (contador_humanos / poblacion_total)*CIEN;
	return porcentaje_humano;
}

float Contadores::obtener_porcentaje_vampiros(){
	float poblacion_total = contador_humanos + contador_vampiros + contador_zombis;
	float porcentaje_vampiros = (contador_vampiros / poblacion_total)*CIEN;
	return porcentaje_vampiros;
}

float Contadores::obtener_porcentaje_zombis(){
	float poblacion_total = contador_humanos + contador_vampiros + contador_zombis;
	float porcentaje_zombi = (contador_zombis / poblacion_total)*CIEN;
	return porcentaje_zombi;
}

float Contadores::obtener_porcentaje_agua(){
	float total_item_anti_plaga = contador_agua + contador_cruces + contador_estacas;
	float porcentaje_agua = (contador_agua / total_item_anti_plaga)*CIEN;
	return porcentaje_agua;
}

float Contadores::obtener_porcentaje_cruz(){
	float total_item_anti_plaga = contador_agua + contador_cruces + contador_estacas;
	float porcentaje_cruces = (contador_cruces / total_item_anti_plaga)*CIEN;
	return porcentaje_cruces;
}

float Contadores::obtener_porcentaje_estaca(){
	float total_item_anti_plaga = contador_agua + contador_cruces + contador_estacas;
	float porcentaje_estaca = (contador_estacas / total_item_anti_plaga)*CIEN;
	return porcentaje_estaca;
}

int Contadores::obtener_cantidad_humanos(){
	return this->contador_humanos;
}

int Contadores::obtener_cantidad_zombis(){
	return this->contador_zombis;
}

int Contadores::obtener_cantidad_vampiros(){
	return this->contador_vampiros;
}

int Contadores::obtener_cantidad_agua(){
	return this->contador_agua;
}

int Contadores::obtener_cantidad_cruces(){
	return this->contador_cruces;
}

int Contadores::obtener_cantidad_estacas(){
	return this->contador_estacas;
}

int Contadores::obtener_cantidad_escopetas(){
	return this->contador_escopetas;
}

int Contadores::obtener_cantidad_balas(){
	return this->contador_balas;
}

void Contadores::asignar_cantidad_humanos(int humanos){
	this->contador_humanos = humanos;
}

void Contadores::asignar_cantidad_zombis(int zombis){
	this->contador_zombis = zombis;
}

void Contadores::asignar_cantidad_vampiros(int vampiros){
	this->contador_vampiros = vampiros;
}

void Contadores::asignar_cantidad_agua(int agua){
	this->contador_agua = agua;
}

void Contadores::asignar_cantidad_cruces(int cruces){
	this->contador_cruces = cruces;
}

void Contadores::asignar_cantidad_estacas(int estacas){
	this->contador_estacas = estacas;
}

void Contadores::asignar_cantidad_escopetas(int escopetas){
	this->contador_escopetas = escopetas;
}

void Contadores::asignar_cantidad_balas(int balas){
	this->contador_balas = balas;
}

void Contadores::mostrar_estadisticas(){
	std::cout << std::endl;
	std::cout << "Humanos: " << this->contador_humanos << std::endl;
	std::cout << "Zombis: " << this->contador_zombis << std::endl;
	std::cout << "Vampiros: " << this->contador_vampiros << std::endl;
	std::cout << "balas: " << this->contador_balas << std::endl;
	std::cout << "Escopetas: " << this->contador_escopetas << std::endl;
	std::cout << "agua: " << this->contador_agua << std::endl;
	std::cout << "Cruces: " << this->contador_cruces << std::endl;
	std::cout << "Estacas: " << this->contador_estacas << std::endl;

	std::cout << "-----Porcentajes-----" << std::endl;
	std::cout << "Humanos: "<< obtener_porcentaje_humanos() << std::endl;
	std::cout << "Vampiros: " << obtener_porcentaje_vampiros() << std::endl;
	std::cout << "Zombi " << obtener_porcentaje_zombis() << std::endl;
	std::cout << "Agua: " << obtener_porcentaje_agua() << std::endl;
	std::cout << "Estaca: " << obtener_porcentaje_estaca() << std::endl;
	std::cout << "Cruz: " << obtener_porcentaje_cruz() << std::endl;
	std::cout << "Escopetas: " << obtener_porcentaje_escopetas() << std::endl;
	std::cout << "Balas: " << obtener_porcentaje_balas() << std::endl;
}

Contadores::~Contadores() {
	// TODO Auto-generated destructor stub
}

