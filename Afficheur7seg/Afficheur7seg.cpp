#include <iostream> 
#include <bitset> 

using namespace std;


void affiche7seg() 
{
	cout << "     a\n";
	cout << "     __\n";
	cout << " f |    | b\n";  
	cout << "   | d  |\n";
	cout << "     __\n";
	cout << " g |    | c\n";
	cout << "   |    |\n";
	cout << "     __\n";
	cout << "     e   \n";
}


void affichage_horizontal(int taille) {
	cout << "    ";
	for (int i = 0; i < taille - 1; i++) {
		cout << "_";
	}
	cout << "_\n";
}

void affichage_vertical(int taille,int v1,int v2) {
	if (v1 == 1 && v2 == 1) {
		for (int i = 0; i < taille; i++) {
			cout << "   |    |  \n";
		}
	}
	else if (v1 == 1 && v2 == 0) {
		for (int i = 0; i < taille; i++) {
			cout << "   |       \n";
		}
	}
	else if (v1 == 0 && v2 == 1) {
		for (int i = 0; i < taille; i++) {
			cout << "        |  \n";
		}
	}
	else if (v1 == 0 && v2 == 0) {
		for (int i = 0; i < taille; i++) {
			cout << "           \n";
		}
	}
}






void affichage7seg_dyna(int taille, bitset<7> nombre) {

	if (nombre[0] == 1) {
		affichage_horizontal(taille);
	}

	affichage_vertical(taille, nombre[5], nombre[1]);

	if (nombre[3] == 1) {
		affichage_horizontal(taille);
	}

	affichage_vertical(taille, nombre[6], nombre[2]);

	if (nombre[4] == 1) {
		affichage_horizontal(taille);
	}

}




bitset<7> convert_dec_bin2(int decimal)
{
	bitset<7> bin;
	for (int i = 0; i < 7; i++)
	{	
		bin[i] = decimal % 2;
		decimal = decimal / 2;
	}
	return bin;
}



void affichage_broches(bitset<7> value) {
	cout << "broches allumes : ";
	for (int i = 0; i < 7; i++)
	{

		if (value[i] == true) {
			int nom_broche = 'a';
			nom_broche += i;
			cout << char(nom_broche) << " ";
		}

	}
	cout << endl;
}


int main()
{
	
	int binary,value,taille_broche;
	bitset<7> matrice;
	
	cout << "saisir entier (0-9)" << endl;
	cin >> value;
	cout << "saisir taille" << endl;
	cin >> taille_broche;


	if (value == 0) {
		binary = 119;
	}else if (value == 1) {
		binary = 6;
	}
	else if (value == 2) { 
		binary = 91;
	}
	else if (value == 3) {
		binary = 31;
	}
	else if (value == 4) {
		binary = 46;
	}
	
	if (value == 5) {
		binary = 61;
	}
	else if (value == 6) {
		binary = 125;
	}
	else if (value == 7) {
		binary = 7;
	}
	else if (value == 8) {
		binary = 127;
		
	}
	else if (value == 9) {
		binary = 63;
		
	}
	else if (value > 9 || value<0) {
		cout << "La valeur saisie n'appartiens pas a [0-9]" << endl;
		exit (1);
	}

	
	matrice= convert_dec_bin2(binary);
	affichage_broches(matrice);
	affiche7seg();
	affichage7seg_dyna(taille_broche,matrice);

	exit(0);
}


