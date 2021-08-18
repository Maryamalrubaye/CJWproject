#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mylibrary.h"

// functions declarations :

    // this function has the first page that shoes up to the user immediately after he enters his login information correctly
void mainpage();

    // this function gives all the choices the program can do related to the silver section.
void silver_system();

	// this function gives all the choices the program can do related to the gold section.
void gold_system ();

	// this function analysis the ingot.
void ingot ( );

    // this function subtract two numbers to give the quantity difference and save them into a file for silver system.
void subsilver ();

	// this function subtract two numbers to give the quantity difference and save them into a file for gold system.
void subgold();

	// this function shows the total quantity diference that has been saved in the file and showes the quantity that left in the box.
void totalQuantitysilver();

	// this function shows the total quantity diference that has been saved in the file and showes the quantity that left in the box.
void totalQuantitygold();

    // this function change the amount of a particular piece of  jewelry from grams and calculate its price in dollars.
void dollars ( );

    // this function has a table that shows the wages to every single type of a gold jewelry.
void gold_wages();

    // this function has a table that shows the wages to every single type of a silver jewelry.
void silver_wages();

    // this function shows all  types of jewelry that can be created in this company.
void type();

    //this function change the amount of a particular piece of  jewelry from grams and calculate its price in dollars
void dollar();

    // this function
void goback();

    //using struct to use the same variables multiple times to know the menufactoring wages for every single piece of jewelry in both gold and silver systems
struct wages
{
    char type [70];
    int price;
    float prices;
};

    //used this struct to do a list that contains all the jewelry types that
struct type
{
    char type [40];
};

    // I used struct to use the same variable multiple times to calculate the total price in dollars for both silver and gold systems
typedef struct
{
    float ONS;
    float grams;
    float wegs;
    int caliber;
}Doca; //struct to dollar calculating


    //function of type struct pointer to allocate a space in the Ram to do some calculating used this function to both silver and gold systems
Doca *allocatememory (Doca*,int);



int main ()
{

    // calling function that shows the date and time on the top of the screen
        timetable();
        system ("COLOR B");
    printf("\t\t\t\t_________________________________________\n\n");
    printf("\t\t\t\t  *****JEWELRY MANAGEMENT  SYSTEM *****\n\a");
    printf("\t\t\t\t_________________________________________\n\n");

    // calling a function that has login system
    password();

    // using loops to give the user the ability to access to the program and to try again if he enters wrong number.
   mainpage();

        return 0;
}

void subsilver ()
{
    float m,n,result=0,temp;
    int i,j,b,max=100;
FILE *pt;
p:
printf("HOW MANY PIECE OF JEWELRY DO YOU WANT TO ENTER: \t "); 
fflush(stdin);
scanf("%d",&b);
if (b>0&&b<max)
	{
	}
	else {
		system("cls");
		printf("wrong interd please try again\n\n" );
		goto p;
	}
printf("DO YOU WANT TO START FROM THE BEGINING ? \t (Press 1 for yes Press 2 to countinue) : ");
scanf("%d",&j);
if (j==1)
{
	pt = fopen ("result.txt","w"); // the user could chose between deleting the file contant by using writing mood or keep them and add to them by chossing append mood.
}
else if (j==2)
{
	pt = fopen ("result.txt","a");
}
    for (i=0;i<b;i++)
    {
    printf("OUT-QUANTITY : \t "); scanf("%f",&m);

    printf("IN-QUANTITY : \t"); scanf("%f",&n);
    
    temp = m-n;
    result=result+temp;

    printf("\n THE QUANTITY DIFERENCE IS = %f\n\n",temp);
    }

    printf("\n");
	fprintf(pt,"%f ",result ); //the sum of the results will be saved in a file
    printf("\n THE TOTAL DIFERENCE IS = %f\n",result);
    fclose (pt);

  	goback(); //calling a function that contains to options one to exit and the ather one to go back to the main page

}

