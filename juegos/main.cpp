#include "miniwin.h"
#include <cstdio>
using namespace miniwin;

bool mostrarGameOver(char pointsStr[20]);
bool bola(float &x, float &y, float r, float &vx, float &vy, float &barX, float barY, float barAncho, int &points);
void reset(float &x, float &y, float &barX, int &points);


int main() {
	// Medidas de cuadro
	int x = 600;
	int y = 600;

	// Medidas de la barra
    float barX = 260;
    const float barY = 500;
    const float barAncho = 80;
    const float barAlto = 20;

	// Variables para la bola #1
    float pelotaX = 100;
    float pelotaY = 50;
    float pelotaRadio = 10;
    float pelotaVelX = 0;
    float pelotaVelY = 0;
    int startTime = 0;
    
    // Variables para la bola #2
    float pelota2X = 500;
    float pelota2Y = 50;
    float pelota2Radio = 10;
    float pelota2VelX = 0;
    float pelota2VelY = 0;
    int startTime2 = 500;
	
	// Variables de control
    bool exit = false;
    int points = 0;
    int dificultad = -1;
   	
   	
   	// ####### MENÚ DE DIFICULTAD #######
    vredimensiona(x, y);
    borra();
    
    color(VERDE);
    rectangulo((vancho() / 2)-200,(valto() / 3)-50,(vancho() / 2)+200,(valto() / 3)+150);
    texto((vancho() / 2) -80, valto() / 3, "SELECCIONA LA DIFICULTAD: ");
    refresca();
    texto((vancho() / 2) - 50, (valto() / 3) + 30, "1. Fácil   ^_^");
    texto((vancho() / 2) - 50, (valto() / 3) + 50, "2. Medio   O_O");
    texto((vancho() / 2) - 50, (valto() / 3) + 70, "3. Difícil   X_X");
    refresca();

    while (dificultad < 1 || dificultad > 3) {
	    int tecla = miniwin::tecla();
	    if (tecla >= '1' && tecla <= '3') {
	        dificultad = tecla - '0';
	        switch (dificultad) {
	            case 1:
	                pelotaVelX = 1;
	                pelotaVelY = 1;
	                pelota2VelX = 2;
    				pelota2VelY = 2;
	                break;
	            case 2:
	                pelotaVelX = 3;
	                pelotaVelY = 3;
	                pelota2VelX = 4;
    				pelota2VelY = 4;
	                break;
	            case 3:
	                pelotaVelX = 5;
	                pelotaVelY = 5;
	                pelota2VelX = 6;
    				pelota2VelY = 6;
	                break;
	        }
	    }
	}
    
	// ######### INICIO DEL JUEGO ########### 
    while (!exit) {
    	borra();
    	
        // Contar los puntos
        points += 1;
        char pointsStr[20];
        sprintf(pointsStr, "PUNTOS: %d", points);
        texto(vancho()-150, 20, pointsStr);
        
        color(BLANCO);
        rectangulo_lleno(barX, barY, barX + barAncho, barY + barAlto);
        color(ROJO);
        linea(0,barY+15,vancho(),barY+15);
        
        // ########### BOLA #1 #############
        color(BLANCO);
        if (points >= startTime) {
        	exit = bola(pelotaX, pelotaY, pelotaRadio, pelotaVelX, pelotaVelY, barX, barY, barAncho, points);
    	}
        // ########### BOLA #2 #############
        if (points >= startTime2) {
        	exit = bola(pelota2X, pelota2Y, pelota2Radio, pelota2VelX, pelota2VelY, barX, barY, barAncho, points);
        }
        
		// Manejar la barra con las teclas
        int tecla = miniwin::tecla();
        switch (tecla) {
            case IZQUIERDA:
                if (barX > 0) {
                    barX -= 25;
                }
                break;
            case DERECHA:
                if (barX < (vancho() - barAncho)) {
                    barX += 25;
                }
                break;
        }

        refresca();
        espera(20);
    }

    vcierra();
    return 0;
}


void reset(float &x, float &y, float &barX, int &points){
	points = 0;
    barX = 200;
    x = 200;
    y = 50;
}

bool bola(float &x, float &y, float r, float &vx, float &vy, float &barX, float barY, float barAncho, int &points) {
    bool exit = false;
    circulo_lleno(x, y, r);
    x += vx;
    y += vy;

    if (x - r < 0 || x + r > vancho()) {
        vx *= -1;
    }
    if (y - r < 0) {
        vy *= -1;
    }
    if (y + r > barY + 15) {
        //"Game Over"
        char pointsStr[20];
        sprintf(pointsStr, "PUNTOS: %d", points);
        texto(vancho()-150, 20, pointsStr);
		exit = mostrarGameOver(pointsStr);
		if(!exit){
			reset(x, y, barX, points);
		}
    }
    if (x >= barX && x <= barX + barAncho && y+r >= barY) {
        vy *= -1;
    }
    
    return exit;
}

bool mostrarGameOver(char pointsStr[20]){
	borra();
    color(ROJO);
    texto((vancho() / 2) - 50, valto() / 3, "Game Over");
    color(BLANCO);
    texto((vancho() / 2) - 50, (valto() / 3) + 20, pointsStr);
    refresca();
    espera(3000);
    borra();
    
    // "Menu de selección"
    color(VERDE);
    rectangulo((vancho() / 2)-200,(valto() / 3)-50,(vancho() / 2)+200,(valto() / 3)+150);
    texto((vancho() / 2) - 80, valto() / 3, "SELECCIONA UNA OPCIÓN:");
    texto((vancho() / 2) - 50, (valto() / 3) + 40, "1 - Jugar de nuevo");
    texto((vancho() / 2) - 50, (valto() / 3) + 60, "2 - Salir");
    refresca();
    
    bool menu = true;
    while (menu) {
        int seleccion = miniwin::tecla();
        if (seleccion == '1') {
            menu = false;
            break;
        } else if (seleccion == '2') {
            return true;
        }
    }
    return false;
}



