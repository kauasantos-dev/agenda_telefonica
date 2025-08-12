#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool validacao_nome(string nome)
{
   for(int i = 0; i < nome.length(); i++)
   {
      char letra = nome[i];

      if(!isalpha(letra))
      {
         return false;
      }
   }
   return true;
}

bool validacao_numero(string numero)
{
   for(int i = 0; i < numero.length(); i++)
   {
      char numero2 = numero[i];

      if(!isdigit(numero2))
      {
         return false;
      }
   }
   return true;
}

void adicionar(string nome, int numero)
   {
      ofstream arquivo;
      arquivo.open("agenda.txt", ios::app);
      if(arquivo.is_open())
      {
         arquivo << nome << " - " << numero << "\n";
      }
      else{
         cerr << "Erro ao abrir o arquivo.\n";
      }
      arquivo.close();
   }

int main()
{
   
}