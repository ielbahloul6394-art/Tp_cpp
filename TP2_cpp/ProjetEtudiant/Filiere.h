#ifndef FILIERE_H
#define FILIERE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Etudiant.h"

class Filiere {
private:
    std::string nomFiliere;
    std::vector<Etudiant*> etudiants;

public:
    Filiere(std::string nom) : nomFiliere(nom) {}

    ~Filiere() {
        for (Etudiant* e : etudiants) {
            e->setFiliere(nullptr);
            delete e;
        }

        etudiants.clear();
    }

    void inscrireEtudiant(Etudiant* e) {
        if (e == nullptr) {
            throw std::invalid_argument("Etudiant nul");
        }

        for (const auto* et : etudiants) {
            if (et == e) {
                throw std::runtime_error(
                    "Etudiant deja inscrit dans cette filiere"
                );
            }
        }

        if (e->getFiliere() != nullptr) {
            throw std::runtime_error(
                "Etudiant deja inscrit dans une autre filiere"
            );
        }

        etudiants.push_back(e);
        e->setFiliere(this);
    }

    void retirerEtudiant(Etudiant* e) {
        if (e == nullptr) {
            throw std::invalid_argument("Etudiant nul");
        }

        auto it = std::find(
            etudiants.begin(), etudiants.end(), e
        );

        if (it == etudiants.end()) {
            throw std::runtime_error(
                "Etudiant introuvable dans cette filiere"
            );
        }

        e->setFiliere(nullptr);
        etudiants.erase(it);
    }

    int getNombreEtudiants() const {
        return static_cast<int>(etudiants.size());
    }

    void afficherTous() const {
        std::cout << "Etudiants de la filiere "
                  << nomFiliere << ":" << std::endl;

        for (Etudiant* e : etudiants) {
            std::cout << "  - " << e->getNom()
                      << " (Moyenne: "
                      << e->calculerMoyenne()
                      << ")" << std::endl;
        }
    }
};

#endif
