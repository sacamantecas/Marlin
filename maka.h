/*                                                              
                 ##   ###                     ###             
                ####   ##                      ##             
      ##  ##   ##  ##  ##  ##  ####            ## ##          
      #######  ##  ##  ## ##      ##           ### ##         
      #######  ######  ####    #####           ##  ##         
      ## # ##  ##  ##  ## ##  ##  ##     ##    ##  ##         
      ##   ##  ##  ## ###  ##  ### ##    ##   ###  ##         
                                                              

   Esta cabecera se carga 3 veces: una al principio de Configuration.ini (tras boards.h)
   otra hacia el final antes de Configuration_adv.h, y otra vez después
   
   hay cosas que se hacen sólo en la 2ª pasada, como la carga y corrección de pins.h
*/



#define MAKA					// para compilacion condicional
#define CUSTOM_MENDEL_NAME  "mAka"
#define MOTHERBOARD BOARD_RAMPS_13_EFB      // RAMPS 1.3 / 1.4 (Power outputs: Extruder, Fan, Bed) 
#define POWER_SUPPLY 2			// 2 = X-Box 360 203Watts
//#define PS_DEFAULT_OFF

//#define TEMP_SENSOR_1_AS_REDUNDANT
#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 30	// mi termistor secundario llega a marcar diferencias de 40º hasta que se estabiliza (luego va fino)

#define TEMP_RESIDENCY_TIME 5  // (seconds)
#define TEMP_HYSTERESIS 5       // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_WINDOW     2       // (degC) Window around target to start the residency timer x degC early.

#define TEMP_SENSOR_0 1			// 1 is 100k thermistor - best choice for EPCOS 100k (4.7k pullup)
#define TEMP_SENSOR_1 0			// 0 is not used
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_BED 1

// intercambio los pines del termistor redundante y la cama para usar un conector de 4 que viene del fusor
#ifdef SEGUNDA_INCLUSION
#include "pins.h" // cargar pins.h y corregir sus asignaciones
//efine TEMP_0_PIN         13
#define TEMP_1_PIN         14   
#define TEMP_BED_PIN       15 
#endif  


#define G3D_PANEL				// The GADGETS3D G3D LCD/SD Controller (blue PCB)
#define ENCODER_PULSES_PER_STEP 2
#define ENCODER_STEPS_PER_MENU_ITEM 1

  
//#undef PREVENT_DANGEROUS_EXTRUDE
//#undef PREVENT_LENGTHY_EXTRUDE


#define X_MAX_POS 209 // (con 210.5 coge el autolevel, y para soltarlo hay que empujar hasta 205.5)
#define Y_MAX_POS 208 // el super-tornillo trasero no me deja ir más allá
#define Z_MAX_POS 140 // más si se pasan los cables por delante, se retoca el conector del endstop de X, se baja la cama y se rediseña el soporte superior de los ejes Z
#define DISABLE_MAX_ENDSTOPS // los max_endstops los uso para otras cosas
#define INVERT_Z_DIR false

#define ENABLE_AUTO_BED_LEVELING
#undef Z_SAFE_HOMING
#undef AUTO_BED_LEVELING_GRID

////////////////////////////////////////////////////////////////////////
// OjO: las constantes "oficiales" son ?_PROBE_OFFSET_FROM_EXTRUDER, pero si defined(MAKA_ZP_CFG) necesito reconducirlas a variables,
// así que uso mk_?_PROBE_OFFSET_FROM_EXTRUDER para escribir los valores sólo una vez y usarlos en #define y/o en inicialización de array
#define mk_X_PROBE_OFFSET_FROM_EXTRUDER 28.32
#define mk_Y_PROBE_OFFSET_FROM_EXTRUDER -27.25
#define mk_Z_PROBE_OFFSET_FROM_EXTRUDER -5.35 // para que se pegue más, cantidad más pequeña (mayor en valor absoluto)
////////////////////////////////////////////////////////////////////////
#define X_PROBE_OFFSET_FROM_EXTRUDER mk_X_PROBE_OFFSET_FROM_EXTRUDER
#define Y_PROBE_OFFSET_FROM_EXTRUDER mk_Y_PROBE_OFFSET_FROM_EXTRUDER
#define Z_PROBE_OFFSET_FROM_EXTRUDER mk_Z_PROBE_OFFSET_FROM_EXTRUDER
////////////////////////////////////////////////////////////////////////

#undef Z_RAISE_BEFORE_HOMING	3

