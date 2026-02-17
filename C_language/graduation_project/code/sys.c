/**************************** @author sherif osama abdelkareem   ********************* */
/**************************** @date     10Feb26                  ********************* */
/**************************** @file     sys.c                    ********************* */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "std_types.h"
#include "text_colors.h"
#include "interface_def.h"
#include "sys.h"
#include <conio.h> 






custmer_account  customers[MAX_CUSTOMERS_NUMBER];
uint_16 index_of_array  = starting_of_array ;      // looping @ array 





void admin_window (void){
    
    uint_8  choice ;
    uint_32 ID_CHECK ;
    uint_8  PASS_CHECK[MAX_PASSWORD_SIZE];
    uint_8 ch ;
    uint_16 i ;

    printf(__grey__"\nEnter admin ID :");
    fflush(stdin);
    scanf("%u",&ID_CHECK);

    printf(__grey__"\nEnter admin password :");

    // getchar();         // eat the '\n'
    // fgets(PASS_CHECK,MAX_PASSWORD_SIZE,stdin);
    // PASS_CHECK[strcspn(PASS_CHECK, "\n")] = 0;

    i = 0 ;
    while(i < MAX_PASSWORD_SIZE){
        ch = getch();
        if(ch == 13){  // check if char is enter '\n'
            PASS_CHECK[i]='\0';
            break;
        }else if(ch == 8){ // check if char is backspace'\b'
            if (i > 0){ 
             i--;
             printf("\b \b");
            }
        }else {
            PASS_CHECK[i++] = ch ; 
            printf("*");
        }
    }


    if(ID_CHECK == ADMIN_ID  &&  !strcmp(PASS_CHECK,ADMIN_PASS)){
        
        while (choice != _3rd_op){
    
            printf(__yellow__ "\n\n\n\n\t\t\t\t\tWELCOME IN ADMIN WINDOW\n\n\n\n");
            printf(__green__"\t1.Create New Account\n") ;
            printf(__green__"\t2.Open Existing Account\n") ;
            printf(__green__"\t3.Return to main menue\n") ;

            printf("\n\n\n\n\tEnter your choice:");
            fflush(stdin);
            choice = getchar();

            switch (choice)
            {
                case _1st_op : 
                create_account(); 
                break;

                case _2nd_op :
                 open_existing_account();
                 break;

                case _3rd_op : 
                printf(__grey__"\n\n\tEXISTING....");
                break;

                default:
                printf(__red__"\n\n\n\tInvalid Choise");
                break;
            }
        }     
    }else {
        printf (__red__"\n\n\t id or password incorrect..try again !\n\n") ;
    }
}


/*-------------------------------------------------------------------------------------------------------*/


void create_account(void){

    if(index_of_array < MAX_CUSTOMERS_NUMBER){

        uint_64 National_ID ;
        uint_16 Iteration_array ; 
        uint_16 CHECK_CUSTOMER_FOUND_FLAG = NOT_FOUND ;
        
        printf(__black__"\n\n\tEnter customer national ID:");
        scanf("%llu",&National_ID);
        
        for (Iteration_array = starting_of_array ; Iteration_array < index_of_array ; ++Iteration_array){
            if(customers[Iteration_array].National_ID == National_ID){
                CHECK_CUSTOMER_FOUND_FLAG = FOUND ;
                break;
            }
        }
        
        if (CHECK_CUSTOMER_FOUND_FLAG == NOT_FOUND){


            customers[index_of_array].National_ID = National_ID ;

            printf("\n\n\tEnter customer full name:");
            getchar() ;      // eat any '\n'
            fgets(customers[index_of_array].Full_Name, MAX_LETTERS_NAME_NUMBER,stdin);

            printf("\n\n\tEnter customer address:");
            getchar() ;      // eat any '\n'
            fgets(customers[index_of_array].Address, MAX_LETTERS_ADDRESS_NUMBER,stdin);

            printf("\n\n\tEnter customer data of birth(DD MM YYYY):");
            fflush(stdin);
            scanf("%s %s %s",&customers[index_of_array].date.day,&customers[index_of_array].date.month,&customers[index_of_array].date.year);
            
            printf("\n\n\tEnter customer phone number(+20):");
            scanf("%d",&customers[index_of_array].Phone_Number);

            printf("\n\n\tEnter Age:");
            scanf("%d",&customers[index_of_array].Age);

            customers[index_of_array].Bank_Account_ID = DEFAULT_ACCOUNT_ID(customers[index_of_array].National_ID);
            strcpy(customers[index_of_array].Password,ACCOUNT_DEFUALT_PASSWORD);
            customers[index_of_array].Balance =  DEFAULT_BALANCE ;
            customers[index_of_array].Account_Status = active ;

            printf(__green__"\n\n\tCUSTOMER WAS ADDED SUCCSESSFULLY!\n\n\n\n");

            printf(__black__"=================================================\n");
            printf(__yellow__"             CUSOTOMER DATA LIST                \n");
            printf(__black__"=================================================\n\n\n");

            printf ( __black__ );
            printf ("Your name : %s\n"              , customers [index_of_array].Full_Name) ;
            printf ("Your address : %s\n"           , customers [index_of_array].Address) ;
            printf ("Your National ID : %llu\n"     , customers [index_of_array]. National_ID) ;
            printf ("Your Age : %u\n"               , customers [index_of_array]. Age) ;
            printf ("Your phone number : %d\n"      , customers[index_of_array].Phone_Number);
            printf ("Your Balance : %llu\n"         , customers [index_of_array]. Balance) ;
            printf ("Your Password : %s\n"          , customers[index_of_array].Password) ;
            printf ("Your Bank Account ID : %llu\n" , customers [index_of_array].Bank_Account_ID) ;
            printf ("Your data of birht : %s/%s/%s\n" ,customers[index_of_array].date.day,customers[index_of_array].date.month,customers[index_of_array].date.year) ;
            printf ("Your account status is %s\n"    ,customers[index_of_array].Account_Status?"active":"dormant");

           index_of_array ++ ;

        }else{

             printf(__red__"\n\n\tSORRY THIS ACCOUNT IS REGISTERED\n\n\n");
        }
       
    }else {
        
        printf(__red__"\n\n\tSORRY CAN NOT ADD THIS ACCOUNT\n\t  THERE IS NO EMPTY PLACE\n\n\n\n");
    }

}


