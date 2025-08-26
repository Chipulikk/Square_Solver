#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define GG 12345678e-10f
#define LINEY 3
#define HUNA 5
#define ZERO_SOLVES 0
#define ONE_SOLVE 1
#define TWO_SOLVES 2
#define TEST 'q'
#define SOLVE 'w'
#define EXIT 'e'

struct kal
    {
    float a, b, c, d;
    float x1, x2;
    };

void vvodilka (kal *start);
void ProverkaChisla(float *a);
int SuperReshalka (kal *start);
void vivodilka (kal start);
void VvodKvadratki (kal *start);
int NULL_CHECK (float a);
void swap (kal *start);
int AllTests ();
int linchik (kal *start);
int my_assert(float a);
char Fem();

// проассерить все функции
// выбор пути в начале мэйна

//fopen, fread, fclose

int main (void)
{
while (1)
    {
    switch (Fem ())
        {
        case TEST:
            {AllTests (); break;}


        case SOLVE:
            {
            printf ("Введите данные уравнения, опираясь на его вид: ax^2+bx+c=d\n\n");

            struct kal start  = {NAN, NAN, NAN, NAN, NAN, NAN};

            //struct kal *start = NULL;
            my_assert (&start != 0);

            VvodKvadratki (&start);
            //SuperReshalka (start);

            vivodilka (start);

            break;
            }


        case EXIT:
            exit(1);


        case HUNA:
            {
            printf ("У тебя нет такого выбора");
            break;
            }

        }


    printf("\n\n\//////////////////////////////////////////////////////////////////\n\n");                                                                   //
    }
}

//--------------------------------------------------------------------------------


int my_assert(float a)  //, exit(1)
    {
    if (a == 0)
        {
        printf ("\n  ///////////////////////////////////////\n"
                " ////////  Error: NULL adress  /////////"
                "\n///////////////////////////////////////\n");
        exit (1);
        }
    }



//-----------------------------------------------------------------------------------------

void VvodKvadratki (kal *start)
    {
    my_assert (start != 0);


    printf ("Введите значение a:\na=");
    ProverkaChisla(&start->a);

    printf ("Введите значение b:\nb=");
    ProverkaChisla(&start->b);

    printf ("Введите значение c:\nc=");
    ProverkaChisla(&start->c);

    printf ("Введите значение d:\nd=");
    ProverkaChisla(&start->d);
    }



//вычисления
int SuperReshalka (kal *start)
    {
    my_assert(start != NULL);


    if (NULL_CHECK (start->a)==true)
        return (linchik (start));

    else        // the zhirnaya funkcija!  // this is krivo!!!  // kill!
        {
        float D = (start->b) * (start->b) - 4 * (start->a)  *  ((start->c) - (start->d));

        if (NULL_CHECK(D) == true)
            {
            (start->x1) = -(start->b) / ( 2* (start->a));
            (start->x2) = GG;   //x1 - otvet, x2 - GG
            return ONE_SOLVE; // 1 kor
            }

        else
            {
            if (D<0)
                return ZERO_SOLVES;  // 0 kor
                (start->x1) = (start->x2)=0;

            if (D > 0)
                {
                float sqrt_D = sqrt(D);

                (start->x1) = (-(start->b) + sqrt_D) / (2 * (start->a));
                (start->x2) = -((start->b) + sqrt_D) / (2 * (start->a));

                if ((start->x1) > (start->x2))
                    swap (start);

                return TWO_SOLVES; //2 kor

                }
            }
        }
    }

