#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void WaitTime(int n)//fonction qui fait attendre n secondes
{
	time_t debut = time( NULL );//contient l'heure du début
	time_t actu;//contient l'heure actuelle
	unsigned long fin;//variable qui contient actu-debut : le temps passé
	do
	{
		actu = time( NULL);
		fin = (unsigned long) difftime( actu, debut );
	}while(fin < (unsigned long)n);
}


void Reponse(int *choix)//mettre en int.
{
	//int choix;
	scanf("%d", choix);
	//scanf("%*[^\n]")
	getchar ();//vide le buffer, evitant les bugs en cas de saisie invalide type caractere !
	//return choix;
}


void ResetChoix(int *choix)
{
	*choix = (-1);
}


void ResetMachine(int l, int h, char machine[l][h])
{
	for(int a=0; a<h; a++)
	{
		for(int b=0; b<l; b++)
		{
			
			if(a==0 || a==(h-1) || b == 0 || b == (l-1))
			{
				machine[b][a]='x';
			}
			else
			{
				machine[b][a]=' ';
			}
		}
	}
}


void AfficheCara(int l, int h, char Machine[l][h], int a, int b)
{
		if(a==0 && b==0)
		{
			printf("╔");
		}
		else if(a==0 && b==l-1)
		{
			printf("╗");
		}
		else if(a==h-1 && b==0)
		{
			printf("╚");
		}
		else if(a==h-1 && b==l-1)
		{
			printf("╝");
		}
		else if(a==0 || a==h-1)
		{
			printf("═══");
		}
		else if(b==0 || b== l-1)
		{
			printf("║");
		}
		else if (Machine[b][a]=='*')
		{
			printf("\033[34;01m███\033[00m");
		}
		else
		{
			printf(" %c ", Machine[b][a]);
		}
}


void AfficheMachine(int NbMachines,int l, int h ,char Machine1[l][h], char Machine2[l][h], char Machine3[l][h])
{
	int ltotal=NbMachines*l;

	for(int a=0; a<h; a++)
	{
		for(int b=0; b<ltotal; b++)
		{
			if(b<l)//machine 1
			{
				AfficheCara(l, h, Machine1, a, b);//envoie la taille et la position actuelle
			}
			if(b>=l && b<2*l)//machine 2
			{
				AfficheCara(l, h, Machine2, a, b-(l));//envoie la taille et la position actuelle
			}
			if(b>=2*l && b<3*l)//machine 3
			{
				AfficheCara(l, h, Machine3, a, b-(2*l));//envoie la taille et la position actuelle
			}
			
		}
		printf("\n");
	}
}


void AfficheNCara(int n, char cara)//affiche n fois le caractere
{
	for(int i=0; i<n; i++)
	{
		printf("%c", cara);
	}
}


void AfficheN205(int n)
{
	for(int i=0; i<n; i++)
	{
		printf("═");
	}
}


void AfficheMenu(int Argent, int l)
{
	//AfficheNCara(27*3, 32);//incruste 27 espaces pour la version grand écran.
	printf("MENU\n\n");
	//AfficheNCara(20*3, 32);//pour la version grand écran
	printf("1 - Jouer\n");
	//AfficheNCara(20*3, 32);
	printf("2 - Réapprovisionner en jeton (%d actuellement)\n", Argent);
	//AfficheNCara(20*3, 32);
	printf("3 - Récupérer la mise (%d actuellement) / Quitter\n\n\n", Argent);
}


void AfficheInfo(int Mise,int Argent, int Gains)
{
	int espacement=2;
	printf(" JETONS :");
	AfficheNCara(espacement+13, 32);//affiche (a, espace).
	printf(" Mise précédente:");
	AfficheNCara(espacement+5, 32);
	printf(" Gains :\n");

	for(int i=0;i<3; i++)
	{
		printf("╔");
		AfficheN205(20);//affiche 20 fois caractere de bars
		printf("╗");
		AfficheNCara(espacement, 32);
	}
	printf("\n║");
	printf("%20d", Argent);
	printf("║");
	AfficheNCara(espacement, 32);
	printf("║");
	printf("%20d", Mise);
	printf("║");
	AfficheNCara(espacement, 32);
	printf("║");
	printf("%20d", Gains);
	printf("║\n");
	for(int i=0;i<3; i++)
	{
		printf("╚");
		AfficheN205(20);
		printf("╝");
		AfficheNCara(espacement, 32);
	}
	printf("\n");
	//AfficheNCara(27*3, 32);//remet curseur au millieu
}


void AfficheAttenteAction()
{
	AfficheNCara(155, 32);
	printf("\033[32;01mQue voulez vous faire ... ?\033[00m");
	printf(" ");
}


