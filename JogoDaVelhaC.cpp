// Define SEPARADOR como 9 traços
#define SEPARADOR "---------"
// Define TEMPO como 2000
#define TEMPO 2000
//Declara uma matriz inteira 3x3, que simula um tabuleiro
int matriz[3][3] = {
{ 0 , 0 , 0 },
{ 0 , 0 , 0 },
{ 0 , 0 , 0 }
};
int contadordevelha = 0;
int contadordevitoria1 = 0;
int contadordevitoria2 = 0;
int Partida = 1;
// Declara e define a variável inteira velha como 1
int velha = 0;
// Define a variável linha como inteiro
int linha;
// Define a variável coluna como inteiro
int coluna;
// Declara e define a variável booleana HaVencedor como false
bool HaVencedor = false;
// Define jogada como uma string
String jogada;
// Declara e define a variável inteira JogadorDaVez como 1
int JogadorDaVez = 1;
// Define mensagem como um inteiro
int mensagem; 

// Cria uma função para zerar e imprimir o tabuleiro
void ZerarTabuleiro(){
    for (linha = 0; linha < 3; linha++){
    for (coluna = 0; coluna < 3; coluna++){
      matriz[linha][coluna] = 0;
    }
  }
}

// Cria uma função para chamar o jogador e imprimir o tabuleiro na serial
void ChamarJogadorETabuleiro(){
        Serial.println();
        Serial.print("Escolha a casa da sua jogada, jogador ");
        Serial.println(JogadorDaVez);
        Serial.println("");
        for (linha = 0; linha < 3; linha++){
            for (coluna = 0; coluna < 3; coluna++){
               Serial.print(matriz[linha][coluna]);
               if (coluna < 2){
                  Serial.print(" | ");
                  }
               }
            Serial.println();
            if (linha < 2){
              Serial.println(SEPARADOR);
              }
       }
   Serial.println();
}
  
void setup(){
Serial.begin(115200);

// Chama a função ZerarTabuleiro
ZerarTabuleiro();
  
// Chama a função ChamarJogadorETabuleiro
ChamarJogadorETabuleiro();
  
  Serial.print("Partida: ");
  Serial.println(Partida);
}