void dollars ( )
{
    Doca *p;
    int n,i,max=100;
    char c;
    float div,result;
    m:
    printf("HOW MANY PIECE OF JEWELRY DO YOU WANT TO ENTER? (MAX=100)\t"); 
    fflush(stdin);
	scanf("%d",&n);
	if (n>0&&n<max)
	{
	}
	else {
		system("cls");
		printf("wrong interd please again\n\n" );
		goto m;
	}
    p = allocatememory (p,n);
    printf("\n________________________________________________________________\n");
    printf("\n\n HERE YOU HAVE YOUR MANUFACTORÝNG WAGES FOR GOLD :  \n");
    FILE *ptr;
    ptr = fopen ("wages1.txt","r");
		while (c != EOF)
		{
			printf("%c",c);
			c=fgetc(ptr);
		}
		fclose (ptr);
	printf("\n__________________________________________________________\n");
    for (i=0;i<n;i++)
    {
        printf("Enter the ONS price : \t");
        scanf("%f",&(p+i)->ONS );

        printf("Enter the amount of grams :\t");
        scanf("%f",&(p+i)->grams);

        printf("Enter the manufacturing wages : \t");
        scanf("%f",&(p+i)->wegs);
	printf("in which caliber you want to have your result?\n chose one of the following list below:\n");
	printf("1) The 24 caliber\n 2) The 22 caliber\n 3)The 21 caliber\n 4)The 18 caliber\n 5) The 14 caliber\n 6) The 12 caliber \n 7) The 8 caliber\n ");
	        printf("The gold caliber you want to get the price in : \t");
	        scanf("%d",&(p+i)->caliber);
	        printf("\n");
        	if ((p+i)->caliber==24)
			{
			    result = (((p+i)->ONS/31.1)*(p+i)->grams)*(p+i)->wegs;
		    }
			else if ((p+i)->caliber==22)
			{
			    div = ((p+i)->ONS/31.1)*(p+i)->grams;
				result = (div/0.916)*(p+i)->wegs;
			}
		    else if ((p+i)->caliber==21)
			{
				div = ((p+i)->ONS/31.1)*(p+i)->grams;
				result = (div/0.875)*(p+i)->wegs;
			}
			else if ((p+i)->caliber==18)
			{
			    div = ((p+i)->ONS/31.1)*(p+i)->grams;
			    result = (div/0.750)*(p+i)->wegs;
		    }
		    else if ((p+i)->caliber==14)
			{
			    div = ((p+i)->ONS/31.1)*(p+i)->grams;
			    result = (div/0.585)*(p+i)->wegs;
			}
            else if ((p+i)->caliber==12)
		    {
				div = ((p+i)->ONS/31.1)*(p+i)->grams;
				result = (div/0.500)*(p+i)->wegs;
			}
			else if ((p+i)->caliber==8)
	        {
				div = ((p+i)->ONS/31.1)*(p+i)->grams;
				result = (div/0.335)*(p+i)->wegs;
			}
			 else
		    {
			printf("wrong number \n\n");
			}
			printf("\n\n THE RESULT IN USA Dollars IS  -> ( %f $ )",result);
        printf("\n");
}
   
   goback();
 }

void gold_wages ()
{
    int n,d=1;
    struct wages w[5];
    FILE * wages1 ;
        wages1=fopen("wages1.txt","w+");


    printf("YOU CAN KNOW THE GOLD MANUFACTORING WAGES FROM THE LIST BELOW :\n\n\n ");

    strcpy( w[0].type,"Gold polish");         //using strings to save characters completed words
    w[0].price= 2;
    strcpy( w[1].type,"Gold polish and handmade");
    w[1].price= 3;
    strcpy( w[2].type,"Gold polish,handmade and laser");
    w[2].price= 4;
    strcpy( w[3].type,"Professional and high quality jewelry");
    w[3].price= 5;
    strcpy( w[4].type,"Special handmade jewelry");
    w[4].price= 8;
    for (n=0;n<5;n++)
    {
        printf("%d) the price of %s  is equal to -> ( %d $ ) \n",d+n,w[n].type,w[n].price);

    }
    for (n=0;n<5;n++)
    {

	    fprintf(wages1,"%d) the price of %s  is equal to -> ( %d $ ) \n",d+n,w[n].type,w[n].price);

    }
     fclose(wages1);

 goback();

}

