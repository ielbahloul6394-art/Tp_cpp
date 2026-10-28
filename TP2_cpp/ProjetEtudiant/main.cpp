#include <iostream>
#include <exception>
#include "Etudiant.h"
#include "Filiere.h"

void Etudiant::changerDeFiliere(Filiere* nouvelleFiliere) {
    if (nouvelleFiliere == nullptr) {
        throw std::invalid_argument(
            "Nouvelle filiere invalide"
        );
    }

    if (filiere == nouvelleFiliere) {
        throw std::runtime_error(
            "Etudiant deja dans cette filiere"
        );
    }

    if (filiere != nullptr) {
        filiere->retirerEtudiant(this);
    }

    nouvelleFiliere->inscrireEtudiant(this);

    std::cout << nom
              << " a change de filiere."
              << std::endl;
}

int main() {
    Filiere* f1 = new Filiere("Informatique");
    Etudiant* e1 = nullptr;

    try {
        e1 = new Etudiant("Alice", "123", 15, 16, 17);

        f1->inscrireEtudiant(e1);

        std::cout << "Premiere inscription reussie."
                  << std::endl;

        f1->inscrireEtudiant(e1);
    }
    catch (const std::exception& e) {
        std::cerr << "Erreur : "
                  << e.what() << std::endl;
    }

    delete f1;

    return 0;
}
