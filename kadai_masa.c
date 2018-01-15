/************************************************/
/*  kadai.c
/*
/*  ���t1�Ɠ��t2�̊Ԃ̓������v�Z�B
/*
/************************************************/

#include <stdio.h>
#include <cstring>
#include <stdlib.h>

/************************************************/
/*  main
/*
/*  �p�����[�^ : �Ȃ�
/*  �߂�l     : �Ȃ� 
/*
/*  ���t1�Ɠ��t2����͂��Ԃ̓�����\������B
/************************************************/


int main (void)
{
    int Year1=0,Year2=0,Mon1=0,Mon2=0,Day1=0,Day2=0,Nissu=0;		/* ���t1�Ɠ��t2�̔N�����i�[ */
    int     chk_date,chk_date2					;					/* ���Ɠ����`�F�b�N�p */
    char    conv[ 10 ];												/* ���t�𕶎���ɂ��� */
    char    work[ 128 ];											/* ���͂��ꂽ���t���i�[*/

    while( 1 ) {
        printf( "\n ���t1( YYYYMMDD  )" );

        work[ 0 ] = '\0';
        scanf( "%s", work );

        if( strlen( work ) != 8 ) {									/* �N������������Ɠ��͂���܂ŌJ��Ԃ� */
            printf( "\n ���̓~�X�ł�" );
            continue;
        }

        if( strspn( work, "1234567890" ) < strlen( work ) ) {
            printf( "\n ���l�ȊO�����͂���܂���" );
            continue;
        }

        conv[0] = work[4];
        conv[1] = work[5];
        conv[2] = '\0';

        chk_date = atoi( conv );
        if( chk_date > 12 || chk_date < 1 ) {
            printf( "\n ���t( �� )���̓G���[�ł�" );
            continue;
        }

        conv[0] = work[6];
        conv[1] = work[7];
        conv[2] = '\0';
        chk_date2 = atoi( conv );
        if( chk_date2 > 31 || chk_date2 < 1 ) {
            printf( "\n ���t( �� )���̓G���[�ł�" );
            continue;
        }

        break;
    }
    conv[0] = work[0];												/* �N�̐�̈ʑ�� */
    conv[1] = work[1];												/* �N�̕S�̈ʑ�� */
    conv[2] = work[2];												/* �N�̏\�̈ʑ�� */
    conv[3] = work[3];												/* �N�̈�̈ʑ�� */
    conv[4] = '\0';
    Year1 = atoi(conv);
    Mon1 = chk_date;
    Day1 = chk_date2;
    
        while( 1 ) {
        printf( "\n ���t2( YYYYMMDD  )" );

        work[ 0 ] = '\0';
        scanf( "%s", work );

        if( strlen( work ) != 8 ) {									/* �N������������Ɠ��͂���܂ŌJ��Ԃ� */
            printf( "\n ���̓~�X�ł�" );
            continue;
        }

        if( strspn( work, "1234567890" ) < strlen( work ) ) {
            printf( "\n ���l�ȊO�����͂���܂���" );
            continue;
        }

        conv[0] = work[4];
        conv[1] = work[5];
        conv[2] = '\0';

        chk_date = atoi( conv );
        if( chk_date > 12 || chk_date < 1 ) {
            printf( "\n ���t( �� )���̓G���[�ł�" );
            continue;
        }

        conv[0] = work[6];
        conv[1] = work[7];
        conv[2] = '\0';
        chk_date2 = atoi( conv );
        if( chk_date2 > 31 || chk_date2 < 1 ) {
            printf( "\n ���t( �� )���̓G���[�ł�" );
            continue;
        }

        break;
    }
    conv[0] = work[0];												/* �N�̐�̈ʑ�� */
    conv[1] = work[1];												/* �N�̕S�̈ʑ�� */
    conv[2] = work[2];												/* �N�̏\�̈ʑ�� */
    conv[3] = work[3];												/* �N�̈�̈ʑ�� */
    conv[4] = '\0';
    Year2 = atoi(conv);
    Mon2 = chk_date;
    Day2 = chk_date2;

    printf("%d���ł��B",niti(Year1,Year2,Mon1,Mon2,Day1,Day2,Nissu));
}

/************************************************/
/*  niti
/*
/*  �p�����[�^ : Year1,Year2,Mon1,Mon2,Day1,Day2,Nissu
/*  �߂�l     : int Nissu 
/*
/*  ���t1�Ɠ��t2�̊Ԃ̓������J�E���g����B
/************************************************/


int niti(Year1,Year2,Mon1,Mon2,Day1,Day2,Nissu)
{
	int uru=0;
	while((Year1 != Year2) || (Mon1 != Mon2) || (Day1 != Day2)) {
		if(Mon1 == 2) {
			uru = ururu(Year1,uru);									/* ���邤�N�v�Z */
			if(uru == 0 && Day1 == 28) {
				Mon1++;
				Day1=1;
				Nissu++;
			}
			else if(uru == 1 && Day1==29) {							/* ���邤�N�̌������� */
				Mon1++;
				Day1=1;
				Nissu++;
			}
			else {
				Day1++;
				Nissu++;
			}
		}
		else if(Day1 == 30) {
			if((Mon1 ==4) || (Mon1 == 6) || (Mon1 == 9) || (Mon1 == 11)) {
				Mon1++;
				Day1=1;
				Nissu++;
			}
			else {
				Day1++;
				Nissu++;
			}
		}
		else if(Day1 == 31) {
			if(Mon1 == 12) {										/* �N������ */
				Mon1 = 1;
				Day1 = 1;
				Nissu++;
				Year1++;
			}
			else {
				Mon1++;
				Day1 = 1;
				Nissu++;
			}
		}
		else {
			Day1++;
			Nissu++;
		}
	}

	return Nissu;
}


/************************************************/
/*  ururu
/*
/*  �p�����[�^ : Year1,uru
/*  �߂�l     : int uru
/*
/*  ���t1�̔N������N������
/************************************************/


int ururu(Year1,uru)
{
	if((Year1 % 4 == 0) && (Year1 % 100 != 0) || (Year1 % 400 == 0) ) {
		uru =1;

	}
	else {
		uru = 0;
	}
	return uru ;
}
