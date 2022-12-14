#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int coeff;
	int pow;
	struct Node* next;
};

void create_node(int x, int y,
				struct Node** temp)
{
	struct Node *r, *z;
	z = *temp;
	if (z == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		r->coeff = x;
		r->pow = y;
		*temp = r;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r = r->next;
		r->next = NULL;
	}
	else
	{
		r->coeff = x;
		r->pow = y;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r = r->next;
		r->next = NULL;
	}
}

void polyadd(struct Node* poly1,
			struct Node* poly2,
			struct Node* poly)
{
	while (poly1->next &&
		poly2->next)
	{
		if (poly1->pow > poly2->pow)
		{
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff;
			poly1 = poly1->next;
		}

		else if (poly1->pow < poly2->pow)
		{
			poly->pow = poly2->pow;
			poly->coeff = poly2->coeff;
			poly2 = poly2->next;
		}

		else
		{
			poly->pow = poly1->pow;
			poly->coeff = (poly1->coeff +
						poly2->coeff);
			poly1 = poly1->next;
			poly2 = poly2->next;
		}

		poly->next =
			(struct Node*)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}
	while (poly1->next || poly2->next)
	{
		if (poly1->next)
		{
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff;
			poly1 = poly1->next;
		}
		if (poly2->next)
		{
			poly->pow = poly2->pow;
			poly->coeff = poly2->coeff;
			poly2 = poly2->next;
		}
		poly->next =
			(struct Node*)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}
}

void show(struct Node* node)
{
	while (node->next != NULL)
	{
		printf("%dx^%d", node->coeff,
				node->pow);
		node = node->next;
		if (node->coeff >= 0)
		{
			if (node->next != NULL)
				printf("+");
		}
	}
}


int main()
{
	struct Node *poly1 = NULL,
				*poly2 = NULL,
				*poly = NULL;

    int count1, count2;
    int p1data[10][10], p2data[10][10];
    //array to store coefficients and power of polynomials

    cout<<"\n -> How many terms do you have in first polynomial : ";
    cin>>count1;

    for (int i=0; i<count1; i++){
        cout<<"~ FOR "<<i+1<<" term ~"<<endl;
        cout<<"Enter the coefficient : ";
        cin>>p1data[i][0];
        cout<<"Enter the power : ";
        cin>>p1data[i][1];
    }
    
    //creating the node poly1
    for (int i=0; i<count1; i++){
            int coeff=p1data[i][0];
            int power=p1data[i][1];
            create_node(coeff, power, &poly1);
    }

    cout<<"\n -> 1st Number/Polynomial: ";
	show(poly1);

    cout<<"\n -> How many terms do you have in second polynomial : ";
    cin>>count2;

    for (int i=0; i<count2; i++){
        cout<<"~ FOR "<<i+1<<" term ~"<<endl;
        cout<<"Enter the coefficient : ";
        cin>>p2data[i][0];
        cout<<"Enter the power : ";
        cin>>p2data[i][1];
    }

//creating the node poly2
    for (int i=0; i<count2; i++){
            int coeff=p2data[i][0];
            int power=p2data[i][1];
            create_node(coeff, power, &poly2);
    }

	cout<<"\n -> 2nd Number/Polynomial : ";
	show(poly2);

	poly = (struct Node*)malloc(sizeof(struct Node));

	polyadd(poly1, poly2, poly);

	cout<<"\n -> Added polynomial: "<<endl;
	show(poly);

	return 0;
}
