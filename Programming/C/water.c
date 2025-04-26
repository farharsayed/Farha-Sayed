
// *****************************************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) // don't change this line
{
	int AUTOGRADING = 0;
	if (argc > 1 && !strcmp(argv[1], "g"))
		AUTOGRADING = 1;


	short UserChoice;		// the menu choice the user has entered, 1=compute a bill, 2=show sums and statistics, 3=quit
	int CustomerType;		// the type of the customer for which a bill is to be computed, 1=domestic, 2=commercial
	int QWaterConsumption;	// the quarterly water consumption of this customer
	double QFreshWaterCharge;	// the quarterly charge for fresh water for this customer
	double QWasteWaterCharge;	// the quarterly charge for waste water for this customer
	double QSurfaceWaterCharge;	// the quarterly charge for surface water for this customer
	double QStandingCharges;	// the quarterly standing charge for this customer
	double QTotalCharge;		// the total of all quarterly charges
	double QVAT;				// the quarterly VAT on all charges, remember that domestic customers don't pay VAT, i.e. VAT = 0
	double QAmountToPay;		// the total amount of the quarterly bill for this customer
	double QTotalFreshWater;	// total amount of fresh water provided to all customers in this quarter
	double QTotalDomestic;	// total amount of fresh water provided to domestic customers in this quarter
	double QRevenue;			// quaretrly revenue made from the sale of water to ALL customers
	double QCost ;			// quaretrly cost of the water provided to ALL customers
	double QProfit;			// quaretrly profit made from the sale of water to ALL customers
	double QIncomeTax;		// the quaretrly income tax that must be paid to the government
	double QAverageDomesticBill;	// the average of all domestic bills in this quarter
	double QMaxDomesticBill;		// the maximum value of a domestic bill in this quarter


// ************************************************

int band = 0;
//band is used to decide which band the customer belongs to
double noofdomesticbills = 0.0;
//to help calculate avg of domestic bills
double totaldomesticbill = 0.0;
//to help calculate avg of domestic bills


// ************************************************************
	// display the menu and prompt the user to enter a choice
	if (!AUTOGRADING) // do not display the menu if autograding
	{
		printf ("1. Compute and display the bill for a customer\n");
		printf ("2. Display sums and statistics\n");
		printf ("3. Quit the program\n");
	}
	while (1) // repeat forever (or until the user enters 3 for choice)
	{
		if (!AUTOGRADING) // don't show a prompt if autograding
			printf ("\nEnter your choice (1, 2, or 3):");  // prompt the user to enter a menu choice number
		scanf ("%hi", &UserChoice); // read the choice number

		// process the user choice
		switch (UserChoice)
		{
		case 1: // the choice for computing and displaying the bill for one customer
			if (!AUTOGRADING) // don't show the prompt if autograding
				printf ("Enter customer type (1=domestic, 2=commercial):");
			scanf (" %i", &CustomerType);
			if (!AUTOGRADING) // don't process customer type if autograding
			{
				while (CustomerType != 1 && CustomerType != 2)
				{
					printf ("This is not a valid customer type!\nTry again:");
					scanf ("%i", &CustomerType);
				}
			}
			if (!AUTOGRADING) // don't show the prompt if autograding
				printf ("Enter water consumption:");
			scanf ("%i", &QWaterConsumption); // input the quarterly water consumption


// ***********************************


//calculating bands

if(CustomerType == 2)
band = 5;
if(QWaterConsumption>=0 && QWaterConsumption<=5)
	band = 1;
if(QWaterConsumption>=6 && QWaterConsumption<=12)
	band = 2;
if(QWaterConsumption>=13 && QWaterConsumption<=25)
	band = 3;
if(QWaterConsumption>=26 && QWaterConsumption<=60)
	band = 4;
if(QWaterConsumption>40)
	band = 5;
if (CustomerType ==2)
band = 5;

if(CustomerType ==2)
	{
		QFreshWaterCharge = QWaterConsumption*2.50;
		QSurfaceWaterCharge = 50;
		QWasteWaterCharge = 2*0.95*QWaterConsumption;
		QStandingCharges = 1.30*91;
}

//calculating the amt to pay

if(CustomerType ==1)
{
	QStandingCharges = 0.10*91;
	QSurfaceWaterCharge = 10;
	QWasteWaterCharge = 0.25*0.95*QWaterConsumption;
	switch(band)
	{
		case 1:
		{

			QFreshWaterCharge = QWaterConsumption*0.20;

		}
		break;
		case 2:
		{

			QFreshWaterCharge = 5*0.20+(QWaterConsumption-5)*0.35;
		}
		break;
		case 3:
		{
			QFreshWaterCharge = 5*0.20 + 0.35*(12-5) + (QWaterConsumption-12)*0.50;
		}
		break;
		case 4:
		{

			QFreshWaterCharge = 5*0.20 + 0.35*(12-5) + (25-12)*0.50 +(QWaterConsumption-25)*0.75;
		}
		break;
		case 5:
		{
			QFreshWaterCharge = 5*0.20 + 0.35*(12-5) + (25-12)*0.50 + (40-25)*0.75 + (QWaterConsumption-40)*2.50;
		}
		break;

}
}

QTotalCharge = QFreshWaterCharge+QWasteWaterCharge+QSurfaceWaterCharge+QStandingCharges;

if(CustomerType == 2)
{
QVAT = 0.2*QTotalCharge;
}
if (CustomerType == 1)
{
QVAT = 0.0;
}

QAmountToPay = QTotalCharge + QVAT;

//calculating cumulative sums

QTotalFreshWater = QTotalFreshWater+ QWaterConsumption;

if(CustomerType ==1)
QTotalDomestic = QTotalDomestic + QWaterConsumption;

QRevenue = QRevenue + QTotalCharge;

QCost = QCost + (QWaterConsumption);

QProfit = QProfit + QTotalCharge - QWaterConsumption;

QIncomeTax = QProfit*0.25;

if(CustomerType == 1)
{
noofdomesticbills = noofdomesticbills+1;
totaldomesticbill = totaldomesticbill + QTotalCharge;
QAverageDomesticBill = totaldomesticbill/noofdomesticbills;

	if (QTotalCharge>QMaxDomesticBill)
		QMaxDomesticBill = QTotalCharge;
}




// *****************************************************************************************************************
			// THIS IS THE CODE FOR DISPLAYING THE BILL ON THE SCREEN
			if (!AUTOGRADING)
			{
				printf ("\n------------------------------------------\n");
				printf ("Customer Type: ");
				if (CustomerType == 1)
					printf ("Domestic\n");
				else
					printf ("Commercial\n");
				// now let's display the bill
				printf ("Fresh Water Consumption:  %i Cubic Meter\n" , QWaterConsumption);
				printf ("Fresh Water Charge:       %.2f GBP\n", QFreshWaterCharge);
				printf ("Waste Water Charge:       %.2f GBP\n" , QWasteWaterCharge);
				printf ("Surface Water Charge:     %.2f GBP\n", QSurfaceWaterCharge);
				printf ("Standing Charges:         %.2f GBP\n", QStandingCharges);
				printf ("Total Charges:            %.2f GBP\n" , QTotalCharge);
				printf ("VAT:                      %.2f GBP\n" , QVAT);
				printf ("Amount to Pay:            %.2f GBP\n" , QAmountToPay);
				printf ("-------------------------------------------\n\n");
			}
			else
			{
				if (argc == 2 && !strcmp (argv[1],"g"))
				{
					printf ("%d\n" , QWaterConsumption);
					printf ("%.2f\n", QFreshWaterCharge);
					printf ("%.2f\n" , QWasteWaterCharge);
					printf ("%.2f\n", QSurfaceWaterCharge);
					printf ("%.2f\n", QStandingCharges);
					printf ("%.2f\n" , QTotalCharge);
					printf ("%.2f\n" , QVAT);
					printf ("%.2f\n" , QAmountToPay);
				}
			}
			break;
		case 2: // the choice for displaying the sums
			if (!AUTOGRADING)
			{
				printf ("Total Fresh Water Supplied:              %.2f Cubic Meter\n" , QTotalFreshWater);
				printf ("Total Fresh Water to Domestic Customers: %.2f Cubic Meter\n", QTotalDomestic);
				printf ("Total Revenue:                           %.2f GBP\n" , QRevenue);
				printf ("Total Cost:                              %.2f GBP\n" , QCost);
				if (QProfit >= 0)
					printf ("Profit:                                  %.2f GBP\n" , QProfit);
				else
					printf ("Loss:                                    %.2f GBP\n" , QProfit);

				printf ("Income Tax:                              %.2f GBP\n" , QIncomeTax);
				printf ("Maximum Domestic Bill:                   %.2f GBP\n", QMaxDomesticBill);
				printf ("Average Domestic Bill:                   %.2f GBP\n", QAverageDomesticBill);
			}
			else
			{
				if (argc == 3 && (!strcmp (argv[2], "tfw") || !strcmp (argv[2], "all")))
					printf ("%.2f\n" , QTotalFreshWater);
				if (argc > 2 && (!strcmp (argv[2], "tdm") || !strcmp (argv[2], "all")))
					printf ("%.2f\n", QTotalDomestic);
				if (argc > 2 && (!strcmp (argv[2], "rev") || !strcmp (argv[2], "all")))
					printf ("%.2f\n" , QRevenue);
				if (argc > 2 && (!strcmp (argv[2], "cst") || !strcmp (argv[2], "all")))
					printf ("%.2f\n" , QCost);
				if (argc > 2 && (!strcmp (argv[2], "prf") || !strcmp (argv[2], "all")))
					printf ("%.2f\n" , QProfit);
				if (argc > 2 && (!strcmp (argv[2], "tax") || !strcmp (argv[2], "all")))
					printf ("%.2f\n" , QIncomeTax);
				if (argc > 2 && (!strcmp (argv[2], "max") || !strcmp (argv[2], "all")))
					printf ("%.2f\n", QMaxDomesticBill);
				if (argc > 2 && (!strcmp (argv[2], "avg") || !strcmp (argv[2], "all")))
					printf ("%.2f\n", QAverageDomesticBill);
			}
			break;
		case 3:
			exit (0);
		default:
			printf ("not a valid option number");
		}
	}
	return 0;

}

//==============================================================================
