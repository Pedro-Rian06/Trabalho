#include <iostream>

int main( ) {
	char reserva[10][6] = {
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '}
	};
	int fileira = -1, acento = -1;
	char poltrona = ' ';
    char cond, Tipo_Pass,mudar_pol;
    printf("==================================================\n");
    printf("|              |reserva de passagem|             |\n");
    printf("==================================================\n");
    while(bool continuar_reserva = true){
         printf("Tipos de passagem\n[C]Comum\n[E]Executiva\nescolha um tipo de passagem: ");
         scanf(" %c",&Tipo_Pass);

         printf("\nDigite a fileira (1-10): ");
         if (scanf("%d", &fileira) != 1 || fileira < 1 || fileira > 10) {
            printf("Opção inválida. Por favor, digite um número entre 1 e 10.\n");
            while(getchar() != '\n');  //Limpaza
            continue;
        }

        printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
		scanf(" %c", &poltrona);
		
		switch(poltrona){
			case 'A':
			case 'a':
				acento = 0;
				break;
			case 'B':
			case 'b':
				acento = 1;
				break;
			case 'C':
			case 'c':
				acento = 2;
				break;
			case 'D':
			case 'd':
				acento = 3;
				break;
			case 'E':
			case 'e':
				acento = 4;
				break;
			case 'F':
			case 'f':
				acento = 5;
				break;
			default:
				printf("\nPoltrona invalida");
		}
		// Implementação da lógica de tipos de passagem
        if (Tipo_Pass == 'C' || Tipo_Pass == 'c') {  // Passagem Econômica
            if (acento == 5 || acento == 0) {
                printf("\nPoltronas A e F são exclusivas para passagem Executiva. Escolha outra poltrona.\n");
                continue;
            } else {
                printf("\nPassagem Econômica reservada na poltrona %c, fileira %d.\n", poltrona, fileira);
            }
        } else if (Tipo_Pass == 'E' || Tipo_Pass == 'e') {  // Passagem Executiva
            if (acento != 5 && acento != 0) {
                printf("\nPara Passagem Executiva, recomendamos as poltronas A ou F.Deseja mudar o local\n(S/N): ");
                scanf(" %c", &mudar_pol);
                if (mudar_pol == 's' || mudar_pol == 'S'){
                    
                    continue;
                    
                }
            } else {
                printf("\nPassagem Executiva reservada na poltrona %c, fileira %d.\n", poltrona, fileira);
            }
        } else {
            printf("\nTipo de passagem inválido.\n");
            continue;
        }
        
        //verificação de cadeiras
        if(reserva[fileira-1][acento] == 'x'){
            printf ("A cadeira já esta reservada, escolha outra");
        }
        else{
            reserva[fileira-1][acento] = 'x';
        }
        
        
         //imprimir as cadeiras
       	printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
		for (int x=0; x<10; x++){
			if (x!=9)	printf("\n\t0%d\t", x+1);
			else		printf("\n\t%d\t", x+1);	
			
			for (int y=0; y<6; y++){
				printf("[%c] ", reserva[x][y]);
				if (y==2){
					printf("\t");
				}
			}
		}
		printf("\n");
        
        
        printf("\nVocê deseja fazer outra reserva?\nDigite |S| ou |N|: ");
        scanf(" %c",&cond);
        if (cond == 's' || cond == 'S' ){
            
            continue;
        }
        else{
            break;
        }
        
    }
        //imprimir as cadeiras pós compra 
        reserva[fileira-1][acento] = 'x';
        printf("\t\t  |MAPA| |DE| |ASSENTOS|\t");
       	printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
		for (int x=0; x<10; x++){
			if (x!=9)	printf("\n\t0%d\t", x+1);
			else		printf("\n\t%d\t", x+1);	
			
			for (int y=0; y<6; y++){
				printf("[%c] ", reserva[x][y]);
				if (y==2){
					printf("\t");
				}
			}
		}
		printf("\n");
    printf("\nencerrando o sistema...\n");
    	
}
