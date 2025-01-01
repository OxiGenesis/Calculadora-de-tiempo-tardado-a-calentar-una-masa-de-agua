# Calentador de Agua

## Descripción

**Calentador de Agua** es una aplicación de escritorio que permite calcular el tiempo necesario para calentar una cierta cantidad de agua a una temperatura máxima específica. Utiliza un sistema de inducción para estimar el tiempo en función de la potencia aplicada.

## Características

- Cálculo de tiempo de calentamiento basado en la potencia de inducción.
- Interfaz gráfica moderna con Qt.
- Estimación del tiempo en horas y minutos.


## Requisitos

### Software

- Qt 5.15 o superior.
- C++17.
- Linux (pero también puedes compilar para Windows y dispositivos Android).

### Dependencias

Asegúrate de tener instalados los siguientes paquetes en tu sistema:

- **Qt 5**: Para la interfaz gráfica.
- **GCC o MinGW**: Para compilar el código en tu sistema.

### Instalación

1. Clona este repositorio
2. Entra al directorio del proyecto
3. Instala las dependencias necesarias de Qt y el compilador:
    -En Linux (Ubuntu/Debian):
       sudo apt-get install qt5-qmake qtbase5-dev qtbase5-dev-tools build-essential
4. Compila el proyecto usando qmake:
     qmake & make
5. Ejecuta la aplicación

   
