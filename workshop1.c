

// intialize files 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int whole_part(float x)
{
	int num = x;
	
	return num;

}

float velocity_mps(float velocity)
{
	 float velocity_mps;
	 velocity_mps = 1000.0/3600.0 * velocity;
	 return velocity_mps;
	
	
}
	
float impact_force(float mass, float velocity_mps, float stopping_distance)
{
	float force;
	force = (0.5)* mass * pow(velocity_mps,2)/ stopping_distance;
	return force;
	
}	
int main()
{   
   float mass, stopping_distance;  //intialize  variable
   float max_velocity, min_velocity;                
   printf("Please enter mass(in kg) : ");    // prompt the user to enter the values for variables
   scanf("%f", &mass);
   printf("\n");
   printf("Please enter minimum velocity(in km/h): ");
   scanf("%f", &min_velocity);
   printf("\n");
   printf("Please enter maximum velocity(in km/h): ");
   scanf("%f", &max_velocity);
   printf("\n");
   printf("Please enter stopping_distance(on m): ");
   scanf("%f", &stopping_distance);
   printf("\n"); 
   
   // Error display message for invalid input
   if (mass<=0 || min_velocity<=0 || max_velocity<=0 || stopping_distance <=0){
	   
	   printf("ERROR: Data entered is invalid!\n");
	   exit(0);
    }
   if(min_velocity > max_velocity){
	   
       printf("ERROR: Minimum velocity is less than Maximum velocity");zz
	   exit(0);
    }
	
	
	float i =  min_velocity;
	printf(" -------------------------------------------------\n");
	printf("| velocity(km/h) |velocity(m/s) |force of impact(N)| \n");
	printf(" -------------------------------------------------\n");
	float velocity_mp = velocity_mps(i);
		
	float force = impact_force(mass, velocity_mp, stopping_distance);
		
	printf(" %8f\t  | %8f\t | %8f \t |\n", i , velocity_mp, force);
	
	for ( i= min_velocity; i<= max_velocity; i++)
		
	{
	 
		int velocity_int = whole_part(i);
		
		float velocity_mp1 = velocity_mps(i);          // calling functions
		
		float force1 = impact_force(mass, velocity_mp, stopping_distance);
		
	    printf(" %8d\t  | %8f\t | %8f \t |\n", velocity_int, velocity_mp1, force1);
		
	}	
	
 
   return 0;

}


