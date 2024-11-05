%{
int vowel_count = 0, consonant_count = 0;
%}

%%
[aAeEiIoOuU]              { vowel_count++; }    
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { consonant_count++; }
[\n]                       { return 0; }
.                          ; 
%%
int main() {
    yylex();  
    printf("Vowels: %d\n", vowel_count);
    printf("Consonants: %d\n", consonant_count);
    return 0;
}
