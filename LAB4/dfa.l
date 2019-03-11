%option noyywrap

%%
a(a|b)+a    {printf("Valid");}
.*          {printf("Invalid");}

%%
main()
{yylex();
}

