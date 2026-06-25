#include "alquiler.h"

Alquiler::Alquiler() {
    id_alquiler = 0;
    id_auto = 0;
    id_cliente = 0;
    id_usuario = 0;
    metodoPago = "";
    fechaInicio = "";
    fechaFin = "";
    precioTotal = 0.0;
    estado = "";
}

Alquiler::Alquiler(int id_alquiler, int id_auto, int id_cliente, int id_usuario, QString metodoPago, QString fechaInicio, QString fechaFin, double precioTotal, QString estado) {
    this->id_alquiler = id_alquiler;
    this->id_auto = id_auto;
    this->id_cliente = id_cliente;
    this->id_usuario = id_usuario;
    this->metodoPago = metodoPago;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
    this->precioTotal = precioTotal;
    this->estado = estado;
}

int Alquiler::getid_alquiler() const{
    return id_alquiler;
}

void Alquiler::setid_alquiler(int value){
    id_alquiler = value;
}

int Alquiler::getid_auto() const {
    return id_auto;
}

void Alquiler::setid_auto(int value){ id_auto = value;
}

int Alquiler::getid_cliente() const{
    return id_cliente;
}

void Alquiler::setid_cliente(int value){
    id_cliente = value;
}

int Alquiler::getid_usuario() const {
    return id_usuario;
}

void Alquiler::setid_usuario(int value){
    id_usuario = value;
}

QString Alquiler::getMetodoPago() const {
    return metodoPago;
}

void Alquiler::setMetodoPago(const QString &value) {
    metodoPago = value;
}

QString Alquiler::getFechaInicio() const{
    return fechaInicio;
}

void Alquiler::setFechaInicio(const QString &value){
    fechaInicio = value;
}

QString Alquiler::getFechaFin() const{
    return fechaFin;
}

void Alquiler::setFechaFin(const QString &value){
    fechaFin = value;
}

double Alquiler::getPrecioTotal() const{
    return precioTotal;
}

void Alquiler::setPrecioTotal(double value){
    precioTotal = value;
}

QString Alquiler::getEstado() const {
    return estado;
}

void Alquiler::setEstado(const QString &value){
    estado = value;
}