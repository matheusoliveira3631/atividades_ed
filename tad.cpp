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
    string produto;
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
        void buscaForcenedor(string produto);
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
        cout << "Tempo de produção: "; cin >> tempoProd;
        chacara.novaEspecie(nome, periodo, tempoProd);
        break;
    }
    case 2:{
        string nome;
        string produto;
        int telefone;
        cout << "Nome: "; cin >> nome;
        cout << "Produto de interesse: "; cin >> produto;
        cout << "Telefone (somente números): "; cin >> telefone;
        chacara.novoFornecedor(nome, produto, telefone);
        break;
    }
    case 3:{
        chacara.listaEspecies();
        break;
    }
    case 4:{
        chacara.listaFornecedores();
        break;
    }
    case 5:{
        string busca;
        cout << "Produto fornecido: "; cin >> busca;
        chacara.buscaForcenedor(busca);
        break;
    }
    case 6:
        saida = false;
        break;
    default:
        cout << "Opção inválida\n\n";
        break;
    }
    }
}



void Chacara::novaEspecie(string nome, string periodo, int tempoProd){
 if(totalEspecies>=10)
 {
    cout << "Máximo de espécies cadastradas\n";
    return;
 }
 especiesCadastradas[totalEspecies].nome=nome;
 especiesCadastradas[totalEspecies].periodo=periodo;
 especiesCadastradas[totalEspecies].tempoProd=tempoProd;
 totalEspecies+=1;
 cout << "Especie cadastrada";
}

void Chacara::novoFornecedor(string nome, string produto, int telefone){
 if(totalFornecedores>=10)
 {
    cout << "Máximo de fornecedores cadastrados\n";
    return;
 }
 fornecedoresCadastrados[totalFornecedores].nome=nome;
 fornecedoresCadastrados[totalFornecedores].produto=produto;
 fornecedoresCadastrados[totalFornecedores].telefone=telefone;
 totalFornecedores+=1;
 cout << "Fonrecedor cadastrado";
}

void Chacara::listaEspecies(){
    for(int i=0; i<totalEspecies; i++){
        cout << "Espécie " << i+1 << endl
            << "Nome: " << especiesCadastradas[i].nome << endl
            << "Período de plantio: " << especiesCadastradas[i].periodo << endl
            << "Tempo de produção: " << especiesCadastradas[i].tempoProd << " meses\n" << endl;
    }
}

void Chacara::listaFornecedores(){
    for(int i=0; i<totalFornecedores; i++){
        cout << "Fornecedor " << i+1 << endl
            << "Nome: " << fornecedoresCadastrados[i].nome << endl
            << "Produto de interesse: " << fornecedoresCadastrados[i].produto << endl
            << "telefone: " << fornecedoresCadastrados[i].telefone << endl;
    }
}

void Chacara::buscaForcenedor(string produto){
    cout << "Fornecedores encontrados: \n";
    for(int i=0; i<totalFornecedores; i++){
        if(fornecedoresCadastrados[i].produto==produto)
        {
            cout << fornecedoresCadastrados[i].nome << endl;
        }
    }
}