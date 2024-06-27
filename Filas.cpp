#include <iostream>
#include <queue>

/*Código desenvolvido por Maria Eduarda Fodor e Pedro Xavier Oliveira.*/

using namespace std;

int main() {
    queue<int> senhasGeradas;
    queue<int> senhasAtendidas;
    int opcao = -1;
    int senhaAtual = 1;

    while (opcao != 0 || !senhasGeradas.empty()) {
        cout << "\nEscolha uma das três opções:\n";
        cout << "0. Sair\n";
        cout << "1. Gerar senha\n";
        cout << "2. Realizar atendimento\n";

        cout << "Senhas esperando atendimento: " << senhasGeradas.size() << endl;

        cin >> opcao;

        switch (opcao) {
            case 0:
                if (senhasGeradas.empty()) {
                    cout << "Não há senhas para atender. Encerre o programa ou gere uma nova senha.\n";
                } else {
                    cout << "Ainda há senhas esperando atendimento. Não é possível encerrar.\n";
                }
                break;
            case 1:
                senhasGeradas.push(senhaAtual);
                cout << "Senha gerada: " << senhaAtual << endl;
                senhaAtual++;
                break;
            case 2:
                if (!senhasGeradas.empty()) {
                    int senha = senhasGeradas.front();
                    senhasGeradas.pop();
                    senhasAtendidas.push(senha);
                    cout << "Senha atendida: " << senha << endl;
                } else {
                    cout << "Não há mais senhas para atender.\n";
                }
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }

    cout << "\nTotal de senhas atendidas: " << senhasAtendidas.size() << endl;

    return 0;
}