/*-------------------------------------------------------------------------------------------------------*/



void open_existing_account(){


    uint_64 ACC_ID ;
    uint_16 Iteration_array ; 
    uint_16 CHECK_CUSTOMER_FOUND_FLAG = NOT_FOUND ;


    printf("\n\n\tEnter bank account ID :");
    fflush(stdin);
    scanf("%llu",&ACC_ID);

     for (Iteration_array = starting_of_array ; Iteration_array < index_of_array ; Iteration_array++) {
            if(customers[Iteration_array].Bank_Account_ID == ACC_ID){
                CHECK_CUSTOMER_FOUND_FLAG = FOUND ;
                break;
            }
    }


    if(CHECK_CUSTOMER_FOUND_FLAG == NOT_FOUND){
        printf(__red__"\n\n\t\t\t\tTHIS ACCOUNT ID NOT FOUND");
    }else{

        uint_8 choice ;

        while (choice != _5th_op)
        {
            printf(__yellow__"\n\nSELECT ACTION\n");
            printf(__grey__"1.Make transaction\n");
            printf(__grey__"2.Make withdrow\n");
            printf(__grey__"3.Make deposit\n");
            printf(__grey__"4.Change account status\n");
            printf(__grey__"5.Back into previous menue\n");
            printf("\n\n\nEnter your choice :");
            fflush(stdin);
            choice = getchar();

            switch (choice)
            {
                case _1st_op:
                    transfer_money(Iteration_array);
                    break;

                case _2nd_op:
                    make_withdrow(Iteration_array);
                    break;

                case _3rd_op:
                    make_deposit(Iteration_array);
                    break;

                case _4th_op:
                    change_account_status(Iteration_array);
                    break;

                case _5th_op:
                    /*NO THING */
                    break;
                
                default:
                    printf(__red__"\n\t\t\t\t\tInvalid choice"); 
                    break;
            }
        }
    }
}



