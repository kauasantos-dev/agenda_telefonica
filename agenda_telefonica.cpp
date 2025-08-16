#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool validacao_nome(string nome)
{
   for(size_t i = 0; i < nome.length(); i++)
   {
      char letra = nome[i];

      if(!isalpha(letra))
      {
         cout << "\nNome inválido. Por favor, digite somente letras.\n";
         return false;
      }
   }
   return true;
}

bool validacao_numero(string numero)
{
   for(size_t i = 0; i < numero.length(); i++)
   {
      char numero2 = numero[i];

      if(!isdigit(numero2))
      {
         cout << "\nNúmero de telefone inválido. Por favor, digite somente números.\n";
         return false;
      }
   }
   return true;
}

void adicionar(string nome, string numero)
   {
      ofstream arquivo;
      arquivo.open("agenda.txt", ios::app);
      if(arquivo.is_open())
      {
         arquivo << nome << " - " << numero << endl;
         cout << "\nContato adicionado com sucesso!\n";
      }

      else{
         cerr << "\nErro ao abrir o arquivo.\n";
      }
      
      arquivo.close();
   }

   void buscar_contato_nome(string nome)
   {
      ifstream arquivo;
      string linha;
      arquivo.open("agenda.txt");
      if(arquivo.is_open())
      {
        while(getline(arquivo, linha))
        {
          if(linha.find(nome) != string::npos)
          {
            cout << "\nContato encontrado:\n";
            cout << linha << endl;
            arquivo.close();
            return;
          }
        }
          cout << "\nContato não encontrado.\n";
          arquivo.close();
          return;
      }

      else{
        cerr << "\nErro ao abrir o arquivo.\n";
      }
   }

void buscar_contato_numero(string numero)
{
   ifstream arquivo;
   string linha;
   arquivo.open("agenda.txt");
   if(arquivo.is_open())
   {
     while(getline(arquivo, linha))
     {
       if(linha.find(numero) != string::npos)
       {
         cout << "\nContato encontrado:\n";
         cout << linha << endl;
         arquivo.close();
         return;
       }
     }
       cout << "\nContato não encontrado.\n";
       arquivo.close();
       return;
   }

   else{
     cerr << "\nErro ao abrir o arquivo.\n";
   }
}

void lista_contatos()
{
   ifstream arquivo;
   string linha;
   arquivo.open("agenda.txt");
   if(arquivo.is_open())
   {
      if(arquivo.peek() == ifstream::traits_type::eof()) // o peek() serve para verificar se o arquivo está vazio.
      {
         cout << "\nNão há contatos em sua lista.\n";
         arquivo.close();
         return;
      }

      cout << "\nSua lista de contatos:\n";
      while(getline(arquivo, linha))
      {
        cout << linha << endl;
      }
      arquivo.close();
   }

   else{
     cerr << "\nErro ao abrir o arquivo.\n";
   }
}

int main()
{
   while(true)
   {
   cout << "\n========== MENU ==========\n";
   cout << "\nEscolha uma opção abaixo\n";
   cout << "\n1- Adicionar contato\n2- Ver lista de contatos\n3- Buscar contato pelo nome\n4- Buscar contato pelo número\n5- Sair\n";
   
   int opcao;
   cin >> opcao;
   switch(opcao)
   {
      case 1:
      {
         string nome, numero;
         cout << "Informe o nome do contato: ";
         cin >> nome;
         bool validacao = validacao_nome(nome);
         if(validacao == false)
           break;
         
         else{
         cout << "Informe o número de telefone: ";
         cin >> numero;
         bool validacao2 = validacao_numero(numero);
         if(validacao2 == false)
           break;
         
           else{
            adicionar(nome, numero);
            break;
           }
       }
      }

      case 2:
      {
        lista_contatos();
        break;
      }

      case 3:
      {
         string nome;
         cout << "Informe o nome do contato: ";
         cin >> nome;
         bool validacao = validacao_nome(nome);
         if(validacao == false)
           break;
         
           else{
           buscar_contato_nome(nome);
           break;
           }
      }

      case 4:
      {
         string numero;
         cout << "Informe o número do contato: ";
         cin >> numero;
         bool validacao = validacao_numero(numero);
         if(validacao == false)
           break;
         
           else{
             buscar_contato_numero(numero);
             break;
           }
      }

      case 5:
      {
       cout << "Programa encerrado.\n";
       return 0;
      }

      default:
        cout << "Opção inválida. Por favor, selecione uma opção válida.\n";
        break;
   }
}
}