void silver_wages ()
{
    int n,d=1;
printf("YOU CAN KNOW THW SILVER MANUFACTORING WAGES FROM THE LIST BELOW :\n ");

    struct wages w[5];
    FILE * wages2 ;
        wages2=fopen("wages2.txt","w+");

        strcpy( w[0].type,"Silver polish");
        w[0].price=1;
        strcpy( w[1].type,"Silver polish, and handmade");
        w[1].price= 2;
        strcpy( w[2].type," polish, laser and handmade");
        w[2].price= 3;
        strcpy( w[3].type,"Professional handmade");
        w[3].price= 4;
        strcpy( w[4].type,"special handmade");
        w[4].price= 5;
            for (n=0;n<5;n++)
    {
        printf("%d) the price of %s  is equal to -> ( %d $ ) \n",d+n,w[n].type,w[n].price);
    }
    for (n=0;n<5;n++)
    {

	    fprintf(wages2,"%d) the price of %s  is equal to -> ( %d $ ) \n",d+n,w[n].type,w[n].price);

    }
     fclose(wages2);


    goback();

}

void type ()
{

int i,d=1;
printf("\nYOU CAN KNOW THW AVAILABLE TYPES OF JEWELRY FROM THE LIST BELOW :\n");
    struct type t[11];
    strcpy( t[0].type,"Women's necklaces");
    strcpy( t[1].type,"Women's earrings");
    strcpy( t[2].type,"Women's rings");
    strcpy( t[3].type,"Women's bracelets");
    strcpy( t[4].type,"Women's anklets");
    strcpy( t[5].type,"Brooch");
    strcpy( t[6].type,"Men's earrings");
    strcpy( t[7].type,"Men's rings");
    strcpy( t[8].type,"Men's bracelets");
    strcpy( t[9].type,"Men's necklaces");
    strcpy( t[10].type,"Buttons");
    printf("\n                              \n           { For Women }          \n                                   \n");
    for(i=0;i<6;i++)
    {
        printf("%d) %s\n",d+i,t[i].type);
    }
    printf("\n                              \n           { For Men }          \n                                   \n");
   for(i=6;i<10;i++)
    {
        printf("%d) %s\n",d+i,t[i].type);
    }
    printf("\n                              \n           { For Both }          \n                                   \n");
    printf("11) %s",t[10].type);

 goback();
}

void dollar ()
{
    Doca *p;
    int i,n,max=100;
    float div,result;
    char c;
    m:
    printf("HOW MANY PIECE OF JEWELRY DO YOU WANT TO ENTER? ");
    fflush(stdin);
    scanf("%d",&n);
    if (n>0&&n<max)
	{
	}
	else {
		system("cls");
		printf("wrong interd please again\n\n" );
		goto m;
	}
    p = allocatememory (p,n);
    printf( "\n\nHERE YOU HAVE YOUR MANUFACTORING WAGES\n");
    	FILE *fp;
    	fp=fopen("wages2.txt","r");
    	if (fp==NULL)
    	{
    		printf("WARNING!!\tcan not open this file!");
		}
		c = fgetc(fp);
		while (c != EOF)
		{
			printf("%c",c);
			c=fgetc(fp);
		}

    	fclose(fp);



    for (i=0;i<n;i++)
    {
        printf("\nEnter the ONS price : \t");
        scanf("%f",&(p+i)->ONS );

        printf("\nEnter the amount of grams : \t");
        scanf("%f",&(p+i)->grams);

        printf("\nEnter the manufacturing wages : \t");
        scanf("%f",&(p+i)->wegs);
        div= ((p+i)->ONS/31.1)*0.925;
        result = (div*(p+i)->grams)*(p+i)->wegs;
        printf("YOUR FINAL RESULT IS : %f $\n",result);

   }
    goback();
}

