#pragma once
#include <iostream>
#include <vector>
template <class T>
class Arvore {
    template <class N> friend std::ostream& operator<<(std::ostream& os, Arvore<N>& arv);
    public:
        Arvore();
        Arvore(T *dado);
        ~Arvore();
        void inserir(T *dado);
        T *buscar(T *dado);
        T* get_valor();
        Arvore<T>* get_esq();
        Arvore<T>* get_dir();
        std::vector<T> arvoreToVector();

    private:
        T *valor;
        Arvore <T> *esq;
        Arvore <T> *dir;
        void inserir(T *dado, Arvore<T> *arv);
        T *buscar(T *dado, Arvore<T> *arv);
        void imprimir(Arvore<T> *arv);
};

template <class T>
Arvore<T>::Arvore() {
    this->valor = nullptr;
    this->esq = nullptr;
    this->dir = nullptr;
}

template <class T>
Arvore<T>::Arvore (T *dado) {
    this->valor = dado;
    this->esq = nullptr;
    this->dir = nullptr;
}

template <class T>
Arvore<T>::~Arvore() {}

template <class T>
void Arvore<T>::inserir(T *dado) {
    if (this->valor == nullptr) {
        this->valor = new T(*dado);
    } else {
        inserir(dado, this);
    }
}

template <class T>
void Arvore<T>::inserir(T *dado, Arvore<T> *arv) {
    if (*dado < *(arv->valor)) {
        if (arv->esq == nullptr) {
            arv->esq = new Arvore<T>(dado);
        } else {
            inserir(dado, arv->esq);
        }
    } else {
        if (arv->dir == nullptr) {
            arv->dir = new Arvore<T>(dado);
        } else {
            inserir(dado, arv->dir);
        }
    }
}

template <class T>
T *Arvore<T>::buscar(T *dado) {
    return buscar(dado, this);
}

template <class T>
T *Arvore<T>::buscar(T *dado, Arvore<T> *arv) {
    if (arv == nullptr) {
        return nullptr;
    } else if (*dado == *(arv->valor)) {
        return arv->valor;
    } else if (*dado < *(arv->valor)) {
        return buscar(dado, arv->esq);
    } else {
        return buscar(dado, arv->dir);
    }
}

template <class T>
std::ostream &operator<<(std::ostream &os, Arvore<T> &arv) {
    arv.imprimir(&arv);
    return os;
}
    
template <class T>
void Arvore<T>::imprimir(Arvore<T> *arv) {
    if (arv != nullptr) {
        imprimir(arv->esq);
        std::cout << *(arv->valor) << std::endl;
        imprimir(arv->dir);
    }
}

template <class T>
T* Arvore<T>::get_valor() {
    return this->valor;
}

template <class T>
Arvore<T>* Arvore<T>::get_esq() {
    return this->esq;
}

template <class T>
Arvore<T>* Arvore<T>::get_dir() {
    return this->dir;
}

template <class T> std::vector<T> Arvore<T>::arvoreToVector() {
    std::vector<T> vetor;
    if (this->valor != nullptr) {
        if (this->esq != nullptr) {
            std::vector<T> esq = this->esq->arvoreToVector();
            vetor.insert(vetor.end(), esq.begin(), esq.end());
        }
        vetor.push_back(*(this->valor));
        if (this->dir != nullptr) {
            std::vector<T> dir = this->dir->arvoreToVector();
            vetor.insert(vetor.end(), dir.begin(), dir.end());
        }
    }
    return vetor;
}