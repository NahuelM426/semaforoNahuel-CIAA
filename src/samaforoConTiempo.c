#include "semaforo.h"
#include "semaforoConTiempo.h"
#include <sapi.h>

int tiempoLuzRoja = 4000;
int tiempoLuzAmarilla = 3000;
int tiempoLuzVerde = 2000;

void EstadoInicial(SemaforoConTiempo * semSec) {
	semSec->sema.LuzRoja = 0;
	(semSec->TiempoRoja) = 0;
	semSec->sema.LuzAmarilla = 0;
	(semSec->TiempoAmarilla) = 0;
	semSec->sema.LuzVerde = 0;
	(semSec->TiempoVerde) = 0;

}
void SemaforoInicializar(SemaforoConTiempo * semSec, int LuzAPrender,
		int AsignarTiempoALuz) {

EstadoInicial(semSec);
	if (Roja == LuzAPrender) {
		(semSec->sema.LuzRoja) = 1;
		semSec->TiempoRoja = AsignarTiempoALuz;
		delay(semSec->TiempoRoja);
	}
	if (Amarilla == LuzAPrender) {
		(semSec->sema.LuzAmarilla) = 1;
		semSec->TiempoAmarilla = AsignarTiempoALuz;
		delay(semSec->TiempoAmarilla);
	}
	if (Verde == LuzAPrender) {
		(semSec->sema.LuzVerde) = 1;
		semSec->TiempoVerde = AsignarTiempoALuz;
		delay(semSec->TiempoVerde);
	}

}
void SemaforoImprimir(SemaforoConTiempo * semSec) {

	if ((semSec->sema.LuzRoja) == 1) {
		gpioWrite(LED2,ON);
	} else {
		gpioWrite(LED2,OFF);

	}
	if ((semSec->sema.LuzAmarilla) == 1) {
		gpioWrite(LED1,ON);
	} else {
		gpioWrite(LED1,OFF);

	}
	if ((semSec->sema.LuzVerde) == 1) {
		gpioWrite(LED3,ON);
	} else {
		gpioWrite(LED3,OFF);

	}
}
void SemaforoPrenderLuz(SemaforoConTiempo * semSec, int colorLuz,
		int tiempoEncendido) {

	EstadoInicial(semSec);
	if (Roja == colorLuz) {
		semSec->sema.LuzRoja = 1;
		semSec->TiempoRoja = tiempoEncendido;
		delay(semSec->TiempoRoja);
	}
	if (Amarilla == colorLuz) {
		semSec->sema.LuzAmarilla = 1;
		semSec->TiempoAmarilla = tiempoEncendido;
		delay(semSec->TiempoAmarilla);
	}
	if (Verde == colorLuz) {
		semSec->sema.LuzVerde = 1;
		semSec->TiempoVerde = tiempoEncendido;
		delay(semSec->TiempoVerde);
	}
}

void CambiarLuz(SemaforoConTiempo * semSec, int colorLuz, int tiempoEncendido) {
	EstadoInicial(semSec);
	SemaforoPrenderLuz(semSec, colorLuz, tiempoEncendido);
}

void cicloSemaforo(SemaforoConTiempo * semSec) {
	EstadoInicial(semSec);

	SemaforoInicializar(semSec, Verde, tiempoLuzVerde);
	SemaforoImprimir(semSec);

	CambiarLuz(semSec, Amarilla, tiempoLuzAmarilla);
	SemaforoImprimir(semSec);

	CambiarLuz(semSec, Roja, tiempoLuzRoja);
	SemaforoImprimir(semSec);

	CambiarLuz(semSec, Amarilla, tiempoLuzAmarilla);
	SemaforoImprimir(semSec);

}