void AleaMachine(int *a1, int *a2, int *a3)//renvoie 3 nombres entre 1 et 6.
{
	srand (time (NULL));
	*a1=(rand()%6)+1;
	*a2=((((((rand()%6)+12)%6)+6)*53)%6)+1;
	*a3=(((((rand()%6)+12)%6)*42)%6)+1;
}


void AfficheMenuJouer()
{
	printf("Combien d'argent voulez vous miser ? maximum 3!\n");
	printf("0 - Retour en arriere\n");
	printf("1, 2 ou 3 - la mise en Jeton\n");
	printf("\n\n\n\n");//pour mettre a niveau par rapport au meu initiale
}


void TransfoEnMaj(int n, char tab[n])
{
	for(int i=0; i<n; i++)
	{
		if(tab[i]>='a' && tab[i]<='z')
		{
			tab[i]=tab[i]+('A'-'a');
		}
	}
}


void AfficheMotParie()
{
	printf("Sur Quel mot de 3 lettres pariez vous ?\nEntrez le mot sans espace!\n");
	printf("Les lettres disponibles sont : A\tC\tU\tF\tO\tE\n");
	printf("\n\n\n\n");//pour mettre a niveau par rapport au meu initiale
}

char RemplissageLettreDansMachine(int alea, int l, int h,char Machine[l][h])
{
	char CharMachine;//va contenir le caractere aleatoire affiché dans la machine
	if(alea == 1)
	{
		CharMachine='A';
		for(int i=0; i<h; i++)
		{
			for(int j=0;j<l;j++)
			{
				//bar de gauche//bardu haut//bar de droite//bar du centre !!!!!
				if( (i>=1 && i<=h-2 && j>=1 && j<= 1)|| ( i>=1 && i<=1 && j>=1 && j<=l-2 ) || (i>=1 && i<=h-2 && j>=l-2 && j<=l-2) || (i>=4 && i<=4 && j>=1 && j<=l-2) )//corespond au 4 bar du A
				{
					Machine[j][i]='*';
				}
			}
		}
	}
	if(alea == 2)
	{
		CharMachine='C';
		for(int i=0; i<h; i++)
		{
			for(int j=0;j<l;j++)
			{	//bar de gauche, bar du haut, bar du bas
				if( (i>=1 && i<=h-2 && j>=1 && j<=1) || ( i>=1 && i<=1 && j>=1 && j<=l-2 ) || (i>=h-2 && i<=h-2 && j>=1 && j<=l-2))
				{
					Machine[j][i]='*';
				}
			}
		}
	}
	
	if(alea == 3)
	{
		CharMachine='U';
		for(int i=0; i<h; i++)
		{
			for(int j=0;j<l;j++)
			{
				//bar de gauche, bar de droite, bar du bas
				if( (i>=1 && i<=h-2 && j>=1 && j<=1) || (i>=1 && i<=h-2 && j>=l-2 && j<=l-2) || (i>=h-2 && i<=h-2 && j>=1 && j<=l-2) )
				{
					Machine[j][i]='*';
				}
			}
		}
	}
	if(alea == 4)
	{
		CharMachine='F';
		for(int i=0; i<h; i++)
		{
			for(int j=0;j<l;j++)
			{
				//bar de gauche//bardu haut//bar du centre !!!!!
				if( (i>=1 && i<=h-2 && j>=1 && j<=1) || ( i>=1 && i<=1 && j>=1 && j<=l-2 ) || (i>=4 && i<= 4 && j>=1 && j<=2) )
				{
					Machine[j][i]='*';
				}
			}
		}
	}
	if(alea == 5)
	{
		CharMachine='O';
		for(int i=0; i<h; i++)
		{
			for(int j=0;j<l;j++)
			{
				//bar de gauche//bardu haut//bar de droite//bar du bas !!!!!
				if( (i>=1 && i<=h-2 && j>=1 && j<=1) || ( i>=1 && i<=1 && j>=1 && j<=l-2 ) || (i>=1 && i<=h-2 && j>=l-2 && j<=l-2) || (i>=h-2 && i<=h-2 && j>=1 && j<=l-2) )
				{
					Machine[j][i]='*';
				}
			}
		}
	}
	if(alea == 6)
	{
		CharMachine='E';
		for(int i=0; i<h; i++)
		{
			for(int j=0;j<l;j++)
			{	//bar de gauche, bar du haut, bar du bas//bar du milieu
				if( (i>=1 && i<=h-2 && j>=1 && j<=1) || (i>=1 && i<=1 && j>=1 && j<=l-2) || (i>=h-2 && i<=h-2 && j>=1 && j<=l-2) || (i>=4 && i<=4 && j>=1 && j<=2) )
				{
					Machine[j][i]='*';
				}
			}
		}
	}
	return CharMachine;
}


