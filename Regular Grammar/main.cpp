#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct productie
{
    char si;
    string sf;
};

void cautare_cuvinte(int numar_litere_ramase, char neterminal, int pozitie_neterminal, string cuvant, vector <productie> v)
{
    if(numar_litere_ramase >= 0)
    {

    for(int i = 0; i < v.size(); i++)
    {
        if(neterminal == v[i].si)
        {
            if(numar_litere_ramase == 0 && v[i].sf == "lambda")
            {
                cout << cuvant << " ";
            }
            else
            {

                        ///am verificat daca exista vreun neterminal in v.sf
                        int ok = 1;
                        for(int j = 0; j < v[i].sf.length(); j++)
                        {
                            if(v[i].sf[j] >= 'A' && v[i].sf[j] <= 'Z')
                            {
                                ok = 0;
                            }
                        }

                        ///daca nu exista, afisam cuvantul, daca se poate
                        if(ok)
                        {

                            if(v[i].sf.length() == numar_litere_ramase)
                            {

                                for(int j = 0; j < pozitie_neterminal; j++)
                                {
                                cout << cuvant[j];
                                }
                                cout << v[i].sf;
                                for(int j = pozitie_neterminal; j < cuvant.length(); j++)
                                {
                                    cout << cuvant[j];
                                }
                                cout << " ";
                            }
                        }
                        else
                        {

                            for(int j = 0; j < v[i].sf.length(); j++)
                            {
                                if(v[i].sf[j] >= 'A' && v[i].sf[j] <= 'Z')
                                {

                                    cautare_cuvinte(numar_litere_ramase - v[i].sf.length() + 1, v[i].sf[j], j, cuvant + v[i].sf.substr(0, j) + v[i].sf.substr(j+1), v);
                                }
                            }
                        }

            }
        }
    }
    }
}

int main()
{

    int numar_de_productii;
    int numar_de_litere;

    ifstream fin("date.in");

    ///citirea numarului de productii si de productii
    fin >> numar_de_productii;

    ///am folosit un vector ce contine date de tip struct in care am stocat fiecare productie
    vector <productie> productii(numar_de_productii);

    for(int i = 0; i < numar_de_productii; i++)
    {
        fin >> productii[i].si >> productii[i].sf;
    }

    ///citirea numarului de litere ale cuvintelor acceptate
    cout << "  --- Tema aleasa este tema cu numarul 4 ---\n\n";
    cout << "Lungimea cuvintelor care se doreste a fi generate: ";
    cin >> numar_de_litere;

    ///afisarea cuvintelor gasite
    cout << "\nLista cuvintelor de dimensiune " << numar_de_litere << " recunoscute de gramatica: ";
    cautare_cuvinte(numar_de_litere, 'S', 0, "", productii);
    cout << '\n';

    return 0;
}
