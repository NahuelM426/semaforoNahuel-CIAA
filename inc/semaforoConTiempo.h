

#ifndef SEMAFOROCONTIEMPO_H_
#define SEMAFOROCONTIEMPO_H_

typedef struct SemaforoConTiempo {
	Semaforo sema;
	int TiempoRoja;
	int TiempoAmarilla;
	int TiempoVerde;
} SemaforoConTiempo;


void EstadoInicial(SemaforoConTiempo * semSec);
void SemaforoInicializar(SemaforoConTiempo * semSec, int Roja,
		int AsignarTiempoLuzRoja);
void SemaforoImprimir(SemaforoConTiempo * semSec);
void SemaforoPrenderLuz(SemaforoConTiempo * semSec, int colorLuz,int tiempoEncendido);
void CambiarLuz(SemaforoConTiempo * semSec, int colorLuz, int tiempoEncendido);
void cicloSemaforo(SemaforoConTiempo * semSec);






#endif /* SEMAFOROCONTIEMPO_H_ */
