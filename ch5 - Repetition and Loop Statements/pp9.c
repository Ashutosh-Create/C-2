/*
 * Name: Abhijit Parida		Date: 15-02-17
 * Program Description: To get case inventory, process weekly sales and
 *	display final inventory for a beer distributorship
 * Input: case inventory, and transactions consisting of brand id and
 *	amount purchased/sold
 * Output: final inventory
 * Algorithm:
 * 	1. Get case inventory for each brand
 * 	2. Process weekly records
 * 	3. Display final inventory
 */

#include <stdio.h>

#define PIELS_ID 1
#define COORS_ID 2
#define BUD_ID 3
#define IRONCITY_ID 4

int
main(void)
{
	int piels_inventory;
	int coors_inventory;
	int bud_inventory;
	int ironcity_inventory;
	int brand_id, amount;

	int input_status;

	/* Get case inventory for each brand */
	scanf("%d%d%d%d", &piels_inventory, &coors_inventory,
		&bud_inventory, &ironcity_inventory);

	/* Display inventory */
	printf("Beer inventory:\n");
	printf("Piels: %d cases\n", piels_inventory);
	printf("Coors: %d cases\n", coors_inventory);
	printf("Bud: %d cases\n", bud_inventory);
	printf("Iron City: %d cases\n", ironcity_inventory);

	/* Process weekly records */
	input_status = scanf("%d%d", &brand_id, &amount);
	while (input_status != -1) {
		switch (brand_id) {
			case PIELS_ID:
			piels_inventory += amount;
			break;

			case COORS_ID:
			coors_inventory += amount;
			break;

			case BUD_ID:
			bud_inventory += amount;
			break;

			case IRONCITY_ID:
			ironcity_inventory += amount;
			break;
		}
		input_status = scanf("%d%d", &brand_id, &amount);
	}

	/* Display final inventory */
	printf("\nFinal inventory:\n");
	printf("Piels: %d cases\n", piels_inventory);
	printf("Coors: %d cases\n", coors_inventory);
	printf("Bud: %d cases\n", bud_inventory);
	printf("Iron City: %d cases\n", ironcity_inventory);

	return (0);
}
