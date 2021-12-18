#include "surface.h"

Surface::Surface() {

}

Surface::~Surface() {

}

void Surface::SEARCH_TEXTURE(nodoTextures* lista, int n) {
    while ((lista != nullptr) && (lista->fileNumLoaded <= n)) {
        if (lista->fileNumLoaded == n) {
            Textura = lista;
            return;
        }
        lista = lista->siguiente; // avanza una posicion de la lista
    }

    Textura = nullptr;
}

void Surface::ADD_NEW_TEXTURE(SDL_Renderer*& renderer, nodoTextures*& lista, int n) {
    std::stringstream path;
    path << "Resources/graphics/" << n << ".bmp";

    auto* nuevo_nodo = new nodoTextures();
    nuevo_nodo->fileNumLoaded = n;
    nuevo_nodo->textureLoaded.loadFromFile(renderer, path.str());

    nodoTextures* aux1 = lista;
    auto* aux2 = new nodoTextures();

    while ((aux1 != nullptr) && (aux1->fileNumLoaded < n)) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lista == aux1) {
        lista = nuevo_nodo;
    } else {
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

    // Eliminamos la reserva de memoria.
    aux1 = nullptr;
    aux2 = nullptr;
    nuevo_nodo = nullptr;
    delete aux1;
    delete aux2;
    delete nuevo_nodo;
}

void Surface::DELETE_ALL_TEXTURES() {
    while (listTLoaded != nullptr) { // mientras no sea el final de la lista
        nodoTextures* aux = listTLoaded;
        aux->textureLoaded.freeMemory();
        listTLoaded = aux->siguiente;
        delete aux;
    }
}

void Surface::checkTextureExist(SDL_Renderer*& renderer, int n) {
    // primero busca
    SEARCH_TEXTURE(listTLoaded, n);

    // no existe?
    if (Textura == nullptr) {
        ADD_NEW_TEXTURE(renderer, listTLoaded, n); // agregamos
        SEARCH_TEXTURE(listTLoaded, n); // volvemos a buscar su posicion
    }
}

nodoTextures*& Surface::gTextura() {
    return Textura;
}