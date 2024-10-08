#include "Fecha.h"

int Fecha::getDia() { return _dia; }
int Fecha::getMes() { return _mes; }
int Fecha::getAnio() { return _anio; }

std::string Fecha::getNombreDia()
{
    std::string nombres[7] = {
        "Domingo",
        "Lunes",
        "Martes",
        "Miercoles",
        "Jueves",
        "Viernes",
        "Sabado" };

    if (_diaSemana >= 0 && _diaSemana <= 6)
    {
        return nombres[_diaSemana];
    }
    return "";
}

void Fecha::setDia(int dia) { _dia = dia; }

void Fecha::setMes(int mes) { _mes = mes; }

void Fecha::setAnio(int anio) { _anio = anio; }

Fecha::Fecha()
{
    time_t t = time(NULL);
    struct tm* f = localtime(&t);
    _dia = f->tm_mday;
    _mes = f->tm_mon + 1;
    _anio = f->tm_year + 1900;
    _diaSemana = f->tm_wday;
}
Fecha::Fecha(int dia, int mes, int anio)
{
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    _diaSemana = -1;
}
std::string Fecha::toString()
{
    std::string valorADevolver;
    valorADevolver = std::to_string(_dia) +
        "/" + std::to_string(_mes) +
        "/" + std::to_string(_anio);

    return valorADevolver;
}
void Fecha::FechaActual()
{
    time_t t = time(NULL);
    struct tm* f = localtime(&t);
    _dia = f->tm_mday;
    _mes = f->tm_mon + 1;
    _anio = f->tm_year + 1900;
    _diaSemana = f->tm_wday;
}

bool Fecha::operator==(const Fecha& aux) const
{
    return (_dia == aux._dia) && (_mes == aux._mes) && (_anio == aux._anio);
}