////////////////////////////////////////////////////////////////////////
// OjO: las constantes "oficiales" son Z_RAISE_*_*, pero si defined(MAKA_ZP_CFG) necesito reconducirlas a variables,
// así que uso mk_Z_RAISE_*_* para escribir los valores sólo una vez y usarlos en #define y/o en inicialización de array
#define mk_Z_RAISE_BEFORE_PROBING		(3 - Z_PROBE_OFFSET_FROM_EXTRUDER)
#define mk_Z_RAISE_BETWEEN_PROBINGS		2
#define mk_Z_RAISE_AFTER_PROBING		Z_RAISE_BETWEEN_PROBINGS
////////////////////////////////////////////////////////////////////////
#define Z_RAISE_BEFORE_PROBING			mk_Z_RAISE_BEFORE_PROBING	
#define Z_RAISE_BETWEEN_PROBINGS		mk_Z_RAISE_BETWEEN_PROBINGS 
#define Z_RAISE_AFTER_PROBING			mk_Z_RAISE_AFTER_PROBING	
////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
// OjO: las constantes "oficiales" son ABL_PROBE_PT_n_?, pero si defined(MAKA_ZP_CFG) necesito reconducirlas a variables,
// así que uso mk_ABL_PROBE_PT_n_c para escribir los valores sólo una vez y usarlos en #define y/o en inicialización de array
#define mk_ABL_PROBE_PT_1_X		X_MIN_POS + X_PROBE_OFFSET_FROM_EXTRUDER
#define mk_ABL_PROBE_PT_2_X		(X_MAX_POS - X_MIN_POS) / 2
#define mk_ABL_PROBE_PT_3_X		X_MAX_POS - 10
#define mk_ABL_PROBE_PT_1_Y		15
#define mk_ABL_PROBE_PT_2_Y		Y_MAX_POS + Y_PROBE_OFFSET_FROM_EXTRUDER
#define mk_ABL_PROBE_PT_3_Y		ABL_PROBE_PT_1_Y
////////////////////////////////////////////////////////////////////////
#define ABL_PROBE_PT_1_X	mk_ABL_PROBE_PT_1_X
#define ABL_PROBE_PT_2_X 	mk_ABL_PROBE_PT_2_X
#define ABL_PROBE_PT_3_X	mk_ABL_PROBE_PT_3_X
#define ABL_PROBE_PT_1_Y	mk_ABL_PROBE_PT_1_Y
#define ABL_PROBE_PT_2_Y	mk_ABL_PROBE_PT_2_Y
#define ABL_PROBE_PT_3_Y	mk_ABL_PROBE_PT_3_Y
////////////////////////////////////////////////////////////////////////


#define __XY_MAX__	210 // velocidad máxima horizontal (mm/min)
#define DEFAULT_AXIS_STEPS_PER_UNIT	{80.3, 80.3, 4000, 444.64} // extrusor de madera: 631.55
#define HOMING_FEEDRATE 			{50*60, 50*60, 3*60, 0}  // set the homing speeds (mm/min)
#define DEFAULT_MAX_FEEDRATE		{__XY_MAX__, __XY_MAX__, 3.6, 10}    // (mm/sec) // en movimientos simples aguanta 350, pero en uno diagonal, indicando una velocidad loca hay problemas (una solución sería evitar velocidades locas por mucho que se pidan)
#define XY_TRAVEL_SPEED				__XY_MAX__*60	// a tope


#define DEFAULT_MAX_ACCELERATION      {3000,3000,100,3000} 
#define DEFAULT_ACCELERATION          3000
#define DEFAULT_RETRACT_ACCELERATION  3000


// Preheat Constants
#define PLA_PREHEAT_HOTEND_TEMP 200
#define PLA_PREHEAT_HPB_TEMP 40
#define PLA_PREHEAT_FAN_SPEED 0  


// PID
#define  DEFAULT_Kp 12.67
#define  DEFAULT_Ki 2.06
#define  DEFAULT_Kd 19.52


#define LANGUAGE_INCLUDE "language_es.h" // cargo las definiciones por defecto, y luego modifico las que necesito
#include "language.h"
// traducciones negligentes
#define MSG_RESUMING             "Reanudando"
#define MSG_KILLED               "PARADA DE EMERGENCIA" 
#define MSG_VOLUMETRIC           "Filamento" 
/*
// features que no me interesan, y algo ahorramos
#undef PIDTEMP
#undef TEMP_RESIDENCY_TIME
#define DISABLE_M503
*/

// reclculos con variables que se han cambiado aqui
#define X_MAX_LENGTH (X_MAX_POS - X_MIN_POS)
#define Y_MAX_LENGTH (Y_MAX_POS - Y_MIN_POS)
#define Z_MAX_LENGTH (Z_MAX_POS - Z_MIN_POS)


