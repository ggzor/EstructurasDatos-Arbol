/**
 * Benemérita Universidad Autónoma de Puebla
 * Estructuras de datos
 * 
 * Implementación de la interfaz para mostrar recorridos
 *  en un arbol binario.
 * 
 * Fecha: 24/04/2019
 * 
 * Equipo:
 *   Axel Suárez Polo        201744436
 *   Marisol Huitzil Juárez  201745351
 *   Emmanuel Cortés Rosas   201764328
 *   Jafet Siliceo Luna      201759850
 * 
 */
#include "Arbol.hpp"
#include "Color.hpp"
#include "Utilerias.hpp"

#include <iostream>

// Lectura del grafo
Arbol<int> leerArbol()
{
  Arbol<int> arbol;

  int cantidadNodos;
  std::cout << "¿Cuántos nodos va a tener el árbol? " << enNegritas << colorVertice;
  std::cin >> cantidadNodos;
  std::cout << terminarColor;

  int valor;
  std::cout << "Valores del árbol: " << colorVertice << enNegritas;
  for (int i = 0; i < cantidadNodos; i++)
  {
    std::cin >> valor;
    arbol.insertar(valor);
  }
  std::cout << terminarColor;

  return arbol;
}

int main()
{
  Arbol<int> arbol = leerArbol();

  int op;
  do
  {
    limpiarTerminal();
    std::cout << arbol << std::endl;
    std::cout << "Menú:\n"
              << "  1. Mostrar PreOrden. \n"
              << "  2. Mostrar InOrden.\n"
              << "  3. Mostrar PostOrden.\n"
              << "  4. Mostrar hijos de un nodo. \n"
              << "  5. Salir. \n"
              << std::endl;
    std::cout << "Opción: ";
    std::cin >> op;
    std::cout << std::endl;

    switch (op)
    {
    case 1:
      if (arbol.estaVacio())
      {
        std::cout << acentuar << "El árbol está vacío." << terminarColor << std::endl;
      }
      else
      {
        // Realizar recorrido en PreOrden y mostrar los resultados.
        auto recorrido = arbol.recorrerPreOrden();

        std::cout << "El recorrido en PreOrden es: "
                  << colorVertice << enNegritas;
        for (auto nodo : recorrido)
        {
          std::cout << nodo->valor << ' ';
        }

        std::cout << terminarColor << std::endl;
      }

      esperarEnter();
      break;

    case 2:
    {
      if (arbol.estaVacio())
      {
        std::cout << acentuar << "El árbol está vacío." << terminarColor << std::endl;
      }
      else
      {
        // Realizar recorrido en EnOrden y mostrar los resultados.
        auto recorrido = arbol.recorrerEnOrden();

        std::cout << "El recorrido en EnOrden es: "
                  << colorVertice << enNegritas;
        for (auto nodo : recorrido)
        {
          std::cout << nodo->valor << ' ';
        }

        std::cout << terminarColor << std::endl;
      }

      esperarEnter();
      break;
    }
    case 3:
      if (arbol.estaVacio())
      {
        std::cout << acentuar << "El árbol está vacío." << terminarColor << std::endl;
      }
      else
      {
        // Realizar recorrido en PostOrden y mostrar los resultados.
        auto recorrido = arbol.recorrerPostOrden();
        std::cout << "El recorrido en PostOrden es: "
                  << colorVertice << enNegritas;
        for (auto nodo : recorrido)
        {
          std::cout << nodo->valor << ' ';
        }

        std::cout << terminarColor << std::endl;
      }
      esperarEnter();
      break;

    case 4:
      if (arbol.estaVacio())
      {
        std::cout << acentuar << "El árbol está vacío." << terminarColor << std::endl;
      }
      else
      {
        // Recibir el valor del nodo a buscar.
        int valor;
        std::cout << "Valor del nodo: " << colorVertice;
        std::cin >> valor;
        std::cout << terminarColor;

        auto resultado = arbol.buscarNodo(valor);

        if (resultado == nullptr)
        {
          std::cout << acentuar << "No se encontró el valor en el árbol." << terminarColor << std::endl;
        }
        else 
        {
          std::cout << "Los hijos del nodo son: " << std::endl;

          // Imprime el hijo de la izquierda si no es nulo, o una cadena que representa el valor nulo
          std::cout << "  Izquierda: " << terminarColor;
          if (resultado->izquierda == nullptr)
          {
            std::cout << acentuar << enNegritas << "nulo";
          }
          else
          {
            std::cout << colorVertice << enNegritas << resultado->izquierda->valor;
          }
          std::cout << terminarColor << std::endl;

          // Imprime el hijo de la derecha si no es nulo, o una cadena que representa el valor nulo
          std::cout << "  Derecha:   " << terminarColor;
          if (resultado->derecha == nullptr)
          {
            std::cout << acentuar << enNegritas << "nulo";
          }
          else
          {
            std::cout << colorVertice << enNegritas << resultado->derecha->valor;
          }
          std::cout << terminarColor << std::endl;
        }
      }
      esperarEnter();
      break;

    case 5:
      // Para evitar el siguiente mensaje
      break;

    default:
      std::cout << acentuar << "Opcion inválida." << terminarColor << std::endl;
      esperarEnter();
      break;
    }
  } while (op != 5);

  return 0;
}