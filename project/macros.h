#define data_debut 0

#define rouge_debut data_debut 
#define rouge_size 8
#define rouge_fin rouge_debut + rouge_fin -1

#define vert_debut rouge_fin +1
#define vert_size 8
#define vert_fin vert_debut + vert_fin -1

#define bleu_debut vert_fin +1
#define bleu_size 8
#define bleu_fin bleu_debut + bleu_fin -1

#define vitesse_debut bleu_fin +1
#define vitesse_size 4
#define vitesse_fin vitesse_debut + vitesse_fin -1

#define taille_debut vitesse_fin +1
#define taille_size 8
#define taille_fin taille_debut + taille_fin -1

#define type_debut taille_fin +1
#define type_size 4
#define type_fin type_debut + type_fin -1

#define amis_debut type_fin +1
#define amis_size 4
#define amis_fin amis_debut + amis_fin -1

#define bouff_debut amis_fin +1
#define bouff_size 4
#define bouff_fin bouff_debut + bouff_fin -1

#define defand_debut bouff_fin +1
#define defand_size 4
#define defand_fin defand_debut + defand_fin -1

#define vision_debut defand_fin +1
#define vision_size 8
#define vision_fin vision_debut + vision_fin -1

#define deplacement_debut vision_fin +1
#define deplacement_size 2
#define deplacement_fin deplacement_debut + deplacement_fin -1

#define data_fin deplacement_fin
#define data_size 62
