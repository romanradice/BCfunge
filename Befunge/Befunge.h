#ifndef BEFUNGE_H_INCLUDED
#define BEFUNGE_H_INCLUDED

#include <vector>
#include <string>
#include <stack>

#include <fstream>

class Befunge
{
    public:

        Befunge(std::ifstream & codingRead);//Create Class
        void Exec();

    private:
        std::vector<std::string> code;
        std::stack<int> memoire;
        int sensFleche = 0;
        bool ending = false;

        std::string sentence = "";

    protected:
        void SensLecture(int & i,int & y);
        void FonctionEmpileNombre(char Digit);        //Empile ce nombre sur la pile
        void FonctionAddition();            //Addition: d�pile a et b, puis empile a+b
        void FonctionSoustraction();        //Soustraction: d�pile a et b, puis empile b-a
        void FonctionMultiplication();      //Multiplication: d�pile a et b, puis empile a*b
        void FonctionDivision();            //Division enti�re: d�pile a et b, puis empile la partie enti�re de b/a. Si a est nul, demande � l'utilisateur le r�sultat voulu.
        void FonctionModulo();              //Modulo: d�pile a et b, puis empile le reste de la division enti�re de b/a. Si a est nul, demande � l'utilisateur le r�sultat voulu.
        void FonctionNonLogique();          // 	NON logique: d�pile une valeur. Si elle est nulle, empile 1; sinon, empile 0.
        void FonctionPlusGrand();           // 	Plus grand que: D�pile a et b, puis empile 1 si b>a, sinon 0.
        void FonctionDroite();              // 	D�place vers la droite
        void FonctionGauche();              // 	D�place vers la gauche
        void FonctionHaut();                // 	D�place vers le haut
        void FonctionBas();                 //D�place vers le bas
        void FonctionAlea();                //D�place vers une direction al�atoire
        void FonctionDepileDroiteGauche(int & i);  //D�pile une valeur; d�place � droite si valeur=0, � gauche sinon
        void FonctionDepileBasHaut(int & y);       //D�pile une valeur; d�place en bas si valeur=0, en haut sinon
        void FonctionChaineCaracteres(int & i,int & y);    //D�marre le mode chaine de caract�res : empile chaque valeur ASCII jusqu'au prochain "
        void FonctionDuplique();            //Duplique la valeur en sommet de pile
        void FonctionPermute();             //Permute les deux valeurs en sommet de pile
        void FonctionDepile();              // 	D�pile une valeur
        void FonctionDepileEntier();        //D�pile une valeur et l'affiche en tant qu'entier
        void FonctionDepileASCII();         // 	D�pile une valeur et l'affiche en tant que caract�re ASCII
        void FonctionTrampoline(int & i, int & y);          //Trampoline: saute la cellule suivante
        void FonctionDepilexyv();           // 	D�pile y, x et v, puis change les caract�res � la position (x,y) dans le programme en le caract�re dont le code ASCII est v
        void FonctionDepilexy();            // 	D�pile y et x, puis empile la valeur ASCII du caract�re situ� � cette position dans le programme
        void FonctionDemandeNombre();       // 	Demande un nombre � l'utilisateur et l'empile
        void FonctionDemandeCaractere();  // 	Demande un caract�re � l'utilisateur et empile son code ASCII
        void FonctionFin();                 // 	Termine le programme
};


#endif // BEFUNGE_H_INCLUDED
