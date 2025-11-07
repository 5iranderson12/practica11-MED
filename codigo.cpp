#include <iostream>
#include <string>
using namespace std;

// ========== EJERCICIO 1: INVERTIR UN NÚMERO ==========
// Función auxiliar que recibe el número invertido acumulado
int invertirNumeroAux(int n, int invertido = 0) {
    // Caso base: cuando n es 0, retornar el número invertido
    if (n == 0) {
        return invertido;
    }
    
    // Extraer el último dígito (n mod 10)
    int ultimoDigito = n % 10;
    
    // Agregar el dígito al número invertido (multiplicar por 10 y sumar)
    invertido = invertido * 10 + ultimoDigito;
    
    // Llamada recursiva con el resto del número (n / 10)
    return invertirNumeroAux(n / 10, invertido);
}

// Función principal
int invertirNumero(int n) {
    // Manejar números negativos
    if (n < 0) {
        return -invertirNumeroAux(-n);
    }
    return invertirNumeroAux(n);
}

// ========== EJERCICIO 2: SUMA DE ELEMENTOS DE UN ARREGLO ==========
int sumaArreglo(int arr[], int tam) {
    // Caso base: si el tamaño es 0, la suma es 0
    if (tam == 0) {
        return 0;
    }
    
    // Sumar el último elemento con la suma recursiva del resto
    return arr[tam - 1] + sumaArreglo(arr, tam - 1);
}

// ========== EJERCICIO 3: INVERTIR UNA CADENA ==========
string invertirCadena(string cadena) {
    // Caso base: cadena vacía o de un solo carácter
    if (cadena.length() <= 1) {
        return cadena;
    }
    
    // Tomar el primer carácter y colocarlo al final de la inversión
    // recursiva del resto de la cadena
    return invertirCadena(cadena.substr(1)) + cadena[0];
}

// ========== EJERCICIO 4: CONTAR VOCALES ==========
bool esVocal(char c) {
    c = tolower(c); // Convertir a minúscula para facilitar comparación
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int contarVocales(string cadena) {
    // Caso base: cadena vacía
    if (cadena.empty()) {
        return 0;
    }
    
    // Si el primer carácter es vocal, suma 1
    int esVocalActual = esVocal(cadena[0]) ? 1 : 0;
    
    // Llamar recursivamente con el resto de la cadena
    return esVocalActual + contarVocales(cadena.substr(1));
}

// ========== FUNCIÓN MAIN PARA PROBAR TODOS LOS EJERCICIOS ==========
int main() {
    cout << "=== PRACTICA 11: RECURSION EN C++ ===" << endl << endl;
    
    // Prueba Ejercicio 1: Invertir número
    cout << "EJERCICIO 1: Invertir un numero" << endl;
    int numero = 1234;
    cout << "Numero original: " << numero << endl;
    cout << "Numero invertido: " << invertirNumero(numero) << endl;
    cout << "Numero negativo -567 invertido: " << invertirNumero(-567) << endl;
    cout << endl;
    
    // Prueba Ejercicio 2: Suma de arreglo
    cout << "EJERCICIO 2: Suma de elementos de un arreglo" << endl;
    int arreglo[] = {5, 10, 15, 20, 25};
    int tam = sizeof(arreglo) / sizeof(arreglo[0]);
    cout << "Arreglo: ";
    for (int i = 0; i < tam; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    cout << "Suma total: " << sumaArreglo(arreglo, tam) << endl;
    cout << endl;
    
    // Prueba Ejercicio 3: Invertir cadena
    cout << "EJERCICIO 3: Invertir una cadena" << endl;
    string texto = "hola";
    cout << "Cadena original: " << texto << endl;
    cout << "Cadena invertida: " << invertirCadena(texto) << endl;
    
    string texto2 = "recursion";
    cout << "Cadena original: " << texto2 << endl;
    cout << "Cadena invertida: " << invertirCadena(texto2) << endl;
    cout << endl;
    
    // Prueba Ejercicio 4: Contar vocales
    cout << "EJERCICIO 4: Contar vocales en una cadena" << endl;
    string frase = "Estructura de Datos";
    cout << "Cadena: " << frase << endl;
    cout << "Total de vocales: " << contarVocales(frase) << endl;
    
    string frase2 = "Universidad de Oriente";
    cout << "Cadena: " << frase2 << endl;
    cout << "Total de vocales: " << contarVocales(frase2) << endl;
    cout << endl;
    
    return 0;
}
