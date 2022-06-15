#include <iostream>
using namespace std;

struct Especie
{
    string nome;
    string periodo;
    int tempoProd;
};

struct Fornecedor
{
    string nome;
    Especie produto;
    int telefone;
};

class Chacara
{
    public:
        Chacara(){
            totalEspecies=0;
            totalFornecedores=0;
        }
        void novaEspecie(string nome, string periodo, int tempoProd);
        void novoFornecedor(string nome, string produto, int telefone);
        void listaEspecies();
        void listaFornecedores();
        Fornecedor buscaForcenedor(string produto);
    private:
        int totalEspecies;
        int totalFornecedores;
        Especie especiesCadastradas[10];
        Fornecedor fornecedoresCadastrados[10];
};

int main(){
    Chacara chacara;
    bool saida = true;
    while(saida){
    cout << "O que deseja fazer?\n\n"
    << "1 - Cadastrar uma nova espécie\n"
    << "2 - Cadastrar um novo fornecedor\n"
    << "3 - Listar espécies\n"
    << "4 - Listar fornecedores\n"
    << "5 - Buscar fornecedores\n" 
    << "6 - Sair" << endl;

    int escolha;
    cin >> escolha;

    switch (escolha)
    {
    case 1:{
        string nome;
        string periodo;
        int tempoProd;
        cout << "Nome: "; cin >> nome;
        cout << "Período de plantio: "; cin >> periodo;
        cout << "Tempo de produção (meses): "; cin >> tempoProd;
        chacara.novaEspecie(nome, periodo, tempoProd);
        break;
    }
    case 3:{
        chacara.listaEspecies();
    }
    default:
        break;
    }
    }
}



void Chacara::novaEspecie(string nome, string periodo, int tempoProd){
 if(totalEspecies=10)
 {
    cout << "Máximo de espécies cadastradas\n";
    return;
 }
 Especie model;
 model.nome=nome;
 model.periodo=periodo;
 model.tempoProd=tempoProd;
 especiesCadastradas[totalEspecies]=model;
 totalEspecies+=1;
 cout << "Especie cadastrada";
}

void Chacara::listaEspecies(){
    for(int i=0; i<totalEspecies; i++){
        cout << "Espécie " << i+1 << endl
            << "Nome: " << especiesCadastradas[i].nome << endl
            << "Período de plantio: " << especiesCadastradas[i].periodo << endl
            << "Tempo de produção: " << especiesCadastradas[i].tempoProd << "meses" << endl;
    }
}