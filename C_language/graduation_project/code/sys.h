/**************************** @author sherif osama abdelkareem   ********************* */
/**************************** @date     10Feb26                  ********************* */
/**************************** @file     sys.h                    ********************* */





#ifndef      _SYS_H_
#define      _SYS_H_




/**
 * @brief Displays the administrative control panel.
 * 
 * 
 */

void admin_window(void);


/**
 * @brief  adds a new customer account to the system.
 * 
 * 
*/

void create_account(void);


/**
 *  @brief Searches for and opens a specific existing account.
 * 
 * 
**/

void open_existing_account(void);


/**
 * @brief Transfers funds between two distinct accounts.
 * @param Iteration_array ->  The index of the source account in the database.
 * @note This function will prompt for the recipient's Account ID 
 * and verify sufficient balance before proceeding.
 */

void transfer_money(uint_16 Iteration_array);

/**
 * @brief Deducts a specific amount from an account balance.
 * @param Iteration_array -> The index of the account in the database.
 * @note Operation is only permitted if the account is 'active' and 
 * has sufficient funds.
 */

void make_withdrow(uint_16 Iteration_array);


/**
 * @brief Adds a specific amount to an account balance.
 * @param Iteration_array -> The index of the account in the database.
 * @note Operation is restricted if the account status is 'dormant' or 'closed'.
 */

void make_deposit(uint_16 Iteration_array);



/**
 * @brief Toggles or sets the status of a specific account.
 * @param Iteration_array -> The index of the account in the database.
 * @note Statuses typically include: Active, Dormant, or Closed.
 */

void change_account_status(uint_16 Iteration_array);



/**
 * @brief Displays the standard user interface for customers.
 * * Provides a restricted menu where customers can view their own info,
 * change passwords, or perform basic transactions after logging in.
 */

void user_window(void);



/**
 * @brief Updates the security password for a specific account.
 * * @param iter_arr The index of the account in the database.
 * * @note Usually requires verification of the old password or administrative override.
 */

void change_password(uint_16 iter_arr);


/**
 * @brief Prints all public and private details of a specific account.
 * @param iter_arr -> The index of the account in the database.
 * @note Displays Name, ID, Status, Balance, and Date of Birth.
 */

void display_info(uint_16 iter_arr);




#endif  /*_SYS_H_*/