#include <string.h>
#include <stdio.h>
#include <stdlib.h>



const char * SubStr(const char * str,const char * substr)  ;



int main(void)
{
	char * str = "ewfwefehferflhfe2e" ;
	char * substr = "l" ;


	const char * ret = SubStr(str,substr) ;

	puts(ret) ;



	return 0;
}


const char * SubStr(const char * str,const char * substr)  
{
	if(NULL == str || (NULL == substr)) 
		return NULL ;
	const char * temp_str = str ;
	const char * temp_substr = substr;
	while(*temp_str != '\0')
	{	
		if(*temp_str != *temp_substr)
		{
			++temp_str ;
			continue ;
		}

		const char *temp2_str = temp_str ;
		const char *temp2_substr = temp_substr ;

		while(*temp2_substr != '\0')
		{
			if(*temp2_str != *temp2_substr)
			{
				++ temp_str ;
				break ;
			}

			++temp2_str;
			++temp2_substr ;
		}

		if(*temp2_substr == '\0')
		{

			return temp_str ;

		}
	
	}


	return NULL; 

}