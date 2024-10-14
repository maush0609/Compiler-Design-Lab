

32 of 1,517
Fwd:
Inbox

Ashish Mohan B21CS1214
Attachments
Thu, Oct 3, 5:52 PM (11 days ago)
to me


---------- Forwarded message ---------
From: CSE TechnicalStaff <cse.technicalstaff@mbcet.ac.in>
Date: Thu, 3 Oct 2024, 4:20 pm
Subject:
To: Ashish Mohan B21CS1214 <ashishmohan.b21cs1214@mbcet.ac.in>




--------------------------------------------------------------------------------------------------------------
Go Green: DO NOT print this e-mail unless absolutely necessary. Save paper, Save Trees.
--- Disclaimer ---

The information in this mail, including any attachments, is confidential and is intended solely for the addressee. Access to this mail by anyone else is unauthorized. Copying or further distribution beyond the original recipient may be unlawful if you are not the intended recipient. Please contact the sender by reply email and destroy all copies of the original message. Any opinion expressed in this mail is that of the sender and does not necessarily reflect that of Mar Baselios College of Engineering and Technology, Thiruvananthapuram.


--------------------------------------------------------------------------------------------------------------
Go Green: DO NOT print this e-mail unless absolutely necessary. Save paper, Save Trees.
--- Disclaimer ---

The information in this mail, including any attachments, is confidential and is intended solely for the addressee. Access to this mail by anyone else is unauthorized. Copying or further distribution beyond the original recipient may be unlawful if you are not the intended recipient. Please contact the sender by reply email and destroy all copies of the original message. Any opinion expressed in this mail is that of the sender and does not necessarily reflect that of Mar Baselios College of Engineering and Technology, Thiruvananthapuram.

 7 Attachments
  •  Scanned by Gmail
%{
	#include<stdio.h>
	int vowels=0;
	int consonants=0;
%}
%%
[aeiouAEIOU]	{
		vowels++;
}
[a-zA-Z]	{
		consonants++;
}
%%

int main(){
	FILE*infile=fopen("inp.txt","r");
	FILE*outfile=fopen("oup.txt","w");
	
	yyin=infile;
	yylex();
	
	fprintf(outfile,"no vowels %d\n",vowels);
	fprintf(outfile,"no of consonants %d\n",consonants);
	
	fclose(infile);
	fclose(outfile);
	return 0;
}
int yywrap(){
	return 1;
}

INPUT
maushmi is here

OUTPUT
no vowels 6
no of consonants 7
