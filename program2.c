/*
 
 Program: <Conversions>
 Author: Priyam Patel
 Date: <April 14th 2015>
 Time Spent: <2 days>
 Purpose: The purpose of this program is to convert lengths and weights from either
          the metric unit or the U.S system of units. The user can enter any amount they
          wish and the program will compute their results.
 */

#include <stdio.h>

void ask_user();

void convert_lengths(int *choice); //displays message that shows user chose to convert lengths

void convert_weights(int *choice); //displays message that shows user chose to convert weights

void length_to_metric(); //displays message that shows user chose to convert U.S. to metric
void input_length_metric(); //user inputs number of ft and inches
void conversion_length_metric(int *p_feet, double *p_inches); //function converts to metric units
void output_length_metric(int *p_feet, double *p_inches, int result_meters, double centimeters_result);//displays final result of kg and g

void length_to_us();
void input_length_us();
void conversion_length_us(int *p_meters, double *p_centimeters);
void output_length_us(int *p_meters, double *p_centimeters, int result_feet, double inches_result);

void weight_to_us(); // displays message that shows user chose to convert to U.S. system
void input_weight_us(); // user inputs number of kg and g
void conversion_weight_us(int *p_kg, double *p_g);// function converts to U.S. system
void output_weight_us(int *p_kg, double *p_g, int result_lbs, double result_oz); //displays final number of feet and inches

void weight_to_metric();
void input_weight_metric();
void conversion_weight_metric(int *p_lbs, double *p_oz);
void output_weight_metric(int *p_lbs, double *p_oz, int result_kg, double result_g);

void clear_keyboard_buffer(void); //clear keyboard buffer function

int main (int argc, char * argv[])
{
    int choice;
    do
    {
        ask_user(&choice);
    }
    while (choice != 0);
    return 0;
}

void ask_user(int *choice)
{
    printf("Would you like to convert lengths or weights?:");
    printf("Enter 1 for lengths, 2 for weights, or 0 to end program.\n");
    printf("(1)\n");
    printf("(2)\n");
    scanf("%d", choice);
    clear_keyboard_buffer();
    while (*choice != 1 && *choice != 2 && *choice != 0) //if user does not choose 0/1/2, lets them try again
    {
        printf("I do not understand your choice.\n");
        printf("Enter 1 for lengths, 2 for weights, or 0 to end program.\n");
        printf("Enter 1 for lengths or 2 for weights\n");
        printf("(0)\n");
        printf("(1)\n");
        printf("(2)\n");
        scanf("%d", choice);
        clear_keyboard_buffer();
        if (*choice !=0 && *choice != 1 && *choice != 2 )
        {
            printf("I do not understand your choice.\n");
            printf("Enter 1 for lengths, 2 for weights, or 0 to end program.\n");
            printf("Enter 1 for lengths or 2 for weights\n");
            printf("(0)\n");
            printf("(1)\n");
            printf("(2)\n");
            scanf("%d", choice);
            clear_keyboard_buffer();
        }
        
    }
    if (*choice==1) //if choice is one, convert lengths
    {
        convert_lengths(choice);
    }
    if (*choice==2)
    {
        convert_weights(choice);
    }
    if (choice==0) //if choice is zero, end program
    {
        choice = 0;
    }
}

