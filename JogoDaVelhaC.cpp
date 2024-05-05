#define SEPARADOR "---------"
//Declara uma matriz 3x3
int matriz[3][3] = {
{ 0 , 0 , 0 },
{ 0 , 0 , 0 },
{ 0 , 0 , 0 }
};
int velha = 1;
int linha;
int coluna;
bool HaVencedor = false;
String jogada;
int JogadorDaVez = 1;
int mensagem; 

void ZerarTabuleiro(){
    for (linha = 0; linha < 3; linha++){
    for (coluna = 0; coluna < 3; coluna++){
      matriz[linha][coluna] = 0;
    }
  }
}

void ChamarJogadorETabuleiro(){
        Serial.print("Escolha sua casa jogador ");
        Serial.println(JogadorDaVez);
        Serial.println("");
        for (linha = 0; linha < 3; linha++){
            for (coluna = 0; coluna < 3; coluna++){
               Serial.print(matriz[linha][coluna]);
               if (coluna < 2){
                  Serial.print(" | ");
                  }
               }
            Serial.println("");
            if (linha < 2){
              Serial.println(SEPARADOR);
              }
       }
   Serial.println("");
}
  
void setup(){
Serial.begin(9600);
  
ZerarTabuleiro();
  
ChamarJogadorETabuleiro();
}

void loop(){
  
HaVencedor = false;

velha = 1;
 
do {
    if (Serial.available() > 0) {
    jogada = Serial.readString();
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
  
  if (matriz[linha][coluna] == 0) {
      matriz[linha][coluna] = JogadorDaVez;

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
    
velha = velha + 1;

    
  } else {
    Serial.print("Jogada Invalida!, Jogue novamente jogador ");
    Serial.println(JogadorDaVez);
        }
    ChamarJogadorETabuleiro();
    }
} while (!HaVencedor && velha <= 9);
          if (velha >= 9){
        mensagem = 2;
    }
  
     switch (mensagem){
        case 1:
        Serial.print("Voce ganhou jogador ");
        Serial.println(JogadorDaVez);
        Serial.println();
        Serial.println("Novo Jogo!");
        Serial.println();
        ZerarTabuleiro();
        ChamarJogadorETabuleiro();
        break;

        case 2:
        Serial.println("DEU VELHA!");
        Serial.println();
        Serial.println("Novo Jogo!");
        Serial.println();
        ZerarTabuleiro();
        ChamarJogadorETabuleiro();
        break;
    }
}