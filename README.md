<h1 align="center">Gerenciador De Pratas Para minhas ilhas</h1>

Este repositório contém uma implementação em C de um Tipo Abstrato de Dados (TAD) para gerenciar o fluxo de caixa, investimentos e reservas de prata (Silver) para a administração de ilhas no jogo Albion Online.

---

## Sumário 
1. [Português](#1-português)
2. [English](#2-english)
3. [中文 (Chinese)](#3-中文-chinese)
4. [עברית (Hebrew)](#4-עברית-hebrew)

---

## 1. Português

⚠️ **Nota de Desenvolvimento:** Este projeto está em fase de criação contínua até alcançar todos os objetivos planejados.

### Descrição
Este projeto simula um sistema de fluxo de caixa para jogadores ou guildas de Albion Online que investem pesadamente em ilhas. Ele permite registrar o montante inicial investido, acompanhar a recuperação do capital à medida que as ilhas geram retorno econômico, e criar reservas financeiras dedicadas à expansão (compra de novas ilhas).

### Funcionalidades
* **Criar Gerenciador**: Inicializa a estrutura de dados com o valor investido nas ilhas.
* **Recuperar Prata**: Reduz o valor pendente de recuperação e adiciona a prata ao saldo livre atual.
* **Reservar Prata**: Move fundos do saldo livre para uma conta dedicada à compra de uma nova ilha (apenas se houver saldo suficiente).
* **Exibir Relatório**: Apresenta de forma organizada os saldos atuais no console.

### Como Compilar e Executar
Para compilar e rodar o projeto, use um compilador C (como o `gcc`):

```bash
gcc -o gerenciador main.c
./gerenciador
```

``` bash
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
```



2. English
⚠️ Development Note: This project is under continuous creation and development until it reaches its target state.

Description
This project simulates a cash flow management system for Albion Online players or guilds who invest heavily in economic islands. It tracks the initial silver investment, monitors capital recovery as islands generate returns, and allows users to set aside secure reserves for future real estate expansion.

Features
Create Manager: Allocates memory and initializes the capital structure.

Recover Silver: Decreases the pending investment amount and transfers the funds into the free current balance.

Reserve Silver: Allocates funds from the free balance into a savings account dedicated to purchasing a new island (only if sufficient funds exist).

Display Report: Prints formatted financial data to the console terminal.

Compilation and Execution
To compile and run the project using gcc:

``` bash
gcc -o silver_manager main.c
./silver_manager
```

``` bash
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================================
// [ADT] STRUCTURE DEFINITION AND INTERFACE (Simulated Header)
// ============================================================================

typedef struct {
    double current_balance;
    double total_invested_islands;
    double new_island_reserve;
} SilverManager;

// ------------------------------------------------------------------------------------

SilverManager* create_manager(double initial_investment);
void recover_silver(SilverManager *manager, double value);
void reserve_silver_for_new_island(SilverManager *manager, double value);
void display_report(const SilverManager *manager);
void destroy_manager(SilverManager *manager);

// ------------------------------------------------------------------------------------

int main()
{
    SilverManager *my_cash = create_manager(29000000.0);

    // 1. Creates the manager with the initial 29M spent/invested
    // Represented in millions (29,000,000)
    printf("\n\n\t--- Starting Silver Administration for Islands in Albion Online ---\n\n");
    display_report(my_cash);

    // 2. Recovering a partial amount (e.g., target of 6,500,000)
    printf("\n>>> Recovering partial 6.5M silver...\n");
    recover_silver(my_cash, 6500000.0);
    display_report(my_cash);

    // Simulation: Recovering the remainder to clear investment and unlock cash flow
    printf("\n>>> Recovering the remaining amount of the 29M invested...\n");
    recover_silver(my_cash, 22500000.0);

    // 3. Reserve 26M for purchasing the new island
    printf("\n>>> Reserving 26M for the new island...\n");
    reserve_silver_for_new_island(my_cash, 26000000.0);

    destroy_manager(my_cash);

    return 0;
}

// ============================================================================
// ADT IMPLEMENTATION METHODS
// ============================================================================

SilverManager* create_manager(double initial_investment) {
    SilverManager *manager = malloc(sizeof(SilverManager));

    if (manager) {
        manager->current_balance = 0.0;
        manager->total_invested_islands = initial_investment;
        manager->new_island_reserve = 0.0;
    }
    return manager;
}

void recover_silver(SilverManager *manager, double value) {
    if (manager == NULL) return;

    manager->current_balance += value;
    manager->total_invested_islands -= value;

    if (manager->total_invested_islands < 0) {
        manager->total_invested_islands = 0; // Prevents negative numbers
    }
}

void reserve_silver_for_new_island(SilverManager *manager, double value) {
    if (manager == NULL) return;

    if (manager->current_balance >= value) {
        manager->current_balance -= value;
        manager->new_island_reserve += value;
        printf("\n------------------- SUCCESS -------------------\n");
        printf("Value of %.2f reserved for a new island.\n", value);
        printf("-----------------------------------------------\n");
    }
    else {
        printf("\n------------------- Error -------------------\n");
        printf("Insufficient balance (%.2f) to reserve %.2f.\n", manager->current_balance, value);
        printf("--------------------------------------------\n");
    }
}

void display_report(const SilverManager *manager) {
    if (manager == NULL) return;
    
    printf("=========================================\n");
    printf(" SILVER VALUES:\n");
    printf("-----------------------------------------\n");
    printf(" Current Free Balance    : %.2f\n", manager->current_balance);
    printf(" Pending Recovery        : %.2f\n", manager->total_invested_islands);
    printf(" Reserved for New Island : %.2f\n", manager->new_island_reserve);
    printf("=========================================\n");
}

void destroy_manager(SilverManager *manager) {
    if (manager) {
        free(manager);
        printf("\n\nSystem Closed and memory freed.\n\n");
    }
}
```



3. 中文 (Chinese)
⚠️ 开发状态提示： 该项目目前正处于持续开发与构建阶段，直至完全达到预期的最终功能目标。

项目简介
本项目是一个用C语言编写的抽象数据类型（ADT）模拟系统，专门用于管理《阿尔比恩Online》（Albion Online）玩家或公会在经济岛屿上的白银（Silver）现金流。该系统允许玩家记录初始岛屿投资，跟踪岛屿产生收益时的资金回笼情况，并设立专用准备金以备购买新岛屿扩张。

主要功能
创建管理器：分配内存并初始化岛屿投资管理数据结构。

白银回收：减少待回收的投资额度，并将回收的白银充值到当前自由流动资金。

新岛白银准备金：在余额充足的情况下，从自由资金中划拨特定额度到新岛专用存储账户。

显示财务报告：在控制台终端格式化输出详细的白银资产状况。

编译与运行
使用 C 语言编译器（如 gcc）进行编译和运行：

``` bash
gcc -o silver_manager main.c
./silver_manager
```
英文代码展示




4. עברית (Hebrew)
⚠️ הערת פיתוח: פרויקט זה נמצא בשלב של יצירה ופיתוח מתמשכים עד שיגיע למצב הסופי המבוקש.

תיאור הפרויקט
פרויקט זה מדמה מערכת לניהול תזרים מזומנים בשפת C, הממומשת באמצעות טיפוס נתונים מופשט (ADT). המערכת מיועדת לשחקנים או גילדות במשחק Albion Online המשקיעים כספים רבים באיים כלכליים. היא מאפשרת לעקוב אחר ההשקעה הראשונית של הכסף (Silver), לנטר את החזר ההשקעה ככל שהאיים מייצרים רווחים, ולשמור רזרבות כספיות מאובטחות לרכישת איים חדשים בעתיד.

תכונות עיקריות
יצירת מנהל (Create Manager): הקצאת זיכרון ואתחול מבנה הנתונים של ההשקעות.

החזרת כסף (Recover Silver): הפחתת סכום ההשקעה הממתין להחזר והעברת הכסף ליתרה הפנויה הנוכחית.

שמירת רזרבה לאי חדש (Reserve Silver): העברת כספים מהיתרה הפנויה לחשבון חיסכון ייעודי לרכישת אי חדש (רק במידה וקיים סכום מספק).

הצגת דוח (Display Report): הדפסת נתונים פיננסיים מעוצבים ומאורגנים ישירות למסך.

קומפילציה והרצה
כדי לקמפל ולהריץ את הפרויקט, השתמש במהדר C (לדוגמה gcc):

``` bash
gcc -o silver_manager main.c
./silver_manager
```

קוד מקור באנגלית 
