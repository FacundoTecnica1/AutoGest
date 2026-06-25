#include "alquiler.h"

Alquiler::Alquiler() {
    idAlquiler = 0;
    idAuto = 0;
    idCliente = 0;
    idUsuario = 0;
    metodoPago = "";
    fechaInicio = "";
    fechaFin = "";
    precioTotal = 0.0;
    estado = "";
}

Alquiler::Alquiler(int idAlquiler, int idAuto, int idCliente, int idUsuario, QString metodoPago, QString fechaInicio, QString fechaFin, double precioTotal, QString estado) {
    this->idAlquiler = idAlquiler;
    this->idAuto = idAuto;
    this->idCliente = idCliente;
    this->idUsuario = idUsuario;
    this->metodoPago = metodoPago;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
    this->precioTotal = precioTotal;
    this->estado = estado;
}

int Alquiler::getIdAlquiler() const{
    return idAlquiler;
}

void Alquiler::setIdAlquiler(int value){
    idAlquiler = value;
}

int Alquiler::getIdAuto() const {
    return idAuto;
}

void Alquiler::setIdAuto(int value){ idAuto = value;
}

int Alquiler::getIdCliente() const{
    return idCliente;
}

void Alquiler::setIdCliente(int value){
    idCliente = value;
}

int Alquiler::getIdUsuario() const {
    return idUsuario;
}

void Alquiler::setIdUsuario(int value){
    idUsuario = value;
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