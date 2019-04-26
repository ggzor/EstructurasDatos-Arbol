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

#include <cmath>
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


    /**
     * Regresa todos los nodos hoja del árbol, realizando
     */
    Lista<NodoArbol<T> *> obtenerHojas() {
      Lista<NodoArbol<T> *> resultado;

      auto recorrido = recorrerEnOrden();
      for (NodoArbol<T> *nodo : recorrido)
      {
        if (nodo->derecha == nullptr && nodo->izquierda == nullptr)
        {
          resultado.insertarFinal(nodo);
        }
      }

      return resultado;
    } 

    /**
     * Regresa el hermano de un nodo, delega la búsqueda al método recursivo.
     */
    NodoArbol<T> *obtenerHermano(T valor)
    {
      if (raiz != nullptr)
      {
        // La raíz no tiene hermanos
        if (raiz->valor == valor)
        {
          return nullptr;
        }
        else
        {
          // Delegar a metodo recursivo
          return obtenerHermano(raiz, valor);
        }
      }
      else
      {
        return nullptr;
      }
    }

    /**
     * Expone la raíz del árbol.
     */
    NodoArbol<T> *obtenerRaiz() {
      return raiz;
    }

    /**
     * Obtiene el padre de un nodo con el valor especificado
     */
    NodoArbol<T> *obtenerPadre(T valor)
    {
      if (raiz != nullptr)
      {
        if (raiz->valor == valor)
        {
          // La raíz no tiene padre
          return nullptr;
        }
        else
        {
          // Delegar a método recursivo
          return obtenerPadre(raiz, valor);
        }
      }
      else
      {
        return nullptr;
      }
    }

    /**
     * Obtiene los descendientes de un nodo
     */
    Lista<NodoArbol<T> *> obtenerDescendientes(T valor)
    {
      Lista<NodoArbol<T> *> resultadoFinal;
      Lista<NodoArbol<T> *> resultado;
      auto nodo = buscarNodo(valor);

      if (nodo == nullptr)
      {
        // El nodo no está en el árbol
        return resultado;
      }
      else
      {
        // Realizar un recorrido para llenarla con los resultados desde este nodo
        recorrerEnOrden(nodo, resultado);

        for (auto nodo : resultado)
        {
          if (nodo->valor != valor)
          {
            resultadoFinal.insertarFinal(nodo);
          }
        }

        return resultadoFinal;
      }
    }

    /**
     * Obtiene el camino entre dos nodos, si estos existen
     */
    Lista<NodoArbol<T> *> obtenerCamino(T valor1, T valor2) 
    {
      Lista<NodoArbol<T> *> resultado;

      return resultado;
    }

    /**
     * Obtiene la altura desde un nodo
     */
    int obtenerAltura(T valor)
    {
      auto nodo = buscarNodo(valor);

      if (nodo != nullptr)
      {
        return obtenerAltura(nodo);
      }
      else
      {
        return -1;
      }
    }

    /**
     * Obtener la altura total
     */
    int obtenerAlturaTotal()
    {
      return obtenerAltura(raiz);
    }

    /**
     * Obtiene el peso total del árbol
     */
    int obtenerPeso() {
      auto recorrido = recorrerPostOrden();
      return recorrido.obtenerLongitud();
    }

    /**
     * Verifica si el arbol es lleno
     */
    bool esLleno() {
      return std::pow(2, obtenerAlturaTotal() + 1) - 1 == obtenerPeso();
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

    /**
     * Regresa el hermano de un nodo, delega la búsqueda al método recursivo.
     */
    NodoArbol<T> *obtenerHermano(NodoArbol<T> *nodo, T valor)
    {
      if (nodo != nullptr)
      {
        if (nodo->izquierda != nullptr && nodo->izquierda->valor == valor)
        {
          return nodo->derecha;
        }
        else if (nodo->derecha != nullptr && nodo->derecha->valor == valor)
        {
          return nodo->izquierda;
        }
        else
        {
          auto resultadoIzquierda = obtenerHermano(nodo->izquierda, valor);

          if (resultadoIzquierda != nullptr)
          {
            return resultadoIzquierda;
          }
          else
          {
            return obtenerHermano(nodo->derecha, valor);
          }
        }
      }
      else
      {
        return nullptr;
      }
    }

    /**
     * Obtiene el padre de un nodo con el valor especificado
     */
    NodoArbol<T> *obtenerPadre(NodoArbol<T> *nodo, T valor)
    {
      if (nodo != nullptr)
      {
        if (nodo->izquierda != nullptr && nodo->izquierda->valor == valor)
        {
          return nodo;
        }
        else if (nodo->derecha != nullptr && nodo->derecha->valor == valor)
        {
          return nodo;
        }
        else
        {
          auto resultadoIzquierda = obtenerPadre(nodo->izquierda, valor);

          if (resultadoIzquierda != nullptr)
          {
            return resultadoIzquierda;
          }
          else
          {
            return obtenerPadre(nodo->derecha, valor);
          }
        }
      }
      else
      {
        return nullptr;
      }
    }

    /**
     * Método recursivo para obtener la altura de un árbol
     */
    int obtenerAltura(NodoArbol<T> *nodo) {
      if (nodo == nullptr) 
      {
        return 0;
      } else if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
        return 0;
      } else {
        return std::max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha)) + 1;
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