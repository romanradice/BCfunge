#include "Befunge.h"

using namespace std;

Befunge::Befunge(ifstream & codingRead){
    string ligne;
    while(codingRead.tellg() != -1){
        getline(codingRead,ligne);
        code.push_back(ligne);
    }
}

void Befunge::Exec(){
    int i = 0, y = 0;
    while(!ending){
        switch(code[y][i]){

            case '+':
                FonctionAddition();
                break;

            case '-':
                FonctionSoustraction();
                break;

            case '*':
                FonctionMultiplication();
                break;

            case  '/':
                FonctionDivision();
                break;

            case '%':
                FonctionModulo();
                break;

            case '!':
                FonctionNonLogique();
                break;

            case '`':
                FonctionPlusGrand();
                break;

            case '>':
                FonctionDroite();
                break;

            case '<':
                FonctionGauche();
                break;

            case '^':
                FonctionHaut();
                break;

            case 'v':
                FonctionBas();
                break;

            case '?':
				FonctionAlea();
                break;

            case '_':
                FonctionDepileDroiteGauche(i);
                break;

            case '|':
                FonctionDepileBasHaut(y);
                break;

            case '"':
                FonctionChaineCaracteres(i,y);
                break;

            case ':':
                FonctionDuplique();
                break;

            case '\'':
                FonctionPermute();
                break;

            case '$':
                FonctionDepile();
                break;

            case '.':
                FonctionDepileEntier();
                break;

            case ',':
                FonctionDepileASCII();
                break;

            case '#':
                FonctionTrampoline(i,y);
                break;

            case 'p':
				FonctionDepilexyv(i, y);
                break;

            case 'g':
				FonctionDepilexy(i, y);
                break;

            case '&':
				FonctionDemandeNombre();
                break;

            case '~':
				FonctionDemandeCaractere();
                break;

            case '@':
                FonctionFin();
                break;

            default:
                if (isdigit(code[y][i])){
                    FonctionEmpileNombre(code[y][i]);
                }
                break;
        }
        //sens de lecture du script
        SensLecture(i,y);
    }
}


//SENS LECTURE SCRIPT
void Befunge::SensLecture(int & i,int & y){
    if (sensFleche == 1) y--;
    else if(sensFleche == 2) i++;
    else if(sensFleche == 3) y++;
    else if(sensFleche == 4) i--;
}


void Befunge::FonctionTrampoline(int & i, int & y){
    SensLecture(i,y);
}

// FONCTION STOCKING STACK
void Befunge::FonctionEmpileNombre(char Digit){
    memoire.push(int(Digit) - '0'); //'0' = int(48)
}
void Befunge::FonctionChaineCaracteres(int & i,int & y){
    SensLecture(i,y);
    while(code[y][i] != '"'){
        memoire.push(int(code[y][i]));
        SensLecture(i,y);
    }
}


//FONCTION CALCULE
void Befunge::FonctionAddition(){
    if (memoire.size() >= 2){
        int digit = 0;
        for (int i = 0; i < 2;i++){
            digit += memoire.top();
            memoire.pop();
        }
        memoire.push(digit);
    }
    else{
        cout <<"ERROR : Il n'y a rien en memoire +"<<endl;
    }
}
void Befunge::FonctionSoustraction(){
    if (memoire.size() >= 2){
        int digit = memoire.top();
        memoire.pop();
        digit -= memoire.top();
        memoire.pop();
        memoire.push(digit);
        }
    else{
        cout <<"ERROR : Il n'y a rien en memoire -"<<endl;
    }
}
void Befunge::FonctionMultiplication(){
    if (memoire.size() >= 2){
        int digit = memoire.top();
        memoire.pop();
        digit *= int(memoire.top());
        memoire.pop();
        memoire.push(digit);
    }
    else{
        cout <<"ERROR : Il n'y a rien en memoire *"<<endl;
    }
}
void Befunge::FonctionDivision(){
    if (memoire.size() >= 2 ){
        int digit = memoire.top();
        memoire.pop();
        if(memoire.top() == 0){
            cout <<"division impossible, a/0. Quel resultat voulez-vous ?" <<endl;
            cin.ignore();
            cin >> digit;
        }
        else{
            digit /= memoire.top();
            memoire.pop();
        }

        memoire.push(digit);
    }
    else{
        cout <<"ERROR : Il n'y a rien en memoire /"<<endl;
    }
}
void Befunge::FonctionModulo(){
    if (memoire.size() >= 2 ){
        int digit = memoire.top();
        memoire.pop();
        if(memoire.top() == 0){
            cout <<"division impossible, a/0. Quel resultat voulez-vous ?" <<endl;
            cin.ignore();
            cin >> digit;
        }
        else{
            digit %= memoire.top();
        }

        memoire.push(digit);
    }
    else{
        cout <<"ERROR : Il n'y a rien en memoire %"<<endl;
    }
}


