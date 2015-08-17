/////
/////Siemka to taki kod dotyczacy ekonomii
/////wiem ze wyglada to jakby pisal to niedouczony siedmiolatek, ale dawno nie pisalem w c++
////
// AuAx v 0.0001 test1.cpp
//
#include "stdafx.h"
#include "cstdlib"
#include "iostream"
#include "ctime"
////sorry za zmienne po polsku
const int liczbaPostaci = 1000; //na razie tyle dalem
const int liczbaPrzedmiotowHandlarza = 400; //kod dotyczy transakcji z jednym handlarzem, na razie
int poziomPotrzeby[liczbaPostaci ]; //trzeba go potem wygenerowac
int pPodstawowe[10]; ///lista podstawowych potrzeb do przedmiotow, max 10 (tak dalem na razie)
int pNarzedziowe[10];//jak wyzej tylko do narzedzi
int pMaterialne[10];
int pUslugowe[10];
int rozmiarPotrzeb = sizeof(pPodstawowe) + sizeof(pNarzedziowe) + sizeof(pMaterialne) + sizeof(pUslugowe);
int hierarchia[40]; //przedmioty (albo grupy) w kolejnosci do kupowania, ale kodu na ta kolejnosc jeszcze nie ma
int portfel[liczbaPostaci]; //zasobnosc portfela, w jakiejs walucie, dla kazdej postaci (NPC i gracze) ma wartosc
int cenaPrzedmiotu[liczbaPrzedmiotowHandlarza]; //cena przedmiotu
int zaspokojeniePotrzeby[liczbaPrzedmiotowHandlarza]; //liczba punktów, dla każdego przedmiotu jak zaspokaja potrzebe i redukuje punkty potrzeby
//////////////////////////////////////////////////////////////////////////////////////////
//NIEUZYTECZNY KOD (na dole)
/////////////////////////////////////////////////////////////////////////////////////////
/*int ktoreMiejsce(int nrPrzedmiotu){
	int potrzebyHierarchia[5];
	int Kolejnosc = 0;
	while (Kolejnosc <  (1 / 2 * sizeof(pPodstawowe)))  {
		potrzebyHierarchia[Kolejnosc] = pPodstawowe[Kolejnosc];
		Kolejnosc++;
	}
	while (Kolejnosc <  (1 / 2 * sizeof(pPodstawowe) + 1 / 2 * sizeof(pNarzedziowe)))  {
		potrzebyHierarchia[Kolejnosc] = pNarzedziowe[Kolejnosc];
		Kolejnosc++;
	}
	while (Kolejnosc <  (1 / 2 * sizeof(pPodstawowe) + 1 / 2 * sizeof(pNarzedziowe) + 1 / 4 * sizeof(pMaterialne)))  {
		potrzebyHierarchia[Kolejnosc] = pMaterialne[Kolejnosc];
		Kolejnosc++;
	}
	while (Kolejnosc <  (1 / 2 * sizeof(pPodstawowe) + 1 / 2 * sizeof(pNarzedziowe) + 1 / 4 * sizeof(pMaterialne) + 1 / 4 * sizeof(pUslugowe)))  {
		potrzebyHierarchia[Kolejnosc] = pUslugowe[Kolejnosc];
		Kolejnosc++;
	}
	while (Kolejnosc <  (sizeof(pPodstawowe) + 1 / 2 * sizeof(pNarzedziowe) + 1 / 4 * sizeof(pMaterialne) + 1 / 4 * sizeof(pUslugowe)))  {
		potrzebyHierarchia[Kolejnosc] = pPodstawowe[Kolejnosc];
		Kolejnosc++;
	}
	while (Kolejnosc <  (sizeof(pPodstawowe) + sizeof(pNarzedziowe) + 1 / 4 * sizeof(pMaterialne) + 1 / 4 * sizeof(pUslugowe)))  {
		potrzebyHierarchia[Kolejnosc] = pNarzedziowe[Kolejnosc];
		Kolejnosc++;
	}
	while (Kolejnosc <  (sizeof(pPodstawowe) + sizeof(pNarzedziowe) + 1 / 2 * sizeof(pMaterialne) + 1 / 2 * sizeof(pUslugowe)))  {
		potrzebyHierarchia[Kolejnosc] = pMaterialne[Kolejnosc];
		Kolejnosc++;
	}
	while (Kolejnosc <  (sizeof(pPodstawowe) + sizeof(pNarzedziowe) + 1 / 2 * sizeof(pMaterialne) + sizeof(pUslugowe)))  {
		potrzebyHierarchia[Kolejnosc] = pUslugowe[Kolejnosc];
		Kolejnosc++;
	}
	while (Kolejnosc <  rozmiarPotrzeb)  {
		potrzebyHierarchia[Kolejnosc] = pMaterialne[Kolejnosc];
		Kolejnosc++;
	}
	return(potrzebyHierarchia[nrPrzedmiotu]);
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/ //^^^^^^^^^^^^^^^^TEN KOD NA RAZIE NIEUZYWANY I NIEPOTRZEBNY MUSZE PRZEMYSLEC I UZGONIC PARE RZECZY
///////////////////////////////////// KONIEC NIEUZYTECZNEGO KODU


int kupowaniePrzedmiotu(int nrKupowanegoPrzedmiotu, int nrKupujacejPostaci){
	portfel[nrKupujacejPostaci] -= cenaPrzedmiotu[nrKupowanegoPrzedmiotu];
	poziomPotrzeby[nrKupujacejPostaci] -= zaspokojeniePotrzeby[nrKupowanegoPrzedmiotu];
	return 0;
}

int Kupowanie(int nrPostaci){
	bool ifBuying = true;
	while (ifBuying){
		double randomNumber = rand() % 100;
		if (randomNumber < poziomPotrzeby[nrPostaci]){
			int nrPrzedmiotu = 1;
			kupowaniePrzedmiotu(nrPrzedmiotu, nrPostaci);
			nrPrzedmiotu++;
		}
		else {
		ifBuying = false;
		}
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{

	for (int i = 0; i < 40; i++){
		hierarchia[i] = ktoreMiejsce(i);
		Kupowanie(7);

	}
	return 0;
}