#define BLOCK_BUFFER_SIZE	8	// funcionando con SD no hace falta más buffer, y reacciona mejor a la pausa

/*                                                                                
           ###                     #                                            
          ## ##                   ##                                            
          ##      ####   ####    #####  ##  ##  ## ###    ####    #####         
         ####    ##  ##     ##    ##    ##  ##   ### ##  ##  ##  ##             
          ##     ######  #####    ##    ##  ##   ##  ##  ######   ####          
          ##     ##     ##  ##    ## #  ##  ##   ##      ##          ##         
         ####     ####   ### ##    ##    ### ## ####      ####   #####          
*/

// organizar macros con cantidad variable de parámetros
#define macro_dispatcher_na_(_0,_1,_2,_3,_4,_5, n ,...)  n
#define macro_dispatcher_na(...)  macro_dispatcher_na_(__VA_ARGS__,5,4,3,2,1,0)
#define macro_dispatcher(func, ...) macro_dispatcher_(func, macro_dispatcher_na(__VA_ARGS__))
#define macro_dispatcher_(func, nargs) macro_dispatcher__(func, nargs)
#define macro_dispatcher__(func, nargs) func ## nargs

// macro debug() que puede tener 0, 1 o 2 parámetros
//#define dbug(args...)						// versión producción
#define dbug(args...) debug_(NULL,## args)		// versión desarrollo

#define debug_(...) macro_dispatcher(debug_, __VA_ARGS__)(__VA_ARGS__)
#define debug_0(filler) SERIAL_PROTOCOLLNPGM("paso")
#define debug_1(filler,val) debug_2(NULL,STRINGIFY(val),val)
#define debug_2(filler,msg,val) {SERIAL_PROTOCOLPGM("DBG - "msg": ");SERIAL_PROTOCOLLN(val);}



#define MAKA_ZP_CFG			// posición de la sonda Z configurable
#define MAKA_ALARMAS 		// la alarma sonora se detiene con M68, o actuando sobre el botón del ULTIPANEL; se reactiva con M68 P o con el menú del LCD
#define MAKA_FILAMENTO		// detector de falta de filamento, y solución en modo producción (se activa con M67 P)
#define MAKA_DESORDEN		// gestión de desorden mecánico
//#define TESTEANDO_MAKA_DESORDEN
#define MAKA_LCD_ENCODER	// acelerador de rotor del LCD
#define MAKA_PAUSA			// pausa mejorada
#define MAKA_SONDA_Z		// sonda de Z para autolevel, que sale y entra mecánicamente
#define MAKA_Z_PROBE		// protección frente a la posibilidad de que falle el z-probe
#define MAKA_VENTILADOR		// gestión mejorada del ventilador
#define MAKA_TEMPERATURA	// permisividad respecto a las diferencas de temperatura de los 2 termistores de hotend
#define MAKA_PULIDO			// refinamientos varios de escasa entidad
//#define MAKA_AUTONOMA		// elimina la comunicación por serie (son 17kb)
#define MAKA_KILL_INMEDIATO	// apagado inmediato de la máquina, sin retardos de ningún tipo