void DemandeMotParie(char *l1, char *l2, char *l3)//j'aurais du séparer en 2fonction : 1affiche et 2demande!!
{
		char string[4];
		scanf ("%3[ACEFOUacefou]", string);//n'accepte que les lettres a c e f o et u.
		scanf ("%*[^\n]");
		getchar ();
		TransfoEnMaj(4, string);//si l'utilisateur a entré une minuscule, la transforme en majuscule
		//scanf("%s", string);
		*l1=string[0];
		*l2=string[1];
		*l3=string[2];
		//printf("lettre1|%c|lettre2|%c|lettre3|%c|", *l1, *l2, *l3);

}

int ArgentGagne(int mise, char l1, char l2, char l3)
{//en partant du principe qu'il est plus compliqué d'avoir 3 lettres pareils que 3 différentes plus il y a de lettres pareil, plus on gagne d'argent!
	if(mise==1)
	{
		if(l1==l2)//1 jeton similaire
		{
			mise=mise*2;//on double le bénefice en jeton
		}
		if(l2==l3)
		{
			mise=mise*2;//on double le bénefice en jeton
		}
		if(l1==l1)
		{
			mise=mise*2;//on doucle le bénefice en jeton
		}
	}
	if(mise==2)
	{
		if(l1==l2)//1 jeton similaire
		{
			mise=mise*3;//on triple le bénefice en jeton
		}
		if(l2==l3)
		{
			mise=mise*3;//on triple le bénefice en jeton
		}
		if(l1==l1)
		{
			mise=mise*3;//on triple le bénefice en jeton
		}
	}
	if(mise==3)
	{
		if(l1==l2)//1 jeton similaire
		{
			mise=mise*4;//on quadruple le bénefice en jeton
		}
		if(l2==l3)
		{
			mise=mise*4;//on quadruple le bénefice en jeton
		}
		if(l1==l1)
		{
			mise=mise*4;//on quadruple le bénefice en jeton
		}
	}
	return mise;
}


void Jouer(int *Mise, int *Argent, int *Gains, int l, int h, char Machine1[l][h], char Machine2[l][h], char Machine3[l][h])
{
	int choix=-1;char l1='\0';char l2='\0';char l3='\0';
	
	do
	{
		system("clear");
		AfficheMachine(3, l, h, Machine1, Machine2, Machine3);
		if(*Argent<choix)
		{
			printf("\033[36;01mVous ne possédez pas assez de Jetons\033[00m\n");
		}
		AfficheMenuJouer();//demande la mise en jeton
		AfficheInfo(*Mise, *Argent, *Gains);
		AfficheAttenteAction();
		Reponse(&choix);
		
	}while(choix != 0 && choix != 1 && choix != 2 && choix != 3 || *Argent < choix );//avec 0 le retour en arriere
	*Mise=choix;

	if(choix != 0)//on ne choisit pas de revenir en arriere donc on lance les machines :
	{
		int alea1, alea2, alea3;

		system("clear");
		AfficheMachine(3, l, h, Machine1, Machine2, Machine3);
		AfficheMotParie();//affiche la demande de 3 lettres
		DemandeMotParie(&l1, &l2, &l3);//recupere le mot de 3 lettre sur lequel le joueur parie
		while(l1=='\0' || l2=='\0' || l3=='\0')
		{
			system("clear");
			AfficheMachine(3, l, h, Machine1, Machine2, Machine3);
			AfficheMotParie();//affiche la demande de 3 lettres
			printf("\033[36;01mle mot que vous avez entré,|%c%c%c| n'est pas un mot valide !\033[00m\nVeuillez de nouveau entrer votre mot :", l1, l2, l3);
			DemandeMotParie(&l1, &l2, &l3);//recupere le mot de 3 lettre sur lequel le joueur parie
		}
		AleaMachine(&alea1, &alea2, &alea3);//renvoie 3 nombres entre 1 et 6.
		
		char M1=RemplissageLettreDansMachine(alea1, l, h, Machine1);//converti le nombre en char et affiche dans machine
		system("clear");//clear le teerminal
		AfficheMachine(3, l, h, Machine1, Machine2, Machine3);//affiche la machine avec le symbole aleatoire tiré
		printf("\n\nVotre mot : %c%c%c", l1, l2, l3);
		printf("\n");
		
		WaitTime(2);//attend

		char M2=RemplissageLettreDansMachine(alea2, l, h, Machine2);//remplie la machine 2...
		system("clear");//clear le terminal ...
		AfficheMachine(3, l, h, Machine1, Machine2, Machine3);//affiche la machine 1 2 et 3 replies...
		printf("\n\nVotre mot : %c%c%c", l1, l2, l3);
		printf("\n");

		
		WaitTime(2);

		char M3=RemplissageLettreDansMachine(alea3, l, h, Machine3);
		system("clear");
		AfficheMachine(3, l, h, Machine1, Machine2, Machine3);
		printf("\n\nVotre mot : %c%c%c", l1, l2, l3);
		printf("\n");
		
		WaitTime(2);

		system("clear");

		if(M1 == l1 && M2 == l2 && M3 == l3)
		{
			AfficheMachine(3, l, h, Machine1, Machine2, Machine3);
			printf("\n\033[32;05mBRAVOOOOOOO C'EST UNE VICTOIIIIRE\033[00m\n\n\n\n\n\n");
			WaitTime(5);//cumule de wait pour rester plus longtemps sur l'ecran de victoire.
			int argentgagne=ArgentGagne(*Mise, l1, l2, l3);
			
			*Argent=*Argent-*Mise;//enleve les jetons de la mise
			*Argent=*Argent+argentgagne;//donne les jetons pour la victoire
			*Gains=*Gains+argentgagne;//fait augmenter le compteur des gains.

			AfficheInfo(*Mise, *Argent, *Gains);
		}
		else
		{
			AfficheMachine(3, l, h, Machine1, Machine2, Machine3);
			printf("\nVotre mot : |%c%c%c| ne correspond pas à |%c%c%c|\nVous avez été débité de votre mise(%d jetons)\n\n\n\n\n", l1, l2, l3, M1, M2, M3, *Mise);
			*Argent=*Argent-*Mise;
			AfficheInfo(*Mise, *Argent, *Gains);
		}
		WaitTime(5);
	}
	//sinon retour en arriere
}

