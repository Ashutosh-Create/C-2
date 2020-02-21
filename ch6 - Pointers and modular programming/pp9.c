/*
 * Program Description: To calculate drag for an aircraft
 * Input: A (projected area of aircraft perpendicular to velocity vector) and
 *      CD (drag coefficient)
 * Output: Drag force for a range of velocities from 0m/s to 40 m/s in
 *      increments of 5 m/s
 */

#include <stdio.h>

#define DENSITY 1.23        /* 1.23 kg/m^3, density of air at sea level */
#define VELOCITY_INITIAL 0  /* 0 m/s */
#define VELOCITY_FINAL 40   /* 40 m/s */
#define VELOCITY_STEP 5     /* 5 m/s */

double drag_force(double CD, double A, double p, double V);

int
main(void)
{
    double force;       /* Drag force (newtons) */
    double drag_coeff;  /* Drag coefficient */
    double area;        /* Projected area of aircraft perpendicular to
                           velocity vector (m^2) */
    double density;     /* Density of gas or fluid through which the body
                           is traveling (kg/m^3) */
    double velocity;    /* The body's velocity (m/s) */

    printf("Enter area of aircraft perpendicular to velocity vector: ");
    scanf("%lf", &area);

    printf("Enter drag coefficient: ");
    scanf("%lf", &drag_coeff);

    density = DENSITY;
    printf("Density of air at sea level = %.2f kg/m^3\n", density);

    for (velocity = VELOCITY_INITIAL;
         velocity <= VELOCITY_FINAL;
         velocity += VELOCITY_STEP) {
        force = drag_force(drag_coeff, area, density, velocity);
        printf("Drag = %.3f newtons at velocity %.f m/s\n", force, velocity);
    }

    return (0);
}

/*
 * Calculates drag force
 * Pre: Drag coefficient, Area, Density and Velocity
 */
double
drag_force(double CD, double A, double p, double V)
{
    return 0.5 * CD * A * p * V * V;
}