//FONCTION DE COMPARAISON
void Befunge::FonctionNonLogique(){
    int digit;
    if (memoire.size() >= 1 ){
        if (memoire.top() == 0){
            memoire.push(1);
        }
        else{
            memoire.push(0);
        }
        memoire.pop();
    }
    else{
        cout <<"ERROR : Il n'y a rien en memoire !"<<endl;
    }
}
void Befunge::FonctionPlusGrand(){
    if (memoire.size() >= 2){
        int digit = memoire.top();
        memoire.pop();
        if (memoire.top() > digit){
            memoire.push(1);
        }
        else{
            memoire.push(0);
        }
        memoire.pop();
    }
    else{
        cout <<"ERROR : Il n'y a rien en memoire"<<endl;
    }
}


//FONCTION DEPLACEMENT SCRIPT
void Befunge::FonctionDroite(){
    sensFleche = 2;
}
void Befunge::FonctionGauche(){
    sensFleche = 4;
}
void Befunge::FonctionHaut(){
    sensFleche = 1;
}
void Befunge::FonctionBas(){
    sensFleche = 3;
}

void Befunge::FonctionAlea()
{
	sensFleche = rand() % 4 + 1;
}

//FONCTION AFFICHER
void Befunge::FonctionDepileEntier(){
    if (memoire.size() > 0){
        cout <<memoire.top()<<endl;
        sentence += memoire.top();

        memoire.pop();
    }
    else{
        cout <<"ERROR : Il n'y a pas d'entier a lire en memoire."<<endl;
    }

}
void Befunge::FonctionDepileASCII(){
    if (memoire.size() > 0){
        cout <<char(memoire.top())<<endl;
        sentence += memoire.top();
        memoire.pop();
    }
    else{
        cout <<"ERROR : Il n'y a pas d'ASCII a lire en memoire."<<endl;
    }

}


//FONCTION CONDITION
void Befunge::FonctionDepileDroiteGauche(int & i){
    if (memoire.size() > 0){
        int digit = memoire.top();
        memoire.pop();
        if (digit == 0){
            i++;
        }
        else{
            i--;
        }
    }
    else{
        cout <<"ERROR : Il n'y a rien en memoire _"<<endl;
    }

}
void Befunge::FonctionDepileBasHaut(int & y){
    if (memoire.size() > 0){
        int digit = memoire.top();
        memoire.pop();
        if (digit == 0){
            y++;
        }
        else{
            y--;
        }
    }
    else{
        cout <<"ERROR : Il n'y a rien en memoire |"<<endl;
    }

}

//FONCTION ON STACK
void Befunge::FonctionDuplique(){
    if(memoire.size()> 0){
        memoire.push(memoire.top());
    }
    else{
        cout <<"ERROR : Il n'y a rien a memoire :"<<endl;
    }
}
void Befunge::FonctionPermute(){
    if (memoire.size() >= 2){
        int a = memoire.top();
        memoire.pop();
        int b = memoire.top();
        memoire.pop();

        //PUSH
        memoire.push(b);
        memoire.push(a);
    }
    else{
        cout <<"ERROR : Il n'y a rien a memoire "<<endl;
    }
}
void Befunge::FonctionDepile(){
    if (memoire.size() > 0){
        memoire.pop();
    }
    else{
        cout <<"ERROR : Il n'y a rien a depiller"<<endl;
    }
}

//FONCTION SAUVEGARDE
void Befunge::FonctionDepilexyv(int & i,int & y)
{
    if (memoire.size() > 2){
        y = memoire.pop();
        i = memoire.pop();
        int v = memoire.pop();
        code[y][i] = char(v);
    }
    else{
        cout <<"ERROR : Il n'y a rien a memoire "<<endl;
    }
}

void Befunge::FonctionDepilexy(int & i,int & y)
{
    if (memoire.size() > 1){
        y = memoire.pop();
        i = memoire.pop();
        memoire.push(int(code[y][i]));
    }
    else{
        cout <<"ERROR : Il n'y a rien a memoire "<<endl;
    }
}

//FONCTION DEMMANDE
void Befunge::FonctionDemandeNombre(){
    int digit;
    cin.ignore();
    cout<<"Choisissez un nombre -> ";
    cin >>digit;
    memoire.push(digit);
}
void Befunge::FonctionDemandeCaractere(){
    char car;
    cin.ignore();
    cout<<"Choisissez un caractere -> ";
    cin >>car;
    memoire.push(car);
}

//FONCTION END
void Befunge::FonctionFin(){
    ending = true;
    cout <<"phrase : "<<sentence<<endl;
}
