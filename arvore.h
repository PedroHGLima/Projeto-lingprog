#pragma once
#include <iostream>

template <class T>
class Arvore {
    //friend ostream& operator<<(ostream& os, const Arvore& arvore);
    public:
        Arvore();
        Arvore(T *dado);
        ~Arvore();
        void inserir(T *dado);
        void remover(T *dado);
        T *buscar(T *dado);
        void imprimir();
    private:
        struct No {
            T *dado;
            No *esq;
            No *dir;
        };
        No *raiz;
        void inserir(T *dado, No *no);
        void remover(T *dado, No *no);
        T *buscar(T *dado, No *no);
        void imprimir(No *no);
};

template <class T>
Arvore<T>::Arvore() {
    raiz = nullptr;
}

template <class T>
Arvore<T>::Arvore(T *dado) {
    raiz = new No;
    raiz->dado = dado;
    raiz->esq = nullptr;
    raiz->dir = nullptr;
}

template <class T>
Arvore<T>::~Arvore() {}

template <class T>
void Arvore<T>::inserir(T *dado) {
    if (raiz == nullptr) {
        raiz = new No;
        raiz->dado = dado;
        raiz->esq = nullptr;
        raiz->dir = nullptr;
    } else {
        inserir(dado, raiz);
    }
}

template <class T>
void Arvore<T>::inserir(T *dado, No *no) {
    if (*dado < *(no->dado)) {
        if (no->esq == nullptr) {
            no->esq = new No;
            no->esq->dado = dado;
            no->esq->esq = nullptr;
            no->esq->dir = nullptr;
        } else {
            inserir(dado, no->esq);
        }
    } else if (*dado > *(no->dado)) {
        if (no->dir == nullptr) {
            no->dir = new No;
            no->dir->dado = dado;
            no->dir->esq = nullptr;
            no->dir->dir = nullptr;
        } else {
            inserir(dado, no->dir);
        }
    }
}

template <class T>
void Arvore<T>::remover(T *dado) {
    if (raiz != nullptr) {
        remover(dado, raiz);
    }
}

template <class T>
void Arvore<T>::remover(T *dado, No *no) {
    if (dado < no->dado) {
        if (no->esq != nullptr) {
            remover(dado, no->esq);
        }
    } else if (dado > no->dado) {
        if (no->dir != nullptr) {
            remover(dado, no->dir);
        }
    } else if (no->esq != nullptr && no->dir != nullptr) {
        no->dado = buscar_menor(no->dir)->dado;
        remover(no->dado, no->dir);
    } else {
        No *temp = no;
        if (no->esq != nullptr) {
            no = no->esq;
        } else {
            no = no->dir;
        }
        delete temp;
    }
}

template <class T>
T *Arvore<T>::buscar(T *dado) {
    if (raiz != nullptr) {
        return buscar(dado, raiz);
    } else {
        return nullptr;
    }
}

template <class T>
T *Arvore<T>::buscar(T *dado, No *no) {
    if (*dado < *(no->dado)) {
        if (no->esq != nullptr) {
            return buscar(dado, no->esq);
        }
    } else if (*dado > *(no->dado)) {
        if (no->dir != nullptr) {
            return buscar(dado, no->dir);
        }
    } else {
        return no->dado;
    }
    return nullptr;
}

template <class T>
void Arvore<T>::imprimir() {
    if (raiz != nullptr) {
        imprimir(raiz);
    }
}

template <class T>
void Arvore<T>::imprimir(No *no) {
    if (no->esq != nullptr) {
        imprimir(no->esq);
    }
    std::cout << *(no->dado) << std::endl;
    if (no->dir != nullptr) {
        imprimir(no->dir);
    }
}
