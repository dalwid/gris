#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// ============================================================================
// [TAD] DEFINIÇÃO DA ESTRUTURA E INTERFACE (Meu cabeçalho simulado)
// ============================================================================

typedef struct{
    double saldo_atual;
    double total_investido_ilhas;
    double reserva_nova_ilha;
}GerenciadorPrata;

// ------------------------------------------------------------------------------------

GerenciadorPrata* criar_gerenciador(double investimento_inicial);
void recuperar_prata(GerenciadorPrata *gerenciador, double investimento_inical);
void reservar_prata_para_nova_ilha(GerenciadorPrata *gerenciador, double valor);
void exibir_relatorio(const GerenciadorPrata *gerenciador);
void destruir_gerenciador(GerenciadorPrata *gerenciador);

// ------------------------------------------------------------------------------------

int main()
{
    GerenciadorPrata *meu_caixa = criar_gerenciador(29000000.0);

    // 1. Cria o gerenciador com os 29M iniciais que foram gastos/investidos
    // Representado em milhões (29.000.000)
    printf("\n\n\t--- Iniciando Administração de Prata para Ilhas no Albion Online ---\n\n");
    exibir_relatorio(meu_caixa);

    // 2. Recuperando uma parte (ex: a meta de 6.500.000)
    printf("\n>>> Recuperando parcial de 6.5M de prata...\n");
    recuperar_prata(meu_caixa, 6500000.0);
    exibir_relatorio(meu_caixa);

    // Simulação: Recuperando o restante para zerar o investimento e ter caixa livre
    printf("\n>>> Recuperando o restante dos 29M investidos...\n");
    recuperar_prata(meu_caixa, 22500000.0);

    // 3. Reservar 26M para a compra da nova ilha
    printf("\n>>> Reservando 26M para a nova ilha...\n");
    reservar_prata_para_nova_ilha(meu_caixa, 26000000.0);

    destruir_gerenciador(meu_caixa);

    return 0;
}

// ============================================================================
// IMPLEMENTAÇÃO DOS MÉTODOS DO TAD
// ============================================================================

GerenciadorPrata* criar_gerenciador(double investimento_inicial){
    GerenciadorPrata *gerenciador = malloc(sizeof(GerenciadorPrata));

    if(gerenciador){
        gerenciador->saldo_atual = 0.0;
        gerenciador->total_investido_ilhas = investimento_inicial;
        gerenciador->reserva_nova_ilha = 0.0;
    }
}

void recuperar_prata(GerenciadorPrata *gerenciador, double valor){
    if(gerenciador == NULL) return;

    gerenciador->saldo_atual += valor;
    gerenciador->total_investido_ilhas -= valor;

    if(gerenciador->total_investido_ilhas < 0){
        gerenciador->total_investido_ilhas = 0; // Evita valores negativos
    }
}

void reservar_prata_para_nova_ilha(GerenciadorPrata *gerenciador, double valor){
    if(gerenciador == NULL) return;

    if(gerenciador->saldo_atual >= valor){
        gerenciador->saldo_atual -= valor;
        gerenciador->reserva_nova_ilha += valor;
        printf("\n------------------- SUCESSO -------------------\n");
        printf("Valor de %.2f reservado para nova ilha.\n", valor);
        printf("-----------------------------------------------\n");
    }
    else{
        printf("\n------------------- Erro -------------------\n");
        printf("Saldo insuficiente (%.2f) para reservar %.2f.\n", gerenciador->saldo_atual, valor);
        printf("--------------------------------------------\n");
    }
}

void exibir_relatorio(const GerenciadorPrata *gerenciador) {
    if (gerenciador == NULL) return;
    
    printf("=========================================\n");
    printf(" VALORES EM PRATA (SILVER):\n");
    printf("-----------------------------------------\n");
    printf(" Saldo Livre Atual       : %.2f\n", gerenciador->saldo_atual);
    printf(" Pendente p/ Recuperar   : %.2f\n", gerenciador->total_investido_ilhas);
    printf(" Reservado p/ Nova Ilha  : %.2f\n", gerenciador->reserva_nova_ilha);
    printf("=========================================\n");
}

void destruir_gerenciador(GerenciadorPrata *gerenciador){
    if(gerenciador){}
        free(gerenciador);
        printf("\n\nSistema Encerrado e memoria liberado.\n\n");
}