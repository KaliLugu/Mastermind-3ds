#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	// commande pour initialiser le système graphique par défaut
	gfxInitDefault();
	
	consoleInit(GFX_TOP, NULL);
	
	//Print current time
	time_t unixTime = time(NULL);
	struct tm* timeStruct = gmtime((const time_t *)&unixTime);

	int hours = timeStruct->tm_hour;
	int minutes = timeStruct->tm_min;
	int seconds = timeStruct->tm_sec;

	// Créer une seed unique en combinant les composants de la date et de l'heure	
	int seed = hours + minutes + seconds;
	
	// Initialiser le générateur de nombres aléatoires avec la seed
	srand(seed);
	
	// Générer et afficher 4 chiffres aléatoires
	char chiffre[5];
    for (int i = 0; i < 4; i++) {
        chiffre[i] = '0' + (rand() % 10); // Génère un chiffre entre '0' et '9'
    }
    chiffre[4] = '\0'; // Termine la chaîne de caractères

    // Afficher les chiffres générés (pour le débogage)
    //printf("Generated: %s\n", chiffre);
	printf("Press B to enter numbers.");

	
	// Main loop
	while (aptMainLoop())
	{
		// vérifie si une touche est presser
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break; // break in order to return to hbmenu
		
		static SwkbdState swkbd;
		static char mybuf[60];
		SwkbdButton button = SWKBD_BUTTON_NONE;
		bool didit = false;
		
		if (kDown & KEY_B)
		{
			didit = true;
			swkbdInit(&swkbd, SWKBD_TYPE_NUMPAD, 1, 4);
			swkbdSetPasswordMode(&swkbd, SWKBD_PASSWORD_HIDE_DELAY);
			swkbdSetValidation(&swkbd, SWKBD_ANYTHING, 0, 0);
			swkbdSetFeatures(&swkbd, SWKBD_FIXED_WIDTH);
			button = swkbdInputText(&swkbd, mybuf, sizeof(mybuf));
		}
		
		if (didit)
		{
			if (button != SWKBD_BUTTON_NONE)
			{
				printf("\nyou tried : %s", mybuf);
				int longueur = strlen(mybuf);
				
				if (longueur == 4) {
                    if (strcmp(mybuf, chiffre) == 0)
                    {
                        printf("\nGreat, you found the sequence of numbers,\npress start to return to the homebrew launcher.");
                    } else {
                        // Comparaison des caractères
                        for (int i = 0; i < 4; i++) {
                            if (mybuf[i] == chiffre[i]) {
                                printf("\nNumber %c is in the correct position.", mybuf[i]);
                            } else {
                                for (int j = 0; j < 4; j++) {
                                    if (mybuf[i] == chiffre[j]) {
                                        printf("\nNumber %c is in the wrong position.", mybuf[i], i+1);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                } else {
					printf("\nYou have to use 4 numbers.");
				}
			} else
				printf("swkbd event: %d\n", swkbdGetResult(&swkbd));
		}
		
		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}
	
	gfxExit();
	return 0;
}