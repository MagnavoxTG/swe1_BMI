#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    int x = 0;
    char gender;
    char heightreadout[10] = "";
    char weightreadout[10] = "";
    float height = 0, weight = 0, BMI = 0;

    while (x != 1) {
        // displays a message asking you for your gender and then write it into a char
        printf("\nEnter m for male and f for female: ");
        scanf("%c", &gender);

        // displays a message asking you for your height and writes it into a string
        printf("\nEnter your height in meter (f.e. 1.75): ");
        scanf("%s", heightreadout);

        //displays a message asking you for your weight and writes it into a string
        printf("\nEnter your wight in kg (f.e. 75.45): ");
        scanf("%s", weightreadout);

        // strspan checks how many of the specified character are inside the string and gives an integer
        // strlen checks how long the string (char array) is and gives an integer
        // if they are the same then there are only allowed characters in the string
        // if all the inputs are valid the BMi is calculated
        if ((strspn(heightreadout, "0123456789.") == strlen(heightreadout))
        && (strspn(weightreadout, "0123456789.") == strlen(weightreadout))
        && (gender == 'f' || gender =='m'))
            {
            // Casting the strings into floats
            height = (float)atof(heightreadout);
            weight = (float)atof(weightreadout);
            //BMI is calculated with kg/m²
            BMI = weight / (height * height);
            //switch that checks the gender
            switch(gender){
                case 'f':
                    // Checks BMI and then displays the corresponding message
                    if (BMI < 19) printf("Your BMI is %.f which means you are UNDERWEIGHT", BMI);
                    if (BMI >= 19 && BMI <= 24) printf("Your BMI is %.f which means you have normal weight", BMI);
                    if (BMI > 24 && BMI <= 30) printf("Your BMI is %.f which means you are OVERWEIGHT", BMI);
                    if (BMI > 30 && BMI <= 41) printf("Your BMI is %.f which means you are suffering from OBESITY", BMI);
                    if (BMI > 41) printf("Your BMI is %.f which means you are suffering from MASSIVE OBESITY", BMI);
                    break;
                case 'm':
                    // Checks BMI and then displays the corresponding message
                    if (BMI < 20) printf("Your BMI is %.f which means you are UNDERWEIGHT", BMI);
                    if (BMI >= 20 && BMI <= 25) printf("Your BMI is %.f which means you have normal weight", BMI);
                    if (BMI > 25 && BMI <= 30) printf("Your BMI is %.f which means you are OVERWEIGHT", BMI);
                    if (BMI > 30 && BMI <= 41) printf("Your BMI is %.f which means you are suffering from OBESITY", BMI);
                    if (BMI > 41) printf("Your BMI is %.f which means you are suffering from MASSIVE OBESITY", BMI);
                    break;
                //this code is unreachable but for the sake of it I still but it in
                default:
                    break;
            }
            //breaking the while
            x = 1;
        } else {
            // displaying error message for using invalid characters in the input
            printf("invalid input");
        }
    }
}