void gold_system ()
{
    int m;
    printf("\n\n                                      	    { GOLD MAMAGEMENT SYSTEM }                               \n________________________________________________________________________________________________________________________\n");
    printf("\n\n\n - FOR EVERY DAY TABLE CHOSE 1\n - FOR CALCULATING THE TOTAL QUANTITY DIFERANCE CHOSE 2\n - TO CHANG FROM GRAMS TO DOLLAR CHOSE 3\n - TO KNOW THE MANUFACTORING WAGES CHOSE 4\n - TO KNOW THE AVAILABLE TYPES OF JEWELRY FOR BOTH GENDERS CHOSE 5\n - TO GO BACK TO THE MAIN PAGE CHOSE 6\n");
    scanf("%d",&m);
	if (m==1)
    {
		system("cls");
		subgold(); //calling function
    }
    else if (m==2)
    {
    system("cls");
    totalQuantitygold();
	}
    else if (m==3)
    {
     	system("cls");
        dollars ();  //calling function
	}
    else if (m==4)
    {
	    system("cls");
	    gold_wages(); //calling function
    }
    else if (m==5)
    {
        system("cls");
        type(); //calling function
    }
    else if (m==6)
    {
        goback();
    }
	else
    {	system("cls");
        printf ("wrong number please try again\n");
        fflush (stdin);
        gold_system();
    }
}

void silver_system()
{
    int p;
    
  	printf("\n\n                                      	    { SILVER MAMAGEMENT SYSTEM }                               \n________________________________________________________________________________________________________________________\n");
    printf("\n\n\n - FOR EVERY DAY TABLE CHOSE 1\n - FOR CALCULATING THE TOTAL QUANTITY DIFERANCE CHOSE 2\n - TO CHANG FROM GRAMS TO DOLLAR CHOSE 3\n - TO KNOW THE MANUFACTORING WAGES CHOSE 4\n - TO KNOW THE AVAILABLE TYPES OF JEWELRY FOR BOTH GENDERS CHOSE 5\n - TO GO BACK TO THE MAIN PAGE CHOSE 6\n");
    scanf("%d",&p);
    
    if (p==1)
    {
		system("cls");
		subsilver(); //calling function
    }
    else if (p==2)
    {
        system("cls");
        totalQuantitysilver();
    }
	else if (p==3)
    {
		system("cls");
        dollar();
    }
    else if (p==4)
    {
    	system("cls");
   		silver_wages(); //calling function
    }
	else if (p==5)
    {
        system("cls");
        type(); //calling function
	}
    else if (p==6)
    {
        goback();
    }
	 else
    {
    	system("cls");
		printf("wrong number please try again");
        fflush(stdin);
        silver_system();
    }
                    
}

void ingot ( )
{
    float x,y,h,m,result1,result2,result3,result4;
    int j,f,i,max=100;
	p:
    printf("HOW MANY INGOT DO YOU WANT TO ENTER? (MAX=100)\t");
    fflush(stdin);
    scanf("%d",&j);
    if (j>0&&j<max)
	{
	}
	else {
		system("cls");
		printf("wrong interd please again\n\n" );
		goto p;
	}

        for (i=0;i<j;i++)
            {

                printf("\nEnter the weight of the ingot : \t"); scanf("%f",&x);

                printf("1- Enter the gold caliber\t 2- Enter the silver caliber\t 3- Enter the copper caliber\n");
                scanf("%f %f %f", &y,&h,&m);

                result1=x*y;
                result2=x*h;
                result3=x*m;
                result4= result1 - result2 - result3;

                printf("1- the pure amount of gold in the ingot is : ( %f )\n 2- the pure amount of silver in the ingot is : ( %f )\n 3- the pure amount of the copper in the ingot is : ( %f )\n 4- the amount of the impurities in the ingot is  : ( %f )\n ", result1,result2,result3,result4);

            }
  goback();

}
void mainpage()
{
    int s;
    printf("\n_____________________________________\n");
    printf("CHOSE ONE OF THE FOLLOWING OPTIONS : \n\n ");


        printf("- FOR GOLD MANAGEMENT SYSTEM CHOSE 1 \n - FOE SILVER MANAGEMENT SYSTEM CHOSE 2\n - FOR INGOT ANALYSIS AND EXTRACTION  OF METAL VALUES CHOSE 3\n");
        scanf("%d",&s);

        if (s==1)
        {
             system("cls");

            // calling a function that has the gold management system in it.
            gold_system ();

        }
    else if (s==2)
    {
        system("cls");
        //calling a function that has the silver management system
        silver_system();
    }
   else if (s==3)
    {
    	system("cls");
       //calling function that analysis the ingot
    	ingot ( );
    }
   else
    {
        system("cls");	
        printf("wrong number please try again\n");
        fflush (stdin); //If the user has entered an invalid number, an error message will be printed and the options will be printed again.
        mainpage(); //recalling the function .
    }
    
}