void convert_lengths(int *choice)
{
    
    printf("You chose to convert to lengths\n");
    printf("Do you want to convert from feet/inches to meters/centimeters (1) or from meters to centimeters to feet/inches (2) ?:\n");
    printf("(1)\n");
    printf("(2)\n");
    scanf("%d", choice);
    
    if (*choice==1) //if choice is one, convert U.S==>metric
    {
        length_to_metric();
        *choice = 1;
    }
    if (*choice==2)
    {
        length_to_us();
        *choice = 1;
    }
    if (*choice==0) //goes back to asking user convert lengths/weights
    {
        *choice = 0;
    }
    
}
void length_to_metric()
{
    printf("You chose to convert from feet/inches to meters/centimeters!\n");
    input_length_metric();
}
void input_length_metric()
{
    int feet;
    double inches;
    printf("Please enter the number of feet:\n");
    scanf("%d", &feet);
    while (feet <= 0)
    {
        printf("Enter a distance greater than zero");
        scanf("%d", &feet);
        clear_keyboard_buffer();
    }
    printf("Please enter the number of inches:\n");
    scanf("%lf", &inches);
    while (inches <= 0)
    {
        printf("Enter a distance greater than zero");
        scanf("%lf", &inches);
        clear_keyboard_buffer();
    }
    conversion_length_metric(&feet, &inches);
}
void conversion_length_metric(int *p_feet, double *p_inches)
{
    double feet_to_meters = *p_feet * 0.3048; //0.3048m in 1ft
    double inches_to_meters = (*p_inches/12) * .3048;//divide inches by 12 (12inch==1ft) and multiply by 0.3048
    double total_meters = inches_to_meters + feet_to_meters;
    int result_meters = inches_to_meters + feet_to_meters;
    double centimeters_result = (total_meters-result_meters)*100;
    output_length_metric(p_feet, p_inches, result_meters, centimeters_result);

}
void output_length_metric(int *p_feet, double *p_inches, int result_meters, double centimeters_result) //output message
{
    printf("%d feet and %lf inches is equivalent to %d meters and %lf centimeters\n", *p_feet, *p_inches, result_meters, centimeters_result);
}
void length_to_us()
{
    printf("You chose to convert from meters/centimeters to feet/inches!\n");
    input_length_us();
}
void input_length_us()
{
    int meters;
    double centimeters;
    printf("Please enter the number of meters:\n");
    scanf("%d", &meters);
    clear_keyboard_buffer();
    while (meters <= 0)
    {
        printf("Enter a positive distance or one that is greater than zero\n");
        scanf("%d", &meters);
        clear_keyboard_buffer();
    }
    printf("Please enter the number of centimeters\n");
    scanf("%lf", &centimeters);
    while (centimeters <= 0)
    {
        printf("Enter a positive distance or one that is greater than zero\n");
        scanf("%lf", &centimeters);
        clear_keyboard_buffer();
    }
    
    conversion_length_us(&meters, &centimeters);
}
void conversion_length_us(int *p_meters, double *p_centimeters)
{
    double meters_to_feet = *p_meters / .3048;
    double centimeters_to_feet = (*p_centimeters/100) / .3048;
    double total_feet = meters_to_feet + centimeters_to_feet;
    int result_feet = meters_to_feet + centimeters_to_feet;
    double inches_result = (total_feet-result_feet) * 12;
    output_length_us(p_meters, p_centimeters, result_feet, inches_result);


}
void output_length_us(int *p_meters, double *p_centimeters, int result_feet, double inches_result)
{
    printf("%d meters and %lf centimeters is equivalent to %d feet and %lf inches\n", *p_meters, *p_centimeters, result_feet, inches_result);
}
void convert_weights(int *choice)
{
    
    printf("You chose to convert to weights\n");
    printf("Do you want to convert from pounds/ounces to kilograms/grams (1) or from kilograms/grams to pounds/ounces (2) ?:\n");
    printf("(1)\n");
    printf("(2)\n");
    scanf("%d", choice);
    
    if (*choice==1)
    {
        weight_to_metric();
        *choice = 1;
    }
    if (*choice==2)
    {
        weight_to_us();
        *choice = 1;
    }
    if (*choice==0)
    {
        *choice = 0;
    }
    
}
void weight_to_us()
{
    printf("You chose to convert from kilograms/grams to pounds/ounces!\n");
    input_weight_us();
}
void input_weight_us()
{
    int kg;
    double g;
    printf("Please enter the number of kilograms:");
    scanf("%d", &kg);
    clear_keyboard_buffer();
    while (kg <= 0)
    {
        printf("Enter a positive number or one that is greater than zero:\n");
        scanf("%d", &kg);
        clear_keyboard_buffer();
    }
    printf("Please enter the number grams:");
    scanf("%lf", &g);
    clear_keyboard_buffer();
    while (g <= 0)
    {
        printf("Enter a positive number or one that is greater than zero:\n");
        scanf("%lf", &g);
        clear_keyboard_buffer();
    }
    conversion_weight_us(&kg, &g);
}
void conversion_weight_us(int *p_kg, double *p_g)
{
    double kg_to_lbs = *p_kg * 2.2046;
    double g_to_lbs = (*p_g/1000) * 2.2046;
    double result_amount = kg_to_lbs + g_to_lbs;
    int result_lbs = kg_to_lbs + g_to_lbs;
    double result_oz = (result_amount - result_lbs) * 16;
    output_weight_us(p_kg, p_g, result_lbs, result_oz);
}
void output_weight_us(int *p_kg, double *p_g, int result_lbs, double result_oz)
{
    printf("%d kilograms and %f grams is equivalent to %d pounds and %f ounces.\n", *p_kg, *p_g, result_lbs, result_oz);
}

void weight_to_metric()
{
    printf("You chose to convert from pounds/ounces to kilograms/grams!\n");
    input_weight_us();
}
void input_weight_metric()
{
    int lbs;
    double oz;
    printf("Please enter the number of pounds: ");
    scanf("%d", &lbs);
    clear_keyboard_buffer();
    while (lbs <= 0)
    {
        printf("Please enter a positive weight:");
        scanf("%d", &lbs);
        clear_keyboard_buffer();
    }
    
    printf("Please enter the number of ounces: ");
    scanf("%lf", &oz);
    clear_keyboard_buffer();
    while (oz <= 0)
    {
        printf("Please enter a positive weight:");
        scanf("%lf", &oz);
        clear_keyboard_buffer();
    }
    conversion_weight_metric(&lbs, &oz);
}
void conversion_weight_metric(int *p_lbs, double *p_oz)
{
    double lbs_to_kg = *p_lbs / 2.2046;
    double oz_to_kg = (*p_oz/16) / 2.2046;
    double amount_total = lbs_to_kg +oz_to_kg;
    int result_kg = lbs_to_kg + oz_to_kg;
    double result_g = (amount_total - result_kg)  * 100;
    output_weight_us(p_lbs, p_oz, result_kg, result_g);
}
void output_weight_metric(int *p_lbs, double *p_oz, int result_kg, double result_g)
{
    printf("%d pounds and %f ounces is equivalent to %d kilograms and %f grams.\n", *p_lbs, *p_oz, result_kg, result_g);
    
    
}
void clear_keyboard_buffer(void)
{
    char c;
    scanf("%c", &c);
    while(c != '\n')
    {
        scanf("%c", &c);
    }
    return;
}