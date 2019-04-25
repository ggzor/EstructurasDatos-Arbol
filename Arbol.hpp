/**
 * Benemérita Universidad Autónoma de Puebla
 * Estructuras de datos
 * 
 * Clase que representa un árbol binario no balanceado.
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

#if !defined(_ARBOL_HPP_)
#define _ARBOL_HPP_

#include <ostream>
#include "Lista.hpp"

/**
 * Estructura para representar los nodos de un árbol.
 */
template <typename T>
struct NodoArbol {
  T valor;
  NodoArbol<T> *izquierda = nullptr;
  NodoArbol<T> *derecha = nullptr;
};

template <typename T>
class Arbol
{
  private:
    NodoArbol<T> *raiz = nullptr;

  public:
    /**
     * Inserta un valor en el árbol de forma ordenada, delegando su funcionamiento al método privado
     * en caso de ser necesario.
     */
    void insertar(T valor)
    {
      if (estaVacio())
      {
        raiz = new NodoArbol<T>{valor};
      }
      else
      {
        insertar(raiz, valor);
      }
    }

    /**
     * Busca un nodo con el valor especificado, delega su funcionamiento a la función recursiva 
     * del mismo nombre
     */
    NodoArbol<T> *buscarNodo(T valor)
    {
      return buscarNodo(raiz, valor);
    }

    /**
     * Recorre el árbol en pre-orden, delegando su funcionamiento al método recursivo
     * del mismo nombre pero con visibilidad privada.
     */
    Lista<NodoArbol<T> *> recorrerPreOrden()
    {
      Lista<NodoArbol<T> *> resultado;
      recorrerPreOrden(raiz, resultado);
      return resultado;
    }

    /**
     * Recorre el árbol en in-orden, delegando su funcionamiento al método recursivo
     * del mismo nombre pero con visibilidad privada.
     */
    Lista<NodoArbol<T> *> recorrerEnOrden() {
      Lista<NodoArbol<T> *> resultado;
      recorrerEnOrden(raiz, resultado);
      return resultado;
    }

    /**
     * Recorre el árbol en post-orden, delegando su funcionamiento al método recursivo
     * del mismo nombre pero con visibilidad privada.
     */
    Lista<NodoArbol<T> *> recorrerPostOrden() {
      Lista<NodoArbol<T> *> resultado;
      recorrerPostOrden(raiz, resultado);
      return resultado;
    }

    /**
     * Obtiene los hijos de un nodo especificado.
     */
    Lista<NodoArbol<T> *> obtenerHijosDe(T valor) {
      NodoArbol<T> *nodo = buscarNodo(valor);

      if (nodo == nullptr) 
        return {};
      else
        return {nodo->izquierda, nodo->derecha}; 
    }

    /**
     * Este método regresa verdadero si el árbol está vacío.
     */
    bool estaVacio() {
      return raiz == nullptr;
    }

  private:
    /**
     * Inserta un elemento en el árbol dependiendo de su orden con respecto a los otros nodos.
     */
    void insertar(NodoArbol<T> *nodo, T valor)
    {
      if (valor < nodo->valor)
      {
        if (nodo->izquierda == nullptr)
        {
          nodo->izquierda = new NodoArbol<T>{valor};
        }
        else
        {
          insertar(nodo->izquierda, valor);
        }
      }
      else
      {
        if (nodo->derecha == nullptr)
        {
          nodo->derecha = new NodoArbol<T>{valor};
        }
        else
        {
          insertar(nodo->derecha, valor);
        }
      }
    }

    /**
     * Busca un nodo con el valor especificado, recursivamente.
     */
    NodoArbol<T> *buscarNodo(NodoArbol<T> *nodo, T valor)
    {
      // Caso base
      if (nodo == nullptr)
      {
        return nullptr;
      }
      else
      {
        // Buscar en el nodo especificado según sea el caso
        if (valor == nodo->valor)
        {
          return nodo;
        }
        else if (valor < nodo->valor)
        {
          return buscarNodo(nodo->izquierda, valor);
        }
        else
        {
          return buscarNodo(nodo->derecha, valor);
        }
      }
    }

    /**
     * Método interno para llenar la lista de resultados con el recorrido en pre-orden.
     */
    void recorrerPreOrden(NodoArbol<T> *nodo, Lista<NodoArbol<T> *> &resultado)
    {
      // Raíz - Izquierda - Derecha
      if (nodo != nullptr)
      {
        resultado.insertarFinal(nodo);
        recorrerPreOrden(nodo->izquierda, resultado);
        recorrerPreOrden(nodo->derecha, resultado);
      }
    }

    /**
     * Método interno para llenar la lista de resultados con el recorrido en in-orden.
     */
    void recorrerEnOrden(NodoArbol<T> *nodo, Lista<NodoArbol<T> *> &resultado)
    {
      // Izquierda - Raíz - Derecha
      if (nodo != nullptr)
      {
        recorrerEnOrden(nodo->izquierda, resultado);
        resultado.insertarFinal(nodo);
        recorrerEnOrden(nodo->derecha, resultado);
      }
    }

    /**
     * Método interno para llenar la lista de resultados con el recorrido en post-orden.
     */
    void recorrerPostOrden(NodoArbol<T> *nodo, Lista<NodoArbol<T> *> &resultado)
    {
      // Izquierda - Derecha - Raíz
      if (nodo != nullptr)
      {
        recorrerPostOrden(nodo->izquierda, resultado);
        recorrerPostOrden(nodo->derecha, resultado);
        resultado.insertarFinal(nodo);
      }
    }
};

/**
 * El toString de la clase.
*/
template <typename T>
std::ostream &operator<<(std::ostream &flujo, const Arbol<T> &arbol)
{
  return flujo;
}

#endif // _ARBOL_HPP_