

#include "semaforo.h"
#include "semaforoConTiempo.h"

int main(void) {

//	Semaforo inicializar;
//
//	SemaforoInicializar1(&inicializar, Roja);
//	SemaforoImprimir1(&inicializar);
//
//	SemaforoPrenderLuz1(&inicializar, Amarilla);
//	SemaforoImprimir1(&inicializar);

//	ApagarUnaLuz1(&inicializar, Amarilla);
//	SemaforoImprimir1(&inicializar);
//
//	CambiarLuz1(&inicializar, Verde);
//	SemaforoImprimir1(&inicializar);
//
//	CambiarLuz1(&inicializar, Amarilla);
//	SemaforoImprimir1(&inicializar);
//
//	CambiarLuz1(&inicializar, Roja);
//	SemaforoImprimir1(&inicializar);



	SemaforoConTiempo semaforo;

	int contador = 0;
	EstadoInicial(&semaforo);

	while (1) {
		cicloSemaforo(&semaforo);
		contador += 1;
	}
	return 0;
}

