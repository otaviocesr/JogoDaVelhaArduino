int velha = 1;
int linha;
int coluna;
bool HaVencedor = false;
int matriz[3][3] = {
{ 1 , 2 , 3 },
{ 1 , 2 , 3 },
{ 1 , 2 , 3 }
};
char jogador1 = Serial.println("Jogador 1");
char jogador2 = Serial.println("Jogador 2");
char jogada;
int JogadorDaVez = 1;
int linha;
int coluna;
for (int linha = 0; linha < 3; linha++) {
    for (coluna = 0; coluna < 3; coluna++)
}

while(!HaVencedor && velha <= 9) {
Serial.println(matriz[3][3]);
Serial.println("Digite a posição da sua peça " & JogadorDaVez);

Serial.available() > 0;
Serial.read();
jogada = Serial.read;

if (validaPosicao(jogada) = false) {
    Serial.println("Jogada Inválida!!!")
} else {
    (linha = ToInteger(Char(jogada,0))) 
    (coluna = ToInteger(Char(jogada,2)))
    Serial.println("Linha: " & linha & "Coluna: " & coluna)
}

if (matriz[linha][coluna] != 0) {
    Serial.println("Posição ocupada, jogue novamente!!!")
} else {
    matriz[linha][coluna] = JogadorDaVez
}
}
