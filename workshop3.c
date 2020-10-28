// Programming fundamental assignment 
// initialize libraries
#include<stdio.h>  
#include<math.h>
#include<stdlib.h>
// create stucture with different field
struct Vehicle {
	   int  Vehicle_Number;
	   char Vehicle_Manufacturer[20]; // limit character to 20 character
	   char Vehicle_Name[10];         // limit the character to 10 character
	   int  First_Manufactured;
	   float Top_Speed;
	   int  Number_of_Seats;
	   float Mass;
};

// define function to search the vehicle number in vehicle info array

int find_index(struct Vehicle Vehicle_info[], int num_elements, int value)
{
   int i;
   for (i=0; i<num_elements; i++)
   {
	 if (Vehicle_info[i].Vehicle_Number == value)
	 {
	    return(i);  /* it was found and return index value*/ 
	 }
   }
   return(-1);  /* if it was not found */
}
// function to calculate the impact force using previous work 
float impact_force(float mass, float velocity_mps, float stopping_distance)
{
	float force;
	force = (0.5)* mass * pow(velocity_mps,2)/ stopping_distance;
	return force;
	
}
int main()
{   
   // initialize the five value in array;
	int i, num_vehicle;
	int choice;
	 struct Vehicle Vehicle_info[50]={ {1,"Toyata", "Camry", 1991, 200, 5, 1100},
                         { 2,"Bugati", "Veyron", 2005, 415, 2, 1888 },
						 { 3,"Alexander", "Environ", 2005, 129, 9, 1800 },
						 { 4,"Hyundai", "Elantra", 2014, 100, 5, 1200 },
						 { 5,"Hyundai", "Corola", 1998, 150, 5, 1800 }
	                   };  
	
    printf("Do you want to add Vehicle Press 1 or 0 for No: "); // give user choice to add vehicle data or not BONUS WORK
	scanf("%d", &choice);
	
	if (choice == 1)
	{
	 
	 printf("Enter the Number of Vehicle want to add : ");
	 scanf("%d", &num_vehicle);
	 // Initialize loop to allow user to add number of vehicles
	 
	 for(i= 0; i < num_vehicle; i++)
	 {
	  
	  printf("Enter the Vehicle detail %d\n\n", i+1);
	  printf("Enter the Vehicle_Number: ");
	  scanf("%d", &Vehicle_info[i+5].Vehicle_Number);
	  
	  printf("Enter the Vehicle_Manufacturer: ");
	  scanf("%s", Vehicle_info[i+5].Vehicle_Manufacturer);
	  
	  //printf("\n");
   	  printf("Enter the Vehicle_Name: ");
	  scanf("%s", Vehicle_info[i+5].Vehicle_Name);
	  
	  printf("Enter the First_Manufactured: ");
	  scanf("%d", &Vehicle_info[i+5].First_Manufactured);
	  
	  printf("Enter the Top_Speed: ");
	  scanf("%f", &Vehicle_info[i+5].Top_Speed);
	  
	  printf("Enter the Number_of_Seats: ");
	  scanf("%d", &Vehicle_info[i+5].Number_of_Seats);
	  
	  printf("Enter the Mass: ");
	  scanf("%f", &Vehicle_info[i+5].Mass);
	  }
	}
	
	printf("\n");
	// Print the available vehicle information in the data and also add the new vehicle detail
	int total_vehicle = 7 ;
	total_vehicle = total_vehicle + num_vehicle;
	
	printf("Vehicle_Number  Vehicle_Manufacturer Vehicle_Name First_Manufactured  Top_Speed Number_of_Seats Mass \n");

	for(i = 0; i < total_vehicle; i++ )
	{
		printf("%6d\t%12s\t%14s\t%10d\t%16f\t%6d\t%17f\n", 
		Vehicle_info[i].Vehicle_Number, Vehicle_info[i].Vehicle_Manufacturer,
		Vehicle_info[i].Vehicle_Name, Vehicle_info[i].First_Manufactured,
		Vehicle_info[i].Top_Speed, Vehicle_info[i].Number_of_Seats,
		Vehicle_info[i].Mass);
	}
	
	float max_velocity, stopping_distance;
	
	
    printf("Please enter maximum velocity(in km/h): ");
    scanf("%f", &max_velocity);
    printf("\n");
    printf("Please enter stopping_distance(on m): ");
    scanf("%f", &stopping_distance);
    printf("\n"); 
   
   // Error display message for invalid input
   if ( max_velocity<=0 || stopping_distance <=0){
	   
	   printf("ERROR: Data entered is invalid!\n");
	   exit(0);
    }
	int Vehicle_Num, index;
   do
   {
	 printf("Enter the Vehicle_Number or to exist enter -1: ");
	 scanf("%d", &Vehicle_Num);	
	 if (Vehicle_Num == -1)
	 {
		 exit(0);
	 }
	
     index = find_index(Vehicle_info, total_vehicle, Vehicle_Num);
	//printf("%d",index);
     if (index == -1)
     {
	  printf("The value %d was not found.\n", Vehicle_Num); //vehicle number not in range of available data
	  printf("Enter the valid Vehicle Number");
	  exit(0);
     }
     else
     {
	  printf("The value %d was found at %d\n", Vehicle_Num, index);
	  
     }
	 float mass, force1;
	 mass = Vehicle_info[index].Mass;
	 // checking if the velocity is greater than top speed
	 
	 if(max_velocity > Vehicle_info[index].Top_Speed)
	 {
		 printf("Maximum Velocity cannot greater than top speed");
		 exit(0);
	 }
	 force1 = impact_force(mass, max_velocity, stopping_distance);
	//printf("%f",force1);
	 printf("Vehicle_Number  Vehicle_Name Mass Top_Speed TestVelocity(Km/h) Stopping distance Force\n");
	 printf("%6d\t%12s\t%10f\t%10f\t%3f\t%5f\t%6f\n", 
		Vehicle_info[index].Vehicle_Number, Vehicle_info[index].Vehicle_Name,
		Vehicle_info[index].Mass, Vehicle_info[index].Top_Speed,
		max_velocity, stopping_distance, force1);
   }while(Vehicle_Num != -1);
	
  return 0;
}