//------------------------------------------

 void vivodilka (kal start)
    {
    my_assert (&start != 0);


    int res = SuperReshalka(&start);
    switch (res)
        {

        case ZERO_SOLVES:
            {printf ("\nU etogo uravneniya net resheniy");break;}


        case ONE_SOLVE:
            {printf ("\nU etogo kvadratnogo uravneniya tolko 1 reshenie:\n x=%f", start.x1); break;}


        case TWO_SOLVES:
            {printf ("\nРешение вашего уравнения: %f; %f", start.x1, start.x2); break;}


        case LINEY:
            {
            printf ("\n\npshel ti, kozel, eto ne kvadratnoye uravnenyie"
                     "\n\nLadno, poh, reshu:\n x = %f", start.x2);
            break;
            }


        case HUNA:
            {printf("\nti voobsche daun"); break;}
        }
    }

//--------------------------------------------------------------------------

void ProverkaChisla(float *a)
    {
    my_assert (a != 0);


    while(1)
        {

        while (scanf("%f", a) == 0)
            {
            printf ("\n\n Eto ne chislo, vvedite chislo povtorno:   ");
            while (getchar() != '\n');
            }

        if (getchar() == '\n')
            break;

        else
            while (getchar() != '\n');
            printf ("\n\nGovno posle chisla\nVvedite chislo povtorno:   ");
        }
    }

//---------------------------------------------------------------------------

int NULL_CHECK (float a)
    {
    my_assert (&a != 0);

    if (abs(a)<10e-28)
        return 1;
    else
        return 0;
    }
//--------------------------------------------------------------------------

void swap (kal *start)
    {
    my_assert (start != 0);

    float z = start->x1;
    start->x1=start->x2;
    start->x2=z;
    }

//---------------------------------------------------------------------------------------

int Test (kal start)
    {
    my_assert (&start != 0);


    float x1t=start.x1;
    float x2t=start.x2;

    SuperReshalka (&start);

    if (x1t==start.x1 && x2t==start.x2)
        {
        printf ("Испытание прошло успешно\n");
        return 0;
        }

    else
        {
        printf ("Ошибка\n");
        return 1;
        }
    }

//-------------------------------------------------------------------

int AllTests ()
    {



    kal test1 = {4, 3, -1, 0, -1, 0.25};
    kal test2 = {0, 0, 2, 4, GG, GG};
    kal test3 = {0, 1078, 0, 60583.6, GG, 56.2};
    kal test4 = {1, 9.4, 21 ,-1.09, -4.7, GG};
    kal test5 = {46, 4.74, 943, 49, 0, 0};

    int N = (Test (test1) + Test (test2) + Test (test3) + Test (test4) + Test (test5));

    printf ("Обнаружено %d ошибок из 5 возможных", N);
    }

//-----------------------------------------------------------------

int linchik (kal *start)
    {
    my_assert (start != 0);


    if (NULL_CHECK (start->b)==true)   // huna
            {
            return HUNA;
            (start->x1) = GG; (start->x2)= GG;
            }
        else
            {
            (start->x2) = ((start->d) - (start->c)) / (start->b);     //x2 - otvet x1 - GG
            return LINEY;
            (start->x1) = GG;   //liney
            }
    }

 //----------------------------------------------------------

 char Fem ()
    {
    printf ("Выберите функцию.\na: Тестирование\nb: Решить уравнениеn \nc: Закрыть программу\n_\b ");
    char a;
    while (1)
        {
        if (scanf ("%c", &a) == 0)
            {
            while (getchar() != '\n');
            return HUNA;
            break;
            }

        if (a == 'a')
            if (getchar() == '\n')
                {
                return TEST;
                break;
                }

            else
                {
                while (getchar() != '\n');
                return HUNA;
                break;
                }


        if (a == 'b')
            if (getchar() =='\n')
                {
                return SOLVE;
                break;
                }
            else
                {
                while (getchar() != '\n');
                return HUNA;
                break;
                }


        if (a == 'c')
            if (getchar() == '\n')
                {
                return EXIT;
                break;
                }
            else
                {
                while (getchar() != '\n');
                return HUNA;
                break;
                }


        if (a!= 'a' && a!= 'b' && a!='c')
            {
            while (getchar() != '\n');
            return HUNA;
            }
        }
    }


//-------------------------------------------

//char ProvBuk ()