void goback()
{
    int f,k;
    for (k=0;k<5;k++)
    {

        printf("\n \n \n to go back to the main page chose 1\n to exit chose 2\n");
   	    scanf("%d",&f);

	    if (f==1)
	    {
	        system("cls");
	        mainpage();
	        break;
	    }
	    else if (f==2)
	    {
	        printf("\n press any to exit");
	        exit(0);
	    }
	    else
	    {
	    	printf("\n wrong number please try again");
		}
}
}

////used this function to allocate memory that can be used several times and can be changed
Doca *allocatememory (Doca*p, int n)
{
    p = (Doca*) malloc(n*sizeof(Doca));
    return p;
}
void totalQuantitysilver()
{
	FILE *fp;
	float sum =0,result=0;
	float z,f;
	
	fp= fopen ("result.txt","r"); //read the numbers that has been saved in the result file which came from the sum of the out&in quantity differance
	
	while (fscanf(fp,"%f",&z)!=EOF)
	{
		sum+=z;
	}
	fclose(fp);
	
	printf("ENTER THE TOTAL QUANTITY OF THAT YOU HAVE IN THE BOX : ");
	scanf("%f",&f);
	result = f-sum;
	printf("the total Quantity diference is :  %f\n",sum);
	printf("the left quantity in the box is : %f\n",result);

	goback();
}

void subgold()
{
	float m,n,result=0,temp;
	int i,j;
	FILE *ptr;
	int x,max=100;
	
	printf("                                      WELCOME TO EVERYDAY TABLE                                              \n\n");
	p:
	printf("HOW MANY PIECE OF JEWELRY DO YOU WANT TO ENTER (MAX:100) : \t"); 
	fflush(stdin);
	scanf("%d",&x);
	if (x>0&&x<max)
	{
	}
	else {
		system("cls");
		printf("wrong interd please again\n\n" );
		goto p;
	}
	printf("\n\nDO YOU WANT TO START FROM THE BEGINING ? \t (Press 1 for yes Press 2 to countinue) : \t"); scanf("%d",&j);
	
	if (j==1)
	{
		ptr = fopen ("result1.txt","w"); 
		// the user could chose between deleting the file contant by using writing mood or keep them and add to them by chossing append mood.
	}
	else if (j==2)
	{
		ptr = fopen ("result1.txt","a");
	}
	for (i=0;i<x;i++)
	{
	    printf("OUT-QUANTITY\t "); scanf("%f",&m);
	        
	    printf("IN-QUANTITY\t"); scanf("%f",&n);
	        
	    temp = m-n;
	    result=result+temp;
	
	    printf("\n\n THE QUANTITY DIFERENCES IS  =  %f\n",temp);
	}
	
	printf("\n");
	
	fprintf(ptr,"%f ",result ); //the sum of the results will be saved in a file
	
	printf("\n THE TOTAL DIFERANCE QUANTITY IS = %f\n",result);
	fclose (ptr);
	goback();

}

void totalQuantitygold()
{
	FILE *fpr;
	float sum =0,result=0;
	float j,f;
	fpr= fopen ("result1.txt","r"); //read the numbers that has been saved in the result1  file which came from the sum of the out&in quantity differance
	while (fscanf(fpr,"%f",&j)!=EOF)
	{
		sum+=j;
	}
	fclose(fpr);
	
	printf("ENTER THE TOTAL QUANTITY OF THAT YOU HAVE IN THE BOX : ");
	scanf("%f",&f);
	
	result = f-sum;
	
	printf("the total Quantity diference is :  %f\n",sum);
	printf("the left quantity in the box is : %f\n",result);
	goback();
}


