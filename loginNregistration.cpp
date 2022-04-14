#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
class Client
{
private:
    int age;
    string nom;
    string prenom;
    string mdp;

public:
    Client()
    {
    }
    Client(int a, string n, string p, string md)
    {
        age = a;
        nom = n;
        prenom = p;
        mdp = md;
    }
    // getter
    void getData()
    {
        cout << nom << endl
             << prenom << endl
             << age << endl;
    }
    string getNom()
    {
        return nom;
    }
    string getpswd()
    {
        return mdp;
    }
    // setter
    void setData()
    {
        cout << "Entrez votre nom de famille" << endl;
        if (!(cin >> nom))
        {
            perror("enter a valid name");
            exit(EXIT_FAILURE);
        }
        cout << "Entrez votre prénom" << endl;
        if (!(cin >> prenom))
        {
            perror("enter a valid name");
            exit(EXIT_FAILURE);
        }
        cout << "Entrez votre age" << endl;
        if (!(cin >> age))
        {
            cin.clear();
            cin.ignore();
            cout << "you typed a non number , try again please " << endl;
            setData();
        }
    }
    void setPswd()
    {
        string tmpPasswd;
        cout << "Enter password" << endl;
        cin >> tmpPasswd;
        cout << "Enter it again just to make sure" << endl;
        cin >> mdp;
        if (mdp != tmpPasswd)
        {
            cout << "oops you typed it wrong, try again" << endl;
            setPswd();
        }
    }
};

vector<Client> setClient(vector<Client> tab)
{
    Client tmp;
    tmp.setData();
    tmp.setPswd();
    // add client to arrayList
    tab.push_back(tmp);
    return tab;
}
void login(vector<Client> tabClient)
{
    string tempNom;
    cout << "Entrez votre nom" << endl;
    cin >> tempNom;
    // la fonction find se situe dans le include algorithm
    for (Client a : tabClient)
    {
        if (a.getNom() == tempNom)
        {
            cout << "trouvé" << endl
                 << "veuillez entrez votre mdp" << endl;
            string tmpMdp;
            cin >> tmpMdp;
            if (tmpMdp == a.getpswd())
            {
                cout << "Bienvenue" << endl;
                exit(EXIT_SUCCESS);
            }
            cout << "Mauvais mot de passe ... " << endl
                 << "Retour à l'accueil" << endl;
        }
    }
}
void menu(vector<Client> tabClient)
{
    cout
        << "Appuyez sur 1 pour vous inscrire 2 pour vous connectez, et 3 pour quittez" << endl;
    int choix;
    cin >> choix;
    switch (choix)
    {
    case 1:
        tabClient = setClient(tabClient);
        break;

    case 2:
        login(tabClient);
        break;
    case 3:
        cout << "Au revoir !" << endl;
        exit(EXIT_SUCCESS);

    default:
        cout << "trompé" << endl;
        exit(EXIT_FAILURE);
        break;
    }
    menu(tabClient);
}
int main()
{
    vector<Client> tabClient;
    tabClient.push_back({10, "toto", "toto", "toto"});
    cout
        << "Bonjour souhaitez vous vous inscrire ou vous connectez ? " << endl;
    menu(tabClient);
}