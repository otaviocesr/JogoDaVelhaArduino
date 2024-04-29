function main() {
    while (true) {
        principal2();
    }
}

function principal2() {
    // Criar tabuleiros e jogadores. Zerar as variáveis
    // 
    // 0: Posição Vazia
    // 1: Jogada na posição do Jogador1
    // 2: Jogada na posição do Jogador2
    var velha;
    var linha;
    var coluna;
    var haVencedor;

    haVencedor = 0;
    var tabuleiro = Array(9);

    // Limpar/Zerar o tabuleiro
    var index;

    for (index = 0; index <= 8; index++) {
        tabuleiro[index] = 0;
    }
    var jogada;

    // Iniciar o jogo, definir quem joga primeiro
    var jogadorDavez;

    jogadorDavez = 1;

    // Anotar/Registrar a jogada, do primeiro jogador
    velha = 1;
    do {
        console.log(tabuleiro[0].toString() + tabuleiro[1] + tabuleiro[2]);
        console.log(tabuleiro[3].toString() + tabuleiro[4] + tabuleiro[5]);
        console.log(tabuleiro[6].toString() + tabuleiro[7] + tabuleiro[8]);
        jogada = "";
        console.log("Digite a posição da sua peça jogador " + jogadorDavez);
        jogada = window.prompt('Enter a value for jogada');
        if (varrerJogada(jogada) == true) {

            // Simula a função Serial.parseInt do Arduino
            linha = parseInt(jogada.charAt(0));
            coluna = parseInt(jogada.charAt(2));

            // Verificar se a posição "jogada" é valida
            // Converter a jogada texto em dois inteiros linha e coluna
            if (tabuleiro[3 * linha + coluna] == 0) {
                tabuleiro[3 * linha + coluna] = jogadorDavez;
                haVencedor = verificacao(tabuleiro, jogadorDavez);
                if (jogadorDavez == 1) {
                    jogadorDavez = 2;
                } else {
                    jogadorDavez = 1;
                }

                // Verificar o tabuleiro, se houve ganhador ou empate, finalizar o jogo
                // Verificar a jogada vencedora nas linhas
                velha = velha + 1;
            } else {
                console.log("Erro. Posição já ocupada, digite novamente outra posição");

                // Informar ao Jogador 1 que a posição está preenchida, é inválida e ele precisa informar uma posição válida.
            }
        } else {
            console.log("JOGADA INVÁLIDA");
        }
    } while (haVencedor == 0 && velha <= 9);
    if (jogadorDavez == 1) {
        jogadorDavez = 2;
    } else {
        jogadorDavez = 1;
    }
    if (haVencedor == 1) {
        console.log("Parabéns, você ganhou jogador " + jogadorDavez);
    } else {
        console.log("Deu Velha!");
    }
}

function varrerJogada(entrada) {
    var entradaValida;

    entradaValida = false;
    console.log(entrada.length);
    if (entrada.length == 3) {
        if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
            if (entrada.charAt(2) == "0" || entrada.charAt(2) == "1" || entrada.charAt(2) == "2") {
                entradaValida = true;
            }
        }
    }
    
    return entradaValida;
}

function verificacao(tabuleiro, jogadorDaVez) {
    var vencedor;

    vencedor = 0;
    if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
        vencedor = 1;
    } else {

        // Verificar a jogada vencedora nas colunas
        if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
            vencedor = 1;
        } else {

            // Verificar a jogada vencedora nas dioganais
            if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
                vencedor = 1;
            }
        }
    }
    
    return vencedor;
}
