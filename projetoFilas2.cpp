#include <iostream>
#include <queue>
#include <unordered_map>

/*Código desenvolvido por Maria Eduarda Fodor.*/

using namespace std;

struct Guiche {
    int id;
    queue<int> senhasAtendidas;
};

int main() {
    queue<int> senhasGeradas;
    unordered_map<int, Guiche> guichesAbertos;
    int opcao = -1;
    int senhaAtual = 1;
    int proximoIdGuiche = 1;

    while (opcao != 0 || !senhasGeradas.empty()) {
        cout << "\nSelecione uma opção:\n";
        cout << "0. Sair\n";
        cout << "1. Gerar senha\n";
        cout << "2. Abrir guichê\n";
        cout << "3. Realizar atendimento\n";
        cout << "4. Listar senhas atendidas\n";

        cout << "Senhas aguardando atendimento: " << senhasGeradas.size() << endl;
        cout << "Guichês abertos: " << guichesAbertos.size() << endl;

        cin >> opcao;

        switch (opcao) {
            case 0:
                if (senhasGeradas.empty()) {
                    cout << "Não há mais senhas para atender. Encerrando o programa.\n";
                } else {
                    cout << "Ainda há senhas aguardando atendimento. Não é possível encerrar.\n";
                }
                break;
            case 1:
                senhasGeradas.push(senhaAtual);
                cout << "Senha gerada: " << senhaAtual << endl;
                senhaAtual++;
                break;
            case 2: {
                Guiche novoGuiche = {proximoIdGuiche++};
                guichesAbertos[novoGuiche.id] = novoGuiche;
                cout << "Guichê aberto com ID: " << novoGuiche.id << endl;
                break;
            }
            case 3: {
                if (senhasGeradas.empty()) {
                    cout << "Não há senhas para atender.\n";
                } else if (guichesAbertos.empty()) {
                    cout << "Não há guichês abertos para atendimento.\n";
                } else {
                    int idGuiche;
                    cout << "Digite o ID do guichê: ";
                    cin >> idGuiche;

                    if (guichesAbertos.find(idGuiche) != guichesAbertos.end()) {
                        int senha = senhasGeradas.front();
                        senhasGeradas.pop();
                        guichesAbertos[idGuiche].senhasAtendidas.push(senha);
                        cout << "Senha atendida pelo guichê " << idGuiche << ": " << senha << endl;
                    } else {
                        cout << "Guichê não encontrado.\n";
                    }
                }
                break;
            }
            case 4: {
                if (guichesAbertos.empty()) {
                    cout << "Não há guichês abertos para listar senhas atendidas.\n";
                } else {
                    int idGuiche;
                    cout << "Digite o ID do guichê: ";
                    cin >> idGuiche;

                    if (guichesAbertos.find(idGuiche) != guichesAbertos.end()) {
                        queue<int> senhas = guichesAbertos[idGuiche].senhasAtendidas; // Copiar a fila
                        if (senhas.empty()) {
                            cout << "Nenhuma senha atendida pelo guichê " << idGuiche << ".\n";
                        } else {
                            cout << "Senhas atendidas pelo guichê " << idGuiche << ":\n";
                            while (!senhas.empty()) {
                                cout << senhas.front() << " ";
                                senhas.pop();
                            }
                            cout << endl;
                        }
                    } else {
                        cout << "Guichê não encontrado.\n";
                    }
                }
                break;
            }
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }

    int totalSenhasAtendidas = 0;
    for (const auto &pair : guichesAbertos) {
        totalSenhasAtendidas += pair.second.senhasAtendidas.size();
    }

    cout << "\nTotal de senhas atendidas: " << totalSenhasAtendidas << endl;

    return 0;
}
