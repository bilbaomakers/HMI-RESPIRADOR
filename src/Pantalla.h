#ifndef _Pantalla
#define _Pantalla

#include <Arduino.h>
#include <NTPClient.h>					// Para la gestion de la hora por NTP
#include <WiFiUdp.h>					// Para la conexion UDP con los servidores de hora.
#include <ESP32Encoder.h>


class Pantalla
{



private:
    
    bool HayQueSalvar;
	String mificheroconfig;

    typedef void(*RespondeComandoCallback)(String comando, String respuesta);			// Definir como ha de ser la funcion de Callback (que le tengo que pasar y que devuelve)
	RespondeComandoCallback MiRespondeComandos = nullptr;								// Definir el objeto que va a contener la funcion que vendra de fuera AQUI en la clase.
	
    ESP32Encoder Encoder1, Encoder2, Encoder3, Encoder4;    
    
public:

    Pantalla(String fich_config_Pantalla);
    //~Pantalla();

    //  Variables Publicas
	String HardwareInfo;											// Identificador del HardWare y Software
	bool ComOK;														// Si la wifi y la conexion MQTT esta OK
	

	// Funciones Publicas
	String MiEstadoJson(int categoria);								// Devuelve un JSON con los estados en un array de 100 chars (la libreria MQTT no puede con mas de 100)
	void Run();														// Actualiza las propiedades de estado de este objeto en funcion del estado de motores y sensores
    void SetRespondeComandoCallback(RespondeComandoCallback ref);	// Definir la funcion para pasarnos la funcion de callback del enviamensajes
	boolean LeeConfig();
	boolean SalvaConfig();
    
};

#endif