/*-------------------------------------------------------------------------------------------------------*/



 void transfer_money(uint_16 Iteration_array ){

    uint_64  ACC_ID ;
    uint_16 ITS_Iteration_array ;
    uint_16 CHECK_CUSTOMER_FOUND_FLAG = NOT_FOUND ;
    f_64 TRANS_CASH ;

    printf(__grey__"\n\nEnter bank account ID you want to transfer money to : ");
    scanf("%llu",&ACC_ID);

    for(ITS_Iteration_array = starting_of_array ; ITS_Iteration_array < index_of_array ; ITS_Iteration_array ++){

        if(customers[ITS_Iteration_array].Bank_Account_ID == ACC_ID){
            CHECK_CUSTOMER_FOUND_FLAG = FOUND;
            break;
        }
    }

    if(CHECK_CUSTOMER_FOUND_FLAG == FOUND){

        if(customers[ITS_Iteration_array].Account_Status == active){
            L1 : printf("\n\tEnter the amount of money you want to transfer:");
            scanf("%lf",&TRANS_CASH);
            if(TRANS_CASH < 0){
               printf(__red__"\n\n\tCASH CAN NOT BE NEGATIVE !");
               goto L1 ;
            }
            if(customers[Iteration_array].Balance >= TRANS_CASH){
                customers[Iteration_array].Balance -= TRANS_CASH;
                customers[ITS_Iteration_array].Balance += TRANS_CASH;
                printf(__green__"\n\n\t\t\t\tMONEY TRANSFERED SUCCESSFULLY");
            }else{
                printf(__red__"\n\n\t\t\t\tTHERE IS NOT ENOUGH BALANCE !");
            }

        }else{
          printf(__red__"\n\n\t\t\t\tTHIS ACCOUNT IS DORMANT\n\t\t\tYOU CAN NOT DO ANY OPERATION NOW\n");
        }


    }else{
        printf(__red__"\n\n\t\t\t\tTHIS ACCOUNT ID NOT FOUND");
    }

 }


 /*-------------------------------------------------------------------------------------------------------*/


  void make_withdrow(uint_16 Iteration_array){

       if(customers[Iteration_array].Account_Status == active ){

            f_64 cash ;

           L1: printf("\n\tEnter the amount of money you want to get :");
            scanf("%lf",&cash);
            if(cash < 0){
            printf(__red__"\n\n\tCASH CAN NOT BE NEGATIVE !");
            goto L1 ;
            }

            if(customers[Iteration_array].Balance >= cash){
                customers[Iteration_array].Balance -= cash;
                printf (__green__"\n\n\tOPOERATION COMPLETED SUCCESSFULLY\n") ;
                printf ("\tNow your cash is : %lf \n" , customers[Iteration_array].Balance) ;

            }else{
                printf(__red__"\n\n\tTHERE IS NOT ENOUGH BALANCE !");
            }

        }else{
            printf(__red__"\n\n\tTHIS ACCOUNT IS DORMANT\n\tYOU CAN NOT DO ANY OPERATION NOW\n");
        }
  }


/*-------------------------------------------------------------------------------------------------------*/
  

   void make_deposit(uint_16 Iteration_array){

        if(customers[Iteration_array].Account_Status == active){

            f_64 cash ;

            L1 : printf("\n\tEnter the amount of money you want to add :");
                scanf("%lf",&cash);
                if(cash < 0){
                printf(__red__"\n\n\t\tCASH CAN NOT BE NEGATIVE !");
                goto L1 ;
                }

            customers[Iteration_array].Balance += cash ;
            
            printf (__green__"\n\n\tOPOERATION COMPLETED SUCCESSFULLY\n") ;
            printf ("\tNow your cash is : %lf \n" , customers[Iteration_array].Balance) ;

       }else{
            printf(__red__"\n\n\tTHIS ACCOUNT IS DORMANT\n\tYOU CAN NOT DO ANY OPERATION NOW\n");
        }
}

   
/*-------------------------------------------------------------------------------------------------------*/


 void change_account_status(uint_16 Iteration_array){

    uint_8  choice;
	
	printf (__yellow__"SELECT ACTION :\n\n") ;
    printf ("1.Set Account to active State\n") ;
    printf ("2.Set Account to dormant State\n") ;
    printf ("3.Delete Account\n") ;
    printf ("\n\n\nEnter your choice : ") ;

    fflush (stdin) ;
    choice = getchar();
	
	if (choice == _1st_op){
    	customers[Iteration_array].Account_Status = active ;
		printf (__green__"\n\n\tThe account has been activated successfully\n") ;
    }else if (choice == _2nd_op){
    	customers[Iteration_array].Account_Status = dormant ;
		printf (__green__"\n\n\tThe account has been restricted successfully\n") ;
    }else if (choice == _3rd_op){

		for (uint_8 index = Iteration_array  ; index < PRE_ELEMENT(index_of_array) ; index ++){
		    	customers[index] = customers[NEXT_ELEMENT(index)] ;
		    }
		printf (__green__"\n\n\tThe account has been deleted successfully\n") ;

        index_of_array -- ;
    }else{
    	printf (__red__"\n\n\n\tInvalid Choice\n\n\n") ;
    }

 }


 /*-------------------------------------------------------------------------------------------------------*/


 void user_window(void){

    uint_64 ID_CHECK ;
    uint_8 PASS_CHECK[MAX_PASSWORD_SIZE];
    uint_16 iter_arr ;
    uint_16 CHECK_CUSTOMER_FOUND_FLAG = NOT_FOUND ;
    uint_8 ch ;
    uint_16 i ;

    
    printf(__grey__"\n\tEnter your account ID :");
    scanf("%llu",&ID_CHECK);

    printf(__grey__"\n\tEnter your password :");
    // getchar();         // eat the '\n'
    // fgets(PASS_CHECK,MAX_PASSWORD_SIZE,stdin);

     i = 0 ;
    while(i<MAX_PASSWORD_SIZE){
        ch = getch();
        if(ch == 13){
            PASS_CHECK[i]='\0';
            break;
        }else if(ch == 8) {
            if (i > 0) { 
             i--;
             printf("\b \b");
            }
        }else {
            PASS_CHECK[i++] = ch ; 
            printf("*");
        }
    }

    for(iter_arr = starting_of_array ; iter_arr < index_of_array ; iter_arr ++){

        if(customers[iter_arr].Bank_Account_ID == ID_CHECK){
            CHECK_CUSTOMER_FOUND_FLAG = FOUND ;
            break;
        }
    }

    if(CHECK_CUSTOMER_FOUND_FLAG == FOUND ){

        if(!strcmp(customers[iter_arr].Password , PASS_CHECK)){

            uint_8 choice ;    
                       
            while (choice != _6th_op){

                printf(__yellow__"\n\nSELECT ACTION : \n\n");
                printf(__grey__"1.Make transaction\n");
                printf(__grey__"2.Make withdrow\n");
                printf(__grey__"3.Make deposit\n");
	            printf(__grey__"4.Change Account Password\n") ;
	            printf(__grey__"5.display_info\n") ;
                printf(__grey__"6.Back into main menue\n");
                printf("\n\n\nEnter your choice :");
            
                fflush (stdin) ;
                scanf  (" %c" ,&choice) ;

                    
                switch (choice)
                {
                    case _1st_op:
                        transfer_money(iter_arr);
                        break;

                    case _2nd_op:
                        make_withdrow(iter_arr);
                        break;

                    case _3rd_op:
                        make_deposit(iter_arr);
                        break;

                    case _4th_op:
                        change_password(iter_arr);
                        break;

                    case _5th_op:
                        display_info(iter_arr);
                        break;

                    
                    case _6th_op:
                         /* NO THING */
                         break;
                    
                    default:
                        printf(__red__"\n\t\t\t\t\tInvalid Choice"); 
                        break;
                }
                
            }

        }else{
            printf(__red__"\n\n\t\t\t\tINVALID ENTERED PASSWORD");
        }

    }else{
        printf(__red__"\n\n\t\t\t\tTHIS ACCOUNT ID NOT FOUND");
    }
 }