int DemandeRemettreArgent(int l,int h,char Machine1[l][h],char Machine2[l][h],char Machine3[l][h])
{
	int argent=0;
	do
	{
		system("clear");
		AfficheMachine(3, l, h, Machine1, Machine2, Machine3);
		if(argent != 0)
		{
			printf("\n\n\033[36;01mVeuillez entrez un nombre correcte !\033[00m\n");
			printf("Votre nombre :\n");
		}
		else
		{
			printf("\n\nVeuillez entrer le nombre de Jeton que vous souhaitez ajouter : ");
		}
		Reponse(&argent);
	}while(argent<0);
	return argent;
}


int main()
{
	int bugcaractere=0;
	int Mise=0;int Gains=0;int Argent=0;//a int quand appuyer sur jouer
	int l=5;int h=10;
	int choix=-1;
	

	char Machine1[l][h];
	char Machine2[l][h];
	char Machine3[l][h];

	ResetMachine(l, h, Machine1);
	ResetMachine(l, h, Machine2);
	ResetMachine(l, h, Machine3);

	do
	{
		ResetChoix(&choix);
		system("clear");
		AfficheMachine(3, l, h, Machine1, Machine2, Machine3);
		AfficheMenu(Argent, l);
		AfficheInfo(Mise, Argent, Gains);
		
		AfficheAttenteAction();
		Reponse(&choix);

		if(choix==1)//on choisit de jouer
		{
			if(Argent > 0)//verifie que l'on possède assé de jetons
			{
				ResetMachine(l, h, Machine1);
				ResetMachine(l, h, Machine2);
				ResetMachine(l, h, Machine3);
				Jouer(&Mise, &Argent, &Gains, l, h, Machine1, Machine2, Machine3);				
			}
			else
			{
				system("clear");
				AfficheMachine(3, l, h, Machine1, Machine2, Machine3);
				printf("\n\n\033[36;01mVOUS N'AVEZ PAS ASSEZ D'ARGENT VEUILLEZ VOUS RECHARGER EN JETONS !\033[00m\n\n\n\n\n");
				AfficheInfo(Mise, Argent, Gains);
				WaitTime(5);
			}
			ResetChoix(&choix);//réinitialise la var choix pour eviter les boucles de menu
		}
		if(choix==2)//on choisit de mettre de l'argent
		{
			Argent=Argent+DemandeRemettreArgent(l, h, Machine1, Machine2, Machine3);//demande et remet de l'argent!
			ResetChoix(&choix);//réinitialise la var choix pour eviter les boucles de menu
		}
		if(choix !=1 && choix !=2 && choix !=3)
		{
			printf("\n");//permet de réafficher le menu correctement sans que le texte précedent ne deborde dessus car le system("clear")semble ne pas fonctionner
		}
	}while(choix != 3);//on choisit de quitter // tourne peut etre en boucle ...
	system("clear");
	return 0;
}