void loop(){
  
// "Zera" a variável HaVencedor
HaVencedor = false;

// "Zera" a variável velha
velha = 0;
 
// Comando do...while verifica se há ganhador ou a jogada é inválida
do {
// Vê se tem bytes disponíveis e transforma a string em inteiro
    if (Serial.available() > 0) {
    jogada = Serial.readString();
        if (jogada.length() > 3){
          Serial.print("Jogada invalida, Jogue novamente jogador ");
          Serial.println(JogadorDaVez);
            }else if (jogada.length() < 3){
              Serial.print("Jogada invalida, Jogue novamente jogador ");
              Serial.println(JogadorDaVez); 
                }else{
// Verifica se tem caracteres indesejados inserido pelo jogador
                   if((jogada.indexOf("-") != -1) || (jogada.indexOf("+") != -1) || (jogada.indexOf(",") != -1) || (jogada.indexOf("!") != -1) ||
                      (jogada.indexOf("@") != -1) || (jogada.indexOf("#") != -1) || (jogada.indexOf("$") != -1) || (jogada.indexOf("%") != -1) || 
                      (jogada.indexOf("&") != -1) || (jogada.indexOf("*") != -1) || (jogada.indexOf("(") != -1) || (jogada.indexOf("§") != -1) ||
                      (jogada.indexOf(")") != -1) || (jogada.indexOf("¢") != -1) || (jogada.indexOf("}") != -1) || (jogada.indexOf(";") != -1) ||  
                      (jogada.indexOf("=") != -1) || (jogada.indexOf("[") != -1) || (jogada.indexOf("]") != -1) || (jogada.indexOf("{") != -1) || 
                      (jogada.indexOf(":") != -1) || (jogada.indexOf(".") != -1) || (jogada.indexOf("<") != -1) || (jogada.indexOf(">") != -1) ||
                      (jogada.indexOf("`") != -1) || (jogada.indexOf("^") != -1) || (jogada.indexOf("~") != -1) || (jogada.indexOf("'") != -1) ||
                      (jogada.indexOf("a") != -1) || (jogada.indexOf("b") != -1) || (jogada.indexOf("c") != -1) || (jogada.indexOf("d") != -1) ||
                      (jogada.indexOf("e") != -1) || (jogada.indexOf("f") != -1) || (jogada.indexOf("g") != -1) || (jogada.indexOf("h") != -1) ||
                      (jogada.indexOf("i") != -1) || (jogada.indexOf("j") != -1) || (jogada.indexOf("k") != -1) || (jogada.indexOf("l") != -1) ||
                      (jogada.indexOf("m") != -1) || (jogada.indexOf("n") != -1) || (jogada.indexOf("o") != -1) || (jogada.indexOf("p") != -1) ||
                      (jogada.indexOf("q") != -1) || (jogada.indexOf("r") != -1) || (jogada.indexOf("s") != -1) || (jogada.indexOf("t") != -1) ||
                      (jogada.indexOf("u") != -1) || (jogada.indexOf("v") != -1) || (jogada.indexOf("w") != -1) || (jogada.indexOf("x") != -1) ||
                      (jogada.indexOf("y") != -1) || (jogada.indexOf("z") != -1) || (jogada.indexOf("3") != -1) || (jogada.indexOf("4") != -1) || 
                      (jogada.indexOf("5") != -1) || (jogada.indexOf("6") != -1) || (jogada.indexOf("7") != -1) || (jogada.indexOf("8") != -1) || 
                      (jogada.indexOf("9") != -1) || (jogada.indexOf("/") != -1)) {
                          Serial.println();
                          Serial.print("Jogada invalida, jogue novamente jogador ");
                          Serial.println(JogadorDaVez);
                          Serial.println();
                          }else{
    linha = jogada.substring(0,1).toInt();
    coluna = jogada.substring(2,3).toInt();
      
    Serial.println();
    Serial.println(SEPARADOR);
    Serial.print("Linha: ");
    Serial.println(linha);
    Serial.print("Coluna: ");
    Serial.println(coluna);
    Serial.println(SEPARADOR);
    Serial.println();

// Verifica se a posição feita pelo jogador é válida
  if (matriz[linha][coluna] == 0) {
// Troca o número do jogador na matriz
    matriz[linha][coluna] = JogadorDaVez;

// Executa o comando de verificação de vencedores na matriz, em linhas, colunas e diagonais, respectivamente
    if ((matriz[0][0] ==JogadorDaVez && matriz[0][1] ==JogadorDaVez && matriz[0][2] ==JogadorDaVez) || 
        (matriz[1][0] ==JogadorDaVez && matriz[1][1] ==JogadorDaVez && matriz[1][2] ==JogadorDaVez) ||
         matriz[2][0] ==JogadorDaVez && matriz[2][1] ==JogadorDaVez && matriz[2][2] ==JogadorDaVez){
            HaVencedor = true;
            mensagem = 1;  
          } else if ((matriz[0][0] ==JogadorDaVez && matriz[1][0] ==JogadorDaVez && matriz[2][0] ==JogadorDaVez) || 
                    (matriz[0][1] ==JogadorDaVez && matriz[1][1] ==JogadorDaVez && matriz[2][1] ==JogadorDaVez) ||
                     matriz[0][2] ==JogadorDaVez && matriz[1][2] ==JogadorDaVez && matriz[2][2] ==JogadorDaVez){
                        HaVencedor = true;
                        mensagem = 1;  
                      } else if ((matriz[0][0] ==JogadorDaVez && matriz[1][1] ==JogadorDaVez && matriz[2][2] ==JogadorDaVez) || 
                                 (matriz[0][2] ==JogadorDaVez && matriz[1][1] ==JogadorDaVez && matriz[2][0] ==JogadorDaVez)){
                                    HaVencedor = true;
                                    mensagem = 1;                           
                                  } else if (JogadorDaVez == 1){
                                    JogadorDaVez = 2;
                                  } else {
                                    JogadorDaVez = 1;
                        }

// Toda vez que o if for executado, o valor de velha acrescentará em 1
velha = velha + 1;

// Caso a condição verificação acima for falsa, executará o else
  } else {
    Serial.print("Jogada Invalida!, Jogue novamente jogador ");
    Serial.println(JogadorDaVez);
         }

// Chama a variável ChamarJogadorETabuleiro
    ChamarJogadorETabuleiro();
      }
    }
  }

} while (!HaVencedor && velha < 9); 
          if (velha > 9){
        mensagem = 2;
    }

// Se a condição "mensagem" for igual a um, executará o Case 1, caso seja igual a 2, executará os comandos do Case 2
     switch (mensagem){
        case 1:
        Serial.print("Parabens, Voce ganhou jogador ");
        Serial.println(JogadorDaVez);
        Serial.println();
       if (JogadorDaVez == 1){
         contadordevitoria1++;
         Serial.print("Quantidade de vitorias do jogador 1: ");
         Serial.println(contadordevitoria1);
         Serial.print("Quantidade de vitorias do jogador 2: ");
         Serial.println(contadordevitoria2);
       }else {
         contadordevitoria2++;
         Serial.print("Quantidade de vitorias do jogador 1: ");
         Serial.println(contadordevitoria1);
         Serial.print("Quantidade de vitorias do jogador 2: ");
         Serial.println(contadordevitoria2);
       }
        delay(TEMPO);
        Serial.print("Quantidade de empates: ");
        Serial.println(contadordevelha);
        Serial.println();
        Serial.println("Novo Jogo!");
        Serial.println();
        ZerarTabuleiro();
        JogadorDaVez = 1;
        ChamarJogadorETabuleiro();
        Partida = Partida + 1;
        Serial.print("Partida: ");
        Serial.println(Partida);
        break;

        case 2:
        Serial.println("DEU VELHA!");
        delay(TEMPO);
        Serial.println();
        Serial.println("Novo Jogo!");
        Serial.println();
        Serial.println(Partida);
        ZerarTabuleiro();
        JogadorDaVez = 1;
        ChamarJogadorETabuleiro();
        contadordevelha = contadordevelha + 1;
        Serial.print("Quantidade de empates: ");
        Serial.println(contadordevelha);
        Serial.print("Quantidade de vitorias do jogador 1: ");
        Serial.println(contadordevitoria1);
        Serial.print("Quantidade de vitorias do jogador 2: ");
        Serial.println(contadordevitoria2);
        Partida = Partida + 1;
        Serial.print("Partida: ");
        break;
    }
}