/*-------------------------------------------------------------------------------------------------------*/


void change_password(uint_16 iter_arr){

    uint_8 PASS1[MAX_PASSWORD_SIZE];
    uint_8 PASS2[MAX_PASSWORD_SIZE];

    printf(__grey__"\n\nEnter your new password :");
    fflush(stdin);
    fgets(PASS1,MAX_PASSWORD_SIZE,stdin);
    PASS1[strcspn(PASS1, "\n")] = 0;


    printf(__grey__"\n\nEnter your new password again :");
    fflush(stdin);
    fgets(PASS2,MAX_PASSWORD_SIZE,stdin);
    PASS2[strcspn(PASS2, "\n")] = 0;


    if(!strcmp(PASS1,PASS2)){

        strcpy(customers[iter_arr].Password , PASS1);
        printf(__green__"\n\n\n\t\t\t\tPASSWORD CHANGED SUCCESSFULLY");

    }else{
        printf(__red__"\n\n\n\tTHE TWO PASSWORD NOT THE SAME..TRY AGAIN");
    }
}


/*-------------------------------------------------------------------------------------------------------*/


void display_info(uint_16 iter_arr){


        printf(__black__"=================================================\n");
        printf(__yellow__"             CUSOTOMER DATA LIST                \n");
        printf(__black__"=================================================\n\n\n");

        printf ( __black__ );
        printf ("Your name : %s\n"                , customers [iter_arr].Full_Name) ;
        printf ("Your address : %s\n"             , customers [iter_arr].Address) ;
        printf ("Your National ID : %llu\n"       , customers [iter_arr].National_ID) ;
        printf ("Your Age : %u\n"                 , customers [iter_arr].Age) ;
        printf ("Your phone number : %d\n"        , customers[iter_arr].Phone_Number);
        printf ("Your Balance : %lf\n"            , customers [iter_arr].Balance) ;
        printf ("Your Password : %s\n"            , customers[iter_arr].Password) ;
        printf ("Your Bank Account ID : %llu\n"   , customers [iter_arr].Bank_Account_ID) ;
        printf ("Your data of birht : %s/%s/%s\n" ,customers[iter_arr].date.day,customers[iter_arr].date.month,customers[iter_arr].date.year) ;
        printf ("Your account status is %s\n"     ,customers[iter_arr].Account_Status?"active":"dormant");

}




 