#ifdef MAKA_ZP_CFG	
	#define MAKA_ZP_CFG_MENU	"Calibracion Z"
	#define MAKA_ZP_CFG_MENU_PUNTO	"Punto "
	#define MAKA_ZP_CFG_MENU_OFFSET	"Offset "
	#define MAKA_ZP_CFG_MENU_RANTES	"Sube antes"
	#define MAKA_ZP_CFG_MENU_RENTRE	"Sube entre"
	#define MAKA_ZP_CFG_MENU_RFINAL	"Sube final"
	
	#define MAKA_ZP_CFG_RETRACTIL	true
	// M63 [S]: sonda retráctil
	#define MAKA_ZP_CFG_CODIGO_SR	63
	#define MAKA_ZP_CFG_RETRACTIL_MSG		"S. retractil"
	
	// OjO: redefinición de ?_PROBE_OFFSET_FROM_EXTRUDER
	#define MAKA_ZP_CFG_PROBE_OFFSET	{mk_X_PROBE_OFFSET_FROM_EXTRUDER, mk_Y_PROBE_OFFSET_FROM_EXTRUDER, mk_Z_PROBE_OFFSET_FROM_EXTRUDER}	
	#define X_PROBE_OFFSET_FROM_EXTRUDER probe_offset_from_extruder[0]
	#define Y_PROBE_OFFSET_FROM_EXTRUDER probe_offset_from_extruder[1]
	#define Z_PROBE_OFFSET_FROM_EXTRUDER probe_offset_from_extruder[2]
	// M64 [X offset_X] [Y offset_Y] [Z offset_Z]: por defecto, valores actuales para probe_offset
	// OjO: no se permite una combinación incoherente de probe_offset_from_extruder y maka_zp_punto, acotando los puntos
	#define MAKA_ZP_CFG_CODIGO_PO	64

	// OjO: redefinición de Z_RAISE_*
	#define MAKA_Z_RAISE					{mk_Z_RAISE_BEFORE_PROBING, mk_Z_RAISE_BETWEEN_PROBINGS, mk_Z_RAISE_AFTER_PROBING}
	#define Z_RAISE_BEFORE_PROBING			probe_raise[0]
	#define Z_RAISE_BETWEEN_PROBINGS		probe_raise[1]
	#define Z_RAISE_AFTER_PROBING			probe_raise[2]
	// M65 [P primero] [S siguientes] [F final]: por defecto, valores actuales
	#define MAKA_ZP_CFG_CODIGO_PR	65

	// OjO: redefinición de ABL_PROBE_PT_n_?
	#define MAKA_ABL_PROBE		{{mk_ABL_PROBE_PT_1_X, mk_ABL_PROBE_PT_1_Y}, {mk_ABL_PROBE_PT_2_X, mk_ABL_PROBE_PT_2_Y}, {mk_ABL_PROBE_PT_3_X, mk_ABL_PROBE_PT_3_Y}}
	#define ABL_PROBE_PT_1_X	maka_zp_punto[0][0]
	#define ABL_PROBE_PT_2_X 	maka_zp_punto[1][0]
	#define ABL_PROBE_PT_3_X	maka_zp_punto[2][0]
	#define ABL_PROBE_PT_1_Y	maka_zp_punto[0][1]
	#define ABL_PROBE_PT_2_Y	maka_zp_punto[1][1]
	#define ABL_PROBE_PT_3_Y	maka_zp_punto[2][1]
	// M66 [P{1..3}] [X offset_X] [Y offset_Y]: sin P se ignora; el nº de punto se acota; las coordenadas por defecto son las actuales para X-Y
	// OjO: no se permite una combinación incoherente de probe_offset_from_extruder y maka_zp_punto, acotando los puntos
	#define MAKA_ZP_CFG_CODIGO_PP	66

	#ifndef SEGUNDA_INCLUSION
		extern float maka_zp_punto[3][2];
		extern float probe_offset_from_extruder[3];
		extern float probe_raise[3];
		extern bool maka_sonda_retractil;
	#endif
#endif



#ifdef MAKA_ALARMAS
	#define MAKA_ALARMAS_DURACION	100	// duración mínima, que se va alargando mientras se mantenga la causa
	#define MAKA_ALARMAS_LED_PIN	2  // si está asignado, se pone a 1 ese puerto mientras se mantenga la causa (no evitable)
	#define MAKA_ALARMAS_CODIGO		68 // con M68 de calla la alarma y con M68P se activa el pitido
	#define MAKA_ALARMAS_MSG	 "alarma silente"	                              
#endif

#ifdef MAKA_FILAMENTO
	#define MAKA_FILAMENTO_PIN	15 // originalmente Y_MAX_PIN
	#define MAKA_FILAMENTO_INVERTING true 
	#define MAKA_FILAMENTO_RETRACCION 20 // retracción de filamento antes de apagar el fusor (la cama se mantiene para que no se despegue la pieza)
	#define MAKA_FILAMENTO_ALARMA_FRE	1000
	#define MAKA_FILAMENTO_ALARMA_PIP	400
	#define MAKA_FILAMENTO_MSG	"FALTA FILAMENTO"
	#if MAKA_FILAMENTO_ALARMA_PIP < 50	
	#error la duracion del pulso de la alarma debe ser >= 50
	#endif
#endif MAKA_FILAMENTO	

#ifdef MAKA_DESORDEN
	#define MAKA_DESORDEN_PIN	19 // originalmente Z_MAX_PIN
	#define MAKA_DESORDEN_INVERTING false
	#define MAKA_DESORDEN_ALARMA_FRE	2000
	#define MAKA_DESORDEN_ALARMA_PIP	100
	#define MAKA_DESORDEN_MSG	"DESORDEN MECANICO"
	#if MAKA_DESORDEN_ALARMA_PIP < 50	
	#error la duracion del pulso de la alarma debe ser >= 50
	#endif
#endif MAKA_DESORDEN

