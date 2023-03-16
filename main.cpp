#include <iostream>
#include <string>

using namespace std;

int Taille(const string& str)
{
	return static_cast<int>(str.size());
}

string RetirerTous(const string& motDepart, const string& carac)
{
	string resultat{ motDepart };
	size_t position = resultat.find(carac);
	while (position != string::npos)
	{
		resultat.erase(position, carac.size());
		position = resultat.find(carac);
	}
	return resultat;
}

void RetirerLettre(const string & motDepart)
{
	char carac{ ' ' };
	cout << "Entrer une lettre: " << endl;
	cin >> carac;

	cout << motDepart << " sans " << carac << " : ";
	cout << RetirerTous(motDepart, string{ carac }) << endl;
}

void CodeAnsi(const string& motDepart)
{
	cout << motDepart << ": ";
	for (int i = { 0 }; i < Taille(motDepart); i++)
	{
		int ansi{ motDepart[i] };
		cout << ansi << " ";
	}
	cout << endl;
}

string InverserChaine(const string& motDepart)
{
	string chaineInverser{ " " };
	for (int i{ Taille(motDepart) - 1}; i >= 0; i--)
	{
		chaineInverser += motDepart[i];
	}
	return chaineInverser;
}

void ResultatInverserChaine(const string& motDepart)
{
	string chaine{ InverserChaine(motDepart) };
	cout << motDepart << ": " << chaine << endl;
}

bool EstPalindromme(const string& motDepart) 
{
	int longueur = Taille(motDepart);
	for (int i = 0; i < longueur / 2; ++i) 
	{
		if (motDepart[i] != motDepart[longueur - 1 - i]) 
		{
			return false;
		}
	}
	return true;
}

void ResultatEstPalindromme(const string& motDepart)
{
	if (EstPalindromme(motDepart))
	{
		cout << motDepart << " est un palindromme" << endl;
	}
	else
	{
		cout << motDepart << " n'est pas un palindromme" << endl;
	}
}

string EnMinuscule(const string& motUtilisateur)
{
	string mot{ "" };
	for (int i{ 0 }; i < Taille(motUtilisateur); i++)
	{
		if (motUtilisateur[i] >= 'A' && motUtilisateur[i] <= 'Z')
		{
			mot += motUtilisateur[i] + 32;
		}
		else
		{
			mot += motUtilisateur[i];
		}
	}
	return mot;
}

string ObtenirEntree()
{
	string motUtilisateur{ " " };
	cout << "Entrer un mot: ";
	cin >> motUtilisateur;
	return EnMinuscule(motUtilisateur);
}

int Menu(const string& motDepart)
{
	int choix{ 0 };
	cout << "Choisir l'opération à appliquer sur \"" << motDepart << "\": " << endl;
	cout << "1. Inverser la chaîne" << endl;
	cout << "2. Codes ANSI des caractères de la chaîne" << endl;
	cout << "3. Vérification de palindrome" << endl;
	cout << "4. Retirer une lettre du mot" << endl;
	cout << "5. Quitter" << endl;
	cin >> choix;
	return choix;
}

void Operations(int choixMenu, const string& motDepart)
{
	switch (choixMenu)
	{
	case 1:
		ResultatInverserChaine(motDepart);
		break;
	case 2:
		CodeAnsi(motDepart);
		break;
	case 3:
		ResultatEstPalindromme(motDepart);
		break;
	case 4:
		RetirerLettre(motDepart);
		break;
	default:
		exit(0);
	}
}

int main()
{
	setlocale(LC_ALL, "");

	const string motDepart{ ObtenirEntree() };
	int choixMenu{ Menu(motDepart) };

	while (choixMenu != 5)
	{
		Operations(choixMenu, motDepart);
		choixMenu = Menu(motDepart);
	}
	return 0;
}