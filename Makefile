CC = gcc
EXEC = programme

all : $(EXEC)

$(EXEC) : obj/main.o obj/BIB_standard.o obj/conio2.o obj/BIB_recruteur.o obj/BIB_offre.o obj/BIB_demande.o obj/BIB_affichage.o obj/EMPLOI_LLC_BIBLIO.o
	$(CC) -o $(EXEC).exe obj/main.o obj/BIB_standard.o obj/conio2.o obj/BIB_recruteur.o obj/BIB_offre.o obj/BIB_demande.o obj/BIB_affichage.o obj/EMPLOI_LLC_BIBLIO.o

obj/main.o : main.c
	$(CC) -o obj/main.o -c main.c

obj/BIB_standard.o : lib/BIB_standard.c
	$(CC) -o obj/BIB_standard.o -c lib/BIB_standard.c

obj/conio2.o : lib/conio2.c
	$(CC) -o obj/conio2.o -c lib/conio2.c

obj/BIB_recruteur.o : lib/BIB_recruteur.c
	$(CC) -o obj/BIB_recruteur.o -c lib/BIB_recruteur.c

obj/BIB_offre.o : lib/BIB_offre.c
	$(CC) -o obj/BIB_offre.o -c lib/BIB_offre.c

obj/BIB_demande.o : lib/BIB_demande.c
	$(CC) -o obj/BIB_demande.o -c lib/BIB_demande.c

obj/BIB_affichage.o : lib/BIB_affichage.c
	$(CC) -o obj/BIB_affichage.o -c lib/BIB_affichage.c

obj/EMPLOI_LLC_BIBLIO.o : EMPLOI_LLC_BIBLIO.c
	$(CC) -o obj/EMPLOI_LLC_BIBLIO.o -c EMPLOI_LLC_BIBLIO.c

