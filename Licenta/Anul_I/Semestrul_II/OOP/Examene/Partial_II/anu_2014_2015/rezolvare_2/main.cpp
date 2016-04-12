#include "Propozitie.h"
#include "stdio.h"
using namespace std;
int main(void)

{ 

	Propozitie p1,p2,p3;

	if (p1.SetPropozitie("Ana are mere")==false)

		printf("Propozitie incorecta\n");

	

	if (p1.SetPropozitie("   Ana    are     mere   .")==false)

		printf("Propozitie incorecta (2)\n");

	else

		printf("Cuvinte = %d\n",p1.GetCount());

	

	printf("%d\n",p1.ContainsWord("are"));

	for (int tr=0;tr<p1.GetCount();tr++)

		printf("Word[%d] = %s\n",tr,p1.GetWord(tr));



	p2.SetPropozitie("are mene Ana.");

	printf("%d\n",p1.HasSameWords(p2));



	p3.SetPropozitie("Ana are mere rosii.");

	printf("%d\n",p3.Contains(p1));



	p3.SetPropozitie("Ana                  are                                  mere    .");

	printf("%d\n",p1.IsIdentical(p3));

    return 0;
}
