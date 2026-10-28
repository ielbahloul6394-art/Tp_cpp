#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <iostream>
#include <string>
#include <stdexcept>

class Filiere;

class Etudiant {
private:
    std::string nom;
    std::string cin;
    double note1, note2, note3;
    Filiere* filiere;

public:
    Etudiant(std::string n, std::string c,
             double n1, double n2, double n3)
        : nom(n), cin(c),
          note1(n1), note2(n2), note3(n3),
          filiere(nullptr) {
        if (n1 < 0 || n1 > 20 ||
            n2 < 0 || n2 > 20 ||
            n3 < 0 || n3 > 20) {
            throw std::invalid_argument("Notes invalides");
        }
    }

    std::string getNom() const {
        return nom;
    }

    std::string getCin() const {
        return cin;
    }

    double calculerMoyenne() const {
        return (note1 + note2 + note3) / 3.0;
    }

    void setFiliere(Filiere* f) {
        filiere = f;
    }

    Filiere* getFiliere() const {
        return filiere;
    }

    void changerDeFiliere(Filiere* nouvelleFiliere);
};

#endif