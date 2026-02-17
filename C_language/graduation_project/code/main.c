/*******************************************************************************************/
/*******************************************************************************************/
/**************************** << BANK MANAGMENT SYSTEM PROJECT>> ***************************/
/*******************************************************************************************/
/*******************************************************************************************/





#include  <stdio.h>
#include  "std_types.h"
#include  "text_colors.h"
#include  "sys.h"
#include "interface_def.h"








int main(){

    uint_8 choice ;

    while(choice != _3rd_op ){

        printf(__yellow__"\n\n\n\n\n\n CUSTOMER ACCOUNT BANKING MANAGMENT");
        printf(__grey__"\n\tWELCOME TO THE MENUE\n");
        printf(__green__);
        printf("\n\n\n1.Admin window");
        printf("\n2.User window");
        printf("\n3.Close system");
        printf("\n\n\n\n\nEnter your choice:");
        fflush(stdin);
        scanf(" %c",&choice);

        switch (choice)
        {
            case _1st_op : admin_window() ; break;
            case _2nd_op : user_window()  ; break;
            case _3rd_op : printf(__bg_blue__"\n\n\tSYSTEM CLOSED\n\n")  ; break;

            default: printf(__red__"\n\tInvalid Choice"); break;          
                    
        }   
    }

}












