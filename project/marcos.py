f = file('macros.h','w+')
var = (
    ('rouge',8),
    ('vert',8),
    ('bleu',8),
    ('vitesse',4),
    ('taille',8),
    ('type',4),
    ('amis',4),
    ('bouff',4),
    ('defand',4),
    ('vision',8),
    ('deplacement',2),
    )
size = 0
for i in range(0,var.__len__()):
    if i ==0:
        f.write('#define data_debut 0\n\n')
        f.write('#define %s_debut data_debut \n' % (var[i][0]))
    else :
        f.write('#define %s_debut %s_fin +1\n' %(var[i][0],var[i-1][0]))

    f.write('#define %s_size %d\n' % (var[i][0],var[i][1]))
    f.write('#define %s_fin %s_debut + %s_fin -1\n' %(var[i][0],var[i][0],var[i][0]))
    size += var[i][1]
    f.write('\n')

    if i == var.__len__()-1:
        f.write('#define data_fin %s_fin\n' % var[i][0])
        f.write('#define data_size %d\n' % size)