#ifdef MAKA_LCD_ENCODER
	#define MAKA_LCD_ENCODER_TIEMPO 200 // tiempo entre clics por debajo del cual se multiplica por 5 el nº de pasos (300 induce a error y 100 no es práctico)
#endif MAKA_LCD_ENCODER

#ifdef MAKA_PULIDO
	#ifdef TEMP_SENSOR_1_AS_REDUNDANT
		#define MAKA_PULIDO_MSG_TERMOMETRO "T. fusor / incremento"
	#endif
	#define MAKA_PULIDO_XY_HOME	"Ir al origen XY"
	#define MAKA_PULIDO_Z_HOME	"Ir al origen Z"
	#ifdef MAKA_SONDA_Z
		#define MAKA_PULIDO_Z_G29	"Calibrar Z"
	#endif
	#define MAKA_PULIDO_BAJA_Z	"Baja 1mm forzado"
#endif

#ifdef MAKA_PAUSA
  #define MAKA_PAUSA_APARCA_X	0
  #define MAKA_PAUSA_APARCA_Y	500
  #define MAKA_PAUSA_ALZAMIENTO	1
  #define MAKA_PAUSA_RETRACCION	2
  #define MAKA_PAUSA_INVOCACION	PSTR("M25")
  #define MAKA_PAUSA_MSG	"pausa"
#endif


#ifdef MAKA_SONDA_Z
	#ifdef ENABLE_AUTO_BED_LEVELING
		#define	MAKA_SONDA_Z_SACA_COGER		209
		#define	MAKA_SONDA_Z_SACA_DESDE		MAKA_SONDA_Z_SACA_COGER + 2.5
		#define	MAKA_SONDA_Z_SACA_HASTA		MAKA_SONDA_Z_SACA_DESDE - 11.5
		#define	MAKA_SONDA_Z_SACA_SUELTA	MAKA_SONDA_Z_SACA_HASTA + 1
		#define	MAKA_SONDA_Z_METE_DESDE		195
		#define	MAKA_SONDA_Z_METE_HASTA		MAKA_SONDA_Z_METE_DESDE + 11
	#else
		#undef MAKA_SONDA_Z
	#endif
#endif


#ifdef MAKA_Z_PROBE
	#ifdef ENABLE_AUTO_BED_LEVELING
		#define MAKA_Z_PROBE_MSG_L	"No puedo encontrar la cama: puede estar muy abajo o haber fallado el sistema"
		#define MAKA_Z_PROBE_MSG_C	"Err: NO VEO ORIGEN Z"
		#define MAKA_Z_PROBE_RANGO	1 // máximo desnivel admisible
	#else
		#undef MAKA_Z_PROBE		
	#endif
#endif

#ifdef MAKA_TEMPERATURA
	#ifdef TEMP_SENSOR_1_AS_REDUNDANT
		#define MAKA_TEMPERATURA_MSG	"TMP.INCIERTA: \0999.9"
		#define MAKA_TEMPERATURA_CONFIRMACION	10*1000	// ms consecutivos para tomar en serio la alarma y tomar medidas
		#define MAKA_TEMPERATURA_ACTUALIZACION	6*1000 	// periodo de refresco de la temperatura mientras dure la alarma
		#define MAKA_TEMPERATURA_ACTUACION	5*60*1000 // momento en el que hay que actuar (se ha dado tiempo al usuario para desactivar el modo autónomo)
		#define MAKA_TEMPERATURA_ALARMA_FRE	8000
		#define MAKA_TEMPERATURA_ALARMA_PIP	50
	#else
		#undef MAKA_TEMPERATURA
	#endif
#endif


#define MAKA_PRODUCCION		defined(MAKA_FIILAMENTO) || defined(MAKA_Z_PROBE) || defined(MAKA_TEMPERATURA)
#ifdef MAKA_PRODUCCION
	#define MAKA_PRODUCCION_MSG "modo autonomo"
	#define MAKA_PRODUCCION_CODIGO	67
#endif	


#define MAKA defined(MAKA_ALARMAS) || defined(MAKA_FILAMENTO) || defined(MAKA_DESORDEN) || defined(MAKA_LCD_ENCODER) \
		  || defined(MAKA_PAUSA) || defined(MAKA_SONDA_Z) || defined(MAKA_Z_PROBE) || defined(MAKA_VENTILADOR) || defined(MAKA_PULIDO) \
		  || defined(MAKA_KILL_INMEDIATO)


/*
MAKA_Z_PROBE: falta investigar qué pasa cuando el error se produce desde SD
lo propio sería abortar la lectura
*/
#define SEGUNDA_INCLUSION
